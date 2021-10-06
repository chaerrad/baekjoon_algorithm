#include <iostream>
using namespace std;
#define MAX 50
int map[MAX + 2][MAX + 2] = { 0 };
int number = 0;
int go_x[8] = { -1,-1,0,1,1,1,0,-1 };
int go_y[8] = { 0,1,1,1,0,-1,-1,-1 };
void go_island(int x, int y)
{
	map[x][y] = 2;
	for (int i = 0; i < 8; i++)
	{
		if (map[x + go_x[i]][y + go_y[i]] == 1)
		{
			go_island(x + go_x[i], y + go_y[i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = 1, k = 1;
	int number = 0;
	cin >> n >> k;
	while ((n != 0) && (k != 0))
	{
		int number = 0;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < MAX + 2; i++)
		{
			for (int j = 0; j < MAX + 2; j++)
			{
				if (map[i][j] == 1)
				{
					number += 1;
					go_island(i, j);

				}
			}
		}
		cout << number << '\n';
		cin >> n >> k;
	}
	return 0;
}