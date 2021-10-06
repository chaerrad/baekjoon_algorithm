#include <iostream>
using namespace std;
long long N[1001][10];

int main()
{
	int number;
	long long result = 0;
	cin >> number;

	for (int i = 0; i <= 9; i++)
	{
		N[1][i] = 1;
	}

	for (int i = 2; i <= number; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				N[i][j] += N[i - 1][k];
				N[i][j] %= 10007;
			}
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		result += N[number][i];
	}
	result %= 10007;
	cout << result;
	return 0;
}