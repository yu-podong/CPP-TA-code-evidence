#include <iostream>
#include <string>
#include <vector>
using namespace std;

void CountWords(string buffer);
void PrintWords();
void RemoveAll();

struct WORD {
	string str;
	int count;
};

// WORD 구조체 포인터를 저장하는 벡터 객체
vector <WORD*> words;

int main() {
	string buffer;
	cout << "문자열 입력(종료: Ctrl + Z)\n";

	while (cin >> buffer) {
		if (buffer == "^Z") {
			words.push_back(new WORD);
			words.back()->str = buffer;
			break;
		}
		CountWords(buffer);
	}

	//단어 출력
	PrintWords();
	RemoveAll();

	return 0;
}

void CountWords(string buffer) {
	//현재 벡터에 들어있는 element의 개수 구하기
	int size = words.size();

	// vector 안에 buffer가 있는지 검색 후
	for (int i = 0; i < size; i++) {
		// 발견되면 해당 단어의 빈도수 1 증가
		if (words[i]->str == buffer) {
			words[i]->count++;

			return;
		}
	}
	// 단어가 발견되지 않으면 vector에 단어 추가 후 빈도수 1로 설정
	words.push_back(new WORD);
	words.back()->str = buffer;
	words.back()->count = 1;
}

void PrintWords() {
	int size = words.size();

	cout << "=================================\n";
	for (int i = 0; i < size; i++) {
		cout << words[i]->str <<" : "<< words[i]->count <<'\n';
	}
	cout << "=================================\n";
}

void RemoveAll() {
	int size = words.size();

	for (int i = 0; i < size; i++) {
		delete words[i];
	}
}