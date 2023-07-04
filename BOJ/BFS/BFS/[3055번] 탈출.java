import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;


class Pair{ //좌표 객체
	int x;
	int y;
	
	Pair(int x, int y) {
		this.x=x;
		this.y=y;
	}
}

public class Main {
	
	static int dx[]=new int[] {-1, 0, 1, 0};
	static int dy[]=new int[] {0, 1, 0, -1};
	
	static int R, C;
	static char [][]arr;
	static Pair beaver;
	static Queue<Pair> wq; //물 이동
	static Queue<Pair> hq; //고슴도치 이동
	static boolean[][]visited1;
	static boolean[][]visited2;
	
	static boolean isPossible() {
		for(int d=0; d<4; d++) {
			int nx=beaver.x+dx[d];
			int ny=beaver.y+dy[d];
			
			if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
			
			if(arr[nx][ny]!='*' && arr[nx][ny]!='X') {
				return true;
			}
		}
		
		return false;
	}
	
	static boolean move() {
		int sz=hq.size();
		
		for(int i=0; i<sz; i++) {
			Pair p=hq.poll();
			
			for(int d=0; d<4; d++) {
				int nx=p.x+dx[d];
				int ny=p.y+dy[d];
				
				if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
				if(arr[nx][ny]=='X') continue; //돌 통과 못함
				if(arr[nx][ny]=='*') continue; //물 통과 못함
				if(visited1[nx][ny]) continue;
				
				if(nx==beaver.x && ny==beaver.y) return true;
				
				hq.add(new Pair(nx, ny));
				arr[nx][ny]='S';
				visited1[nx][ny]=true;
			}
		}
		
		return false;
	}
	
	static void bfs() {
		int sz=wq.size();
		
		for(int i=0; i<sz; i++) { //물
			Pair p=wq.poll();
			
			for(int d=0; d<4; d++) {
				int nx=p.x+dx[d];
				int ny=p.y+dy[d];
				
				if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
				if(arr[nx][ny]=='D') continue; //비버의 굴로 물 못감
				if(arr[nx][ny]=='X') continue; //돌 통과 못함
				if(visited2[nx][ny]) continue;
				
				visited2[nx][ny]=true;
				arr[nx][ny]='*';
				wq.add(new Pair(nx, ny));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		R=Integer.parseInt(st.nextToken());
		C=Integer.parseInt(st.nextToken());
		
		wq=new ArrayDeque<>();
		hq=new ArrayDeque<>();
		
		arr=new char[R][C];
		visited1=new boolean[R][C];
		visited2=new boolean[R][C];
		
		for(int i=0; i<R; i++) {
			char[]input=br.readLine().toCharArray();
			for(int j=0; j<C; j++) {
				arr[i][j]=input[j];
				
				if(arr[i][j]=='D') {
					beaver=new Pair(i, j);
				}
				else if(arr[i][j]=='S') {
					hq.add(new Pair(i, j));
				}
				else if(arr[i][j]=='*') {
					wq.add(new Pair(i, j));
				}
			}
		}
		
		int t=0;
		int count=R*C;
		boolean flag=false;
		while(count-->0) {
			t++;
			bfs();
			if(move()) {
				flag=true;
				break;
			}
		}
		
		if(!flag) System.out.println("KAKTUS");
		else System.out.println(t);
	}

}
