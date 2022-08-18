#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int

/*vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> res;
	for(int i=0;i<nums.size();++i)
	{
		int curProd=1;
		for(int j=0;j<nums.size();++j)
		{
			if(i==j)
				continue;
			curProd=curProd*nums[j];
		}
		res.push_back(curProd);
	}
	return res;
}*/

/*vector<int> productExceptSelf(vector<int>& nums) {
	int n=nums.size();
	vector<int> prefixProd(n,1),suffixProd(n,1);
	int curProd=1;
	for(int i=1;i<n;++i)
	{
		curProd=curProd*nums[i-1];
		prefixProd[i]=curProd;
	}
	curProd=1;
	for(int i=n-2;i>=0;--i)
	{
		curProd=curProd*nums[i+1];
		suffixProd[i]=curProd;
	}
	vector<int> res;
	for(int i=0;i<n;++i)
	{
		res.push_back(prefixProd[i]*suffixProd[i]);
	}
	return res;
}*/

vector<int> productExceptSelf(vector<int>& nums) {
	int n=nums.size();
	vector<int> res(n,1);
	int curProd=1;
	for(int i=1;i<n;++i)
	{
		curProd=curProd*nums[i-1];
		res[i]=curProd;
	}
	curProd=1;
	for(int i=n-1;i>=0;--i)
	{
		res[i]=curProd*res[i];
		curProd=curProd*nums[i];
	}
	return res;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n;
       cin>>n;
       vector<int> v(n);
       for(auto& i:v)
       		cin>>i;
       vector<int> res=productExceptSelf(v);
       for(auto i:res)
       		cout<<i<<" ";
       cout<<"\n";
}