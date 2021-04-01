#include <iostream>
#include <cstring>
using namespace std;

int GetMin(int, int);
double GetMin(double, double);
char* GetMin(char*, char*);
int GetMin(int[]);

int main() {
	int num1, num2, arr[10] = { 0 };
	double num3, num4;
	char str1[100], str2[100];

	//정수
	cout << "두 개의 정수를 입력하세요 : ";
	cin >> num1 >> num2;

	cout << "최소값은 " << GetMin(num1, num2) << "입니다\n";

	//실수
	cout << "두 개의 실수를 입력하세요 : ";
	cin >> num3 >> num4;

	cout << "최소값은 " << GetMin(num3, num4) << "입니다\n";

	//문자열
	cout << "두 개의 문자열을 입력하세요 : ";
	cin >> str1 >> str2;
	cin.ignore();

	cout << "최소값은 " << GetMin(str1, str2) << "입니다\n";

	//배열
	cout << "배열의 원소 : ";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	cout << "최소값은 " << GetMin(arr) << "입니다\n";

	return 0;
}

int GetMin(int num1, int num2) {
	if (num1 < num2)
		return num1;
	else
		return num2;
}

double GetMin(double num1, double num2) {
	if (num1 < num2)
		return num1;
	else
		return num2;
}

char* GetMin(char* str1, char* str2) {
	if (strcmp(str1, str2) < 0)
		return str1;
	else
		return str2;
}

int GetMin(int arr[]) {
	int minNum = INT_MAX;
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		if (arr[i] < minNum)
			minNum = arr[i];
	}
	return minNum;
}