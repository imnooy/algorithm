# 스택

(바킹독님의 실전 알고리즘 강의를 통해 공부한 내용)
https://blog.encrypted.gg/

### 스택의 정의와 성질
1. 스택은 먼저 들어간 원소가 제일 나중에 나온다.
    * FILO (First In Last Out) 구조 (프링글스 통처럼)
2. 원소의 추가, 제거가 O(1)
3. 제일 상단의 원소 확인이 O(1)
4. 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능하다.
    * 스택은 **원소의 추가/제거/제일 상단의 원소 확인**의 기능만 제공하는 자료구조이기 때문!
    * 물론 배열을 이용하면 가능하게는 만들 수 있긴 하다..

----

### 스택의 기능과 구현

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
	dat[pos] = x;
	pos++;
}

void pop() {
	pos--;
}

int top() {
	return dat[pos - 1];
}

void test() {
	push(5); push(4); push(3);
	cout << top() << '\n'; // 3
	pop(); pop();
	cout << top() << '\n'; // 5
	push(10); push(12);
	cout << top() << '\n'; // 12
	pop();
	cout << top() << '\n'; // 10
}

int main(void) {
	test();
}
```

---

</br>

STL stack을 사용할 때는 stack이 비었는지 꼭 확인하자!