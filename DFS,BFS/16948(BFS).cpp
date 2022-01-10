#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
int chess[200][200] = { -1 };
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			chess[i][j] = 0;
		}
	}

	int start_x, start_y;
	int finish_x, finish_y;
	cin >> start_x >> start_y >> finish_x >> finish_y;

	queue<int> q1;
	queue<int> q2;

	q1.push(start_x);
	q2.push(start_y);
	while (!q1.empty())
	{
		int x = q1.front(); q1.pop();
		int y = q2.front(); q2.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)//안되는경우
			{
				continue;
			}
			if (chess[nx][ny] == 0)
			{
				chess[nx][ny] = chess[x][y] + 1;
				q1.push(nx);
				q2.push(ny);
			}

		}

	}
	if (chess[finish_x][finish_y] == 0)
	{
		cout << -1;
	}
	else
	{
		cout << chess[finish_x][finish_y];
	}

	return 0;
}