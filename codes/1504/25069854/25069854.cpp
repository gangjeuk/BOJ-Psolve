#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 654321
using namespace std;
int v, e;
int start;
vector<pair<int, int> > adj[20001];
int visited[1000];
vector<int> dijk(int start) {
	vector<int> dist(v+1, MAX);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist,there });
				visited[there] = true;
			}
		}
	}
	return dist;
}

int main() {
	
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	int a, b;
	cin >> a >> b;
	vector<int> dist = dijk(1);
	vector<int> dist_a = dijk(a);
	vector<int> dist_b = dijk(b);
	
	int output = min(dist[a] + dist_a[b] + dist_b[v], dist[b] + dist_b[a] + dist_a[v]);
	printf("%d\n", (output >= MAX ? -1 : output));

	
}