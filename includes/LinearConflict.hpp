#ifndef LINEARCONFLICT_HPP
# define LINEARCONFLICT_HPP

# include <list>
# include "Manhattan.hpp"
# include <iostream>

class LinearConflict : public Manhattan {

public:
  LinearConflict();
  LinearConflict(unsigned short **finalMap, size_t size);
  LinearConflict(LinearConflict const &src);
  ~LinearConflict();

  LinearConflict  &operator=(LinearConflict const &rhs);
  virtual int		distance(const unsigned short * const *map) const;

private:
  std::list<unsigned short> *rows;
  std::list<unsigned short> *cols;
};

#endif
