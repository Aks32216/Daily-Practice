#define ili pair<int,ListNode*>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ili,vector<ili>,greater<ili> > pq;
        for(int i=0;i<lists.size();++i)
        {
            if(lists[i]!=NULL)
            {
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* newHead=new ListNode(0);
        ListNode* sentinal=newHead;
        while(!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();
            sentinal->next=new ListNode(cur.first);
            sentinal=sentinal->next;
            if(cur.second->next!=NULL)
                pq.push({cur.second->next->val,cur.second->next});
        }
        return newHead->next;
    }
};