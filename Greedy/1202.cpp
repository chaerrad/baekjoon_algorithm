#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct jewel {
	int m, v;
};
bool compare(jewel u, jewel v)
{
	return u.v > v.v;
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<jewel> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].m >> a[i].v;
	}
	sort(a.begin(), a.end(), compare);
	multiset<int> s;
	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		s.insert(t);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto it = s.lower_bound(a[i].m);
		if (it != s.end())
		{
			ans += a[i].v;
			s.erase(it);
		}
	}
	cout << ans;
	return 0;
}