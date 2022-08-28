bool comp(string& a,string& b){
    return a.length()<b.length();
}

struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void putKey(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    void putEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};

string completeString(int n, vector<string> &a){
    sort(begin(a),end(a),comp);
    string res="";
    Node* root=new Node();
    for(int i=0;i<a.size();++i)
    {
        string temp=a[i];
        Node* node=root;
           int isComplete=0;
        for(int j=0;j<temp.length();++j)
        {
            if(node->containsKey(temp[j])==false){
                node->putKey(temp[j],new Node());
            }
            node=node->getNext(temp[j]);
            if(node->isEnd())
            {
                isComplete++;
            }
        }
        node->putEnd();
        if(isComplete+1==temp.length())
        {
            if(res.length()==temp.length()){
                res=min(res,temp);
            }else if(temp.length()>res.length()){
                res=temp;
            }
        }
    }
    return res==""?"None":res;
}