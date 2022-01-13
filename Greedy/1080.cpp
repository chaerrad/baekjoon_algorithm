#include <iostream>
#include <cstdio>
#include <vector>
int maze1[51][51];
int maze2[51][51];
int ans = 0;
int N, M;
using namespace std;
void change(int x, int y)
{
	if (x + 2 > N || y + 2 > M)
	{
		return;
	}
	for (int i = x; i <= x + 2; i++)
	{
		for (int j = y; j <= y + 2; j++)
		{
			if (maze1[i][j] == 0)
			{
				maze1[i][j] = 1;
			}
			else {
				maze1[i][j] = 0;
			}

		}
	}
}
int main()
{

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &maze1[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &maze2[i][j]);
		}
	}

	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 2; j++)
		{
			if (maze1[i][j] != maze2[i][j])
			{
				change(i, j);
				ans += 1;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (maze1[i][j] != maze2[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;

	return 0;
}