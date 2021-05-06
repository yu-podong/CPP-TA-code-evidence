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
		void Initialize();	// 멤버변수 초기화
		void Initialize(string, int, string);	// 인자값으로 멤버변수 초기화
		void InputValue(int &);
		void InputValue(string &);
		void InputData();	// 멤버변수 값 입력
		void PrintTitle();	// 멤버변수에 대하 title Text 출력
		void PrintData();	// 멤버변수 값 출력
		void CalcGPA();		// 평점 계산

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