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
 
const int N = 200001;
vi tree[N];
 
lli ar[N];
lli temp[N];
 
lli st[2*N];
 
lli sub[N];
lli in[N];
int _timer = 0;
 
void dfs(int node, int par)
{
	sub[node] = 1;
	in[node] = ++_timer;
	ar[in[node]] = temp[node];
	
	for(int child : tree[node])
	if(child != par)
	dfs(child , node) , sub[node] += sub[child];
}
 
void build(int si , int ss , int se)
{
	
	if(ss == se){
		st[si] = ar[ss];
		return;
	}
	
	int mid = (ss + se) >> 1;
	build(2*si , ss , mid);
	build(2*si + 1 , mid+1 , se);
	
	st[si] = st[2*si] + st[2*si + 1];
}
 
void update(int si , int ss , int se , int qi , lli dx)
{
	if(ss > qi || se < qi) return;
	
	if(ss == se)
	{
		st[si] += dx;
		return;
	}
	
	int mid = (ss + se) >> 1;
	update(2*si , ss , mid , qi , dx);
	update(2*si + 1 , mid+1 , se , qi , dx);
	
	st[si] = st[2*si] + st[2*si + 1];
}
 
lli getSum(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si];
	
	int mid = (ss + se) >> 1;
	lli L = getSum(2*si , ss , mid , qs , qe);
	lli R = getSum(2*si + 1 , mid+1 , se , qs , qe);
	
	return L + R;
}
 
int main()
{
	int n , q , a , b , code;
	cin>>n>>q;
	
	REP(i , n) cin>>temp[i];
	REP(i , n-1) cin>>a>>b , tree[a].pb(b) , tree[b].pb(a);
	
	dfs(1 , -1);
	build(1 , 1 , n);
	
	while(q--)
	{
		cin>>code;
		
		if(code == 1) {
			cin>>a>>b;
			update(1 , 1 , n , in[a] , b - ar[in[a]]);
			ar[in[a]] = b;
		}
		else{
			cin>>a;
			cout<<getSum(1 , 1 , n , in[a] , in[a] + sub[a] - 1)<<endl;
		}
	}
}
 
