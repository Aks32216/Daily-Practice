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

int repeatedNumber(const vector<int> &A) {
    vector<int> nums={A[0],(int)1e9,(int)1e9};
    vector<int> count={1,0,0};
    int n=A.size();
    for(int i=0;i<n;++i)
    {
        if(A[i]==nums[0])
            count[0]++;
        else if(A[i]==nums[1])
            count[1]++;
        else if(A[i]==nums[2])
            count[2]++;
        else if(count[0]==0)
            nums[0]=A[i],count[0]=1;
        else if(count[1]==0)
            nums[1]=A[i],count[1]=1;
        else if(count[2]==0)
            nums[2]=A[i],count[2]=1;
        else
            count[0]--,count[1]--;
    }
    count={0,0,0};
    for(int i=0;i<n;++i)
    {
        if(A[i]==nums[0])
            count[0]++;
        if(A[i]==nums[1])
            count[1]++;
        if(A[i]==nums[2])
            count[2]++;
    }
    int res;
    if(count[0]>n/3)
        res=nums[0];
    else if(count[1]>n/3)
        res=nums[1];
    else if(count[2]>n/3)
        res=nums[2];
    else
        res=-1;
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
       vi v(n);
       for(auto& i:v)
       		cin>>i;
       	cout<<repeatedNumber(v)<<"\n";
}