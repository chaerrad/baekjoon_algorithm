#include <iostream>
using namespace std;
int D[100001];
int main()
{
	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		D[i] = number;
		for (int j = 1; j * j <= i; j++)
		{
			if (D[i] > D[i - j * j] + 1)
			{
				D[i] = D[i - j * j] + 1;
			}
		}
	}
	cout << D[number];
	return 0;
}