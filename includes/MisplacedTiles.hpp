#ifndef MISPLACEDTILES_HPP
# define MISPLACEDTILES_HPP

#include "Manhattan.hpp"

class MisplacedTiles : public Manhattan {

public:
  MisplacedTiles();
  MisplacedTiles(MisplacedTiles const &src);
  MisplacedTiles(unsigned short **final_map, size_t size);
  ~MisplacedTiles();

  MisplacedTiles &operator=(MisplacedTiles const &rhs);
  virtual int distance(const unsigned short * const *map) const;
};

#endif
