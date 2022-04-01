#pragma once
#include "Monster.h"

// ���� ���� : Monster Ŭ������ ���縦 �����Ϸ����� �̸� �˸���.
class Monster;

class Player
{
public:
	void KillMonster();

public:
	int _hp;
	int _attack;

	// �̷� ������ ���漱�� ����
	class Monster* _target;

	// ���� ��ü ������ ���ؼ��� include �ʿ�
	// - Monster�� �� ����Ʈ����(Ȥ�� ����) �˾ƾ� ��!
	Monster _target2;

	// �Ʒ����� �ڱ� �ڽ��� ���� ��ü�� ������ ���� ����.
	// - Player�� �ϼ��ϱ� ���� ��������� Player�� �����ϰ� �Ǳ� ������
	//Player _targetP1;

	// Player* �� ������ �� �ִ�.
	// - �����ʹ� �׻� ����ũ��! (4 or 8 byte)
	// - Player* ũ�⸦ �˱� ������ Player ��ü�� ���� �� �ִ�.
	Player* _targetP2;
};