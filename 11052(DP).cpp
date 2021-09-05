#include <iostream>
#include <algorithm>
using namespace std;

int N[1001];
int P[10001];
int main()
{
	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		cin >> P[i];
	}
	N[0] = 0;
	N[1] = P[1];
	for (int i = 2; i <= number; i++)
	{
		int temp = 0;
		int ans = 0;
		for (int j = 1; j <= i; j++)
		{
			temp = N[i - j] + P[j];
			if (ans <= temp)
				ans = temp;
		}
		N[i] = ans;
	}

	cout << N[number];

	return 0;
}