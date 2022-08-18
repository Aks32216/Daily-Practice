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
 
 /*bool findPair(int arr[], int size, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<size;++i)
    {
        mp[arr[i]]++;
    }
    int zer=0,count=0;
    for(int i=0;i<size;++i)
    {
        if(mp[arr[i]]>1)
            zer++;
        if(mp[arr[i]+n]>0)
            count++;
    }
    if(n==0)
        return zer==0?false:true;
    else
        return count==0?false:true;
    
}*/

bool findPairDiff(vi& arr,int k)
{
	sort(arr.begin(),arr.end());
	int i = 0, j = 1;
   	int size=arr.size();
   while(i < size && j < size)
   {
       if(arr[j] - arr[i] == k) return true;
       else if(arr[j] - arr[i] < k) j++; 
       else i++;
   }
   return false;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n,k;
       cin>>n>>k;
       vi v(n);
       for(auto& i:v)
       		cin>>i;
       	cout<<findPairDiff(v,k)<<"\n";
}