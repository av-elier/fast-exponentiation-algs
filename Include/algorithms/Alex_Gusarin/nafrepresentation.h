#ifndef NAFREPRESENTATION_H
#define NAFREPRESENTATION_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

class NAFRepresentation//класс для представления числа в форме NAF
{
public:
    NAFRepresentation();
    ~NAFRepresentation();
    void createNAF(NTL::ZZ& val);
    char getBitVal(unsigned long long pos);
    void setSize(unsigned long long sz);
    unsigned long long getSize();
    long long getValueOnInterval(unsigned long long i,unsigned long long s);// i - s <= 63 && i - s >= 0
private:
    void setBitVal(unsigned long long pos,char v);

    unsigned long long blockNumber;//количество блоков (char), отведённых под NAF
    unsigned long long size;//длина битовой последовательности
    unsigned char* NAF;//массив значений (побитовый)
    unsigned char* sign;//знак элемента
};

#endif // NAFREPRESENTATION_H
