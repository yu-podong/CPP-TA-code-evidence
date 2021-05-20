#pragma once
#include <iostream>
#include <string>
using namespace std;

// 다양한 type을 입력받는 class
class InputUtil {
	public:
		inline static void InputValue(int &numInt) {
			cin >> numInt;
			// I/O 오류가 발생하면
			while (cin.fail() == 1) { 
				// 모든 오류비트 clear
				cin.clear();
				// buffer 내부를 모두 비움
				cin.ignore(); 
				// 다시 입력
				cout << "잘못된 값이 입력되었으므로, 다시 입력해 주세요 : \n";
				cin >> numInt;
			}

			cin.ignore();
		}
		inline static void InputValue(string &str) {
			getline(cin,str);

			// I/O 오류가 발생하면
			while (cin.fail() == 1) {
				// 모든 오류비트 clear
				cin.clear();
				// buffer 내부를 모두 비움
				cin.ignore();
				// 다시 입력
				cout << "잘못된 값이 입력되었으므로, 다시 입력해 주세요 : \n";
				cin >> str;
			}
		}
		inline static void InputValue(char *ch) {
			cin >> ch;

			// I/O 오류가 발생하면
			while (cin.fail() == 1) {
				// 모든 오류비트 clear
				cin.clear();
				// buffer 내부를 모두 비움
				cin.ignore();
				// 다시 입력
				cout << "잘못된 값이 입력되었으므로, 다시 입력해 주세요 : \n";
				cin >> ch;
			}
			cin.ignore();
		}
		inline static void InputValue(float &numFloat) {
			cin >> numFloat;

			// I/O 오류가 발생하면
			while (cin.fail() == 1) {
				// 모든 오류비트 clear
				cin.clear();
				// buffer 내부를 모두 비움
				cin.ignore();
				cout << "잘못된 값이 입력되었으므로, 다시 입력해 주세요 : \n";
				cin >> numFloat;
			}
			cin.ignore();
		}
		inline static void InputValue(double &numDouble) {
			cin >> numDouble;

			// I/O 오류가 발생하면
			while (cin.fail() == 1) {
				// 모든 오류비트 clear
				cin.clear();
				// buffer 내부를 모두 비움
				cin.ignore();
				cout << "잘못된 값이 입력되었으므로, 다시 입력해 주세요 : \n";
				cin >> numDouble;
			}
			cin.ignore();
		}
};
