#pragma once
#include <iostream>
#include <string>
using namespace std;

// �پ��� type�� �Է¹޴� class
class InputUtil {
	public:
		inline static void InputValue(int &numInt) {
			cin >> numInt;
			// I/O ������ �߻��ϸ�
			while (cin.fail() == 1) { 
				// ��� ������Ʈ clear
				cin.clear();
				// buffer ���θ� ��� ���
				cin.ignore(); 
				// �ٽ� �Է�
				cout << "�߸��� ���� �ԷµǾ����Ƿ�, �ٽ� �Է��� �ּ��� : \n";
				cin >> numInt;
			}

			cin.ignore();
		}
		inline static void InputValue(string &str) {
			getline(cin,str);

			// I/O ������ �߻��ϸ�
			while (cin.fail() == 1) {
				// ��� ������Ʈ clear
				cin.clear();
				// buffer ���θ� ��� ���
				cin.ignore();
				// �ٽ� �Է�
				cout << "�߸��� ���� �ԷµǾ����Ƿ�, �ٽ� �Է��� �ּ��� : \n";
				cin >> str;
			}
		}
		inline static void InputValue(char *ch) {
			cin >> ch;

			// I/O ������ �߻��ϸ�
			while (cin.fail() == 1) {
				// ��� ������Ʈ clear
				cin.clear();
				// buffer ���θ� ��� ���
				cin.ignore();
				// �ٽ� �Է�
				cout << "�߸��� ���� �ԷµǾ����Ƿ�, �ٽ� �Է��� �ּ��� : \n";
				cin >> ch;
			}
			cin.ignore();
		}
		inline static void InputValue(float &numFloat) {
			cin >> numFloat;

			// I/O ������ �߻��ϸ�
			while (cin.fail() == 1) {
				// ��� ������Ʈ clear
				cin.clear();
				// buffer ���θ� ��� ���
				cin.ignore();
				cout << "�߸��� ���� �ԷµǾ����Ƿ�, �ٽ� �Է��� �ּ��� : \n";
				cin >> numFloat;
			}
			cin.ignore();
		}
		inline static void InputValue(double &numDouble) {
			cin >> numDouble;

			// I/O ������ �߻��ϸ�
			while (cin.fail() == 1) {
				// ��� ������Ʈ clear
				cin.clear();
				// buffer ���θ� ��� ���
				cin.ignore();
				cout << "�߸��� ���� �ԷµǾ����Ƿ�, �ٽ� �Է��� �ּ��� : \n";
				cin >> numDouble;
			}
			cin.ignore();
		}
};
