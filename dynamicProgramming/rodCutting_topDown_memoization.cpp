#include <iostream>
#include <algorithm>

using namespace std;

int memoized_cut_rod_aux(int p[], int n, int r[])
{

	if (r[n] >= 0)
	{
		return r[n];
	}

	int q;
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = -1;
		for (int i = 0; i < n; ++i)
		{
			if (i < 10)
			{
				q = max(q, p[i] + memoized_cut_rod_aux(p,n-i-1,r));
			}
			else
			{
				q = max(q, r[10] + memoized_cut_rod_aux(p,n-1-10,r));
			}
		}
	}
	r[n] = q;

	return q;
}

int main(int argc, char const *argv[])
{
	int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	for (int n = 1; n < 1000; ++n)
	{
		int r[n+1];
		for (int i = 0; i <= n; ++i)
			r[i] = -1;

		int value = 0;
		value = memoized_cut_rod_aux(p, n, r);
		cout << "The value is : " << value << endl;
	}

	return 0;
}