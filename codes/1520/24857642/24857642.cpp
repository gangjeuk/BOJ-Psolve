#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;



int H, W;
int map[500][500];
int visited_cases[500][500];
int road(int y, int x) {
	if (y == H - 1 && x == W - 1) {
		return 1;
	}
	if (visited_cases[y][x] != -1) return visited_cases[y][x];

	visited_cases[y][x] = 0;
	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,1,-1 };

	int temp = 0;

	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx  = dx[i] + x;
		if (ny >= 0 && nx >= 0 && ny < H && nx < W) {
			if (map[y][x] > map[ny][nx]) {
				visited_cases[y][x] += road(ny, nx);
			}
			
			
			
			
		}
	}
	return visited_cases[y][x];
	


}

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			visited_cases[i][j] = -1;
		}
	}	


	cout << road(0, 0);
}