// Convert a sorted list to a BST
#include <iostream>
#include <cstdlib>

using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int val): data(val), next(nullptr){}
};

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr){}
};

void push(ListNode **head, int value){
    ListNode *newptr = new ListNode(value);
    newptr->next = *head;
    *head = newptr;
}

void display(ListNode *head){
    while(head){
        cout <<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

TreeNode* createBST(ListNode **head, int start, int end)
{
    if (start > end)
        return nullptr;
        
    int mid = start + (end-start)/2;
    TreeNode *leftNode = createBST(head,start,mid-1);
    TreeNode *root = new TreeNode((*head)->data);
    root->left = leftNode;
    
    *head = (*head)->next;
    root->right = createBST(head,mid+1,end);
    
    return root;
}

void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        cout <<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    ListNode *head = nullptr;
    push(&head,13);
    push(&head,11);
    push(&head,9);
    push(&head,7);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    cout <<"Display of the sorted link list"<<endl;
    display(head);
    cout<<endl;
    
    auto *root = createBST(&head,0,8);
    cout<<"In-order display of BST"<<endl;
    inorder(root);
    cout <<endl;
    return 0;
}
