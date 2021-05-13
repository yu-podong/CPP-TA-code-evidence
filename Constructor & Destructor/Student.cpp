#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
	cout << "Student 디폴트 생성자 호출\n";
}

Student::Student(string stdName, int stdHakbun, int subnum, Subject* stdSub) {
	m_name = stdName;
	m_hakbun = stdHakbun;
	m_subnum = subnum;
	// 깊은 복사를 위해 새로운 동적 메모리 할당
	// 새로 동적 메모리를 받은 m_sub에게 stdSub의 값을 대입
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].SetName(stdSub[i].GetName());
		m_sub[i].SetHakjum(stdSub[i].GetHakjum());
		m_sub[i].SetGrade(stdSub[i].GetGrade());
		m_sub[i].SetGPA(stdSub[i].GetGPA());
	}
	CalcAveGPA();
	cout << "Student 인자있는 생성자 호출\n";
}
Student::Student(const Student &std) {
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	// 깊은 복사를 위해 새로운 동적 메모리 할당
	// 새로 동적 메모리를 받은 m_sub에게 stdSub의 값을 대입
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].SetName(std.m_sub[i].GetName());
		m_sub[i].SetHakjum(std.m_sub[i].GetHakjum());
		m_sub[i].SetGrade(std.m_sub[i].GetGrade());
		m_sub[i].SetGPA(std.m_sub[i].GetGPA());
	}
	m_aveGPA = std.m_aveGPA;
	cout << "Student 복사 생성자 호출\n";
}

Student::~Student() {
	cout << "Student 소멸자 호출\n";
	if (m_subnum == 1)
		delete m_sub;
	else if (m_subnum > 1)
		delete[] m_sub;
	else;

	m_sub = NULL;
	
}

void Student::InputValue(string &str) {
	getline(cin, str);
}

void Student::InputValue(int &i) {
	cin >> i;
	cin.ignore();
}

void Student::InputData() {
	// 학생정보 입력
	cout << "이름 : ";
	InputValue(m_name);
	cout << "학번 : ";
	InputValue(m_hakbun);

	// 과목정보 입력
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData();
	}

	CalcAveGPA();
}

void Student::PrintData() {
	// 학생 정보 title
	cout << "===============================================================\n";
	cout.width(15);
	cout << "이름 : ";
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << "학번 : ";
	cout.width(15);
	cout << m_hakbun << '\n';

	// 과목 정보 출력
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "===============================================================\n";

	//해당 학생의 과목 평균 평점 출력
	cout.width(45);
	cout << "평균평점 : ";
	cout << m_aveGPA << '\n';
}

void Student::CalcAveGPA() {
	int sumHakjum = 0;
	float sumGPA = 0.0;

	for (int i = 0; i < m_subnum; i++) {
		//모든 과목의 학점 저장
		sumHakjum += m_sub[i].GetHakjum();
		//모든 과목의 평점 저장
		sumGPA += m_sub[i].GetGPA();
	}
	//계산된 과목 평균 평점 전달
	m_aveGPA = sumGPA / (float)sumHakjum;
}

void Student::stdInfoModify() {
	//포인터 구조체이기에 -> 이용
	cout << "< " << GetName() << ", " << GetHakbun() << ">의 정보를 수정하세요.\n";

	//검색한 학생의 이름과 학번 수정
	cout << "이름 : ";
	InputValue(m_name);
	cout << "학번 : ";
	InputValue(m_hakbun);
	cout << "\n";
}

void Student::Modify() {
	string modifyInfo;

	//수정하고픈 정보 입력
	cout << "\n수정할 정보를 선택하세요 <학생정보 / 과목정보 / 모두> : ";
	InputValue(modifyInfo);
	cout << '\n';

	//학생 정보를 입력한 경우
	if (modifyInfo == "학생 정보" || modifyInfo == "학생정보") {
		stdInfoModify();
	}
	//과목 정보를 입력한 경우
	else if (modifyInfo == "과목 정보" || modifyInfo == "과목정보") {
		// 해당 학생이 수강하고 있는 모든 과목 정보를 수정
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify();
		}
		//수정한 정보를 바탕으로 AveGPA수정
		CalcAveGPA();
	}
	// 모두를 입력한 경우
	else if (modifyInfo == "모두") {
		// 학생의 인적 정보 수정
		stdInfoModify();
		// 학생의 모든 과목 정보 수정
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify();
		}
		//수정한 정보를 바탕으로 AveGPA수정
		CalcAveGPA();
	}
	//잘못 입력한 경우
	else {
		cout << "<수정하고자 하는 정보를 정확히 입력해주세요.>\n\n";
	}
}