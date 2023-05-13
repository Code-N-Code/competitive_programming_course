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
 
int c[200002];
int res[200001];
vi ar[200002];
set<int> *st[200001];
 
void dfs(int node, int par)
{
	int mx = 0;
	int mxNode = -1;
	
	for(int child : ar[node])
	if(child != par)
	{
		dfs(child , node);
		if( st[child]->size() > mx )
		mx = st[child]->size() , mxNode = child;
	}
	
	if(mxNode == -1) st[node] = new set<int>();
	else			 st[node] = st[mxNode];
	
	st[node] -> insert(c[node]);
	
	for(int child : ar[node])
	if(child != par && child != mxNode)
	{
		for(int color : *st[child])
		st[node]->insert(color);
	}
	
	res[node] = st[node] -> size();
}
 
int main()
{
	int n , a , b;
	cin>>n;
	REP(i , n) cin>>c[i];
	
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	dfs(1 , -1);
	
	REP(i , n) cout<<res[i]<<" ";
}
 
