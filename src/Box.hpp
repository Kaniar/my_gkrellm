//
// Box.hpp for Box in /home/kania_r/rendu/cpp_gkrellm
// 
// Made by Romain Kania
// Login   <kania_r@epitech.net>
// 
// Started on  Sat Jan 21 12:32:08 2017 Romain Kania
// Last update Sat Jan 21 17:27:58 2017 Romain Kania
//

#ifndef BOX_HPP_
# define BOX_HPP_

#include <ncurses.h>
#include <vector>
#include <string>

class	Box
{
private:
  std::string name;
  WINDOW *win;
  int x;
  int y;
  int height;
  int width;
  std::string data;
public:
  Box(const std::string &, int, int, int, int);
  Box(const Box &);
  ~Box(){};
  std::string getName() const;
  WINDOW *getWin() const;
  int	getX() const;
  int	getY() const;
  int	getHeight() const;
  int	getWidth() const;
  std::string getData() const;
  void	setData(const std::string &);
  void	setWin(WINDOW *);
};

#endif
