#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;

// 오늘의 주제 : 람다(lambda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() {}

	Item(int itemId, Rarity rarity, ItemType type)
		: _itemId(itemId), _rarity(rarity), _type(type)
	{

	}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉽게 만드는 문법
	// 람다 자체로 c++11에 '새로운' 기능이 들어간 것은 아니다.

#pragma region 람다 사용법
	{
		// 함수 객체
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		// 람다 표현식(lambda expression)
		// 람다 객체 = 클로저(closure) = 람다에 의해 만들어진 실행시점 객체
		auto isUniqueLambda = [](Item& item)
		{
			return item._rarity == Rarity::Unique;
		};

		// 람다 활용법 1
		auto findIt = std::find_if(v.begin(), v.end(), isUniqueLambda);

		// 람다 활용법 2
		findIt = std::find_if(v.begin(), v.end(),
			[](Item& item) { return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "아이템ID : " << findIt->_itemId << endl;
	}
#pragma endregion


	{
		// 함수 객체
		struct FindItem
		{
			FindItem(int itemId, Rarity rarity, ItemType type) 
				: _itemId(itemId), _rarity(rarity), _type(type)
			{

			}

			bool operator()(Item& item)
			{
				return	item._itemId == _itemId &&
						item._rarity == _rarity &&
						item._type == _type;
			}

			int _itemId;
			Rarity _rarity;
			ItemType _type;
		};

		int itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		// [ ] 캡쳐(capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사
		// 사진을 찰칵 [캡쳐]하듯... 일종의 스냅샷을 찍는다는 느낌
		// 기본 캡처 모드 : 값 방식(=), 참조 방식(&)
		// 변수마다 캡쳐 모드를 지정해서 사용 가능 : 값 방식(name), 참조 방식(&name)
		auto findByItem = [&itemId, rarity, type](Item& item)
		{
			return	item._itemId == itemId &&
					item._rarity == rarity &&
					item._type == type;
		};

		itemId = 10;

		// 함수 객체
		//auto findIt = std::find_if(v.begin(), v.end(), FindItem(4,Rarity::Unique, ItemType::Weapon));
		// 람다
		auto findIt = std::find_if(v.begin(), v.end(), findByItem);

		if (findIt != v.end())
			cout << "아이템ID : " << findIt->_itemId << endl;
		else
			cout << "아이템이 없습니다." << endl;

	}


	{
		class Knight
		{
		public:
			auto ResetHpJob()
			{
				// [=] : this->_hp 를 '참조' 하고 있다. '복사'가 아니다.
				//auto f = [=]() { _hp = 200; }; // 위험한 발상

				
				auto f = [this]() { _hp = 200; }; // 위와 같음
				// 근본적인 문제 해결은 아님.(this->_hp를 수정하는 위험성)
				// 하지만, 명시적으로 어떤 데이터가 들어온 것인지 알 수 있음.
				// 명확하게 알 수 있으므로 실수를 방지할 수 있다.

				return f;
			}

		public:
			int _hp = 100;
		};

		Knight* k = new Knight();
		auto job = k->ResetHpJob();	// 함수 객체를 받아준다.
		delete k;	// k를 삭제한다.
		job();		// ResetHpJob() 을 호출한다.
		// 위처럼 k 삭제 후, job()에서 this->_hp=200 으로 변경하면 어떻게 될까?
		// 이미 날아간 메모리인 k의 _hp를 수정하는 것이므로, 메모리 오염 발생
		// 심지어 바로 크래시가 나지도 않는다.
	}

#pragma region 우선순위 큐 람다 cmp 테스트
	{
		auto cmp = [](Item a, Item b) -> bool
		{
			return a._rarity < b._rarity;
		};

		priority_queue<Item, vector<Item>, decltype(cmp)> pq(cmp);

		struct cmp3
		{
			bool operator()(Item a, Item b)
			{
				return a._rarity > b._rarity;
			}
		};

		priority_queue<Item, vector<Item>, cmp3> pq;


		pq.emplace(3, Rarity::Common, ItemType::Armor);
		pq.emplace(1, Rarity::Rare, ItemType::Armor);
		pq.emplace(2, Rarity::Common, ItemType::Armor);
		pq.emplace(1, Rarity::Unique, ItemType::Armor);


		//while (!pq.empty())
		//{
		//	cout << pq.top()._itemId << " ";
		//	if (pq.top()._rarity == Rarity::Common)
		//		cout << "Common" << endl;
		//	else if (pq.top()._rarity == Rarity::Rare)
		//		cout << "Rare" << endl;
		//	else if (pq.top()._rarity == Rarity::Unique)
		//		cout << "Unique" << endl;

		//	pq.pop();
		//}
	}
#pragma endregion



	return 0;
}