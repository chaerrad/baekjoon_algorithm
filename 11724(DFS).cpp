#include <iostream>
#include <vector>
using namespace std;
vector<int> Edges[1001];
bool check[1001];
void dfs(int v)
{
	check[v] = true;
	for (int i = 0; i < Edges[v].size(); i++)
	{
		int y = Edges[v][i];
		if (check[y] == false)
		{
			dfs(y);
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		Edges[u].push_back(v);
		Edges[v].push_back(u);
	}
	int components = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
			components += 1;

		}
	}
	cout << components;
	return 0;
}