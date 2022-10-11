import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, d, k, c;
    static int[]arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        n= Integer.parseInt(st.nextToken()); //접시 수
        d= Integer.parseInt(st.nextToken()); //초밥 가짓 수
        k= Integer.parseInt(st.nextToken()); //연속해서 먹는 접시의 수
        c= Integer.parseInt(st.nextToken()); //쿠폰 번호

        int []num=new int[d+1];

        arr=new int[n];

        for(int i=0; i<n; i++) {
            arr[i]= Integer.parseInt(br.readLine());
        }

        int ans=1; //이미 쿠폰 먹었다
        num[c]=1; //쿠폰 씀

        for(int i=0; i<k; i++) { //일단 k개 보기
            if(num[arr[i]]==0) ans++;
            num[arr[i]]++;
        }

        int start=0;
        int end=k;
        int cnt=ans;

        for(int i=end; i<n+k-1; i++) { //원형 큐처럼 도니까 끝나는 범위를 최대 (n+k-1)까지
            int index=i;
            num[arr[start]]--; //시작점 초밥 뱉음
            if(num[arr[start]]==0) { //윈도우에 없을 때만
                cnt--; //윈도우에 없음 -> 개수 조정
            }

            if(i>=n) index-=n; //end 범위 조정 (원형 큐처럼 처음으로 갈 때 대비)
            if(num[arr[index]]==0) cnt++; //새로운 초밥
            num[arr[index]]++; //새로운 초밥 먹음

            ans=Math.max(ans, cnt);
            start++; //슬라이딩 윈도우 시작점 조정
        }

        System.out.println(ans);
    }
}
