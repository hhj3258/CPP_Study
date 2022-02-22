#include <iostream>
using namespace std;

// 오늘의 주제 : 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다.

// a[ 1 ]
// a라는 이름의 바구니를 할당하고 안에 1을 넣는다.
int a = 1;
int b = 2;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isInvincible = true;

unsigned char flag; //부호를 없애야 >> 를 하더라도 부호비트가 딸려오지 않음

//한 번 정해지면 절대 바뀌지 않을 값들
//constant의 약자인 const를 붙임(변수를 상수화 한다고 함)
//const를 붙였으면 초기값을 반드시 지정해야 함
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

//전역변수
//[데이터 영역]
//.data(초기값 있는 경우)
int c = 2;
//.bss(초기값 없는 경우)
int d;
//.rodata(읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
    //[스택 영역]
    int e = 3;

#pragma region 산술 연산
    // [산술 연산자]
    // 
    // [대입연산]
    a=b;
    // -> b라는 바구니 안에 있는 값을, a라는 바구니 안에 복사한다.

    // [사칙연산]
    // 언제 필요한가?
    // ex) 데미지 계산
    // ex) 체력을 깎는다거나
    // ex) 루프문에서 카운터를 1 증가시킨다거나
    // 증감 연산자
    a = a + 1; //add eax, 1 --> inc eax
    a++;
    b = a++;    // b = a -> a를 1 증가
    b = ++a;    // a를 1증가 -> b = a
    
#pragma endregion

#pragma region 비교 연산
    // 언제 필요한가?
    // ex) 체력이 0이 되면 사망
    // ex) 체력이 30% 이하면 궁극기를 발동 (100 * hp / maxHp)
    //

    // a == b : a와 b의 값이 같은가?
    // 같으면 1, 다르면 0
    isSame = (a == b);  //a==b 가 참이면 isSame=1

    // a != b : a와 b의 값이 다른가?
    // 다르면 1, 같으면 0
    isDifferent = (a != b);
    
    isGreater = (a > b);

    isSmaller = (a < b);

#pragma endregion

#pragma region 논리 연산
    // 언제 필요한가? 조건에 대한 논리적 사고가 필요할 때
    // ex) 로그인할 때 아이디도 같고 AND 비밀번호도 같아야 한다.
    // ex) 길드 마스터이거나 OR 운영자 계정이면 길드 해산 가능
    // 
    // ! not
    // 0이면 1, 그 외 0
    test = !isSame;  //사실상 isDifferent의 의미

    //&& and
    // a&&b -> 둘 다 같으면 1
    test = (hp <= 0 && isInvincible == false);    //죽음

    // || or
    // a || b -> 둘 중 하나라도 1이면 1 (둘 다 0이면 0)
    test = (hp > 0 || isInvincible == true);    // !(hp <= 0 && isInvincible == false);
    

#pragma endregion

#pragma region 비트 연산
    // 대표적으로 BitFlag
    // ~ bitwise not
    // 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0으로 뒤바꿈

    // & bitwise and
    // 두 숫자의 모든 비트 쌍을 대상으로, and를 한다

    // | bitwise or
    // 두 숫자의 모든 비트 쌍을 대상으로, or를 한다

    // ^ bitwise xor
    // 두 숫자의 모든 비트 쌍을 대상으로, xor를 한다

    // << 비트 좌측 이동
    // 비트열을 N만큼 왼쪽으로 이동
    // 왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 N개의 비트는 0으로 채운다
    // *2를 할 때 자주 보이는 패턴

    // >> 비트 우측 이동
    // 비트열을 N만큼 오른쪽으로 이동
    // 오른쪽의 넘치는 N개의 비트는 버림
    // 왼쪽 생성되는 N개의 비트는
    // - 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
    // - 아니면 0

    // 실습
    // 0b0000 [무적][공포][변이][스턴][공중부양]

    // 무적 상태로 만든다
    flag = (1 << INVINCIBLE);

    // 변이 상태를 추가한다(무적 + 변이)
    flag |= (1 << POLYMORPH);

    // 무적인지 확인하고 싶다? (다른 상태는 관심 없음)
    // bitmask
    bool invincible = ((flag & (1 << 3)) != 0);

    // 무적이거나 스턴 상태인지 확인하고 싶다면?
    bool mask = (1 << 3) | (1 << 1);
    bool mask2 = 0b1010;
    bool stunOrInvincible = ((flag & mask2) != 0);

#pragma endregion
}

