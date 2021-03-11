

template <typename STRUCT>
Storage<STRUCT>::Storage(int address, int size){
    _address=address;
    _size=size;
  }
template <typename STRUCT> 
void Storage<STRUCT>::clear(){
    for (int i = _address ; i < (i+_size) ; i++) {
    EEPROM.write(i, 0);
  }
}
template <typename STRUCT>
void Storage<STRUCT>::setData(STRUCT data){
  EEPROM.put(_address, data);
}
  
template <typename STRUCT>
   void Storage<STRUCT>::getData(STRUCT& data){
   EEPROM.get((_address),data);
 }
