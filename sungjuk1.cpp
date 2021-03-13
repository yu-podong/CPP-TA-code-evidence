#include <iostream>	
#include <iomanip>	
#include <cstring>	
using namespace std;	

typedef struct Subject Subject;	
typedef struct Student Student;	

void print_menu();	
void input_std(int i, Student student[]);
void input_sub(int i, Student student[]);	
float score(int i, int j, Student student[]);	
void print_StdGrade(int i, Student student[]);

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
int main() {		
	int menu_num = 0;	
	Student student[2]; 

	while (1) { 
		print_menu(); 

		cout << "원하는 기능을 입력하세요 : "; 
		cin >> menu_num; 
		cout << "\n"; 

		if (menu_num == 1) { 
			for (int i = 0; i < 2; i++) { 
				input_std(i, student); 
				input_sub(i, student); 
			}
		}
		else if (menu_num == 2) { 
			cout << setw(43) << "전체 학생 성적 보기\n"; 
			cout << "===============================================================\n"; 
			for (int i = 0; i < 2; i++) { 
				print_StdGrade(i, student); 
				cout << "\n\n"; 
			}
		}
		else { 
			cout << "프로그램을 종료합니다.\n"; 
			break; 
		}
	}
	return 0; 
}
void print_menu() { 
	cout << "==========메뉴==========\n"; 
	cout << "1. 학생 성적 입력\n"; 
	cout << "2. 전체 학생 성적 보기\n"; 
	cout << "3. 프로그램 종료\n" << "\n"; 
}
void input_std(int i, Student student[]) { 
	cout << "* "<< i+1 << " 번째 학생 이름과 학번을 입력하세요.\n"; 
	cout << "이름 :"; 
	cin >> student[i].StdName; 
	cout << "학번 :"; 
	cin >> student[i].Hakbun; 
	cout << "\n\n"; 
}
void input_sub(int i, Student student[]) { 
	cout << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n"; 
	for (int j = 0; j < 3; j++) { 
		cout << "교과목명 : "; 
		cin >> student[i].Sub[j].SubName; 
		cout << "과목학점 : "; 
		cin >> student[i].Sub[j].Hakjum; 
		cout << "과목등급(A+ ~ F) : "; 
		cin >> student[i].Sub[j].Grade; 
		cout << "\n"; 

		student[i].Sub[j].GPA = score(i, j, student)*(float)student[i].Sub[j].Hakjum; 
	}
	cout << "\n\n"; 
}
float score(int i, int j, Student student[]) { 
	if (strcmp(student[i].Sub[j].Grade, "A+") == 0) 
		return 4.5; 
	else if (strcmp(student[i].Sub[j].Grade, "A0") == 0) 
		return 4.0; 
	else if (strcmp(student[i].Sub[j].Grade, "B+") == 0) 
		return 3.5; 
	else if (strcmp(student[i].Sub[j].Grade, "B0") == 0) 
		return 3.0; 
	else if (strcmp(student[i].Sub[j].Grade, "C+") == 0) 
		return 2.5; 
	else if (strcmp(student[i].Sub[j].Grade, "C0") == 0) 
		return 2.0; 
	else if (strcmp(student[i].Sub[j].Grade, "D+") == 0) 
		return 1.5; 
	else if (strcmp(student[i].Sub[j].Grade, "D0") == 0) 
		return 1.0; 
	else 
		return 0.0; 
}
void print_StdGrade(int i, Student student[]) { 
	float avegpa = 0.0; 
	
	cout << "이름 : " << student[i].StdName << "  학번 : " << student[i].Hakbun << "\n"; 
	cout << "===============================================================\n"; 
	cout << setw(13) << "과목명" << setw(15) << "과목학점" << setw(15) << "과목등급" << setw(15) << "과목평점\n"; 
	for (int j = 0; j < 3; j++) { 
		cout << fixed << setprecision(2); 
		cout << setw(13) << student[i].Sub[j].SubName << setw(12) << student[i].Sub[j].Hakjum << setw(15) << student[i].Sub[j].Grade << setw(15) << student[i].Sub[j].GPA << "\n"; 
		avegpa += student[i].Sub[j].GPA; 
	}
	cout << "===============================================================\n"; 
	student[i].AveGPA = avegpa / (float)3.0; 
	cout << setw(43) << "평균평점" << setw(12) << student[i].AveGPA; 
}