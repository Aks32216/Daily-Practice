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
bool checkStraightLine(vector<vector<int>>& coordinates) {
    for(int i=0;i<coordinates.size();++i)
    {
        for(int j=i+1;j<coordinates.size();++j)
        {
            for(int k=j+1;k<coordinates.size();++k)
            {
                double x1=coordinates[i][0];
                double x2=coordinates[i][1];
                double y1=coordinates[j][0];
                double y2=coordinates[j][1];
                double z1=coordinates[k][0];
                double z2=coordinates[k][1];

                if(x2==y2 || z2==y2)
                    continue;

                long double sl1=(y1-x1)/(y2-x2);
                long double sl2=(z1-y1)/(z2-y2);
                cout<<sl1<<" "<<sl2<<"\n";
                if(sl1!=sl2)
                    return false;
            }
        }
    }
    return true;
}
*/
bool checkStraightLine(vector<vector<int> >& coordinates){
    sort(begin(coordinates),end(coordinates));
    int n=coordinates.size()-1;
    double x1=coordinates[0][0];
    double x2=coordinates[0][1];
    double y1=coordinates[n][0];
    double y2=coordinates[n][1];
    double sl1=(y1-x1)/(y2-x2);
    for(auto i:coordinates)
        cout<<i[0]<<" "<<i[1]<<"\n";
    for(int i=0;i<coordinates.size();++i)
    {
        if(i+1==coordinates.size())
            break;
        x1=coordinates[i][0];
        x2=coordinates[i][1];
        y1=coordinates[i+1][0];
        y2=coordinates[i+1][1];
        if(y2==x2)
            continue;
        double sl2=(y1-x1)/(y2-x2);
        cout<<sl1<<" "<<sl2<<"\n";
        if(sl1!=sl2)
            return false;
    }
    return true;
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
 	vector<vector<int> > coordinates(n,vector<int>(2));
 	for(int i=0;i<n;++i)
 	{
 		cin>>coordinates[i][0]>>coordinates[i][1];
 	}      
 	cout<<checkStraightLine(coordinates)<<"\n";


}