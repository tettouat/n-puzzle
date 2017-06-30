#ifndef NOTHING_HPP
# define NOTHING_HPP

# include "IHeuristic.hpp"

class Nothing : public IHeuristic {
public:
	Nothing();
	Nothing(Nothing const &src);
	~Nothing();

	Nothing &operator=(Nothing const &rhs);
	virtual int	distance(const unsigned short * const *map) const ;
};

#endif
