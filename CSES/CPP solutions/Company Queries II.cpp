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

const int maxN = 21;
vi ar[200001];
int dp[200001][maxN];
int level[200001];
int n;

void dfs(int node , int lvl)
{
	level[node] = lvl;
	
	for(int child : ar[node])
	dfs(child , lvl + 1);
}

void preprocess()
{
	for(int i=1;i<maxN;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int par = dp[j][i-1];
			
			if(par == -1) continue;
			else
			dp[j][i] = dp[par][i-1];
		}
	}
}

int LCA(int a , int b)
{
	if(level[a] < level[b]) swap(a , b);
	
	int d = level[a] - level[b];
	
	while(d > 0)
	{
		int i = log2(d);
		a = dp[a][i];
		d -= (1 << i);
	}
	
	if(a == b) return a;
	
	for(int i=maxN-1;i>=0;i--)
	if(dp[a][i] != -1 && (dp[a][i] != dp[b][i]))
	{
		a = dp[a][i];
		b = dp[b][i];
	}
	
	return dp[a][0];
}

int main()
{
	int q , a , b;
	cin>>n>>q;
	
	memset(dp , -1 , sizeof dp);
	for(int i=2;i<=n;i++) cin>>a , dp[i][0] = a , ar[a].pb(i);
	
	dfs(1 , 0);
	preprocess();
	
	while(q--)
	{
		cin>>a>>b;
		
		cout<<LCA(a , b)<<endl;
	}
}


