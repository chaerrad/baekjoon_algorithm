#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int sum = 0;
	string s;
	vector<int> v;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		sum += s[i];

		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end());
	if (sum % 3 == 0 && v[0] == 0)
	{
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}