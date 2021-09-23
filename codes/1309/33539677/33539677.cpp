#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <functional>
#include <future>
#include <math.h>
#include <cassert>
#include <thread>
#include <iostream>
#define LLMAX 1e18
#define DIV 1000000007
#define MAX 987654321
using ll = long long;
using namespace std;


int n;

int dp[101010];

int main() {
	cin >> n;
	
	dp[1] = 3;
	dp[2] = 7;
	dp[3] = 17;
	dp[4] = 41;


	for (int i = 5; i < 101010; i++)
	{
		dp[i] = dp[i - 1] * 2 + dp[i - 2];
		dp[i] %= 9901;
	}

	cout << dp[n];


}