#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<char> s;
	bool isgroup, isnot;
	int n, j;
	int cnt = 0;
	cin >> n;

	bool *arr=new bool[n];
	string *sarr = new string[n];

	for (int i = 0; i < n; i++) {
		s.clear();
		cin >> sarr[i];
		for (int k = 0; k < sarr[i].size(); k++) {
			s.insert(sarr[i].at(k));
		}
		if (s.size() == sarr[i].size()) arr[i] = true;
		else {
			isnot = false;
			while (1) {
				j = 0;
				if (sarr[i].size() > 1) {
					if ((sarr[i].at(j) == sarr[i].at(j + 1)) && (s.find(sarr[i].at(j)) != s.end())) { //연속되는 문자가 있고 set에 있을 때
						sarr[i] = sarr[i].substr(j + 1, sarr[i].size() - 1); //set에서 지우지 않고 한글자 잘라냄
					}
					else if ((sarr[i].at(j) != sarr[i].at(j + 1)) && (s.find(sarr[i].at(j)) != s.end())) { //연속되는 문자 없고 set에 있을 때
						s.erase(s.find(sarr[i].at(j)));
						sarr[i] = sarr[i].substr(j + 1, sarr[i].size() - 1);
					}

					else {
						isnot = true;
						break;
					}
				}
				else if (sarr[i].size() == 1 && (s.find(sarr[i].at(j)) != s.end())) { //길이가 1이고 set에 있을 때
					isnot = false;
					break;
				}
				else if (sarr[i].size() == 1 && (s.find(sarr[i].at(j)) == s.end())) { //길이가 1이고 set에 없을 때
					isnot = true;
					break;
				}
			}
			if(isnot==false) arr[i] = true;
			else arr[i] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == true) cnt++;
	}

	cout << cnt;

	delete[] arr;
	delete[] sarr;

	return 0;
}