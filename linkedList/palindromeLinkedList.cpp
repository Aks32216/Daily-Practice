class Solution {
public:
    /*
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!s.empty()){
            if(temp->val!=s.top())
                return false;
            temp=temp->next;
            s.pop();
        }
        return true;
    }
    
    ListNode* temp;
    bool check(ListNode* head)
    {
        if(head==NULL)
            return true;
        bool isPalindrome=check(head->next) && temp->val==head->val;
        temp=temp->next;
        return isPalindrome;
    }
    bool isPalindrome(ListNode* head){
        temp=head;
        return check(head);
    }
    */

    bool isPalindrome(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        ListNode* prevPtr=NULL;
        ListNode* curPtr=fast;
        ListNode* nextPtr;
        while(curPtr)
        {
            nextPtr=curPtr->next;
            curPtr->next=prevPtr;
            prevPtr=curPtr;
            curPtr=nextPtr;
        }
        while(slow && prevPtr)
        {
            if(slow->val!=prevPtr->val)
                return false;
            slow=slow->next;
            prevPtr=prevPtr->next;
        }
        return true;
    }
};