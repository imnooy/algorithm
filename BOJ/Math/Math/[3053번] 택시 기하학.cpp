#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const double PI = std::acos(-1);
	double r;
	cin >> r;

	cout << fixed;
	cout.precision(6);

	cout << r * r * PI << '\n' << 2 * r*r;
}