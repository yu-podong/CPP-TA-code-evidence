#include "Student.h"
#include "Subject.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	
	Subject sub1("��ǻ��", 3, "C0");
	Subject sub2(sub1);

	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintData();

	cout << "\n" << "sub2 ����" << "\n";
	sub2.PrintData();

	sub2.Modify();

	//------------------------------------------------------
	
	Student st2("ȫ�浿", 2013909845, 1, &sub1);
	Student st3("�輺��", 2015909845, 1, &sub2);

	// st1 = st2; <- ���� ���簡 �̷������ ����
	Student st1(st2);

	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData();

	cout << "\n" << "st2 ����" << "\n";
	st2.PrintData();

	st2.Modify();

	cout << "\n" << "������ st2 ����" << "\n";
	st2.PrintData();

	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData();

	cout << "\n" << "st3 ����" << "\n";
	st3.PrintData();
}
