#include "fonction.h"
#include <gtk/gtk.h>
enum
{
	EID,
	ENOM,
	EPRENOM,
	ETEL,
	ENIVEAU,
	ECHAMBRE,
	ENUMCH,
	COLUMNS
};



void ajouter(char nom2[], char prenom2[], char login[], char password[], char role[])
{
FILE *f=NULL;
f=fopen("utilisateurs.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %s %s\n" ,nom2,prenom2,login,password,role);
fclose(f);
}
else
printf("\n Not Found");

}




int verifier (char login[], char password[])
{
FILE *f=NULL;
int trouve=0;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char a[20];
f=fopen("utilisateurs.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s",ch1,ch2,ch3,ch4,a)!=EOF)
{
if (((strcmp(ch3,login)==0)&&(strcmp(ch4,password)==0))&&(strcmp(a,"2")==0))
trouve=1;
}
fclose(f);
}
return trouve;
}



//espacefoyer
int verif(etudiant etud,char iden[],char carte[])
{
    FILE *f=NULL;
    f=fopen("etudiant.txt","r");
    while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
    {
        if ((strcmp(etud.id,iden)==0)||(strcmp(etud.carteid,carte)==0))
        {
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;

}







void ajout (etudiant etud)
{
FILE *f=NULL;
FILE *f1=NULL;
f=fopen("etudiant.txt","a+");
f1=fopen("etudiant2.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,etud.naissance.jour,etud.naissance.mois,etud.naissance.annee,etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,etud.payer,etud.chambre,etud.numch);     
fclose(f);


fprintf(f1,"%s %s %s %s %s %s %s \n",etud.id,etud.nom,etud.prenom,etud.tel,etud.niveau,etud.chambre,etud.numch);     
fclose(f1);
}
else
printf("\n impossible d'ouvrir le fichier");
}







void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char id[20];
char nom[20];
char prenom[20];
char tel[20];
char niveau[20];
char chambre[20];
char numch[20];
store=NULL;

FILE *f1;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("tel", renderer, "text", ETEL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("niveau", renderer, "text",ENIVEAU, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("chambre", renderer, "text", ECHAMBRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("numch", renderer, "text", ENUMCH, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f1=fopen("etudiant2.txt","r");

if(f1==NULL)
{
return;
}
else
{
f1=fopen("etudiant2.txt","a+");
while(fscanf(f1,"%s %s %s %s %s %s %s \n",id,nom,prenom,tel,niveau,chambre,numch)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, EID, id, ENOM, nom, EPRENOM, prenom, ETEL, tel, ENIVEAU, niveau, ECHAMBRE, chambre, ENUMCH, numch, -1);
}
fclose(f1);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


void vider (GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char id[20];
char nom[20];
char prenom[20];
char tel[20];
char niveau[20];
char chambre[20];
char numch[20];
store=NULL;

FILE *f1;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("tel", renderer, "text", ETEL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("niveau", renderer, "text",ENIVEAU, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("chambre", renderer, "text", ECHAMBRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("numch", renderer, "text", ENUMCH, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
gtk_list_store_append (store, &iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
//g_object_unref (store);
}


int verif1(etudiant etud, char ident[])
{
FILE *f=NULL;
    f=fopen("etudiant.txt","r");
    while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
    {
        if ((strcmp(etud.id,ident)==0))
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}




void supprimer(etudiant etud,char ident[])
{
    FILE *f=NULL;
    FILE *t=NULL;
    FILE *f1=NULL;
    FILE *t1=NULL;
    f=fopen("etudiant.txt","r");
    t=fopen("tmp.txt","a+");
    f1=fopen("etudiant2.txt","r");
    t1=fopen("tmp2.txt","a+");
    while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
    {if (strcmp(etud.id,ident)!=0)
        {
            fprintf(t,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,etud.naissance.jour,etud.naissance.mois,etud.naissance.annee,etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,etud.payer,etud.chambre,etud.numch);
        }
    }
    fclose(f);
    fclose(t);
    remove("etudiant.txt");
    rename("tmp.txt","etudiant.txt");




while(fscanf(f1,"%s %s %s %s %s %s %s \n",etud.id,etud.nom,etud.prenom,etud.tel,etud.niveau,etud.chambre,etud.numch)!=EOF)
    {if (strcmp(etud.id,ident)!=0)
        {
            fprintf(t1,"%s %s %s %s %s %s %s \n",etud.id,etud.nom,etud.prenom,etud.tel,etud.niveau,etud.chambre,etud.numch);
	}
    }
    fclose(f1);
    fclose(t1);
    remove("etudiant2.txt");
    rename("tmp2.txt","etudiant2.txt");
}




void modifier(etudiant etud,char ident[],char a[20],char b[20],char c[20],int d,int e,int ff,int z,char w[20],char g[20],char h[20],char i[20],char j[20],int k,char m[20],char l[20])
{
FILE *f=NULL;
FILE *t=NULL;
FILE *f1=NULL;
FILE *t1=NULL;
f=fopen("etudiant.txt","r");
t=fopen("tmp.txt","a+");
f1=fopen("etudiant2.txt","r");
t1=fopen("tmp2.txt","a+");
while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
    {
        if (strcmp(etud.id,ident)==0)
        {
           strcpy(etud.id,ident);
	   strcpy(etud.nom,a);
	   strcpy(etud.prenom,b);
	   strcpy(etud.carteid,c);
	   etud.naissance.jour=d;
	   etud.naissance.mois=e;
	   etud.naissance.annee=ff;
	   etud.sexe=z;
	   strcpy(etud.ville,w);
	   strcpy(etud.tel,g);
	   strcpy(etud.contact,h);
	   strcpy(etud.sante,i);
	   strcpy(etud.niveau,j);
 	   etud.payer=k;
	   strcpy(etud.chambre,m);
	   strcpy(etud.numch,l);

	   
           fprintf(t,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,etud.naissance.jour,etud.naissance.mois,etud.naissance.annee,etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,etud.payer,etud.chambre,etud.numch);
 
        }
        else{
            fprintf(t,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,etud.naissance.jour,etud.naissance.mois,etud.naissance.annee,etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,etud.payer,etud.chambre,etud.numch);
     }
    }
    fclose(f);
    fclose(t);
    remove("etudiant.txt");
    rename("tmp.txt","etudiant.txt");


while(fscanf(f1,"%s %s %s %s %s %s %s \n",etud.id,etud.nom,etud.prenom,etud.tel,etud.niveau,etud.chambre,etud.numch)!=EOF)
    {if (strcmp(etud.id,ident)==0)
        {
	   strcpy(etud.id,ident);
	   strcpy(etud.nom,a);
	   strcpy(etud.prenom,b);
	   strcpy(etud.tel,g);
	   strcpy(etud.niveau,j);
	   strcpy(etud.chambre,m);
	   strcpy(etud.numch,l);
            fprintf(t1,"%s %s %s %s %s %s %s \n",etud.id,etud.nom,etud.prenom,etud.tel,etud.niveau,etud.chambre,etud.numch);
	}
     else{
            fprintf(t1,"%s %s %s %s %s %s %s \n",etud.id,etud.nom,etud.prenom,etud.tel,etud.niveau,etud.chambre,etud.numch);     }
    }
    fclose(f1);
    fclose(t1);
    remove("etudiant2.txt");
    rename("tmp2.txt","etudiant2.txt");

}

int nombreetud(etudiant etud,char nv[])
{
    FILE *f=NULL;
    int s=0;
    f=fopen("etudiant.txt","r");
    while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
    {
        if (strcmp(etud.niveau,nv)==0)
        {
            s=s+1;
        }
    }
    fclose(f);
    return s;
}





void afficher1(GtkWidget *liste,char identtt[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char id[20];
char nom[20];
char prenom[20];
char tel[20];
char niveau[20];
char chambre[20];
char numch[20];
store=NULL;

FILE *f1;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("tel", renderer, "text", ETEL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("niveau", renderer, "text",ENIVEAU, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("chambre", renderer, "text", ECHAMBRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("numch", renderer, "text", ENUMCH, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f1=fopen("etudiant2.txt","r");

if(f1==NULL)
{
return;
}
else
{
f1=fopen("etudiant2.txt","a+");
while(fscanf(f1,"%s %s %s %s %s %s %s \n",id,nom,prenom,tel,niveau,chambre,numch)!=EOF)
{
char *suiteChaine;
suiteChaine = strstr(id,identtt);
if (suiteChaine != NULL)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, EID, id, ENOM, nom, EPRENOM, prenom, ETEL, tel, ENIVEAU, niveau, ECHAMBRE, chambre, ENUMCH, numch, -1);
}
}
fclose(f1);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}







