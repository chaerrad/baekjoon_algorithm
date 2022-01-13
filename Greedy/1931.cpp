#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Meeting {
	int begin, end;
};
bool cmp(struct Meeting& u, struct Meeting& v) //정렬기준
{
	if (u.end == v.end) {
		return u.begin < v.begin;
	}
	else {
		return u.end < v.end;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<Meeting> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].begin >> a[i].end;
	}
	sort(a.begin(), a.end(), cmp);
	int now = 0;
	int ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (now <= a[i].begin) {
			now = a[i].end;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}