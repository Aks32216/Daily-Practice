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

int binLeft(const vector<int> &arr,int ele)
{    
    int start=0,end=arr.size()-1;
    if(arr[start]==ele)
        return start;
    if(arr[end]<ele)
        return -1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==ele)
        {
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]<ele)
            start=mid+1;
        else
            end=mid-1;
    }
    return ans;
}

int binRight(const vector<int> &arr,int ele)
{    
    int start=0,end=arr.size()-1;
    if(arr[end]==ele)
        return end;
    if(ele<arr[start])
        return -1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==ele)
        {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]<ele)
            start=mid+1;
        else
            end=mid-1;
    }
    return ans;
}

vector<int> searchRange(const vector<int> &A, int B) {
    int findLeft=binLeft(A,B);
    int findRight=binRight(A,B);
    if(findLeft!=-1 && findRight!=-1)
        return {findLeft,findRight};
    else
        return {-1,-1};
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n,target;
       cin>>n>>target;
       vi v(n);
       for(auto& i:v)
       		cin>>i;
       	vi res=searchRange(v,target);
       	cout<<res[0]<<" "<<res[1]<<"\n";
}