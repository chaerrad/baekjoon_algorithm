#include <iostream>
using namespace std;
int Triangle[501][501];
int DP[501][501];
int main()
{
	int number;
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> Triangle[i][j];
		}
	}
	DP[1][1] = Triangle[1][1];
	for (int i = 2; i <= number; i++)
	{
		for (int j = 1; j <= number; j++)
		{
			DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + Triangle[i][j];
		}
	}
	int result = 0;
	for (int i = 1; i <= number; i++)
	{
		if (result < DP[number][i])
			result = DP[number][i];
	}
	cout << result;
	return 0;
}