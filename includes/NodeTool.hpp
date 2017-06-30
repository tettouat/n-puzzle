#ifndef NODETOOL_HPP
# define NODETOOL_HPP

# include <stack>
# include "Node.hpp"

class NodeTool {
public:
	NodeTool(void);
	NodeTool(const NodeTool& src);
	NodeTool(size_t size);
	~NodeTool(void);

	NodeTool&	operator=(const NodeTool& rhs);

	void		allocateNodes(size_t number);
	Node*		newNode(void);
	void		delNode(Node*);

private:
	std::stack<Node*>	freeNodes;
	size_t				size;
};

#endif
