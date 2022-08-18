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

struct Job{
	int id;
	int dead;
	int profit;
};

bool comp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(vector<Job>& arr, int n) 
    { 
        sort(arr.begin(),arr.end(),comp);
        int b[n];
        memset(b,-1,sizeof(b));
        int profit=0;
        int job=0;
        for(int i=0;i<n;++i)
        {
            for(int j=min(n,arr[i].dead-1);j>=0;--j)
            {
                if(b[j]==-1)
                {
                    b[j]=arr[i].id;
                    profit+=arr[i].profit;
                    job++;
                    break;
                }
            }
        }
        for(int i=0;i<n;++i)
        	cout<<b[i]<<" ";
       	cout<<"\n";
        return {job,profit};
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
       vector<Job> v(n);
       for(int i=0;i<n;++i)
       {
       		cin>>v[i].id>>v[i].dead>>v[i].profit;
       }
       vi res=JobScheduling(v,n);
       for(auto& i:res)
       		cout<<i<<" ";
       	cout<<"\n";
}