#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y) : m_x(x), m_y(y)
{
}

Cell::~Cell()
{
}

void Cell::add_neighb(Cell *n1)
{
  for (int i = 0; i < m_nb_neighb; i++)
    if (m_neighb[i] == n1)
      return;

  m_nb_neighb++;

  Cell **new_neighb = new Cell *[m_nb_neighb];
  for (int i = 0; i < m_nb_neighb - 1; i++)
    new_neighb[i] = m_neighb[i];

  new_neighb[m_nb_neighb - 1] = n1;
  delete[] m_neighb;
  m_neighb = new_neighb;

  n1->add_neighb(this);
}

void Cell::add_neighb(Cell *n1, Cell *n2)
{
  add_neighb(n1);
  add_neighb(n2);
}

void Cell::add_neighb(Cell *n1, Cell *n2, Cell *n3)
{
  add_neighb(n1);
  add_neighb(n2);
  add_neighb(n3);
}

void Cell::to_string() const
{
  cout << "   Position cellule : x = " << m_x << " y = " << m_y << " -> Adresse cellule : " << this << endl;
  cout << "   Liste des voisins :" << endl;
  for (int i = 0; i < m_nb_neighb; i++)
  {
    cout << "           x = " << m_neighb[i]->m_x << " y = " << m_neighb[i]->m_y << " -> Adresse cellule : " << m_neighb[i] << m_y << endl;
  }
}

ostream &operator<<(ostream &stream, const Cell &c)
{
  stream << endl
         << "(" << c.m_x << "," << c.m_y << ")";
  if (c.m_nb_neighb > 0)
  {
    stream << c.m_nb_neighb;
  }
  for (int i = 0; i < c.m_nb_neighb; i++)
  {
    stream << "(" << c.m_neighb[i]->m_x << "," << c.m_neighb[i]->m_y << ")";
  }
  return stream;
}
istream &operator>>(istream &stream, Cell &c)
{
  int cell_length = 5;
  int count = 0;
  bool is_a_cell;
  string input;
  do
  {
    is_a_cell = true;
    char p = stream.get();
    // cout << "p = " << p << endl;
    if (p == '\n')
      p = stream.get();
    if (p == '#')
    {
      //ignores the comment lines
      string line;
      getline(stream, line);
      is_a_cell = false;
      count = 0;
    }
    if (is_a_cell)
    {
      //stacks characters of the cell
      input += p;
      count++;
    }

  } while (count < cell_length);
  if (is_a_cell)
  {
    cout << "cell read : " << input << endl;
    atoi(&input[1]) >> c.m_x;
    atoi(&input[3]) >> c.m_y;
  }

  return stream;
}