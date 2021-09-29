#include <iostream>
using namespace std;

int ans = 0;
int T[16];
int P[16];
int day;

void go(int d, int sum)
{
	if (d - 1 == day)
	{
		if (sum > ans)
			ans = sum;
		return;
	}
	if (d - 1 > day)
	{
		return;
	}
	go(d + 1, sum);
	go(d + T[d], sum + P[d]);
}

int main()
{
	cin >> day;

	for (int i = 1; i <= day; i++)
	{
		cin >> T[i];
		cin >> P[i];
	}

	go(1, 0);
	cout << ans << endl;
	return 0;
}