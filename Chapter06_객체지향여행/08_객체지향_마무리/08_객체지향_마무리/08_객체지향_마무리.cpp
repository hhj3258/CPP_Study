#include <iostream>
using namespace std;

// 오늘의 주제 : 객체지향 마무리

// 1) struct vs class 차이점은?

// c++에서는 struct나 class나 종이 한 장 차이다.
// struct는 기본 접근 지정자가 public 이고, class 는 private이다.
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.(추측)
// -> struct는 그냥 구조체 (데이터 묶음)을 표현하는 용도로 활용하자.
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도.

// 구조체에도 생성자, 소멸자 사용 가능
struct TestStruct
{
    int _a;
    int _b;
};

class TestClass
{
    int _a;
    int _b;
};

// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
    // 특정 마린 객체에 종속적
    int _hp;

    void TakeDamage(int damage)
    {
        _hp -= damage;
    }


    // 특정 마린 객체와 무관.
    // 마린이라는 '클래스' 자체와 연관
    static int s_attack; // 설계도 상으로만 존재

    static void SetAttack()
    {
        s_attack = 100;
    }
};

// static 변수는 어떤 메모리를 사용할까?
// 초기화 하면 .data
// 초기화 안 하면 .bss
int Marine::s_attack = 0;

class Player
{
public:
    int _id;
};

int GenerateId()
{
    // 정적 지역 객체
    // 생명주기 : 프로그램의 시작/종료와 함께 함. (메모리에 항상 올라가 있음)
    // 가시범위(사용범위) : 블럭 내부, 선언된 함수 or 클래스 내부
    static int s_id = 1;

    return s_id++;
}

int main()
{
    Marine::s_attack = 6;

    Marine m1;
    m1._hp = 40;
    //m1.s_attack = 6;

    Marine m2;
    m2._hp = 14;
    //m2.s_attack = 6;

    // 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 끝)
    /*m1.s_attack = 7;
    m2.s_attack = 7;*/
    Marine::s_attack = 7;
    Marine::SetAttack();

    static int id = 10;
    int a = id;

    for (int i = 0; i < 5; i++)
        cout << GenerateId() << endl;

    return 0;
}
