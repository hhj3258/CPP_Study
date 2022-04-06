#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 객체

void HelloWorld()
{
	cout << "Hello World" << endl; 
}

class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}

private:
	int _hp = 100;
};

class Functor
{
public:
	void operator() ()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator() (int number)
	{
		cout << "Functor Test2" << endl;
		_value += number;
		cout << _value << endl;

		return true;
	}

private:
	int _value = 0;
};

class MoveTask
{
public:
	void operator() ()
	{
		// TODO
		cout << "해당 좌표로 플레이어 이동" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};

int main()
{
	// 함수 객체(Functor) : 함수처럼 동작하는 객체

	// 함수 포인터 선언
	// 동작을 넘겨줄 때 유용하다
	void (*pfunc)();
	pfunc = &HelloWorld;
	(*pfunc)();

	// 함수 포인터의 단점
	// 1) 시그니쳐가 동일하지 않으면 사용할 수 없다.
	// 2) 상태를 가질 수 없다.(클래스 멤버 데이터 같은 것)

	// 함수 객체
	Functor functor;
	functor();
	bool ret = functor(3);

	// MMO에서 함수 객체를 활용하는 예시
	// 클라 <-> 서버
	// 서버 : 클라가 보내준 네트워크 패킷을 받아서 처리
	// ex) 클라 : 나 (5,0) 좌표로 이동시켜줘!

	// 함수 객체의 장점 : 만들어주는 시점과 실행하는 시점을 분리할 수 있다!
	MoveTask task;

	// 주문서
	task._playerId = 1000;
	task._posX = 5;
	task._posY = 0;

	// 나중에 여유 될 때 일감을 실행한다
	task();

	return 0;
}