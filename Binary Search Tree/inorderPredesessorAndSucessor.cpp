Node * inOrderPredessecor(Node *root, int x)
   {
       Node *curr=NULL;
       while(root)
       {
           if(root->key>=x)
           {        
               root=root->left;
           }
           else
           {
            curr=root;
               root=root->right;
           }
       }
       return curr;
   }
   
   Node * inOrderSuccessor(Node *root, int x)
   {
       Node *curr=NULL;
       while(root)
       {
           if(root->key>x)
           {
               curr=root;
               root=root->left;
           }
           else
           {
               root=root->right;
           }
       }
       return curr;
   }
   
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
   
   Node *p=inOrderPredessecor(root,key);
   Node *s=inOrderSuccessor(root,key);
   
   pre=p;
   suc=s;
   
   

// Your code goes here

}