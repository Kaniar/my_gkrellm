//
// MonitorDisplay.cpp for Moni in /home/kania_r/rendu/cpp_gkrellm/src
// 
// Made by Romain Kania
// Login   <kania_r@epitech.net>
// 
// Started on  Sun Jan 22 09:30:59 2017 Romain Kania
// Last update Sun Jan 22 09:36:12 2017 Romain Kania
//

#include "MonitorDisplay.hpp"

MonitorDisplay::MonitorDisplay()
{
}

std::string	MonitorDisplay::getMode() const
{
  return (this->mode);
}

void		MonitorDisplay::setMode(const std::string &mode)
{
  this->mode = mode;
}
