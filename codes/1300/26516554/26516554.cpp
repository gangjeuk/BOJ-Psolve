#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
#define DIV 100999

long long n, k;

long long go(long long mid)
{
	long long cnt = 0;
	for (long long i = 1; i <= n; i++)
	{
		cnt += min(n, mid / i);
	}

	return cnt;
}


int main() {
	cin >> n;
	cin >> k;

	long long left = 1;
	long long right = n * n;
	long long ans = 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (go(mid) >= k)
		{
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << endl;
}