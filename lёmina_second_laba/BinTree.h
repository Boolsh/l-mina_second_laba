#pragma once

struct Node {
private:
	int m_data;
	Node* m_left;
	Node* m_right;
public:
	Node(int data);
	~Node();
	void add(int data);
	void print(int level);
	void clear();
	bool is_leaf();
	int count_leafs();

	//int countNodeOnLevelRec(int level, int curLevel);
	//int countNodeOnLevelIter(int level);
};

struct BinTree {
private:
	Node* root;
public:
	BinTree();
	~BinTree();
	void add(int data);
	void print();
	void clear();
	int count_leafs();

	//int countNodeOnLevelRec(int level);
	//int countNodeOnLevelIter(int level);
};