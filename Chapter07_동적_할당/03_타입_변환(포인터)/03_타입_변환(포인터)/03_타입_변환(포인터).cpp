#include<iostream>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	// 복사 생성자
	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};	// 이런 저런 정보들로 인해 비대해진
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
	// 복습
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// item2 가 포인터로 선언되었지만, main() 함수 안에 있으므로 Stack에 올라가 있다.
		// Stack에 올라가있는 item2는 '주소'를 가지고 있고, 이 '주소'를 따라가면 Heap 에 올라가있는 Item 이 있다.
		// Stack [ 주소(4~8byte) ] -> Heap [ type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();

		TestItem(item);
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);

		// delete 하지 않으면 메모리 누수(Memory Leak) -> 점점 가용 메모리가 줄어들어서 Crash
		delete item2;
	}

	// 배열
	{
		cout << "------------------------------------------------" << endl;

		// 진짜 아이템이 100개 있는 것 (스택 메모리에 올라와 있는)
		Item item3[100] = {};

		cout << "------------------------------------------------" << endl;

		// 아이템이 100개 있을까요?
		// No! 아이템을 가리키는 바구니가 100개. 실제 아이템은 1개도 없을 수도 있음.
		Item* item4[100] = {};
		
		// 아래처럼 아이템 생성
		*item4 = new Item;
		item4[50] = new Item;
		delete item4[0];
		delete item4[50];
	}

	return 0;
}