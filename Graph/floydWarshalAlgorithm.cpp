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

vector<vector<int>> floydWarshall(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int k=0;k<n;++k)
	    {
	        for(int i=0;i<n;++i)
	        {
	            for(int j=0;j<n;++j)
	            {
	                if(matrix[i][k]!=-1 && matrix[k][j]!=-1)
	                {
	                    if(matrix[i][j]==-1)
	                        matrix[i][j]=matrix[i][k]+matrix[k][j];
	                    else
	                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                }
	            }
	        }
		if(k==1 || k==2)
		{
			for(int i=0;i<n;++i)
       		{
       			for(int j=0;j<n;++j)
       				cout<<matrix[i][j]<<" ";
       			cout<<"\n";
       		}
		}        
	    }
	 	return matrix;   
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
       vector<vector<int> > v(n,vector<int>(n));
       for(int i=0;i<n;++i)
       {
       		for(int j=0;j<n;++j)
       			cin>>v[i][j];
       }
       vector<vector<int> > res=floydWarshall(v);
       for(int i=0;i<n;++i)
       {
       		for(int j=0;j<n;++j)
       			cout<<res[i][j]<<" ";
       		cout<<"\n";
       }
}