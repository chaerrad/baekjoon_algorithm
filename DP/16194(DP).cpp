#include <iostream>
using namespace std;
int N[1001];
int P[10001];

int main()
{
	int number;
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		N[i] = -1;
	}

	for (int i = 1; i <= number; i++)
	{
		cin >> P[i];
	}
	N[0] = 0;
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (N[i] == -1 || N[i] > N[i - j] + P[j])
			{
				if (N[i] == -1)
					N[i] = N[i - j] + P[j];
				else {
					N[i] = min(N[i], N[i - j] + P[j]);
				}
			}
		}
	}
	cout << N[number];

	return 0;
}