#pragma once
#include "Node.h"
class BinTree
{
private:
	Node* parentNode;
public:
	BinTree(int parentData);
	void AddNode(int data);
	bool DeleteNode(int dataToDelete);
};