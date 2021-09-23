#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#define MAX 987654321
using namespace std;


#define black 1
#define white 0
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> map_anw1(8, vector<bool>(8, 0));
	vector<vector<bool>> map_anw2(8, vector<bool>(8, 0));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((j+i) % 2 == 1) {
				map_anw1[i][j] = black;
			}
			else {
				map_anw1[i][j] = white;

			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((j+i) % 2 == 1) {
				map_anw2[i][j] = white;
			}
			else {
				map_anw2[i][j] = black;

			}
		}
	}

	vector<vector<bool>> map(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char input;
			cin >> input;
			if (input == 'B') {
				map[i][j] = black;
			}
			else {
				map[i][j] = white;
			}
		}
	}
	
	int min_output= MAX;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int output1 = 0, output2 = 0;
			
			for (int y_start = i; y_start < i + 8; y_start++) {
				for (int x_start = j; x_start < j + 8; x_start++) {
					if (map[y_start][x_start] != map_anw1[(y_start - i)][(x_start - j)]) {
						output1++;
					}
					if (map[y_start][x_start] != map_anw2[(y_start - i)][(x_start - j)]) {
						output2++;
					}
				}
			}
			min_output = min(min_output,min(output2, output1));
		}
	}
	cout << min_output;
}