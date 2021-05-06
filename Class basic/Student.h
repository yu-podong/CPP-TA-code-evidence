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
		void Initialize();	// ������� �ʱ�ȭ
		void Initialize(string, int, int, Subject*);	// ���ڰ����� ������� �ʱ�ȭ
		void Remove();		// �����޸� ����(m_sub)
		void InputValue(int &);
		void InputValue(string &);
		void InputData();	// ������� �� �Է�
		void PrintData();	// ������� �� ���
		void CalcAveGPA();	// ��� ���� ���

		// ������ �Լ�
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