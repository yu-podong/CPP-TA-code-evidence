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
		// 디폴트 생성자 추가 생성
		IOInterface() {
			cout << "IOInterface의 디폴트 생성자 호출\n";
			m_name = "";
			m_data = 0;
		}
		// 인자있는 생성자
		IOInterface(string m_name, int m_data) {
			cout << "IOInterface의 인자있는 생성자 호출\n";
			this->m_name = m_name;
			this->m_data = m_data;
		}
		// 소멸자
		~IOInterface() {
			cout << "IOInterface의 소멸자 호출\n";
		}
		// 멤버변수의 값 입력
		void InputData() {
			InputUtil::InputValue(m_name);
			InputUtil::InputValue(m_data);
		}
		// 멤버변수의 값 출력
		void PrnitData() const {
			cout << m_name;
			cout << m_data;
		}
		//멤버변수의 값 수정
		void Modify() {
			cout << "새로운 m_name의 값을 입력하세요 : ";
			InputUtil::InputValue(m_name);
			cout << "새로운 m_data의 값을 입력하세요 : ";
			InputUtil::InputValue(m_data);
		}
		// 접근자 함수
		string GetName() const {
			return m_name;
		}
		// 접근자 함수
		int GetData() const {
			return m_data;
		}
};
