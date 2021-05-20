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

	///* CODE1. SubSearch() test */
	//// 디폴트 생성자 호출
	//Student std;

	//// std에 학생정보와 과목 정보 입력
	//std.InputData();

	//// std의 정보를 출력
	//std.PrintData();

	//// std에 해당 과목이 있는지 탐색
	//Subject* sub = std.SubSearch("사진학");
	//
	//// 과목명이 성공적으로 탐색된 경우
	//// 해당 과목정보가 있는 메모리 주소를 리턴
	//if (sub != NULL) {
	//	sub->PrintTitle();
	//	sub->PrintData();
	//}

	///* CODE2. static과 const 멤버함수 test */
	//// 각 과목정보를 저장할 Subject 객체 생성 (인자있는 생성자 호출)
	//Subject sub1("컴퓨터", 3, "C0"); 
	//Subject sub2("계산기", 2, "A0");

	//// static 멤버함수 출력
	//Subject::PrintTitle();

	//// 각 과목정보 출력
	//sub1.PrintData();
	//sub2.PrintData();

	//// 학생정보와 과목정보를 저장할 Student객채 생성 (인자있는 생성자 호출)
	//Student st1("홍길동", 2013909845, 1, &sub1);

	//// 해당 학생의 학생정보와 과목 정보 호출
	//st1.PrintData();

	//// 주의 : Get함수가 const가 아니라면 error 발생
	//Data(st1);
	
	/* CODE3. 여러가지 객체 생성 방법 test */
	// 객체 배열 생성 (각 원소를 생성자로 초기화)
	Subject sub1[2] = { Subject("컴퓨터", 3, "C0"), Subject("현대무용", 2, "A0") };
	// 포인터 객체 배열 생성 (각 원소를 생성자로 초기화)
	Subject *sub2[2] = { new Subject(), new Subject("수학", 3, "C0") };
	// 객체 생성
	Student st1;
	// 객체 생성 (인자있는 생성자로 초기화)
	Student st2("홍길동", 2013909845, 2, sub1);
	// 포인터 생성 (각 원소를 디폴트 생성자로 초기화)
	Student *st3 = new Student[2];

	// sub[0] 입력
	cout << "\n" << "sub2[0] 입력" << "\n";
	sub2[0]->InputData();

	// st1 입력 - m_sub = sub1
	cout << "\n" << "st1 입력" << "\n";
	st1.InputData();

	// st3의 모든 원소에 대한 값 입력
	cout << "\n" << "st3 입력" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->InputData();

	// sub1 출력
	cout << "\n" << "sub1 정보 출력" << "\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++) 
		sub1[i].PrintData();

	// sub2 출력
	cout << "\n" << "sub2 정보 출력" << "\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++) {
		sub2[i]->PrintData();
	}

	cout << "\n" << "st1 정보 출력" << "\n";
	st1.PrintData();

	cout << "\n" << "st2 정보 출력" << "\n";
	st2.PrintData();

	cout << "\n" << "st3 정보 출력" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->PrintData();
}