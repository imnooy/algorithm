
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
/*
 * BJ_1931_회의실배정_김윤미
 */
class Pair{
	int start;
	int end;
	
	Pair(int start, int end) {
		this.start=start;
		this.end=end;
	}
}

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		int n=Integer.parseInt(br.readLine());
		List<Pair> list=new ArrayList<>();
		for(int i=0; i<n; i++) {
			String []str=br.readLine().split(" ");
			int start=Integer.parseInt(str[0]);
			int end=Integer.parseInt(str[1]);
			list.add(new Pair(start, end));
		}
		
		//최대한 끝나는 시간이 빨라야 다음 작업이 빨리 시작할 수 있다.
		Collections.sort(list, new Comparator<Pair>() { //빨리 끝나는 걸 앞으로
			@Override
			public int compare(Pair o1, Pair o2) {
				Integer num1=Integer.valueOf(o1.end);
				Integer num2=Integer.valueOf(o2.end);
				int ans=num1.compareTo(num2);
				if(ans==0) {
					ans=Integer.valueOf(o1.start).compareTo(Integer.valueOf(o2.start));
				}
				return ans;
			}
		});
		
		int cnt=1;
		int endPoint=list.get(0).end;
		for(int i=1; i<n; i++) {
			if(list.get(i).start>=endPoint) {
				endPoint=list.get(i).end;
				cnt++;
			}
		}
		
		System.out.println(cnt);
	}

}
