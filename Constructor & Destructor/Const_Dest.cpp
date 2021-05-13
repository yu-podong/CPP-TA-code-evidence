#include "Student.h"
#include "Subject.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	
	Subject sub1("컴퓨터", 3, "C0");
	Subject sub2(sub1);

	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintData();

	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintData();

	sub2.Modify();

	//------------------------------------------------------
	
	Student st2("홍길동", 2013909845, 1, &sub1);
	Student st3("김성령", 2015909845, 1, &sub2);

	// st1 = st2; <- 깊은 복사가 이루어지지 않음
	Student st1(st2);

	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();

	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();

	st2.Modify();

	cout << "\n" << "수정된 st2 정보" << "\n";
	st2.PrintData();

	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();

	cout << "\n" << "st3 정보" << "\n";
	st3.PrintData();
}
