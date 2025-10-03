#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
};
class tree
{
public:
    node* root;
    tree()
    {
        root=nullptr;
    }
    node* insertnode(node* root,int d);
    node* findmin(node* root);
    node* deletenode(node* root,int value);
    bool search(node* root,int k);
    void display(node* root,int);
};
node* tree::insertnode(node* root,int d)
{
    if(root==NULL)
    {
        node* n=new node();
        n->data=d;
        n->left=n->right=nullptr;
        return n;
    }
    if(d<root->data)
        root->left=insertnode(root->left,d);
    else if(d>root->data)
        root->right=insertnode(root->right,d);
    return root;
}
node* tree::findmin(node* root)
{
    while(root && root->left!=nullptr)
        root=root->left;
    return root;
}
node* tree::deletenode(node* root,int value)
{
    if(root==nullptr)
        return root;
    if(value<root->data)
        root->left=deletenode(root->left,value);
    else if(value>root->data)
        root->right=deletenode(root->right,value);
    else
    {
        if(root->left==nullptr && root->right==nullptr)
        {
            delete root;
            return nullptr;
        }
        else if(root->left==nullptr)
        {
            node* t=root->right;
            delete root;
            return t;
        }
        else if(root->right==nullptr)
        {
            node* t=root->left;
            delete root;
            return t;
        }
        else
        {
            node* t=findmin(root->right);
            root->data=t->data;
            root->right=deletenode(root->right,t->data);
        }
    }
    return root;
}
bool tree::search(node* root,int k)
{
    if(root==nullptr)
        return false;
    if(root->data==k)
        return true;
    else if(k<root->data)
        return search(root->left,k);
    else if(k>root->data)
        return search(root->right,k);
}
void tree::display(node *ptr, int level=0) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);  // Print right subtree first
        cout << "\n";
        for (int i = 0; i < level; i++)
            cout << "         ";  // Indentation per level (8 spaces)
        if (ptr == root)
            cout << "Root -> ";
        else
            cout << "  -> ";
        cout << ptr->data;
        display(ptr->left, level + 1);   // Then print left subtree
    }
}
/*void tree::display(node* root)
{
    if(root!=nullptr)
    {
        display(root->left);
        cout<<"\t"<<root->data;
        display(root->right);
    }
}**/
int main()
{
    int c,value,k;
    node* root;
    tree t;
    cout<<"\t\t\tBINARY SEARCH TREE\n";
    cout<<"\t\tChoose the options\n";
    cout<<"1.Insert\n";
    cout<<"2.Delete\n";
    cout<<"3.Search\n";
    cout<<"4.Display\n";
    cout<<"5.Exit\n";
    do
    {
        cout<<"\nEnter the choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            cout<<"\t\t---INSERT---\n";
            cout<<"Enter the value:";
            cin>>value;
            t.root=t.insertnode(t.root,value);
            break;
        case 2:
            cout<<"\t\t---DELETE---\n";
            cout<<"Enter the value to delete:";
            cin>>value;
            t.root=t.deletenode(t.root,value);
            cout<<"\n\tDeleted Successfully\n";
            break;
        case 3:
            cout<<"\t\t---SEARCH---\n";
            cout<<"Enter the key value to search:";
            cin>>k;
            if(t.search(t.root,k))
            {
                cout<<"\n\tKey found.";
            }
            else
            {
                cout<<"\n\tKey not found.";
            }
            break;
        case 4:
            cout<<"\t\t---DISPLAY---\n";
            cout<<"\n\t Binary Search Tree\n ";
            t.display(t.root);
            cout<<endl;
            break;
        case 5:
            cout<<"\n\tExiting.....\n";
            break;
        default:
            cout<<"\n\tInvalid choice.Enter the choice between 1-5";
        }
    }while(c!=5);
return 0;
}
