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
 
int findNextZero(vector<int>& v)
{
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==0)
        {
            v[i]=1;
            return i;
        }
    }
    return -1;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       string s;
       cin>>s;
       int start=0,end=0;
       unordered_map<char,int> mp;
       while(end<s.length())
       {
            if(s[end]=='?')
            {
                if(end-start+1==26)
                    break;
                end++;
                continue;
            }
            if(mp.find(s[end])==mp.end())
            {
                mp[s[end]]=end;
                if(end-start+1==26)
                    break;
            }
            else
            {
                if(mp[s[end]]<start)
                {
                    mp[s[end]]=end;
                }
                else
                {
                    start=mp[s[end]]+1;
                    mp[s[end]]=end;
                }
                if(end-start+1==26)
                    break;
            }
            end++;
       }
       if(end==s.length())
       {
            cout<<"-1\n";
            exit(0);
       }
       // cout<<start<<" "<<end<<"\n";
        vector<int> available(26,0);
         for(int i=start;i<=end;++i)
         {
                if(s[i]=='?')
                    continue;
             available[s[i]-65]++;
         }
         for(int i=start;i<=end;++i)
         {
            
             if(s[i]=='?')
             {
                 int j=findNextZero(available);       
                 s[i]=65+j;
             }
         }
         for(int i=0;i<s.length();++i)
         {
            if(s[i]=='?')
                s[i]='A';
         }
         cout<<s<<"\n";
}