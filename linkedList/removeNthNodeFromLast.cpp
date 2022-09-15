/*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        int diff=count-n+1;
        if(diff==1)
            return head->next;
        temp=head;
        count=1;
        while(temp!=NULL)
        {
            if(count+1==diff)
                break;
            temp=temp->next;
            count++;
        }
        temp->next=temp->next->next;
        return head;
    }
    */
    ListNode* removeNthFromEnd(ListNode* head,int n)
    {
        ListNode* dum=new ListNode(0);
        dum->next=head;
        ListNode* fast=dum;
        for(int i=0;i<n;++i)
            fast=fast->next;
        ListNode* slow=dum;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dum->next;
    }