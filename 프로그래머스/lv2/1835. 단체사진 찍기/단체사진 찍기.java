import java.util.*;

class Solution {
    static class Kakao {
        char c;
        int diff;
        char op;
        
        Kakao(char c, char op, int diff) {
            this.c=c;
            this.diff=diff;
            this.op=op;
        }
    }
    
    public int get(char c) {
        if(c=='A') return 0;
        if(c=='C') return 1;
        if(c=='F') return 2;
        if(c=='J') return 3;
        if(c=='M') return 4;
        if(c=='N') return 5;
        if(c=='R') return 6;
        else return 7;
    }
    
    public void func(int k) {
        if(k==8) {
            ans++;
            return;
        }
        
        for(int i=0; i<8; i++) {
            int index = get(chars[i]);
            if(isused[index]>=0) continue;
            List<Kakao> list = arr[index];
            boolean isPossible=true;
            for(Kakao kakao : list) {
                int cIndex = get(kakao.c);
                if(isused[cIndex]==-1) continue;

                int diff = Math.abs(k-isused[cIndex])-1;

                if(kakao.op=='=') {                          
                    if(diff!=kakao.diff) {
                        isPossible=false;
                        break;
                    }
                }
                else if(kakao.op=='>') {
                    if(diff<=kakao.diff) {
                        isPossible=false;
                        break;
                    }
                }
                else if(kakao.op=='<') {
                    if(diff>=kakao.diff) {
                        isPossible=false;
                        break;
                    }
                }
            }
            if(!isPossible) continue;
            
            isused[index]=k;
            func(k+1);
            isused[index]=-1;
        }
        
    }
    
    public List[] arr;
    public int[]res; //디버깅용
    public char[]chars=new char[]{'A', 'C','F','J','M','N','R','T'};
    public int ans;
    public int[]isused; //쓰인 인덱스 저장
    public int solution(int n, String[] data) {
        int answer = 0;
        ans=0;
        arr=new ArrayList[8];
        isused=new int[8];
        
        for(int i=0; i<8; i++) {
            isused[i]=-1;
            arr[i]=new ArrayList<>();
        }
        for(int i=0; i<data.length; i++) {
            String str = data[i];
            char c1 = str.charAt(0);
            char c2 = str.charAt(2);
            char op = str.charAt(3);
            int diff = str.charAt(4)-'0';
            
            Kakao k1 = new Kakao(c1, op, diff);
            Kakao k2 = new Kakao(c2, op, diff);
            arr[get(c2)].add(k1);
            arr[get(c1)].add(k2);
        }
        
        func(0);
        
        return ans;
    }
}