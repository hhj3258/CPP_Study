#include <iostream>
using namespace std;

// 오늘의 주제 : 객체 지향의 시작

// 객체지향 프로그래밍
// 절차(procedural)지향 프로그래밍 <- 이전까지 한 것
// - procedure = 함수라는 뜻도 있음.

// 데이터 + 가공(로직, 동작) = 프로그램 OR 게임

// 객체지향의 주인공 = 객체
// 객체란? 플레이어, 몬스터, GameRoom ...

// Knight를 설계
// - 속성(데이터): hp, attack, position(y, x)
// - 기능(동작): Move, Attack, Die
// class는 일종의 설계도 -> 설계도를 실제로 메모리에 할당해서 사용할 필요가 있음.
class Knight
{
public:
	// 멤버 함수 '선언'
	void Move(int y, int x);
	void Attack();
	// 인라인 함수 구현
	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	// 디버깅 해보면 sizeof(k1) 의 크기는 16바이트(int 4개)
	// 멤버 변수는 잡혀있지만 멤버 함수는 메모리에 잡히지 않는다.
	int hp;
	int attack;
	int posY;
	int posX;
};

void Move(Knight* knight, int y, int x)
{
	knight->posY = y;
	knight->posX = x;
}

// 클래스 밖에서도 구현 가능
void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

int main()
{
	// Instantiate 객체를 만든다!
	// 살아움직이게 만든 것.
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	// 전역함수는 k1의 존재를 알려줄 필요가 있음.
	Move(&k1, 3, 3);
	// k1의 멤버함수는 이미 k1에 속해있음.
	// 어셈블리 레벨에서 봤을 때 전역함수와 멤버함수는 동작방식에 큰 차이가 없다.
	// 문법을 봤을 때 편의성과 명확성에서 차이가 있다.
	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}
