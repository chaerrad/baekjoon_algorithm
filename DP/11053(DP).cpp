#include <iostream>
using namespace std;
int DP[1001];
int D[1001];
int main()
{
	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		cin >> DP[i];
	}

	for (int i = 1; i <= number; i++)
	{
		D[i] = 1;
	}

	for (int i = 2; i <= number; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (DP[j] < DP[i] && D[i] <= D[j])
			{
				D[i] = D[j] + 1;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= number; i++)
	{
		if (result < D[i])
			result = D[i];
	}
	cout << result;
	return 0;
}