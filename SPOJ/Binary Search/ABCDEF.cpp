/*
 * Problem Name : ABCDEF
 * Problem Link : https://www.spoj.com/problems/ABCDEF/
 * Video solution link : https://youtu.be/07rX0DjWSdY
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
 
int ar[100];
int main()
{
	int n;
	map<int,int> mp;
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>ar[i];
	
	for(int f=0;f<n;f++)
	{
		for(int e=0;e<n;e++)
		{
			for(int d=0;d<n;d++) {
				if(ar[d] == 0) continue;
				mp[(ar[e] + ar[f]) * ar[d]]++;
			}
		}
	}
	
	lli res = 0;
	
	for(int a=0;a<n;a++)
	{
		for(int b=0;b<n;b++)
		{
			for(int c=0;c<n;c++) res += mp[(ar[a] * ar[b]) + ar[c]];
		}
	}
	
	cout<<res;
	
}
 
