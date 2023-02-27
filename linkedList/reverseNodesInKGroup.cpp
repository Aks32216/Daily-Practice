class Solution {
public:

    void reverse(ListNode* s,ListNode* e)
    {
        ListNode* prev=NULL;
        ListNode* cur=s;
        ListNode* nex;
        while(prev!=e)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1)
            return head;
        ListNode* s=head;
        ListNode* e=head;
        int inc=k-1;
        while(inc--)
        {
            e=e->next;
            if(e==NULL)
                return head;
        }
        ListNode* newHead=reverseKGroup(e->next,k);
        reverse(s,e);
        s->next=newHead;
        return e;
    }
};