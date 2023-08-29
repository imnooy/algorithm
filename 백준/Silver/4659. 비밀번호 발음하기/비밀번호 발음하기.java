import java.util.*;
import java.io.*;


public class Main
{
    public static boolean one(String str) {
        if(str.indexOf("a") < 0 && str.indexOf("e") < 0 
            && str.indexOf("i") < 0 && str.indexOf("o") < 0
             && str.indexOf("u") < 0) {
                 return false;
        }
        return true;
    }

    public static boolean two(String str) {
        String tmp = str.replaceAll("([aeiou]{3,})|([^aeiou]{3,})", "0");
        if(tmp.indexOf("0") >= 0) return false;
        return true;
    }

    public static boolean three(String str) {
        String tmp = str.replaceAll("ee", "1");
        tmp = tmp.replaceAll("oo", "1");

        tmp = tmp.replaceAll("([a-z])\\1", "0");
        // System.out.println(str + " " + tmp + " ");
        if(tmp.indexOf("0") >= 0) return false;
        return true;
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true) {
            String str = br.readLine();
            if(str.equals("end")) break;
            sb.append("<" + str + "> is ");

            if(one(str) && two(str) && three(str)) {
                sb.append("acceptable.");
            }
            else {
                sb.append("not acceptable.");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}