// Problem Name : Longest Flight Route
// Problem Link : https://cses.fi/problemset/task/1680
// Video solution link : 
// Write here if video solution doesn't exist : icodencode@gmail.com
// Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;
bool vis[200001];
vi adj[200001];
int dp[200001];
int next_node[200001] , n;

void dfs(int node){
	vis[node] = true;
	
	for(int v : adj[node]){
		if(vis[v] == false) dfs(v);
		
		if((dp[v] != -1) && (dp[v] + 1 > dp[node])){
			dp[node] = dp[v] + 1;
			next_node[node] = v;
		}
	}
}
int  main(){
	int m , a , b;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) dp[i] = -1;
	dp[n] = 1;
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	dfs(1);
	
	if(dp[1] == -1){
		cout<<"IMPOSSIBLE";
	}else{
		cout<<dp[1]<<"\n";
	
		int node = 1;
		while(node){
			cout<<node<<" ";
			node = next_node[node];
		}
	}
	
}
