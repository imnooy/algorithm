# Backtracking

(바킹독님의 실전 알고리즘 강의를 통해 공부한 내용)
https://blog.encrypted.gg/

### 백트래킹

: 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘

</br>

---

## STL next_permutation

순열, 조합 해결 (n, m 시리즈는 next_permutation을 써서 다시 풀어보기!!)

-> http://www.cplusplus.com/reference/algorithm/next_permutation/

</br>


```cpp
int a[3]={1, 2, 3};

do{
    for(int i=0; i<3; i++) cout << a[i];
    cout << '\n'
} while(next_permutation(a, a+3));

/*
result:
123
132
213
231
312
321
*/
```

</br>

```cpp
//1 2 3 4 중 2개를 순서없이 뽑기
int a[4]={0, 0, 1, 1};

do{
    for(int i=0; i<4; i++) {
        if(a[i]==0) cout << i+1;
    }
    cout << '\n'
} while(next_permutation(a, a+4));

/*
result:
12
13
14
14
23
24
34
*/
```