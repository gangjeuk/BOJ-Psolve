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
#include <numeric>
#include <math.h>
#include <cassert>
#define __IO_INIT ios_base::sync_with_stdio(false), cin.tie(NULL);
#define LLMAX 1e18
#define DIV 1000000007
#define MAX 987654321
using ll = long long;
using namespace std;


ll n, k;
ll dp[1<<17][101];

ll ten_mod[651];
ll num_mod[15];
vector<string> nums;


ll fact() {
	ll ret = 1;
	for (ll i = 1; i <= nums.size(); i++) {
		ret *= i;
	}
	return ret;
}

ll GCD(ll a, ll b) { return !b ? a : GCD(b, a % b); }


ll how_long_before(ll num) {
	ll l = 0;
	for (int i = 0; i < n; i++) {
		if (num & (1 << i))
			l += nums[i].size();
	}
	return l;
}

int main() {
	__IO_INIT;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string input; 
		cin >> input;
		nums.push_back(input);
	}

	cin >> k;

	dp[0][0] = 1;
	ten_mod[0] = 1;
	for (int i = 1; i < 651; i++)
		ten_mod[i] = ten_mod[i - 1] * 10 % k;

	for (int i = 0; i < nums.size(); i++) {
		num_mod[i] = 0;
		for (int j = 0; j < nums[i].size(); j++) {
			num_mod[i] += (nums[i][j] - '0') * ten_mod[nums[i].size() - j - 1] % k;
		}
		num_mod[i] %= k;
	}


	for (int i = 0; i < (1 << n); i++) {

		for (int m = 0; m < k; m++) {
			if (!dp[i][m])
				continue;
			for (int j = 0; j < n; j++) {
				int sh = (1 << j);

				if (!(i & sh)) {
					dp[i | sh][((m *  ten_mod[nums[j].size()] + num_mod[j]) % k)] += dp[i][m];


				}
			}
		}
	}

	ll f = fact();
	ll gcd = GCD(dp[(1 << n) - 1][0], f);
	num_mod;
	ten_mod;
	cout << dp[(1 << n) - 1][0] / gcd << "/" << f / gcd << endl;
}

