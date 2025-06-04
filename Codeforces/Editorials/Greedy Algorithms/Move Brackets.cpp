/*
 * Problem Name : C. Move Brackets
 * Problem Link : https://codeforces.com/problemset/problem/1374/C
 * Video solution link : https://youtu.be/g6HhBoXv50I
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
char ar[1000001];
int n;

int getAns()
{
	stack<char> st;
	
	REP(i , n)
	{
		if(ar[i] == '(')
		st.push('(');
		else
		{
			if(!st.empty() && st.top() == '(') st.pop();
			else
			st.push(')');
		}
	}
	
	return st.size();
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		REP(i , n) cin>>ar[i];
		
		cout<<(getAns())/2<<endl;
	}
}
