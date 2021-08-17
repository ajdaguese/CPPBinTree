#pragma once
#include "Node.h"
class BinTree
{
private:
	Node parentNode;
public:
	BinTree();
	BinTree(Node parent);
	void AddNode(Node newNode);
	void DeleteNode(int dataToDelete);
};