int length=0;
    ListNode* ll;
    Solution(ListNode* head) {
        ListNode* temp=head;
        ll=head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int idx=rand()%length;
        int i=0;
        ListNode* head=ll;
        while(i<idx && head!=NULL)
        {
            head=head->next;
            i++;
        }
        return head->val;
    }