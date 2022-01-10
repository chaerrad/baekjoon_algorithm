#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int gogo[101];
int dist[101];

int main()
{
	for (int i = 1; i < 101; i++)
	{
		gogo[i] = i;
		dist[i] = -1;
	}
	int N, M;
	cin >> N >> M;
	while (N--) {
		int x, y;
		cin >> x >> y;
		gogo[x] = y;
	}
	while (M--) {
		int x, y;
		cin >> x >> y;
		gogo[x] = y;
	}
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int y = x + i;
			if (y > 100)
			{
				continue;
			}
			y = gogo[y];
			if (dist[y] == -1)
			{
				dist[y] = dist[x] + 1;
				q.push(y);
			}

		}
	}
	cout << dist[100];



	return 0;
}
