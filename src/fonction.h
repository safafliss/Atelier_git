#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>
typedef struct{
int jour;
int mois;
int annee;
}date;

typedef struct{
char id[20];
char nom[20];
char prenom[20];
char carteid[20];
date naissance;
int sexe;
char ville[20];
char tel[20];
char contact[20];
char sante[20];
char niveau[20];
int payer;
char chambre[20];
char numch[20];
}etudiant;


void ajouter (char nom2[], char prenom2[], char login[], char password[], char role[]);
int verifier (char login[], char password[]);


int verif(etudiant etud,char iden[],char carte[]);
void ajout(etudiant etud);
void afficher(GtkWidget *liste);
int verif1(etudiant etud, char ident[]);
void supprimer(etudiant etud,char ident[]);
void modifier(etudiant etud,char ident[],char a[20],char b[20],char c[20],int d,int e,int ff,int z,char w[20],char g[20],char h[20],char i[20],char j[20],int k,char m[20],char l[20]);
int nombreetud(etudiant etud,char nv[]);
void vider (GtkWidget *liste);



void afficher1(GtkWidget *liste,char identtt[]);
