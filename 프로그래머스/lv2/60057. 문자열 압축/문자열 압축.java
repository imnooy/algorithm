class Solution {
    public int solution(String s) {
        int answer = s.length();
        
        for(int i=1; i<=s.length()/2; i++) { //자를 문자열 개수
            String str = ""; //압축한 문자열이다
            String before = s.substring(0, i);
            int cnt = 0; //같은 문자열 개수 찾음
            int lastIndex = 0;
            for(int j=i; j<=s.length() - i; j+=i) {
                String split = s.substring(j, j+i);
                lastIndex = j+i;
                if(before.equals(split)) {
                    cnt++;
                }
                else {
                    if(cnt > 0) {
                        str += ((cnt+1) + before);
                    }
                    else {
                        str += before;
                    }
                    before = split;
                    cnt = 0;
                }
            }
            if(cnt > 0) {
               str += ((cnt+1) + before);
            }
            else {
                str += before;
            }
            str += s.substring(lastIndex);
            answer = Math.min(answer, str.length());
        }
        
        return answer;
    }
}