//package study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.SortedMap;
import java.util.TreeMap;


public class Main {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
	
		int T=Integer.parseInt(br.readLine());
		
		for(int t=0; t<T; t++) {
			int K=Integer.parseInt(br.readLine());
			SortedMap<Integer, Integer> map=new TreeMap<>(); //오름차순으로 정렬(SortedMap)되는 TreeMap 생성
			
			for(int k=0; k<K; k++) {
				String []str=br.readLine().split(" ");
				
				String command=str[0];
				int n=Integer.parseInt(str[1]);
				
				if(command.equals("I")) {
					if(map.get(n)!=null) {
						map.put(n, map.get(n)+1); //이미 있으면 cnt만 하나 증가
					}
					else map.put(n, 1);
				}
				else if(command.equals("D")) {
					if(!map.isEmpty()) {
						if(n==1) {
							if(map.get(map.lastKey())==1) { //최댓값이 1개
								map.remove(map.lastKey()); //1개면 바로 제거 (lastKey -> 오름차순 정렬 map에서 제일 마지막 key)
							}
							else { //중복값이 있으면
								map.put(map.lastKey(), map.get(map.lastKey())-1); //cnt만 하나 감소
							}
						}
						else if(n==-1) {
							if(map.get(map.firstKey())==1) { //최솟값이 1개
								map.remove(map.firstKey());//1개면 바로 제거 (firstKey -> 오름차순 정렬 map에서 제일 첫번째 key)
							}
							else {//중복값이 있으면
								map.put(map.firstKey(), map.get(map.firstKey())-1); //cnt만 하나 감소
							}
						}
					}
				}
			}
			if(map.isEmpty()) sb.append("EMPTY\n"); //map이 비어있으면 EMPTY 출력
			else { //아니면 최댓값, 최솟값 출력 (key가 값임)
				sb.append(map.lastKey()).append(" ").append(map.firstKey()).append("\n");
			}
		}
		System.out.println(sb.toString());
	}

}
