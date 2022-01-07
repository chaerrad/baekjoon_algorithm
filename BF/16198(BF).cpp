#include <iostream>
#include <vector>
using namespace std;
int go(vector<int>& a, int sum)
{
	if (a.size() == 2) //첫번째와 마지막번째만 남으면 끝
	{
		return sum;
	}
	int ans = -1;
	for (int i = 1; i < a.size() - 1; i++) //지울꺼를 하나 선택
	{
		vector<int>b(a);
		b.erase(b.begin() + i);
		int temp = go(b, sum + a[i - 1] * a[i + 1]);
		if (ans == -1 || temp > ans)
		{
			ans = temp;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << go(a, 0);
	return 0;
}