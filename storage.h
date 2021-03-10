#ifndef MYSTORAGE_H
#define MYSTORAGE_H

#include <EEPROM.h>


template <typename STRUCT> 
class Storage{
  public:
  Storage(int address, int size);
  void clear();
  void setData(STRUCT data);
  void getData(STRUCT& data);
  
  private:
  int _address;
  int _size;
};

#include "storage.cpp.h"
#endif
