#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class BinTree
{
    public:
        struct Node
        	{
        		string data = "";
        		int left = -1;
        		int right = -1;
        	};
    	BinTree(int _size)
    	{
    	    int height = ceil(log2(_size));
    	    size = pow(2,height);
    		tree = new Node*[size];
    	}
    	Node* Get(int idx)
    	{
    	    if(idx < 0 || idx >= size)
    	        return new Node;
    	    return tree[idx];
    	}
    	void Add(int _idx, string _data, int _left, int _right)
    	{
    	   if(_idx < 0 || _idx >= size)
    	        return;
    	        
    	   Node* n = new Node();
    	   n->data = _data;
    	   n->left = _left;
    	   n->right = _right;
    	   
    	   tree[_idx] = n;	    
    	}
    	string traverse()
    	{
    	    cout << postOrder("", tree[0]) << endl;
    	    cout << inOrder("", tree[0]) << endl;
    	    cout << preOrder("", tree[0]) << endl;
    	}
    	string postOrder(string cur, Node* root)
    	{
    	    if(root->left != -1)
    	        cur = postOrder(cur, tree[root->left]);
    	    if(root->right != -1)
    	        cur = postOrder(cur, tree[root->right]);
    	    cur = cur + root->data + " ";
    	    return cur;
    	}
    	string inOrder(string cur, Node* root)
    	{
    	    if(root->left != -1)
    	        cur = inOrder(cur, tree[root->left]);
    	    cur = cur + root->data + " ";
    	    if(root->right != -1)
    	        cur = inOrder(cur, tree[root->right]);
    	    return cur;
    	}
    	string preOrder(string cur, Node* root)
    	{
    	    cur = cur + root->data + " ";
    	    if(root->left != -1)
    	        cur = preOrder(cur, tree[root->left]);
    	    if(root->right != -1)
    	        cur = preOrder(cur, tree[root->right]);
    	    return cur;
    	}
    private:
        Node** tree;
        int size;
};

int main()
{
    int size;
    cin >> size;
    BinTree* tree = new BinTree(size);
    for(int i=0; i< size; i++)
    {
        string data;
        int left, right;
        cin >> data >> left >> right;
        tree->Add(i, data, left, right);
    }
    tree->traverse();
    return 0;
}
