#include <iostream>
#include <queue>
using namespace std;

int go_x[8] = { -1,-2,-2,-1,1,2,2,1 };
int go_y[8] = { -2,-1,1,2,2,1,-1,-2 };
int end_x, end_y;
int chess;
void bfs(int start_x, int start_y, int(*pan)[301], bool(*visited)[301])
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			if (xx + go_x[i] > -1 && xx + go_x[i]<chess && yy + go_y[i]>-1 && yy + go_y[i] < chess && !visited[xx + go_x[i]][yy + go_y[i]])
			{
				visited[xx + go_x[i]][yy + go_y[i]] = true;
				q.push(make_pair(xx + go_x[i], yy + go_y[i]));
				pan[xx + go_x[i]][yy + go_y[i]] = pan[xx][yy] + 1;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		bool visited[301][301] = { false };
		int pan[301][301] = { 0 };

		cin >> chess;
		int start_x, start_y;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		if (end_x == start_x && end_y == start_y)
		{

		}
		else
		{
			bfs(start_x, start_y, pan, visited);
		}
		cout << pan[end_x][end_y] << endl;


	}

	return 0;
}