Q link- https://classroom.codingninjas.com/app/practice/2543644/15231/merge-in-between

Solution:

LinkedListNode* mergeInBetween(int x, int y, LinkedListNode *head1, LinkedListNode *head2) 
{
    LinkedListNode* temp1=head1;
    LinkedListNode* temp2=head1;
    LinkedListNode* temp3=head2;
    while(temp3->next)
    {
        temp3=temp3->next;
    }
    int i=0;
    while(i<y)
    {
        temp2=temp2->next;
        i++;
    }
    i=0;
    while(i<x-1)
    {
        temp1=temp1->next;
        i++;
    }
    temp3->next=temp2->next;
    temp2->next=NULL;
    temp1->next=head2;
    return head1;
}