#include <iostream>
using namespace std;
int mod = 1000000000;
int DP[101][10];
int main()
{
	int number;
	cin >> number;

	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}
	DP[1][0] = 0;
	for (int i = 2; i <= number; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 >= 0)
			{
				DP[i][j] += DP[i - 1][j - 1];
			}
			if (j + 1 < 10)
			{
				DP[i][j] += DP[i - 1][j + 1];
			}
			DP[i][j] %= 1000000000;
		}

	}
	long long result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result += DP[number][i];
	}
	result %= 1000000000;
	cout << result;

	return 0;
}