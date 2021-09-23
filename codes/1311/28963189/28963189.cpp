#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <bitset>
#include <string.h>
#include <math.h>
#define __IO_INIT ios_base::sync_with_stdio(false), cin.tie(NULL);
#define FOR(N) for(int xr = 0; xr < N; xr++)
using ll = long long;
using namespace std;



int costs[20][20];
int dp[1 << 20];

int main() {
	__IO_INIT;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> costs[i][j];
		}
	}

	fill(dp, dp + (1<<n) , 987654321);
	dp[0] = 0;

	for (int i = 0; i < (1 << n); i++) {
		int on_bit = 0;
		int num = i;
		while (num > 0) {
			on_bit += (num % 2);
			num /= 2;
		}
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j)))
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + costs[on_bit][j]);
		}
	}

	cout << dp[(1 << n) - 1];
	
}