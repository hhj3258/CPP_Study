#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : vector

int main()
{
	// STL(Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// 첫번째 컨테이너 vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 동적 배열
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용할 수 있는 것인가?
	// 1) 여유분을 두고 메모리를 할당한다.
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.
	int* arr = new int[100];
	delete[] arr;	// 꽉 차면 메모리 날리고
	// TODO: 기존 데이터 복사 후 붙여넣기
	arr = new int[1000];	// 더 큰 메모리를 새롭게 잡는다.

	// Q1) 여유분은 얼만큼이 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존의 데이터를 어떻게 처리할까?

	vector<int> v;
	// size = 실제 사용 데이터 개수
	v.resize(100);	// size(데이터 개수)를 100개 넣을 공간 할당
	// capacity = 여유분을 포함한 용량 개수
	v.reserve(200); // capacity(여유분 포함 총 크기)를 200개로 할당

	// 메모리가 꽉 차면 1.5배 정도 크기를 증설한 메모리에 기존 데이터를 복사한다.
	// (복사 비용이 크기 때문에 여유를 가지고 메모리를 증설하는 것)
	int cap = v.capacity();
	for (int i = 0; i < 1000; i++)
	{
		if (v.capacity() > cap)
		{
			cout << v.size() << " " << v.capacity() << endl;
			cap = v.capacity();
		}

		v.push_back(100);
	}

	v.clear();
	cout << "<Clear>" << endl;
	cout << v.size() << " " << v.capacity() << endl;
	// capacity 날리는 팁 : 임시 벡터와 v 를 swap 한다.
	// v는 임시 벡터 값을 가지고 v값을 가진 임시 벡터는 다음 줄에서 소멸한다.
	vector<int>().swap(v);
	cout << v.size() << " " << v.capacity() << endl;


	return 0;
}