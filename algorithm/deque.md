# 덱(Double Ended Queue)

(바킹독님의 실전 알고리즘 강의를 통해 공부한 내용)
https://blog.encrypted.gg/

### 덱의 정의와 성질
1. 양쪽 끝에서 삽입, 삭제가 전부 가능하다.
2. 원소의 추가, 제거가 O(1)이다.
3. 제일 앞/뒤의 원소 확인이 O(1)이다.
4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능하다.
5. **STL deque에서는 인덱스로 원소에 접근할 수 있다.**

---

### 덱의 기능과 구현
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

void test() {
	push_back(30); // 30
	cout << front() << '\n'; // 30
	cout << back() << '\n'; // 30
	push_front(25); // 25 30
	push_back(12); // 25 30 12
	cout << back() << '\n'; // 12
	push_back(62); // 25 30 12 62
	pop_front(); // 30 12 62
	cout << front() << '\n'; // 30
	pop_front(); // 12 62
	cout << back() << '\n'; // 62
}

int main(void) {
	test();
}
```

----

STL deque는 STL vector와 비슷한 느낌...
하지만 deque는 메모리에 연속적으로 저장되어있는 건 아님!  

=>**앞쪽에서의 추가/제거가 필요할 때는 deque를 쓰자!**