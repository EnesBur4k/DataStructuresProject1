#ifndef Dugum_hpp
#define Dugum_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Dugum
{
public:
    int veri;
    Dugum(double veri);
    ~Dugum();
    Dugum* onceki;
    Dugum* sonraki;
    void adresYazdir(int sira);
    void degerYazdir(int sira);
    void sonrakiDugumYazdir(int sira);

};

#endif