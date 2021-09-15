#include <iostream>
#include <algorithm>
using namespace std;
int Tiny[10];

int main()
{
	int sum = 0;
	for (int i = 1; i < 10; i++)
	{
		cin >> Tiny[i];
		sum += Tiny[i];
	}
	sort(Tiny + 1, Tiny + 10);
	for (int i = 1; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (sum - Tiny[i] - Tiny[j] == 100)
			{
				for (int k = 1; k < 10; k++)
				{
					if (i == k || j == k)
						continue;
					cout << Tiny[k] << "\n";
				}
				return 0;
			}
		}
	}

	return 0;
}