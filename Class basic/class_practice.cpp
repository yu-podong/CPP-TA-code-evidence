#include "Subject.h"
#include "Student.h"
#include <iostream>	
#include <iomanip>
using namespace std;

void ShowData(const Student &s) { // �������α׷��� �ִ� �����Լ�
	cout << s.m_name << "�� ������ ������ ��" << s.m_subnum << "���� ";
	cout << "������ ������ ���������" << s.m_aveGPA << "�Դϴ�.\n";
}

int main() {
	/*int i;
	Subject sub1, sub2, sub3[2], *sub4;

	// ��ü �ʱ�ȭ
	sub1.Initialize();
	sub2.Initialize("������", 3, "A+");

	// ��ü �迭�� �� ���� �ʱ�ȭ
	for (i = 0; i < 2; i++)
		sub3[i].Initialize("��ǻ��", 3, "C");

	// ��ü �迭�� ���� �޸𸮷� �Ҵ�
	sub4 = new Subject[2];

	// �ش� ��ü�� �� ��������� �Է�
	sub1.InputData();

	// sub1��ü�� ����� ��� (�Է��� �� ���)
	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintTitle(); 
	sub1.PrintData();

	// sub2��ü�� ����� ���
	cout << "\n" << "sub2 ����" << "\n";
	sub2.PrintTitle(); 
	sub2.PrintData();

	// sub3 ��ü �迭�� �� ���� ����� ���
	cout << "\n" << "sub3 ����" << "\n";
	sub3[0].PrintTitle();
	for (i = 0; i < 2; i++) 
		sub3[i].PrintData();

	// sub4 ���� ��ü �迭�� �� ���� ����� ���
	cout << "\n" << "sub4 ����" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++) 
		// �ƹ� ���� �Է����� �ʾ����Ƿ�, �����Ⱚ ���
		(sub4 + i)->PrintData();

	delete[] sub4;*/

	// ���� ��ü ���� �� �ʱ�ȭ
	Subject sub[2];
	sub[0].Initialize("��ǻ��", 3, "C0");
	sub[1].Initialize("���빫��", 2, "A0");

	//�л� ��ü ���� �� �ʱ�ȭ
	Student st1, st2;
	st1.Initialize("test", 0, 2, new Subject[2]);
	st2.Initialize("ȫ�浿", 2013909845, 2, sub);

	// st1�� ��������� ���� �Է�
	
	st1.InputData();

	cout.precision(2);
	cout << fixed;

	//st1 ���� ���
	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData();

	// st2 ���� ���
	cout << "\n" << "st2 ����" << "\n";
	st2.PrintData();

	// friend �Լ� ����
	ShowData(st2);

	// st1�� m_sub�� �Ҵ��ߴ� �޸� ����
	st1.Remove();
	return 0;
}