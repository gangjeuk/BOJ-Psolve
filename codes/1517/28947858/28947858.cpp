#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using ll = long long;
using namespace std;
vector<pair<int, int>> nums;


struct seg_tree {
	vector<int> arr;
	vector<int> seg;
	int n;
	int h;
	seg_tree() : arr() {
		for (int i = 0; i < nums.size(); i++) {
			arr.push_back(nums[i].first);
		}
		n = nums.size();
		h = (int)ceil(log2(n));

		seg.resize(1 << (h + 1));

	}
	ll init() {
		return init(0, arr.size() - 1, 1);
	}

	ll init(int node_start, int node_end, int seg_node) {
		if (node_start == node_end)
			return 0;

		ll changed_count = 0;

		int mid = (node_start + node_end) >> 1;

		changed_count += init(node_start, mid, seg_node * 2);
		changed_count += init(mid + 1, node_end, seg_node * 2 + 1);

		vector<int> sorted;
		sorted.resize(node_end - node_start + 1);

		int low = node_start;
		int k = 0;
		int high = mid + 1;
		while (low <= mid && high <= node_end)
		{
			if (arr[low] <= arr[high])
			{
				sorted[k++] = arr[low++];
			}
			else
			{
				changed_count += mid - low + 1;
				sorted[k++] = arr[high++];
			}
		}
		if (low <= mid)
		{
			for (int i = low; i <= mid; i++)
				sorted[k++] = arr[i];
		}
		else
		{
			for (int i = high; i <= node_end; i++)
				sorted[k++] = arr[i];
		}

		for (int i = 0; i < sorted.size(); i++) {
			arr[node_start + i] = sorted[i];
		}

		return changed_count;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back({ num,i });
	}

	seg_tree tree;

	nums;
	cout << tree.init();
}