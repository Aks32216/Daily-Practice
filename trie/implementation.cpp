struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void putKey(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* getNext(char ch)
    {
        return links[ch-'a'];
    }
    
    void putEnd()
    {
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {

private:
    Node* root;
    
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            if(node->containsKey(word[i])==false)
            {
                node->putKey(word[i],new Node());
            }
            node=node->getNext(word[i]);
        }
        node->putEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            if(node->containsKey(word[i])==false)
            {
                return false;
            }
            node=node->getNext(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            if(node->containsKey(word[i])==false)
            {
                return false;
            }
            node=node->getNext(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */