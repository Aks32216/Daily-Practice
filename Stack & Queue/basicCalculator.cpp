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
 
int calculate(string s) {
	int n=s.length();
	stack<int> st;
	int curNumber=0;
	char curOperation='+';
	for(int i=0;i<n;++i)
	{
		if(isdigit(s[i]))
			curNumber=curNumber*10+(s[i]-'0');
		if(!isdigit(s[i]) && !iswspace(s[i]) || i==n-1)
		{
			if(curOperation=='+')
				st.push(curNumber);
			else if(curOperation=='-')
				st.push(-curNumber);
			else if(curOperation=='*')
			{
				int lastNumber=st.top();
				st.pop();
				int value=lastNumber*curNumber;
				st.push(value);
			}
			else
			{
				int lastNumber=st.top();
				st.pop();
				int value=lastNumber/curNumber;
				st.push(value); 
			}
			curOperation=s[i];
			curNumber=0;
		}
	}
	int res=0;
	while(!st.empty())
	{
		res+=st.top();
		st.pop();
	}
	return res;
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
 	cout<<calculate(s)<<"\n";
}