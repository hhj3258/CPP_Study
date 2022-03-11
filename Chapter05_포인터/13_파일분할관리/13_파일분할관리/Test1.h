// 헤더 파일을 여러번 include 해도
// 유일하게 하나만 복붙하게 만들어준다.
// 없을 경우 struct 등이 헤더에 있으면 문제가 생김.
#pragma once

// 귀찮다고 아래처럼 전부 헤더파일에 넣진 말자.
// 헤더파일은 필요한 것만 간단간단하게.
// #include <iostream>
// using namespace std;

void Test_1();

void Test_2();

// 구현부도 만들어줄 수 있음.
// 하지만 굳이 하진 말자.
// 링크 에러
//void Test_3()
//{
//
//}