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

int romanToInt(string s) {
        int val=0;
        for(int i=0;i<s.length();)
        {
            if(i+1<s.length() && (s[i]=='I' && s[i+1]=='V'))
                val+=4,i+=2;
            else if(i+1<s.length() && (s[i]=='I' && s[i+1]=='X'))
                val+=9,i+=2;
            else if(i+1<s.length() && (s[i]=='X' && s[i+1]=='L'))
                val+=40,i+=2;
            else if(i+1<s.length() && (s[i]=='X' && s[i+1]=='C'))
                val+=90,i+=2;
            else if(i+1<s.length() && (s[i]=='C' && s[i+1]=='D'))
                val+=400,i+=2;
            else if(i+1<s.length() && (s[i]=='C' && s[i+1]=='M'))
                val+=900,i+=2;
            else if(s[i]=='I')
                val+=1,i++;
            else if(s[i]=='V')
                val+=5,i++;
            else if(s[i]=='X')
                val+=10,i++;
            else if(s[i]=='L')
                val+=50,i++;
            else if(s[i]=='C')
                val+=100,i++;
            else if(s[i]=='D')
                val+=500,i++;
            else if(s[i]=='M')
                val+=1000,i++;
        }
        return val;
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
       cout<<romanToInt(s)<<"\n";
}