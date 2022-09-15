 /*
   ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right)
            return head;
        stack<int> s;
        int i=1;
        ListNode* temp=head;
        while(i<left)
        {
            i++;
            temp=temp->next;
        }
        ListNode* p=temp;
        while(i<=right)
        {
            i++;
            s.push(temp->val);
            temp=temp->next;
        }
        temp=p;
        i=left;
        while(i<=right)
        {
            temp->val=s.top();
            s.pop();
            i++;
            temp=temp->next;
        }
        return head;
    }
    */
    ListNode* reverseBetween(ListNode* head,int left,int right)
    {
        if(head==NULL || head->next==NULL || left==right)
            return head;
        ListNode* prev=NULL;
        ListNode* curPtr=head;
        ListNode* nextPtr;
        ListNode* s1;
        ListNode* s2;
        int i=1;
        while(i<left)
        {
            i++;
            prev=curPtr;
            curPtr=curPtr->next;
        }
        ListNode* endPtr=curPtr;
        while(i<=right)
        {
            i++;
            endPtr=endPtr->next;
        }
        s1=prev;
        s2=curPtr;
        while(curPtr!=endPtr)
        {
            nextPtr=curPtr->next;
            curPtr->next=prev;
            prev=curPtr;
            curPtr=nextPtr;
        }
        if(s1!=NULL)
            s1->next=prev;
        else
            head=prev;
        s2->next=curPtr;
        return head;
    }