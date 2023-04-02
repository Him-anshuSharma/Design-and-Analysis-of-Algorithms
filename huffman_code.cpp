#include<iostream>
#include<queue>
#include<string>
#include<map>
using namespace std;

typedef struct node node;


map<char, string> codes;

typedef struct node{
    struct node* left;
    struct node* right;
    char val;
    int freq;
    bool operator<(const struct node& rhs) const
    {
        return freq > rhs.freq;
    }
    node(struct node* l,struct node* r, char v, int f){
        left = l; right = r; val = v; freq = f;
    }

}*nodeptr;

node* head = NULL;

int isLeaf(node* root)
 
{
 
    return !(root->left) && !(root->right);
}

string printArr(int arr[], int n)
{
    int i;string str = "";
    for (i = 0; i < n; ++i){
        str += to_string(arr[i]);
    }
    return str;
}

void printCodes(node* root, int arr[], int top)
 
{
 
    if (root->left) {
 
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    if (root->right) {
 
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
 
        codes[root->val] =printArr(arr, top);
    }
}

struct MyComparator {
    bool operator() (nodeptr arg1, nodeptr arg2) {
        return arg1->freq > arg2->freq; //calls your operator
    }
};

void HuffManCode(priority_queue<nodeptr,vector<nodeptr>,MyComparator> pq){ 
    node* n1=new node(NULL,NULL,'Z',0);
    node* n2=new node(NULL,NULL,'Z',0);
    node* n3=new node(NULL,NULL,'Z',0);

    while(pq.size()!=1){
        n1 = pq.top();pq.pop();
        n2 = pq.top();pq.pop();
        int sum = n1->freq + n2->freq;
        n3 = new node(n1,n2,'0',sum);
        pq.push(n3);
    }
    head = n3;
}


int main(){
    priority_queue<nodeptr,vector<nodeptr>,MyComparator> pq;
    int size = 7;
    char c = 'A';
    int arr[size];
    for(int i=0;i<7;i++){
        cin >>arr[i];
        node* n = new node(NULL,NULL,c++,arr[i]);
        pq.push(n);
    }
    HuffManCode(pq);
    printCodes(head,arr,0);
    for(pair<char,string> i : codes){
        cout<< i.second<<" ";
    }
    return 0;
}