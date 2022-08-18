void solve(Node* node)
{
    if(node==NULL)
        return;
    solve(node->left);
    solve(node->right);
    swap(node->left,node->right);
}
    void mirror(Node* node) {
        solve(node);
    }