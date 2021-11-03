#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void go(vector<int>& a, int index, int cnt) //a는 배열, index는 lotto index, cnt는 들어간수
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}
	if (a.size() == index)
	{
		return;
	}
	lotto.push_back(a[index]);
	go(a, index + 1, cnt + 1);
	lotto.pop_back();
	go(a, index + 1, cnt);
}
int main()
{
	while (1)
	{
		int number;
		cin >> number;
		if (number == 0)
			break;
		vector<int> a(number);
		for (int i = 0; i < number; i++)
		{
			cin >> a[i];
		}

		go(a, 0, 0);
		cout << endl;
	}


	return 0;
}