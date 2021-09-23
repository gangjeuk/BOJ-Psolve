#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n;
int costs[1000][3];
int max_costs[1000][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> costs[i][j];
		}
	}


	max_costs[0][0] = costs[0][0];
	max_costs[0][1] = costs[0][1];
	max_costs[0][2] = costs[0][2];


	for (int i = 0; i < n-1 ; i++) {
		int next = i + 1;
		int here = i;
		int parents[3] = { 0,1,2 };
		for (int color = 0; color < 3; color++) {
			vector<int> ok_nums;
			for (int parent = 0; parent < 3; parent++) {
				if (parents[color] != parent) {
					ok_nums.push_back(parent);
				}
				else {
					parents[color] = parent;
				}
			}


			max_costs[next][color] = costs[next][color] + min(max_costs[here][ok_nums[1]], max_costs[here][ok_nums[0]]);
			ok_nums.clear();
		}
		
	}

	cout << min({ max_costs[n - 1][0],max_costs[n - 1][1],max_costs[n - 1][2] });


}