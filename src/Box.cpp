//
// Box.cpp for Box in /home/kania_r/rendu/cpp_gkrellm
// 
// Made by Romain Kania
// Login   <kania_r@epitech.net>
// 
// Started on  Sat Jan 21 12:37:05 2017 Romain Kania
// Last update Sat Jan 21 16:16:08 2017 Romain Kania
//

#include "Box.hpp"

Box::Box(const std::string &name, int x, int y, int width, int height)
{
  this->name = name;
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

Box::Box(const Box &box)
{
  this->name = box.name;
  this->x = box.x;
  this->y = box.y;
  this->width = box.width;
  this->height = box.height;
}

std::string	Box::getName() const
{
  return (this->name);
}

int		Box::getX() const
{
  return (this->x);
}

int		Box::getY() const
{
  return (this->y);
}

int		Box::getHeight() const
{
  return (this->height);
}

int		Box::getWidth() const
{
  return (this->width);
}

WINDOW		*Box::getWin() const
{
  return (this->win);
}

void		Box::setWin(WINDOW *win)
{
  this->win = win;
}

std::string	Box::getData() const
{
  return (this->data);
}

void		Box::setData(const std::string &data)
{
  this->data = data;
}
