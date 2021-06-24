#include <iostream>
#include <string>
#include<stack>
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
	BSTNode* Min(BSTNode* root);
	BSTNode* Max(BSTNode* root);
	void Delete(BSTNode* node);
	BSTNode* successor(BSTNode*);
public:
	BST();
	~BST();
	void Insert(int value);
	BSTNode* Search(int value);
	void Inorder(string& result);
	int Min();
	int Max();
	int successor(int value);
	int predecessor(int value);
	void Delete(int value);
};
BST::~BST()
{
	delete root;
}
void BST::Delete(int value)
{
	Delete(Search(value));
}
BSTNode* BST::successor(BSTNode* tmp)
{
	if (tmp->right)
		return Min(tmp->right);
	else if (tmp->left)
		return tmp->parent;
	else return tmp;
}
void BST::Delete(BSTNode* node)
{
	if (root != node)
	{
		if (!node->right && !node->left)
		{
			if (node->parent->left == node) node->parent->left = nullptr;
			else node->parent->right = nullptr;
		}
		else if (!node->right && node->left)
		{
			if (node->parent->left == node) node->parent->left = node->left;
			else node->parent->right = node->left;
		}
		else if (node->right && !node->left)
		{
			if (node->parent->left == node) node->parent->left = node->right;
			else node->parent->right = node->right;
		}
		else if (node->right && node->left)
		{
			auto tmp = successor(node);
			tmp->parent = node->parent;
			tmp->right = node->right == tmp ? node->right->right : node->right;
			tmp->left = node->left == tmp ? node->left->left : node->left;
			tmp->right->parent = tmp;
			tmp->left->parent = tmp;
			if (node->parent->left == node) node->parent->left = tmp;
			else node->parent->right = tmp;
		}
		else throw exception();
		}
	else
	{
		if (!node->right && !node->left) root = nullptr;
		else if (!node->right && node->left)
		{
			delete root;
			root = root->left;
		}
		else if (node->right && !node->left)
		{
			delete root;
			root = root->right;
		}
		else if (node->right && node->left)
		{
			auto tmp = successor(node);
			//delete root;
			tmp->parent = node->parent;
			tmp->right = node->right == tmp ? node->right->right : node->right;
			tmp->left = node->left == tmp ? node->left->left : node->left;
			tmp->right->parent = tmp;
			tmp->left->parent = tmp;
			delete root;
			root = tmp;
		}
		else throw exception();
	}
}
int BST::successor(int value)
{
	BSTNode* tmp = Search(value);
	if (tmp->right)return Min(tmp->right)->data;
	else return tmp->parent->data;
}
int BST::predecessor(int value)
{
	BSTNode* tmp = Search(value);
	if (tmp->left)return Max(tmp->left)->data;
	else return tmp->parent->data;

}
BSTNode* BST::Min(BSTNode* root)
{
	BSTNode* tmp = root;
	while (tmp->left != nullptr) tmp = tmp->left;
	return tmp;
}
BSTNode* BST::Max(BSTNode* root)
{
	BSTNode* tmp = root;
	while (tmp->right != nullptr) tmp = tmp->right;
	return tmp;
}
int BST::Min()
{
	return Min(root)->data;
}
int BST::Max()
{
	return Max(root)->data;
}
BST::BST()
{
}
BSTNode* BST::Search(BSTNode* root, int value)
{
	if (root != nullptr)
	{
		if (root->data == value) return root;
		if (root->data < value) Search(root->right, value);
		else Search(root->left , value);
	}
	else return nullptr;
}
BSTNode* BST::Search(int value)
{
	return Search(root, value);
}
void BST::Insert( int value)
{
	if (!root) root = new BSTNode(value);
	else Insert(root, value);
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
	bst.Insert(10);
	bst.Insert(11);
	bst.Delete(5);
	string str = "";
	bst.Inorder(str);
	cout << str << endl;
	if (bst.Search(6) != nullptr) cout << 6 << " Found " << endl;
	else cout << 6 << " Not Found " << endl;
	if(bst.Search(0) != nullptr) cout << 0 << " Found " << endl;
	else cout << 0 << " Not Found " << endl;
	cout << "Min = " << bst.Min() << endl;
	cout << "Max = " << bst.Max() << endl;
	cout << "successor(1) = " << bst.successor(1) << endl;
	cout << "predecessor(9) = " << bst.predecessor(6) << endl;
	return 0;
}
