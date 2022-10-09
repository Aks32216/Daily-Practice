/*
    int pairSum(ListNode* head)
    {
        stack<int> s;
        ListNode* temp=head;
        while(temp)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        int sum=0;
        temp=head;
        while(temp)
        {
            int curVal=s.top()+temp->val;
            sum=max(sum,curVal);
            s.pop();
            temp=temp->next;
        }
        return sum;
    }
    */
    
    void solve(ListNode* head,ListNode** cur,int& ans)
    {
        if(head==NULL)
            return;
        solve(head->next,cur,ans);
        ans=max(ans,head->val+(*cur)->val);
        (*cur)=(*cur)->next;
    }
    
    int pairSum(ListNode* head) {
        int ans=INT_MIN;
        ListNode* cur=head;
        solve(head,&cur,ans);
        return ans;
    }