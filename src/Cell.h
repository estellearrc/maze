#ifndef __CELL_H__
#define __CELL_H__

#include <cstdlib>
#include <fstream>
#include <iostream>

class Cell
{
  //external operator overwrite
  friend std::ostream &operator<<(std::ostream &stream, const Cell &c);
  friend std::istream &operator>>(std::istream &stream, Cell &c);

public:
  Cell(int x, int y);
  ~Cell();
  void add_neighb(Cell *n1);
  void add_neighb(Cell *n1, Cell *n2);
  void add_neighb(Cell *n1, Cell *n2, Cell *n3);
  void to_string() const;

  // protected:
  int m_x, m_y;
  int m_nb_neighb = 0;
  Cell **m_neighb = NULL;
  bool m_displayed = false;
  bool m_flag = false;
  bool m_saved = false;
};

#endif