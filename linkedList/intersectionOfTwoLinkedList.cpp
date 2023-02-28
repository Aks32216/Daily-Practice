class Solution {
public:
    /*
    int findLength(ListNode* head)
    {
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int len1=findLength(temp1);
        int len2=findLength(temp2);
        temp1=headA;
        temp2=headB;
        while(len1>len2){
            temp1=temp1->next;
            len1--;
        }
        while(len2>len1){
            temp2=temp2->next;
            len2--;
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2)
                return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
    */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        unordered_map<ListNode*,int> mp;
        ListNode* temp=headA;
        while(temp!=NULL)
        {
            mp[temp]++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL)
        {
            if(mp.find(temp)!=mp.end())
                return temp;
            mp[temp]++;
            temp=temp->next;
        }
        return NULL;
    }
};