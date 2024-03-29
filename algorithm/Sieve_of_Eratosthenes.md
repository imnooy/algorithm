# 에라토스테네스의 체

<img width="736" alt="에라토스테네스의 체" src="https://user-images.githubusercontent.com/75800620/111868612-4509e500-89be-11eb-915d-66c3cc39d20a.gif">
</br></br>

만약 120까지의 모든 소수를 구한다고 하면,  
소수가 아닌 것들을 모두 체크하면 된다.  
  
2을 제외한 2의 배수들을 체크  
3을 제외한 3의 배수들을 체크  
4는 이미 체크당했으니 소수가 아니다.  
5를 제외한 5의 배수들을 체크  
6도 이미 체크당했으니 소수가 아니다.  
.  
.  
.  
이런 식으로 체크해나가서  
체크가 안된 수들이 소수이다.  
</br>
```cpp
void isPrime() {
    //2 ~ n까지의 수를 검사
	bool *arr = new bool[n + 1]; 
    //소수와 인덱스가 일치하도록

	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	} //초기화

	for (int i = 2; i <= n; i++) {
		if (arr[i] == true) { 
        //검사안된 수나 소수일 때만
			for (int j = i * 2; j <= n; j += i) {
				//i의 배수를 체크
				arr[j] = false;
			}
		}
	}
    ...
}
```
이렇게 짰는데, 두번째 for문에서 i를 n대신 sqrt(n) 까지만 검사해도 된다고 한다.

잘 이해가 되지 않아 직접 써보려고 한다.  
</br>

-----
</br>
만약 N이라는 합성수가 있다고 하자.  

N = a * b 라고 하면, 

a나 b 둘 중 하나는 무조건 sqrt(N)보다 작거나 같을 수 밖에 없다.  

그러니까.. 만약 N이 12면 12의 약수는  
1, 2, 3, 4, 6, 12인데  
12의 제곱근은 3.xxx일 것이다.  
그런데 제곱근을 기준으로 좌우로 곱하기가 대칭을 이루기 때문에  
제곱근보다 작거나 같은 숫자로 나누어 떨어지면  
이 다음부터는 대칭이기 때문에 계산을 할 필요가 없는 것이다.

그렇기 때문에 2부터 sqrt(N)까지의 수로 나눠서  
나눠지는 수가 있으면 소수가 아닌 것이다. 

</br>

---------
</br>
바꾼 코드는 다음과 같다.  

```cpp
void isPrime() {
    //2 ~ n까지의 수를 검사
	bool *arr = new bool[n + 1]; 
    //소수와 인덱스가 일치하도록

	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	} //초기화

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == true) { 
        //검사안된 수나 소수일 때만
			for (int j = i * 2; j <= n; j += i) {
				//i의 배수를 체크
				arr[j] = false;
			}
		}
	}
    ...
}
```


