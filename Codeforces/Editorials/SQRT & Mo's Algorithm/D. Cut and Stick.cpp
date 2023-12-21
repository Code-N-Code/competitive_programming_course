/*
 * Problem Name : D. Cut and Stick
 * Problem Link : https://codeforces.com/contest/1514/problem/D
 * Video solution link : https://youtu.be/zNadd6gLuAA
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
#define BLOCK 555
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;
struct query{
	int l;
	int r;
	int i;
};
query Q[300001];
int ar[300001] , ans[300001];
int fre[300001];

int freOfFre[300001];
int currMax = 0;
 
bool comp(query a , query b)
{
	if(a.l / BLOCK != b.l/BLOCK)
	return a.l/BLOCK < b.l/BLOCK;
	
	return a.r < b.r;
}

void add(int pos)
{
	int preF = fre[ar[pos]];
	fre[ar[pos]]++;
	int currF = fre[ar[pos]];
	
	freOfFre[preF]--;
	freOfFre[currF]++;
	
	if(currF > currMax)
	{
		currMax = currF;
	}
}
 
void remove(int pos)
{
	int preF = fre[ar[pos]];
	fre[ar[pos]]--;
	int currF = fre[ar[pos]];
	
	freOfFre[preF]--;
	freOfFre[currF]++;
	
	if(currF < currMax)
	{
		while(freOfFre[currMax] == 0)
		currMax--;
	}
}
 
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n , q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	
	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i = i , Q[i].l-- , Q[i].r--;
	}
	
	sort(Q , Q+q , comp);
	int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
		
		while(ML > L)
		ML-- , add(ML);
		
		while(MR < R)
		MR++ , add(MR);
		
		while(ML < L)
		remove(ML) , ML++;
		
		while(MR > R)
		remove(MR) , MR--;
		
		int total = Q[i].r - Q[i].l + 1;
		int rem = total - currMax;
		int half = (total+1)/2;
		
		if(currMax <= half)
		ans[Q[i].i] = 1;
		else
		{
			ans[Q[i].i] = total - 2*rem;
		}
	}
	
	for(int i=0;i<q;i++)
	cout<<ans[i]<<'\n';
}