#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "Dugum.hpp"

using namespace std;

class SatirListesi
{
public:
    Dugum* ilkDugum;
    int ort;
public:
    SatirListesi();
    ~SatirListesi();
    void ekle(double veri);
    void sil(int silinecekDugum);
    void cizgiCizdir(int sira);
    void tireCizdir(int sira);
    void adresYazdir(int sira);
    void degerYazdir(int sira);
    void sonrakiDugumYazdir(int sira);
    void yazdir(int sira);
    int elemanSayisi();
    float ortBul();
};

#endif