import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        // str = str.replaceAll("[0-9!@@#$%^&~`*())_+?></,.= ]", "");
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();
        for(int i = 0; i < str1.length() - 1; i++) {
            String substr = str1.substring(i, i + 2);
            substr = substr.replaceAll("[0-9!:;@#$%^&~`*())_+?></,.= ]", "");
            substr = substr.toLowerCase();
            if(substr.length() < 2) continue;
            
            if(map1.containsKey(substr)) {
                map1.put(substr, map1.get(substr) + 1);
            }
            else map1.put(substr, 1);
        }
        
        for(int i = 0; i < str2.length() - 1; i++) {
            String substr = str2.substring(i, i + 2);
            substr = substr.replaceAll("[0-9!@#$%:;^&~`*())_+?></,.= ]", "");
            substr = substr.toLowerCase();
            if(substr.length() < 2) continue;
            
            if(map2.containsKey(substr)) {
                map2.put(substr, map2.get(substr) + 1);
            }
            else map2.put(substr, 1);
        }
        
        int inner = 0;  //교집합
        int sum = 0; //합집합
        for(String key : map2.keySet()) {
            if(map1.containsKey(key)) {
                inner += Math.min(map1.get(key), map2.get(key));
                sum += Math.abs(map1.get(key) - map2.get(key));
            }
            else {
                //map2에만 있을 때 -> 차집합
                sum += map2.get(key);
            }
        }
        
        for(String key : map1.keySet()) {
            if(!map2.containsKey(key)) {
                sum += map1.get(key);
            }
        }
        
        sum += inner; //합집합 크기
        
        if(inner == sum) return 65536;
        
        double similarity = (double) inner / (double) sum;
        answer = (int)(similarity * 65536.0);
        
        return answer;
    }
}