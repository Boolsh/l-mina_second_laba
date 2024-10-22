#include "BinTree.h"
#include <iostream>
#include <stack>

Node::Node(int data)
{
	m_data = data;
	m_left = nullptr;
	m_right = nullptr;
}

Node::~Node()
{
	clear();
}

void Node::add(int data)
{
	if (data == m_data) {
		return;
	}
	if (data < m_data) {
		if (m_left == nullptr)
			m_left = new Node(data);
		else
			m_left->add(data);
	}
	else {
		if (m_right == nullptr)
			m_right = new Node(data);
		else
			m_right->add(data);
	}
}

void Node::print(int level)
{
	if (m_left) {
		m_left->print(level + 1);
	}
	for (int i{}; i < level; ++i)
		std::cout << "   ";
	std::cout << m_data << std::endl;
	if (m_right) {
		m_right->print(level + 1);
	}
}

void Node::clear()
{
	if (m_left) {
		delete m_left;
		m_left = nullptr;
	}
	if (m_right) {
		delete m_right;
		m_right = nullptr;
	}
}

bool Node::is_leaf()
{
	return (!m_left && !m_left) ? true : false;
}

int Node::count_leafs()
{
	int result = 0;
	if (is_leaf())
		return 1;
	else
	{
		if (m_left)
			result += m_left->count_leafs();
		if (m_right)
			result += m_right->count_leafs();
		return result;
	}

}



//int Node::countNodeOnLevelRec(int level, int curLevel)
//{
//	int result = 0;
//	if (curLevel < level)
//	{
//		if (m_left)
//			result += m_left->countNodeOnLevelRec(level, curLevel + 1);
//		if (m_right)
//			result += m_right->countNodeOnLevelRec(level, curLevel + 1);
//		return result;
//	}
//	if (level == curLevel) return 1;
//	if (level < curLevel) return 0;
//}
//
//int Node::countNodeOnLevelIter(int level)
//{
//	if (level == 0)
//		return 1;
//	std::stack < Node* > st;
//	st.push(this);
//	std::stack < Node* > st_next;
//
//	int cur_level{};
//	while (cur_level != level)
//	{
//		while (!st.empty())
//		{
//			Node* node = st.top();
//			st.pop();
//			if (node->m_left) st_next.push(m_left);
//			if (node->m_right) st_next.push(m_right);
//
//		}
//		st = st_next;
//		++cur_level;
//	}
//
//}





BinTree::BinTree()
{
	root = nullptr;
}

BinTree::~BinTree()
{
	clear();
}

void BinTree::add(int data)
{
	if (!root) {
		root = new Node(data);
	}
	else {
		root->add(data);
	}
}

void BinTree::print()
{
	if (!root) std::cout << "Derevo empty\n";
	else root->print(0);
}

void BinTree::clear()
{
	if (root) {
		root->clear();
		root = nullptr;
	}
}

int BinTree::count_leafs()
{
	if (!root)
		return -1;
	else return root->count_leafs();
}

//int BinTree::countNodeOnLevelRec(int level)
//{
//	if (root)
//		return root->countNodeOnLevelRec(level, 0);
//	else
//		return 0;
//}
//
//int BinTree::countNodeOnLevelIter(int level)
//{
//	if (root)
//		return root->countNodeOnLevelIter(level);
//	else
//		return 0;
//}
