#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject() {
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
	cout << "Subject ����Ʈ ������ ȣ��\n";
}

Subject::Subject(string subName, int subHakjum, string subGrade) {
	m_name = subName;
	m_hakjum = subHakjum;
	m_grade = subGrade;
	CalcGPA();
	cout << "Subject �����ִ� ������ ȣ��\n";
}

Subject::Subject(const Subject &sub) {
	m_name = sub.m_name;
	m_hakjum = sub.m_hakjum;
	m_grade = sub.m_grade;
	m_GPA = sub.m_GPA;
	cout << "Subject ���� ������ ȣ��\n";
}

Subject::~Subject() {
	cout << "Subject �Ҹ��� ȣ��\n";
}

void Subject::InputValue(string &str) {
	getline(cin, str);
}

void Subject::InputValue(int &i) {
	cin >> i;
	cin.ignore();
}

void Subject::InputData() {
	// �������� �Է�
	cout << "������� : ";
	InputValue(m_name);
	cout << "�������� : ";
	InputValue(m_hakjum);
	cout << "������(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	CalcGPA();
}

void Subject::PrintTitle() {
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "���";
	cout.width(15);
	cout << "����\n";
	cout << "===============================================================\n";
}

void Subject::PrintData() {
	PrintTitle();
	// �������� ���
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

	//�ش� ������ grade�� ���Ͽ� �ش��ϴ� ������ ����
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

	//�Ϻ��� ���� ���� ���� ����
	m_GPA = result * m_hakjum;
}

void Subject::Modify() {
	cout << "<" << m_name << ", " << m_hakjum << ", " << m_grade << ">�� ������ �����ϼ���.\n";

	// Subject�� protected�� ������ �����ؾ��ϱ� ������ Set�Լ��� �ʿ�
	cout << "������� : ";
	InputValue(m_name);

	cout << "�������� : ";
	InputValue(m_hakjum);

	cout << "������(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	//������ ������ �������� GPA����
	CalcGPA();
}