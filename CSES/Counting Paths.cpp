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
int res[200001];
int level[200001];
int forNode[200001];
int forChild[200001];
int n;

void dfs(int node , int par , int lvl)
{
	level[node] = lvl;
	dp[node][0] = par;
	
	for(int child : ar[node])
	if(child != par)
	dfs(child , node , lvl + 1);
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

void update(int node ,int par , int sum)
{
	sum += forNode[node];
	res[node] = sum;
	
	for(int child : ar[node])
	if(child != par)
	{
		update(child , node , sum - forChild[node]);
	}
}

int main()
{
	int q , a , b , m;
	cin>>n>>m;
	
	memset(dp , -1 , sizeof dp);
	for(int i=2;i<=n;i++) cin>>a>>b ,ar[b].pb(a) , ar[a].pb(b);
	
	dfs(1 , -1 , 0);
	preprocess();
	
	while(m--)
	{
		cin>>a>>b;
		
		int lca = LCA(a , b);
		
		if(lca == a)
		{
			forNode[a]++;
			forChild[b]++;
		}
		else
		if(lca == b)
		{
			forNode[b]++;
			forChild[a]++;
		}
		else
		{
			forNode[lca]++;
			forChild[a]++;
			forChild[b]++;
		}
	}
	
	update(1 , -1 , 0);
	
	REP(i , n) cout<<res[i]<<" ";
}


