class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p1=head;
        Node* p2=head;
        while(p1!=NULL){
            p2=p1->next;
            Node* copyNode=new Node(p1->val);
            p1->next=copyNode;
            copyNode->next=p2;
            p1=p2;
        }
        p1=head;
        while(p1!=NULL){
            if(p1->random!=NULL)
            {
                p1->next->random=p1->random->next;   
            }
            p1=p1->next->next;
        }
        Node* newHead=new Node(0);
        Node* c1=newHead;
        p1=head;
        p2=head;
        while(p1!=NULL)
        {
            p2=p1->next->next;
            c1->next=p1->next;
            c1=c1->next;
            p1->next=p2;
            p1=p2;
        }
        return newHead->next;
    }
};