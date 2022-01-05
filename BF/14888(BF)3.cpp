#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int Max = -1000000000;
int Min = 1000000000;
int calc(vector<int>& number, vector<char>& Giho)
{
	int n = Giho.size();
	int now = number[0];
	for (int i = 0; i < n; i++)
	{
		if (Giho[i] == '+')
		{
			now += number[i + 1];
		}
		if (Giho[i] == '-')
		{
			now -= number[i + 1];

		}
		if (Giho[i] == '*')
		{
			now *= number[i + 1];
		}
		if (Giho[i] == '/')
		{
			now /= number[i + 1];
		}
	}
	return now;
}
int main()
{
	int n;
	cin >> n;
	vector<int> number;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		number.push_back(x);
	}
	vector<char> Giho;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Giho.push_back('+');
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Giho.push_back('-');
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Giho.push_back('*');
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Giho.push_back('/');
	}
	sort(Giho.begin(), Giho.end());
	do
	{
		int now = calc(number, Giho);
		if (now > Max)
		{
			Max = now;
		}
		if (now < Min)
		{
			Min = now;
		}
	} while (next_permutation(Giho.begin(), Giho.end()));
	cout << Max << "\n" << Min;
	return 0;

}