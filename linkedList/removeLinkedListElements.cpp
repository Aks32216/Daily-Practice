class Solution {
public:

    /*
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        head->next=removeElements(head->next,val);
        return head->val==val?head->next:head;
    }
    */

    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
        while(head && head->val==val)
            head=head->next;
        if(!head)
            return head;
        
        ListNode* prev=head;
        ListNode* cur=head->next;
        while(cur)
        {
            while(cur && cur->val==val)
                cur=cur->next;
            prev->next=cur;
            prev=prev->next;
            if(cur)
                cur=cur->next;
        }
        return head;
    }
};