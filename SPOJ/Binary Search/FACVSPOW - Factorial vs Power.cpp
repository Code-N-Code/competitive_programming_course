#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int
#define vi vector<int>
#define pb push_back
using namespace std;

void _fast()
{
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
}

double ar[10000001];
double H(int a , int n)
{
	double ans = ar[n]/log(a);
	return ans - n;
}

int bsearch(int base)
{
	int low =1;
	int high = 10000000;
	int mid;
	
	while(low<=high)
	{
		mid = (low+high)/2;
		
		double p = H(base , mid);
		double q = H(base , mid-1);
		
		//cout<<mid<<','<<p<<','<<q<<'\n';
		//cout<<mid<<',';
		if(p>0 && q<=0)
		return mid;
		
		if(p> 0)
		high = mid-1;
		
		else
		low = mid+1;
	}
	
	return 1;
}

void generate()
{
	ar[0] = 0;
	for(int i=1;i<=10000000;i++)
	ar[i] = ar[i-1] + log(i);
}
int main()
{
	//_fast();
	int t, a;
	cin>>t;
	generate();
	while(t--)
	{
		cin>>a;
		
		cout<<bsearch(a)<<'\n';
	}
}
