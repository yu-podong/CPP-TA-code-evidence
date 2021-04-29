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

// WORD ����ü �����͸� �����ϴ� ���� ��ü
vector <WORD*> words;

int main() {
	string buffer;
	cout << "���ڿ� �Է�(����: Ctrl + Z)\n";

	while (cin >> buffer) {
		if (buffer == "^Z") {
			words.push_back(new WORD);
			words.back()->str = buffer;
			break;
		}
		CountWords(buffer);
	}

	//�ܾ� ���
	PrintWords();
	RemoveAll();

	return 0;
}

void CountWords(string buffer) {
	//���� ���Ϳ� ����ִ� element�� ���� ���ϱ�
	int size = words.size();

	// vector �ȿ� buffer�� �ִ��� �˻� ��
	for (int i = 0; i < size; i++) {
		// �߰ߵǸ� �ش� �ܾ��� �󵵼� 1 ����
		if (words[i]->str == buffer) {
			words[i]->count++;

			return;
		}
	}
	// �ܾ �߰ߵ��� ������ vector�� �ܾ� �߰� �� �󵵼� 1�� ����
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