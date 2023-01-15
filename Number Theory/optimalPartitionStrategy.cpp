#include <bits/stdc++.h>
 
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
#define mod 1e9+7
 
/*
int partitionString(string s) {
    int numPartitions=0;
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();++i)
    {
        mp[s[i]-97]++;
        if(mp[s[i]-97]>1)
        {
            numPartitions++;
            mp.clear();
            mp[s[i]-97]++;
        }
    }
    return numPartitions+1;
}


int partitionString(string s)
{
    int start=0,end=0,partition=0;
    unordered_map<char,int> mp;
    while(end<s.length())
    {
        if(mp.find(s[end])==mp.end())
            mp[s[end]]=end;
        else
        {
            if(mp[s[end]]<start)
                mp[s[end]]=end;
            else
            {
                partition++;
                start=end;
                mp[s[end]]=end;
            }
        }
        end++;
    }
    return partition+1;
}
*/

int partitionString(string s)
{
	int flag=0;
	int start=0,end=0,partition=0;
	while(end<s.length())
	{
		if(flag&(1<<(s[end]-97)))
		{
			flag=0;
			partition++;
		}
		flag=flag|(1<<(s[end]-97));
		end++;
	}
	return partition+1;
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
 	cout<<partitionString(s)<<"\n";  
}