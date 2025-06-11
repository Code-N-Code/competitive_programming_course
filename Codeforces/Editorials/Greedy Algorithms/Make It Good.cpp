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
#define endl '\n'
using namespace std;
int ar[200001];

int getMax1(int n)
{
	int cnt = 1;
	for(int i=n-1;i>=1;i--)
	if(ar[i] <= ar[i+1])
	cnt++;
	else
	break;
	
	return cnt;
}

int getMax2(int n)
{
	int cnt = 1;
	for(int i=n-1;i>=1;i--)
	if(ar[i] >= ar[i+1]) cnt++;
	else
	break;
	
	return cnt;
}

int getMax3(int n)
{
	int cnt = 1;
	
	int i = n-1;
	for(;i>=1;i--)
	{
		if(ar[i] >= ar[i+1]) cnt++;
		else
		break;
	}
	
	for(;i>=1;i--)
	{
		if(ar[i] <= ar[i+1]) cnt++;
		else
		break;
	}
	
	return cnt;
}

int main()
{
	int t , n , mx;
	cin>>t;
	while(t--)
	{
		cin>>n;
		REP(i , n) cin>>ar[i];
		
		mx = 1;
		mx = max(mx , getMax1(n));
		mx = max(mx , getMax2(n));
		mx = max(mx , getMax3(n));
		
		
		cout<<n-mx<<endl;
	}
}
