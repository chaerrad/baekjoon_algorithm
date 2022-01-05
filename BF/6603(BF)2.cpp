#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> lotto;
void solve(vector<int>& number, int index, int cnt) // number�� ����, index�� ����, cnt�� ����
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << "\n";
	}
	if (index == number.size()) //�Ұ���
		return;
	lotto.push_back(number[index]);
	solve(number, index + 1, cnt + 1);
	lotto.pop_back();    //�������....
	solve(number, index + 1, cnt);
}
int main()
{
	int n = 100;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> number(n);
		for (int i = 0; i < n; i++)
		{
			cin >> number[i];
		}
		solve(number, 0, 0);
		cout << "\n";
	}

	return 0;
}