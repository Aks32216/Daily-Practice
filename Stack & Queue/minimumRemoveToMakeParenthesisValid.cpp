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

/*string minRemoveToMakeValid(string s) {
	int count=0;
	for(int i=0;i<s.length();++i){
		if(s[i]==')' && count==0)
			s[i]='#';
		if(s[i]=='(')
			count++;
		else if(s[i]==')')
			count--;
	}
	count=0;
	for(int i=s.length()-1;i>=0;--i){
		if(s[i]=='(' && count==0)
			s[i]='#';
		if(s[i]==')')
			count++;
		else if(s[i]=='(')
			count--;
	}
	string res;
	for(int i=0;i<s.length();++i){
		if(s[i]!='#')
			res+=s[i];
	}
	return res;
}*/
 
string minRemoveToMakeValid(string s) {
	stack<int> st;
	for(int i=0;i<s.length();++i){
		if(s[i]=='(')
			st.push(i);
		else if(s[i]==')'){
			if(st.empty())
				s[i]='#';
			else
				st.pop();
		}
	}
	while(!st.empty()){
		s[st.top()]='#';
		st.pop();
	}
	string res;
	for(int i=0;i<s.length();++i){
		if(s[i]!='#')
			res+=s[i];
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
 	cout<<minRemoveToMakeValid(s)<<"\n";
}