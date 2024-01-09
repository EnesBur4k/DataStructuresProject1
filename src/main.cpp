/** 
* @file main.cpp
* @description Ekrana yazdırma ve dosyadan veri okuma işlemlerini yapar.
* @course Birinci Öğretim A Grubu
* @assignment 1.Ödev
* @date 25.11.2022
* @author Enes Burak Kaya enes.kaya11@ogr.sakarya.edu.tr
*/

#include "YoneticiListesi.hpp"
#include <string>
#include <sstream>
using namespace std;

void basliklariYazdir(int index, int satirKontrol) // En üst satırdaki ilk, son ve ok işaretlerini yazdırır.
{
  if(index == 1)  cout << "ilk" << setw(99) << "--->" << endl;
  
  else if(index + 8 < satirKontrol) cout << "<---" << setw(98) << "--->" << endl;
  
  else if(index + 8 > satirKontrol)
  {
    if(satirKontrol % 8 != 1) cout << "<---";
    for(int t=0; t < (satirKontrol % 8) - 1; t++) cout << "           ";
    cout << "        son" << endl;
  }
}

int main()
{
  srand(time(0));
  int index = 1, sira = 1, ySirasi = 1, satirKontrol = 0, silinecekDugum;
  string satir;
  char ch;

  YoneticiListesi* yListesi = new YoneticiListesi();
  ifstream dosya ("veriler.txt");

  /*  Dosyadan okuma işlemi  */
  while(getline(dosya,satir)) // Dosyada satır kalmayana kadar çalışan döngü.
  {
    stringstream ss(satir);
    int siradaki;
    SatirListesi* sListesi = new SatirListesi();
    
    while(ss>>siradaki) // Satırda veri kalmayana kadar çalışan döngü.
    {
      sListesi->ekle(siradaki);
    }
    
    yListesi->ekle(sListesi);
    satirKontrol++;
  }
  /*  Dosyadan okuma işlemi sonu. */

  /*  Sürekli ekrana bastıran döngü. */
  while(true)
  {
    system("CLS");
    basliklariYazdir(index, satirKontrol);
    yListesi->yazdir(index, sira, ySirasi);

    cin >> ch;

    if(ch == 'z')
    {
      if(index == 1 && sira == 1) continue; // Eğer index ve sira 1 e eşitse while döngüsüne döner, altındaki kodlar çalışmaz.
      sira--;
      if(sira < 1) // Eğer ilk yönetici düğümü seçiliyse işlem yapıldığında bir önceki sekizliye gider.
      {
        index -=8;
        sira = 8;
      }
      ySirasi--;
    }
    
    if(ch == 'c') 
    {
      if((index + sira) > satirKontrol) continue; // Eğer index ve sira toplamı toplam satır sayısını geçerse while döngüsüne döner, altındaki kodlar çalışmaz.
      
      sira++;
      
      if(sira > 8) // Eğer sayfadaki son yönetici düğümü seçiliyse işlem yapıldığında bir sonraki sekizliye gider.
      {
        index +=8;
        sira = 1;
      }
      
      ySirasi++;
    }
    
    if(ch == 'a' && !((index - 8) < 1)) // 8 önceki yönetici listesi düğümüne gider.
    {
      index -= 8;
      ySirasi -= 8;
    }
    
    if(ch == 'd' && !((index + sira + 7) > satirKontrol)) //8 sonraki yönetici listesi düğümüne gider.
    {
      index += 8;
      ySirasi += 8;
    }
    
    if(ch == 'k') // Seçili yönetici düğümünden rastgele bir satir listesi düğümünü siler.
    {
      YoneticiDugum* gec = yListesi->ilkYoneticiDugum;
      int i = 1;
      
      while(i < (index + sira)-1) // Seçili yönetici düğümünün sırasının 1 eksiği kadar gec düğümünün sonraki düğümüne gider.
      {
        gec = gec->sonraki;
        i++;
      }
      
      silinecekDugum = rand() % (gec->sListesiAdresi->elemanSayisi()); // Silinecek düğümün indexini belirler.

      if(gec->sListesiAdresi->elemanSayisi() == 1) // Eğer satır listesinde bir adet düğüm varsa içeri girer.
      {
        if(gec->onceki == 0) yListesi->ilkYoneticiDugum = gec->sonraki;
        
        delete gec;
        if(index != 1 && sira != 1)
		{
			sira--;
			ySirasi--;
			satirKontrol--;
		}
	  
        if(index != 1 && sira == 0) 
        {
          index -= 8;
          sira = 8;
        }
      }
      else // Satır listesinde bir adet düğüm yoksa içeri girer.
      {
        gec->sListesiAdresi->sil(silinecekDugum);
        Dugum* gecSatirListesiDugumu = gec->sListesiAdresi->ilkDugum;
        SatirListesi* yeniSatirListesi = new SatirListesi();
        
        while(gecSatirListesiDugumu != 0)
        {
          yeniSatirListesi->ekle(gecSatirListesiDugumu->veri);
          gecSatirListesiDugumu = gecSatirListesiDugumu->sonraki;
        }
        
        if(gec->onceki == 0)
      {
        yListesi->ilkYoneticiDugum = gec->sonraki;
      }
        delete gec;
        YoneticiDugum* yeniYoneticiDugum = new YoneticiDugum(yeniSatirListesi);
        yListesi->ekle(yeniSatirListesi);
      }
    }
    if(ch == 'p') // Seçili yönetici düğümünü siler.
    {
      YoneticiDugum* gec = yListesi->ilkYoneticiDugum;
      int i = 1;
      
      while(i < (index + sira)-1)
      {
        gec = gec->sonraki;
        i++;
      }
      
      if(gec->onceki == 0)
      {
        yListesi->ilkYoneticiDugum = gec->sonraki;
      }
      delete gec;
      
      sira--;
      ySirasi--;
      satirKontrol--;
      
      if(index == 1 && sira == 0) 
      {
        sira = 1;
        ySirasi = 1;
      }

      if(index != 1 && sira == 0) 
      {
        index -= 8;
        sira = 8;
      }
    }
  }
  dosya.close();
  
  delete yListesi;
}