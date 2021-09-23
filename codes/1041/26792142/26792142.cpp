#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <unordered_map>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
#define DIV 1000000007
typedef long long ll;



ll N;

#define top 0
#define e 1
#define s 2
#define n 3
#define w 4
#define buttom 5

ll nums[6];




int main() {
	init();

	
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> nums[i];
	}

	ll min_two_sides = 98765432;
	ll min_three_sides = 98765432;
	ll bisides_array[4];
	bisides_array[0] = nums[n] + nums[w];
	bisides_array[1] = nums[w] + nums[s];
	bisides_array[2] = nums[s] + nums[e];
	bisides_array[3] = nums[e] + nums[n];
	for (int i = 1; i <= 4; i++) {
		ll top_num = nums[top];
		ll buttom_num = nums[buttom];

		min_two_sides = min(min_two_sides,min(top_num + nums[i], buttom_num + nums[i]));

		min_three_sides = min(min_three_sides, min(top_num + bisides_array[i - 1], buttom_num + bisides_array[i - 1]));

	}
	min_two_sides = min(min_two_sides, *min_element(bisides_array, bisides_array + 4));

	ll three_sides_num = 4;

	ll two_sides_num = 4*(N - 1) + 4*(N-2);

	ll others = 4 * ((N-2) * (N - 1)) + (N - 2) * (N - 2);

	if (N == 1) {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += nums[i];
		}
		cout << sum - *max_element(nums, nums + 6);
	}
	else {
		cout << ll(min_two_sides * two_sides_num + min_three_sides * three_sides_num + others * (*min_element(nums, nums + 6)));
	}
	
	

}
