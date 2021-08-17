#include "Node.h"
/*
* Constructs a new node with no children, the parent and a boolean representing whether this node is to the left (false) or right (true) 
* of it's parent
*/
Node::Node(int d, Node* par, bool parPos)
{
	parent = par;
	parentPosition = parPos;
	data = d;
	//set the left and right nodes to NULL since there were no child nodes passed in
	right = NULL;
	left = NULL;
}
/*
* returns this nodes data variable
*/
int Node::GetData()
{
	return data;
}
/*
* adds the passed new node to the approriate side. If that side is already occupied, calls this method in the child
*/
void Node::AddNode(Node* newNode)
{
	if (newNode->GetData() > data)
	{
		if (right == NULL)
		{
			right = newNode;
		}
		else
		{
			right->AddNode(newNode);
		}
	}
	else if (newNode->GetData() < data)
	{
		if (left == NULL)
		{
			left = newNode;
		}
		else
		{
			left->AddNode(newNode);
		}
	}
	else
	{
		cout << "This node is either duplicate or incomprehensible data, did not add" << endl;
	}
}
/*
* sets the left child node
*/
void Node::SetLeft(Node* n)
{
	left = n;
}
/*
* sets the right child node
*/
void Node::SetRight(Node* n)
{
	right = n;
}
/*
* reassigns children of the parent to complete before freeing this node
*/
void Node::Del()
{
	//if this node has 2 children, adds the left child to the right then adds that right node to this node's parent.
	if (right != NULL && left != NULL)
	{
		right->AddNode(left);
		if (parentPosition)
		{
			parent->SetRight(NULL);
			parent->AddNode(right);
		}
		else
		{
			parent->SetLeft(NULL);
			parent->AddNode(right);
		}
	}
	//if the right child is the only one that exists exists, set this nodes parent to it's right child before deleting it
	else if (right != NULL)
	{
		if (parentPosition)
		{
			parent->SetRight(right);
		}
		else
		{
			parent->SetLeft(right);
		}
	}
	//if the left child is the only one that exists, set this nodes parent to it's left child before deleting it
	else if (left != NULL)
	{
		if (parentPosition)
		{
			parent->SetRight(left);
		}
		else
		{
			parent->SetLeft(left);
		}
	}
	//if this node has no children, it is a leaf and for deletion we just have to set it's postion in it's parent as NULL
	else
	{
		if (parentPosition)
		{
			parent->SetRight(NULL);
		}
		else
		{
			parent->SetLeft(NULL);
		}
	}
}