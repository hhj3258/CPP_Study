#include <iostream>
using namespace std;

// 오늘의 주제 : 생성자와 소멸자 1~2

// [생성자(Constructor)와 소멸자(Destructor)]
// 클래스에 '소속'된 함수들을 멤버 함수라고 함
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 존재 가능)
// - 끝(소멸) -> 소멸자 (오직 1개만)

// [암시적(Implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면.
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음!

// Knight를 설계
// class는 일종의 설계도 -> 설계도를 실제로 메모리에 할당해서 사용할 필요가 있음.
class Knight
{
public:
	// [1] 기본 생성자 (인자가 없음)
	Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	// [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
	// 일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다.
	// 인자로 들어온 기사와 판박이인 기사를 만든다.
	// const 붙는 이유? : 인자로 들어온 값을 바꿔줄 필요가 전혀 없기 때문에.
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	// [3] 기타 생성자

	// 이 중에서 인자를 1개만 받는 [기타 생성자]를
	// [타입 변환 생성자]라고 부르기도 함
	// explicit : 명시적인 용도로만 사용할 것!
	// - Knight k5 = 1; 과 같이 암시적으로 사용 불가
	// - Knight k5 = (Knight)1; 처럼 명시적으로 써준다.
	explicit Knight(int hp)
	{
		cout << "Knight(int) 생성자 호출" << endl;

		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	Knight(int hp, int attack, int posY, int posX)
	{
		cout << "Knight(int) 생성자 호출" << endl;

		_hp = hp;
		_attack = attack;
		_posY = posY;
		_posX = posX;
	}

	// 소멸자
	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}

	// 멤버 함수 '선언'
	void Move(int y, int x);
	void Attack();
	// 인라인 함수 구현
	void Die()
	{
		this->_hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	// 디버깅 해보면 sizeof(k1) 의 크기는 16바이트(int 4개)
	// 멤버 변수는 잡혀있지만 멤버 함수는 메모리에 잡히지 않는다.
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

// 클래스 밖에서도 구현 가능
void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

int main()
{
	// [3] 생성자 호출
	Knight k1(100);
	//k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// [2] 복사 생성자 호출
	Knight k2(k1);
	Knight k3 = k1;

	Knight k4;		// 생성자
	k4 = k1;		// 복사

	// k1의 멤버함수는 이미 k1에 속해있음.
	// 어셈블리 레벨에서 봤을 때 전역함수와 멤버함수는 동작방식에 큰 차이가 없다.
	// 문법을 봤을 때 편의성과 명확성에서 차이가 있다.
	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;
	float f = num;
	// 명시적 형변환
	float f2 = (float)num;

	Knight k5 = (Knight)1;

	return 0;
}
