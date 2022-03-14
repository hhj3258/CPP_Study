#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

struct StatInfo
{
    int hp;
    int attack;
    int defence;
};

// 메모리
// [     Knight     ]   <- 2층
// [  [  Player  ]  ]   <- 1층
// 건축할 때 1층을 올린 다음 2층을 올린다.(생성자 순서)
// 해체할 때 2층을 먼저 해체한 다음 1층을 해체한다.(소멸자 순서)

// 상속(Inheritance)? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(여러개) / 소멸자(1개)

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! 그냥 둘 다 호출하자!!
// - 순서 : 부모 생성자 - 자식 생성자 - 자식 소멸자 - 부모 소멸자

// 부모님 클래스를 만들자
class Player
{
public:
    Player()
    {
        _hp = 0;
        _attack = 0;
        _defence = 0;

        cout << "Player() 기본 생성자 호출" << endl;
    }

    Player(int hp)
    {
        _hp = hp;
        _attack = 0;
        _defence = 0;

        cout << "Player(int hp) 생성자 호출" << endl;
    }

    ~Player()
    {
        cout << "~Player() 소멸자 호출" << endl;
    }

    void Move() { cout << "Player Move 호출" << endl; }
    void Attack() { cout << "Player Attack 호출" << endl; }
    void Die() { cout << "Player Die 호출" << endl; }

public:
    int _hp;
    int _attack;
    int _defence;
};

// Player를 상속받은 Knight 클래스
// - Player의 메모리 크기(4바이트 * 3)을 그대로 받고 더 추가 가능.
class Knight : public Player
{
public:
    // 생성자와 소멸자는 부모 따로 자식 따로 만들어진다.
    Knight()
        /*
        선처리 영역
        - 여기서 Player() 생성자가 호출된다.
        - Player() 생성자가 모두 실행된 후에 Knight() 생성자가 마저 실행된다.
        - 순서는 결국 부모 생성자 -> 자식 생성자 로 출력된다.
        */
    {
        _stamina = 100;

        cout << "Knight() 기본 생성자 호출" << endl;
    }

    Knight(int stamina) : Player(100)
        /*
        선처리 영역
        - 여기서 Player(int hp) 생성자가 호출된다.
        */
    {
        _stamina = stamina;

        cout << "Knight(int stamina) 생성자 호출" << endl;
    }

    ~Knight()
    {
        cout << "~Knight() 소멸자 호출" << endl;
    }
    /*
    후처리 영역
    - 여기서 ~Player() 소멸자가 호출된다.
    */

    // 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든?
    void Move() { cout << "Knight Move 호출" << endl; }

public:
    int _stamina;
};

class Mage : public Player
{
public:

public:
    int _mp;
};

int main()
{
    Knight k(100);

    k._hp = 100;
    k._attack = 10;
    k._defence = 5;
    k._stamina = 50;

    // 나만의 버전 호출
    //k.Move();

    // 부모님 버전 호출
    // 하지만 쓸 일 없다. -> 이럴거면 재정의를 할 필요가 없으니까.
    //k.Player::Move();

    return 0;
}