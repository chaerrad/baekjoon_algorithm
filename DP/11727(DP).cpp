#include <iostream>
using namespace std;
int D[1001] = { 0 };


int main()
{
	int number;
	cin >> number;

	D[1] = 1;
	D[2] = 3;

	for (int i = 3; i <= number; i++)
	{
		D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
	}
	cout << D[number] << endl;

	return 0;
}