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

vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        vector<bool> visited(friends.size(),false);
        q.push(id);
        visited[id]=true;
        while(level--)
        {
            int size=q.size();
            while(size--)
            {
                int cur=q.front();
                q.pop();
                for(auto child:friends[cur])
                {
                    if(!visited[child])
                    {
                        visited[child]=true;
                        q.push(child);
                    }
                }
            }
        }
        unordered_map<string,int> mp;
        while(!q.empty())
        {
            vector<string> v=watchedVideos[q.front()];
            q.pop();
            for(auto i:v)
                mp[i]++;
        }
        vector<pair<int,string> > res;
        for(auto i:mp)
        {
            res.push_back({i.second,i.first});
        }
        sort(res.begin(),res.end());
        vector<string> ans;
        for(auto i:res)
            ans.push_back(i.second);
        return ans;
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
       vector<vector<string> > watchedVideos(n);
       for(int i=0;i<n;++i)
       {
       		int j;
       		string video;
       		cin>>j;
       		while(j--)
       		{
       			cin>>video;
       			watchedVideos[i].push_back(video);
       		}
       }
       vector<vector<int> > friends(n);
       for(int i=0;i<n;++i)
       {
       		int j;
       		int fr;
       		cin>>j;
       		while(j--)
       		{
       			cin>>fr;
       			friends[i].push_back(fr);
       		}
       }
       int level,id;
       cin>>id>>level;
       vector<string> res=watchedVideosByFriends(watchedVideos,friends,id,level);
       for(auto i:res)
       	cout<<i<<"\n";

}