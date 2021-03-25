/*
	<구현할 함수>
	1. 메뉴 출력 함수
	2. 평점 계산 함수
	3. 교과목 평점 계산 함수
	4. 전체 학생 정보 출력 함수
	5. 개인 학생 정보 출력 함수
	6. 학생 이름 검색 함수
*/
#include <iostream>	
#include <iomanip>	
#include <cstring>	
using namespace std;

struct Subject {
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};
struct Student {
	char StdName[30];
	int Hakbun;
	Subject Sub[3];
	float AveGPA;
};

void PrintMenu();
void inputStd(Student *std);
void inputSub(Subject *sub);
float calcGPA(Subject &sub);
float calcAveGPA(Subject* sub);
void PrintAllData(const Student *pst, int StudentNum);
void printSub(const Subject *sub);
void PrintOneData(const Student &rst);
void Search(Student *pst, int StudentNum);
Student* StdSearch(Student *pst, int StudentNum);

int menuNum;

int main() {
	Student student[2];
	cout.precision(2);
	cout << fixed;

	while (1) {
		PrintMenu();

		//2명의 학생 정보 입력
		if (menuNum == 1) {
			inputStd(student);
		}
		//전체학생 정보 출력
		else if (menuNum == 2) {
			PrintAllData(student, 2);
		}
		//원하는 학생의 정보 출력
		else if (menuNum == 3) {
			Search(student, 2);
		}
		//프로그램 종료
		else if (menuNum == 4){
			cout << "프로그램을 종료합니다.\n";
			break;
		}
		//출력된 메뉴에 없는 번호를 선택했을 경우
		else {
			cout << "<없는 메뉴 번호를 선택하셨습니다.>\n";
		}
	}
	return 0;
}
void PrintMenu() {
	cout << "==========메뉴==========\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 프로그램 종료\n" << "\n";

	cout << "원하는 기능을 입력하세요 : ";
	cin >> menuNum;
	cout << "\n";
}
void inputStd(Student *std) {
	for (int i = 0; i < 2; i++) {
		cout << "* " << i + 1 << " 번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		cin >> std[i].StdName;
		cout << "학번 : ";
		cin >> std[i].Hakbun;
		cout << "\n\n";

		//해당 학생이 수강한 과목 정보 입력
		inputSub(std[i].Sub);
		//해당 학생의 과목 평균 평점 계산
		std[i].AveGPA = calcAveGPA(std[i].Sub);
	}
}
void inputSub(Subject *sub) {
	float sumGPA = 0.0;

	cout << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
	for (int j = 0; j < 3; j++) {
		cout << "교과목명 : ";
		cin >> sub[j].SubName;
		cout << "과목학점 : ";
		cin >> sub[j].Hakjum;
		cout << "과목등급(A+ ~ F) : ";
		cin >> sub[j].Grade;
		cout << "\n";

		sub[j].GPA = calcGPA(sub[j]);
	}
	cout << "\n\n";
}
float calcGPA(Subject &sub) {
	float result;
	//해당 과목의 grade를 비교하여 해당하는 평점을 저장
	if (strcmp(sub.Grade, "A+") == 0)
		result = 4.5;
	else if (strcmp(sub.Grade, "A0") == 0)
		result = 4.0;
	else if (strcmp(sub.Grade, "B+") == 0)
		result = 3.5;
	else if (strcmp(sub.Grade, "B0") == 0)
		result = 3.0;
	else if (strcmp(sub.Grade, "C+") == 0)
		result = 2.5;
	else if (strcmp(sub.Grade, "C0") == 0)
		result = 2.0;
	else if (strcmp(sub.Grade, "D+") == 0)
		result = 1.5;
	else if (strcmp(sub.Grade, "D0") == 0)
		result = 1.0;
	else
		result = 0.0;

	//완벽히 계산된 과목 평점 전달
	return result * sub.Hakjum;
}

float calcAveGPA(Subject *sub) {
	int sumHakjum = 0;
	float sumGPA = 0.0;
	for (int i = 0; i < 3; i++) {
		//모든 과목의 학점 저장
		sumHakjum += sub[i].Hakjum;
		//모든 과목의 평점 저장
		sumGPA += sub[i].GPA;
	}
	//계산된 과목 평균 평점 전달
	return sumGPA / (float)sumHakjum;
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
	printSub(rst.Sub);
	cout << "===============================================================\n";

	cout.width(45);
	cout << "평균평점 : ";
	//해당 학생의 과목 평균 평점 출력
	cout << rst.AveGPA << "\n\n";
}

void printSub(const Subject *sub) {
	for (int i = 0; i < 3; i++) {
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
	char searchName[20];
	cout << "검색할 학생 이름 : ";
	cin >> searchName;

	for (int i = 0; i < StudentNum; i++) {
		//해당 학생의 이름과 찾고자 하는 학생 이름 비교
		if (strcmp(searchName, pst[i].StdName) == 0) {
			//있으면 검색 그만하고 해당 학생의 정보가 저장된 구조체 주소 전달
			return &pst[i];
		}
		//계속 일치하는 학생 찾기
		else;
	}
	//검색한 이름이 프로그램에 없는 학생이라면 NULL 값 전달
	return NULL;
}