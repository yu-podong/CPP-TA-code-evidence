#pragma once
#include "Subject.h"
#include <string>
using namespace std;

class Student {
protected:
	string m_name;	// �л���
	int m_hakbun;	// �й�
	int m_subnum;	// ������ ���� �� 
	Subject *m_sub;	// ������ �����
	float m_aveGPA;	// ������ ������� ��� ����
public:
	Student();	// ����Ʈ ������
	Student(string, int, int, Subject*);	// �����ִ� ������ (���� ����)
	Student(const Student &std);			// ��������� (���� ����)
	~Student();	// �Ҹ���
	void InputValue(int &);
	void InputValue(string &);
	void InputData();	// ������� �� �Է�
	void PrintData();	// ������� �� ���
	void CalcAveGPA();	// ��� ���� ���
	void Modify();		// �л� ���� ����
	void stdInfoModify();	// �л��� ���� ���� ����

	// ������ �Լ�
	// Set�Լ�
	void SetName(string stdName) {
		m_name = stdName;
	}
	void SetHakbun(int stdHakbun) {
		m_hakbun = stdHakbun;
	}
	void SetSubNum(int stdSubNum) {
		m_subnum = stdSubNum;
	}
	void SetSub(Subject* sub) {
		m_sub = sub;
	}
	void SetAveGPA(float stdAveGPA) {
		m_aveGPA = stdAveGPA;
	}
	// Get�Լ�
	string GetName() {
		return m_name;
	}
	int GetHakbun() {
		return m_hakbun;
	}
	int GetSubNum() {
		return m_subnum;
	}
	float GetAveGPA() {
		return m_aveGPA;
	}

	// friend �Լ�
	friend void ShowData(const Student &s);
};