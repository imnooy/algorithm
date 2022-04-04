#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, pair<string, string>>> vec; //순서, {이름, 상태}

bool cmp(pair<int, pair<string, string>> a, pair<int, pair<string, string>> b) {
	return a.first < b.first;
}

vector<string> solution(vector<string> record) {
	multimap<string, pair<int, pair<string, string>>> m; //id, {순서, {이름, 상태}} 들어옴

	for (int i = 0; i < record.size(); i++) {
		string str = record[i];

		string com = str.substr(0, str.find(' '));
		str = str.substr(com.length() + 1);

		string id = str.substr(0, str.find(' '));
		string name = str.substr(id.length());
		if (name != "") name = name.substr(1);

		if (com == "Enter") {
			m.insert({ id, {i, {name, "님이 들어왔습니다."}} });
		}
		else if (com == "Leave") {
			name = m.find(id)->second.second.first;
			m.insert({ id, {i, {name, "님이 나갔습니다."}} });
		}
		if (com != "Leave") {
			for (auto iter = m.lower_bound(id); iter != m.upper_bound(id); iter++) {
				iter->second.second.first = name;
			}
		}
	}
	for (auto &i : m) {
		vec.push_back({ i.second });
	}

	sort(vec.begin(), vec.end(), cmp);

	vector<string> answer;

	for (int i = 0; i < vec.size(); i++) {
		answer.push_back(vec[i].second.first + vec[i].second.second);
	}


	return answer;
}