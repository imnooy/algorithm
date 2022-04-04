#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
	int answer = 1001;
	int len = s.length();

	if (len == 1) return 1;

	for (int i = 1; i <= len / 2; i++) { //몇개 단위로 끊는지
		string cmp = s.substr(0, i);
		vector<string> vec;
		int cnt = 1;
		for (int j = 0; j < len; j += i) { //문자열 살펴보기
			if (j != 0) {
				string to = s.substr(j, i);
				if (cmp == to) cnt++;
				else {
					if (cnt == 1) vec.push_back(cmp);
					else {
						string pushs = to_string(cnt) + cmp;
						vec.push_back(pushs);
					}
					cnt = 1;
					cmp = to;
				}
			}
		}
		if (cnt == 1) vec.push_back(cmp);
		else {
			string pushs = to_string(cnt) + cmp;
			vec.push_back(pushs);
		}
		if (!vec.empty()) {
			string res = "";
			for (int k = 0; k < vec.size(); k++) res += vec[k];
			int len = res.length();
			answer = min(answer, len);
		}
	}
	return answer;
}