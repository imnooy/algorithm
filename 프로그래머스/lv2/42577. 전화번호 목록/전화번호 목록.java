import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        for(int i=1; i<phone_book.length; i++) {
            if(phone_book[i].contains(phone_book[i-1]) && phone_book[i].indexOf(phone_book[i-1])==0) return false;
        }
        return answer;
    }
}