#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "islemler.h"
/*
* @file BP3-PROJE-2
* @description Bu projede, iki adet buyuk sayi arasinda toplama 
ve cikarma isleminin yapilmasi amaclanmaktadir. 
* @assignment PROJE_2
* @date 18/01/2022
* @author Bahadir Sina Terzioglu/bahadir.terzioglu@stu.fsm.edu.tr
*/

int size1 = 0;
int size2 = 0;

void readNumbers(){
    char *sayi1;
    sayi1 = (char*)malloc(11000 * sizeof(char)) ; // char arrayler dinamik bellek icin heapde tanimlandi.
    char *sayi2 ;
    sayi2 = (char*)malloc(5100 * sizeof(char)) ;
    char temp;
    char temp2;
    FILE *FP1 = fopen("sayi1.txt", "r"); // dosyalarin acilması saglandi.
    FILE *FP2 = fopen("sayi2.txt", "r");

    if (FP1 == NULL)  // acilan dosyalarin kontrolu yapildi.
    {
        printf("sayi1.txt acilamadi!!");
        exit(EXIT_SUCCESS);
    }
    if (FP2 == NULL)
    {
        printf("sayi2.txt acilamadi!!");
        exit(EXIT_SUCCESS);
    }

        temp = getc(FP1);
        while (!feof(FP1))  // sayi1.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu. 
        {
            if (temp != '\n')
            {
                *sayi1 = temp;
                sayi1++;
                size1++;   // sayi1.txt dosyasinin içindeki sayilarin boyutu hesaplandi. 
                temp = getc(FP1);
            }else
            {
                temp = getc(FP1);
                continue;
            }

        }
        temp2 = getc(FP2);
        while (!feof(FP2))    // sayi2.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu. 
        {
            if (temp2 != '\n')
            {
                *sayi2 = temp2;
                sayi2++;
                size2++;         // sayi2.txt dosyasinin içindeki sayilarin boyutu hesaplandi. 
                temp2 = getc(FP2);
            }else
            {
                temp2 = getc(FP2);
                continue;
            }
        }
        printf("\n\nSAYILAR BASARIYLA OKUNDU...\n\n");         // okunduguna dair bilgi ekrana yazdirildi.
//       free(sayi1);
//       free(sayi2);          gerekli alanlar iade edildi. 
        fclose(FP1);
        fclose(FP2);    // dosyalar kapatildi. 

}
void writeNumbers(){
    char *sayi1;
    sayi1 = (char*)malloc(11000 * sizeof(char)) ;
    char *sayi2 ;
    sayi2 = (char*)malloc(5100 * sizeof(char)) ;

    uint8_t *sayilar1 = (uint8_t*)malloc(11000 * sizeof(uint8_t)) ;  // sayilar dinamik bellek için heapde tanimlandi 
    uint8_t *sayilar2 = (uint8_t*)malloc(5100 * sizeof(uint8_t)) ;

    char temp;
    char temp2;

    FILE *FP1 = fopen("sayi1.txt", "r");   // dosyalarin acilması saglandi.
    FILE *FP2 = fopen("sayi2.txt", "r");

    if (FP1 == NULL)
    {
        printf("sayi1.txt acilamadi!!");  // acilan dosyalarin kontrolu yapildi.
        exit(EXIT_SUCCESS);
    }
    if (FP2 == NULL)
    {
        printf("sayi2.txt acilamadi!!");
        exit(EXIT_SUCCESS);
    }
        printf("\n****************************************************************************************************SAYI1.TXT****************************************************************************************************\n");
        temp = getc(FP1);
        while (!feof(FP1))
        {
            if (temp != '\n')
            {
                *sayi1 = temp;
                *sayilar1 = *sayi1 - '0';  // sayi1.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu ve okunan karakterler sayiya cevrildi.  
                printf("%d", *sayilar1);   // cevrilen sayilar tek tek yazildi. 
                sayi1++;
                temp = getc(FP1);
            }else
            {
                temp = getc(FP1);
                continue;
            }

        }
        printf("\n****************************************************************************************************SAYI2.TXT****************************************************************************************************\n");
        temp2 = getc(FP2);
        while (!feof(FP2))  // sayi2.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu ve okunan karakterler sayiya cevrildi. 
        {
            if (temp2 != '\n')
            {
                *sayi2 = temp2;
                *sayilar2 = *sayi2 - '0'; 
                printf("%d", *sayilar2);   // cevrilen sayilar tek tek yazildi.
                sayi2++;
                temp2 = getc(FP2);
            }else
            {
                temp2 = getc(FP2);
                continue;
            }
        }
//        free(sayi1);
//        free(sayi2);          gerekli alanlar iade edildi. 
//        free(sayilar1);
//        free(sayilar2);
        fclose(FP1);    // dosyalar kapatildi. 
        fclose(FP2);

}
void artiIslemYazdir(){ 
    char *sayi1 = (char*)malloc(11000 * sizeof(char)) ;    // char arrayler dinamik bellek icin heapde tanimlandi.
    char *sayi2 = (char*)malloc(5100 * sizeof(char)) ;

    uint8_t *sayilar1 = (uint8_t*)malloc(11000 * sizeof(uint8_t)) ;    // sayi arrayleri dinamik bellek için heapde tanimlandi.
    uint8_t *sayilar2 = (uint8_t*)malloc(5100 * sizeof(uint8_t)) ;  

    char temp;
    char temp2;

    FILE *FP1 = fopen("sayi1.txt", "r");         // dosyalarin acilması saglandi.
    FILE *FP2 = fopen("sayi2.txt", "r");

    if (FP1 == NULL)
    {
        printf("sayi1.txt acilamadi!!");     // acilan dosyalarin kontrolu yapildi.
        exit(EXIT_SUCCESS);
    }
    if (FP2 == NULL)
    {
        printf("sayi2.txt acilamadi!!");
        exit(EXIT_SUCCESS);
    }
        int p = 0;
        temp = getc(FP1);
        while (!feof(FP1))
        {
            if (temp != '\n')
            {
                *sayi1 = temp;
                *(sayilar1 +p) = *sayi1 - '0';   // sayi1.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu ve okunan karakterler sayiya cevrildi. 
                temp = getc(FP1);
                p++;
            }else
            {
                temp = getc(FP1);
                continue;
            }
        }

        int s = 0;
        temp2 = getc(FP2);
        while (!feof(FP2))
        {
            if (temp2 != '\n')
            {
                *sayi2 = temp2;
                *(sayilar2 +s) = *sayi2 - '0';   // sayi2.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu ve okunan karakterler sayiya cevrildi. 
                temp2 = getc(FP2);
                s++;
            }else
            {
                temp2 = getc(FP2);
                continue;
            }
        }
        int *sonuclar = (int*)malloc(size1 * sizeof(int)) ;   // sonuclar arrayi dinamik bellek icin heapte tanimlandi. 
        int diff = size1 - size2;
        int remainder = 0;
        int sum = 0;
        int sonuc = 0;
        int sonuc2 = 0;
        int k = size1 - 1;
        for (int i = size1-1; i >= 0; i--,k--)    // toplama isleminde iki dosya icinden sayilar okunduktan ve sayiya cevrildikten sonra iki arrayin son kismindan baslanarak
        {                                         // sayilar birer birer toplandi. Toplanan sayilar eger 2 basamakli ise sayinin 10 ile modu alinarak arraye atildi. Daha sonra
            sum = (*(sayilar1+i) + *(sayilar2+i-diff) + remainder); // sayi 10 ile bölünerek elde bulundu. Elde sayisi bir önceki elemana eklenerek toplama islemi gerceklesti. 
            sonuc = (sum % 10);
            *(sonuclar + k) = sonuc; 
            remainder = (sum / 10);
        }
        k += size2+1;
       for (int j = diff-1; j >= 0; j--,k--)
        {
            sum = *(sayilar1+j) + remainder;
            sonuc2 = (sum % 10);
            *(sonuclar + k) = sonuc2; 
            remainder = (sum / 10);
        }

        for (int i = 0; i < size1; i++)
        {
            printf("%d",*(sonuclar+i));         // toplama islemi sonucu ekrana yazdirildi.
        } 
            FILE *FP3 = fopen("sonuclar.txt", "a"); // dosya append modda acildi cunku icine ekleme yapilacak. 
                if (FP3 == NULL)
                {
                    printf("sonuclar.txt acilamadi!!");  // acilmama durumu kontrol edildi. 
                    exit(EXIT_SUCCESS);
                 }
                    fprintf(FP3,"\n******************************************************************************************************************\n");
                for (int i = 0; i < size1; i++)
                {
                    fprintf(FP3,"%d", *(sonuclar  + i)); // sonuclar.txt dosyasi icine elde edilen toplama islemi sonucu yazdirildi. 
                }
                
        free(sayi1);
        free(sayi2);  // gerekli alanlar iade edildi. 
        free(sayilar1);
        free(sayilar2);
        free(sonuclar);
        fclose(FP1);
        fclose(FP2);  // dosyalar kapatildi. 
        fclose(FP3);

}

void eksiIslemYazdir(){
    char *sayi1 = (char*)malloc(11000 * sizeof(char)) ;   // char arrayler dinamik bellek icin heapde tanimlandi.
    char *sayi2 = (char*)malloc(5100 * sizeof(char)) ;

    uint8_t *sayilar1 = (uint8_t*)malloc(11000 * sizeof(uint8_t)) ;
    uint8_t *sayilar2 = (uint8_t*)malloc(5100 * sizeof(uint8_t)) ;     // sayi arrayleri dinamik bellek için heapde tanimlandi.

    char temp;
    char temp2;

    FILE *FP1 = fopen("sayi1.txt", "r");    // dosyalarin acilması saglandi.
    FILE *FP2 = fopen("sayi2.txt", "r");

    if (FP1 == NULL)
    {
        printf("sayi1.txt acilamadi!!");    // acilan dosyalarin kontrolu yapildi.
        exit(1);
    }
    if (FP2 == NULL)
    {
        printf("sayi2.txt acilamadi!!");
        exit(1);
    }
        int p = 0;
        temp = getc(FP1);
        while (!feof(FP1))
        {
            if (temp != '\n')
            {
                *sayi1 = temp;
                *(sayilar1 +p) = *sayi1 - '0';   // sayi1.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu ve okunan karakterler sayiya cevrildi.
                temp = getc(FP1);
                p++;
            }else
            {
                temp = getc(FP1);
                continue;
            }
        }

        int s = 0;
        temp2 = getc(FP2);
        while (!feof(FP2))
        {
            if (temp2 != '\n')
            {
                *sayi2 = temp2;
                *(sayilar2 +s) = *sayi2 - '0';  // sayi2.txt dosyasi sonuna kadar gezilerek ve /n kontrolu yapilarak dosyadan karakterler okundu ve okunan karakterler sayiya cevrildi. 
                temp2 = getc(FP2);
                s++;
            }else
            {
                temp2 = getc(FP2);
                continue;
            }
        }
        int *sonuclar2 = (int*)malloc(size1 * sizeof(int)) ;   // sonuclar arrayi dinamik bellek icin heapte tanimlandi. 
        int diff = size1 - size2;
        int remainder = 0;
        int sum = 0;
        int sonuc = 0;
        int sonuc2 = 0;
        int k = size1 - 1;
        for (int i = size1-1; i >= 0; i--,k--)    // cikartma isleminde ise iki dosya icinden sayilar okunduktan ve sayiya cevrildikten sonra iki arrayin son kismindan baslanarak
        {                                         // sayilar birer birer birbirinden cikarildi. Ancak ilk sayi ikinci sayidan kucuk ise sonuc eksi deger cikamayacagindan bir önceki sayidan
            sum = (*(sayilar1+i) - *(sayilar2+i-diff) - remainder); // 1 cikarilir ve ilk sayiya 10 eklenir. Bu islem iki array icinde gerceklestirilir.
            if (sum < 0)
            {
                sum+= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
            *(sonuclar2 + k)= sum;
        }
        k += size2+1;
       for (int j = diff-1; j >= 0; j--,k--)
        {
            sum = *(sayilar1+j) - remainder;
            if (sum < 0)
            {
                sum+= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
            *(sonuclar2 + k)= sum;
        }
         for (int i = 0; i < size1; i++)
        {
            printf("%d",*(sonuclar2+i));         // cikarma islemi sonucu ekrana yazdirildi.
        } 
                    FILE *FP3 = fopen("sonuclar.txt", "a");   // dosya append modda acildi cunku icine ekleme yapilacak. 
                if (FP3 == NULL)
                {
                    printf("sonuclar.txt acilamadi!!");  // acilmama durumu kontrol edildi. 
                    exit(EXIT_SUCCESS);
                 }
                    fprintf(FP3,"\n******************************************************************************************************************\n");
                for (int i = 0; i < size1; i++)
                {
                    fprintf(FP3,"%d", *(sonuclar2  + i));  // sonuclar.txt dosyasi icine elde edilen cikarma islemi sonucu yazdirildi. 
                }
        free(sayi1);
        free(sayi2);
        free(sayilar1);  // gerekli alanlar iade edildi.
        free(sayilar2);
        free(sonuclar2);
        fclose(FP1);     
        fclose(FP2);     // dosyalar kapatildi. 
}