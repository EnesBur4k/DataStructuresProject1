#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp
#include "SatirListesi.hpp"

class YoneticiDugum
{
public:
    SatirListesi* sListesiAdresi;
    YoneticiDugum(SatirListesi* sListesiAdresi);
    ~YoneticiDugum();
    YoneticiDugum* onceki;
    YoneticiDugum* sonraki;
    void cizgiCizdir();

};

#endif