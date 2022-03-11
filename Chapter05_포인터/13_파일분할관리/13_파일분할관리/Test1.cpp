// 필수는 아니지만 보통 Test1.h 와 세트로 만들어준다.

// 전처리구문 : 컴파일 직전에 실행되는 별도의 프로그램
// Test1.h 에 있는 것들을 복붙해줘 라는 뜻
#include "Test1.h"
#include<iostream>
using namespace std;

void Test_1()
{
	Test_2();
}

void Test_2()
{
	cout << "Hello World" << endl;
}