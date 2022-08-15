
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/*
 * BJ_11047_동전0_김윤미
 */
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		String []str=br.readLine().split(" ");
		
		int n=Integer.parseInt(str[0]);
		int k=Integer.parseInt(str[1]);
		
		int []arr=new int[n];
		for(int i=0; i<n; i++) arr[i]=Integer.parseInt(br.readLine());
		
		int ans=0;
		for(int i=n-1; i>=0; i--) {
			ans+=k/arr[i];
			k%=arr[i];
		}
		System.out.println(ans);
	}

}
