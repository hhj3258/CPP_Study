#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{
	// �����Ͷ� ���� �����͸� ����ϱ� ���ؼ��� include�� �ʿ��ϴ�.
	// - Monster�� ��ü���� ���踦 �� �ʿ䰡 �ֱ� ����.
	_target->_hp = 0;
	// ���� �Լ��� ����� ���� ���� ��������
	_target->KillMe();
}
