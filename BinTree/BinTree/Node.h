#pragma once

#include<iostream>
using namespace std;

class Node
{
private:
	bool parentPosition;
	Node* parent;
	Node* right;
	Node* left;
	int data;
public:
	Node(int d, Node* par, bool parPos);
	int GetData();
	void AddNode(Node* newNode);
	void SetLeft(Node* n);
	void SetRight(Node* n);
	void Del();
};

