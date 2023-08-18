#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data >= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void solve( string s )
{
    ordered_set subNumbers;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if((i%3) == 0 )
        {
            string subStr = s.substr(i, 1);
            subNumbers.insert(stoi(subStr));
        }
        else if( ( i % 3 ) == 1 )
        {
            string subStr = s.substr(i, 2);
            subNumbers.insert(stoi(subStr));
            i++ ;
        } 
    }
    sort(subNumbers.rbegin(), subNumbers.rend());
    Node* root = nullptr;
    while( !subNumbers.empty())
    {
        int k = subNumbers.size() ;
        auto it = subNumbers.find_by_order( k / 2 ) ;
        root = insert(root , *it) ;
        subNumbers.erase(it) ;
    }
    preorderTraversal(root);

}
int main() {
    string numberAsString = "567843431";
    
    return 0;
}
