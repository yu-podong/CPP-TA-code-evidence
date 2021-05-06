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
	// �л����� �Է�
	cout << "�̸� : ";
	InputValue(m_name);
	cout << "�й� : ";
	InputValue(m_hakbun);

	// �������� �Է�
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData();
	}

	CalcAveGPA();
}

void Student::PrintData() {
	// �л� ���� title
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�̸� : ";
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << "�й� : ";
	cout.width(15);
	cout << m_hakbun << '\n';

	// ���� ���� title
	m_sub->PrintTitle();
	// ���� ���� ���
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "===============================================================\n";

	//�ش� �л��� ���� ��� ���� ���
	cout.width(45);
	cout << "������� : ";
	cout << m_aveGPA << '\n';
}

void Student::CalcAveGPA() {
	int sumHakjum = 0;
	float sumGPA = 0.0;

	for (int i = 0; i < m_subnum; i++) {
		//��� ������ ���� ����
		sumHakjum += m_sub[i].GetHakjum();
		//��� ������ ���� ����
		sumGPA += m_sub[i].GetGPA();
	}
	//���� ���� ��� ���� ����
	m_aveGPA = sumGPA / (float)sumHakjum;
}
