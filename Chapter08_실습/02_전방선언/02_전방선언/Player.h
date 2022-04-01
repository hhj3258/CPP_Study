#pragma once
#include "Monster.h"

// 전방 선언 : Monster 클래스의 존재를 컴파일러에게 미리 알린다.
class Monster;

class Player
{
public:
	void KillMonster();

public:
	int _hp;
	int _attack;

	// 이런 식으로 전방선언 가능
	class Monster* _target;

	// 실제 객체 선언을 위해서는 include 필요
	// - Monster가 몇 바이트인지(혹은 설계) 알아야 함!
	Monster _target2;

	// 아래같이 자기 자신의 실제 객체를 선언할 수는 없다.
	// - Player를 완성하기 위해 재귀적으로 Player를 참조하게 되기 때문에
	//Player _targetP1;

	// Player* 는 선언할 수 있다.
	// - 포인터는 항상 고정크기! (4 or 8 byte)
	// - Player* 크기를 알기 때문에 Player 객체를 만들 수 있다.
	Player* _targetP2;
};