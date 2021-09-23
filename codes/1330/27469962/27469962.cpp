#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stack>
#include <list>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;
#define MAX 1000000007

int a, b;

int main() {
	cin >> a >> b;
	
	if (a > b) {
		cout << ">";
	}
	else if (a < b) {
		cout << "<";
	}
	else {
		cout << "==";
	}

	
}