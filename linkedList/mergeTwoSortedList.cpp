
// Approach - 1

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead=new ListNode(0);
        ListNode* temp3=newHead;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                temp3->next=temp1;
                temp3=temp3->next;
                temp1=temp1->next;
            }
            else
            {
                temp3->next=temp2;
                temp3=temp3->next;
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL)
            temp3->next=temp1;
        if(temp2!=NULL)
            temp3->next=temp2;
        return newHead->next;
    }

// Approach - 2

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        else if(list1->val<=list2->val)
        {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
    }