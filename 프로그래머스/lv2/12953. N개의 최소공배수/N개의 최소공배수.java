import java.util.*;

class Solution {
    public int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b % a, a);
    }
    
    public int solution(int[] arr) {
        int answer = 0;
        Arrays.sort(arr);
        
        if(arr.length == 1) return arr[0];
        
        int lcm = (arr[0] * arr[1]) / gcd(arr[0], arr[1]);
        
        for(int i = 2; i < arr.length; i++) {
            int a, b;
            if(lcm > arr[i]) {
                a = arr[i];
                b = lcm;
            }
            else {
                a = lcm;
                b = arr[i];
            }
            
            lcm = (a * b) / gcd(a, b);
        }
        
        return lcm;
    }
}