#pragma once
#include "Subject.h"
#include <string>
using namespace std;

class Student {
	protected:
		string m_name;	// 학생명
		int m_hakbun;	// 학번
		int m_subnum;	// 수강한 과목 수 
		Subject *m_sub;	// 수강한 과목들
		float m_aveGPA;	// 수강한 과목들의 평균 평점
	public:
		Student();	// 디폴트 생성자
		Student(string, int, int, Subject*);	// 인자있는 생성자 (깊은 복사)
		Student(const Student &std);			// 복사생성자 (깊은 복사)
		~Student();	// 소멸자
		void InputData();	// 멤버변수 값 입력
		void PrintData() const;	// 멤버변수 값 출력
		void CalcAveGPA();	// 평균 평점 계산
		void Modify();		// 학생 정보 변경
		void stdInfoModify();	// 학생의 인적 정보 변경
		Subject* SubSearch(string subName) const;	// 찾고자 하는 과목을 탐색

		// 접근자 함수
		// Set함수
		void SetName(string stdName) {
			m_name = stdName;
		}
		void SetHakbun(int stdHakbun) {
			m_hakbun = stdHakbun;
		}
		void SetSubNum(int stdSubNum) {
			m_subnum = stdSubNum;
		}
		void SetSub(Subject* sub) {
			m_sub = sub;
		}
		void SetAveGPA(float stdAveGPA) {
			m_aveGPA = stdAveGPA;
		}
		// Get함수
		// Get함수가 const가 아니라면, const객체가 get함수를 호출할 때 error 발생
		string GetName()const {
			return m_name;
		}
		int GetHakbun() const {
			return m_hakbun;
		}
		int GetSubNum() const {
			return m_subnum;
		}
		float GetAveGPA() const {
			return m_aveGPA;
		}
};