import java.util.*;

class Solution {
    public int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b % a, a);
    }
    
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;
        Arrays.sort(arrayA);
        Arrays.sort(arrayB);
        
        int a = 0;
        int b = 0;
        
        for(int i = 0; i < arrayA.length; i++) {
            a = gcd(a, arrayA[i]);  //a 최댓값
        }
        
        for(int i = 0; i < arrayB.length; i++) {
            b = gcd(b, arrayB[i]); // b 최댓값
        }
        
        for(int i = 0; i < arrayB.length; i++) {
            if(arrayB[i] % a==0) {
                a = 0;
                break;
            }
        }
        for(int i = 0; i < arrayA.length; i++) {
            if(arrayA[i] % b == 0) {
                b = 0;
                break;
            }
        }
        
        if(a == 0 && b == 0) return 0;
        return Math.max(a, b);
    }
}