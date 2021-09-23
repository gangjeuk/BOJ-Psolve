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
#include <list>
#include <unordered_set>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

int n;


vector<pair<int,int>> graph[100001];
bool visited[100001];
int farest_node = 0;
int dia = 0;

void dfs(int root, int dist) {
	visited[root] = true;

	for (int i = 0; i < graph[root].size(); i++) {
		int child = graph[root][i].first;
		int next_dist = graph[root][i].second;
		if (visited[child] == false) {
			if (dist + next_dist > dia) {
				farest_node = child;
				dia = dist + next_dist;
			}
			dfs(child, dist + next_dist);
		}

	}

}

int main() {
	init();
	cin >> n;



	for (int i = 1; i <= n; i++) {
		int root;
		cin >> root;
		int input;
		while (true) {
			cin >> input;
			if (input == -1) {
				break;
			}
			
			int node = input;
			cin >> input;
			int cost = input;
			graph[root].push_back({ node,cost });
	
		}
	}
	
	
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(farest_node, 0);

	cout << dia;

}