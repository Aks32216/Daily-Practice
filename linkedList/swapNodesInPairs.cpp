ListNode* swapPairs(ListNode* head) {
        while(head && head->next)
        {
            ListNode* a=head;
            ListNode* b=head->next;
            ListNode* c=b->next;
            b->next=a;
            a->next=swapPairs(c);
            return b;
        }
        return head;
    }