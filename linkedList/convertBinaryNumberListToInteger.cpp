// Approach - 1

int length(ListNode* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        int len=length(head);
        int ans=0;
        len=len-1;
        cout<<len<<"\n";
        while(head)
        {
            if(head->val==1)
            ans=ans+pow(2,len);
            len--;
            head=head->next;
        }
        return ans;
    }

// Approach - 2

int getDecimalValue(ListNode* head) {
        int value=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            int nodeValue=temp->val;
            value=(value<<1)|nodeValue;
            temp=temp->next;
        }
        return value;
    }