/*
 * Problem Name : Missing Number
 * Problem Link : https://cses.fi/problemset/task/1083/
 * Video solution link : NA
 * Write here if video solution doesn't exist : icodencode@gmail.com
 * Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ll n, tmp;
	cin>>n;
	
	ll res = (n * (n + 1))/2;
	
	for(int i=1;i<n;i++) cin>>tmp, res -= tmp;
	
	cout<<res;
}
