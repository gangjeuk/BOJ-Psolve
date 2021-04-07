/*
 * Created on 2021 4 Wed Apr 07 2021 18:14:18
 *
 * Copyright (c) 2021 Your Company
 * This work is licensed under the terms of The 3-Clause BSD License.
 * 설명 - explanation - 解説
 * --
 * HLD문제
 *  참고 자료 - reference - 参考資料
 * --
 * https://panty.run/boj13512/
 * 
 * 노래 추천 - Music recommend - 歌のおすすめ
 * --
 * https://www.youtube.com/watch?v=N2DglZjKvBU
 */

#define algo_init ios_base::sync_with_stdio(false), cin.tie(NULL);
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <math.h>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

#define black 1
#define white 0


int n,m;
vector<int> graph[101010];
int groups[101010];
int parents[101010];
int weights[101010];
int ranks[101010];

struct seg_tree {
	int group = 0;
	int n = 0;
	const vector<int>* array = NULL;
	vector<int> seg_array;
	
	seg_tree() {
		group = 0;
		n = 0;
		array = NULL;
	}

	/*
	seg_tree(const vector<int>* nums,int _group) {
		array = nums;
		n = (*array).size();
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		group = _group;
		seg_array.resize(tree_size);
	}
	*/
	void init(const vector<int>* nums, int _group) {
		array = nums;
		n = (*array).size();
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		group = _group;
		seg_array.resize(tree_size);
	}


	void update(int i) {
		//int pos = num_to_index(i);
		int pos = ranks[i] - ranks[group];
		update_nodes(seg_array, pos, 0, n - 1, 1);
	}
	
	void update_nodes(vector<int>& array, int target, int start, int end, int node) {
		if (target < start || end < target) return;

		if (start == end) {
			array[node] = array[node] == white ? black : white;
			return;
		}

		int m = start + end >> 1;
		update_nodes(array, target, start, m, node * 2);
		update_nodes(array, target, m + 1, end, node * 2 + 1);

		int l_c = array[node * 2];
		int r_c = array[node * 2 + 1];

		if (l_c == black || r_c == black)
			array[node] = black;
		else
			array[node] = white;
		return;
	}

	/*
	int num_to_index(int i) {
		int index = find((*array).begin(), (*array).end(), i) - (*array).begin();
		return index;
	}
	*/

	int query(int left, int right) {
		left = ranks[left] - ranks[group];
		right = ranks[right] - ranks[group];
		//left = num_to_index(left);
		//right = num_to_index(right);
		int ret = query(seg_array, left, right, 0, n - 1, 1);
		return ret == 200000000 ? -1 : (*array)[ret];

	}

	int query(const vector<int>& array, int left, int right,int nodeLeft,int nodeRight, int node) {
		if (right < nodeLeft || nodeRight < left) return 200000000;
		if (nodeLeft == nodeRight) {
			if (array[node] == black)
				return nodeLeft;
			else
				return 200000000;
		}
		int m = nodeLeft + nodeRight >> 1;
		
		bool l_c = array[node * 2];
		bool r_c = array[node * 2 + 1];

		if (l_c == white && r_c == white)
			return 200000000;

		int l_ret = 200000000;
		int r_ret = 200000000;
		if (l_c == black) {
			l_ret = query(array, left, right, nodeLeft, m, node * 2);
		}
		else {
			r_ret = query(array, left, right, m + 1, nodeRight, node * 2 + 1);
		}

		return min(l_ret, r_ret);
	}
};

using tree = struct seg_tree;

// unordered_map<int, seg_tree*> group_map;
seg_tree group_re_map[101010];

void dfs_first(int start) {
	weights[start] = 1;
	for (auto& child : graph[start])
	{
		if (!weights[child])
		{
			parents[child] = start;
			ranks[child] = ranks[start] + 1;
			dfs_first(child);
			weights[start] += weights[child];
		}
	}
}

void dfs_second(int start,int group,vector<int>* p) {
	int heaviest = -1;
	if (start == group) {
		p = new vector<int>;
		p->push_back(start);
		groups[start] = start;
	}
	for (auto& child : graph[start]) {
		if (parents[child] == start && (heaviest == -1 || weights[child] > weights[heaviest]))
			heaviest = child;
	}

	if (heaviest != -1) {
		groups[heaviest] = groups[start];
		p->push_back(heaviest);
		dfs_second(heaviest, group, p);
	}
	if (heaviest == -1) {
		// group_re_map[group] = new tree(p,group);
		group_re_map[group].init(p, group);
		return;
	}

	for (auto& child : graph[start]) {
		if (parents[child] == start && child != heaviest)
		{
			groups[child] = group;
			dfs_second(child, child, p);
		}
	}
}

void query1(int v) {

	int& g = groups[v];
	//group_re_map[g]->update(v);
	group_re_map[g].update(v);

}

int query2(int v) {
	int root = 1;

	int ret = -1;

	while (groups[1] != groups[v]) {
		int& g = groups[v];
		//int tmp = group_re_map[g]->query(g, v);
		int tmp = group_re_map[g].query(g, v);

		ret = tmp == -1 ? ret : tmp;
		v = parents[groups[v]];
	}
	//int tmp = group_re_map[1]->query(1, v);
	int tmp = group_re_map[1].query(1, v);

	ret = tmp == -1 ? ret : tmp;

	return ret;
}



int main() {
	algo_init
		cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs_first(1);

	dfs_second(1, 1, NULL);


	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1)
			query1(b);
		else
			cout << query2(b) << "\n";
	}
}
