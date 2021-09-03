#include <iostream>
using namespace std;
int DP[12];

int go(int num)
{
	if (DP[num])
		return DP[num];
	return go(num - 3) + go(num - 2) + go(num - 1);
}
int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		int number;
		cin >> number;
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;
		if (number > 3)
		{
			cout << go(number) << endl;
		}
		else {
			cout << DP[number] << endl;
		}
	}
	return 0;
}