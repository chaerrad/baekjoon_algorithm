#include <iostream>
#include <vector>
int sum[20 * 100000 + 1];
using namespace std;
void solve(vector<int>& S, int index, int num)
{
	sum[num] = 1;
	if (S.size() == index)
	{
		return;
	}
	solve(S, index + 1, num + S[index]);
	solve(S, index + 1, num);
}
int main()
{
	int N;
	cin >> N;
	vector<int> S(N);
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	solve(S, 0, 0);
	for (int i = 1; i < 20 * 100000 + 1; i++)
	{
		if (sum[i] != 1)
		{
			cout << i;
			break;
		}
	}
	return 0;
}