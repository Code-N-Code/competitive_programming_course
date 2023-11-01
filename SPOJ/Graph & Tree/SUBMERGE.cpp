#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> adj[N+1];
bool vis[N+1];
bool isArticulationPoint[N+1];
int in[N+1] , low[N+1];
int timer;
int result;

void clear(int n){
	for(int i=1;i<=n;i++){
		adj[i].clear();
		vis[i] = isArticulationPoint[i] = false;
	}
	timer = result = 0;
}

void dfs(int node , int par){
	vis[node] = true;
	in[node] = low[node] = timer++;
	int child = 0;

	for(int v : adj[node]){
		if(v == par) continue;

		if(vis[v]){
			low[node] = min(low[node] , in[v]);
		}else{
			child++ , dfs(v , node);
			if(par != -1 && low[v] >= in[node]){
				if(isArticulationPoint[node] == false){
					isArticulationPoint[node] = true;
					result++;
				}
			}
			low[node] = min(low[node] , low[v]);
		}
	}

	if(par == -1 && child > 1){
		if(isArticulationPoint[node] == false){
			isArticulationPoint[node] = true;
			result++;
		}
	}

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt" , "r" , stdin);
		freopen("output.txt" , "w" , stdout);
	#endif

	int n , m;
	int a , b;

	while(1){
		cin>>n>>m;
		if(n == 0 && m == 0) break;

		clear(n);

		for(int i=1;i<=m;i++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs(1 , -1);
		cout<<result<<"\n";
	}
}