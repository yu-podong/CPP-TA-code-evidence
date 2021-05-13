#pragma once
#include <string>
using namespace std;

class Subject {
protected:
	string m_name;	// �����
	int m_hakjum;	// ����
	string m_grade;	// ���
	float m_GPA;	// ����
public:
	Subject();	// ����Ʈ ������
	Subject(string, int, string);	// �����ִ� ������
	Subject(const Subject &sub);	// ���������
	~Subject();						// �Ҹ���
	void InputValue(int &);
	void InputValue(string &);
	void InputData();	// ������� �� �Է�
	void PrintTitle();	// ��������� ���� title Text ���
	void PrintData();	// ������� �� ���
	void CalcGPA();		// ���� ���
	void Modify();		// ���� ���� ����

	// ������ �Լ�
	// Set�Լ�
	void SetName(string subName) {
		m_name = subName;
	}
	void SetHakjum(int subHakjum) {
		m_hakjum = subHakjum;
	}
	void SetGrade(string subGrade) {
		m_grade = subGrade;
	}
	void SetGPA(float subGPA) {
		m_GPA = subGPA;
	}

	// Get�Լ�
	string GetName() {
		return m_name;
	}
	int GetHakjum() {
		return m_hakjum;
	}
	string GetGrade() {
		return m_grade;
	}
	float GetGPA() {
		return m_GPA;
	}
};