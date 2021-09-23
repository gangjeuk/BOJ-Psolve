#include <iostream>
#include <time.h>
#define MAX 98765432
using namespace std;

int a,b,c;

int power(int a, int b) {
	
	if (b == 0) {
		return 1;
	}

	int ret1 = power(a, b / 2) % c;

	int result = (1LL*ret1 * ret1) % c;

	if (b % 2) 
		result = 1LL * result * a % c;

	return result;
	

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	cout << power(a, b);


}

