/*
 * Problem Name : AGGRCOW - Aggressive cows
 * Problem Link : https://www.spoj.com/problems/AGGRCOW/
 * Video solution link : https://youtu.be/lLA0BW_f8v0
 * Write here if video solution doesn't exist : icodencode@gmail.com
 * Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
 */

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
int ar[100001];
 
bool isValid(int mid , int C , int n)
{
	int cnt = 0;
	int pre = -INF;
	
	for(int i=1;i<=n;i++)
	if(ar[i] - pre >= mid)
	cnt++ , pre = ar[i];
	
	if(cnt >= C) return true;
	else		 return false;
}
 
int getAns(int n , int c)
{
	int L = 0;
	int H = ar[n] - ar[1];
	
	int ans = 0;
	
	while(L <= H)
	{
		int mid = (L + H) / 2;
		
		if(isValid(mid , c , n))
		ans = max(ans , mid) , L = mid + 1;
		else
		H = mid - 1;
	}
	
	return ans;
}
 
int main()
{
	int t , n , c;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(int i=1;i<=n;i++)
		cin>>ar[i];
		
		sort(ar + 1 , ar + n + 1);
		cout<<getAns(n , c)<<endl;
	}
}
