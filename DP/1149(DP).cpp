#include <iostream>
#include <algorithm>
using namespace std;
int DP[1001][4];
int cost[1001][4];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> cost[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		DP[i][1] = min(DP[i - 1][2], DP[i - 1][3]) + cost[i][1];
		DP[i][2] = min(DP[i - 1][1], DP[i - 1][3]) + cost[i][2];
		DP[i][3] = min(DP[i - 1][1], DP[i - 1][2]) + cost[i][3];
	}
	cout << min(DP[N][1], min(DP[N][2], DP[N][3]));
	return 0;
}