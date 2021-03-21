## 몰랐거나 헷갈리던 개념들 정리  

</br>

### 실수의 성질

1. 실수의 저장/연산과정에서 반드시 오차가 발생할 수 밖에 없다.  
    + float은 유효숫자 6자리, double은 유효숫자 15자리  
    float은 상대오차 10<sup>-6</sup>까지 안전하고, double은 10<sup>-15</sup>까지 안전하다.  
    </br>
    =>float 보단 double을 쓰자!
    </br>
    
2. double에 long long 범위의 정수를 함부로 담으면 안된다.
    + double은 유효숫자가 15자리인데, long long은 최대 19자리이므로 double에 long long 범위의 값을 담으면 오차가 섞인 값이 저장될 수 있다. 
    </br>

3. 실수를 비교할 때는 등호를 사용하면 안된다.
    + 앞에서 이해했듯이 오차 때문!  
    대략 10<sup>-12</sup>(1e-12) 이하면 동일하다고 처리를 하는 게 안전하다.

</br>

----
</br>

### 시간복잡도 관련 개념
</br>

```cpp
bool cmp1(vector<int> v1, vector<int> v2, int idx) {
    return v1[idx] > v2[idx];
}
```
이 코드의 시간복잡도는 O(N).  
</br>

```cpp
bool cmp2(vector<int> &v1, vector<int> &v2, int idx) {
    return v1[idx] > v2[idx];
}
```
이 코드의 시간복잡도는 O(1)이다.  
  
첫번째 코드에서 cmp1에는 v1와 v2가 <span style="color:green">복사</span>되어서 전달되기 때문에 N개를 복사하므로 O(N)의 시간 복잡도를 가지는 것이다.

</br>

----