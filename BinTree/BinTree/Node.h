#pragma once

#include<iostream>
using namespace std;

class Node
{
private:
	const bool LEFT = false;
	const bool RIGHT = true;
	bool parentPosition;
	Node* parent;
	Node* right;
	Node* left;
	int data;
public:
	Node(int d);
	Node(int d, Node* par, bool parPos);
	int GetData();
	bool AddNode(int newData);
	void SetLeft(Node* n);
	void SetRight(Node* n);
	void SetParent(Node* n, bool pos);
	Node* GetLeft();
	Node* GetRight();
	Node* Del();
};

