class Solution {
    
    public String solution(int n) {
        String answer = "";
        int[]arr=new int[]{4, 1, 2};
        StringBuilder sb=new StringBuilder();
        while(n>0) {
            int r=n%3;
            n/=3;

            if(r==0) n--; //나누어떨어지면 하나 빼야함...
            sb.append(arr[r]);
        }
        
        return sb.reverse().toString();
    }                                         
}