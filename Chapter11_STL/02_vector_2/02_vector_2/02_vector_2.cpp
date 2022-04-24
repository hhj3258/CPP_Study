#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : vector
// - 중간 삽입/삭제
// - 처음/끝 삽입/삭제
// - 임의 접근

int main()
{
	// 반복자(Iterator) : 포인터와 유사한 개념. 
	// 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);
	v.reserve(1000);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	vector<int>::iterator it;
	int* ptr;

	// begin() 은 iterator를 반환한다.
	it = v.begin();
	ptr = &v[0];

	// iterator는 포인터가 아닌데 어떻게 포인터처럼 쓰는 걸까?
	// '연산자 오버로딩'을 통해 포인터처럼 쓸 수 있게 만들어 놓은 것
	// sizeof(it) = 12 byte
	// 포인터가 가지는 정보를 포함해서 컨테이너의 정보도 들고 있다.
	cout << (*it) << endl;
	cout << (*ptr) << endl;

	vector<int>::iterator itBegin = v.begin();
	// end() 는 마지막 원소 다음 주소를 가리킨다.(쓰레기 값)
	vector<int>::iterator itEnd = v.end();

	// iterator를 이용한 탐색
	// 이거... 더 복잡해보이는데?
	// - 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될 수도 있음
	// - iterator는 vector뿐만 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	// - vector 한정으로는 윗 버전이 더 많이 쓰인다.(별 차이 없음)
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << (*iter) << " ";
	cout << endl;

	// iterator와 비슷하게 포인터로 만들어보자면...
	int* ptrBegin = &v[0];	// v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10;	// v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
		cout << (*ptr) << " ";
	cout << endl;

	vector<int>::const_iterator cit1 = v.cbegin();
	// cit1 = v.end();		// OK!, 포인터를 바꾼다
	// *cit1 = 100;			// ERROR!, 값을 바꿀 수 없다.

	// vector = 동적 배열 = 동적으로 커지는 배열 = 결국 배열은 배열임
	// 원소가 하나의 메모리 블록에 연속되게 저장된다!!

#pragma region 중간 삽입/삭제 (비효율적)
	// [0] [1] [2] [3] [4] [ ] [ ]
	// 중간에 5를 넣는다 -> [0] [1] [5] [2] [3] [4] [ ]
	// 중간 원소를 삭제한다 -> [0] [1] [2] [3] [4] [ ]
	// 삽입/삭제 하려는 인덱스 뒤의 원소들을 모두 복사 및 이동해줘야 한다.
	// 
	// insert는 뭔가 쓰기 어렵게 되어있다. -> 웬만하면 쓰지 말라는 힌트
	vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);	// 하나만 삭제
	// 범위 삭제 : 마지막 값은 포함하지 않는다!
	vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);


	// ex) 쭉~ 스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다
	for (vector<int>::iterator iter = v.begin(); iter != v.end();)
	{
		int data = *iter;
		if (data == 3)
		{
			// erase하고 새로 iterator를 받아주는 것이 포인트
			// erase만 하면 iterator도 사라진다. -> Crash
			iter = v.erase(iter);
		}
		else
		{
			// 여기서 iterator를 증가시켜준다.
			// erase 후에 검사하지 않은 원소를 건너뛰게 되는 것 방지
			++iter;
		}
	}
#pragma endregion

#pragma region 처음 삽입/삭제
	// 중간 삽입/삭제와 똑같다. (비효율적)
	// push_back()은 있어도 push_front()는 없다.

	// <임의 접근(Random Access)>
	// 벡터의 원소들이 하나의 메모리 블록에 연속되게 저장되어 있으므로 가능
	// 3번째 데이터는 어디 있습니까?
	v[2] = 3;
#pragma endregion




	return 0;
}