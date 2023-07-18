import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[]arr=s.split(" ");
        Arrays.sort(arr, new Comparator<>() {
            @Override
            public int compare(String str1, String str2) {
                int a = Integer.valueOf(str1);
                int b = Integer.valueOf(str2);
                return a-b;
            }
        });
        answer=arr[0]+" "+arr[arr.length-1];
        return answer;
    }
}