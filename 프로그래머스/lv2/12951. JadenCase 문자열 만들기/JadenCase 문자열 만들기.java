import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] toArr = s.split(" ");
        List<String> strs = new ArrayList<>();
        
        for(String str : toArr) {
            strs.add(str);
        }
        
        String blankStr = "";
        if(s.charAt(s.length() - 1) == ' ') {
            int index = s.length() - 1;
            while(s.charAt(index) == ' ') {
                blankStr += " ";
                index--;
            }
            blankStr = blankStr.substring(1);
            strs.add(blankStr);
        }
        
        for(String str : strs) {
            String toJaden = str.toLowerCase();
            toJaden = toJaden.replaceAll(" ", "");
            
            if(toJaden.equals("")) {
                answer += (str + " ");
                continue;
            }
            String firstStr = toJaden.substring(0, 1);
            firstStr = firstStr.toUpperCase();
            if(toJaden.length() == 1) toJaden = firstStr;
            else toJaden = firstStr + toJaden.substring(1);
            answer += (toJaden + " ");
        }
        answer = answer.substring(0, answer.length()-1);
        
        return answer;
    }
}