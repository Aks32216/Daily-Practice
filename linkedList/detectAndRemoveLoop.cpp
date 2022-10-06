 void removeLoop(Node* head)
 {
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            break;
    }
    if(fast==NULL || fast->next==NULL)
        return;
    if(slow==fast)
    {
        slow=head;
        if(slow==fast)
        {
            while(fast->next!=slow)
                fast=fast->next;
        }
        else
        {
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next=NULL;
    }
}