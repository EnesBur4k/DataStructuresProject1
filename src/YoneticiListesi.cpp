/** 
* @file YoneticiListesi.cpp
* @description YoneticiDugum sınıfını yönetir.
* @course Birinci Öğretim A Grubu
* @assignment 1.Ödev
* @date 25.11.2022
* @author Enes Burak Kaya enes.kaya11@ogr.sakarya.edu.tr
*/

#include "YoneticiListesi.hpp"

YoneticiListesi::YoneticiListesi()
{
    ilkYoneticiDugum = 0;
}
YoneticiListesi::~YoneticiListesi()
{
    YoneticiDugum* gec = ilkYoneticiDugum;
    YoneticiDugum* silinecek;
    
    while(gec != 0)
    {
        silinecek=gec;
        gec = gec->sonraki;
        delete silinecek;
    }
}
void YoneticiListesi::ekle(SatirListesi* sListesiAdresi)
{
    YoneticiDugum* yeniYoneticiDugum = new YoneticiDugum(sListesiAdresi);
    if(ilkYoneticiDugum==0)
    {
        ilkYoneticiDugum = yeniYoneticiDugum;
    }
    else
    {
        YoneticiDugum* gec = ilkYoneticiDugum;
        while(sListesiAdresi->ortBul() > gec->sListesiAdresi->ortBul()) // Satır Listelerinin ortalamasına göre Yönetici Listesine ekleme yapar.
        {
            if(gec->sonraki == 0)
            {
                gec->sonraki = yeniYoneticiDugum;
                yeniYoneticiDugum->onceki=gec;
                return;
            }
            gec = gec->sonraki;
        }
        if(gec->onceki == 0)
        {
            gec->onceki = yeniYoneticiDugum;
            yeniYoneticiDugum->sonraki = gec;
            ilkYoneticiDugum = yeniYoneticiDugum;
            return;
        }
        yeniYoneticiDugum->onceki = gec->onceki;
        yeniYoneticiDugum->sonraki = gec;
        gec->onceki->sonraki = yeniYoneticiDugum;
        gec->onceki = yeniYoneticiDugum;
        
        
    }
}
void YoneticiListesi::cizgiCizdir(int index)
{
    int sayac = 1;
    YoneticiDugum* gec = this->ilkYoneticiDugum;
    while(sayac < index)
    {
        gec = gec->sonraki;
        sayac++;
    }

    for(int i = 0; i < 8; i++)
    {
        if(gec != 0)    cout << "-----------  " ;
        if(gec != 0) gec = gec->sonraki;
    }

    cout << endl;
}
void YoneticiListesi::adresYazdir(int index)
{
    int sayac = 1;
    YoneticiDugum* gec = this->ilkYoneticiDugum;
    while(sayac < index) // Bir sayfada ilk hangi yönetici düğümü gösterilecekse o düğüme erişir.
    {
        gec = gec->sonraki;
        sayac++;
    }

    for(int i = 0; i < 8; i++)
    {
        if(gec != 0)
        {
            cout << setw(10) << gec << "   ";
            gec = gec->sonraki;
        }
    }
    cout << endl;
}
void YoneticiListesi::oncekiDugumYazdir(int index)
{
    int sayac = 1;
    YoneticiDugum* gec = this->ilkYoneticiDugum;
    while(sayac < index)
    {
        gec = gec->sonraki;
        sayac++;
    }

    for(int i = 0; i < 8; i++)
    {
        if(gec != 0)
        {
            cout << "|" << setw(9) << gec->onceki << "|" << "  ";
            gec = gec->sonraki;
        }
    }
    cout << endl;
}
void YoneticiListesi::ortYazdir(int index) // Satır Listesinin tuttuğu düğümlerin ortalamasını yazdırır.
{
    int sayac = 1;
    YoneticiDugum* gec = this->ilkYoneticiDugum;
    while(sayac < index)
    {
        gec = gec->sonraki;
        sayac++;
    }

    for(int i = 0; i < 8; i++)
    {
        if(gec != 0)
        {
            cout << "|" << setw(9) << gec->sListesiAdresi->ortBul() << "|" << "  ";
            gec = gec->sonraki;
        }
    }
    cout << endl;
}
void YoneticiListesi::sonrakiDugumYazdir(int index)
{
    int sayac = 1;
    YoneticiDugum* gec = this->ilkYoneticiDugum;
    while(sayac < index)
    {
        gec = gec->sonraki;
        sayac++;
    }

    for(int i = 0; i < 8; i++)
    {
        if(gec != 0)
        {
            cout << "|" << setw(9) << gec->sonraki << "|" << "  ";
            gec = gec->sonraki;
        }
    }
    cout << endl;
}

void YoneticiListesi::yazdir(int index, int sira, int ySirasi)
{
    YoneticiDugum* gec = this->ilkYoneticiDugum;
    for(int i = 1; i < ySirasi; i++)
    {
        gec = gec->sonraki;
    }

    this->adresYazdir(index);
    this->cizgiCizdir(index);
    this->oncekiDugumYazdir(index);
    this->cizgiCizdir(index);
    this->ortYazdir(index);
    this->cizgiCizdir(index);
    this->sonrakiDugumYazdir(index);
    this->cizgiCizdir(index);
    cout << endl;
    gec->sListesiAdresi->yazdir(sira);
}