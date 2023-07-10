import java.util.*;

class Solution {
    public int gcd(int a, int b) {
        if(a==0) return b;
        return gcd(b%a, a);
    }
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;
        int a=0;
        int b=0;
        
        Arrays.sort(arrayA);
        Arrays.sort(arrayB);
        
        for(int i=0; i<arrayA.length; i++) {
            a= gcd(a, arrayA[i]);  
        }
        
        for(int i=0; i<arrayB.length; i++) {
            b=gcd(b, arrayB[i]);
        }
        
        for(int i=0; i<arrayB.length; i++) {
            if(arrayB[i]%a==0) {
                a=1;
                break; //a는 안된다
            }
        }
        for(int i=0; i<arrayA.length; i++) {
            if(arrayA[i]%b==0) {
                b=1;
                break; //b는 안된다
            }
        }
        
        if(a==1 && b==1) return 0;
        return Math.max(a, b);
    }
}