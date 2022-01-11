#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
bool number[10000];
char how[10000];
int from[10000];
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		memset(number, false, sizeof(number));
		memset(how, '0', sizeof(number));
		memset(from, -1, sizeof(number));
		int start, finish;
		cin >> start >> finish;
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			int next1 = (x * 2) % 10000;
			int next2 = x - 1;
			if (next2 == -1)
			{
				next2 = 9999;
			}
			int next3 = ((x % 1000) * 10) + (x / 1000);
			int next4 = (x / 10) + ((x % 10) * 1000);

			if (number[next1] == false)
			{
				number[next1] = true;
				from[next1] = x;
				how[next1] = 'D';
				q.push(next1);
			}
			if (number[next2] == false)
			{
				number[next2] = true;
				from[next2] = x;
				how[next2] = 'S';
				q.push(next2);
			}
			if (number[next3] == false)
			{
				number[next3] = true;
				from[next3] = x;
				how[next3] = 'L';
				q.push(next3);
			}
			if (number[next4] == false)
			{
				number[next4] = true;
				from[next4] = x;
				how[next4] = 'R';
				q.push(next4);
			}

		}
		string ans = "";

		while (start != finish)
		{
			ans += how[finish];
			finish = from[finish];
		}
		reverse(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
		}


		cout << endl;
	}

	return 0;
}