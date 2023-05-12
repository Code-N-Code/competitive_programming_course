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
int d;
 
void dfs(int node ,int par)
{
	vi childList;
	
	for(int child : ar[node])
	if(child != par)
	{
		dfs(child , node);
		f[node] = max(f[node] , f[child] + 1);
		childList.pb(f[child]);
	}
	
	d = max(d , f[node]);
	
	sort(childList.begin() , childList.end());
	if(childList.size() >= 2)
	{
		g[node] = 2 + childList[childList.size()-1] + childList[childList.size()-2];
		d = max(d , g[node]);
	}
}
 
int main()
{
	int n , a , b;
	cin>>n;
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	dfs(1 , -1);
	
	cout<<d;
}
 
