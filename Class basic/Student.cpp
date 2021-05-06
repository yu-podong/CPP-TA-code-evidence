#include "Student.h"
#include <iostream>
using namespace std;

void Student::Initialize() {
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
}

void Student::Initialize(string stdName, int stdHakbun, int subnum, Subject* stdSub) {
	m_name = stdName;
	m_hakbun = stdHakbun;
	m_subnum = subnum;
	m_sub = stdSub;
	CalcAveGPA();
}

void Student::Remove() {
	delete[] m_sub;
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

	// 과목 정보 title
	m_sub->PrintTitle();
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
