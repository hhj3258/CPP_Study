#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터 2
class Knight;

// typedef의 진실
// typedef 왼쪽값 오른쪽값 -> 오른쪽(커스텀 타입 정의)
typedef int NUMBER;

// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법]을 만들고, typedef를 앞에다 붙이기만 하면 된다.
typedef int INTEGER;
typedef int* POINTER;
typedef int ARRAY[20];

typedef int (*PFUNC)(int, int);		// 함수 포인터
typedef int (Knight::* PMEM_FUNC)(int, int);		// 멤버 함수 포인터

int Test(int a, int b)
{
	static int count = 1;
	cout << "Test" << count++ << endl;
	return a + b;
}

class Knight
{
public:
	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};

int main()
{
	// 함수 포인터
	// 1) 포인터				*
	// 2) 변수의 이름	fn
	// 3) 타입				함수(인자로 int 2개를 받고, int 1개를 반환)
	int (*fn)(int, int);

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn2;

	fn = &Test;		// & 생략 가능(C언어 호환성 때문)

	fn(1, 2);
	(*fn)(1, 2);

	// ----------------------------------------------------------------------------
	PFUNC fn2;
	fn2 = &Test;
	fn2(3, 4);

	// 위의 문법으로 만든 함수 포인터는
	// [전역 함수 / 정적 함수]만 담을 수 있다.(호출 규약이 동일한 애들)

	Knight k1;

	// 멤버 함수 포인터
	PMEM_FUNC mfn;

	// 스택에 있는 객체의 경우
	mfn = &Knight::GetHp;
	(k1.*mfn)(1, 1);

	// 힙에 있는 객체의 경우
	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);

	delete k2;

	return 0;
}