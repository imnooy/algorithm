import java.util.*;
import java.io.*;

public class Main
{
    static String s;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s=br.readLine();
        int toZero = 0;
        int toOne = 0;

        int index = -1;
        char cur = '0';

        while(index<s.length()-1) { //0으로 만들어보기
            index++;
            char c = s.charAt(index);
            if(c=='0') {
                cur = '0';
                continue;
            }
            else {
                if(cur!='1') {
                    cur = '1';
                    toZero++;
                }
            }
        }
        index = -1;
        cur = '1';
        while(index<s.length()-1) { //1으로 만들어보기
            index++;
            char c = s.charAt(index);
            if(c=='1') {
                cur = '1';
                continue;
            }
            else {
                if(cur!='0') {
                    cur = '0';
                    toOne++;
                }
            }
        }

        System.out.println(Math.min(toZero, toOne));
    }
}