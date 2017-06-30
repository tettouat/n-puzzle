#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>

struct Node
{
	struct	Square {
		Square(int x, int y) : x(x), y(y) {}
		Square(void) {}
		int	x;
		int	y;
	};

	Node();
	Node(size_t size);
	Node(const Node& src);
	Node(const unsigned short * const * map, int size);
	Node(const unsigned short * const * map, int size, int cost, int heuristic, unsigned short pos0[2], Node *parent);
	~Node();
	void	setMap(const unsigned short * const * map);
	Square	find0(const unsigned short * const * map, size_t size);
	void	dump(void) const;
	unsigned short*	square(const Square& s) const;
	void	hash(void);

	Node&	operator=(const Node& rhs);

	unsigned short	**map;
	size_t	size;
	int		cost;
	int		heuristic;
	int		distance;
	Node	*parent;
	Square	pos0;
	size_t	_hash;
};

Node::Square	operator+(Node::Square lhs, const Node::Square& rhs);

bool	operator==(const Node& lhs, const Node& rhs);
bool	operator<(const Node& lhs, const Node& rhs);

#endif
