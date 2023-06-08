#include <stdio.h>
#include <stdlib.h>
#include "islemler.h"
/*
* @file BP3-PROJE-2
* @description Bu projede, iki adet buyuk sayi arasinda toplama 
ve cikarma isleminin yapilmasi amaclanmaktadir. 
* @assignment PROJE_2
* @date 18/01/2022
* @author Bahadir Sina Terzioglu/bahadir.terzioglu@stu.fsm.edu.tr
*/
int main(int argc, char *argv[]){
    int sec;
    while (1 != 0)
        {
        printf("\n===========Buyuk sayilar ile matematiksel islemler==========\n");
        printf("Dosyadan sayilari oku: (1)\n");
        printf("Okunan sayilari ekrana yaz: (2)\n");
        printf("Toplama islemi icin: (3)\n");
        printf("Cikarma islemi icin: (4)\n");
        printf("Cikis : (5)\n");
        printf("Girmek istediginiz islemi secin:");
        scanf("%d",&sec);
            if (sec == 1)
            {
                readNumbers();     

            } else if(sec == 2)
            {
                writeNumbers();

            } else if (sec == 3)
            {
                artiIslemYazdir();
                   
            }         
            else if (sec == 4)
            {           
                eksiIslemYazdir();

            } else if (sec == 5)
            {
                printf("Cikis yapildi.\n");
                exit(EXIT_SUCCESS);

            } else
            {
             printf("Lutfen 1-4 arasinda seciminizi yapiniz!!!\n");           
            }
        }        
return 0;  
} 
    
