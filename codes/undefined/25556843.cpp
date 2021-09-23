#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#define MAX 987654321
using namespace std;

int fibo[50][2];
int visited[50];
int one, zero;

void func(int num) {
	if (visited[num] == 1) {
		zero += fibo[num][0];
		one += fibo[num][1];
		return;
	}
	


	func(num - 1);
	func(num - 2);
	visited[num] = 1;
	fibo[num][0] = fibo[num - 1][0] + fibo[num - 2][0];
	fibo[num][1] = fibo[num - 1][1] + fibo[num - 2][1];
}

int main() {
	int test_case;
	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;
	visited[0] = 1;
	visited[1] = 1;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int input;
		cin >> input;
		one = 0;
		zero = 0;
		func(input);
		cout << zero << " " << one << endl;
	}

}