#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
void solve(vector<int>& number, int sum, int index, int cnt)
{
	if (number.size() == index && sum == cnt)//정답인경우
	{
		ans += 1;
		return;
	}
	if (number.size() == index && sum != cnt) //불가능한경우
		return;

	solve(number, sum + number[index], index + 1, cnt);

	solve(number, sum, index + 1, cnt);
}
int main()
{
	int N;
	int S;
	cin >> N;
	cin >> S;

	vector<int> number;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		number.push_back(x);
	}
	solve(number, 0, 0, S);
	if (S == 0)
		ans -= 1;
	cout << ans;
	return 0;
}