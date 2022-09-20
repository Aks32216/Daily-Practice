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
 
/*
int minSubArrayLen(int target, vector<int>& nums) {
    // generate every subarray and return the minimum subarray size among all
    int size=INT_MAX;
    for(int i=0;i<nums.size();++i)
    {
        int sum=0;
        for(int j=i;j<nums.size();++j)
        {
            sum+=nums[j];
            if(sum>=target)
            {
                size=min(size,j-i+1);
                break;
            }
        }
    }
    return size==INT_MAX?0:size;
}


bool isPossible(vector<int>& nums,int target,int subSize)
{
    int sum=0;
    for(int i=0;i<subSize;++i)
        sum+=nums[i];
    if(sum>=target)
        return true;
    for(int i=subSize;i<nums.size();++i)
    {
        sum=sum+nums[i]-nums[i-subSize];
        if(sum>=target)
            return true;
    }
    return false;
}

int minSubArrayLen(int target,vector<int>& nums)
{
    // binary search over the subarray size as subarray size can range from 1-nums.size()
    int start=1,end=nums.size();
    int res=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(nums,target,mid))
        {
            res=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return res;
}
*/

int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int start=0,end=0;
        int sum=0;
        while(end<nums.size())
        {
            sum+=nums[end];
            while(sum>=target)
            {
                sum-=nums[start];
                len=min(len,end-start+1);
                start++;
            }
            end++;
        }
        return len==INT_MAX?0:len;
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
    vector<int> v(n);
    for(auto& i:v)
        cin>>i;
    cout<<minSubArrayLen(target,v)<<"\n";
}