#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
typedef struct
{
    int m;
    int a;
    int j;
} date;
typedef struct
{
    char sexe;
    int matricule;
    date naissance;
    char ville[10];
    char nom[20];
} etudiant;
void info_etudiant(etudiant *a,int taille)
    int i;
    int j;
    for(i=0;i<taille;i++)
    {
        printf("\n------------ETUDIANT NUMERO %d -------\n",i);
        printf("Donner le nom de l'etudiant : ");
        fflush(stdin);
        gets(a[i].nom);
        printf("Donner la ville : ");
        fflush(stdin);
        gets(a[i].ville);
        printf("Donner le matricule  : ");
        scanf("%d",&a[i].matricule);
    }
}
void current time()
{
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );
}
void ajouter(etudiant *a,int *taille)
{
   int i;
        printf("\n------------ETUDIANT NUMERO %d -------\n",i);
        printf("Donner le nom de l'etudiant : ");
        fflush(stdin);
        gets(a[*taille].nom);
        printf("Donner la ville : ");
        fflush(stdin);
        gets(a[*taille].ville);
        do
        {
            printf("Donner le matricule : ");
            scanf("%d",&a[*taille].matricule);
        } while(a[*taille].matricule==a[(*taille)-1].matricule);
        (*taille)++;
}
void affichage(etudiant *a,int taille)
{
    int i;
        for(i=0;i<taille;i++)
    {
        printf("\n------------ETUDIANT NUMERO %d -------\n",i);
        printf("Nom : %s\n",a[i].nom);
        printf("Ville : %s\n",a[i].ville);
        printf("Matricule : %d",a[i].matricule);
    }
}
void Suppression(etudiant *a,int *taille,char ville[])
{
    int i;
    int position;
    if(*taille!=0)
    {
        for(i=0;i<*taille;i++)
        {
            if(strcmp(ville,a[i].ville)==0)
            {
                break;
            }
        }
        position=i;
        for(i=position;i<*taille;i++)
        {
            a[i]=a[i+1];
        }
        (*taille)--;
    } else
    {
        printf("Aucun etudiant : ");
    }
}
void trier(etudiant *a,int taille)
{
    int i;
    int j;
    etudiant swap;
    for(i=0;i<taille;i++)
    {
        for(j=i+1;j<taille;j++)
        {
            swap=a[i];
            a[i]=a[i+1];
            a[i+1]=swap;
        }
    }
    printf("\n----------TRIER----------\n");
      for(i=0;i<taille;i++)
    {
        printf("\n------------ETUDIANT NUMERO %d -------\n",i);
        printf("Nom : %s\n",a[i].nom);
        printf("Ville : %s\n",a[i].ville);
        printf("Matricule : %d",a[i].matricule);
    }
}
void main()
{
    etudiant p[100];
    int taille;
    int choix;
    char ville[20];
    do
    {
        clrscr();
        puts("1-Saisir les infos  : ");
        puts("2-Affichage  :");
        puts("3-Ajouter Un etudiant : ");
        puts("4-Suppression : ");
        puts("0-Quitter  ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1:
            {
                do
                  {
                    printf("Donner le nombre d'etudiant  :");
                    scanf("%d",&taille);
                  } while(taille<0 ||taille>100);
                  info_etudiant(p,taille);
            } break;
        case 2:
            {
                if(taille==0)
                {
                    printf("Error");
                } else
                {
                    affichage(p,taille);
                }
            } break;
        case 3:ajouter(p,&taille);break;
        case 4:
            {
                printf("Donner la ville:  ");
                fflush(stdin);
                gets(ville);
                Suppression(p,&taille,ville);
            } break;
        case 0:printf("FIN DU PROGRAMME ");break;
        }
        getch();
    } while(choix!=0);
}
