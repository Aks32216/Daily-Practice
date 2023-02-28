ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        while(temp2!=NULL)
        {
            if(temp1->val==temp2->val)
                temp2=temp2->next;
            else
            {
                temp1->next=temp2;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        temp1->next=NULL;
        return head;
    }