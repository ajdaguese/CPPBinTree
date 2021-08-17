#include "BinTree.h"

BinTree::BinTree(int parentData)
{
	parentNode = new Node(parentData);
}

void BinTree::AddNode(int data)
{
	parentNode->AddNode(data);
}

bool BinTree::DeleteNode(int data)
{
	//a boolean indicating whether the data was found and subsequently deleted
	bool deleted = false;
	Node* currNode = parentNode;
	//while there is more tree to traverse, traverse it
	while ((data < currNode->GetData() && currNode->GetLeft() != NULL) || (data > currNode->GetData() && currNode->GetRight() != NULL))
	{
		if (data < currNode->GetData())
		{
			currNode = currNode->GetLeft();
		}
		else if(data > currNode->GetData())
		{
			currNode = currNode->GetRight();
		}
		else
		{
			deleted = true;
			Node* tmp = currNode->Del();
			if (tmp != NULL)
			{
				parentNode = tmp;
			}
			delete(currNode);
			break;
		}
	}
	return deleted;
}
