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

char findTheCharacter(string &a, string &b, int k)
{
    int i=0;
    int times=1;
    int turn=0;
    while(i<k)
    {
        if(turn==0)
        {
            i+=times*a.length();
            times++;
            turn=1;
        }
        else
        {
            i+=times*b.length();
            times++;
            turn=0;
        }
    }
    times--;
    if(turn==0)
        i-=times*b.length();
    else
        i-=times*a.length();
    k=k-i;
    if(turn==0)
    {
        k=k%b.length();
        if(k==0)
            return b[b.length()-1];
        else
            return b[k-1];
    }
    else
    {
        k=k%a.length();
        if(k==0)
            return a[a.length()-1];
        else
            return a[k-1];
    }
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       string a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    cout<<findTheCharacter(a,b,n)<<"\n";
}