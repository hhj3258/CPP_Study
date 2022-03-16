#include<iostream>
using namespace std;

// 오늘의 주제 : 다형성

// 객체지향
// - 상속성
// - 은닉성(캡슐화)
// - 다형성

// 다형성( Polymorphism = Poly(여러가지) + morph(형체, 몸?) ) = 겉은 똑같은데, 기능이 다르게 동작한다.
// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용
// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 사용
// 
// 동적 바인딩을 원한다면? -> 가상 함수(Virtual function)

// 그런데 실제 객체가 어떤 타입인지 어떻게 알고서 가상함수를 호출해준걸까
// - 가상 함수 테이블 (vftable) 이 생긴다!
// .vftable [ ] : 64bit OS에서 4바이트, 64bit OS에서 8바이트
// 
// 가상 함수가 존재할 시 Knight k 의 &k 즉 메모리 주소를 참고해보면 첫 줄에 가상 함수 테이블의 주소값이 추가로 할당된다.
// 이 가상 함수 테이블은 Player의 것과 Knight의 것이 따로 존재한다.
// void VMovePlayer(SSS* sss) 에서 매개변수로 들어온 객체가 무엇이냐에 따라 해당 객체의 주소값을 받아와
// 해당 객체의 가상 함수 테이블에 들어있는 VMove()를 실행하게 된다.

// 순수 가상 함수 : 구현은 없고 '인터페이스' 만 전달하는 용도로 사용하고 싶을 경우
// virtual void VAttack() = 0;
// Player 클래스가 이런 식으로 구현되어야 할 것임. -> 세부 구현은 Knight와 Mage 클래스에서 재정의 하는 것이 이치에 맞다.
// 추상 클래스 : 순수 가항 함수가 1개 이상 포함되면 바로 추상 클래스로 간주된다.
// - 직접적으로 '객체'를 만들 수 없게 됨.

class Player
{
public:
	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }
	// 오버로딩
	//void Move(int a) { cout << "Move Player (int) !" << endl; }

	// 가상함수 <- 동적 바인딩을 써보자
	virtual void VMove() { cout << "Move Player !" << endl; }
	virtual void VDie() { cout << "Die Player !" << endl; }

	// 순수 가상 함수
	//virtual void VAttack() = 0;

public:
	int _hp;
};

class Knight : public Player
{
public:
	Knight()
	{
		_stamina = 10;
	}

	// 오버라이딩
	void Move() { cout << "Move Knight !" << endl; }

	// 가상 함수는 재정의를 하더라도 가상 함수다!
	// virtual 키워드를 제거해도 여전히 가상 함수임.
	// virtual void VMove() == void VMove()
	virtual void VMove() { cout << "Move Knight !" << endl; }
	virtual void VDie() { cout << "Die Knight !" << endl; }

	virtual void VAttack() { cout << "VAttack Knight" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:
	int _mp;
};


void MovePlayer(Player* player)
{
	// 정적 바인딩 -> 컴파일타임에 결정
	// Player 객체가 매개변수로 들어올 것으로 예상하고 있음.
	// 매개변수에 Knight 객체가 들어와도 Player 클래스의 Move() 가 실행됨.
	player->Move();
}

void VMovePlayer(Player* player)
{
	// 동적 바인딩 -> 런타임에 결정 -> virtual 키워드
	// 매개변수에 들어오는 객체 종류에 따라 Player::VMove() 또는 Knight::VMove() 가 실행될 수도 있음.
	player->VMove();
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

int main()
{
	
	Player p;
	MovePlayer(&p);			// 플레이어는 플레이어다? YES
	// MoveKnight(&p);		// 플레이어는 기사다? NO <- 꼭 그렇진 않을 것

	Knight k;
	MoveKnight(&k);		// 기사는 기사다? YES
	MovePlayer(&k);		// 기사는 플레이어다? YES <- 기사이기 이전에 플레이어임!
	
	cout << "---------------------------------" << endl;

	Knight k2;
	VMovePlayer(&k2);

	return 0;
}