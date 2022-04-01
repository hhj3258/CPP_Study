#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{
	// 포인터라도 내부 데이터를 사용하기 위해서는 include가 필요하다.
	// - Monster의 구체적인 설계를 알 필요가 있기 때문.
	_target->_hp = 0;
	// 내부 함수를 사용할 때도 위와 마찬가지
	_target->KillMe();
}
