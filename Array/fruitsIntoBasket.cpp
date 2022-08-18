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

int totalFruit(vector<int>& fruits) {
        int ele1=fruits[0],ele2=-1;
        int ele1last=0,ele2last=-1;
        int m=1,count=1;
        for(int i=1;i<fruits.size();++i)
        {
            if(fruits[i]!=ele1 && ele2==-1)
            {
                ele2=fruits[i],count++,ele2last=i;
                continue;
            }
            if(fruits[i]==ele1)
                count++,ele1last=i;
            else if(fruits[i]==ele2)
                count++,ele2last=i;
            else
            {
                m=max(m,count);
                if(fruits[i-1]==ele1)
                {
                    ele2=fruits[i];
                    count=i-ele2last;
                    ele2last=i;
                }
                else
                {
                    ele1=fruits[i];
                    count=i-ele1last;
                    ele1last=i;
                }
                m=max(m,count);
            }
        }
        m=max(m,count);
        return m;
    }

    /*
		int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        unordered_map<int,int> mp; // map to store frequency
        int n= fruits.size();
        int mlen=INT_MIN;
        while(j<n){
            mp[fruits[j]]++;
            
            if(mp.size()>2){
                while(mp.size()>2){  // if map sie increases from 2 that means we need to remove the fruits from the back of our sliding window
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]); //erase from map to decrease the size  of map
                    }
                    i++;
                }
                // mp.erase(fruits[i]);
            }
            mlen= max(mlen,j-i+1);
            j++;
        }
        return mlen;
    }
    */
 
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
    cout<<totalFruit(v)<<"\n";
}