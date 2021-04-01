#include <iostream>
#include <cstring>
using namespace std;

template <class T>
void Sort(T arr[]) {
	T temp;
	int indexNum;

	for (int i = 0; i < 5; i++) {
		indexNum = i;

		for (int j = i + 1; j < 5; j++) {
			if (arr[j] < arr[indexNum])
				indexNum = j;
		}

		temp = arr[i];
		arr[i] = arr[indexNum];
		arr[indexNum] = temp;
	}
}


int main() {
	int menuNum, arr1[5];
	double arr2[5];

	while (1) {
		//3가지 메뉴 출력
		cout << "1. 정수 정렬\n";
		cout << "2. 실수 정렬\n";
		cout << "3. 종료\n";
		
		cout << "메뉴 선택 : ";
		cin >> menuNum;
		cout << "\n";

		//각 메뉴를 선택하였을 때 수행될 code 작성
		if (menuNum == 1) {
			cout << "5개의 정수를 입력하세요 : ";
			for (int i = 0; i < sizeof(arr1) / sizeof(int); i++) {
				cin >> arr1[i];
			}
			Sort(arr1);

			cout << "정렬 결과 : ";
			for (int i = 0; i < sizeof(arr1) / sizeof(int); i++) {
				cout << arr1[i] << " ";
			}
			
		}
		else if (menuNum == 2) {
			cout << "5개의 정수를 입력하세요 : ";
			for (int i = 0; i < sizeof(arr1) / sizeof(double); i++) {
				cin >> arr2[i];
			}
			Sort(arr2);

			cout << "정렬 결과 : ";
			for (int i = 0; i < sizeof(arr2) / sizeof(double); i++) {
				cout << arr2[i] << " ";
			}
		}
		else if (menuNum == 3) {
			cout << "프로그램을 종료합니다.";
			break;
		}
		//1~3번 이외의 메뉴 선택 시,
		else {
			cout << ">> 메뉴 번호를 잘못입력하셨습니다. <<";
		}

		cout << "\n\n";
	}
	
	return 0;
}
