#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
#define DIV 100999

unsigned long long map[101][101];
bool avail[201][201];
int m, n;


int main() {
	
	cin >> n >> m;

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int start_y, start_x;
		int finish_y, finish_x;
		cin >> start_x >> start_y >> finish_x >> finish_y;

		avail[start_y + finish_y][start_x + finish_x] = 1;
	}
	map[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		if (avail[2*i-1][0] == 1)
			break;
		map[i][0] = 1;
	}
	for (int j = 1; j <= n; j++) {
		if (avail[0][2*j-1] == 1)
			break;
		map[0][j] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (avail[i*2][j*2-1] == 0)
				map[i][j] += map[i][j - 1];
			if (avail[i*2-1][j*2] == 0)
				map[i][j] += map[i - 1][j];

				
		}
	}

	cout << map[m][n];

}