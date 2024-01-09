/** 
* @file SatirListesi.cpp
* @description Düğüm yapılarını yönetir.
* @course Birinci Öğretim A Grubu
* @assignment 1.Ödev
* @date 25.11.2022
* @author Enes Burak Kaya enes.kaya11@ogr.sakarya.edu.tr
*/

#include "SatirListesi.hpp"
#include <ctime>

SatirListesi::SatirListesi()
{
    ilkDugum=0;
}

SatirListesi::~SatirListesi()
{
    Dugum* gec = ilkDugum;
    Dugum* silinecek;
    
    while(gec != 0) // Tüm Dugum nesnelerine erişmeyi sağlar.
    {
        silinecek=gec;
        gec = gec->sonraki;
        delete silinecek;
    }
}
void SatirListesi::ekle(double veri)
{
    Dugum *yeniDugum = new Dugum(veri);
    if(ilkDugum==0)
    {
        ilkDugum = yeniDugum;
    }else
    {
        Dugum* gec = ilkDugum;
        while(gec->sonraki!=0) // Son Dugum nesnesine ulaşır.
            gec = gec->sonraki;
        
        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }
}
void SatirListesi::sil(int silinecekDugum)
{
    Dugum* gec = ilkDugum;
    while(silinecekDugum > 0) // Silinecek olan Dugum nesnesine ulaşır.
    {
        gec = gec->sonraki;
        silinecekDugum--;
    }
    if(gec->onceki == 0 && gec->sonraki == 0)
    {
        delete gec;
    }
    else if(gec->onceki == 0 && (gec->sonraki != 0))
    {
        gec->sonraki->onceki = gec->onceki;
        this->ilkDugum = gec->sonraki;
        delete gec;
    }
    else if(gec->sonraki == 0 && (gec->onceki != 0))
    {
        gec->onceki->sonraki = gec->sonraki;
        delete gec;
    }
    else
    {
    gec->onceki->sonraki = gec->sonraki;
    gec->sonraki->onceki = gec->onceki;
    delete gec;
    }
}
int SatirListesi::elemanSayisi() // Satır Listesinin tuttuğu eleman sayısını döndüren kod.
{
    Dugum* gec = ilkDugum;
    int sayac = 0;
    while(gec != 0)
    {
        sayac++;
        gec = gec->sonraki;
    }
    return sayac;
}
float SatirListesi::ortBul() // Satır Listesinin tuttuğu Dugumlerin ortalamasını bulur.
{
    float toplam = 0;
    Dugum* gec = ilkDugum;
    while(gec!=0)
    {
        toplam += gec->veri;
        gec = gec->sonraki;
    }
    return (toplam / elemanSayisi()); 
}
void SatirListesi::cizgiCizdir(int sira)
{
    for(int i = 1; i < sira; i++)
    {
        cout << "             ";
    }
    cout << "^^^^^^^^^^^  " << endl;
}

void SatirListesi::yazdir(int sira)
{
    Dugum* gec = this->ilkDugum;
    this->cizgiCizdir(sira);
    while(gec != 0)
    {
        gec->adresYazdir(sira);
        gec->degerYazdir(sira);;
        gec->sonrakiDugumYazdir(sira);
        cout << endl;
        gec = gec->sonraki;
    }
}