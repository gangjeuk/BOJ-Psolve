// 코드 더러워유
#define algo_init ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <math.h>
#include <set>

using namespace std;

vector<int> graph[101010];
int weights[101010];
int visited[101010];
int parents[101010][22];
int ranks[101010];

typedef struct Node {
	Node* left;
	Node* right;
	int vertex;
	Node() { left = right = NULL; vertex = 0; }
}Node;

vector<Node*> root(101010);

void make_orig_tree(Node* node, int s, int e)
{
	if (s == e) {
		node->vertex = 0; return;
	}
	int m = (s+e)/2;
	node->left = new Node(); node->right = new Node();
	make_orig_tree(node->left, s, m); make_orig_tree(node->right, m + 1, e);
	node->vertex = 0;
	return;
}

void add_dst_tree(Node* prv, Node* here, int s, int e, int added) {
	int tmp = prv->vertex;
	tmp += 1;
	if (s == e) {

		here->vertex = tmp;
		return;
	}

	int m = (s+e)/2;
	if (added <= m) {
		here->vertex = tmp;
		here->left = new Node(); here->right = prv->right;
		add_dst_tree(prv->left, here->left, s, m, added);
	}
	else {
		here->vertex = tmp;
		here->right = new Node(); here->left = prv->left;
		add_dst_tree(prv->right, here->right, m + 1, e, added);
	}
	return;
}


void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int child = graph[start][i];
		if (visited[child] == true)
			continue;
		parents[child][0] = start;
		ranks[child] = ranks[start] + 1;
		dfs(child);
	}
	return;
}

int find_lca(int node1, int node2) {
	// 오른쪽 낮음
	if (ranks[node1] > ranks[node2]) {
		swap(node1, node2);
	}
	int rank1 = ranks[node1];
	int rank2 = ranks[node2];

	int diff = rank2 - rank1;
	for (int i = 0; diff; i++) {
		if (diff % 2) node2 = parents[node2][i];
		diff /= 2;
	}

	if (node1 != node2) {
		for (int i = 19; i >= 0; i--) {
			if (parents[node1][i] != -1 && parents[node1][i] != parents[node2][i]) {
				node1 = parents[node1][i];
				node2 = parents[node2][i];
			}

		}
		node1 = parents[node1][0];
	}

	return node1;
}

int query(Node* node1, Node* node2, Node* lca, Node* lca_p, int s, int e, int nth) {
	if (s == e) return s;
	int m = (s + e) / 2;
	int l_diff = node1->left->vertex + node2->left->vertex - lca->left->vertex - lca_p->left->vertex;
	if (nth <= l_diff) return query(node1->left, node2->left, lca->left, lca_p->left, s, m, nth);
	return query(node1->right, node2->right, lca->right, lca_p->right, m+1, e, nth - l_diff);
}

int main() {
	algo_init
	int n;
	cin >> n;
	int m;
	cin >> m;
	
	int max_weight = -1;
	for (int i = 1; i <= n; i++) {\
		cin >> weights[i];
		max_weight = max(max_weight, weights[i]);
	}

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	memset(parents, -1, sizeof(parents));
	memset(ranks, -1, sizeof(visited));
	ranks[0] = 0;
	ranks[1] = 1;
	parents[1][0] = 0;
	parents[0][0] = 0;

	

	for (int j = 0; j < 18; j++)
		for (int i = 1; i <= n; i++)
			if (parents[i][j] != -1)
				parents[i][j + 1] = parents[parents[i][j]][j];

	vector<int> tmp[101010];
	for (int i = 1; i <= n; i++) {
		int rank = ranks[i];
		tmp[rank].push_back(i);
	}

    root[0] = new Node();
	make_orig_tree(root[0], 1, max_weight);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < tmp[i].size(); j++) {
			int c = tmp[i][j];
            root[c] = new Node();
			int p = parents[c][0];
			add_dst_tree(root[p], root[c], 1, max_weight, weights[c]);

		}
	}
	
	

	
	
	
	for (int i = 0; i < m; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		if (u == v)
			cout << weights[u] << "\n";
		int lca = find_lca(u, v);
		int lca_p = parents[lca][0];

		cout << query(root[v], root[u], root[lca], root[lca_p], 1, max_weight, k)<<"\n";
	}

}
