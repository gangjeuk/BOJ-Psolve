#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
#include <list>
#include <bitset>
#include <string.h>
#include <math.h>
#define __IO_INIT ios_base::sync_with_stdio(false), cin.tie(NULL);
#define FOR(N) for(int xr = 0; xr < N; xr++)
#define LLMAX 1e18
#define DIV 1000000007
#define MAX 987654321
using ll = long long;
using namespace std;

int dp[1010101][11];

int dfs(int num, int k) {
	if (k <= 0) return num;

	int& ret = dp[num][k];
	if (ret != -1)
		return ret;

	int tmp_num = num;
	vector<int> arr;
	while (tmp_num / 10) {
		arr.push_back(tmp_num % 10);
		tmp_num /= 10;
	}
	arr.push_back(tmp_num);

	for (int i = 0; i < arr.size(); i++) {
		int l_h = arr[i];
		for (int j = i + 1; j < arr.size(); j++) {
			int r_h = arr[j];
			tmp_num = num;
			if (l_h == 0 && j == arr.size() - 1)
				continue;
			tmp_num -= pow(10, i) * l_h;
			tmp_num -= pow(10, j) * r_h;
			tmp_num += pow(10, i) * r_h;
			tmp_num += pow(10, j) * l_h;

			ret = max(ret, dfs(tmp_num, k - 1));
		}
	}

	return ret;
}

int main() {
	__IO_INIT

	int n, k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << dfs(n, k);
	dp;
}