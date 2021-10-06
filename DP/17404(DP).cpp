// »¡ -> ......->ÃÊ
// »¡ -> ......->ÆÄ
// ÃÊ -> ......->»¡
// ÃÊ -> ......->ÆÄ
// ÆÄ -> ......->ÃÊ
// ÆÄ -> ......->»¡

#include <iostream>
#include <algorithm>
using namespace std;
int house[1001][4];
int DP[1001][4];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> house[i][j];
		}
	}
	int ans = 1000 * 1000 + 1;
	for (int k = 1; k <= 3; k++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (j == k)
			{
				DP[1][j] = house[1][j];
			}
			else {
				DP[1][j] = 1000 * 1000 + 1;
			}
		}
		for (int i = 2; i <= num; i++)
		{
			DP[i][1] = min(DP[i - 1][2], DP[i - 1][3]) + house[i][1];
			DP[i][2] = min(DP[i - 1][1], DP[i - 1][3]) + house[i][2];
			DP[i][3] = min(DP[i - 1][2], DP[i - 1][1]) + house[i][3];
		}
		for (int j = 1; j <= 3; j++)
		{
			if (j == k)
				continue;
			ans = min(ans, DP[num][j]);
		}
	}


	cout << ans;
	return 0;
}