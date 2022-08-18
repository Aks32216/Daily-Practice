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

bool isValid(string ip)
{
    string temp;
    for(int i=0;i<ip.length();++i)
    {
        if(ip[i]!='.')
        {
            temp+=ip[i];
        }
        else{
            int num=stoi(temp);
            if(num<0 || num>255 )
                return false;
            if(temp.length()>3)
                return false;
            string temp2=to_string(num);
            if(temp.length()!=temp2.length())
                return false;
            temp="";
        }
    }
    int num=stoi(temp);
    if(num<0 || num>255 || temp.length()>3)
        return false;
    string temp2=to_string(num);
    if(temp.length()!=temp2.length())
        return false;
    return true;
}

void helper(int dots,string ip,vector<string>& res,int idx)
{
    if(dots==3)
    {
        if(isValid(ip))
        {
            res.push_back(ip);
        }
        return;
    }
    for(int i=idx;i<ip.length();++i)
    {
        string temp=ip.substr(0,i)+"."+ip.substr(i);
        helper(dots+1,temp,res,i+2);
    }
}

vector<string> solve(string ip) {
    vector<string> res;
    int dots=0;
    int idx=1;
    helper(dots,ip,res,idx);
    return res;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       string ip;
       cin>>ip;
       vector<string> res=solve(ip);
       for(auto i:res)
       		cout<<i<<"\n";
}