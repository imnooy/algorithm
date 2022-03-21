#include <bits/stdc++.h>
using namespace std;

int n;
string arr[15]; //숫자들
vector<string> op; //연산자들
vector<int> iop; //숫자로..

vector<string> vec; //순서대로 배치

long maximum = -1000000000;
long minimum = 1000000000;

void calculate() {
	int index = 0;
	long res = stoi(arr[0]);
	for (int i = 1; i < n; i++) {
		if (vec[index] == "+") res += stoi(arr[i]);
		else if (vec[index] == "-") res -= stoi(arr[i]);
		else if (vec[index] == "*") res *= stoi(arr[i]);
		else if (vec[index] == "/") {
			if (res < 0 && stoi(arr[i]) > 0) {
				res = abs(res);
				res /= stoi(arr[i]);
				res = -res;
			}
			else res /= stoi(arr[i]);
		}
		index++;
	}
	maximum = max(res, maximum);
	minimum = min(res, minimum);
}

int main() {
	int a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //숫자 입력받기
	}

	for (int i = 0; i < 4; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			if (i == 0) op.push_back("+");
			else if (i == 1) op.push_back("-");
			else if (i == 2) op.push_back("*");
			else if (i == 3) op.push_back("/");
			iop.push_back(i);
		}
	}

	do {
		for (int i = 0; i < op.size(); i++) {
			vec.push_back(op[i]);
		}
		calculate();
		vec.clear();
		next_permutation(op.begin(), op.end());
	} while(next_permutation(iop.begin(), iop.end()));

	cout << maximum << '\n' << minimum;
	
	return 0;
}