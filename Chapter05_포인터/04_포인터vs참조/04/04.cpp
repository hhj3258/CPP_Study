#include <iostream>
using namespace std;

// 오늘의 주제 : 참조
// 오늘의 주제 : 포인터 vs 참조

struct StatInfo
{
	int hp;  
	int attack;
	int defence;
};

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사됨 -> 너무 크다...
// - (주소 전달) StatInfo* 는 8바이트 -> StatInfo 가 얼마나 크던 상관 없이 8바이트만 전달
// - (참조 전달) StatInfo& 는 8바이트

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 진퉁을 건드리는!
// 일석이조의 방식!!

StatInfo globalInfo;

void PrintInfoByPtr(const StatInfo* const info)
{
	if (info == nullptr) 
		return;

	cout << "-----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-----------------------" << endl;

	// const를 * 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)을 바꿀 수 없음
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!
	
	// const를 * 이전에 붙인다면?
	// const StatInfo* info
	// info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀 수 없음

	// info[ 주소값 ]     주소값[ 데이터 ]
	// info = &globalInfo;
	// info->hp = 10000;
}

// const를 사용해서 애매한 부분을 없앨 수 있다.
// 원본 데이터 수정 막기
void PrintInfoByRef(const StatInfo& info) 
{
	cout << "-----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-----------------------" << endl;

	// 신입이 왔다
	// info.hp = 10000;
}

#define OUT

void ChangeInfo(OUT StatInfo& info) 
{
	info.hp = 1000;
}

int main()
{
	// 4바이트 정수형 바구니를 사용할거야.
	// 앞으로 그 바구니 이름을 number라고 할게
	// 그러니까 number에서 뭘 꺼내거나, number에 뭘 넣는다고 하면
	// 찰떡같이 알아듣고 해당 주소에 1을 넣어주면 된다!
	int number = 1;

	// <참조 타입 reference>
	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 실제로 실행해보면 포인터랑 100% 똑같다.
	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름(별명)을 지어줄게
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(진퉁)에 그 값을 꺼내거나 넣으면 돼!
	reference = 3;
	
	// 그런데 귀찮게 또 다른 이름을 짓는 이유는?
	// 그냥 number = 3이라고 해도 똑같은데...
	// 참조 전달 때문!
	// 값 전달보다, 참조(주소) 전달을 하는게 더 효율적이다.
	// 주소 전달보다 참조 전달이 더 쓰는게 편리하다. 값 전달 방식과 문법이 비슷하니까.
	
	StatInfo info;
	PrintInfo(info);

	// 포인터 vs 참조 세기의 대결
	// 성능 : 똑같음!
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데.
	// 참조는 자연스럽게 모르고 지나칠 수도 있음!
	// ex) 마음대로 고친다면?
	// const를 사용해서 이런 마음대로 고치는 부분 개선 가능!

	// 참고로 포인터도 const를 사용 가능.
	// * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 (별칭?)
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤~ 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음
	// 포인터에서 '없다'는 의미로 ? -> nullptr
	// 참조 타입은 이런 nullptr

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference2 = info;
	PrintInfoByRef(reference2);

	// 그래서 결론은?
	// 사실 Team By Team... 정해진 답은 없다
	// ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	// Rookiss 선호 스타일
	// - 없는 경우도 고려해야 한다면 pointer (null 체크 필수)
	// - 바뀌지 않고 읽는 용도(readonly)만 사용하면 const ref&
	// - 그 외 일반적으로 ref (명시적으로 호출할 때 OUT을 붙인다)
	// -- 단, 다른 사람이 pointer를 만들어 놓은걸 이어서 만든다면, 계속 pointer (섞어 사용하진 않는다)
	ChangeInfo(OUT info);

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer[ 주소(&info) ]     ref, info[ 데이터 ]
	PrintInfoByRef(*pointer);

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer[ 주소 ]         reference, info[ 데이터 ]
	PrintInfoByPtr(&reference2);

	return 0;
}