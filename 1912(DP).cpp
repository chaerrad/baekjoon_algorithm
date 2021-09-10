#include <iostream>
using namespace std;
int D[100001];
int number[100001];

int main(void)
{
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> number[i];
	}

	for (int i = 1; i <= num; i++)
	{
		D[i] = number[i];
		if (i == 1)
			continue;
		if (D[i] < D[i - 1] + number[i])
			D[i] = D[i - 1] + number[i];
	}


	int result = D[1];
	for (int i = 1; i <= num; i++)
	{
		if (result < D[i])
			result = D[i];
	}
	cout << result;
	return 0;
}