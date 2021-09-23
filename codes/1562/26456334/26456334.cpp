#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
#define DIV 1000000000

int dp[101][10][1<<10];

int n;

int stairs(int edge, int length, int used_num) {

	if (length == n)
		return used_num == (1 << 10) - 1 ? 1 : 0;

	int& result = dp[length][edge][used_num];

	if (result != -1)
		return result;

	result = 0;
	if (edge - 1 >= 0)
		result += stairs(edge - 1, length + 1, used_num | 1 << (edge - 1));
	if (edge + 1 < 10)
		result += stairs(edge + 1, length + 1, used_num | 1 << (edge + 1));

	result %= DIV;

	return result;

}




int main() {
	cin >> n;

	int result = 0;

	for (int i = 1; i < 10; i++) {
		memset(dp, -1, sizeof(dp));
		result += stairs(i,1,1 << i) ;
		result %= DIV;
	}

	cout << result;
}