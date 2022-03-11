#include "Test1.h"
#include "Test2.h"

#include <iostream>
using namespace std;

// 오늘의 주제 : 파일 분할 관리

//void Test_3()
//{
//
//}

int main()
{
    // 같은 부모(Test1.h)를 가지고 있는 
    // Test1.cpp의 Test_2를 찾아서 실행한다.
    Test_2();

    return 0;
}
