#include "Student.h"
#include "Subject.h"
#include <string>
#include <iostream>
using namespace std;

void Data(const Student &s) { // 응용프로그램에 있는 전역함수
	cout << s.GetName() << "이 수강한 과목은 총" << s.GetSubNum() << "개로";
	cout << "수강한 과목의 평균평점은" << s.GetAveGPA() << "입니다.\n";
}

void main() {
	/*
	// CODE 1. IOInterface 상속 test
	// IOInterface() 추가 전 error 발생 원인
	// : 파생클래스인 std을 선언하면, 기본클래스의 생성자 호출 -> 파생클래스의 생성자 호출
	//   그러나, 파생클래스의 생성자에 기본클래스의 특정 생성자를 작성하지 않았다면, 디폴트 생성자가 호출
	//   즉, IOInterface class에는 디폴트 생성자가 없어서 발생했던 문제
	Student std;
	cout << std.GetData() << "\n";*/

	/*
	// CODE 2. 기본클래스와 파생클래스의 관계
	Subject sub("컴퓨터", 3, "C0");

	cout << "-----------------------------\n";
	// IOInterface Class에서 상속받은 GetData() 호출 -> IOInterface의 m_data 호출;
	cout << "m_data : " << sub.IOInterface::GetData() << "\n";
	// Subject Class에서 재정의된 GetName() 호출 -> 과목 이름 출력
	cout << "교과목 이름 : " << sub.GetName() << "\n";
	// IOInterface Class의 GetName() 호출 -> IOInterface의 m_name 호출
	cout << "부모클래스의 이름 : " << sub.IOInterface::GetName() << "\n";
	cout << "-----------------------------\n\n";

	Student std("홍길동", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	// IOInterface Class에서 상속받은 GetData() 호출;
	cout << "m_data : " <<  std.IOInterface::GetData() << "\n";
	// Student Class에서 재정의된 GetName() 호츨;
	cout << "학생 이름 : " << std.GetName() << "\n";
	// IOInterface Class의 GetName() 호출;
	cout << "부모클래스의 이름 : " << std.IOInterface::GetName() << "\n";
	cout << "-----------------------------\n\n";*/

	// CODE 3. Student class의 Modify() 멤버함수 수정
	Subject sub("컴퓨터", 3, "C0");
	Student std("홍길동", 20138342, 1, &sub);

	// 수정 전 정보를 출력
	std.PrintData();
	// Student Class의 멤버변수 값 수정
	std.Modify(); 
	// 수정한 정보를 출력
	std.PrintData();
}