#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

// 문제 1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
    // str이라는 문자열의 길이를 반환
    int cnt = 0;
    int idx = 0;

    while (str[idx] != '\0')
    {
        idx++;
        cnt++;
    }

    return cnt;
}

// 문제 2) 문자열 복사 함수
void StrCpy(char* dest, char* src)
{
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// 문제 3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{
    char* ret = dest;

    while (*dest != '\0')
        dest++;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return ret;
}

// 문제 4) 두 문자열을 비교하는 함수
int StrCmp(char* str1, char* str2)
{
    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1 == *str2)
        {
            str1++;
            str2++;
        }
        else if (*str1 > *str2)
            return 1;
        else
            return -1;
    }

    return 0;
}

// 문제 5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
    int len = StrLen(str);

    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    const int BUF_SIZE = 100;

    char a[BUF_SIZE] = "Hellz";
    char b[BUF_SIZE] = "Hello";

    //int size = sizeof(a);   //100
    //int len = strlen(a);    //5

    //cout << size << endl << len << endl;
    //cout << "StrLen(): " << StrLen(a) << endl;

    //StrCpy(b, a);
    //cout << b << endl;

    //strcat_s(b, a);
    //cout << b << endl;

    //cout << StrCat(a, b)<<endl;

    /*
    a<b --> -1
    a==b --> 0
    a>b --> +1
    */
    //cout << StrCmp(a, b);

    ReverseStr(a);
    cout << a << endl;

    return 0;
}