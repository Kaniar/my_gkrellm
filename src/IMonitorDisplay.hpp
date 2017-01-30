//
// IMonitorDisplay.hpp for IMonitorDis in /home/kania_r/rendu/cpp_gkrellm/src
// 
// Made by Romain Kania
// Login   <kania_r@epitech.net>
// 
// Started on  Sun Jan 22 09:28:10 2017 Romain Kania
// Last update Sun Jan 22 09:40:52 2017 Romain Kania
//

#ifndef IMONITORDISPLAY_HPP_
# define IMONITORDISPLAY_HPP_

#include <string>

class IMonitorDisplay
{
public:
  virtual std::string getMode() const = 0;
  virtual void setMode(const std::string &) = 0;
  virtual ~IMonitorDisplay(){};
};

#endif
