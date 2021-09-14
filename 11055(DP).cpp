#include <iostream>
using namespace std;
int N[1001];
int DP[1001];
int main()
{
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> N[i];
	}

	for (int i = 1; i <= num; i++)
	{
		DP[i] = N[i];
		for (int j = 1; j < i; j++)
		{
			if (N[i] > N[j] && DP[j] + N[i] > DP[i])
				DP[i] = DP[j] + N[i];
		}
	}
	int result = 0;
	for (int i = 1; i <= num; i++)
	{
		if (result < DP[i])
			result = DP[i];
	}

	cout << result;

	return 0;
}