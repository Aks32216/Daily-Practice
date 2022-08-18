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
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int a1,a2,k1,k2,n;
       cin>>a1>>a2>>k1>>k2>>n;
       int val=(k1-1)*a1;
       val+=(k2-1)*a2;
       int mi=0;
       if((n-val)>0)
       {
       		mi=n-val;
       		if(mi>(a1+a2))
       			mi=a1+a2;
       }
       int ma=0;
       int red;
       if(k1>k2)
       {
       		val=k2;
       		red=a2;
       }
       else
       {
       	val=k1;
       	red=a1;
       }
       while(red>0 && n-val>=0)
       {
       		ma++;
       		n=n-val;
       		red--;
       }
      if(k1>k2)
      {
      	val=k1;
      	red=a1;
      }	
      else
      {
      	val=k2;
      	red=a2;
      }
      while(red>0 && n-val>=0)
      {
      	ma++;
      	n=n-val;
      	red--;
      }
      cout<<mi<<" "<<ma<<"\n";
}