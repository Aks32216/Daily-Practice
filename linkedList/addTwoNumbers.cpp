 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead=new ListNode(0);
        ListNode* temp=newHead;
        int remainder=0;
        while(l1!=NULL || l2!=NULL)
        {
            int x=l1==NULL?0:l1->val;
            int y=l2==NULL?0:l2->val;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            int val=(x+y+remainder);
            int curVal=val%10;
            remainder=val/10;
            ListNode* curElem=new ListNode(curVal);
            temp->next=curElem;
            temp=temp->next;
        }
        if(remainder)
        {
            ListNode* curElem=new ListNode(remainder);
            temp->next=curElem;
        }
        return newHead->next;
    }