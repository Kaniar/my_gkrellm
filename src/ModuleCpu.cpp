//
// ModuleCpu.cpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 16:32:59 2017 Alexandre BARA
// Last update Sat Jan 21 19:01:19 2017 Romain Kania
//
#include <chrono>
#include <thread>
#include "ModuleCpu.hpp"
#include <sstream>
#include <fstream>

unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();

    while(pos < txt.size())
    {
        strs.push_back(txt.substr(initialPos,pos - initialPos));
        initialPos = pos + 1;
        pos = txt.find( ch, initialPos );
    }

    return strs.size();
}

ModuleCpu::ModuleCpu()
{
    this->name = "CPU";
    this->isOpen = true;

    std::ifstream file("/proc/stat");
    std::string str;
    std::vector<std::string> tab;
    std::vector<int> total;
    std::vector<int> working;
    std::vector<float> percent;
    int	i = 0;
    int	j = 0;
    int	tmp;
    int	check;
    int count = 0;

    if (file)
    {
        while (getline(file, str))
        {
            split(str, tab, ' ');
            check = 0;
            i = 0;
	    if (str.substr(0, 3) == "cpu")
	      count++;
	    for(std::vector<std::string>::iterator it = tab.begin();it != tab.end();++it)
            {
                if (i == 0 && (*it).substr(0, 3) == "cpu")
                {
                    check = 1;
                    total.push_back(0);
                    working.push_back(0);
                }
                if (i != 0 && check== 1 && *it != "")
                {
                    if (i < 4)
                    {
                        std::istringstream(*it) >>tmp;
                        working[j] += tmp;
                    }
                    std::istringstream (*it) >> tmp;
                    total[j] += tmp;
                }
                i++;
            }
            j++;
        }
    }

    std::string str2;
    std::vector<std::string> tab2;
    std::vector<int> total2;
    std::vector<int> working2;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::ifstream file2("/proc/stat");
    j = 0;
    if (file2)
    {
        while (getline(file2, str2))
        {
            split(str2, tab2, ' ');
            check = 0;
            i = 0;
            for(std::vector<std::string>::iterator it = tab2.begin();it != tab2.end();++it)
            {
                if (i == 0 && (*it).substr(0, 3) == "cpu")
                {
                    check = 1;
                    total2.push_back(0);
                    working2.push_back(0);
                }
                if (i != 0 && check== 1 && *it != "")
                {
                    if (i < 4)
                    {
                        std::istringstream(*it) >>tmp;
                        working2[j] += tmp;
                    }
                    std::istringstream (*it) >> tmp;
                    total2[j] += tmp;
                }
                i++;
            }
            j++;
        }
    }

    int k = 0;

    for (std::vector<int>::iterator iterator = working.begin();iterator != working.end();++iterator)
    {
        percent.push_back(0);
        percent[k] = (static_cast<float>(*iterator) - static_cast<float>(working2[k])) / (static_cast<float>(total[k]) -static_cast<float>(total2[k])) * 100.0;
        k++;
    }
    this->nb = count;
    this->working = working;
    this->total = total;
    this->percent = percent;
    this->data = data;
}

ModuleCpu::ModuleCpu(const ModuleCpu& ot)
{
    this->name = "CPU";
    this->isOpen = ot.getIsOpen();
    this->data = ot.getData();
}

ModuleCpu&     ModuleCpu::operator=(const ModuleCpu &ot)
{
    this->name = "Name";
    this->isOpen = ot.getIsOpen();
    this->data == ot.getData();
    return *this;
}

const std::vector<std::string>& ModuleCpu::getData() const
{
    return this->data;
}

bool    ModuleCpu::getIsOpen() const {return this->isOpen;}
std::vector<int>     ModuleCpu::getTotal() const {return this->total;}
std::vector<int>     ModuleCpu::getWorking() const {return this->working;}
std::vector<float>     ModuleCpu::getPercent() const {return this->percent;}
int     ModuleCpu::getNb() const {return this->nb;}
