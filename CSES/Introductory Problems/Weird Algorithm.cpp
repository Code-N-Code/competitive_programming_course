/*
 * Problem Name : Weird Algorithm
 * Problem Link : https://cses.fi/problemset/task/1068
 * Video solution link : NA
 * Write here if video solution doesn't exist : icodencode@gmail.com
 * Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
 */


#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	while(true){
		cout<<n<<" ";
		
		if(n == 1) break;
 
		if(n % 2) n = 3*n + 1;
		else	  n = n / 2;
	}
}
