#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : auto

class Knight
{
public:
	int _hp;
};

template<typename T>
void Print(T t)
{
	cout << t << endl;
}

int main()
{
	// Modern C++의 기준 (C++11 ~)

	//int a = 3;
	//float b = 3.14f;
	//double c = 1.23;
	//Knight d = Knight();
	//const char* e = "rookiss";

	// auto
	// 컴파일 타임에 자동으로 추론해준다.
	// auto는 일종의 조커카드 -> 어디서 봤는데... template 과 비슷하다!
	// 형식 연역(type deduction) -> 컴파일러야 알아서 말이 되게 맞춰줘~
	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "rookiss";

	// 주의!
	// 기본 auto는 (const, &) 무시!!!!!!
	int& ref = a;
	const int cst = a;

	auto test1 = ref;	// int& 타입을 줬지만, int 타입으로 추론!
	auto test2 = cst;	// const int 타입을 줬지만, int 타입으로 추론!

	// ex) auto 를 사용했을 때 실수
	vector<int> v(5, 3);
	// 원했던 동작은 (int& data)였는데,
	// (auto data)가 (int data)로 추론된다!
	for (auto data : v)
		data = data * 100;

	for (auto& data : v)
		cout << data << endl;

	// 모든 타입을 auto로 쓰는 건 어떨까? -> 글쎄...
	// auto의 단점 : 가독성이 떨어질 수 있다.
	// auto의 장점 : 뻔하고 긴 타입의 타이핑은 auto 키워드로 간편하게 작성 가능
	// 결론 : 적재적소에 쓰자.

	return 0;
}