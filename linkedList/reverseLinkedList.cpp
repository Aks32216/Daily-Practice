// Iterative Method
// Time Complexity : O(n), Space Complexity : O(1)

struct Node* reverseList(struct Node *head)
    {
        Node* cur=head;
        Node* prev=NULL;
        Node* ptrnext;
        if(head->next==NULL)
            return cur;
        while(cur!=NULL)
        {
            ptrnext=cur->next;
            cur->next=prev;
            prev=cur;
            cur=ptrnext;
        }
        return prev;
    }

// Recursive Way
// Time Complexity  : O(n) , Space Complexity  : O(1)

Node* solve(struct Node* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        struct Node* newHead=solve(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    
    struct Node* reverseList(struct Node *head)
    {
        return solve(head);
    }