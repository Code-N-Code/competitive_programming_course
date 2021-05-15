#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

vi ar[200001];
int f[200001];
int g[200001];

void dfs(int node , int par)
{
	int a = 0;
	
	for(int child : ar[node])
	if(child != par)
	{
		dfs(child , node);
		g[node] += max(f[child] , g[child]);
	}
	
	for(int child : ar[node])
	if(child != par)
	{
		f[node] = max(f[node] , g[node] - max(f[child] , g[child]) + g[child] + 1);
	}
}

int main()
{
	int n , a , b;
	cin>>n;
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	dfs(1 , -1);
	cout<<max(f[1] , g[1]);
}


