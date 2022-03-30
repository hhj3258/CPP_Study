#include<iostream>
using namespace std;

// 오늘의 주제 : 캐스팅 (타입 변환)

class Player
{
public:
	virtual ~Player() { }
};

class Knight : public Player
{

};

class Archer : public Player
{

};

class Dog
{

};

// 1) static_cast - 사용빈도 80%
// 2) dynamic_cast - 사용빈도 10%
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
#pragma region static_cast
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다
	// 1) int <-> float
	// 2) Player* -> Knight* (다운캐스팅=부모에서 자식으로)

	int hp = 100;
	int maxHp = 200;
	//float ratio = (float)hp / maxHp;		// C 스타일
	float ratio = static_cast<float>(hp) / maxHp;		// C++ 스타일

	// 부모 -> 자식 캐스팅
	Player* p1 = new Knight();
	// 컴파일러가 안전하지 않다고 인식하기 때문에 명시적 캐스팅 필요
	//Knight* k1 = (Knight*)p1;		// C 스타일
	Knight* k1 = static_cast<Knight*>(p1);		// C++ 스타일
#pragma endregion

#pragma region dynamic_cast
	// dynamic_cast : 상속 관계에서의 안전 형변환
	// RTTI (RunTime Type Information) : 
	// - 런타임에서 관리하는 정보
	// - 실시간으로 코드가 동작할 때 타입을 확인할 수 있는 기법
	// 다형성을 활용하는 방식
	Player* p2 = new Knight();
	// 반드시 virtual 함수가 하나는 있어야 한다.(가상 함수 테이블을 참조하는 듯)
	// - virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블(vftable) 주소가 생긴다.
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 반환 <- p2=new Archer(); 일 경우
	Knight* k2 = dynamic_cast<Knight*>(p2);
#pragma endregion

#pragma region const_cast
	// const_cast : const를 붙이거나 떼거나 할 때 사용
	const char* str = "Rookies";
	PrintName(const_cast<char*>(str));
#pragma endregion

#pragma region reinterpret_cast
	// 가장 위험하고 강력한 형태의 캐스팅
	// 're-interpret' : 다시-간주하다, 다시-생각하다
	// - 포인터랑 전혀 관계없는 다른 타입 변환 등
	Knight* k3 = new Knight();

	__int64 address = reinterpret_cast<__int64>(k3);

	Dog* dog1 = reinterpret_cast<Dog*>(k3);

	void* vPtr = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(vPtr);

#pragma endregion


	return 0;
}