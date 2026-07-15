/*
 * Problem Name : Repetitions
 * Problem Link : https://cses.fi/problemset/task/1069
 * Video solution link : NA
 * Write here if video solution doesn't exist : icodencode@gmail.com
 * Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
 */

#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define mod 1000000007
using namespace std;
 
int  main(){
	string st;
	cin>>st;
	
	int res = 0;
	int l = 0;
	char ch = '~';
	
	for(char c: st) {
		if(c == ch) {
			l++;
		} else {
			res = max(res, l);
			ch = c;
			l = 1;
		}
	}
	
	cout<<max(res, l);
}
