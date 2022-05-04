#include <iostream>
using namespace std;

// 오늘의 주제 : 오른값(rvalue) 참조와 std::move

class Pet
{

};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	Knight(const Knight& knight)
	{
		cout << "Knight(const Knight&)" << endl;
	}

	// 이동 생성자
	Knight(Knight&& knight) noexcept
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		_hp = knight._hp;

		// knight의 pet의 주소를 받아 같은 펫을 둘이 쓰는 것은 말이 안됨.
		// 즉, pet을 새로 만들어야 한다.(깊은 복사)
		if(knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// 이동 대입 연산자
	// 매개변수로 들어온 knight 는 이후 더이상 사용하지 않을 것.
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(Knight&&)" << endl;

		_hp = knight._hp;
		// knight는 이후 사용되지 않을 객체임.
		// 즉, knight의 pet을 이제부터 내가 사용(복사)하고
		// knight의 pet은 삭제한다.
		_pet = knight._pet;
		knight._pet = nullptr;
	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) {}
// 왼값 참조
void TestKnight_Copy_LvalueRef(Knight& knight) {}
void TestKnight_Copy_Const_LvalueRef(const Knight& knight) {}

// 오른값 참조
// - 원본 객체를 받아와서 수정 가능.
// - 참조와 뭐가 다른데?
// -- 오른값 : 이동 대상
// -- 오른값은 곧 더이상 사용하지 않는다는 의미. 내맘대로 수정 가능
void TestKnight_Copy_RvalueRef(Knight&& knight) 
{
	knight._hp = 0;
}

int main()
{
	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

	int a = 3;
	a = 4;
	//3 = a;	// Error! 식이 수정할 수 있는 lvalue여야 함
	//a++ = 5;

	Knight k1;
	TestKnight_Copy(k1);
	TestKnight_Copy_LvalueRef(k1);

	// Error! : Knight() 는 임시 객체(rvalue) 임
	// 함수 내부에서 Knight() 를 수정하는 일은 의미가 없음.
	//TestKnight_Copy_LvalueRef(Knight());

	// OK! : const 참조 값은 가능
	// 내부에서 읽기(const)만 한다는 의미
	TestKnight_Copy_Const_LvalueRef(Knight());

	TestKnight_Copy_RvalueRef(Knight());
	
	// std::move : k2를 오른값으로 만든다.
	// - 내부적으로는 static_cast 사용
	Knight k2;
	TestKnight_Copy_RvalueRef(static_cast<Knight&&>(k2));
	TestKnight_Copy_RvalueRef(std::move(k2));
	std::cout << k2._hp; 

	Knight k3;
	k3._hp = 1000;
	k2._pet = new Pet();

	Knight k4;
	k4 = std::move(k3);	// 이동 대입 연산자 호출

	unique_ptr<Knight> uptr = make_unique<Knight>();
	//unique_ptr<Knight> uptr2 = uptr;	//Error!
	unique_ptr<Knight> uptr2 = move(uptr);

	return 0;
}