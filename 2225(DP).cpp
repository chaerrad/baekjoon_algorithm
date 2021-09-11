#include <iostream>
#define Mod 1000000000
using namespace std;
long long DP[201][201];

int main()
{
	int N;
	int K;
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
	{
		DP[1][i] = 1;
	}
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				DP[i][j] += DP[i - 1][j - l];
			}
			DP[i][j] = DP[i][j] % Mod;
		}
	}

	cout << DP[K][N];
	return 0;
}