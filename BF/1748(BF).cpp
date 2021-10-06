#include <iostream>
using namespace std;
int main()
{
	int number;
	cin >> number;
	long long ans = 0;
	for (int start = 1, len = 1; start <= number; start*=10;len++)
	{
		int end = start * 10 - 1;
		if (end > number)
		{
			end = number;
		}
		ans += (long long)(end - start + 1) * len;
	}
	cout << ans << endl;
	return 0;
}