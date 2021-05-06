#include "Subject.h"
#include "Student.h"
#include <iostream>	
#include <iomanip>
using namespace std;

void ShowData(const Student &s) { // 응용프로그램에 있는 전역함수
	cout << s.m_name << "이 수강한 과목은 총" << s.m_subnum << "개로 ";
	cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
}

int main() {
	/*int i;
	Subject sub1, sub2, sub3[2], *sub4;

	// 객체 초기화
	sub1.Initialize();
	sub2.Initialize("사진학", 3, "A+");

	// 객체 배열의 각 원소 초기화
	for (i = 0; i < 2; i++)
		sub3[i].Initialize("컴퓨터", 3, "C");

	// 객체 배열을 동적 메모리로 할당
	sub4 = new Subject[2];

	// 해당 객체의 각 멤버변수를 입력
	sub1.InputData();

	// sub1객체의 멤버값 출력 (입력한 값 출력)
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle(); 
	sub1.PrintData();

	// sub2객체의 멤버값 출력
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintTitle(); 
	sub2.PrintData();

	// sub3 객체 배열의 각 원소 멤버값 출력
	cout << "\n" << "sub3 정보" << "\n";
	sub3[0].PrintTitle();
	for (i = 0; i < 2; i++) 
		sub3[i].PrintData();

	// sub4 동적 객체 배열의 각 원소 멤버값 출력
	cout << "\n" << "sub4 정보" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++) 
		// 아무 값도 입력하지 않았으므로, 쓰레기값 출력
		(sub4 + i)->PrintData();

	delete[] sub4;*/

	// 과목 객체 생성 및 초기화
	Subject sub[2];
	sub[0].Initialize("컴퓨터", 3, "C0");
	sub[1].Initialize("현대무용", 2, "A0");

	//학생 객체 생성 및 초기화
	Student st1, st2;
	st1.Initialize("test", 0, 2, new Subject[2]);
	st2.Initialize("홍길동", 2013909845, 2, sub);

	// st1의 멤버변수의 값을 입력
	
	st1.InputData();

	cout.precision(2);
	cout << fixed;

	//st1 정보 출력
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();

	// st2 정보 출력
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();

	// friend 함수 실행
	ShowData(st2);

	// st1의 m_sub에 할당했던 메모리 해제
	st1.Remove();
	return 0;
}