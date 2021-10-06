#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> Edges[1001];
bool check[1001];
bool check2[1001];
void dfs(int v)
{
	check[v] = true;
	cout << v << " ";
	for (int i = 0; i < Edges[v].size(); i++)
	{
		int y = Edges[v][i];
		if (check[y] == false)
		{
			dfs(y);
		}
	}
}
void bfs(int v)
{

	queue<int> q;
	q.push(v);
	check2[v] = true;
	while (!q.empty())
	{
		int num = q.front(); q.pop();
		cout << num << " ";
		for (int i = 0; i < Edges[num].size(); i++)
		{
			int y = Edges[num][i];
			if (check2[y] == false)
			{
				check2[y] = true; q.push(y);
			}
		}
	}

}
int main()
{
	int N;
	int M;
	int V;
	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++)
	{
		int from;
		int to;
		cin >> from >> to;
		Edges[from].push_back(to);
		Edges[to].push_back(from);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(Edges[i].begin(), Edges[i].end());
	}
	dfs(V);
	cout << endl;
	bfs(V);

	return 0;
}