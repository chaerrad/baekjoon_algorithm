#include <iostream>
using namespace std;
long DP[91][2];

int main()
{
	int number;
	cin >> number;

	DP[1][0] = 0;
	DP[1][1] = 1;

	for (int i = 2; i <= number; i++)
	{
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}
	cout << DP[number][0] + DP[number][1];
	return 0;
}