// Approach - 1

int length(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head;
        int len=length(temp);
        len=len/2;
        int i=1;
        temp=head;
        while(i<len)
        {
            temp=temp->next;
            i++;
        }
        return temp->next;
    }

// Approach - 2

ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }