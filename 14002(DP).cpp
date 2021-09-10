//역추적
//어떤값이 왜 바뀌었는지 기록해서 역추적
#include <iostream>
using namespace std;
int DP[1001];
int D[1001];
int V[1001];

void go(int num)
{
	if (V[num] == 0)
	{
		cout << DP[num] << " ";
		return;
	}
	go(V[num]);
	cout << DP[num] << " ";
}

int main()
{
	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		cin >> DP[i];
	}

	for (int i = 1; i <= number; i++)
	{
		D[i] = 1;
	}
	for (int i = 2; i <= number; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (DP[j] < DP[i] && D[i] <= D[j])
			{
				D[i] = D[j] + 1;
				V[i] = j;
			}
		}
	}

	int result = 0;
	int num = 0;
	for (int i = 1; i <= number; i++)
	{
		if (result < D[i])
		{
			result = D[i];
			num = i;
		}
	}
	cout << result << endl;
	go(num);

	return 0;
}