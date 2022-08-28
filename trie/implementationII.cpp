struct Node{
    Node* links[26];
    int countEndWith=0;
    int countPrefix=0;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void putKey(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* getNext(char ch){
        return links[ch-'a'];
    }
   
    void increaseEndWith(){
        countEndWith++;
    }
    void increaseCountPrefix(){
        countPrefix++;
    }
    void decreaseEndWith(){
        countEndWith--;
    }
    void decreaseCountPrefix(){
        countPrefix--;
    }
    
};

class Trie{

    private:
    
        Node* root;
    
    public:
    

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            if(!node->containsKey(word[i]))
            {
                node->putKey(word[i],new Node());
            }
            node=node->getNext(word[i]);
            node->increaseCountPrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            if(!node->containsKey(word[i]))
                   return 0;
            node=node->getNext(word[i]);
        }
        return node->countEndWith;
    }

    int countWordsStartingWith(string &word){
         Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            if(!node->containsKey(word[i]))
                   return 0;
            node=node->getNext(word[i]);
        }
        return node->countPrefix;
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.length();++i)
        {
            node=node->getNext(word[i]);
            node->decreaseCountPrefix();
        }
        node->decreaseEndWith();
    }
};
