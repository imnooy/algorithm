package com.study.BJ_1026_보물_김윤미;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
/*
 * BJ_1026_보물_김윤미
 */
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int n=Integer.parseInt(br.readLine());
		
		int[]a=new int[n];
		Integer []b=new Integer[n];
		
		String[]str=br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			a[i]=Integer.parseInt(str[i]);	
		}
		
		str=br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			b[i]=Integer.parseInt(str[i]);	
		}
		
		Arrays.sort(a);
		Arrays.sort(b, Collections.reverseOrder());
		
		int sum=0;
		for(int i=0; i<n; i++) {
			sum+=(a[i]*b[i]);
		}
		System.out.println(sum);
	} 

}
