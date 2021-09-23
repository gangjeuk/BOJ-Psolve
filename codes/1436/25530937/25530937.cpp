#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#define MAX 987654321
using namespace std;


int main() {
	int n;
	cin >> n;

	int until = 0;
	int output = 0;
	for (int i = 666; i < 2700000; i++) {
		
		string str = to_string(i);
		if (str.find("666") != -1) {
			until++;
			if (until == n) {
				output = i;
				break;
			}
		}
	}

		cout << output;
	
}