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
 
int sub[200001];
int n;
vi ar[200001];
 
void subSize(int node ,int par)
{
	sub[node] = 1;
	
	for(int child : ar[node])
	if(child != par)
	{
		subSize(child , node);
		sub[node] += sub[child];
	}
}
 
int centroid(int node , int par)
{
	for(int child : ar[node])
	if(child != par && sub[child] > n/2) return centroid(child , node);
	
	return node;
}
 
int main()
{
	int a , b;
	cin>>n;
	
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	subSize(1 , -1);
	cout<<centroid(1 , -1);
}
 
