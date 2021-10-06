#include <iostream>
using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int e, s, m;//나의 입력
	e = 1;
	s = 1;
	m = 1;
	int year = 1;
	while (1)
	{

		if (e == E && s == S && m == M)
		{
			cout << year;
			return 0;
		}
		e += 1;
		s += 1;
		m += 1;
		if (e == 16)
		{
			e = 1;
		}
		if (s == 29)
		{
			s = 1;
		}
		if (m == 20)
		{
			m = 1;
		}
		year++;
	}

	return 0;
}