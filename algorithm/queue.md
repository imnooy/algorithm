# 큐

(바킹독님의 실전 알고리즘 강의를 통해 공부한 내용)
https://blog.encrypted.gg/

### 큐의 정의와 성질
1. 먼저 들어간 원소가 먼저 나온다 (FIFO)
2. 원소의 추가/제거가 O(1)이다.
3. 제일 앞/뒤의 원소 확인이 O(1)이다.
4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능하다. (배열로는 구현할 수는 있음)

    (추가되는 곳을 rear, 제거되는 곳을 front라고 함.)  
    (제일 앞을 head로 가리키고, 제일 뒷 원소+1은 tail)


</br>

큐의 원소가 삭제가 될 때마다 앞쪽의 공간이 있음에도 원소를 새로 넣을 수 없는 상황을 막기 위해 원형 큐를 직접 만들어서 쓸 수 있음.  
(head와 tail이 MAX가 될 때마다 0으로 만들면 된다.)

---


### 큐의 구현
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

void test() {
	push(10); push(20); push(30);
	cout << front() << '\n'; // 10
	cout << back() << '\n'; // 30
	pop(); pop();
	push(15); push(25);
	cout << front() << '\n'; // 30
	cout << back() << '\n'; // 25
}

int main(void) {
	test();
}
```