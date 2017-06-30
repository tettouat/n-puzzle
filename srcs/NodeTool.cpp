#include "NodeTool.hpp"

#include <iostream>

NodeTool::NodeTool(size_t size)
{
	this->size = size;
	this->allocateNodes(1000);
}

#include <iterator>

void	NodeTool::allocateNodes(size_t number)
{
	size_t	size = this->size;
	size_t	size2 = size * size;
	Node*	nodes = new Node[number];
	unsigned short**	pmaps = new unsigned short*[size * number];
	unsigned short*	maps = new unsigned short[size * size * number];

	for (size_t i = 0; i < number; i++)
	{
		nodes[i].size = size;
		nodes[i].map = pmaps + i * size;
		for (size_t j = 0; j < size; j++)
		{
			nodes[i].map[j] = maps + (i * size2) + j * size;
		}
		this->freeNodes.push(nodes + i);
	}
}

Node*	NodeTool::newNode(void)
{
	Node*	tmp;

	if (this->freeNodes.empty())
	{
		this->allocateNodes(1000);
	}
	tmp = this->freeNodes.top();
	this->freeNodes.pop();
	return (tmp);
}

void	NodeTool::delNode(Node* node)
{
	this->freeNodes.push(node);
}

NodeTool::~NodeTool(void)
{
}
