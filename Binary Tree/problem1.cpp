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
    	    height = ceil(log2(_size));
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
    	        
    	   tree[_idx] = new Node{_data, _left, _right};    	    
    	}
    	string traverse()
    	{
    	    return "";
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
    cout << tree->traverse();
    return 0;
}
