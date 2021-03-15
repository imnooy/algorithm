#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<char> s;
	bool isgroup, isnot;
	int n;
	int cnt = 0;
	cin >> n;

	bool *arr=new bool[n];
	string *sarr = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> sarr[i];
		for (int j = 0; j < sarr[i].size(); j++) {
			s.insert(sarr[i].at(j));
		}
		if (s.size() == sarr[i].size()) arr[i] = true;
		else {
			isnot = false;
			for (int j = 0; j < sarr[i].size()-1; j++) {
				if ((sarr[i].at(j) == sarr[i].at(j + 1)) && (s.find(sarr[i].at(j))!=s.end())) { //���ӵǴ� ���ڰ� �ְ� set�� ���� ��
					sarr[i] = sarr[i].substr(j + 1, sarr[i].size() - 1); //set���� ������ �ʰ� �ѱ��� �߶�
				}
				else if ((sarr[i].at(j) != sarr[i].at(j + 1)) && (s.find(sarr[i].at(j)) != s.end())) { //���ӵǴ� ���� ���� set�� ���� ��
					sarr[i] = sarr[i].substr(j + 1, sarr[i].size() - 1);
					s.erase(s.find(sarr[i].at(j)));
				}

				else {
					isnot = true;
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

	return 0;
}