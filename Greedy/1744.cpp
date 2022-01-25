#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
vector<int> Plus;
vector<int> Minus;
int zero = 0;
int one = 0;
bool big_first(int v, int u)
{
	return v > u;
}
bool small_first(int v, int u)
{
	return v < u;
}
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			zero += 1;
		}
		else if (x == 1) {
			one += 1;
		}
		else if (x > 1)
		{
			Plus.push_back(x);
		}
		else if (x < 0)
		{
			Minus.push_back(x);
		}
	}
	sort(Plus.begin(), Plus.end(), big_first);
	sort(Minus.begin(), Minus.end(), small_first);
	if (Plus.size() % 2 == 1)
	{
		Plus.push_back(1);
	}
	if (Minus.size() % 2 == 1)
	{
		Minus.push_back(zero > 0 ? 0 : 1);
	}
	int ans = 0;
	ans += one;
	for (int i = 0; i < Plus.size(); i += 2)
	{
		ans += Plus[i] * Plus[i + 1];
	}
	for (int i = 0; i < Minus.size(); i += 2)
	{
		ans += Minus[i] * Minus[i + 1];
	}
	cout << ans << "\n";

	return 0;
}