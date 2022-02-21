#include <iostream>
using namespace std;

// 오늘의 주제 : 문자와 문자열
// char : 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다
// wchar_t : 유니코드 문자를 나타낸다

// ASCII
char ch = 97;
char ch1 = '1';
char ch2 = 'a' + 1;

// 국제화 시대에는 영어만으로(아스키만으로) 서비스 할 수 없음
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드(unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어~ (뚥쿩웱)

// 유니코드는 표기 방식이 여러가지가 있는데 대표적으로 UTF8 UTF16
// UTF8
// - 알파벳, 숫자 1byte (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2byte
// - 한글, 한자 등 3byte
// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = L'안';
wchar_t wch2 = 0xc548;

// Escape Sequence
// 표기하기 애매한 애들을 표현
// \0 = ascii 0 = NULL
// \t = ascii 9 = Tab
// \n = ascii 10 = LineFeed (한줄 아래로)
// \r = ascii 13 = CarriageReturn (커서 <<)
// \'

// 문자열
// 문자들이 열을 지어서 모여 있는 것 (문자 배열?)
// 정수 (1~8byte) 고정 길이로
// ex) Hello World -> 길이가 가변임
// 끝은 NULL -> (0) -> \00

char str[] = { 'h','e','l','l','o', '\0' };
char str2[] = "Hello World";
wchar_t str3[] = L"Hello World";

int main()
{
    cout << ch2 << endl;

    //cout은 char 전용

    wcout.imbue(locale("kor"));
    wcout << wch << endl;
    wcout << wch2 << endl;

    cout << str << endl;

}

