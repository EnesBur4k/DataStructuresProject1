/** 
* @file YoneticiDugum.cpp
* @description SatırListesi yapılarının adresini tutar.
* @course Birinci Öğretim A Grubu
* @assignment 1.Ödev
* @date 25.11.2022
* @author Enes Burak Kaya enes.kaya11@ogr.sakarya.edu.tr
*/

#include "YoneticiDugum.hpp"

YoneticiDugum::YoneticiDugum(SatirListesi* sListesiAdresi)
{
    this->sListesiAdresi=sListesiAdresi;
    onceki=0;
    sonraki=0;
}
YoneticiDugum::~YoneticiDugum()
{
    if(this->onceki == 0)
    {
        this->sonraki->onceki = this->onceki;
    }
    else if(this->sonraki == 0)
    {
        this->onceki->sonraki = this->sonraki;
    }
    else
    {
        this->sonraki->onceki = this->onceki;
        this->onceki->sonraki = this->sonraki;
    }
    delete sListesiAdresi;
}

void YoneticiDugum::cizgiCizdir()
{
    for(int i = 0; i < 8; i++)
    {
        if(this != 0)    cout << "-----------  " ;
    }

    cout << endl;
}