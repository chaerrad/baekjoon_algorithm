#include <iostream>
using namespace std;
int number[1000001];
int main()
{
	int num;
	cin >> num;
	number[1] = 0;
	for (int i = 2; i <= num; i++)
	{
		number[i] = number[i - 1] + 1;
		if (i % 2 == 0)
			number[i] = min(number[i], number[i / 2] + 1);
		if (i % 3 == 0)
			number[i] = min(number[i], number[i / 3] + 1);

	}
	cout << number[num];
	return 0;
}