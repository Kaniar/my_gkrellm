//
// text.cpp for text in /home/kania_r/rendu/cpp_gkrellm
// 
// Made by Romain Kania
// Login   <kania_r@epitech.net>
// 
// Started on  Sat Jan 21 10:10:31 2017 Romain Kania
// Last update Sun Jan 22 09:39:52 2017 Romain Kania
//

#include <unistd.h>
#include <cstring>
#include <ncurses.h>
#include <iostream>
#include <cmath>
#include "MonitorDisplay.hpp"
#include "Box.hpp"
#include "ModuleName.hpp"
#include "ModuleTime.hpp"
#include "ModuleOS.hpp"
#include "ModuleRam.hpp"
#include "ModuleCpu.hpp"
#include "sfml.hpp"

void		init(Box &my_box)
{
  WINDOW *win;

  win = newwin(my_box.getHeight(), my_box.getWidth(), my_box.getY(), my_box.getX());
  my_box.setWin(win);
  box(my_box.getWin(), 0, 0);
}

void		init_OS(Box &box_OS)
{
  ModuleOS mod_OS;
  int		y = 2;
  std::vector<std::string> vec = mod_OS.getData();
  std::vector<std::string>::iterator it = vec.begin();  

  init(box_OS);
  mvwaddstr(box_OS.getWin(), 0, 2, box_OS.getName().c_str());
  for (it = vec.begin() ; it != vec.end() ; ++it)
    mvwaddstr(box_OS.getWin(), y++, 2, (*it).c_str());
}

void		init_time(Box &box_time)
{
  ModuleTime mod_time;
  int		y = 2;
  std::vector<std::string> vec = mod_time.getData();
  std::vector<std::string>::iterator it = vec.begin();  

  init(box_time);
  mvwaddstr(box_time.getWin(), 0, 2, box_time.getName().c_str());
  for (it = vec.begin() ; it != vec.end() ; ++it)
    mvwaddstr(box_time.getWin(), y++, 2, (*it).c_str());
}

void		init_name(Box &box_name)
{
  ModuleName name;
  int		y = 2;

  std::vector<std::string> vec = name.getData();
  std::vector<std::string>::iterator it = vec.begin();

  init(box_name);
  mvwaddstr(box_name.getWin(), 0, 2, box_name.getName().c_str());
  for (it = vec.begin() ; it != vec.end() ; ++it)
    mvwaddstr(box_name.getWin(), y++, 2, (*it).c_str());
}

void		init_RAM(Box &box_RAM)
{
  ModuleRam	ram;
  int		memtotal = ram.getTotMem();
  int	        memused = ram.getUsedMem();
  int		nbofpipe = 58 * memused / memtotal;
  int		x = 2;
  
  init(box_RAM);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  mvwaddstr(box_RAM.getWin(), 0, 2, box_RAM.getName().c_str());
  mvwprintw(box_RAM.getWin(), 0, 5, "[%.1fG / %.1fG]", static_cast<float>(memused / 1000000.00), static_cast<float>(memtotal / 1000000.00));
  wattron(box_RAM.getWin(), COLOR_PAIR(1));
  for(int i = 0; i < nbofpipe ; i++)
    mvwprintw(box_RAM.getWin(), 1, x++, "|");
  wattroff(box_RAM.getWin(), COLOR_PAIR(1));
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  wattron(box_RAM.getWin(), COLOR_PAIR(2));
  while (x < 59)
    mvwprintw(box_RAM.getWin(), 1, x++, "|");
  wattroff(box_RAM.getWin(), COLOR_PAIR(2));
}

Box		init_CPU(int row, int col)
{
  ModuleCpu cpu;
  int	nb_cpu = cpu.getNb();
  int	y = 2;
  int	nb_bar = 2;
  int	nb;
  int	i = 0;
  Box box_cpu("CPU", col / 2 - 30, row / 2 - 3 * nb_cpu + (nb_cpu + 2), 60, 3 * nb_cpu + (nb_cpu + 2));
  std::vector<float>pourcentage = cpu.getPercent();
  
  init(box_cpu);
  start_color();
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  mvwaddstr(box_cpu.getWin(), 0, 2, box_cpu.getName().c_str());
  for (std::vector<float>::iterator it = pourcentage.begin() ; it != pourcentage.end(); ++it)
    {
      nb_bar = 2;
      for (int x = 1; x <= 58 ; ++x)
	mvwprintw(box_cpu.getWin(), y, x, "-");
      y++;
      if (i == 0)
	mvwprintw(box_cpu.getWin(), y++, 2, "Total");
      nb = static_cast<int>(*it);
      nb = 58 * nb / 100;
      mvwprintw(box_cpu.getWin(), y, 2, "%d%%", static_cast<unsigned int>(*it));
      y++;
      wattron(box_cpu.getWin(), COLOR_PAIR(3));
      while (nb_bar <= nb)
	mvwprintw(box_cpu.getWin(), y, nb_bar++, "|");
      wattroff(box_cpu.getWin(), COLOR_PAIR(3));
      wattron(box_cpu.getWin(), COLOR_PAIR(4));
      while (nb_bar <= 58)
	mvwprintw(box_cpu.getWin(), y, nb_bar++, "|");
      y++;
      wattroff(box_cpu.getWin(), COLOR_PAIR(4));
      i++;
    }
  return box_cpu;
}

void		update(Box &box_name)
{
  wrefresh(box_name.getWin());
}

void		init_network(Box &box)
{
  init(box);
  mvwaddstr(box.getWin(), 0, 2, box.getName().c_str());
  mvwaddstr(box.getWin(), 2, 2, "Coming Soon");
}

void		programm()
{
  int		key = 1;
  int		row;
  int		col;
 
  getmaxyx(stdscr, row, col);
  Box		box_name("Machine name and user name", 4, 4, 30, 5);
  Box		box_time("Date and Time", col - 32, 4, 30, 5);
  Box		box_OS("OS and Kernel Version", 4, row - 5, 30, 5);
  Box		box_RAM("Mem", col / 2 - (30), 4, 60, 3);
  Box box_CPU = init_CPU(row, col);
  Box		box_network("Network load", col - 32, row - 5, 30, 5);
  while (key != 10)
    {
      init_name(box_name);
      init_OS(box_OS);
      init_RAM(box_RAM);
      init_time(box_time);
      init_network(box_network);
      init_RAM(box_RAM);
      box_CPU = init_CPU(row, col);
      update(box_name);
      update(box_network);
      update(box_time);
      update(box_OS);
      update(box_RAM);
      update(box_CPU);
      key = getch();
    }
  delwin(box_name.getWin());
  delwin(box_OS.getWin());
  delwin(box_time.getWin());
  delwin(box_CPU.getWin());
}

void		dispwindow()
{
  int		row;
  int		col;

  initscr();
  getmaxyx(stdscr, row, col);
  curs_set(0);
  noecho();
  nodelay(stdscr, TRUE);
  if (row >= 40 && col >= 130)
    {
      programm();
      refresh();
      endwin();
    }
  else
    {
      endwin();
      std::cerr << "Minimum resolution: 130x40" << std::endl;
    }
}

void		textmode()
{
  dispwindow();
}

int		main(int ac, char **av)
{
  IMonitorDisplay *mode = new MonitorDisplay();
  
  if (ac == 1)
    {
      mode->setMode("Graphique");
      sfml();
      return (0);
    }
  if (strcmp(av[1], "-graph") == 0)
    {
      mode->setMode("Graphique");
      sfml();
      return (0);
    }
  else if (strcmp(av[1], "-text") == 0)
    {
      mode->setMode("Text");
      textmode();
      return (0);
    }
  std::cout << "USAGE: ./mygkrellm [-graph / -text]" << std::endl;
  delete mode;
  return (0);
}
