/*
 * Problem Name : C. Pluses and Minuses
 * Problem Link : https://codeforces.com/problemset/problem/1373/C
 * Video solution link : https://youtu.be/YewVnTMnxaE
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
#define endl '\n'
using namespace std;
int ar[1000001];
map<int,int> mp;

int getCnt(int key)
{
	return mp[key];
}

int main()
{
	lli t , res;
	string st;
	cin>>t;
	while(t--)
	{
		cin>>st;
		mp.clear();
		
		res = 0;
		int mx = 0;
		int cnt = 0;
		for(int i=0;i<st.size();i++)
		{
			char ch = st[i];
			if(ch == '-') cnt--;
			else		  cnt++;
			
			ar[i+1] = cnt;
			if(cnt < 0 && mp.find(cnt) == mp.end()) mp[cnt] = i+1;
			
			mx = min(mx , cnt);
		}
		
		mx *= -1;
		
		for(int i=0;i<mx;i++)
		{
			res += getCnt(-(i+1));
		}
		cout<<res+st.size()<<endl;
	}
}