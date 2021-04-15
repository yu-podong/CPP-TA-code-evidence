#include <iostream>	
#include <iomanip>	
#include <cstring>	
#include <string>
using namespace std;

struct Subject {
	string SubName;
	int Hakjum;
	string Grade;
	float GPA;
};
struct Student {
	string StdName;
	int Hakbun;
	Subject *Sub;
	int SubNum;
	float AveGPA;
};

inline void PrintMenu();
void InputData(Student *std, int StudentNum);
void inputSub(Subject *sub, int subNum);
inline void InputValue(string &str);
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
Subject* SubSearch(const Student *pst);

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
			InputValue(stdNum);

			//�л� �� ��ŭ ���� �޸� �Ҵ�
			student = new Student[stdNum];

			InputData(student, stdNum);
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
		InputValue(std[i].SubNum);

		std[i].Sub = new Subject[std[i].SubNum];

		//�ش� �л��� ������ ���� ���� �Է�
		inputSub(std[i].Sub, std[i].SubNum);
		//�ش� �л��� ���� ��� ���� ���
		std[i].AveGPA = calcAveGPA(std[i].Sub, std[i].SubNum);
	}
}
void inputSub(Subject *sub, int subNum) {
	float sumGPA = 0.0;

	cout << "* ������ ����" << subNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";
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
void InputValue(string &str) {
	getline(cin, str);
}
void InputValue(int &i) {
	cin >> i;
	cin.ignore();
}
float calcGPA(Subject &sub) {
	float result;
	//�ش� ������ grade�� ���Ͽ� �ش��ϴ� ������ ����
	if (sub.Grade == "A+")
		result = 4.5;
	else if (sub.Grade == "A0")
		result = 4.0;
	else if (sub.Grade == "B+")
		result = 3.5;
	else if (sub.Grade == "B0")
		result = 3.0;
	else if (sub.Grade == "C+")
		result = 2.5;
	else if (sub.Grade == "C0")
		result = 2.0;
	else if (sub.Grade == "D+")
		result = 1.5;
	else if (sub.Grade == "D0")
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
	string searchName;
	cout << "�˻��� �л� �̸� : ";
	InputValue(searchName);

	for (int i = 0; i < StudentNum; i++) {
		//�ش� �л��� �̸��� ã���� �ϴ� �л� �̸� ��
		if (searchName == pst[i].StdName) {
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
	string modifyInfo;
	Subject *findSub = NULL;

	//�����ϰ��� ���� �Է�
	cout << "\n������ ������ �����ϼ��� <�л����� / ��������> : ";
	InputValue(modifyInfo);
	cout << '\n';

	//�л� ������ �Է��� ���
	if (modifyInfo == "�л� ����" || modifyInfo == "�л�����") {
		//������ ����ü�̱⿡ -> �̿�
		cout << "< " << pst->StdName << ", " << pst->Hakbun << ">�� ������ �����ϼ���.\n";

		//�˻��� �л��� �̸��� �й� ����
		cout << "�̸� : ";
		InputValue(pst->StdName);
		cout << "�й� : ";
		InputValue(pst->Hakbun);
		cout << "\n";
	}
	//���� ������ �Է��� ���
	else if (modifyInfo == "���� ����" || modifyInfo == "��������") {
		//�����ϰ��� ���� ã��
		findSub = SubSearch(pst);

		//�ش� �л��� ������ ���� �߿� ã�� ������ �����Ѵٸ�
		if (findSub != NULL) {
			//���� ���� ����
			cout << "<" << findSub->SubName << ", " << findSub->Hakjum << ", " << findSub->Grade << ">�� ������ �����ϼ���.\n";
			cout << "������� : ";
			InputValue(findSub->SubName);
			cout << "�������� : ";
			InputValue(findSub->Hakjum);
			cout << "������(A+ ~ F) : ";
			InputValue(findSub->Grade);
			cout << "\n";

			//������ ������ �������� GPA, AveGPA ����
			findSub->GPA = calcGPA(*findSub);
			pst->AveGPA = calcAveGPA(pst->Sub, pst->SubNum);
		}
		//�ش� �л��� ���� ���� �߿� ã�� ������ ������
		else {
			cout << "<�ش� �л��� ã���� �ϴ� ������ �������� �ʽ��ϴ�.>\n\n";
		}
	}
	//�߸� �Է��� ���
	else {
		cout << "<�����ϰ��� �ϴ� ������ ��Ȯ�� �Է����ּ���.>\n\n";
	}	
}

Subject* SubSearch(const Student *pst) {
	string searchSub;

	//�����ϰ��� ���� �̸� �Է�
	cout << "�˻��� ���� �̸� : ";
	InputValue(searchSub);

	//�ش� �л��� ������ ������� ��
	for (int i = 0; i < pst->SubNum; i++) {
		//�˻��� ����� ���� �̸� ����
		if (searchSub == pst->Sub[i].SubName) {
			return &(pst->Sub[i]);
		}	
		else;
	}
	return NULL;
}