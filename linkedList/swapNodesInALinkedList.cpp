/*
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        int first=length-k+1;
        ListNode* firstNode;
        ListNode* secondNode;
        int i=1;
        temp=head;
        while(temp){
            if(i==first)
                firstNode=temp;
            if(i==k)
                secondNode=temp;
            temp=temp->next;
            i++;
        }
        swap(firstNode->val,secondNode->val);
        return head;
    }
    
    
    ListNode* swapNodes(ListNode* head,int k){
        stack<ListNode*> s;
        ListNode* temp=head;
        while(temp){
            s.push(temp);
            temp=temp->next;
        }
        int i=1;
        temp=head;
        while(temp){
            if(i==k){
                swap(s.top()->val,temp->val);
                break;
            }
            temp=temp->next;
            s.pop();
            i++;
        }
        return head;
    }
    */
    
    ListNode* swapNodes(ListNode* head,int k){
        ListNode* fast=head;
        ListNode* slow=head;
        int i=1;
        while(i<k){
            fast=fast->next;
            i++;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        fast=head;
        i=1;
        while(i<k){
            fast=fast->next;
            i++;
        }
        swap(fast->val,slow->val);
        return head;
    }