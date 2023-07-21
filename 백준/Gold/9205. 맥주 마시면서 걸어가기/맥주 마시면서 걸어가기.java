import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int INF=1001;

    static class Pair {
        int x;
        int y;

        Pair (int x, int y) {
            this.x=x;
            this.y=y;
        }
    }

    static int getDis(int x1, int y1, int x2, int y2) {
        return Math.abs(x1-x2)+Math.abs(y1-y2);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int T= Integer.parseInt(br.readLine());
        StringBuilder sb=new StringBuilder();
        for(int t=1; t<=T; t++) {
            int n= Integer.parseInt(br.readLine());
            int dis[][]=new int[n+2][n+2];
            boolean d[][]=new boolean[n+2][n+2];
            Pair []arr=new Pair[n+2];

            for(int i=0; i<n+2; i++) {
                StringTokenizer st=new StringTokenizer(br.readLine());

                int x= Integer.parseInt(st.nextToken());
                int y=Integer.parseInt(st.nextToken());
                arr[i]=new Pair(x, y);
            }

            for(int i=0; i<n+2; i++) {
                Pair p=arr[i];
                for(int j=0; j<n+2; j++) {
                    Pair next=arr[j];

                    dis[i][j]=getDis(p.x, p.y, next.x, next.y);

                    if(dis[i][j]<INF) {
                        d[i][j]=true;
                    }
                }
            }

            for(int k=0; k<n+2; k++) {
                for(int i=0; i<n+2; i++) {
                    for(int j=0; j<n+2; j++) {
                        if(d[i][k] && d[k][j]) {
                            d[i][j]=true;
                        }
                    }
                }
            }

            if(d[0][n+1]) {
                sb.append("happy\n");
            }
            else sb.append("sad\n");
        }

        System.out.println(sb.toString());
    }
}
