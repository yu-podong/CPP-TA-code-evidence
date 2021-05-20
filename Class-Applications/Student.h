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
		void InputData();	// ������� �� �Է�
		void PrintData() const;	// ������� �� ���
		void CalcAveGPA();	// ��� ���� ���
		void Modify();		// �л� ���� ����
		void stdInfoModify();	// �л��� ���� ���� ����
		Subject* SubSearch(string subName) const;	// ã���� �ϴ� ������ Ž��

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
		// Get�Լ��� const�� �ƴ϶��, const��ü�� get�Լ��� ȣ���� �� error �߻�
		string GetName()const {
			return m_name;
		}
		int GetHakbun() const {
			return m_hakbun;
		}
		int GetSubNum() const {
			return m_subnum;
		}
		float GetAveGPA() const {
			return m_aveGPA;
		}
};