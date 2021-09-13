#include <iostream>
using namespace std;
long long N[100001][3];
//  X X [i][0]
//  O X [i][1]
//  X O [i][2]
int main()
{
	int number;
	cin >> number;
	N[1][0] = 1;
	N[1][1] = 1;
	N[1][2] = 1;

	for (int i = 2; i <= number; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			N[i][0] = N[i - 1][1] + N[i - 1][2] + N[i - 1][0];
			N[i][0] %= 9901;
			N[i][1] = N[i - 1][0] + N[i - 1][2];
			N[i][1] %= 9901;
			N[i][2] = N[i - 1][0] + N[i - 1][1];
			N[i][2] %= 9901;
		}
	}
	long long result = (N[number][0] + N[number][1] + N[number][2]) % 9901;
	cout << result;
	return 0;
}