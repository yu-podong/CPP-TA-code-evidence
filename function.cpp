/*
	<������ �Լ�>
	1. �޴� ��� �Լ�
	2. ���� ��� �Լ�
	3. ������ ���� ��� �Լ�
	4. ��ü �л� ���� ��� �Լ�
	5. ���� �л� ���� ��� �Լ�
	6. �л� �̸� �˻� �Լ�
*/
#include <iostream>	
#include <iomanip>	
#include <cstring>	
using namespace std;

struct Subject {
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};
struct Student {
	char StdName[30];
	int Hakbun;
	Subject Sub[3];
	float AveGPA;
};

void PrintMenu();
void inputStd(Student *std);
void inputSub(Subject *sub);
float calcGPA(Subject &sub);
float calcAveGPA(Subject* sub);
void PrintAllData(const Student *pst, int StudentNum);
void printSub(const Subject *sub);
void PrintOneData(const Student &rst);
void Search(Student *pst, int StudentNum);
Student* StdSearch(Student *pst, int StudentNum);

int menuNum;

int main() {
	Student student[2];
	cout.precision(2);
	cout << fixed;

	while (1) {
		PrintMenu();

		//2���� �л� ���� �Է�
		if (menuNum == 1) {
			inputStd(student);
		}
		//��ü�л� ���� ���
		else if (menuNum == 2) {
			PrintAllData(student, 2);
		}
		//���ϴ� �л��� ���� ���
		else if (menuNum == 3) {
			Search(student, 2);
		}
		//���α׷� ����
		else if (menuNum == 4){
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
		//��µ� �޴��� ���� ��ȣ�� �������� ���
		else {
			cout << "<���� �޴� ��ȣ�� �����ϼ̽��ϴ�.>\n";
		}
	}
	return 0;
}
void PrintMenu() {
	cout << "==========�޴�==========\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ���α׷� ����\n" << "\n";

	cout << "���ϴ� ����� �Է��ϼ��� : ";
	cin >> menuNum;
	cout << "\n";
}
void inputStd(Student *std) {
	for (int i = 0; i < 2; i++) {
		cout << "* " << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		cin >> std[i].StdName;
		cout << "�й� : ";
		cin >> std[i].Hakbun;
		cout << "\n\n";

		//�ش� �л��� ������ ���� ���� �Է�
		inputSub(std[i].Sub);
		//�ش� �л��� ���� ��� ���� ���
		std[i].AveGPA = calcAveGPA(std[i].Sub);
	}
}
void inputSub(Subject *sub) {
	float sumGPA = 0.0;

	cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
	for (int j = 0; j < 3; j++) {
		cout << "������� : ";
		cin >> sub[j].SubName;
		cout << "�������� : ";
		cin >> sub[j].Hakjum;
		cout << "������(A+ ~ F) : ";
		cin >> sub[j].Grade;
		cout << "\n";

		sub[j].GPA = calcGPA(sub[j]);
	}
	cout << "\n\n";
}
float calcGPA(Subject &sub) {
	float result;
	//�ش� ������ grade�� ���Ͽ� �ش��ϴ� ������ ����
	if (strcmp(sub.Grade, "A+") == 0)
		result = 4.5;
	else if (strcmp(sub.Grade, "A0") == 0)
		result = 4.0;
	else if (strcmp(sub.Grade, "B+") == 0)
		result = 3.5;
	else if (strcmp(sub.Grade, "B0") == 0)
		result = 3.0;
	else if (strcmp(sub.Grade, "C+") == 0)
		result = 2.5;
	else if (strcmp(sub.Grade, "C0") == 0)
		result = 2.0;
	else if (strcmp(sub.Grade, "D+") == 0)
		result = 1.5;
	else if (strcmp(sub.Grade, "D0") == 0)
		result = 1.0;
	else
		result = 0.0;

	//�Ϻ��� ���� ���� ���� ����
	return result * sub.Hakjum;
}

float calcAveGPA(Subject *sub) {
	int sumHakjum = 0;
	float sumGPA = 0.0;
	for (int i = 0; i < 3; i++) {
		//��� ������ ���� ����
		sumHakjum += sub[i].Hakjum;
		//��� ������ ���� ����
		sumGPA += sub[i].GPA;
	}
	//���� ���� ��� ���� ����
	return sumGPA / (float)sumHakjum;
}

void PrintAllData(const Student *pst, int StudentNum) {
	cout << "               ��ü �л� ���� ����" << '\n';
	cout << "===============================================================\n";

	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pst[i]);
	}
}

void PrintOneData(const Student &rst) {
	//��µ� �������� ȭ�鿡 ǥ��
	cout << "�̸� : " << rst.StdName << "  �й� : " << rst.Hakbun << "\n";
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�����";
	cout.width(15);
	cout << "��������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "��������\n";
	cout << "===============================================================\n";

	//�ش� �л��� �����ϴ� ���� ���� ���
	printSub(rst.Sub);
	cout << "===============================================================\n";

	cout.width(45);
	cout << "������� : ";
	//�ش� �л��� ���� ��� ���� ���
	cout << rst.AveGPA << "\n\n";
}

void printSub(const Subject *sub) {
	for (int i = 0; i < 3; i++) {
		cout.width(15);
		cout << sub[i].SubName;
		cout.width(15);
		cout << sub[i].Hakjum;
		cout.width(15);
		cout << sub[i].Grade;
		cout.width(15);
		cout << sub[i].GPA << '\n';
	}
}

void Search(Student *pst, int StudentNum) {
	Student *searchStd = NULL;
	//�л� �̸� �Է� �� ���α׷��� ����� �л� �̸��� ���ϴ� �Լ� ȣ��
	searchStd = StdSearch(pst, StudentNum);

	//ã�� �ִ� �л��� ������ ���� ���, �ش� �л��� ���� ���
	if (searchStd) {
		PrintOneData(*searchStd);
	}
	//ã�� �ִ� �л��� ������ ���� ���, �Ʒ��� �޼��� ���
	else {
		cout << "<�ش� �̸��� ���� �л��� ������ ��ϵǾ����� �ʽ��ϴ�.>\n\n";
	}
}

Student* StdSearch(Student *pst, int StudentNum) {
	char searchName[20];
	cout << "�˻��� �л� �̸� : ";
	cin >> searchName;

	for (int i = 0; i < StudentNum; i++) {
		//�ش� �л��� �̸��� ã���� �ϴ� �л� �̸� ��
		if (strcmp(searchName, pst[i].StdName) == 0) {
			//������ �˻� �׸��ϰ� �ش� �л��� ������ ����� ����ü �ּ� ����
			return &pst[i];
		}
		//��� ��ġ�ϴ� �л� ã��
		else;
	}
	//�˻��� �̸��� ���α׷��� ���� �л��̶�� NULL �� ����
	return NULL;
}