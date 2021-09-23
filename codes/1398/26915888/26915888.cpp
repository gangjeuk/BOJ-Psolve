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
#include <unordered_set>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

int dp[101];
int main() {
	init();
	for (int i = 1; i < 100; i++) {
		dp[i] = i;
		int arr[3] = { 1,10,25 };
		for (int j : arr) {
			if (i - j >= 0)
				dp[i] = min(dp[i], dp[i - j] + 1);
		}
	}
	

	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		ll input;
		cin >> input;
		ll answer = 0;
		while (input / 100 != 0) {
			answer += dp[input % 100];
			input /= 100;
		}
		answer += dp[input];

		cout << answer << "\n";

	}

}

