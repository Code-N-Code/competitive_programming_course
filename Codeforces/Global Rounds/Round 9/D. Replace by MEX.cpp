// Problem Name : D. Replace By MEX
// Problem Link : https://codeforces.com/contest/1375/problem/D
// Video solution link : 
// Write here if video solution doesn't exist : icodencode@gmail.com
// Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

int ar[1000];

int findMex(int n){
	set<int> s(ar + 0 , ar + n);
	
	int mex = 0;
	
	while(s.count(mex)) mex++;
	
	return mex;
}

int getInvalidIndex(int n){
	for(int i=0;i<n;i++) if(ar[i] != i) return i;
	
	return n-1;
}

int  main(){
	int t , n;
	
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>ar[i];
		
		vi result;
		
		for(int i=1;i<=n;i++){
			int mex = findMex(n);
			
			if(mex == n){
				int index = getInvalidIndex(n);
				ar[index] = mex;
				result.push_back(index);
				mex = findMex(n);
			}
			
			ar[mex] = mex;
			result.push_back(mex);
		}
		
		cout<<result.size()<<endl;
		for(int idx : result) cout<<idx + 1<<" ";
		cout<<endl;
	}
}
