#include <iostream>
#include <vector>
#include <List>
using namespace std;

// 오늘의 주제 : using


// typedef 복습
typedef vector<int>::iterator vecIt;
// int 를 다른 타입으로 바꾸기만 하면 id 타입을 모두 변경할 수 있다.
typedef int id; 
id xxx = 5;

void Test(int a)
{
    cout << a << endl;
}

// using
// - typedef 가 하는 일은 using으로 모두 대체 가능
// - 그리고 더 이쁘게 만들 수 있다.

// int 타입에 id2 라는 별칭을 만든다.
using id2 = int;

// 장점 1) 직관성
typedef void(*MyFunc1)();
// using [타입 이름] = [반환값](*)(매개변수);
using MyFunc2 = void(*)(int);
MyFunc2 pTest = &Test;

// 장점 2) 템플릿
// typedef는 템플릿에 쓰기엔 부적절하고 불편하다.
template<typename T>
using myType = list<T>;

myType<int> li;

int main()
{

    return 0;
}
