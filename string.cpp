#include <iostream>	
#include <iomanip>	
#include <cstring>	
#include <string>
using namespace std;

struct Subject {
	string SubName;
	int Hakjum;
	string Grade;
	float GPA;
};
struct Student {
	string StdName;
	int Hakbun;
	Subject *Sub;
	int SubNum;
	float AveGPA;
};

inline void PrintMenu();
void InputData(Student *std, int StudentNum);
void inputSub(Subject *sub, int subNum);
inline void InputValue(string &str);
inline void InputValue(int &i);
float calcGPA(Subject &sub);
float calcAveGPA(Subject* sub, int subNum);
void PrintAllStdList(Student *pSt, int StudentNum);
void PrintAllData(const Student *pst, int StudentNum);
void printSub(const Subject *sub, int subNum);
void PrintOneData(const Student &rst);
void Search(Student *pst, int StudentNum);
Student* StdSearch(Student *pst, int StudentNum);
void ModifyStdInfo(Student *pst);
Subject* SubSearch(const Student *pst);

int menuNum;

int main() {
	Student *student = NULL, *findStd = NULL;
	int stdNum = 0;

	cout.precision(2);
	cout << fixed;

	while (1) {
		PrintMenu();

		//학생 정보 입력
		if (menuNum == 1) {
			//학생 수를 입력받음
			cout << "프로그램에 저장할 학생 수를 입력하세요 : ";
			InputValue(stdNum);

			//학생 수 만큼 동적 메모리 할당
			student = new Student[stdNum];

			InputData(student, stdNum);
		}
		//전체학생 정보 출력
		else if (menuNum == 2) {
			PrintAllData(student, stdNum);
		}
		//원하는 학생의 정보 출력
		else if (menuNum == 3) {
			Search(student, stdNum);
		}
		//전체 학생 정보 출력
		else if (menuNum == 4) {
			PrintAllStdList(student, stdNum);
		}
		//특정 학생의 정보 수정
		else if (menuNum == 5) {
			findStd = StdSearch(student, stdNum);
			if (findStd != NULL) {
				ModifyStdInfo(findStd);
			}
			else {
				cout << "<프로그램 내에 해당 학생의 이름이 없습니다.>\n";
			}

		}
		//프로그램 종료
		else if (menuNum == 6) {
			cout << "프로그램을 종료합니다.\n";
			break;
		}
		//출력된 메뉴에 없는 번호를 선택했을 경우
		else {
			cout << "<없는 메뉴 번호를 선택하셨습니다.>\n";
		}
	}
	//할당했던 동적 메모리 해제
	delete[] student;

	return 0;
}
void PrintMenu() {
	cout << "==========메뉴==========\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n" << "\n";

	cout << "원하는 기능을 입력하세요 : ";
	InputValue(menuNum);
	cout << "\n";
}
void InputData(Student *std, int StudentNum) {
	for (int i = 0; i < StudentNum; i++) {
		cout << "\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(std[i].StdName);
		cout << "학번 : ";
		InputValue(std[i].Hakbun);
		cout << "\n\n";

		//
		cout << "해당 학생이 수강한 과목 수를 입력하세요 : ";
		InputValue(std[i].SubNum);

		std[i].Sub = new Subject[std[i].SubNum];

		//해당 학생이 수강한 과목 정보 입력
		inputSub(std[i].Sub, std[i].SubNum);
		//해당 학생의 과목 평균 평점 계산
		std[i].AveGPA = calcAveGPA(std[i].Sub, std[i].SubNum);
	}
}
void inputSub(Subject *sub, int subNum) {
	float sumGPA = 0.0;

	cout << "* 수강한 과목" << subNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
	for (int j = 0; j < subNum; j++) {
		cout << "교과목명 : ";
		InputValue(sub[j].SubName);
		cout << "과목학점 : ";
		InputValue(sub[j].Hakjum);
		cout << "과목등급(A+ ~ F) : ";
		InputValue(sub[j].Grade);
		cout << "\n";

		sub[j].GPA = calcGPA(sub[j]);
	}
	cout << "\n\n";
}
void InputValue(string &str) {
	getline(cin, str);
}
void InputValue(int &i) {
	cin >> i;
	cin.ignore();
}
float calcGPA(Subject &sub) {
	float result;
	//해당 과목의 grade를 비교하여 해당하는 평점을 저장
	if (sub.Grade == "A+")
		result = 4.5;
	else if (sub.Grade == "A0")
		result = 4.0;
	else if (sub.Grade == "B+")
		result = 3.5;
	else if (sub.Grade == "B0")
		result = 3.0;
	else if (sub.Grade == "C+")
		result = 2.5;
	else if (sub.Grade == "C0")
		result = 2.0;
	else if (sub.Grade == "D+")
		result = 1.5;
	else if (sub.Grade == "D0")
		result = 1.0;
	else
		result = 0.0;

	//완벽히 계산된 과목 평점 전달
	return result * sub.Hakjum;
}

float calcAveGPA(Subject *sub, int subNum) {
	int sumHakjum = 0;
	float sumGPA = 0.0;
	for (int i = 0; i < subNum; i++) {
		//모든 과목의 학점 저장
		sumHakjum += sub[i].Hakjum;
		//모든 과목의 평점 저장
		sumGPA += sub[i].GPA;
	}
	//계산된 과목 평균 평점 전달
	return sumGPA / (float)sumHakjum;
}

void PrintAllStdList(Student *pSt, int StudentNum) {
	cout << "===============================================================\n";
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << "이름\n";
	cout << "===============================================================\n";

	//프로그램에 저장된 학생들의 학번과 이름을 출력
	for (int i = 0; i < StudentNum; i++) {
		cout.width(15);
		cout << pSt[i].Hakbun;
		cout.width(15);
		cout << pSt[i].StdName << '\n';
	}
	cout << "===============================================================\n\n";
}

void PrintAllData(const Student *pst, int StudentNum) {
	cout << "               전체 학생 성적 보기" << '\n';
	cout << "===============================================================\n";

	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pst[i]);
	}
}

void PrintOneData(const Student &rst) {
	//출력될 정보들을 화면에 표시
	cout << "이름 : " << rst.StdName << "  학번 : " << rst.Hakbun << "\n";
	cout << "===============================================================\n";
	cout.width(15);
	cout << "과목명";
	cout.width(15);
	cout << "과목학점";
	cout.width(15);
	cout << "과목등급";
	cout.width(15);
	cout << "과목평점\n";
	cout << "===============================================================\n";

	//해당 학생이 수강하는 과목 정보 출력
	printSub(rst.Sub, rst.SubNum);
	cout << "===============================================================\n";

	cout.width(45);
	cout << "평균평점 : ";
	//해당 학생의 과목 평균 평점 출력
	cout << rst.AveGPA << "\n\n";
}

void printSub(const Subject *sub, int subNum) {
	//해당 학생이 수강하는 과목의 성적 출력
	for (int i = 0; i < subNum; i++) {
		cout.width(15);
		cout << sub[i].SubName;
		cout.width(15);
		cout << sub[i].Hakjum;
		cout.width(15);
		cout << sub[i].Grade;
		cout.width(15);
		cout << sub[i].GPA << '\n';
	}
}

void Search(Student *pst, int StudentNum) {
	Student *searchStd = NULL;
	//학생 이름 입력 후 프로그램에 저장된 학생 이름과 비교하는 함수 호출
	searchStd = StdSearch(pst, StudentNum);

	//찾고 있던 학생의 정보가 있을 경우, 해당 학생의 정보 출력
	if (searchStd) {
		PrintOneData(*searchStd);
	}
	//찾고 있던 학생의 정보가 없을 경우, 아래의 메세지 출력
	else {
		cout << "<해당 이름을 가진 학생의 정보가 등록되어있지 않습니다.>\n\n";
	}
}

Student* StdSearch(Student *pst, int StudentNum) {
	string searchName;
	cout << "검색할 학생 이름 : ";
	InputValue(searchName);

	for (int i = 0; i < StudentNum; i++) {
		//해당 학생의 이름과 찾고자 하는 학생 이름 비교
		if (searchName == pst[i].StdName) {
			//있으면 검색 그만하고 해당 학생의 정보가 저장된 구조체 주소 전달
			return &pst[i];
		}
		//계속 일치하는 학생 찾기
		else;
	}
	//검색한 이름이 프로그램에 없는 학생이라면 NULL 값 전달
	return NULL;
}

void ModifyStdInfo(Student *pst) {
	string modifyInfo;
	Subject *findSub = NULL;

	//수정하고픈 정보 입력
	cout << "\n수정할 정보를 선택하세요 <학생정보 / 과목정보> : ";
	InputValue(modifyInfo);
	cout << '\n';

	//학생 정보를 입력한 경우
	if (modifyInfo == "학생 정보" || modifyInfo == "학생정보") {
		//포인터 구조체이기에 -> 이용
		cout << "< " << pst->StdName << ", " << pst->Hakbun << ">의 정보를 수정하세요.\n";

		//검색한 학생의 이름과 학번 수정
		cout << "이름 : ";
		InputValue(pst->StdName);
		cout << "학번 : ";
		InputValue(pst->Hakbun);
		cout << "\n";
	}
	//과목 정보를 입력한 경우
	else if (modifyInfo == "과목 정보" || modifyInfo == "과목정보") {
		//수정하고픈 과목 찾기
		findSub = SubSearch(pst);

		//해당 학생이 수강한 과목 중에 찾는 과목이 존재한다면
		if (findSub != NULL) {
			//과목 정보 수정
			cout << "<" << findSub->SubName << ", " << findSub->Hakjum << ", " << findSub->Grade << ">의 정보를 수정하세요.\n";
			cout << "교과목명 : ";
			InputValue(findSub->SubName);
			cout << "과목학점 : ";
			InputValue(findSub->Hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(findSub->Grade);
			cout << "\n";

			//수정한 정보를 바탕으로 GPA, AveGPA 수정
			findSub->GPA = calcGPA(*findSub);
			pst->AveGPA = calcAveGPA(pst->Sub, pst->SubNum);
		}
		//해당 학생의 수강 과목 중에 찾는 과목이 없으면
		else {
			cout << "<해당 학생은 찾고자 하는 과목을 수강하지 않습니다.>\n\n";
		}
	}
	//잘못 입력한 경우
	else {
		cout << "<수정하고자 하는 정보를 정확히 입력해주세요.>\n\n";
	}	
}

Subject* SubSearch(const Student *pst) {
	string searchSub;

	//수정하고픈 과목 이름 입력
	cout << "검색할 과목 이름 : ";
	InputValue(searchSub);

	//해당 학생이 수강한 과목들을 비교
	for (int i = 0; i < pst->SubNum; i++) {
		//검색한 과목과 같은 이름 존재
		if (searchSub == pst->Sub[i].SubName) {
			return &(pst->Sub[i]);
		}	
		else;
	}
	return NULL;
}