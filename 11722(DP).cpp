#include <iostream>
using namespace std;
int N[1001];
int D[1001];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> N[i];
	}

	for (int i = num; i > 0; i--)
	{
		D[i] = 1;
		for (int j = num; j > i; j--)
		{
			if (N[i] > N[j] && D[i] <= D[j])
				D[i] = D[j] + 1;
		}
	}
	int result = 0;
	for (int i = 1; i <= num; i++)
	{
		if (result < D[i])
			result = D[i];
	}

	cout << result;

	return 0;
}