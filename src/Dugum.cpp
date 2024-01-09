/** 
* @file Dugum.cpp
* @description Düğüm yapısını oluşturur.
* @course Birinci Öğretim A Grubu
* @assignment 1.Ödev
* @date 25.11.2022
* @author Enes Burak Kaya enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(double veri)
{
    this->veri=veri;
    onceki=0;
    sonraki=0;
}
Dugum::~Dugum()
{
    
}
void Dugum::adresYazdir(int sira) // Bu nesnenin heapte tutulduğu adresi yazdırır.
{
    for(int i = 1; i < sira; i++)  cout << "             ";
    cout << " " << this;
    cout << endl;
    for(int i = 1; i < sira; i++)  cout << "             ";
    cout << "-----------" << endl;
}
void Dugum::degerYazdir(int sira) // Bu nesnenin heapte tuttuğu veriyi yazdırır.
{
    for(int i = 1; i < sira; i++)  cout << "             ";
    cout << "|" << setw(5) << this->veri << setw(5) << "|" << endl;
    for(int i = 1; i < sira; i++)  cout << "             ";
    cout << "-----------" << endl;
}
void Dugum::sonrakiDugumYazdir(int sira) // Bu nesnenin tuttuğu sonraki değişkenini yazdırır.
{
    for(int i = 1; i < sira; i++)  cout << "             ";
    cout << "|" << setw(9) << this->sonraki << "|" << endl;
    for(int i = 1; i < sira; i++)  cout << "             ";
    cout << "-----------" << endl;
}