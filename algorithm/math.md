# 수학

(바킹독님의 실전 알고리즘 강의를 통해 공부한 내용)
https://blog.encrypted.gg/

## 소수

### 소수의 정의

**소수**
* 1과 자기 자신으로만 나누어지는 수
* 약수가 2개인 수

<br>

**합성수**
* 1과 자기 자신을 제외한 다른 약수를 가지고 있는 수

(1은 소수도, 합성수도 아니다!)

<br>

### 소수 판정법

**소수**
* 1과 자기 자신으로만 나누어지는 수
* 약수가 2개인 수
* ***2부터 N-1까지의 수로 나누어지지 않는 수***

```java
boolean isPrime(int n) {
  if(n == 1) return 0;
  for(int i = 2; i < n; i++) {
    if(n % i == 0) return 0;
  }
  return 1;
}
```

=> 시간복잡도 : **O(n)**

<br>

### 합성수 N에서 1을 제외한 가장 작은 약수는 √n이하이다.

* 증명
  * 합성수 N에서 1을 제외한 가장 작은 약수를 x라고 하자.
  N/x 또한 1이 아닌 N의 약수이기 때문에 x ≤ (N/x)이다.
  우변의 분모 x를 좌변으로 옮기면 x^2 ≤ N이므로
  ***x ≤ √N*** !!!

### **2부터 ~~N-1~~ √n까지의 수로 나누어지지 않으면 소수이다.

<br>

```java
void isPrime(int n) {
  if(n == 1) return 0;
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) return 0;
  }
  return 1;
}
```

=> 시간복잡도 : **O(√N)**

(범위 내에서의 소수 판정법 : 에라토스테네스의 채 참고!!!)

<br>

---

## 소인수분해

### 1100 = 2 * 2 * 5 * 5 * 11

N = 1100 (소인수분해를 할 수) / i = 2 (2로 시작해서 1씩 증가)

1. N이 i로 나누어지는지 확인한다.
2. 나누어진다면 소인수 목록에 i를 추가하고 N을 i로 나눈다.
3. 더 이상 N이 i로 나누어지지 않는다면 i를 1씩 증가시키고 1번부터 반복한다.

<br>

### 방법의 정당성
* 소인수 목록에 적힌 수들을 곱했을 때 N이 되는가? -> **Yes**
* 목록에 있는 수들이 전부 소수인가? -> **Yes**

<br>

### 시간복잡도의 개선
* N이 1일 때 종료하는 대신 i * i > N일 때 종료 -> **O(√n)**

<br>

---

## 최대공약수

### 약수

* 약수 = 어떤 수를 나누어 떨어지게 하는 수
  * 18의 약수 = 1, 2, 3, 6, 9, 18

```java
List<Integer> divisor(int n) {
  List<Integer> list;
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) list.add(i);
  }
  return list;
}
```

=> 시간복잡도 : **O(N)**

<br>

이것도 O(√n)에 가능!

```java
List<Integer> divisor(int n) {
  List<Integer> list;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) list.add(i);
  }
  for(int i = list.size() - 1; i >= 0; i--) {
    if(list.get(i) * list.get(i) == n) continue; //중복 예외 처리
    list.add(n / list.get(i));
  }
  return list;
}
```

<br>

### 최대공약수

* 두 자연수의 공통된 약수 중 가장 큰 약수 (Greatest Common Divisor)
  * 20의 약수 = **1**, **2**, **4**, 5, 10, 20
  * 12의 약수 = **1**, **2**, 3, **4**, 6, 12
    * GCD(20, 12) = 4

<br>

* 유클리드 호제법 : 두 수 A, B에 대해 A를 B로 나눈 나머지를 r이라고 하면 GCD(A, B) = GCD(B, r)이다.

<br>

GCD(20, 12) = GCD(12, 8) = GCD(8, 4) = GCD(4, 0) = 4

<br>

```java
int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
```

<br>

### 최소공배수 (LCM, Least Common Multiple)

A * B = GCD(A, B) * LCM(A, B)

<br>

```java
int lcm(int a, int b) {
  return a / gcd(a, b) * b; //만약 a / b * gcd(a, b) 라면 a와 b가 10^9일 때 lcm(a, b)가 10^9임에도 불구하고 overflow가 발생
}
```

<br>

---

## 연립합동방정식

ex) 민경 선생님은 자신의 반 학생이 몇 명인지 갑자기 기억이 나지 않았다. 다만
* 6명씩 조를 짰을 때 3명이 남았다.
* 5명씩 조를 짰을 때 2명이 남았다.
* 학생은 30명 미만이다.

이 3가지 사실은 기억하고 있다. 민경 선생님의 반 학생들은 몇 명일까?

<br>

```java
int chk() {
  for(int i = 0; i < 30; i++) {
    if(i % 6 == 3 && i % 5 == 2) return i;
  }
  return -1;
}
```

<br>

이것보다 조금 더 효율적인 방법....

```java
int chk() {
  for(int i = 3; i < 30; i += 6) {
    if(i % 5 == 2) return i;
  }
  return -1;
}
```

<br>

---

## 이향계수

nCk = n! / ((n-k)! * k!)

nPr = n! / (n-k)!

<br>

순서를 고려하지 않고 5개에서 3개를 뽑는 경우의 수 : 5! / (3!2!) = 10
순서를 고려해 5개에서 3개를 뽑는 경우의 수 : 5! / 2! = 60

<br>

```java
int ret = 1;
for(int i = 1; i <= n; i++) ret *= i;
for(int i = 1; i <= k; i++) ret /= i;
for(int i = 1; i <= n-k; i++) ret /= i;

System.out.println(ret);
```

<br>

n과 k의 제한이 커진다면..??

<br>

다시..

nCk = n-1Ck + n-1Ck-1 (파스칼의 삼각형..생각..)

-> **DP!!!**

<br>

```java
for(int i = 1; i <= n; i++) {
  dp[i][0] = 1;
  dp[i][i] = 1;
  for(int j = 1; j < i; j++) {
    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]);
  }
}

System.out.println(dp[n][m]);
```






