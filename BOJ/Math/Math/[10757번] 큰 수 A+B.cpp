#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	vector<int> arr;
	vector<int> brr;
	for (int i = a.size()-1; i >=0; i--) {
		arr.push_back(a[i] - '0');
	}

	for (int i = b.size()-1; i >=0; i--) {
		brr.push_back(b[i] - '0');
	}

	int s, sum, ssum;

	if (a.size() != b.size()) {
		if (a.size() > b.size()) {
			s = a.size();
			for (int i = 0; i < a.size(); i++) {
				brr.push_back(0);
			}
		}
		else {
			s = b.size();
			for (int i = 0; i < b.size(); i++) {
				arr.push_back(0);
			}
		}
	}
	else s = a.size();
	

	vector<char> res(s, 0+'0');
	
	for (int k = 0; k < s; k++) {
		ssum = arr[k] + brr[k] + (res[k] - '0');
		if ((k == (s - 1)) && ssum >= 10) {
			sum = ssum - 10;
			res[k] = sum + '0';
			res.push_back(1+'0');
			break;
		}
		if (ssum < 10) {
			res[k] = (ssum + '0');
		}
		else {
			sum = ssum - 10;
			res[k + 1] = (res[k+1] - '0') + (1 + '0');
			res[k] = (sum + '0');
		}
	}

	for (auto ir = res.rbegin(); ir != res.rend(); ++ir)
		cout << *ir;

	return 0;
}