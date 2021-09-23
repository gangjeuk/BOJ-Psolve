#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stack>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;
#define MAX 1000000007


int n, m;
int answer = 0;
int input[21];

void func(int k,int cur_sum) {
	if (k == n) {
		if (cur_sum == m) answer++;
		return;
	}

	func(k + 1, cur_sum);
	func(k + 1, cur_sum + input[k]);
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	func(0,0);
	if (m == 0) answer--;
	cout << answer;
}