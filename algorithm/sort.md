# 정렬

(바킹독님의 실전 알고리즘 강의를 통해 공부한 내용)
https://blog.encrypted.gg/

<br></br>

## 기초 정렬

<br>

만약 배열 원소들을 크기 순서대로 정렬한다면  
제일 큰 원소를 끝으로 보내고..를 반복하거나 제일 작은 것부터 보낼 것.  

-> 시간복잡도:  
$N + (N-1) + (N-2) + ... + 1 = (N^2 + N) / 2 = O(N^2)$  

(N개 중에서 제일 큰 원소 찾고.. N-1개 중에서 제일 큰 원소 찾고.. 반복)

<br>

```c++
int arr[10]={3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n=10;

for(int i=n-1; i>0; i--) { //제일 큰 원소를 맨 끝에 보내기 위함
    int mxidx=0;
    for(int j=1; j<=i; j++) {
        if(arr[mxidx]<arr[j]) mxidx=j;
    }
    swap(arr[mxidx], arr[i]); //맨 끝으로
}
```


```c++
int arr[10]={3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n=10;

for(int i=n-1; i>0; i--) {
    swap(*max_element(arr, arr+i+1), arr[i]);
}
```


위의 코드를 드라마틱하게 바꾸기!!  
-> max_element 함수 이용!!


 max_element(arr, arr+k)는 arr[0], arr[1], arr[2], ..., arr[k-1]에서 **최댓값인 원소의 주소를 반환해주는 함수**다.  
 arr[k]가 아니라 arr[k-1]까지인 걸 명심!!  

 만약 배열에서 가장 큰 원소가 들어있는 인덱스를 알고 싶으면  
 k=max_element(arr, arr+n)-arr  

 이렇게 구할 수 있음!  
 (max_element의 시간복잡도: $O(N^2)$)


 ---

 ### 버블 정렬

<br>

 ```C++
int arr[5]={-2, 2, 4, 6, 13};
int n=5;

for(int i=0; i<n; i++) {
    for(int j=0; j<n-1; j++) {
        if(arr[j])>arr[j+1]) swap(arr[j], arr[j+1]);
    }
}
```

<br>

시간복잡도: $O(N^2)$

(선택, 삽입, 버블 정렬의 시간복잡도 동일)

---

<br>

## Merge Sort

<br>

```c++
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int a_index = st, b_index = mid;
	for (int i = st; i < en; i++) {
		if (a_index >= mid) tmp[i] = arr[b_index++];
		else if (b_index >= en) tmp[i] = arr[a_index++];
		else if (arr[a_index] >= arr[b_index]) tmp[i] = arr[b_index++];
		else tmp[i] = arr[a_index++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en) { //st는 포함, en은 포함 안할 때
	if (en - st == 1) 
		return; // 길이 1인 경우
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]을 정렬한다.
	merge_sort(mid, en); // arr[mid:en]을 정렬한다.
	merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
}
```


분할하는 과정(merge_sort())은 $O(N)$  
합쳐나가는 과정(merge())은 $O(NlogN)$  

<br>

시간복잡도: $O(NlogN)$


---


### Stable Sort

<br>

![image](https://user-images.githubusercontent.com/75800620/159928283-fce2f63b-7be9-4af0-a5a2-0ab4947cbd70.png)


나이가 같아도, 원래의 순서인  
파랑->빨강->초록 옷의 사람 순서대로  
정렬되게 하는 것이 stable sort!  

<br>

(우선 순위가 같은 원소들끼리는 원래의 순서를 따라가도록 하는 정렬!)


-> merge sort는 stable sort!!  
(어차피 입력받은 순대로 앞에서부터 빠져나감)

<br>

---

## Quick Sort

<br>

잠깐!!!!!!!!!!!!!!  

코테에서 만약 STL을 못쓰고 직접 정렬을 구현해야 하면 절대절대절대절대절대절대 퀵 소트 쓰지말고 머지 소트 쓰기..  
퀵소트만은 안됨  

<br> <br>

```c++
int arr[8] = { 6, -8, 1, 12, 8, 3, 7, -7 };
	int pivot = arr[0]; //얘 놓을 곳 찾기
	int l = 1;
	int r = 7;

	while (1) {
		while (arr[l] <= pivot) l++; //1. arr[l]이 pivot보다 커질 때까지 l++
		while (arr[r] > pivot) r--; //2. arr[r]이 pivot보다 작거나 같아질 때까지 r++
		if (r < l) break; //4. (1~3)을 l과 r이 교차할 때까지 반복하고 끝냄
		swap(arr[l], arr[r]); //3. 바꿔주기 (pivot보다 큰 걸 오른쪽으로, 작은 걸 왼쪽으로)
	}
	swap(arr[r], arr[0]); //그럼 r번째 위치가 pivot이 들어갈 위치!
```
<br>

l과 r이 한 칸씩 가까워지기 때문에  
이 코드의 시간복잡도는 $O(N)$

<br>

```c++
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

void quick_sort(int st, int en) { // arr[st to en-1]을 정렬할 예정
  if(en <= st+1) return; // 수열의 길이가 1 이하이면 함수 종료.(base condition)
  int pivot = arr[st]; // 제일 앞의 것을 pivot으로 잡는다. 임의의 값을 잡고 arr[st]와 swap해도 상관없음.
  int l = st+1; // 포인터 l
  int r = en-1; // 포인터 r
  while(1){
    while(l <= r && arr[l] <= pivot) l++;
    while(l <= r && arr[r] >= pivot) r--;
    if(l > r) break; // l과 r이 역전되는 그 즉시 탈출
    swap(arr[l], arr[r]);
  }
  swap(arr[st], arr[r]);
  quick_sort(st, r);
  quick_sort(r+1, en);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  quick_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
```


위 코드처럼 재귀적으로 구현하면 됨.


---


![image](https://user-images.githubusercontent.com/75800620/159942508-a945536e-5810-4e57-81b0-6d7038deee9e.png)

<br>

매번 pivot이 가운데에 위치해서 리스트를 균등하게 둘로 나눈다면 단계의 개수는 logN이므로 이 경우에는 퀵 소트의 시간복잡도는 $O(NlogN)$ 이다.

<br><br>

![image](https://user-images.githubusercontent.com/75800620/159942971-7e5be9e9-445d-442f-99c8-92a54ae8d3bb.png)

<br>

최악의 경우... 단계는 logN개가 아니라 N개가 됨.  
시간복잡도는 $O(N^2)$가 된다.


---

||Merge Sort|Quick Sort|
|------|---|---|
|시간 복잡도|$O(NlogN)$|평균 $O(NlogN)$, 최악 $O(N^2)$ / 평균적으로는 Merge Sort보다 빠름|
|추가적으로 필요한 공간(Overhead)|$O(N)$|$O(1)$|
|Stable Sort 여부|O|X|

<br>

---

<br>

## Counting Sort

<br>

정렬하고자 하는 원소가 양수고, 원소 크기의 최대 범위가 정해져 있을 때 사용
비교를 하지않지만, 결과를 저장할 공간이 추가적으로 필요함.


```c++
int cnt[10001]; //수는 10,000보다 작거나 같은 자연수이다. 
//-> 범위가 정해져있으므로 Counting Sort 사용

cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n';
```

<br>

수의 범위가 위에서는 10000까지.  
수의 범위가 K개(여기서는 10000개)라고 할 때  

처음 N개의 수를 보면서 cnt 배열에 값 추가,  
출력할 때 K칸의 값을 확인해야 하기 때문에  
시간복잡도는 $O(N+K)$ 이다.

<br>

---

## Radix Sort

<br>

라딕스 소트는 자릿수를 이용해서 정렬을 수행하는 알고리즘이다.

먼저 인덱스가 0~9까지 있는 배열이 있다.
만약 자릿수의 최대 개수가 3개일 때, (최댓값이 3자리 수일 때)  

1. 각 숫자의 1의 자리를 인덱스로 해 배열에 넣는다.

![image](https://user-images.githubusercontent.com/75800620/160031785-73b2e5e3-17d5-4020-95f0-ccff1098de1c.png)


2. 배열의 0번 인덱스에 있는 리스트부터 수를 꺼내서 수열을 재배열하는데, 이때는 10의 자리를 보면서 배열에 다시 넣는다.


![image](https://user-images.githubusercontent.com/75800620/160031844-bb762498-84ea-45f8-b4d8-308387706bd8.png)

3. 100의 자리를 보면서 재배열한다.

![image](https://user-images.githubusercontent.com/75800620/160031876-5748da24-e0a2-4914-98fc-448395c26a7c.png)

<br>

1의 자리 순으로 재배열, 10의 자리 순으로 재배열, 100의 자리 순으로 재배열..!


어렸을 때 숫자들을 비교할 때  
100의 자리 먼저 보고, 10의 자리 보고, 1의 자리 보면서 비교했던 거랑 똑같다. 

<br>

만약 자리수가 D개라고 할 때, D번에 걸쳐 카운팅 소트를 하는 거랑 같다!  
그럼 만약 리스트 개수가 K개라고 할 때  
시간복잡도는 $O(D(N+K))$이지만 보통 리스트의 개수는 N에 비해선 엄~청 작다.  

위 예시도 리스트의 개수 K는 10밖에 안된다.  

그래서 결론적으로 라딕스 소트의 시간복잡도는 $O(DN)$이다. 


```c++
#include <bits/stdc++.h>
using namespace std;

int n = 15;
int arr[1000001] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240};

// 1, 10, 100의 자리에 대해서 진행, 수가 최대 3자리수가 아닐 경우 d를 조절해야 함
int d = 3;
// p10[i] = 10의 i승
int p10[3];

// x의 10^a 자리의 값을 반환하는 함수
int digitNum(int x, int a){
  return (x / p10[a]) % 10;
}

vector<int> l[10]; //0~9자리수의 list를 저장하는 vector

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  p10[0] = 1;
  for(int i = 1; i < d; i++) p10[i] = p10[i-1] * 10;
  
  for(int i = 0; i < d; i++){
    for(int j = 0; j < 10; j++) l[j].clear();
    // 각 수를 list에 대입
    for(int j = 0; j < n; j++)
      l[digitNum(arr[j], i)].push_back(arr[j]);
    // 0번 리스트부터 차례로 다시 arr에 넣어 재배열
    int aidx = 0;
    for(int j = 0; j < 10; j++){
      for(auto x : l[j]) arr[aidx++] = x;
    }
  }
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
```

<br>

---

<br>

## 정리

Comparison Sort: 버블 소트, 머지 소트, 퀵 소트

Non-comparison Sort: 카운팅 소트, 라딕스 소트

<br>

---
---

## STL sort

```c++
int a[5]={1, 4, 5, 2, 7};
sort(a, a+5);

vector<int> b={1, 4, 5, 2, 7};
sort(b.begin(), b.end()); 
//or sort(b.begin(), b.begin()+5);
```

<br>

STL sort는 퀵 소트 기반  
->최악의 경우에는 $O(NlogN)$이 보장되는 정렬 알고리즘으로 처리됨.

-> $O(NlogN)$  

<br>

stable sort는 아니기 때문에  
꼭 필요하다면 stable_sort 함수를 사용하면 된다.

<br><br>

STL sort에서는 비교 함수를 내가 정해서 인자로 같이 넘겨줄 수 있다.  

```c++
bool cmp(int a, int b) {
	if(a%5 != b%5) return a%5 < b%5;
	return a < b;
}

int a[7]={1, 2, 3, 4, 5, 6, 7};
sort(a, a+7, cmp);
```

만약 위 코드처럼 배열을 5로 나눈 나머지 순으로, 나머지가 같다면 크기 순으로 정렬하고 싶다면  
우리가 만든 나머지 함수인 cmp를 같이 인자로 주면 된다.  

그러면 배열 a는 5, 1, 6, 2, 7, 3, 4로 정렬된다.   

<br>

하지만 **주의사항!!!**

1. 비교 함수는 두 값이 같을 때(혹은 우선순위가 같을 때) false를 반환한다.

그래서 

```c++
if(a>=b) return true;
```

위 같은 코드를 쓰면 런타임 에러가 날 수도 있다.

```c++
return a>b
```

이렇게 쓰도록 하자. 

<br>

2. 비교 함수의 인자로 STL 혹은 클래스 객체를 전달할 때 reference를 사용하자.  

만약 문자열들을 받아 각 문자열의 끝자리의 알파벳 순서대로 정렬하고 싶다고 했을 때, 

```c++
bool cmp(string a, string b) {
	return a.back() < b.back();
}
```

이렇게 하면 안된다. 불필요한 복사가 일어나기 때문..

<br>

```c++
bool cmp(const string &a, const string &b) {
	return a.back() < b.back();
}
```

a와 b의 값은 변하지 않으므로 이게 더 바람직하다. 