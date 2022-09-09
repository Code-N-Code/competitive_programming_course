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
int ar[20] , br[20] , n;
lli dp[20][140][2];

lli getAns(int arr[] , int pos , int sum , int pre)
{
	if(pos > n) return sum;
	
	if(dp[pos][sum][pre] != -1) return dp[pos][sum][pre];
	
	lli res = 0;
	int limit;
	if(pre) limit = 9;
	else	limit = arr[pos];
	
	for(int i=0;i<=limit;i++)
	{
		res += getAns(arr , pos+1 , sum+i , pre || (i < limit));
	}
	
	return dp[pos][sum][pre] = res;
}

lli getDigSum(int arr[])
{
	for(int i=0;i<=n;i++) for(int j=0;j<140;j++) dp[i][j][0] = dp[i][j][1] = -1;
	return getAns(arr ,1 , 0 , 0);
}

int g(int arr[])
{
	int sum = 0;
	for(int i=1;i<=n;i++) sum += arr[i];
	
	return sum;
}

int main()
{
	string a , b;
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b;
		REP(i , a.size()) ar[i] = a[i-1] - '0';
		REP(i , b.size()) br[i] = b[i-1] - '0';
		
		n = b.size();
		lli x = getDigSum(br);
		
		n = a.size();
		lli y = getDigSum(ar);
		
		lli z = g(ar);
		
		cout<<x - y + z<<endl;
	}
}
