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

       ll t;
       cin>>t;
       while(t--)
       {
       		ull n;
       		cin>>n;
       		ull min,max;
       		ull m=n;
       		if(m%2!=0 || m==2)
       		{
       			cout<<"-1\n";
       			continue;
       		}
       		if(n==4 || n==6)
       		{
       			cout<<"1 1\n";
       			continue;
       		}
       		if(n<6)
       		{
       			cout<<"-1\n";
       		}
       		if(m%4==0 || m%4==2)
       		{
       			max=m/4;
       		}
       		else
       		{
       			max=-1;
       		}
       		if(m%6==0)
       		{
       			min=m/6;
       		}
       		else if(m%6==2)
       		{
       			min=(m/6)+1;
       		}
       		else if(m%6==4)
       		{
       			min=(m/6)+1;
       		}
       		else
       			min=-1;
       		cout<<min<<" "<<max<<"\n";

       }
}
