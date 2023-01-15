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

int minimumSwap(string s1, string s2) {
	int xCount=0,yCount=0;
	int t1=0,t2=0;
	for(int i=0;i<s1.length();++i)
	{
		s1[i]=='x'?xCount++:yCount++;
		s2[i]=='x'?xCount++:yCount++;
		if(s1[i]=='x' && s2[i]=='y')
			t1++;
		else if(s1[i]=='y' && s2[i]=='x')
			t2++;
	}
	cout<<xCount<<" "<<yCount<<"\n";
	if(xCount&1==1 || yCount&1==1)
		return -1;
	else if((t1&1 && t2&1==0) || (t1&1==0 && t2&1))
		return -1;
	else
		return ((t1/2)+(t1%2)+(t2/2)+(t2%2));
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
 	cout<<minimumSwap(a,b)<<"\n";
}