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
	/*
	// CODE 1. IOInterface ��� test
	// IOInterface() �߰� �� error �߻� ����
	// : �Ļ�Ŭ������ std�� �����ϸ�, �⺻Ŭ������ ������ ȣ�� -> �Ļ�Ŭ������ ������ ȣ��
	//   �׷���, �Ļ�Ŭ������ �����ڿ� �⺻Ŭ������ Ư�� �����ڸ� �ۼ����� �ʾҴٸ�, ����Ʈ �����ڰ� ȣ��
	//   ��, IOInterface class���� ����Ʈ �����ڰ� ��� �߻��ߴ� ����
	Student std;
	cout << std.GetData() << "\n";*/

	/*
	// CODE 2. �⺻Ŭ������ �Ļ�Ŭ������ ����
	Subject sub("��ǻ��", 3, "C0");

	cout << "-----------------------------\n";
	// IOInterface Class���� ��ӹ��� GetData() ȣ�� -> IOInterface�� m_data ȣ��;
	cout << "m_data : " << sub.IOInterface::GetData() << "\n";
	// Subject Class���� �����ǵ� GetName() ȣ�� -> ���� �̸� ���
	cout << "������ �̸� : " << sub.GetName() << "\n";
	// IOInterface Class�� GetName() ȣ�� -> IOInterface�� m_name ȣ��
	cout << "�θ�Ŭ������ �̸� : " << sub.IOInterface::GetName() << "\n";
	cout << "-----------------------------\n\n";

	Student std("ȫ�浿", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	// IOInterface Class���� ��ӹ��� GetData() ȣ��;
	cout << "m_data : " <<  std.IOInterface::GetData() << "\n";
	// Student Class���� �����ǵ� GetName() ȣ��;
	cout << "�л� �̸� : " << std.GetName() << "\n";
	// IOInterface Class�� GetName() ȣ��;
	cout << "�θ�Ŭ������ �̸� : " << std.IOInterface::GetName() << "\n";
	cout << "-----------------------------\n\n";*/

	// CODE 3. Student class�� Modify() ����Լ� ����
	Subject sub("��ǻ��", 3, "C0");
	Student std("ȫ�浿", 20138342, 1, &sub);

	// ���� �� ������ ���
	std.PrintData();
	// Student Class�� ������� �� ����
	std.Modify(); 
	// ������ ������ ���
	std.PrintData();
}