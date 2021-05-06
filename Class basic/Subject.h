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
		void Initialize();	// ������� �ʱ�ȭ
		void Initialize(string, int, string);	// ���ڰ����� ������� �ʱ�ȭ
		void InputValue(int &);
		void InputValue(string &);
		void InputData();	// ������� �� �Է�
		void PrintTitle();	// ��������� ���� title Text ���
		void PrintData();	// ������� �� ���
		void CalcGPA();		// ���� ���

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