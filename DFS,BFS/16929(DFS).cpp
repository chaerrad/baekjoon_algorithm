#include <iostream>
using namespace std;
int N, M;
char cycle[51][51];
int go_x[4] = { 0,-1,0,1 };
int go_y[4] = { -1,0,1,0 };

bool dfs(int num1, int num2, int cnt, char color, bool(*check)[51], int(*length)[51]) //num1�� num2�� ��ǥ, cnt�� ���� ������, color�� ��
{
	if (check[num1][num2])
	{
		if (cnt - length[num1][num2] >= 4) //cnt���� length�� �����ν� 4�̻�Ǵ��� check
			return true;
		else {
			return false;
		}
	}
	check[num1][num2] = true;
	length[num1][num2] = cnt;
	for (int i = 0; i < 4; i++)
	{
		if (num1 + go_x[i] > 0 && num1 + go_x[i] < N + 1 && num2 + go_y[i]>0 && num2 + go_y[i] < M + 1 && color == cycle[num1 + go_x[i]][num2 + go_y[i]])
		{
			if (dfs(num1 + go_x[i], num2 + go_y[i], cnt + 1, color, check, length))
				return true;
		}
	}
	return false;
}
int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> cycle[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			bool check[51][51] = { false }; //�湮����
			int length[51][51] = { 0 }; //���������� �Ÿ� ����
			if (dfs(i, j, 0, cycle[i][j], check, length))
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}