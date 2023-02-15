// Problem Name : Longest Flight Route
// Problem Link : https://cses.fi/problemset/task/1680
// Video solution link : 
// Write here if video solution doesn't exist : icodencode@gmail.com
// Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define mod 1000000007

using namespace std;
bool vis[100001];
vi adj[100001];
int dp[100001];
ll result , n;

void dfs(int node){
	vis[node] = true;
	
	for(int v : adj[node]){
		if(vis[v] == false) dfs(v);
		
		dp[node] = (dp[node] + dp[v]) % mod;
	}
}

int  main(){
	int m , a , b;
	cin>>n>>m;
	
	dp[n] = 1;
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	dfs(1);
	
	cout<<dp[1];	
}
