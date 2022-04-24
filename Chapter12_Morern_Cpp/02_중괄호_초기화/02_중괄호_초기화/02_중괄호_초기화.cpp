#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : 중괄호 초기화 { }

class Knight
{
public:
	Knight() { }

	Knight(int a, int b)
	{
		cout << "Knight(int, int)" << endl;
	}

	Knight(initializer_list<int> a)
	{
		cout << "Knight(initializer_list<int> a)" << endl;
	}
};

int main()
{
	// 중괄호 초기화 { }
	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1;		// 복사 생성자 호출 (대입 연산자 X)
	Knight k3;				// 기본 생성자
	k3 = k1;					// 대입 연산자

	Knight k4{ k2 };

	// 중괄호 초기화 장점
	// 1) vector 등 container와 잘 어울린다.
	vector<int> v3{ 1,2,3,4,5 };
	vector<int> v4 = { 1,2,3,4,5 };

	// 2) 축소 변환 방지
	int x = 0;
	long long y{ x };
	//double z{ x };		// Error! 축소 변환임!
	double d(x);		// OK! 암시적 캐스팅해주고 있음

	// 3) Bonus
	Knight k7();	// warning! 함수 시그니쳐와 동일하여 경고!
	Knight k5{ };	// OK! 함수 시그니쳐와 다르다. 확실히 구분 가능.

	// 생성자중 Knight(initializer_list<int> a) 로 인해
	// Knight(int a, int b) 등의 생성자들이 가려진다!
	Knight k6{ 1,2 };


	// <정리>
	// 괄호 초기화 문파
	// - 괄호 초기화 () 를 기본으로 간다
	// - 전통적인 C++ (거부감이 없음)
	// - vector 등 특이한 케이스에 대해서만 { } 사용

	// 중괄호 초기화 문파
	// - 중괄호 초기화 { }를 기본으로 간다
	// - 초기화 문법의 일치화
	// - 축소 변환 방지

	return 0;
}