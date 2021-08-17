#include "Node.h"
/*
* This is the main constructor, all these values except for data get instantiated within the add function, so passing them in is redundant
*/
Node::Node(int d)
{
	//initializes all values except for data to NULL
	parent = NULL;
	parentPosition = NULL;
	data = d;
	right = NULL;
	left = NULL;
}
/*
* Constructs a new node with no children, the parent and a boolean representing whether this node is to the left (false) or right (true) 
* of it's parent
*/
Node::Node(int d, Node* par, bool parPos)
{
	parent = par;
	parentPosition = parPos;
	data = d;
	//initialize left and right to NULL
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
bool Node::AddNode(int newData)
{
	
	if (newData > data)
	{
		if (right == NULL)
		{
			Node* newNode = new Node(newData);
			right = newNode;
			right->SetParent(this, RIGHT);
		}
		else
		{
			right->AddNode(newData);
		}
	}
	else if (newData < data)
	{
		if (left == NULL)
		{
			Node* newNode = new Node(newData);
			left = newNode;
			left->SetParent(this, LEFT);
		}
		else
		{
			left->AddNode(newData);
		}
	}
	else
	{
		cout << "This node is either duplicate or incomprehensible data. It did not get added to the tree" << endl;
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
* sets the parent of this node
*/
void Node::SetParent(Node* n, bool pos)
{
	parent = n;
	parentPosition = pos;
}

Node* Node::GetLeft()
{
	return left;
}

Node* Node::GetRight()
{
	return right;
}
/*
* reassigns children of the parent to complete before freeing this node. Returns a pointer to the new parent of the entire tree, if there
* is one. Otherwise returns NULL
*/
Node* Node::Del()
{
	//if this variable remains NULL, the parent node will remain unchanged. If it does not, this method returns the pointer to the new 
	//parent node
	Node* returnNode = NULL;
	//if this is the parent of the tree, set the right node, if it is available, to the new parent of the tree,
	//else set the left node as the parent if it is availabe. if neither is a variable, nothing happens and this node gets deleted
	//leaving the tree empty
	if (parent == NULL)
	{
		//if there is a right and a left child, find the furthest left child of the right tree. This will be the new parent node
		if (right != NULL && left != NULL)
		{
			Node* temp = right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			temp->parent->SetLeft(NULL);
			temp->SetLeft(left);
			temp->SetRight(right);
			temp->SetParent(NULL, NULL);
			returnNode = temp;
		}
		//if there is only a left or a right child, that child becomes the new parent node of the entire tree.
		else if (right != NULL)
		{
			right->SetParent(NULL, NULL);
			returnNode = right;
		}
		else if (left != NULL)
		{
			left->SetParent(NULL, NULL);
			returnNode = left;
		}
	}
	//if this node has 2 children, finds the furthest left node in the right tree to be the successor then updates that node with it's
	//new left, right and parent values
	if (right != NULL && left != NULL)
	{
		Node* temp = right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		temp->parent->SetLeft(NULL);
		temp->SetLeft(left);
		temp->SetRight(right);
		temp->SetParent(parent, parentPosition);
		if (parentPosition)
		{
			temp->parent->SetRight(temp);
		}
		else
		{
			temp->parent->SetLeft(temp);
		}
		returnNode = temp;
	}
	//if the right child is the only one that exists, replaces this node with the right node and updates this node's parent
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
		right->SetParent(parent, parentPosition);
	}
	//if the left child is the only one that exists, replaces this node with the left node and updates this node's parent
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
		left->SetParent(parent, parentPosition);
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
	return returnNode;
}