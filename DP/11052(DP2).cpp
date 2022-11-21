#include <iostream>
#include <algorithm>
using namespace std;

int N[1001] = { 0 };
int P[10001];
int main()
{
	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		cin >> P[i];
	}
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			N[i] = max(N[i], N[i - j] + P[j]);
		}
	}

	cout << N[number];
	return 0;
}