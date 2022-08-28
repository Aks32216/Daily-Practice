struct Node{
  Node* links[26];
  bool containsKey(char ch){
      return links[ch-'a']!=NULL;
  }
    void putKey(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNext(char ch){
        return links[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    int count=1;
    Node* root=new Node();
    for(int i=0;i<s.length();++i)
    {
        Node* node=root;
        for(int j=i;j<s.length();++j)
        {
            if(node->containsKey(s[j])==false)
            {
                node->putKey(s[j],new Node());
                count++;
            }
            node=node->getNext(s[j]);
        }
    }
    return count;
}