/*
 * Problem Name : C. RationalLee
 * Problem Link : https://codeforces.com/contest/1369/problem/C
 * Video solution link : https://youtu.be/QCzl0XwwKhE
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
lli ar[200001] , br[200001];
int main()
{
	int t , n , k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		REP(i , n) cin>>ar[i];
		REP(i , k) cin>>br[i];
		
		sort(ar+1 , ar+n+1);
		sort(br+1 , br+k+1);
		
		lli res = 0;
		int i = 1;
		int j = n;
		int p = 1;
		
		while(p <= k && br[p] == 1)
		res += 2 * ar[j] , j-- , p++;
		
		for(int q=k;q>=p;q--)
		{
			res += ar[j] + ar[i];
			j-- , i++ , br[q] -= 2;
			
			while(br[q] > 0)
			i++ , br[q]--;
		}
		
		cout<<res<<endl;
	}
}
