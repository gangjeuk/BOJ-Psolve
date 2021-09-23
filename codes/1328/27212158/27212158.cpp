#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <unordered_map>
#include <list>
#include <unordered_set>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;
#define MAX 1000000007

ll dp[103][103][103];
	/# °K
M

int main() {
	init();
	int n, r, l;
	cin >> n >> l >> r;

	dp[2][1][2] = 1;
	dp[2][2][1] = 1;
	dp[1][1][1] = 1;
	
	for (int building = 3; building <= n; building++) {
		dp[building][1][building] = 1;
		dp[building][building][1] = 1;

		for (int left = 1; left <= building; left++) {
			for (int right = 1; right <= building; right++) {
				ll tmp = dp[building - 1][left][right] * (building - 2);
				tmp = (tmp + dp[building - 1][left - 1][right]) % MAX;
				tmp = (tmp + dp[building - 1][left][right - 1]) % MAX;
				dp[building][left][right] = tmp;
			}
		}
	}


	cout << dp[n][l][r];

}