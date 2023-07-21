//package com.study.BJ_16236_아기상어_김윤미;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
	int x;
	int y;
	
	Pair(int x, int y) {
		this.x=x;
		this.y=y;
	}
}

public class Main {
	
	static int n;
	static int m;
	static int arr[][];
	static int dx[]=new int[] {-1, 0, 1, 0};
	static int dy[]=new int[] {0, 1, 0, -1};
	static int sec=0; //걸린 시간 - 출력값
	static Pair loc; //상어 위치
	static int SIZE=2; //상어 크기
	static boolean isEnd=false; //먹을 물고기 더 없니
	
	static boolean[][]visited; //bfs시 방문 배열
	static int dis[][]; //bfs시 거리 배열
	
	static Pair chooseFish(Pair pair) {
		visited=new boolean[n][n];
		dis=new int[n][n];

		Queue<Pair> q=new ArrayDeque<>();
		q.add(pair);
		visited[pair.x][pair.y]=true;
		
		
		List<Pair> list=new ArrayList<>();
		
		while(!q.isEmpty()) {
			Pair p=q.poll();
			
			for(int d=0; d<4; d++) {
				int nx=p.x+dx[d];
				int ny=p.y+dy[d];
				
				if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
				if(visited[nx][ny]) continue;
				if(SIZE<arr[nx][ny]) continue;
				
				visited[nx][ny]=true;
				dis[nx][ny]=dis[p.x][p.y]+1;
				q.add(new Pair(nx, ny));
				
				if(SIZE>arr[nx][ny] && arr[nx][ny]!=0 && arr[nx][ny]!=9) {
					list.add(new Pair(nx, ny));
				}
			}
		}
		
		if(list.size()==1) return list.get(0);
		if(list.size()==0) {
			isEnd=true;
			return null;
		}
		
		int min=Integer.MAX_VALUE;
		int compx=n;
		int compy=n;
		for(Pair tmp:list) {
			if(dis[tmp.x][tmp.y]<min || (dis[tmp.x][tmp.y]==min && tmp.x<compx) || (dis[tmp.x][tmp.y]==min && tmp.x==compx && tmp.y<compy)) {
				min=dis[tmp.x][tmp.y];
				compx=tmp.x;
				compy=tmp.y;
			}
		}
		return new Pair(compx, compy);
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		n=Integer.parseInt(br.readLine());
		arr=new int[n][n];
		for(int i=0; i<n; i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				
				if(arr[i][j]==9) {
					loc=new Pair(i, j);
				}
			}
		}
		int fishes=0; //먹은 물고기 수
		while(!isEnd) {
			Pair target=chooseFish(loc);
			if(target==null) break;
			
			sec+=dis[target.x][target.y]; //이동
			arr[loc.x][loc.y]=0; //이동
			arr[target.x][target.y]=9; //먹기
			loc.x=target.x;
			loc.y=target.y;
			fishes++; //먹음
			
			if(SIZE==fishes) { //자신의 크기와 같은 수의 물고기 먹을 때
				SIZE++; //크기 1 증가
				fishes=0; //초기화
			}
		}
		System.out.println(sec);
	}

}
