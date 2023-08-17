#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	int start = 0; int end = 0;
	int cnt = 0;
	cin >> n;

	while (end <= n)
	{
		if (sum < n)
		{
			end++;
			sum += end;
		}
		else if (sum > n)
		{
			sum -= start;
			start++;
		}
		else 
		{
			cnt++;
			end++;
			sum += end;
		}
	}
	cout << cnt;
	return 0;
}
