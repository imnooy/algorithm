import java.util.*;

class Solution {
    int N; //n
    int []arr; //stations
    int W; //w
    int curIndex; //현재 설치되어있는 기지국 중 보고있는 배열 인덱스
    int curNum; //지금 보고있는 기지국 번호
    
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        N=n;
        arr=new int[stations.length];
        curIndex=0;
        for(int i=0; i<stations.length; i++) arr[i]=stations[i];
        W=w;
        curNum=arr[curIndex]+w+1;
        
        while(curNum<=N) {
            if(curIndex<stations.length-1) {
                if(curNum<arr[curIndex+1]-w) { //다음 기지국으로 못 닿음
                    answer++; //설치하고..
                    curNum+=((2*w)+1);
                }
                else {
                    curNum=(arr[curIndex+1]+w+1);
                    curIndex++;
                }
            }
            else {
                answer++; //설치하고..
                curNum+=((2*w)+1);
            }
        }
        
        curNum=arr[0]-w-1;
        //앞에 설치해주기
        while(curNum>=1) {
            answer++;
            curNum-=(2*w+1);
        }

        return answer;
    }
}
