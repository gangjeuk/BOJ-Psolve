#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;
int N,M,K;

int visited[50][50];
int map[50][50];
vector<int > dong;

void find_dong(){


	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	int dong_num = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 1 && visited[y][x] == 0) {
				queue<pair<int, int> > q;
				q.push({ y,x });
				visited[y][x] = 1;
				int dong_size = 1;
				dong.push_back(dong_size);
				

				while (!q.empty()) {
					int temp_y = q.front().first;
					int temp_x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = temp_x + dx[i];
						int ny = temp_y + dy[i];
						if (ny >= 0 && nx >= 0 && ny < N && nx < M && visited[ny][nx] == 0 && map[ny][nx] == 1) {
							q.push({ ny,nx });
							visited[ny][nx] = 1;
							dong[dong_num]++;
							
						}

					}

				}

				dong_num++;
			}


		}
	}

}

int main() {
	int test_case = 0;
	vector<int> output;
	 cin >> test_case;
	 for (int j = 0; j < test_case; j++) {
		 cin >> M >> N >> K;
		 for (int i = 0; i < K; i++) {
			 int y, x;
			 cin >> x >> y;
			 map[y][x] = 1;
		 }

		 find_dong();

		 output.push_back(dong.size());
		 dong.clear();
		 memset(map, 0,sizeof(map));
		 memset(visited,0, sizeof(visited));
		 //cout << visited[0] << "\n";

	 }

	 for (int j = 0; j < test_case; j++) {
		 cout << output[j] << "\n";
	 }

}