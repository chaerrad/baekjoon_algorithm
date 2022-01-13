#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		int num = K / v[i];
		if (num > 0)
		{
			ans += num;
			K -= (num * v[i]);
		}
	}
	cout << ans;

	return 0;
}