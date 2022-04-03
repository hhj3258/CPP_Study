#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터
// - 결론: 함수를 가리키는 포인터

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId;
	int _rarity;		// 희귀도
	int _ownerId;	//소지자 ID
};

// 함수포인터의 활용방안
// bool(*selector)(Item*) <- 이 시그니쳐와 동일하기만 하면
// FindItem 함수를 수정하지 않아도 여러가지 함수를 입맛대로 매개변수로 넣어줄 수 있음
// ex) 희귀도 판단, 소지자 판단, 아이템ID가 맞는지 등등
Item* FindItem(Item items[], int itemCount, bool(*selector)(Item*))
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		// TODO 조건
		if (selector(item)==true)
			return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item)
{
	return (item->_rarity >= 2);
}

int main()
{
	int a = 10;

	// 1) 포인터				*
	// 2) 변수이름		ptr
	// 3) 데이터 타입	int
	int* ptr = &a;

	// 함수
	typedef int(FUNC_TYPE)(int a, int b);

	// 1) 포인터				*
	// 2) 변수이름		fn
	// 3) 데이터 타입	함수 (인자는 int, int), (반환은 int)
	FUNC_TYPE* fn;

	// 함수 포인터
	// 함수의 시그니쳐와 동일해야 함(리턴타입, 매개변수)
	//fn = Add;
	fn = Sub;

	// 함수의 이름은 함수의 시작 주소를 들고 있다고 볼 수 있다(배열과 유사)
	int result = fn(1, 2);
	cout << result << endl;

	Item items[10] = {};
	items[3]._rarity = 2;	//Rare
	Item* rareItem = FindItem(items, 10, IsRareItem);

	return 0;
}