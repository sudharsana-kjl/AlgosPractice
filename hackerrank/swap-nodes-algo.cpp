#include<bits/stdc++.h>
using namespace std;

int max_depth=0;
int n;

struct node{
    int data;
    node * left;
    node * right;
};

node * createNode(int data) {
    node * temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(node * root) {
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void swapnodes(node *root,int d) {
    if(root==NULL)
        return;
    queue<node *>q;
    int depth = 1;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node *t = q.front();
        q.pop();
        if(t==NULL) {
            depth++;
            if(!q.empty())
                q.push(NULL);
        }
        else {
            if(depth==d) {
                node * te = t->left;
                t->left = t->right;
                t->right = te;
            }
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
    
}	
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nk,k;   
    cin>>n;
    
    queue<node *>q;
    node * root = createNode(1);
    q.push(root);
    q.push(NULL);
    int depth = 1;
    while(n>0 && !q.empty()) {
        node * t = q.front();
        q.pop();
        if(t==NULL)
            {
            depth++;
            if(!q.empty())
            q.push(NULL);
        }
        else {
            int l,r;
            cin>>l>>r;
            if(l!=-1) {
                t->left = createNode(l);
                q.push(t->left);
            }
            if(r!=-1) {
                t->right = createNode(r);
                q.push(t->right);
            }
            n--;
        }
        
    }  
 
    cin>>nk;
   
    for(int i=0;i<nk;i++){
        cin>>k;
        int j = k;
        int itr = 2;
       
        while(j<=depth) {  
            swapnodes(root,j);
            j=k*itr;
            itr++;
        }
       inorder(root);
        cout<<endl;
    }
    
    return 0;
}

