/*
 * Problem Name : POLYMUL - Polynomial Multiplication
 * Problem Link : https://www.spoj.com/problems/POLYMUL/
 * Video solution link : 
 * Write here if video solution doesn't exist : icodencode@gmail.com
 * Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
 */


#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define mod 1000000007
using namespace std;

// complex # = a + ib
using cd = complex<double>;
const double PI = acos(-1);

vector<cd> fft(vector<cd> p, int n) {
	if(n == 1) return p;
	
	vector<cd> Pe, Po;
	
	for(int i=0; 2*i<n;i++){
		Pe.push_back(p[2*i]);
		Po.push_back(p[2*i + 1]);
	}
	
	Pe = fft(Pe, n/2);
	Po = fft(Po, n/2);
	
	double ang = (2 * PI) / n;
	
	// w^0 = 1 + 0i
	// w^1 = cos(ang) + isin(ang)
	cd w(1), w_delta(cos(ang), sin(ang));
	
	for(int i=0; i< n/2;i++){
		p[i] = Pe[i] + w * Po[i];
		p[i + n/2] = Pe[i] - w * Po[i];
		
		w *= w_delta;
	}
	
	return p;
}

vector<cd> inversefft(vector<cd> p, int n) {
	if(n == 1) return p;
	
	vector<cd> Pe, Po;
	
	for(int i=0; 2*i<n;i++){
		Pe.push_back(p[2*i]);
		Po.push_back(p[2*i + 1]);
	}
	
	Pe = inversefft(Pe, n/2);
	Po = inversefft(Po, n/2);
	
	double ang = (-2 * PI) / n;
	
	// w^0 = 1 + 0i
	// w^1 = cos(ang) + isin(ang)
	cd w(1), w_delta(cos(ang), sin(ang));
	
	for(int i=0; i < n/2;i++){
		p[i] = (Pe[i] + w * Po[i]);
		p[i + n/2] = (Pe[i] - w * Po[i]);
		
		w *= w_delta;
	}
	
	return p;
}

vector<long> multiply(vector<int> &a, vector<int> &b) {
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	
	// finding nearest power of 2.
	int n = 1;
	while(n < a.size() + b.size()) n <<= 1;
	fa.resize(n), fb.resize(n);
	
	// Evaluating Polynomials.
	fa = fft(fa, n);
	fb = fft(fb, n);
	
	// Multiplying Polynomials.
	for(int i=0;i<n;i++) fa[i] *= fb[i];
	
	// Converting value form to coefficient form.
	fa = inversefft(fa, n);
	
	vector<long> res(n);
	for(int i=0;i<n;i++) res[i] = round(fa[i].real() / n);
	
	return res;
}

int  main(){
	int n, t;
	
	cin>>t;
	
	while(t--){
		cin>>n;
		vector<int> a(n+1), b(n+1);
		
		for(int i=0;i<=n;i++) cin>>a[i];
		for(int i=0;i<=n;i++) cin>>b[i];
		
		vector<long> res = multiply(a, b);
		
		for(int i=0;i<=2*n;i++) cout<<res[i]<<" ";
		cout<<endl;
	}
}
