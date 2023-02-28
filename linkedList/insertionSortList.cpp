class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(INT_MIN,head);
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev=head;
        ListNode* cur=head->next;
        while(cur){
            cout<<cur->val<<" ";
            if(cur->val>prev->val)
            {
                prev=prev->next;
                cur=cur->next;
                continue;
            }

            ListNode* temp=dummy;
            while(cur->val>temp->next->val)
                temp=temp->next;
            prev->next=cur->next;
            cur->next=temp->next;
            temp->next=cur;
            cur=prev->next;
        }
        return dummy->next;
    }
};