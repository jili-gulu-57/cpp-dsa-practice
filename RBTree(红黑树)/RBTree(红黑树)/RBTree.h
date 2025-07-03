#pragma once
#include<iostream>
using namespace std;
//在红黑树中，每个节点需要标记颜色以维护树的稳定性
enum Colour
{
	RED,
	BLACK
};
template<class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_col(RED)
	{}

};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (kv.first < cur->kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(kv);
		if (kv.first< parent->kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//变色处理
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}
		return true;
	}
private:
	Node* _root = nullptr;
};