import java.util.*;
import java.io.*;


public class Main
{
    static int [] dx = {-1, 0, 1, 0}; //위 오 밑 왼
    static int [] dy = {0, 1, 0, -1};
    static int minX, minY, maxX, maxY, nowX, nowY;
    static int dir; //현재 방향

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        StringBuilder sb = new StringBuilder();
        for(int t = 1; t <= T;t++) {
            minX = 0;
            minY = 0;
            maxX = 0;
            maxY = 0;
            nowX = 0;
            nowY = 0;
            
            String str = br.readLine();
            
            for(int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                
                if(c == 'F') {
                    nowX = nowX + dx[dir];
                    nowY = nowY + dy[dir];
                }
                else if(c == 'B') {
                    nowX = nowX - dx[dir];
                    nowY = nowY - dy[dir];
                }
                else if(c == 'L') {
                    dir = (dir + 3) % 4;
                }
                else if(c == 'R') {
                    dir = (dir + 1) % 4;
                }
                
                minX = Math.min(minX, nowX);
                minY = Math.min(minY, nowY);
                maxX = Math.max(maxX, nowX);
                maxY = Math.max(maxY, nowY);
            }
            sb.append((Math.abs(minX)+Math.abs(maxX))*(Math.abs(minY)+Math.abs(maxY))+"\n");
        }
        System.out.println(sb.toString());
    }
}