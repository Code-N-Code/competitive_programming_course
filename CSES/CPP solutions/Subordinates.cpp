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
int sub[200001];

int dfs(int node)
{
	sub[node] = 1;
	for(int child : ar[node])
	dfs(child) , sub[node] += sub[child];
}

int main()
{
	int n , a , b;
	cin>>n;
	
	for(int i=2;i<=n;i++) cin>>a , ar[a].pb(i);
	dfs(1);
	
	REP(i , n) cout<<sub[i]-1<<" ";
}


