#include <iostream>
using namespace std;

// 다중 포인터

// const char* ch1 의 값을 가져온다
// ex) void SetNumber1(int a) 와 같은 문법이라고 볼 수 있음
void SetString1(const char* a)
{
    a = "After: SetString1";
}

// const char* ch1 의 주소를 가져온다
// 다중 포인터
// ex) void SetNumber1(int* a) 와 같은 문법이라고 볼 수 있음
void SetString2(const char** a)
{
    *a = "After: SetString2";
}

// const char* ch1 의 주소를 가져온다
// 포인터의 레퍼런스(참조)
// ex) void SetNumber1(int& a) 와 같은 문법이라고 볼 수 있음
void SetString3(const char*& a)
{
    a = "After: SetString3";
}

int main()
{
    char ch_arr[] = "hello";
    char ch_arr2[] = { 'h','e','l','l','o','\0' };

    // ch1[ Before의 주소 ] << 8바이트(64비트에서)
    // .rdata Before의 주소[B][e][f][o][r][e][\0]
    const char* ch1 = "Before";
    SetString1(ch1);
    cout << ch1 << endl;

    ch1 = "Before";
    SetString2(&ch1);
    cout << ch1 << endl;
    
    ch1 = "Before";
    SetString3(ch1);
    cout << ch1 << endl;

    // pp[ &ch1 ] << 8바이트
    // ch1[ Before의 주소 ] << 8바이트(64비트에서)
    // .rdata Before의 주소[B][e][f][o][r][e][\0]
    const char** pp = &ch1;
    *pp = "After: pp";
    cout << ch1 << endl;

    const char*& pr = ch1;
    pr = "After: pr";
    cout << ch1 << endl;


    return 0;
}