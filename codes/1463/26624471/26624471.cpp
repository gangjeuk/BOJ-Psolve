#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <memory.h>

using namespace std;
#define DIV 1000000007
typedef long long ll;




int dp[1000001];
int main() {
	int n;
	cin >> n;
	fill(dp, dp + 1000001, DIV);
	dp[1] = 0;
	dp[3] = 1;// *3
	dp[2] = 1;// *2 || +1
	for (int i = 4; i <= n; i++) {
		int now = i;
		if (now % 3 == 0) {
			dp[now] = min(dp[now], dp[now / 3] + 1);
		}
		if (now % 2 == 0) {
			dp[now] = min(dp[now], dp[now / 2] + 1);
		}
		dp[now] = min(dp[now], dp[now - 1] + 1);
	}
	cout << dp[n];
}