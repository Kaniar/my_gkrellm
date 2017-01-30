//
// ModuleRAM.cpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 12:46:30 2017 Alexandre BARA
// Last update Sat Jan 21 12:46:31 2017 Alexandre BARA
//

#include "ModuleRam.hpp"
#include <sstream>
#include <fstream>

ModuleRam::ModuleRam()
{
    this->name = "RAM";
    this->isOpen = true;

    std::ifstream file("/proc/meminfo");
    std::vector<std::string> data;
    int i = 0;
    std::string str;
    if (file)
    {
        while (getline(file, str) && i != 6)
        {
            data.push_back(str);
            i++;
        }
    }
    std::istringstream (data[0].substr(10, data[0].size() - 3)) >> this->TotMem;
    std::istringstream (data[1].substr(10, data[1].size() - 3)) >> this->FreeMem;
    std::istringstream (data[2].substr(10, data[2].size() - 3)) >> this->BuffMem;
    std::istringstream (data[3].substr(10, data[3].size() - 3)) >> this->CachedMem;
    std::istringstream (data[4].substr(10, data[4].size() - 3)) >> this->SwapCachedMem;
    this->UsedMem = this->TotMem - (this->FreeMem + this->BuffMem + this->CachedMem + this->SwapCachedMem);
    this->data = data;
}

ModuleRam::ModuleRam(const ModuleRam& ot)
{
    this->name = "Name";
    this->isOpen = ot.getIsOpen();
    this->data = ot.getData();
}

ModuleRam&     ModuleRam::operator=(const ModuleRam &ot)
{
    this->name = "Name";
    this->isOpen = ot.getIsOpen();
    this->data == ot.getData();
    return *this;
}

const std::vector<std::string>& ModuleRam::getData() const
{
    return this->data;
}

bool    ModuleRam::getIsOpen() const
{return this->isOpen;}
int     ModuleRam::getTotMem() const {return this->TotMem;}
int     ModuleRam::getBuffMem() const {return this->BuffMem;}
int     ModuleRam::getFreeMem() const {return this->FreeMem;}
int     ModuleRam::getCachedMem() const {return this->CachedMem;}
int     ModuleRam::getSwapCachedMem() const {return this->SwapCachedMem;}
int     ModuleRam::getUsedMem() const {return this->UsedMem;}