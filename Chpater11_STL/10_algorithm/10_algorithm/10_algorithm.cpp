#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 오늘의 주제 : 알고리즘

int main()
{
	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (데이터를 어떻게 사용할 것인가?)

	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if


	srand(static_cast<unsigned int>(time(nullptr)));

	const int Vsize = 100;
	vector<int> v;
	for (int i = 0; i < Vsize; i++)
		v.push_back(rand() % Vsize);

	// Q1) number라는 숫자가 벡터에 있는지 체크하는 기능
	// bool, 첫 등장 시 iterator
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator findIt;

		// TODO
		findIt = find(v.begin(), v.end(), number);
		if (findIt == v.end())
			cout << "못찾음" << endl;
		else
			cout << "찾음" << endl;
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
	// bool, 첫 등장 iterator
	{
		bool found = false;
		vector<int>::iterator findIt;

		// TODO
		struct CanDivideBy11
		{
			bool operator() (int n) { return (n % 11) == 0; }
		};

		// 3번째 인자에는 '함수 객체' 형태를 넣어준다.
		findIt = find_if(v.begin(), v.end(), CanDivideBy11());
		if (findIt == v.end())
			cout << "못찾음" << endl;
		else
			cout << "찾음" << endl;
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		// TODO
		struct IsOdd
		{
			bool operator()(int n) { return (n % 2) != 0; }
		};
		count = count_if(v.begin(), v.end(), IsOdd());

		// 사촌지간
		// 모든 데이터가 홀수입니까?						->	 NO
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?		-> YES
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나도 없습니까?			-> NO
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

		int a = 3;
	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		struct MultiplyBy3
		{
			// 인자가 레퍼런스 타입임을 주의하자
			void operator() (int& n) { n = n * 3; }
		};

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// 홀수인 데이터를 일괄 삭제
	{
		//for (vector<int>::iterator it = v.begin(); it != v.end();)
		//{
		//	if ((*it) % 2 != 0)
		//		v.erase(it);
		//	else
		//		++it;
		//}

		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);
		
		for (int n : v)
			cout << n << ' ';
		cout << endl;

		struct IsOdd
		{
			bool operator()(int n) { return (n % 2) != 0; }
		};

		// remove, remove_if 와 v.erase() 는 한 세트로 엮어서 생각하자.
		// remove 실행 후에는 반환값으로 주는 iterator(커서)부터 v.end() 까지의 값은 삭제한다.
		// 그렇지 않으면 쓰레기 값이 남아있게 된다.
		auto removeIt=remove_if(v.begin(), v.end(), IsOdd());
		v.erase(removeIt, v.end());

		for (int n : v)
			cout << n << ' ';
		cout << endl;
	}


	// for_each와 함수객체 만들어서 프린트하기 연습
	vector<int> test_vec;
	for (int i = 0; i < 10; i++)
		test_vec.push_back(i);

	class Print
	{
	public:
		void operator() (const int n)
		{
			cout << n << ' ';
		}
	};

	for_each(test_vec.begin(), test_vec.end(), Print());

	return 0;
}