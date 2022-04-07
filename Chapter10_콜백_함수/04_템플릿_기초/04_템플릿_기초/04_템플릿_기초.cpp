#include<iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초

class Knight
{
public:
	// ...

public:
	int _hp = 100;
};

// 연산자 오버로딩(전역함수 버전)
//ostream& operator<< (ostream& os, const Knight& k)
//{
//	os << k._hp;
//	return os;
//}

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
// Knight 클래스에 대한 Print만 특별히 만들어준다.
template<>
void Print(Knight k)
{
	cout << "Knight!!!!!!!!!!!!" << " ";
	cout << k._hp << endl;
}


template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	// 컴파일러가 여러가지 함수를 
	Print(50);
	Print<int>(50);	// 명시적으로 타입 지정 가능
	Print(49.9f);
	Print("Hello World");

	Print("Hello", 100);

	cout << Add(1, 2) << endl;
	cout << Add(1.11f, 2.22f) << endl;

	Knight k1;
	Print(k1);

	return 0;
}