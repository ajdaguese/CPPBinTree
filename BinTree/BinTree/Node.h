#pragma once

#include<iostream>
using namespace std;

class Node
{
	Node* right;
	Node* left;
	int data;
	/*
	* Constructs a new node with no children
	*/
	Node(int d)
	{
		data = d;
		//set the left and right nodes to NULL since there were no child nodes passed in
		right = NULL;
		left = NULL;
	}
	/*
	* Constructs a new node with both a left (data is less than) and a right (data is greater than) child
	*/
	Node(int d, Node* r, Node* l)
	{
		//if the given right's data integer is greater than the data integer for this node, set this node's right to the given right,
		//else the given data is incorrect so set this nodes right to NULL
		if (r->data > d)
		{
			right = r;
		}
		else
		{
			cout << "attempted right node is not greater than this node, setting right node to NULL" << endl;
			right = NULL;
		}
		//if the given left's data integer is less than the data integer for this node, set this node;s left to the given left,
		//else the given data is incorrect so set this nodes left to NULL
		if (l->data < d)
		{
			left = l;
		}
		else
		{
			cout << "attempted left node is not greater than this node, setting left node to NULL" << endl;
			left = NULL;
		}
		data = d;
	}
	/*
	* Constructs a new node with just a right child
	*/
	Node(int d, Node* r)
	{
		//if the given right's data integer is greater than the data integer for this node, set this node's right to the given right,
		//else the given data is incorrect so set this nodes right to NULL
		if (r->data > d)
		{
			right = r;
		}
		else
		{
			cout << "attempted right node is not greater than this node, setting right node to NULL" << endl;
			right = NULL;
		}
		//set the left value to NULL as there was no left node passed
		left = NULL;
		data = d;
	}
	Node(int d, Node* l)
	{
		//if the given left's data integer is greater than the data integer for this node, set this node's left to the given left,
		//else the given data is incorrect so set this nodes left to NULL
		if (l->data > d)
		{
			left = l;
		}
		else
		{
			cout << "attempted left node is not lesser than this node, setting left node to NULL" << endl;
			left = NULL;
		}
		//set the right value to NULL as there was no right node passed
		right = NULL;
		data = d;
	}
};

