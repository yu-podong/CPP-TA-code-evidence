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

void print_menu();
void inputStd();
float inputSub(Subject *sub);
float calcGPA(char grade[], float hakjum);
void printStd();
void printSub(Subject sub[]);

int menuNum;
Student student[2];

int main() {
	cout.precision(2);
	cout << fixed;

	while (1) {
		print_menu();

		if ( menuNum == 1) {
			inputStd();
		}
		else if ( menuNum == 2) {
			printStd();
		}
		else {
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	}
	return 0;
}
void print_menu() {
	cout << "==========�޴�==========\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. ���α׷� ����\n" << "\n";

	cout << "���ϴ� ����� �Է��ϼ��� : ";
	cin >>  menuNum;
	cout << "\n";
}
void inputStd() {
	for (int i = 0; i < 2; i++) {
		cout << "* " << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		cin >> student[i].StdName;
		cout << "�й� : ";
		cin >> student[i].Hakbun;
		cout << "\n\n";

		student[i].AveGPA = inputSub(student[i].Sub);
		student[i].AveGPA /= (float)3.0;
	}
}
float inputSub(Subject *sub) {
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

		sub[j].GPA = calcGPA(sub[j].Grade, (float)sub[j].Hakjum);
		sumGPA += sub[j].GPA;
	}
	cout << "\n\n";
	return sumGPA;
}
float calcGPA(char grade[],float hakjum) {
	float result;
	if (strcmp(grade, "A+") == 0)
		result = 4.5;
	else if (strcmp(grade, "A0") == 0)
		result = 4.0;
	else if (strcmp(grade, "B+") == 0)
		result = 3.5;
	else if (strcmp(grade, "B0") == 0)
		result = 3.0;
	else if (strcmp(grade, "C+") == 0)
		result = 2.5;
	else if (strcmp(grade, "C0") == 0)
		result = 2.0;
	else if (strcmp(grade, "D+") == 0)
		result = 1.5;
	else if (strcmp(grade, "D0") == 0)
		result = 1.0;
	else
		result = 0.0;
	return result * hakjum;
}
void printStd() {
	cout << "               ��ü �л� ���� ����"<< '\n';
	cout << "===============================================================\n";

	for (int i = 0; i < 2; i++) {
		cout << "�̸� : " << student[i].StdName << "  �й� : " << student[i].Hakbun << "\n";
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

		printSub(student[i].Sub);
		cout << "===============================================================\n";

		cout.width(45);
		cout << "������� : ";
		
		cout << student[i].AveGPA << "\n\n";
	}
}

void printSub(Subject sub[]) {
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
