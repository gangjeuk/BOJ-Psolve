#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;
#define DIV 100999
int n, s, m;
bool dp[101][1001];
int main() {
	cin >> n >> s >> m;
	
	int array[1001];
	for (int i = 1; i <= n; i++) {
		cin >> array[i];
	}

	dp[0][s] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!dp[i - 1][j]) {
				continue;
			}
			if (j - array[i] >= 0) { dp[i][j - array[i]] = true; }
			if (j + array[i] <= m) { dp[i][j + array[i]] = true; }

		}
	}

	int answer = -1;
	for (int i = 0; i <= m; i++) {
		if(dp[n][i])
		 answer = max(answer, i);
	}

	cout << answer;
}