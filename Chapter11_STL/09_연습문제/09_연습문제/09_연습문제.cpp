#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : 연습 문제

int main()
{
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
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			if ((*it) == number)
			{
				found = true;
				findIt = it;

				cout << found << endl;
				cout << (*findIt) << endl;

				break;
			}
		}
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
	// bool, 첫 등장 iterator
	{
		bool found = false;
		vector<int>::iterator it;

		// TODO
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			if ((*iter) % 11 == 0)
			{
				found = true;
				it = iter;
				break;
			}
		}
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		// TODO
		for (int i = 0; i < Vsize; i++)
		{
			if (v[i] % 2 != 0)
			{
				cout << v[i] << endl;
				count++;
			}
		}
	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		for (int i = 0; i < Vsize; i++)
			v[i] *= 3;
	}

	return 0;
}