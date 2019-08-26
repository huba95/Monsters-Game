/*Utolso modositas: 2013. 12.11,
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hero{
    char name[100];
    int faj;
    int valodiszint;
    int szinteszkoz;
    int sajatkincs;
    }hero;

typedef struct monsters {
    int sorszam;
    char nev[100],leiras[1000], adatok[100];
    int szint,  kincs, eszkoz;
    }monsters;

typedef struct vehicles{
    char name[100];
    char leiras[1000];
    int szint, type;
    }vehicles;

typedef struct names{
    char fegyver[1000];
    char sisak[1000];
    char csizma[1000];
    char pancel[1000];
    int fegyverszint;
    int sisakszint;
    int csizmaszint;
    int pancelszint;
    }names;

names minden;


void kard(vehicles eszkoz)
{
  int valasztas;

        printf("\n%s",eszkoz.name);
		printf("%s\n",eszkoz.leiras);
		if (minden.fegyverszint!=0)
        {
            printf("Mar van fegyvered. Megtartod az ujat?(1)\n");
            printf("Jelenlegi: %sSzint: %d\n", minden.fegyver, minden.fegyverszint);
            scanf("%d", &valasztas);
            if (valasztas==1) {
                    strcpy(minden.fegyver ,eszkoz.name );
                    minden.fegyverszint = eszkoz.szint;
                    }
        }
            else{
                    strcpy(minden.fegyver ,eszkoz.name );
                    minden.fegyverszint = eszkoz.szint;
                }
}

void hat(vehicles eszkoz)
{
  int valasztas;

        printf("\n%s",eszkoz.name);
		printf("%s\n",eszkoz.leiras);
		if (minden.sisakszint!=0)
        {
            printf("Mar van sisakod. Megtartod az ujat?(1)\n");
            printf("Jelenlegi: %sSzint: %d\n", minden.sisak, minden.sisakszint);
            scanf("%d", &valasztas);
            if (valasztas==1) {
                    strcpy(minden.sisak ,eszkoz.name );
                    minden.sisakszint = eszkoz.szint;
                    }
        }
            else{
                    strcpy(minden.sisak ,eszkoz.name );
                    minden.sisakszint = eszkoz.szint;
                }
}

void shoe(vehicles eszkoz)
{
  int valasztas;

        printf("\n%s",eszkoz.name);
		printf("%s\n",eszkoz.leiras);
		if (minden.csizmaszint!=0)
        {
            printf("Mar van csizmad. Megtartod az ujat?(1)\n");
            printf("Jelenlegi: %sSzint: %d\n", minden.csizma, minden.csizmaszint);
            scanf("%d", &valasztas);
            if (valasztas==1) {
                    strcpy(minden.csizma ,eszkoz.name );
                    minden.csizmaszint = eszkoz.szint;
                    }
        }
            else{
                    strcpy(minden.csizma ,eszkoz.name );
                    minden.csizmaszint = eszkoz.szint;
                }
}

void clothe(vehicles eszkoz)
{
  int valasztas;

        printf("\n%s",eszkoz.name);
		printf("%s\n",eszkoz.leiras);
		if (minden.pancelszint!=0)
        {
            printf("Mar van pancelod. Megtartod az ujat?(1)\n");
            printf("Jelenlegi: %sSzint: %d\n", minden.pancel, minden.pancelszint);
            scanf("%d", &valasztas);
            if (valasztas==1) {
                    strcpy(minden.pancel ,eszkoz.name );
                    minden.pancelszint = eszkoz.szint;
                    }
        }
            else{
                    strcpy(minden.pancel ,eszkoz.name );
                    minden.pancelszint = eszkoz.szint;
                }
}

void savegame(hero h, char mentes[]){
	FILE *fp;
	char save [1000];
	sprintf(save,"saves\\%s.dat",mentes);
	fp=fopen(save,"wb");
	if(fp==NULL){
		printf("Nem sikerult megynitni %s-t irasra.\n",mentes);
		exit(1);
	}
	fwrite(&h,sizeof(h),1,fp);
	fwrite (&minden, sizeof(names),1, fp);
	fclose(fp);
}

hero loadgame(char mentes[]){
	FILE *fp;
	hero h;
	char save [50];
	sprintf(save,"saves\\%s.dat",mentes);
	fp=fopen(save,"rb");
	if(fp==NULL){
		printf("Nem sikerult megynitni %s-t olvasasra.\n",mentes);
		exit(1);
	}
	fread(&h,sizeof(h),1,fp);
	fread (&minden, sizeof(names),1, fp);
	fclose(fp);
	return h;
}

int main()
{

    hero gamer;
	char file[1000], leir[1000], puffer[1000], mentes[100];
    monsters ellenseg;
    int valasztas, eszkozsors, esely, eselyszint,a=0, i=0, jatek=1;
    vehicles eszkoz;
        int eszkozsorszam, k, osszszint=0;
        int  type[1000];
        char vehicle[1000];

     srand(time(0));

            printf("Add meg a neved. Erre a nevre fog menteni a jatek, vagy ezt fogja betolteni.\n");
            scanf ("%s", &mentes);
while (jatek==1)
{
        a=0;
        i=0;
        minden.fegyverszint=0;
        minden.pancelszint=0;
        minden.csizmaszint=0;
        minden.sisakszint=0;

    			printf ("New game...1\nLoad game...2\n");
			scanf ("%d", &i);

			while (i!=1 && i!=2)
                {
                    printf ("Rosszvalasz!! Ird be ujra!\n");
                    scanf ("%d", &i);
                }

			if (i==2)
			{
				gamer=loadgame(mentes);
			}

			if (i==1)
			{

				gamer.valodiszint=1;
				gamer.sajatkincs=0;

				FILE * fp=fopen("start\\kezdoszoveg.txt","rt");
				char s[100];srand(time(0));
				if(fp!=NULL){
					while(fgets(s,100,fp)!=NULL)printf("%s",s);
							}



                gamer.faj=7;
				while (gamer.faj!=0 && gamer.faj!=1 && gamer.faj!=2 && gamer.faj!=3 && gamer.faj!=4 && gamer.faj!=5)
                {
                    scanf ("%d", &gamer.faj);
                    printf ("\n");
                    switch(gamer.faj){
                    case 0: gamer.faj= (int)rand()%5+1;
                    case 1: sprintf(file,"start\\human.txt"); break;
                    case 2: sprintf(file,"start\\warrior.txt"); break;
                    case 3: sprintf(file,"start\\elf.txt"); break;
                    case 4: sprintf(file,"start\\magic.txt"); break;
                    case 5: sprintf(file,"start\\phy.txt"); break;
                    default: printf ("Rosszvalasz!! Ird be ujra!\n"); break;
                    }


                }

                FILE * tp=fopen(file,"rt");
                if(tp==NULL) printf("Fajlnyitas.");
                    while(fgets(leir,100,tp)!=NULL)printf("%s",leir);
			}
 printf ("\n\nA jatek elkezdesehez nyomj entert!!\n");
 getch();

system("CLS");

gamer.valodiszint=1;
printf("\n\nKezdd hat el utadat!!!\n\n\n");

     while (gamer.valodiszint<=15)
     {

     gamer.szinteszkoz=osszszint + gamer.valodiszint;

    ellenseg.sorszam= (int)rand()%33+1;
      printf("%d",ellenseg.sorszam);
    sprintf(file,"monstr\\%d.nom",ellenseg.sorszam);


    FILE * fp=fopen(file,"rt");
    if(fp!=NULL){
		if(fgets(ellenseg.nev,100,fp)==NULL){printf("Hiba, nev olvasasa");}
		printf("\n%s",ellenseg.nev);
		if(fgets(ellenseg.leiras,1000,fp)==NULL){printf("Hiba, leiras olvasasa");}
		printf("%s\n",ellenseg.leiras);
		if(fgets(ellenseg.adatok,1000,fp)==NULL){printf("Hiba, leiras olvasasa");}
		printf("%s\n",ellenseg.adatok);
		if(fgets(puffer,1000,fp)==NULL){printf("Hiba, adatok olvasasa");}
		if(sscanf(puffer,"%d%d%d",&ellenseg.szint,&ellenseg.kincs,&ellenseg.eszkoz)!=3){printf("Hiba, adatok olvasasa"); }
                }
                else printf("Hibaa %d szorny megnyitasakor", ellenseg.sorszam);

    if (ellenseg.sorszam==18){getch(); break;}
    printf("\nA sajat szinted: %d\n", gamer.valodiszint);
    printf("Szinted az eszkozeiddel: %d\n", gamer.szinteszkoz);
    printf("Kincsed: %d\n", gamer.sajatkincs);
	printf("\n\nMegkuzdok vele: 1\nMenekulni probalok:0\n");
	scanf ("%d", &valasztas);


	while(valasztas!=0 && valasztas!=1)
        {
            printf ("Rosszul valasz!! Ird be ujra!\n");
            scanf ("%d", &valasztas);
        }

	if (valasztas==1)
    {
        if (gamer.szinteszkoz>=ellenseg.szint)
        {
            printf("Gyoztel! No egyet a szinted, megkapod a kincset es az eszkozoket!\n\n");
            gamer.valodiszint++;
            gamer.sajatkincs = gamer.sajatkincs + ellenseg.kincs;

                         for (k=1; k<+ellenseg.eszkoz; k++){

                    eszkozsorszam= (int)rand()%37+1;
                    sprintf(vehicle,"vhcls\\%d.eszk", eszkozsorszam);


                FILE * fp=fopen(vehicle,"rt");
                if(fp==NULL) printf("Fajlnyitas.");
                    if(fgets(eszkoz.name,100,fp)==NULL){printf("Hiba");}
                    if(fgets(eszkoz.leiras,1000,fp)==NULL){printf("Hiba");}
                    if(fgets(type,1000,fp)==NULL){printf("Hiba");}
                    if(sscanf(type,"%d%d",&eszkoz.type,&eszkoz.szint)!=2){eszkoz.type=9;}

                    switch(eszkoz.type){
                        case 1 :printf ("Fegyvert kaptal.\n"); kard(eszkoz); break;
                        case 2 :printf("Sisakot kaptal\n"); hat (eszkoz); break;
                        case 3 :printf("Csizmat kaptal\n"); shoe(eszkoz); break;
                        case 4 :printf("Pancelt kaptal\n"); clothe(eszkoz); break;
                        default: printf("Nem kaptal semmit\n"); break;
                        }
                        osszszint = minden.fegyverszint + minden.pancelszint + minden.csizmaszint + minden.sisakszint;
                        printf("Az eszkozeid osszes szintje: %d\n\n", osszszint);

                       }

        }
        if (gamer.szinteszkoz<ellenseg.szint)
        {
            esely=(int)rand()%10;
            eselyszint=gamer.szinteszkoz+esely;

             if (eselyszint>ellenseg.szint)
            {
            printf("Szerencsed! Gyoztel! No egyet a szinted, megkapod a kincset es az eszkozoket!\n\n");
            gamer.valodiszint++;
            gamer.sajatkincs = gamer.sajatkincs + ellenseg.kincs;

             for (k=1; k<=ellenseg.eszkoz; k++){

                    eszkozsorszam= (int)rand()%37+1;
                    sprintf(vehicle,"vhcls\\%d.eszk", eszkozsorszam);


                FILE * fp=fopen(vehicle,"rt");
                if(fp==NULL) printf("Fajlnyitas.");
                    if(fgets(eszkoz.name,100,fp)==NULL){printf("Hiba");}
                    if(fgets(eszkoz.leiras,1000,fp)==NULL){printf("Hiba");}
                    if(fgets(type,1000,fp)==NULL){printf("Hiba");}
                    if(sscanf(type,"%d%d",&eszkoz.type,&eszkoz.szint)!=2){eszkoz.type=9;}

                    switch(eszkoz.type){
                        case 1 :printf ("Fegyvert kaptal.\n"); kard(eszkoz); break;
                        case 2 :printf("Sisakot kaptal\n"); hat (eszkoz); break;
                        case 3 :printf("Csizmat kaptal\n"); shoe(eszkoz); break;
                        case 4 :printf("Pancelt kaptal\n"); clothe(eszkoz); break;
                        default: printf("Nem kaptal semmit\n"); break;
                        }
                        osszszint = minden.fegyverszint + minden.pancelszint + minden.csizmaszint + minden.sisakszint;
                        printf("Az eszkozeid osszes szintje: %d\n\n", osszszint);

                       }
            }
            else {
                printf ("Sajnos a szorny legyozott.\n A jatek szamodra itt veget er. \nBetter luck next time!\n\n");
               getch();
                break;
                }
            }
    }

    	if (valasztas==0)
        {
            if (gamer.valodiszint<=10 || gamer.szinteszkoz/ellenseg.szint>=0.5){
            if (gamer.valodiszint>4){gamer.sajatkincs = gamer.sajatkincs - ((int)rand()%6+1)*100;};
                printf ("Hala Istennek megmenekultel, de kozben elpotyogtattal egy keves kincset! Folytasd utad es legkozelebb legyel erosebb!\n\n");}
            else{
                printf ("Sajnos a szorny legyozott.\n A jatek szamodra itt veget er. \nBetter luck next time!\n\n");
                getch();
                break;
                }
        }


        if (gamer.sajatkincs>1000)
        {
            while (gamer.sajatkincs-1000>0)
            {
                gamer.valodiszint++;
                gamer.sajatkincs = gamer.sajatkincs-1000;
                printf("\n\nEleg kincset gyujtottel, hogy noveld a szinted!\nUj szint: %d,\n Uj kincs: %d.\n\n", gamer.valodiszint, gamer.sajatkincs);
            }
        }

		savegame(gamer, mentes);

     }
     if (gamer.valodiszint>=15){
     printf ("\nGratulalok! \nNyertel! \nIgazi szupermunchkin vagy! \nAjonlom figyelmedbe a kartyajatek valtozatot!");
     }
    printf ("\nAkarsz ujat jatszani?\n");
    scanf ("%d", &jatek);
    system("CLS");
}


    return 6;
}

