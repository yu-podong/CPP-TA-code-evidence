#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject() {
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
	cout << "Subject 디폴트 생성자 호출\n";
}

Subject::Subject(string subName, int subHakjum, string subGrade) {
	m_name = subName;
	m_hakjum = subHakjum;
	m_grade = subGrade;
	CalcGPA();
	cout << "Subject 인자있는 생성자 호출\n";
}

Subject::Subject(const Subject &sub) {
	m_name = sub.m_name;
	m_hakjum = sub.m_hakjum;
	m_grade = sub.m_grade;
	m_GPA = sub.m_GPA;
	cout << "Subject 복사 생성자 호출\n";
}

Subject::~Subject() {
	cout << "Subject 소멸자 호출\n";
}

void Subject::InputValue(string &str) {
	getline(cin, str);
}

void Subject::InputValue(int &i) {
	cin >> i;
	cin.ignore();
}

void Subject::InputData() {
	// 과목정보 입력
	cout << "교과목명 : ";
	InputValue(m_name);
	cout << "과목학점 : ";
	InputValue(m_hakjum);
	cout << "과목등급(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	CalcGPA();
}

void Subject::PrintTitle() {
	cout << "===============================================================\n";
	cout.width(15);
	cout << "교과목명";
	cout.width(15);
	cout << "학점수";
	cout.width(15);
	cout << "등급";
	cout.width(15);
	cout << "평점\n";
	cout << "===============================================================\n";
}

void Subject::PrintData() {
	PrintTitle();
	// 과목정보 출력
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << m_hakjum;
	cout.width(15);
	cout << m_grade;
	cout.width(15);
	cout << m_GPA << '\n';
}

void Subject::CalcGPA() {
	float result;

	//해당 과목의 grade를 비교하여 해당하는 평점을 저장
	if (m_grade == "A+")
		result = 4.5;
	else if (m_grade == "A0")
		result = 4.0;
	else if (m_grade == "B+")
		result = 3.5;
	else if (m_grade == "B0")
		result = 3.0;
	else if (m_grade == "C+")
		result = 2.5;
	else if (m_grade == "C0")
		result = 2.0;
	else if (m_grade == "D+")
		result = 1.5;
	else if (m_grade == "D0")
		result = 1.0;
	else
		result = 0.0;

	//완벽히 계산된 과목 평점 전달
	m_GPA = result * m_hakjum;
}

void Subject::Modify() {
	cout << "<" << m_name << ", " << m_hakjum << ", " << m_grade << ">의 정보를 수정하세요.\n";

	// Subject의 protected한 변수를 수정해야하기 때문에 Set함수가 필요
	cout << "교과목명 : ";
	InputValue(m_name);

	cout << "과목학점 : ";
	InputValue(m_hakjum);

	cout << "과목등급(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	//수정한 정보를 바탕으로 GPA수정
	CalcGPA();
}