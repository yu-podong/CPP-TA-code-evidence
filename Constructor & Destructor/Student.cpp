#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
	cout << "Student ����Ʈ ������ ȣ��\n";
}

Student::Student(string stdName, int stdHakbun, int subnum, Subject* stdSub) {
	m_name = stdName;
	m_hakbun = stdHakbun;
	m_subnum = subnum;
	// ���� ���縦 ���� ���ο� ���� �޸� �Ҵ�
	// ���� ���� �޸𸮸� ���� m_sub���� stdSub�� ���� ����
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].SetName(stdSub[i].GetName());
		m_sub[i].SetHakjum(stdSub[i].GetHakjum());
		m_sub[i].SetGrade(stdSub[i].GetGrade());
		m_sub[i].SetGPA(stdSub[i].GetGPA());
	}
	CalcAveGPA();
	cout << "Student �����ִ� ������ ȣ��\n";
}
Student::Student(const Student &std) {
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	// ���� ���縦 ���� ���ο� ���� �޸� �Ҵ�
	// ���� ���� �޸𸮸� ���� m_sub���� stdSub�� ���� ����
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].SetName(std.m_sub[i].GetName());
		m_sub[i].SetHakjum(std.m_sub[i].GetHakjum());
		m_sub[i].SetGrade(std.m_sub[i].GetGrade());
		m_sub[i].SetGPA(std.m_sub[i].GetGPA());
	}
	m_aveGPA = std.m_aveGPA;
	cout << "Student ���� ������ ȣ��\n";
}

Student::~Student() {
	cout << "Student �Ҹ��� ȣ��\n";
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

void Student::stdInfoModify() {
	//������ ����ü�̱⿡ -> �̿�
	cout << "< " << GetName() << ", " << GetHakbun() << ">�� ������ �����ϼ���.\n";

	//�˻��� �л��� �̸��� �й� ����
	cout << "�̸� : ";
	InputValue(m_name);
	cout << "�й� : ";
	InputValue(m_hakbun);
	cout << "\n";
}

void Student::Modify() {
	string modifyInfo;

	//�����ϰ��� ���� �Է�
	cout << "\n������ ������ �����ϼ��� <�л����� / �������� / ���> : ";
	InputValue(modifyInfo);
	cout << '\n';

	//�л� ������ �Է��� ���
	if (modifyInfo == "�л� ����" || modifyInfo == "�л�����") {
		stdInfoModify();
	}
	//���� ������ �Է��� ���
	else if (modifyInfo == "���� ����" || modifyInfo == "��������") {
		// �ش� �л��� �����ϰ� �ִ� ��� ���� ������ ����
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify();
		}
		//������ ������ �������� AveGPA����
		CalcAveGPA();
	}
	// ��θ� �Է��� ���
	else if (modifyInfo == "���") {
		// �л��� ���� ���� ����
		stdInfoModify();
		// �л��� ��� ���� ���� ����
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify();
		}
		//������ ������ �������� AveGPA����
		CalcAveGPA();
	}
	//�߸� �Է��� ���
	else {
		cout << "<�����ϰ��� �ϴ� ������ ��Ȯ�� �Է����ּ���.>\n\n";
	}
}