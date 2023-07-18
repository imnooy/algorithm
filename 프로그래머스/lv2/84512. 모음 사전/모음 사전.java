import java.util.*;

class Solution {
    public char[]chars = new char[]{'A', 'E', 'I', 'O', 'U'};
    public char[]arr;
    public int ans;
    public int cnt;
    
    public void func(int k, String word) {
        String str = "";
        for(int i=0; i<5; i++) {
            if(arr[i]=='X') str+="";
            else str+=(arr[i]+"");
        }
        if(str.equals(word)) ans = cnt;
        cnt++;
        if(k == 5) {
            return;
        }
        
        for(int i=0; i<5; i++) {
            arr[k] = chars[i];
            func(k+1, word);
            arr[k]='X';
        }
    }
    
    
    public int solution(String word) { 
        int answer = 0;
        ans = 0;
        cnt = 0;
        arr = new char[]{'X', 'X', 'X', 'X', 'X'};
        func(0, word);
        return ans;
    }
}