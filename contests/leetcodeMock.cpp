#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string>& words) {
        vector<int> res(26,INT_MAX);
        for(int i=0;i<words.size();++i)
        {
            vector<int> temp(26,0);
            for(int j=0;j<words[i].length();++j)
                temp[words[i][j]-'a']++;
            for(int j=0;j<26;++j)
                res[j]=min(res[j],temp[j]);
        }
        for(auto i:res)
            cout<<i<<" ";
        vector<string> ans;
        
        return ans;
    }

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<string> v(n);
    for(auto& i:v)
        cin>>i;
    vector<string> res=commonChars(v);
    for(auto i:res)
        cout<<i<<" ";
    cout<<"\n";
}