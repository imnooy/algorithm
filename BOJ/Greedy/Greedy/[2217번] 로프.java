
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
/*
 * BJ_2217번_로프_김윤미
 */
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		int n=Integer.parseInt(br.readLine());
		
		int []arr=new int[n];
		for(int i=0; i<n; i++) {
			arr[i]=Integer.parseInt(br.readLine());
		}
		
		int max=Integer.MIN_VALUE;
		
		Arrays.sort(arr);
		
		for(int i=0; i<n; i++) {
			max=Math.max(max, arr[i]*(n-i));
		}
		
		System.out.println(max);
	}

}
