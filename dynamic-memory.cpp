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
	Subject *Sub;
	int SubNum;
	float AveGPA;
};

inline void PrintMenu();
void InputData(Student *std, int StudentNum);
void inputSub(Subject *sub, int subNum);
inline void InputValue(char *str);
inline void InputValue(int &i);
float calcGPA(Subject &sub);
float calcAveGPA(Subject* sub, int subNum);
void PrintAllStdList(Student *pSt, int StudentNum);
void PrintAllData(const Student *pst, int StudentNum);
void printSub(const Subject *sub, int subNum);
void PrintOneData(const Student &rst);
void Search(Student *pst, int StudentNum);
Student* StdSearch(Student *pst, int StudentNum);
void ModifyStdInfo(Student *pst);

int menuNum;

int main() {
	Student *student = NULL, *findStd = NULL;
	int stdNum = 0;

	cout.precision(2);
	cout << fixed;

	while (1) {
		PrintMenu();

		//�л� ���� �Է�
		if (menuNum == 1) {
			//�л� ���� �Է¹���
			cout << "���α׷��� ������ �л� ���� �Է��ϼ��� : ";
			cin >> stdNum;

			//�л� �� ��ŭ ���� �޸� �Ҵ�
			student = new Student[stdNum];

			InputData(student,stdNum);
		}
		//��ü�л� ���� ���
		else if (menuNum == 2) {
			PrintAllData(student, stdNum);
		}
		//���ϴ� �л��� ���� ���
		else if (menuNum == 3) {
			Search(student, stdNum);
		}
		//��ü �л� ���� ���
		else if (menuNum == 4) {
			PrintAllStdList(student, stdNum);
		}
		//Ư�� �л��� ���� ����
		else if (menuNum == 5) {
			findStd = StdSearch(student, stdNum);
			if (findStd != NULL) {
				ModifyStdInfo(findStd);
			}
			else {
				cout << "<���α׷� ���� �ش� �л��� �̸��� �����ϴ�.>\n";
			}

		}
		//���α׷� ����
		else if (menuNum == 6) {
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
		//��µ� �޴��� ���� ��ȣ�� �������� ���
		else {
			cout << "<���� �޴� ��ȣ�� �����ϼ̽��ϴ�.>\n";
		}
	}
	//�Ҵ��ߴ� ���� �޸� ����
	delete[] student;

	return 0;
}
void PrintMenu() {
	cout << "==========�޴�==========\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n" << "\n";

	cout << "���ϴ� ����� �Է��ϼ��� : ";
	InputValue(menuNum);
	cout << "\n";
}
void InputData(Student *std, int StudentNum) {
	for (int i = 0; i < StudentNum; i++) {
		cout << "\n* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(std[i].StdName);
		cout << "�й� : ";
		InputValue(std[i].Hakbun);
		cout << "\n\n";

		//
		cout << "�ش� �л��� ������ ���� ���� �Է��ϼ��� : ";
		cin >> std[i].SubNum;

		std[i].Sub = new Subject[std[i].SubNum];

		//�ش� �л��� ������ ���� ���� �Է�
		inputSub(std[i].Sub, std[i].SubNum);
		//�ش� �л��� ���� ��� ���� ���
		std[i].AveGPA = calcAveGPA(std[i].Sub, std[i].SubNum);
	}
}
void inputSub(Subject *sub, int subNum) {
	float sumGPA = 0.0;

	cout << "* ������ ����" << subNum <<"���� �� �������, ��������, �������� �Է��ϼ���.\n";
	for (int j = 0; j < subNum; j++) {
		cout << "������� : ";
		InputValue(sub[j].SubName);
		cout << "�������� : ";
		InputValue(sub[j].Hakjum);
		cout << "������(A+ ~ F) : ";
		InputValue(sub[j].Grade);
		cout << "\n";

		sub[j].GPA = calcGPA(sub[j]);
	}
	cout << "\n\n";
}
void InputValue(char *str) {
	cin >> str;
}
void InputValue(int &i) {
	cin >> i;
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

float calcAveGPA(Subject *sub, int subNum) {
	int sumHakjum = 0;
	float sumGPA = 0.0;
	for (int i = 0; i < subNum; i++) {
		//��� ������ ���� ����
		sumHakjum += sub[i].Hakjum;
		//��� ������ ���� ����
		sumGPA += sub[i].GPA;
	}
	//���� ���� ��� ���� ����
	return sumGPA / (float)sumHakjum;
}

void PrintAllStdList(Student *pSt, int StudentNum) {
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << "�̸�\n";
	cout << "===============================================================\n";

	//���α׷��� ����� �л����� �й��� �̸��� ���
	for (int i = 0; i < StudentNum; i++) {
		cout.width(15);
		cout << pSt[i].Hakbun;
		cout.width(15);
		cout << pSt[i].StdName << '\n';
	}
	cout << "===============================================================\n\n";
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
	printSub(rst.Sub, rst.SubNum);
	cout << "===============================================================\n";

	cout.width(45);
	cout << "������� : ";
	//�ش� �л��� ���� ��� ���� ���
	cout << rst.AveGPA << "\n\n";
}

void printSub(const Subject *sub, int subNum) {
	//�ش� �л��� �����ϴ� ������ ���� ���
	for (int i = 0; i < subNum; i++) {
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
	InputValue(searchName);

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

void ModifyStdInfo(Student *pst) {
	//������ ����ü�̱⿡ -> �̿�
	cout << "< " << pst->StdName << pst->Hakbun << ">�� ������ �����ϼ���.\n";

	//�˻��� �л��� �̸��� �й� ����
	cout << "�̸� : ";
	InputValue(pst->StdName);
	cout << "�й� : ";
	InputValue(pst->Hakbun);
}