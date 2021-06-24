#include <iostream>
#include <string>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
	BSTNode(int data):data(data)
	{
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};
class BST
{
	BSTNode* root;
	BSTNode* Insert(BSTNode*  root , int value);
	void Inorder(BSTNode* root  , string& result);
	BSTNode* Search(BSTNode* root, int value);
	int Min(BSTNode* root);
	int Max(BSTNode* root);
public:
	BST();
	void Insert(int value);
	BSTNode* Search(int value);
	void Inorder(string& result);
	int Min();
	int Max();
	int successor(int value);
	int predecessor(int value);
};
int BST::successor(int value)
{
	BSTNode* tmp = Search(value);
	if (tmp->right)
		return Min(root->right);
	else if (tmp->left)
		return tmp->parent->data;
	else throw exception();
}
int BST::predecessor(int value)
{
	BSTNode* tmp = Search(value);
	if (tmp->left)
		return Max(tmp->left);
	else if(tmp->right)
		return tmp->parent->data;
	else throw exception();

}
int BST::Min(BSTNode* root)
{
	BSTNode* tmp = root;
	while (tmp->left != nullptr)
		tmp = tmp->left;
	return tmp->data;
}
int BST::Max(BSTNode* root)
{
	BSTNode* tmp = root;
	while (tmp->right != nullptr)
		tmp = tmp->right;
	return tmp->data;
}
int BST::Min()
{
	return Min(root);
}
int BST::Max()
{
	return Max(root);
}
BST::BST()
{
	
}
BSTNode* BST::Search(BSTNode* root, int value)
{
	if (root != nullptr)
	{
		if (root->data == value)
			return root;
		if (root->data < value)
			Search(root->right, value);
		else 
			Search(root->left , value);
	}
	else return nullptr;
}
BSTNode* BST::Search(int value)
{
	return Search(root, value);
}
void BST::Insert( int value)
{
	if (!root)
		root = new BSTNode(value);
	else
		Insert(root, value);
}
BSTNode* BST::Insert(BSTNode* root, int value)
{
	if (!root)
	{
		root = new BSTNode(value);
		return root;
	}
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
		root->right->parent = root;
	}
	else
	{
		root->left = Insert(root->left, value);
		root->left->parent = root;
	}
	return root;
}

void BST::Inorder(string& res)
{
	if (!root) throw exception();
	Inorder(root , res);
}
void BST::Inorder(BSTNode* root, string& res)
{
	if (root == nullptr) return;
	Inorder(root->left, res);
	res += to_string(root->data) + " ";
	Inorder(root->right, res);
}
int main()
{
	BST bst;
	bst.Insert(5);
	bst.Insert(6);
	bst.Insert(2);
	bst.Insert(1);
	bst.Insert(7);
	bst.Insert(9);
	bst.Insert(8);
	string str = "";
	bst.Inorder(str);
	cout << str << endl;
	if (bst.Search(6) != nullptr)
		cout << 6 << " Found " << endl;
	else
		cout << 6 << " Not Found " << endl;
	if(bst.Search(0) != nullptr)
		cout << 0 << " Found " << endl;
	else
		cout << 0 << " Not Found " << endl;
	cout << "Min = " << bst.Min() << endl;
	cout << "Max = " << bst.Max() << endl;
	cout << "successor(1) = " << bst.successor(1) << endl;
	cout << "predecessor(9) = " << bst.predecessor(1) << endl;
	return 0;
}
