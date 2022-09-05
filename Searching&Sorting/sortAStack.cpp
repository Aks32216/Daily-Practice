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
 
void print(stack<int>& s){
	if(!s.empty()){
		int x=s.top();
		s.pop();
		print(s);
		cout<<x<<" ";
		s.push(x);
	}
}

// Using temporary stack

/*void sort(stack<int>& s){
	stack<int> temp;
	while(!s.empty()){
		int x=s.top();
		s.pop();
		while(!temp.empty() && temp.top()>x){
			s.push(temp.top());
			temp.pop();
		}
		temp.push(x);
	}
	s=temp;
}*/

// Using Recursion

void insert(stack<int>& s,int x){
	if(s.empty() || x>s.top())
	{
		s.push(x);
		return;
	}
	int temp=s.top();
	s.pop();
	insert(s,x);
	s.push(temp);
}

void sort(stack<int>& s){
	if(!s.empty()){
		int x=s.top();
		s.pop();
		sort(s);
		insert(s,x);
	}
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
 	stack<int> s;
 	while(n--){
 		int a;
 		cin>>a;
 		s.push(a);
 	}
 	sort(s);
 	print(s);    
}