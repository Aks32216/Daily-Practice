int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil=-1;
    while(node)
    {
        if(node->data==x)
            return node->data;
        else if(node->data>x)
            ceil=node->data,node=node->left;
        else
            node=node->right;
    }
    return ceil;
}