#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	bool isthere=false;
	set<int> res;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		res.insert(n % 42); //나머지 저장 배열
	}

	cout << res.size();

	return 0;
}