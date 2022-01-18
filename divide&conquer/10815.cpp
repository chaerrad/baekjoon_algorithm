#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool binary_search(vector<int>& v, int s)
{
	int start = 0;
	int end = v.size() - 1;

	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (v[middle] == s)
		{
			return true;
		}
		else if (v[middle] < s)
		{
			start = middle + 1;
		}
		else if (v[middle] > s) {
			end = middle - 1;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++)
	{
		int s;
		cin >> s;
		bool gogo = binary_search(v, s);
		if (gogo)
		{
			a[i] = 1;
		}
		else {
			a[i] = 0;
		}

	}
	for (int i = 0; i < m; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}