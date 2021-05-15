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
int n;

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

int getKthPar(int node , int k)
{
	int i = maxN - 1;
	
	while(i >= 0)
	{
		if( (1 << i) <= k && (dp[node][i] != -1) )
		node = dp[node][i] , k -= (1 << i);
		
		i--;
	}
	
	if(k > 0) node = -1;
	return node;
}

int main()
{
	int q , a , k;
	cin>>n>>q;
	
	memset(dp , -1 , sizeof dp);
	for(int i=2;i<=n;i++) cin>>a , dp[i][0] = a;
	
	preprocess();
	
	while(q--)
	{
		cin>>a>>k;
		
		cout<<getKthPar(a , k)<<endl;
	}
}


