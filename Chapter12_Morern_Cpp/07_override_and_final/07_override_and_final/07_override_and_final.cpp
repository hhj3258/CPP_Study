#include <iostream>
using namespace std;

// 오늘의 주제 : override, final
// 가상함수와 연관

class Player
{
public:
    virtual void Attack()
    {
        cout << "Player!" << endl;
    }

    // final
    // 파생 클래스에서 재정의 금지!
    virtual void Move() final
    {

    }
};

class Knight : public Player
{
public:
    // 재정의(override) -> 오버로딩과는 다르다 오버로딩과는...
    // virtual 키워드 만으로는 오버라이딩을 한 것인지, 처음 만든 것인지 확실치 않다.
    // (실수) 함수의 시그니쳐가 다르면, 오버라이딩이 아니게 된다.
    // override 키워드로 해결!
    virtual void Attack() override
    {
        cout << "Knight!" << endl;
    }

    // 오버로딩(overloading) : 함수 이름의 재사용
    void Attack(int a) { }

    // 부모 클래스에서 final 키워드로 인해 재정의 불가
    //virtual void Move()
    //{

    //}
};

int main()
{
    Player* player = new Knight();
    player->Attack();
    
    return 0;
}