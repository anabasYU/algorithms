#include <iostream>
#include <algorithm>

using namespace std;

const int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int cut_rod(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else
	{
		int q = -1;
		for (int i = 1; i <= n; ++i)
		{
			q = max(q, p[i] + cut_rod(n - i));
		}
		return q;
	}
}

int main(int argc, char const *argv[])
{
	int r = cut_rod(40);
	cout << "The max value is : " << r << endl;

	return 0;
}