#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "----------------------------------------" << endl;
	if (IsDead())
		cout << "[몬스터를 쓰려뜨렸습니다!]" << endl;
	cout << "[몬스터 정보]" << " HP: " << _hp << " ATT: " << _attack << " DEF: " << _defence << endl;
	cout << "----------------------------------------" << endl;
}