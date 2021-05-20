#include "Student.h"
#include "Subject.h"
#include <string>
#include <iostream>
using namespace std;

void Data(const Student &s) { // �������α׷��� �ִ� �����Լ�
	cout << s.GetName() << "�� ������ ������ ��" << s.GetSubNum() << "����";
	cout << "������ ������ ���������" << s.GetAveGPA() << "�Դϴ�.\n";
}

void main() {

	///* CODE1. SubSearch() test */
	//// ����Ʈ ������ ȣ��
	//Student std;

	//// std�� �л������� ���� ���� �Է�
	//std.InputData();

	//// std�� ������ ���
	//std.PrintData();

	//// std�� �ش� ������ �ִ��� Ž��
	//Subject* sub = std.SubSearch("������");
	//
	//// ������� ���������� Ž���� ���
	//// �ش� ���������� �ִ� �޸� �ּҸ� ����
	//if (sub != NULL) {
	//	sub->PrintTitle();
	//	sub->PrintData();
	//}

	///* CODE2. static�� const ����Լ� test */
	//// �� ���������� ������ Subject ��ü ���� (�����ִ� ������ ȣ��)
	//Subject sub1("��ǻ��", 3, "C0"); 
	//Subject sub2("����", 2, "A0");

	//// static ����Լ� ���
	//Subject::PrintTitle();

	//// �� �������� ���
	//sub1.PrintData();
	//sub2.PrintData();

	//// �л������� ���������� ������ Student��ä ���� (�����ִ� ������ ȣ��)
	//Student st1("ȫ�浿", 2013909845, 1, &sub1);

	//// �ش� �л��� �л������� ���� ���� ȣ��
	//st1.PrintData();

	//// ���� : Get�Լ��� const�� �ƴ϶�� error �߻�
	//Data(st1);
	
	/* CODE3. �������� ��ü ���� ��� test */
	// ��ü �迭 ���� (�� ���Ҹ� �����ڷ� �ʱ�ȭ)
	Subject sub1[2] = { Subject("��ǻ��", 3, "C0"), Subject("���빫��", 2, "A0") };
	// ������ ��ü �迭 ���� (�� ���Ҹ� �����ڷ� �ʱ�ȭ)
	Subject *sub2[2] = { new Subject(), new Subject("����", 3, "C0") };
	// ��ü ����
	Student st1;
	// ��ü ���� (�����ִ� �����ڷ� �ʱ�ȭ)
	Student st2("ȫ�浿", 2013909845, 2, sub1);
	// ������ ���� (�� ���Ҹ� ����Ʈ �����ڷ� �ʱ�ȭ)
	Student *st3 = new Student[2];

	// sub[0] �Է�
	cout << "\n" << "sub2[0] �Է�" << "\n";
	sub2[0]->InputData();

	// st1 �Է� - m_sub = sub1
	cout << "\n" << "st1 �Է�" << "\n";
	st1.InputData();

	// st3�� ��� ���ҿ� ���� �� �Է�
	cout << "\n" << "st3 �Է�" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->InputData();

	// sub1 ���
	cout << "\n" << "sub1 ���� ���" << "\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++) 
		sub1[i].PrintData();

	// sub2 ���
	cout << "\n" << "sub2 ���� ���" << "\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++) {
		sub2[i]->PrintData();
	}

	cout << "\n" << "st1 ���� ���" << "\n";
	st1.PrintData();

	cout << "\n" << "st2 ���� ���" << "\n";
	st2.PrintData();

	cout << "\n" << "st3 ���� ���" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->PrintData();
}