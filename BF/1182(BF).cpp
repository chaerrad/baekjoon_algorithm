#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
void go(vector<int>& a, int num, int sum, int index)
{
	if (index == a.size())
	{
		if (sum == num)
		{
			ans += 1;

		}
		return;
	}
	go(a, num, sum + a[index], index + 1);
	go(a, num, sum, index + 1);
}
int main()
{
	int number;
	cin >> number;
	vector<int> a(number);
	int num;
	cin >> num;
	for (int i = 0; i < number; i++)
	{
		cin >> a[i];
	}
	go(a, num, 0, 0);
	if (num == 0)
		ans -= 1;
	cout << ans;
	return 0;
}