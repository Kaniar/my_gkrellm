//
// MonitorDisplay.hpp for mon in /home/kania_r/rendu/cpp_gkrellm/src
// 
// Made by Romain Kania
// Login   <kania_r@epitech.net>
// 
// Started on  Sun Jan 22 09:29:34 2017 Romain Kania
// Last update Sun Jan 22 09:35:46 2017 Romain Kania
//

#ifndef MONITORDISPLAY_HPP_
# define MONITORDISPLAY_HPP_

#include <string>
#include "IMonitorDisplay.hpp"

class	MonitorDisplay : public IMonitorDisplay
{
private:
  std::string	mode;
public:
  MonitorDisplay();
  virtual void	      setMode(const std::string &);
  virtual std::string getMode() const;
};


#endif
