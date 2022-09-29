class Solution
{
    public:
    
    /*
    void solve(Node* head,int& rem)
    {
        if(head==NULL)
            return;
        solve(head->next,rem);
        int val=head->data+rem;
        int curVal=val%10;
        rem=val/10;
        head->data=curVal;
    }
    
    Node* addOne(Node *head) 
    {
        int rem=1;
        Node* temp=head;
        solve(temp,rem);
        if(rem)
        {
            Node* newRoot=new Node(rem);
            newRoot->next=head;
            return newRoot;
        }
        return head;
    }
    */
    
    Node* addOne(Node* head)
    {
        stack<int> s;
        Node* temp=head;
        while(temp)
        {
            s.push(temp->data);
            temp=temp->next;
        }
        int rem=1;
        Node* newHead=NULL;
        while(!s.empty())
        {
            int val=s.top();
            s.pop();
            int curVal=(val+rem)%10;
            rem=(val+rem)/10;
            Node* cur=new Node(curVal);
            cur->next=newHead;
            newHead=cur;
        }
        if(rem)
        {
            Node* cur=new Node(1);
            cur->next=newHead;
            newHead=cur;
        }
        return newHead;
    }
};