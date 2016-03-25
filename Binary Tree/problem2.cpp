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
    		for(int i=0; i<size; i++)
    		{
    		    tree[i] = new Node();
    		}
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
    	    cout << levelOrder("", tree, 1) << endl;
    	}
    	string levelOrder(string cur, Node** level, int levelSize)
    	{
    	    int newSize = levelSize*2;
    	    Node** nexLev = new Node*[newSize];
    	    int idx = 0;
    	    for(int i=0; i<levelSize; i++)
    	    {
    	        cur = cur + level[i]->data + " ";
    	        if(level[i]->left != -1)
    	        {
    	            nexLev[idx] = tree[level[i]->left];
    	            idx++;
    	        }
    	        if(level[i]->right != -1)
    	        {
    	            nexLev[idx] = tree[level[i]->right];
    	            idx++;
    	        }
    	    }
    	    if(idx == 0)
    	        return cur;
    	    return levelOrder(cur, nexLev, idx);
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
