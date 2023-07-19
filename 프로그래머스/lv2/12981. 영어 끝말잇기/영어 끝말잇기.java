import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[]{0, 0};
        List<String> used = new ArrayList<>();
        
        for(int i = 0; i < words.length; i++) {
            if(used.contains(words[i]) || (i > 0 && words[i - 1].charAt(words[i - 1].length() - 1) != words[i].charAt(0))) {
                int person = (i + 1) % n;
                answer[0] = person == 0 ? n : person;
                answer[1] = (i / n) + 1;
                break;
            }
            else used.add(words[i]);
        }

        return answer;
    }
}