#pragma once

class Player;
class Monster;

class Field
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();
	void StartBattle(Player* player);

	void CountDeadMonster(Monster* monster);
	void PrintDeadMonsterInfo();

private:
	Monster* _monster;
	int _arrDeadMonster[3] = { 0 };
};

