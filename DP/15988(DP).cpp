#include <iostream>
using namespace std;
long long DP[1000001];
int main()
{
	int n;
	cin >> n;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	while (n--)
	{
		int k;
		cin >> k;
		for (int i = 4; i <= k; i++)
		{
			DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
			DP[i] = DP[i] % 1000000009;
		}
		cout << DP[k] << endl;
	}

	return 0;
}