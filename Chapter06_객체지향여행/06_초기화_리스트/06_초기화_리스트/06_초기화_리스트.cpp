#include<iostream>
using namespace std;

// 오늘의 주제 : 초기화 리스트

// 멤버 변수 초기화? 다양한 문법이 존재한다.

// 초기화를 왜 해야할까? 귀찮은데...
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서 -> {  }
// - 초기화 리스트
// - C++11 문법
// -- 전부 모던 c++ 로 통일하면 되지 않나?
// -- 게임업계는 팀에 따라 아주 보수적인 팀도 많음, 다양한 문법을 알아두는 것도 중요.

// 초기화 리스트?
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다.
// - 생성자 내 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다.
// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, cosnt 타입)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) 
	{ 
		cout << "Inventory(int size)" << endl; 
		_size = size;
	}

	~Inventory() { cout << "~Inventory" << endl; }

public:
	// c++11 문법
	int _size = 10;
};

class Player
{
public:
	Player() { }
	Player(int id) { }
};

// Is-A (Knight Is-A Player? 기사는 플레이어다) -> OK -> 상속관계
// Has-A (Knight Has-A Inventory? 기사는 인벤토리냐?) NO -> 포함관계

class Knight : public Player
{
public:
	// 초기화 리스트
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		/*
		선처리 영역

		Inventory()
		*/
	{
		// 생성자 내에서 초기화
		_hp = 100;

		// 선처리 영역에서 _inventory의 기본 생성자로 객체를 생성했는데
		// 생성자 정의 부분에서 Inventory(20) 의 생성자로 '한 개 더' 객체를 만들고 있다.
		// 비효율적!
		//_inventory = Inventory(20);
	}

public:
	int _hp;	 // 초기화를 안하면 쓰레기 값이 들어있다.
	Inventory _inventory;

	// 레퍼런스, const 는 반드시 '초기화 리스트' OR 'c++11 문법'으로 초기화를 해주어야 한다.
	// 레퍼런스 타입은 null 값을 가질 수 없다. 포인터와 다르게.
	// const 타입은 초기 값을 변경할 수 없다.
	int& _hpRef;
	const int _hpConst;
};

int main()
{
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
	{
		cout << "Knight is Dead" << endl;
	}

	return 0;
}