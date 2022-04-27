#include<iostream>
#include <bitset>
using namespace std;

// 오늘의 주제 : enum class

// unscoped enum 
// 기본 enum은 범위가 지정되어 있지 않음(전역)
// 이름(PlayerType)이 있으나마나임.
enum PlayerType
{
	PT_Knight,
	PT_Archer,
	PT_Mage
};

// enum class
// - scoped enum
// - 이름공간 관리가 좋음(scoped)
// - 암묵적인 변환 금지
enum class ObjectType
{
	Player,
	Monster,
	Projectile
};

int main()
{
	// enum 사용
	// 암묵적으로 허용
	double value1 = PT_Knight;

	// enum class 사용
	// 명시적 형변환 필요
	double value2 = static_cast<double>(ObjectType::Player);

	// 사용하기가 너무나 불편하다...
	int choice = static_cast<int>(ObjectType::Monster);
	if (choice == static_cast<int>(ObjectType::Monster))
	{
		// TODO
	}

	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Projectile));
	cout << bitset<4>(bitFlag) << endl;
	
	return 0;
}