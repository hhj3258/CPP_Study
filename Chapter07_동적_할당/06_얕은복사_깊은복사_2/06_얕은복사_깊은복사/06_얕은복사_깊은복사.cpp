#include<iostream>
using namespace std;

// 오늘의 주제 : 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}

	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}

	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet& pet)" << endl;
		return *this;
	}

	~Pet()
	{
		cout << "~Pet()" << endl;
	}

public:
	int dummy[500] = {};
};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	// 복사 생성자
	Player(const Player& player)
	{
		cout << "Player(const Player& player)" << endl;
		_level = player._level;
	}

	// 복사 대입 연산자
	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player& player)" << endl;
		_level = player._level;

		return *this;
	}

public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
	}

	// 명시적 복사 생성자를 만들었을 때, 부모&멤버 클래스의 복사 생성자가 호출되길 원한다면
	// 이 역시 명시적으로 선언해줄 필요가 있다.
	// 그렇게 하지 않는다면, 부모&멤버 클래스의 '기본 생성자'가 호출된다.
	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
	{
		cout << "Knight(const Knight& knight)" << endl;

		_hp = knight._hp;
	}

	Knight& operator=(const Knight& knight)
	{
		cout << "operator=(const Knight& knight)" << endl;

		Player::operator=(knight);
		_pet = knight._pet;
		_hp = knight._hp;

		return *this;
	}
	
	~Knight()
	{
	}

public:
	int _hp = 100;
	Pet _pet;
};

int main()
{
	// ------------------------------- 얕은복사 vs 깊은복사 2 -------------------------------
	Knight knight; // 기본 생성자
	knight._hp = 200;
	knight._level = 99;

	//cout << "-------------------- 복사 생성자 --------------------" << endl;
	//Knight knight2 = knight;	// 복사 생성자

	
	Knight knight3;	// 기본 생성자
	cout << "-------------------- 복사 대입 연산자 --------------------" << endl;
	knight3 = knight;	// 복사 대입 연산자
	              
	// 실험)
	// <아래 실험은 Knight가 주인공>
	// - 암시적 복사 생성자 Steps
	// 1) 부모 클래스(Player)의 '복사 생성자' 호출
	// 2) 멤버 클래스(Pet)의 '복사 생성자' 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 -> 얕은 복사(Shallow Copy)
	// 
	// - 명시적 복사 생성자 Steps
	// (이 경우 모든 복사에 관한 책임은 프로그래머에게 있다.)
	// 1) 부모 클래스(Player)의 '기본 생성자' 호출
	// 2) 멤버 클래스(Pet)의 '기본 생성자' 호출

	// - 암시적 복사 대입 연산자 Steps
	// 1) 부모 클래스의 복사 대입 연산자 호출
	// 2) 멤버 클래스의 복사 대입 연산자 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 -> 얕은 복사
	// 
	// - 명시적 복사 대입 연산자 Steps
	// 1) 컴파일러가 알아서 해주는거 없음

	// 왜 이렇게 혼란스러울까?
	// 객체를 '복사' 한다는 것은 두 객체의 값들을 일치시키려는 것
	// 따라서 기본적으로 얕은 복사(Shallow Copy) 방식으로 동작

	// 명시적 복사를 한다 -> [모든 책임]을 프로그래머한테 위임하겠다는 의미

	return 0;
}