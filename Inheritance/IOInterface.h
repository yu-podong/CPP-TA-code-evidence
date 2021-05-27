#pragma once
#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

class IOInterface {
	protected:	
		string m_name;
		int m_data;
	public:
		// ����Ʈ ������ �߰� ����
		IOInterface() {
			cout << "IOInterface�� ����Ʈ ������ ȣ��\n";
			m_name = "";
			m_data = 0;
		}
		// �����ִ� ������
		IOInterface(string m_name, int m_data) {
			cout << "IOInterface�� �����ִ� ������ ȣ��\n";
			this->m_name = m_name;
			this->m_data = m_data;
		}
		// �Ҹ���
		~IOInterface() {
			cout << "IOInterface�� �Ҹ��� ȣ��\n";
		}
		// ��������� �� �Է�
		void InputData() {
			InputUtil::InputValue(m_name);
			InputUtil::InputValue(m_data);
		}
		// ��������� �� ���
		void PrnitData() const {
			cout << m_name;
			cout << m_data;
		}
		//��������� �� ����
		void Modify() {
			cout << "���ο� m_name�� ���� �Է��ϼ��� : ";
			InputUtil::InputValue(m_name);
			cout << "���ο� m_data�� ���� �Է��ϼ��� : ";
			InputUtil::InputValue(m_data);
		}
		// ������ �Լ�
		string GetName() const {
			return m_name;
		}
		// ������ �Լ�
		int GetData() const {
			return m_data;
		}
};
