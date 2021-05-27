#include "Student.h"
#include "InputUtil.h"
#include <iostream>
using namespace std;

Student::Student() {
	cout << "Student�� ����Ʈ ������ ȣ��\n";
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
}

Student::Student(string stdName, int stdHakbun, int subnum, Subject* stdSub) : IOInterface(stdName, 300){
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
	cout << "Student�� �����ִ� ������ ȣ��\n";
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
	cout << "Student�� ��������� ȣ��\n";
}

Student::~Student() {
	cout << "Student�� �Ҹ��� ȣ��\n";
	delete[] m_sub;
	m_sub = NULL;
}

void Student::InputData() {
	// �л����� �Է�
	cout << "�̸� : ";
	InputUtil::InputValue(m_name);
	cout << "�й� : ";
	InputUtil::InputValue(m_hakbun);
	cout << "������ ���� �� : ";
	InputUtil::InputValue(m_subnum);

	// �Է��� ���� ����ŭ ���� �޸� �Ҵ�
	m_sub = new Subject[m_subnum];

	// �������� �Է�
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData();
	}

	CalcAveGPA();
}

void Student::PrintData() const {
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
	Subject::PrintTitle();
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
	InputUtil::InputValue(m_name);
	cout << "�й� : ";
	InputUtil::InputValue(m_hakbun);
	cout << "\n";
}

void Student::Modify() {
	string modifyInfo;
	string modifySubName;
	Subject *findSub = NULL;
	//�����ϰ��� ���� �Է�
	cout << "\n������ ������ �����ϼ��� <�л����� / �������� / ���> : ";
	InputUtil::InputValue(modifyInfo);
	cout << '\n';

	//�л� ������ �Է��� ���
	if (modifyInfo == "�л� ����" || modifyInfo == "�л�����") {
		stdInfoModify();
	}
	//���� ������ �Է��� ���
	else if (modifyInfo == "���� ����" || modifyInfo == "��������") {
		// �����ϰ��� ���� ������ �Է�
		cout << "�����ϰ����ϴ� ������ �̸��� �Է��ϼ��� : ";
		InputUtil::InputValue(modifySubName);
		// �Է��� �����̸��� ������ �ش� �л��� �����ϴ� ����� ��
		findSub = SubSearch(modifySubName);

		// �ش� �л��� �����ϰ� �ִ� �ش� ���� ������ ����
		if (findSub != NULL) {
			findSub->Modify();
			//������ ������ �������� AveGPA����
			CalcAveGPA();
		}
		else {
			cout << "�˻��� ������ �ش��л��� �������� �ʽ��ϴ�.\n";
		}
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

Subject* Student::SubSearch(string subName) const {
	// �ش� �л��� �����ϴ� ���� ����ŭ for�� ����
	for (int i = 0; i < m_subnum; i++) {
		// ���������� Ž���� ���
		if (subName == m_sub[i].GetName()) {
			return &m_sub[i];
		}
	}
	// ã���� �ϴ� ������ �ش� �л��� �������� ���� ���
	cout << "<<ã���ô� �������� �����ϴ�.>>\n";

	return NULL;
}