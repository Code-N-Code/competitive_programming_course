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
int res[200001];
int x , y;
int mx;

void find_a(int node ,int par , int dist)
{
	if(dist >= mx) mx = dist , x = node;
	
	for(int child : ar[node])
	if(child != par)
	{
		find_a(child , node , dist + 1);
	}
}

void find_b(int node ,int par , int dist)
{
	if(dist >= mx) mx = dist , y = node;
	res[node] = max(res[node] , dist);
	
	for(int child : ar[node])
	if(child != par)
	{
		find_b(child , node , dist + 1);
	}
}

void dfs(int node , int par , int dist)
{
	res[node] = max(res[node] , dist);
	
	for(int child : ar[node])
	if(child != par)
	{
		dfs(child , node , dist + 1);
	}
}

int main()
{
	int n , a , b;
	cin>>n;
	
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	find_a(1 , -1 , 0);
	find_b(x , -1 , 0);
	dfs(y , -1 , 0);
	
	REP(i , n) cout<<res[i]<<" ";
}


