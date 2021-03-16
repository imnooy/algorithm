#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;

	int n = ((v - b) / (a - b));
	if(((v - b) % (a - b)==0)) cout << n;
	else cout << n + 1;
	return 0;
}