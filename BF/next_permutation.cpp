bool next_permutaion(int* a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false; //마지막 순열
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j)
	{
		swap(a[i],a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}