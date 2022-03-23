#include<iostream>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	// 복사 생성자
	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	// virtual 키워드가 있어야 상속 관계에 있는 소멸자가(즉, 자식의 소멸자가) 호출이 된다.
	// delete item 할 시 virtual이 없으면 ~Item() 호출
	// virtual이 있으면, 해당하는 클래스의 소멸자(~Weapon(), ~Armor() 등) 호출
	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};	// 이런 저런 정보들로 인해 비대해진
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		_damage = rand() % 100;
		cout << "Weapon" << endl;
	}

	~Weapon()
	{
		cout << "~Weapon" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor" << endl;
	}

	~Armor()
	{
		cout << "~Armor" << endl;
	}

public:
	int _defence = 0;
};

// item 객체가 '복사'된다.
// 복사 생성자 호출
// 함수가 끝날 시점에 '소멸자' 호출
void TestItem(Item item)
{

}

// '주소'를 받아온다.
// '복사' 되지 않는다.
// 생성자, 소멸자 모두 호출되지 않는다.
void TestItemPtr(Item* item)
{

}

int main()
{
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// 암시적으로는 NO
		// 명시적으로는 OK

		// Stack [ 주소 ]
		/*
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbId = 4;	// knight의 크기를 넘어선 엉뚱한 메모리를 바꾼다.
		*/

		// 다행히도 오염된 메모리가 있다면 컴파일러가 delete 시에 잡아준다.
		// 항상 컴파일러가 잡아준다고는 할 수 없다.
		delete knight;
	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();

		// item 은 항상 weapon 인가? NO
		// item 의 메모리 크기가 weapon 보다 작다.
		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;

		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		// weapon은 항상 item 인가? Yes
		Item* item = weapon;

		delete weapon;
	}

	// 명시적으로 타입 변환할 때는 항상항상 조심해야 한다!
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안 하면 되는거 아닌가? -> 아님

	// inventory[] 원소들이 가질 값은 '주소'임. Heap의 어딘가에 있을 값의 주소.
	Item* inventory[20] = {};
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0,1

		switch (randValue)
		{
		case 0:
			// Heap에 동적할당한 Weapon의 주소를 넣는다.
			inventory[i] = new Weapon();
			break;
		case 1:
			// Heap에 동적할당한 Armor의 주소를 넣는다.
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		// 포인터를 다룰 땐 항상 nullptr 체크
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			// 안전하지 않은 변환이라고 했지만, 이 경우 안전함.
			// 위에서 new Weapon 으로 동적 할당 해줬기 때문에.
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ********************** 매우 매우 중요 **********************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		// 포인터를 다룰 땐 항상 nullptr 체크
		if (item == nullptr)
			continue;
		
		// virtual ~item() 이므로 item이 가지고 있는 것이 Weapon인지, Armor인지에 따라 다른 소멸자가 호출된다.
		delete item;
	}

	return 0;
}