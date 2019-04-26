#include <stdio.h>
#include <stdlib.h>




void YeniYarismaDuzenleme()
{
    int alinanYarismaci,hafta=0,t,gecici=0;
    for(;;)
    {
        printf("Toplam Yarismaci Sayisini Giriniz : \n");
        scanf("%d",&alinanYarismaci);
        if((alinanYarismaci>4)&&(alinanYarismaci<21))break;
        system("cls");
        printf("En az 5 en fazla 2 yarismaci olmalidir !!! \n");
    }
    int i,j,k,h,a,l,y=0;
    int yarismaci[alinanYarismaci][alinanYarismaci],verilenPuan[alinanYarismaci][alinanYarismaci];
    int genelPuan[alinanYarismaci][alinanYarismaci],genelYarismaci[alinanYarismaci][alinanYarismaci];
    int koc[alinanYarismaci][hafta],seyirciP[alinanYarismaci][hafta];

    for(i=0; i<alinanYarismaci; i++)
    {
        for(j=0; j<alinanYarismaci; j++)
        {
            yarismaci[i][j]=0;
            verilenPuan[i][j]=0;
            genelPuan[i][j]=0;
            genelYarismaci[i][j]=0;
            seyirciP[i][j]=0;
            koc[i][j]=0;


        }
    }
    for(;;)
    {
        printf("Hafta sayisinizi giriniz (min3):");
        scanf("%d",&hafta);
        if(hafta>2)break;
        system("cls");
        printf("En az 3 hafta girilmelidir !!! \n");
    }

    for(i=1; i<=hafta; i++)
    {

        printf("------------------ \n \n ");
        printf("%d. HAFTA\n",i);
        printf("------------------ \n \n ");
        for(k=1; k<=alinanYarismaci; k++)
        {
            int verilenYPuan[3]= {0};
            for(j=1; j<=3; j++)
            {
                do
                {
                    printf("%d. Kocun %d Puan verdigi yarismaci:",k,j);
                    scanf("%d",&a);

                    if(a==k)
                    {
                        printf("Koc ayni numarada yarismaciya puan veremez tekrar giriniz \n");
                        continue;
                    }

                    else if(a<1||a>alinanYarismaci)
                    {
                        printf("%d max %d min numarali yarismacilara puan verebilirsiniz \n",alinanYarismaci,1);
                        continue;
                    }
                    for(l=0; l<3; l++)
                    {
                        if(verilenYPuan[l]==a)
                        {
                            printf("Koc ayni yarismaciya birden fazla defa puan veremez.\n");
                            y++;
                        }
                    }
                    if(y==0)
                    {
                        yarismaci[a-1][0]+=j;//puan
                        verilenPuan[a-1][0]+=j;//koc seyirci puani
                        genelPuan[a-1][0]+=j;//haftalarin  toplami puanlar
                        genelYarismaci[a-1][0]+=j;
                        verilenYPuan[j]=a;
                        koc[a-1][0]+=j;
                        break;
                    }
                    y=0;

                }
                while(1);

            }
        }
        int seyirci[3]= {0};
        for(j=1; j<=3; j++)
        {

            do
            {

                printf("\nSeyircinin %d puan verdigi yarismaci: ",j);
                scanf("%d",&a);
                if(a<1||a>alinanYarismaci)
                    continue;
                for(t=0; t<3; t++)
                {
                    if(seyirci[t]==a)
                    {
                        printf("Seyirci ayni yarismaciya 1 den fazla puan veremez !!! \n");
                        y++;
                    }
                }
                if(y==0)
                {
                    yarismaci[a-1][0]+=j;
                    verilenPuan[a-1][0]+=j;
                    genelPuan[a-1][0]+=j;
                    genelYarismaci[a-1][0]+=j;
                    seyirci[j]=a;
                    seyirciP[a-1][0]+=j;
                    break;

                }
                y=0;

            }
            while(1);
        }

        for(k=0; k<alinanYarismaci; k++)
        {
            for(t=0; t<alinanYarismaci; t++)
            {
                if(yarismaci[k][0]>yarismaci[t][0])
                {
                    gecici = yarismaci[k][0];
                    yarismaci[k][0]=yarismaci[t][0];
                    yarismaci[t][0]=gecici;
                }
            }
        }
        for(k=0; k<alinanYarismaci; k++)
        {
            for(t=0; t<alinanYarismaci; t++)
            {
                if(genelPuan[k][0]>genelPuan[t][0])
                {
                    gecici = genelPuan[k][0];
                    genelPuan[k][0]=genelPuan[t][0];
                    genelPuan[t][0]=gecici;
                }
            }
        }

        printf("--%d. HAFTANIN SONUCLARI--\n", h+1);
        printf(" \n\nYARISMACI NO\t\tPUAN\t\tTOPLAM PUAN\tSEYIRCI PUANLARI\tKOC PUANLARI\n");
        for(k=0;k<alinanYarismaci;k++){

                for(t=0;t<alinanYarismaci;t++){
                        if(yarismaci[k][0]==verilenPuan[t][0])
                            if(yarismaci[k][0]!=yarismaci[k-1][0])

                            printf("\t%d \t\t%d\t\t%d\t\t%d\t\t\t%d\n",t+1,yarismaci[k][0],genelPuan[k][0],seyirciP[k][0],koc[k][0]);//puanlar
                }
        }

    }

        for(j=0; j<alinanYarismaci; j++)
        {
            yarismaci[j][0]=0;
            verilenPuan[j][0]=0;
        }
}


void anaMenu()
{
    int secim;
    char cikis;
    for(;;)
    {
        printf("\n \n \n");
        printf("\t\t\tANA MENU\n");
        printf("\t \t \t 1)Yeni Yarisma Duzenleme \n ");
        printf("\t \t \t 2)Son Duzenlenen Yarismanin Istatistikleri  \n");
        printf("\t \t \t 3)Cikis \n \nSecim Yapiniz:\n");
        scanf("%d",&secim);
        if(secim==1)
        {
            YeniYarismaDuzenleme();
        }
        if(secim==2)
        {
             IstatikselAltMenu();
        }
        if(secim==3)
        {
            printf("Cikmak Istiyor musunuz (E/e , H/h) \n");
            scanf("%s",&cikis);
            if((cikis =='e')||(cikis=='E'))
            {
                exit(1);
            }
        }

    }

}

int main()
{

    anaMenu();

}
void IstatikselAltMenu()


{
    int tercih,k,alinanYarismaci,yarismaci[alinanYarismaci][alinanYarismaci],verilenPuan[alinanYarismaci][alinanYarismaci];
    int i,hafta,j,t;
    int genelPuan[alinanYarismaci][alinanYarismaci],genelYarismaci[alinanYarismaci][alinanYarismaci];
    int koc[alinanYarismaci][alinanYarismaci], seyirciP[alinanYarismaci][alinanYarismaci];
    for(;;){
    printf("\t \t ISTATIKSEL ALT MENU \n");
    printf("1. Sadece koclarin puanlamasi dikkate alindiginda genel durumun listelenmesi \n");
    printf("2. Sadece seyircilerin puanlamasi dikkate alindiginda genel durumun listelenmesi \n");
    printf("3. Yarismacilarin her hafta aldiklari toplam puanlarin listelenmesi \n");
    printf("4. Yarismacilarin her koctan aldiklari toplam puanlarin listelenmesi \n");
    printf("5. Ana Menu \n");
    printf("\n\n");
    printf("Seciminizi giriniz: ");
    scanf("%d",&tercih);
    }

    switch(tercih){

case 1:

    printf("\n\nSadece koclarin puanlamasina gore genel durum:\n ");
    printf("SIRA NO\t\t YARISMACI NO\t\t PUAN\n ");

    for(k=0;k<alinanYarismaci;k++){
        printf("\t%d",k+1);
    }
    for(k=0;k<alinanYarismaci;k++){
      for(t=0;t<alinanYarismaci;t++){
        printf("\t\t %d\t\t %d\t",t+1,koc[k][0]);
        }
    }
break;
case 2:
    printf("Sadece seyircilerin puanlamasina gore genel durum:\n ");
    printf("SIRA NO\t\t YARISMACI NO\t\t PUAN\n ");

 for(k=0;k<alinanYarismaci;k++){
        printf("\t%d",k+1);
    }
    for(j=1; j<=3; j++)
        {
        printf("\t\t %d\t\t %d\t",t+1, genelPuan[j][0]);
        }
break;
case 3:
    printf("Yarismacilarin her hafta aldiklari toplam puanlar:\n ");

    printf("YARISMACI NO\t\t");
    for(i=1; i<=hafta; i++){
            printf("%d. Hafta\t");

    }
    printf("\n");
    for(k=0; k<alinanYarismaci; k++){
    for(i=1; i<=hafta; i++){
        printf("\t\t%d  ",verilenPuan[k][i]);
    }
    }
break;
case 4:
    printf("Yarismacilarin her koctan aldiklari toplam puanlar: \n");
    printf("YARISMACI NO\t\t");
    for(k=0; k<alinanYarismaci; k++){
            printf("%d. Koc\t\t");
    }
    printf("\n");
    for(k=0; k<alinanYarismaci; k++){
        for(t=0;t<alinanYarismaci;t++){
          printf("\t\t%d\t\t",genelPuan[k][t]);
        }
    }
break;
case 5:
    anaMenu();
break;
default :
    printf("Tekrar giriniz\n");
    break;
    }

    anaMenu();


}
