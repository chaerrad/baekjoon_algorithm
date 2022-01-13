#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 0;
int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
	{
		if (i == 0)
		{

		}
		else {
			a[i] = a[i - 1] + a[i];
		}

		ans += a[i];
	}
	cout << ans;
	return 0;
}