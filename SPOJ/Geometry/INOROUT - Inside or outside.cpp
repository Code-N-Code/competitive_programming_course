#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

ll orientation(ll x1 , ll y1 , ll x2 , ll y2 , ll x3 , ll y3){
	ll o = (x3 - x2) * (y2 - y1) - (y3 - y2) * (x2 - x1);
 
	return o;
}

ll x[1001] , y[1001];

int  main(){
	int n , q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	
	while(q--){
		int a , b;
		cin>>a>>b;
		
		bool flag = true;
		
		for(int i=0;i<n;i++){
			ll o = orientation(x[i] , y[i] , x[(i+1)%n] , y[(i+1)%n] , a , b);
			if(o > 0){
				flag = false;
				break;
			}
		}
		
		if(flag) cout<<"D\n";
		else     cout<<"F\n";
	}
}
