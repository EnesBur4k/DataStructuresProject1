#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "YoneticiDugum.hpp"

class YoneticiListesi
{

public:
    YoneticiDugum* ilkYoneticiDugum;

    YoneticiListesi();
    ~YoneticiListesi();
    void ekle(SatirListesi* sListesiAdresi);
    void sil(int silinecek);
    void cizgiCizdir(int index);
    void adresYazdir(int index);
    void oncekiDugumYazdir(int index);
    void sonrakiDugumYazdir(int index);
    void ortYazdir(int index);
    void yazdir(int index, int sira, int ySirasi);
};

#endif