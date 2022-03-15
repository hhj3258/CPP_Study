#include <iostream>
using namespace std;

// 오늘의 주제 : 은닉성

// 객체지향
// - 상속성(코드의 재사용)
// - 은닉성(안전을 위한 숨김) = 캡슐화
// - 다형성

// ----------------------------------------------------------------------------------------

// 은닉성(Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다! 라는 의미
// 숨기는 이유?
// - 정말 위험하고 건드리면 안되는 경우
// - 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들, 페달, 엔진, 문, 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들/페달/문
// 몰라도 되는 것?(건드리면 큰일 나는 부분)
// - 엔진, 각종 전기선

// ----------------------------------------------------------------------------------------

// 접근 지정자
// public (공개적), protected (보호받는), private (개인적인)
// - public : 누구한테나 공개. 실컷 사용하세요~
// - protected : 나의 자손들한테만 허락
// - private : 나만 사용할거야! << class Car 내부에서만 사용가능!

// ----------------------------------------------------------------------------------------

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음.
// 진짜 어지간한 경우가 아니면 public 상속만 쓰게 된다.
// 
// - public : 공개적 상속? 부모님의 유산 설계 그대로					
//  -- ( public -> public , protected -> protected )
// 
// - protected : 보호받는 상속? 내 자손들한테만 물려줄거야		
//  -- ( public -> protected, protected -> protected )
// 
// - private : 개인적인 상속? 나(첫 자식)까지만 잘 쓰고 자손들한테는 안 물려줄거야 
// -- ( public -> private , protected -> private )

class Car
{
public:	// (멤버) 접근 지정자
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	// 키 꼽아서 시동 걸기
	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	// 일반 사용자는 사용하면 안됨!
	void DisassembleCar() { } // 차를 분해한다.
	void RunEngine() { }	// 엔진을 구동시킨다.
	void ConnectCircuit() { } // 전기선 연결

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선
};

// 상속 접근 지정자
// 99%는 public 상속 지정자를 사용한다.
class SuperCar : public Car	
{
public:
	// 원격 리모컨으로 차 시동걸기
	void PushRemoteController()
	{
		RunEngine();
	}
};

// private 상속 지정자 사용 예제
class TestCar : private SuperCar
{
	void Test()
	{
		PushPedal();
		PushRemoteController();
	}
};

// 캡슐화
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것

class BerserKer
{
public:
	int GetHp() { return _hp; }

	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 ( 강해짐 )
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserKerMode();
	}

private:
	void SetBerserKerMode()
	{
		cout << "매우 강해짐!" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	BerserKer berserker;
	// 은닉성 예제
	// 클래스 밖에서 _hp를 직접 건드리지 못하게 했으며
	// SetBerserKerMode() 또한 SetHp()에서 조건에 맞춰 호출되도록 하였음.
	berserker.SetHp(20);

	TestCar car;
	// 오류! SuperCar를 private으로 상속받았으므로 외부에서 호출 불가. 
	//car.PushRemoteController();	

	return 0;
}
