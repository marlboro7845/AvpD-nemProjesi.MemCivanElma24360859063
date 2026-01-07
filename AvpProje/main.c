#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653589793

double SerbestDusme (double* yercekimi,int GezegenNum,double saniye) { //tüm deneyler kendilerine özel fonksiyonlarla tanýmlanýyor
    return 0.5*(*(yercekimi+GezegenNum))*(saniye*saniye);
}
double YukariAtis (double* yercekimi,int GezegenNum,double hiz) {
    return (hiz*hiz)/(2* *(yercekimi+GezegenNum));
}
double AgirlikDeneyi(double* yercekimi,int GezegenNum,double kutle) {
    return kutle*(*(yercekimi+GezegenNum));
}
double KutlecekimselPotansiyel (double* yercekimi,int GezegenNum,double kutle,double yukseklik) {
    return kutle*yukseklik*(*(yercekimi+GezegenNum));
}
double HidrostatikBasinc (double* yercekimi,int GezegenNum,double yogunluk,double derinlik){
    return yogunluk*derinlik*(*(yercekimi+GezegenNum));
}
double KaldirmaKuvveti (double* yercekimi,int GezegenNum,double yogunluk,double BatanHacim){
    return yogunluk*BatanHacim*(*(yercekimi+GezegenNum));
}
double SarkacPeriyodu(double* yercekimi, int GezegenNum, double uzunluk) {
    return 2 * PI * sqrt(uzunluk /(*(yercekimi + GezegenNum)));
}
double IpGerilmesi(double* yercekimi, int GezegenNum, double kutle) {
    return kutle * (*(yercekimi + GezegenNum));
}
double AsansorAgirligi(double* yercekimi, int GezegenNum, double kutle, double ivme) {
    return kutle * (*(yercekimi + GezegenNum) + ivme);
}


int main()
{
    char isim[90];//bilim adamý ismi iiçin dizi oluþturuluyor
    int deney;
    double saniye,hiz,kutle,yukseklik,derinlik,yogunluk,hacim,uzunluk,ivme;
    char gezegenler[8][10]={
    "Merkur","Venus","Dunya","Mars",
    "Jupiter","Saturn","Uranus","Neptun"// gezegenler farklý ivmelere sahip olduðu için bir dizi içine atanýyor
    };
    double gezegen_yercekim_ivmesi[8]= {
    3.71, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15//gezegenlerin yercekimi ivmeleri
    };
    printf("UZAY SIMULASYONU PROGRAMINA HOS GELDINIZ\n\n");

    printf("Lutfen isminizi giriniz: ");
    scanf("%s",isim);

    while (1) {
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n\n"); // deney secim tablosu

        printf("\nSayin %s, yapmak istediginiz deneyi seciniz:\n",isim);
        scanf("%d",&deney);

        if (deney==-1) { // deney seçim tablosundan çýkmak için -1 girilmesi gerekiyor
            printf("Programdan cikiliyor...");
            break;
        }

        switch(deney) { //deney secimine göre case lere aktarýlýyor
            case 1:
                printf("serbest dusme icin istenen sureyi saniye cinsinden giriniz: ");
                scanf("%lf",&saniye);
                if (saniye<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                saniye=(saniye<0)?saniye*(-1):saniye; //negatif olamayacak deðerlerin kontrollerinden birisi
                }
                for(int i=0;i<8;i++) {
                    double yukseklik=SerbestDusme(gezegen_yercekim_ivmesi,i,saniye);
                    printf("%s gezegeninde %.2f saniyede alinan yol=%.2f metredir.\n",gezegenler[i],saniye,yukseklik);
                }
                break;

            case 2:
                printf("(Bu deneyde yercekimi ihmal edilmektedir!)\n");
                printf("Yukari atis deneyi icin ilk hizi m/sn cinsinden giriniz(m/s cinsinden): ");
                scanf("%lf",&hiz);
                for(int i=0;i<8;i++) {
                    double MaxYukseklik=YukariAtis(gezegen_yercekim_ivmesi,i,hiz);
                    printf("%s gezegeninde %.2lf m/s hizla atilan cismin maksimum yuksekligi=%.2lf metredir.\n",gezegenler[i],hiz,MaxYukseklik);
                }
                break;

            case 3:
                printf("Agirlik deneyi icin istenen kutleyi kilogram cinsinden giriniz: ");
                scanf("%lf",&kutle);
                if (kutle<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                kutle=(kutle<0)?kutle*(-1):kutle;
                }
                for (int i=0;i<8;i++) {
                    double agirlik=AgirlikDeneyi(gezegen_yercekim_ivmesi,i,kutle);
                    printf("%s gezegeninde %.2lf kg kutleli cismin agirligi= %.2lf Newton.\n",gezegenler[i],kutle,agirlik);
                }
                break;

            case 4:
                printf("Kutlecekimsel Potansiyel Enerjisini hesaplamak icin istenen verileri giriniz.\n");
                printf("Yuksekligi metre cinsinden giriniz: \n");
                scanf("%lf",&yukseklik);
                if (yukseklik<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                yukseklik=(yukseklik<0)?yukseklik*(-1):yukseklik;
                }

                printf("cismin kutlesini kilogram cinsinden giriniz: \n");
                scanf("%lf",&kutle);
                if (kutle<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                kutle=(kutle<0)?kutle*(-1):kutle;
                }

                for (int i=0;i<8;i++) {
                    double enerji=KutlecekimselPotansiyel(gezegen_yercekim_ivmesi,i,kutle,yukseklik);
                    printf("%s gezegeninde %.2lf metre yuksekliginde %.2lf kilogram kutleli cismin kutlecekimsel potansiyel enerjisi= %.2lf joule.\n",gezegenler[i],yukseklik,kutle,enerji);
                }

                break;

            case 5:
                printf("Hidrostatik basinci hesaplamak icin istenen verileri giriniz.\n");
                printf("Sivinin birim hacimdeki kutlesini kg/m^3 cinsinden giriniz: \n");
                scanf("%lf",&yogunluk);
                if (yogunluk<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                yogunluk=(yogunluk<0)?yogunluk*(-1):yogunluk;
                }

                printf("Derinligi metre cinsinden giriniz: \n");
                scanf("%lf",&derinlik);
                if (derinlik<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                derinlik=(derinlik<0)?derinlik*(-1):derinlik;
                }

                for (int i=0;i<8;i++) {
                    double basinc=HidrostatikBasinc(gezegen_yercekim_ivmesi,i,yogunluk,derinlik);
                    printf("%s gezegeninde %.2lf kg/m^3 yogunluklu sivinin %.2lf metre derinlikteki hidrostatik basinci= %.2lf Pascal.\n",gezegenler[i], yogunluk, derinlik, basinc);
                }
                break;

             case 6:
                printf("Kaldirma kuvvetini hesaplamak icin istenen verileri giriniz.\n");
                printf("Sivinin birim hacimdeki kutlesini kg/m^3 cinsinden giriniz: \n");
                scanf("%lf",&yogunluk);
                if (yogunluk<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                yogunluk=(yogunluk<0)?yogunluk*(-1):yogunluk;
                }

                printf("Cismin batan hacmini m^3 cinsinden giriniz: \n");
                scanf("%lf",&hacim);
                if (hacim<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                hacim=(hacim<0)?hacim*(-1):hacim;
                }

                for (int i=0;i<8;i++) {
                    double KalKuvveti=KaldirmaKuvveti(gezegen_yercekim_ivmesi,i,yogunluk,hacim);
                    printf("%s gezegeninde %.2lf kg/m^3 yogunluklu sivida %.2lf m^3 batan hacimli cismin kaldirma kuvveti= %.2lf Newton\n",gezegenler[i], yogunluk, hacim, KalKuvveti);
                }
                break;

             case 7:
                printf("Basit sarkac periyodu deneyi icin sarkacin uzunlugunu metre cinsinden giriniz: ");
                scanf("%lf",&uzunluk);
                if (uzunluk<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                uzunluk=(uzunluk<0)?uzunluk*(-1):uzunluk;
                }
                for(int i=0;i<8;i++) {
                    double periyot=SarkacPeriyodu(gezegen_yercekim_ivmesi,i,uzunluk);
                    printf("%s gezegeninde %.2lf metre uzunlugundaki sarkacin tam periyodu= %.2lf saniye\n",gezegenler[i],uzunluk,periyot);
                }
                break;

             case 8:
                printf("Sabit ip gerilmesi deneyi icin cismin kutlesini kilogram cinsinden giriniz: ");
                scanf("%lf", &kutle);
                if (kutle<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                kutle=(kutle<0)?kutle*(-1):kutle;
                }

                for (int i = 0; i < 8; i++) {
                    double gerilme = IpGerilmesi(gezegen_yercekim_ivmesi, i, kutle);
                    printf("%s gezegeninde %.2lf kg kutleli cismin ip gerilme kuvveti= %.2lf Newton\n",gezegenler[i],kutle,gerilme);
                }
                break;

             case 9:
                printf("Asansor deneyi icin cismin kutlesini kilogram cinsinden giriniz: ");
                scanf("%lf", &kutle);
                if (kutle<0) {
                printf("Gecersiz birim duzeltiliyor.\n\n");
                kutle=(kutle<0)?kutle*(-1):kutle;
                }

                printf("Asansor ivmesini m/s^2 cinsinden giriniz (pozitif yukari, negatif asagi): ");
                scanf("%lf", &ivme);

                for (int i = 0; i < 8; i++) {
                    double EtkinkAgirlik = kutle * (gezegen_yercekim_ivmesi[i] + ivme);

                    printf("%s gezegeninde %.2lf kg kutleli cismin etkin agirligi= %.2lf Newton\n",gezegenler[i], kutle, EtkinkAgirlik);
                }
                break;

             default:
                printf("Gecersiz deney numarasi girdiniz lutfen tekrar deneyiniz.\n\n"); //gecersiz deney secimi kontrolü
        }


    }
    return 0;
}
