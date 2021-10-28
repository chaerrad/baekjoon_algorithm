#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check(vector<int>& num, vector<char>& buho)
{
	for (int i = 0; i < buho.size(); i++)
	{
		if (buho[i] == '<' && num[i] > num[i + 1])
		{
			return false;
		}
		if (buho[i] == '>' && num[i] < num[i + 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int number;
	cin >> number;
	vector<char> buho(number);
	for (int i = 0; i < number; i++)
	{
		cin >> buho[i];
	}
	vector<int> small(number + 1);
	vector<int> big(number + 1);
	for (int i = 0; i <= number; i++)
	{
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(small, buho)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(big, buho)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < big.size(); i++)
	{
		cout << big[i];
	}
	cout << endl;
	for (int i = 0; i < small.size(); i++)
	{
		cout << small[i];
	}
	cout << endl;


	return 0;
}