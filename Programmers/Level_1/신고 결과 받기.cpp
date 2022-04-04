#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	map<string, vector<string>> m;
	map<string, int> m_cnt;

	for (int i = 0; i < report.size(); i++) {
		string from = report[i].substr(0, report[i].find(" "));
		string to = report[i].substr(report[i].find(" ") + 1, report[i].length());
		bool flag = true;

		if (m.find(from) == m.end()) { //없음
			vector<string> vec;
			vec.push_back(to);
			m.insert({ from, vec });
		}
		else {
			vector<string> vec = m.find(from)->second;
			if (find(vec.begin(), vec.end(), to) == vec.end()) {
				m.find(from)->second.push_back(to);
			}
			else flag = false; //중복
		}

		if (m_cnt.find(to) == m_cnt.end()) { //신고 안당했음
			m_cnt.insert({ to, 1 });
		}
		else {
			if (flag) m_cnt.find(to)->second += 1; //신고 추가
		}
	}

	for (int i = 0; i < id_list.size(); i++) {
		string from = id_list[i];
		int cnt = 0;
		if (m.find(from) != m.end()) {
			vector<string> vec = m.find(from)->second;
			for (int j = 0; j < vec.size(); j++) {
				if (m_cnt.find(vec[j])->second >= k) {
					cnt++;
				}
			}
		}
		answer.push_back(cnt);
	}

	return answer;
}