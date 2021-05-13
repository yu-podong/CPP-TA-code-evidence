#pragma once
#include <string>
using namespace std;

class Subject {
protected:
	string m_name;	// 과목명
	int m_hakjum;	// 학점
	string m_grade;	// 등급
	float m_GPA;	// 평점
public:
	Subject();	// 디폴트 생성자
	Subject(string, int, string);	// 인자있는 생성자
	Subject(const Subject &sub);	// 복사생성자
	~Subject();						// 소멸자
	void InputValue(int &);
	void InputValue(string &);
	void InputData();	// 멤버변수 값 입력
	void PrintTitle();	// 멤버변수에 대하 title Text 출력
	void PrintData();	// 멤버변수 값 출력
	void CalcGPA();		// 평점 계산
	void Modify();		// 과목 정보 변경

	// 접근자 함수
	// Set함수
	void SetName(string subName) {
		m_name = subName;
	}
	void SetHakjum(int subHakjum) {
		m_hakjum = subHakjum;
	}
	void SetGrade(string subGrade) {
		m_grade = subGrade;
	}
	void SetGPA(float subGPA) {
		m_GPA = subGPA;
	}

	// Get함수
	string GetName() {
		return m_name;
	}
	int GetHakjum() {
		return m_hakjum;
	}
	string GetGrade() {
		return m_grade;
	}
	float GetGPA() {
		return m_GPA;
	}
};