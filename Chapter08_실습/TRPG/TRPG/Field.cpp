#include "Field.h"
#include "Monster.h"
#include <stdlib.h>
#include "Player.h"
#include <iostream>
using namespace std;

Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr)
	{
		delete _monster;
		_monster = nullptr;
	}
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = rand() % 3;

	if (randValue == MT_ORC)
		_monster = new Orc();
	else if (randValue == MT_SKELETON)
		_monster = new Skeleton();
	else if (randValue == MT_SLIME)
		_monster = new Slime();
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		_monster->OnAttacked(player);
		if (_monster->IsDead())
		{
			CountDeadMonster(_monster);

			_monster->PrintInfo();

			delete _monster;
			_monster = nullptr;

			break;
		}

		player->OnAttacked(_monster);
		if (player->IsDead())
		{
			player->PrintInfo();
			PrintDeadMonsterInfo();
			break;
		}
	}
}

void Field::CountDeadMonster(Monster* monster)
{
	_arrDeadMonster[monster->GetMonsterType()] += 1;
}

void Field::PrintDeadMonsterInfo()
{
	cout << "[쓰러뜨린 몬스터 정보]" << endl;
	cout << "Orc: " << _arrDeadMonster[MT_ORC] << ' '
			<< "Slime: " << _arrDeadMonster[MT_SLIME] << ' ' 
			<< "Skeleton: " << _arrDeadMonster[MT_SKELETON] << endl;

	for (int i = 0; i < 3; i++)
		_arrDeadMonster[i] = 0;
}