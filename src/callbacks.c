#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "fonction.h"
#include <math.h>
#include <string.h>
int x=1;
int tab[3]={0,0,0};
char ident[20];
int test=0;
int tab1[1]={0};
int flagmodif = 0;
/*****************/



void
on_FSbutton9trier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


/*****************/




void
on_flisssafabutton2statistique_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowstatistique;
windowstatistique=create_safaflissstatistique();
gtk_widget_show (windowstatistique);	
}



/*****************/





void
on_flisssafabutton3ajouter_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget * id3 , * nom3 , * prenom3 , * CIN3 , * ville3 , * tel3 , * contact3 , * sante3 , * numch3 , * output1 , * windowfoyer, *window8;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *niveau1;
GtkWidget *payer1;
GtkWidget *chambre1;
GtkWidget *windowajout;

GtkWidget *treeview1;


etudiant etud ;
int v;
char iden[20];
char carte[20];
//essai

GtkWidget *outputnom;
outputnom = lookup_widget (button, "FSlabel41champ2") ;
GtkWidget *outputprenom;
outputprenom = lookup_widget (button, "FSlabel42champ3") ;
GtkWidget *outputcin;
outputcin = lookup_widget (button, "FSlabel43champ4") ;
GtkWidget *outputville;
outputville = lookup_widget (button, "FSlabel44champ5") ;
GtkWidget *outputtel;
outputtel = lookup_widget (button, "FSlabel45champ6") ;
GtkWidget *outputcontact;
outputcontact = lookup_widget (button, "FSlabel46champ7") ;
GtkWidget *outputsante;
outputsante = lookup_widget (button, "FSlabel47champ8") ;
GtkWidget *outputnumch;
outputnumch = lookup_widget (button, "FSlabel50champ11") ;
GtkWidget *outputid;
outputid = lookup_widget (button, "FSlabel40champ1") ;


//essai
windowajout=lookup_widget (button,"safaflissAjout");

id3= lookup_widget (button,"FSentry1idajout");
nom3 = lookup_widget (button,"FSentry2nom");
prenom3 = lookup_widget (button,"FSentry3prenom");
CIN3 = lookup_widget (button,"FSentry4cin");


jour1=lookup_widget (button,"FSspinbutton1jour");
mois1=lookup_widget (button,"FSspinbutton2mois");
annee1=lookup_widget (button,"FSspinbutton3ans");



etud.sexe=x;



ville3 = lookup_widget (button,"FSentry5ville");
tel3 = lookup_widget (button,"FSentry6tel");
contact3 = lookup_widget (button,"FSentry7contact");
sante3 = lookup_widget (button,"FSentry9sante");


niveau1=lookup_widget (button,"FScombobox3niveau");
payer1=lookup_widget (button,"FScombobox2payer");


chambre1=lookup_widget (button,"FScombobox1chambreajout");


numch3 = lookup_widget (button,"FSentry8nchambre");


output1 = lookup_widget (button, "FSlabel1msgajout") ;


strcpy(iden,gtk_entry_get_text(GTK_ENTRY(id3)));
strcpy(etud.nom,gtk_entry_get_text(GTK_ENTRY(nom3)));
strcpy(etud.prenom,gtk_entry_get_text(GTK_ENTRY(prenom3)));
strcpy(carte,gtk_entry_get_text(GTK_ENTRY(CIN3)));


etud.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
etud.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
etud.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));


strcpy(etud.ville,gtk_entry_get_text(GTK_ENTRY(ville3)));
strcpy(etud.tel,gtk_entry_get_text(GTK_ENTRY(tel3)));
strcpy(etud.contact,gtk_entry_get_text(GTK_ENTRY(contact3)));
strcpy(etud.sante,gtk_entry_get_text(GTK_ENTRY(sante3)));


if (strcmp("1ere",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(etud.niveau,"1");
}
if (strcmp("2eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(etud.niveau,"2");
}
if (strcmp("3eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(etud.niveau,"3");
}
if (strcmp("4eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(etud.niveau,"4");
}
if (strcmp("5eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(etud.niveau,"5");
}



if (strcmp("par*tranche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(payer1)))==0)
{
etud.payer=1;
}
if (strcmp("par*mois",gtk_combo_box_get_active_text(GTK_COMBO_BOX(payer1)))==0)
{
etud.payer=2;
}
if (strcmp("par*annee",gtk_combo_box_get_active_text(GTK_COMBO_BOX(payer1)))==0)
{
etud.payer=3;
}



if (strcmp("Individuelle",gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre1)))==0)
{
strcpy(etud.chambre,"1");
}
if (strcmp("Double",gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre1)))==0)
{
strcpy(etud.chambre,"2");
}
if (strcmp("Triple",gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre1)))==0)
{
strcpy(etud.chambre,"3");
}


strcpy(etud.numch,gtk_entry_get_text(GTK_ENTRY(numch3)));


v=verif(etud,iden,carte);
if((v==1)&&(tab1[0]==1))
{
strcpy(etud.id,gtk_entry_get_text(GTK_ENTRY(id3)));
strcpy(etud.carteid,gtk_entry_get_text(GTK_ENTRY(CIN3)));
/*****/
int flag=0;
if (strlen(etud.nom)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputnom),"veuillez remplir ce champ!");
}else{
gtk_label_set_text(GTK_LABEL(outputnom),"");
}
if(strlen(etud.prenom)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputprenom),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputprenom),"");
if(strlen(etud.carteid)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputcin),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputcin),"");
if(strlen(etud.ville)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputville),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputville),"");
if(strlen(etud.tel)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputtel),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputtel),"");
if(strlen(etud.contact)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputcontact),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputcontact),"");
if(strlen(etud.sante)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputsante),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputsante),"");
if(strlen(etud.numch)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputnumch),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputnumch),"");
if(strlen(etud.id)==0)
{
flag=1;
gtk_label_set_text(GTK_LABEL(outputid),"veuillez remplir ce champ!");
}else
gtk_label_set_text(GTK_LABEL(outputid),"");
if(flag==0)
{
ajout (etud);
gtk_widget_destroy(windowajout);
windowfoyer=lookup_widget (button,"safaflissespacefoyer"); //**


windowfoyer=create_safaflissespacefoyer();
window8=create_Flisssafawindow1modif_ajout_supp();
gtk_widget_show (window8);
//gtk_widget_show (windowfoyer);
test=3;
treeview1=lookup_widget(windowfoyer,"FStreeview1liste");
afficher(treeview1);
}
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"id ou CIN déja utilisés ou bien case non cochée");
}
}





/*****************/





void
on_flisssafabutton4ajouter_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}




/*****************/





void
on_FSbutton8supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowsure;
windowsure=create_safaflisssure();
gtk_widget_show (windowsure);
}



/*****************/




void
on_FSbutton7modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowmodifier;
windowmodifier=create_safaflissModifier();
gtk_widget_show (windowmodifier);
}




/*****************/





void
on_FSbutton10retour_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowfoyer;
windowfoyer=create_safaflissespacefoyer();
gtk_widget_show (windowfoyer);
}



/*****************/





void
on_FSbutton1ajout_ins_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * nom1 , * prenom1 , * user , * pw , * role1 , * windowauth ;
char nom2[20];
char prenom2[20];
char login[20];
char password[20];
char role[20];
nom1 = lookup_widget (button,"FSentry1nom_ins");
prenom1 = lookup_widget (button,"FSentry2prenom_ins");
user = lookup_widget (button,"FSentry3user_ins");
pw = lookup_widget (button,"FSentry4pass_ins");
role1 = lookup_widget (button,"FSentry5role_ins"); 

strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(prenom2,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(login,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(role,gtk_entry_get_text(GTK_ENTRY(role1)));
ajouter(nom2,prenom2,login,password,role);
windowauth = create_safaflissauthentification();
gtk_widget_show(windowauth);
}




/*****************/





void
on_FSbutton2log_auth_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username,*password,*windowfoyer,*output;
char user[20];
char passw[20];
int trouve;
username = lookup_widget (button, "FSentry6user_auth");
password = lookup_widget (button, "FSentry7pass_auth");
output = lookup_widget (button, "FSlabel1msg") ;
strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(password)));
trouve = verifier(user,passw);
if (trouve==1)
{
windowfoyer=create_safaflissespacefoyer();
gtk_widget_show (windowfoyer);
}
else
{
gtk_label_set_text(GTK_LABEL(output),"Login ou password incorrect");
}
}



/*****************/




void
on_FSradiobutton2homme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}



/*****************/



void
on_FSradiobutton1femme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}



/*****************/










void
on_FSbutton4enregistrer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * nom3 , * prenom3 , * CIN3 , * ville3 , * tel3 , * contact3 , * sante3 , * numch3, * windowfoyer, *windowconfirmer;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *niveau1;
GtkWidget *chambre1;
GtkWidget *payer1;
GtkWidget *treeview1;
GtkWidget *windowmodifff;
etudiant etud ;
int v;
char iden[20];
char a[20],b[20],c[20];
int d,e,ff;
int z;
char w[20],g[20],h[20],i[20];
char j[20];
int k;
char m[20],l[20];

windowmodifff=lookup_widget (button,"safaflissModifier");


nom3 = lookup_widget (button,"FSentry10nom");
prenom3 = lookup_widget (button,"FSentry11prenom");
CIN3 = lookup_widget (button,"FSentry12cin");


jour1=lookup_widget (button,"FSspinbutton4jour");
mois1=lookup_widget (button,"FSspinbutton5mois");
annee1=lookup_widget (button,"FSspinbutton6ans");



z=x;



ville3 = lookup_widget (button,"FSentry19ville");
tel3 = lookup_widget (button,"FSentry20tel");
contact3 = lookup_widget (button,"FSentry21contact");
sante3 = lookup_widget (button,"FSentry22sante");


niveau1=lookup_widget (button,"FScombobox1niveaumo");
payer1=lookup_widget (button,"FScombobox2payermo");

chambre1=lookup_widget (button,"FScombobox1chambremodifier");


numch3 = lookup_widget (button,"FSentry36nchambre");

strcpy(a,gtk_entry_get_text(GTK_ENTRY(nom3)));
strcpy(b,gtk_entry_get_text(GTK_ENTRY(prenom3)));
strcpy(c,gtk_entry_get_text(GTK_ENTRY(CIN3)));


d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
ff=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));


strcpy(w,gtk_entry_get_text(GTK_ENTRY(ville3)));
strcpy(g,gtk_entry_get_text(GTK_ENTRY(tel3)));
strcpy(h,gtk_entry_get_text(GTK_ENTRY(contact3)));
strcpy(i,gtk_entry_get_text(GTK_ENTRY(sante3)));


if (strcmp("1ere",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(j,"1");
}
if (strcmp("2eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(j,"2");
}
if (strcmp("3eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(j,"3");
}
if (strcmp("4eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(j,"4");
}
if (strcmp("5eme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau1)))==0)
{
strcpy(j,"5");
}



if (strcmp("par*tranche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(payer1)))==0)
{
k=1;
}
if (strcmp("par*mois",gtk_combo_box_get_active_text(GTK_COMBO_BOX(payer1)))==0)
{
k=2;
}
if (strcmp("par*annee",gtk_combo_box_get_active_text(GTK_COMBO_BOX(payer1)))==0)
{
k=3;
}

if (strcmp("Individuelle",gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre1)))==0)
{
strcpy(m,"1");
}
if (strcmp("Double",gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre1)))==0)
{
strcpy(m,"2");
}
if (strcmp("Triple",gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre1)))==0)
{
strcpy(m,"3");
}


strcpy(l,gtk_entry_get_text(GTK_ENTRY(numch3)));
modifier(etud,ident,a,b,c,d,e,ff,z,w,g,h,i,j,k,m,l);
gtk_widget_destroy(windowmodifff);
windowfoyer=create_safaflissespacefoyer();
windowconfirmer=create_Flisssafawindow1modif_ajout_supp();
gtk_widget_show (windowconfirmer);
//gtk_widget_show (windowfoyer);
treeview1=lookup_widget(windowfoyer,"FStreeview1liste");
afficher(treeview1);
test=1;
}



/*****************/




void
on_FStreeview1liste_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* prenom;
gchar* tel;
gchar* niveau;
gchar* chambre;
gchar* numch;
etudiant etud;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nom, 2, &prenom, 3, &tel, 4, &niveau, 5, &chambre, 6, &numch, -1);
strcpy(etud.id,id);
strcpy(ident,id);
strcpy(etud.nom,nom);
strcpy(etud.prenom,prenom);
strcpy(etud.tel,tel);
strcpy(etud.niveau,niveau);
strcpy(etud.chambre,chambre);
strcpy(etud.numch,numch);
afficher(treeview);
}
}



/*****************/





void
on_flisssafabutton1ajouter_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
tab1[0]=0;
GtkWidget * windowajout;
windowajout=create_safaflissAjout();
gtk_widget_show (windowajout);
}




/*****************/





void
on_flisssafabutton2chercher_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *iden , *outputt;
GtkWidget * windowaffichage;
etudiant etud ;
int v;
iden = lookup_widget (button,"FSentry1chercher");
outputt = lookup_widget (button, "FSlabel7msgfoyer") ;
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(iden)));
v=verif1(etud,ident);
if(v==1)
{
windowaffichage=create_safaflissaffichage();
gtk_widget_show (windowaffichage);
}
else
{
gtk_label_set_text(GTK_LABEL(outputt),"identifiant introuvable");
}
}



/*****************/





void
on_FSbutton1oui_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
etudiant etud;
GtkWidget * windowsure;
GtkWidget * windowfoyer, *window8;
windowsure=lookup_widget (button,"safaflisssure");
window8=create_Flisssafawindow1modif_ajout_supp();
supprimer(etud,ident);
test=2;
gtk_widget_show (window8);
gtk_widget_destroy(windowsure);
windowfoyer=create_safaflissespacefoyer();
//gtk_widget_show (windowfoyer);
}




/*****************/




void
on_FSbutton2non_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowsure;
GtkWidget * windowaffichage;
windowsure=lookup_widget (button,"safaflisssure");
gtk_widget_destroy(windowsure);
windowaffichage=create_safaflissaffichage();
//gtk_widget_show (windowaffichage);
}







/*****************/




void
on_FSradiobutton3femme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}




/*****************/




void
on_FSradiobutton4homme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}




/*****************/





void
on_FSbutton2okii9_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output1, *output5;
output1 = lookup_widget (button, "FSentry1stat9") ;
output5= lookup_widget (button, "FSlabel34nbetud9");
int a;
char nv[20];
char text1[20];
etudiant etud;
strcpy(nv,gtk_entry_get_text(GTK_ENTRY(output1)));
a=nombreetud(etud,nv);
sprintf(text1, "%d", a);
gtk_label_set_text(GTK_LABEL(output5),text1);
}



/*****************/





void
on_FSbutton1actualiser_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1, *windowfoyer, *w1;
w1 = lookup_widget(button,"safaflissespacefoyer");
windowfoyer=create_safaflissespacefoyer();
gtk_widget_show (windowfoyer);
gtk_widget_hide(w1);
treeview1 = lookup_widget(windowfoyer,"FStreeview1liste");
vider (treeview1);
afficher(treeview1);
}




/*****************/





void
on_FSbutton3supprimerfoyer_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
etudiant etud;
GtkWidget * windowsure;
windowsure=create_safaflisswindow1ouinon();
gtk_widget_show (windowsure);
}



/*****************/





void
on_FSbutton1modifierfoyer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
etudiant etud;
GtkWidget * windowmodifier;
windowmodifier=create_safaflissModifier();
gtk_widget_show (windowmodifier);
}




/*****************/





void
on_FSbutton2afficherfoyer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
etudiant etud;
GtkWidget * windowafficher;
windowafficher=create_safaflissaffichage();
gtk_widget_show (windowafficher);
}




/*****************/






gboolean
on_safaflissstatistique_focus_in_event (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget *output1, *output2, *output3, *output4, *output5;
output1 = lookup_widget (widget, "FSlabel371erestat") ;
output2 = lookup_widget (widget, "FSlabel412emestat") ;
output3 = lookup_widget (widget, "FSlabel423emestat") ;
output4 = lookup_widget (widget, "FSlabel434emestat") ;
output5= lookup_widget (widget, "FSlabel455emestat");
int a;
char nv[20];
char text1[20];
etudiant etud;

a=nombreetud(etud,"1");
sprintf(text1, "%d", a);
gtk_label_set_text(GTK_LABEL(output1),text1);

a=nombreetud(etud,"2");
sprintf(text1, "%d", a);
gtk_label_set_text(GTK_LABEL(output2),text1);

a=nombreetud(etud,"3");
sprintf(text1, "%d", a);
gtk_label_set_text(GTK_LABEL(output3),text1);

a=nombreetud(etud,"4");
sprintf(text1, "%d", a);
gtk_label_set_text(GTK_LABEL(output4),text1);

a=nombreetud(etud,"5");
sprintf(text1, "%d", a);
gtk_label_set_text(GTK_LABEL(output5),text1);
  return FALSE;
}


/*****************/




void code (char ident[])
{
etudiant etud;
FILE *f;
f=fopen(f,"etudiant.txt");
while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
    {
        if (strcmp(etud.id,ident)==0)
        {
	    fclose(f);
            return etud;
        }
    }
    
}




/*****************/





gboolean
on_safaflissaffichage_focus_in_event   (GtkWidget       *button,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7, *output8, *output9, *output10, *output11, *output12, *output13, *output14, *output15, *output16;
FILE *f=NULL;
etudiant etud;
char text1[20];
char text2[20];
char text3[20];
char text4[20];
char text5[20];
output1 = lookup_widget (button, "FSlabel8id22") ;
output2 = lookup_widget (button, "FSlabel10nom22") ;
output3 = lookup_widget (button, "FSlabel12prenom22") ;
output4 = lookup_widget (button, "FSlabel14cin22") ;
output5 = lookup_widget (button, "FSlabel16jour22") ;
output6 = lookup_widget (button, "FSlabel18mois22") ;
output7 = lookup_widget (button, "FSlabel20annee22") ;
output8 = lookup_widget (button, "FSlabel22sexe22") ;
output9 = lookup_widget (button, "FSlabel31ville22") ;
output10 = lookup_widget (button, "FSlabel32tel22") ;
output11 = lookup_widget (button, "FSlabel33contact22") ;
output12 = lookup_widget (button, "FSlabel34sante22") ;
output13 = lookup_widget (button, "FSlabel35niveau22") ;
output14 = lookup_widget (button, "FSlabel36payer22") ;
output15 = lookup_widget (button, "FSlabel37ch22") ;
output16 = lookup_widget (button, "FSlabel38numch22") ;
f=fopen("etudiant.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
{
if ((strcmp(etud.id,ident)==0))
{
gtk_label_set_text(GTK_LABEL(output1),etud.id);
gtk_label_set_text(GTK_LABEL(output2),etud.nom);
gtk_label_set_text(GTK_LABEL(output3),etud.prenom);
gtk_label_set_text(GTK_LABEL(output4),etud.carteid);
gtk_label_set_text(GTK_LABEL(output9),etud.ville);
gtk_label_set_text(GTK_LABEL(output10),etud.tel);
gtk_label_set_text(GTK_LABEL(output11),etud.contact);
gtk_label_set_text(GTK_LABEL(output12),etud.sante);


if (strcmp(etud.niveau,"1")==0)
{
gtk_label_set_text(GTK_LABEL(output13),"1ère année" );
}
if (strcmp(etud.niveau,"2")==0)
{
gtk_label_set_text(GTK_LABEL(output13),"2ème année" );
}
if (strcmp(etud.niveau,"3")==0)
{
gtk_label_set_text(GTK_LABEL(output13),"3ème année" );
}
if (strcmp(etud.niveau,"4")==0)
{
gtk_label_set_text(GTK_LABEL(output13),"4ème année" );
}
if (strcmp(etud.niveau,"5")==0)
{
gtk_label_set_text(GTK_LABEL(output13),"5ème année" );
}


gtk_label_set_text(GTK_LABEL(output15),etud.chambre);
gtk_label_set_text(GTK_LABEL(output16),etud.numch);

sprintf(text1, "%d", etud.naissance.jour);
gtk_label_set_text(GTK_LABEL(output5),text1);

sprintf(text2, "%d", etud.naissance.mois);
gtk_label_set_text(GTK_LABEL(output6),text2);

sprintf(text3, "%d", etud.naissance.annee);
gtk_label_set_text(GTK_LABEL(output7),text3);

sprintf(text4, "%d", etud.sexe);
if(strcmp(text4,"1")==0)
{
gtk_label_set_text(GTK_LABEL(output8),"Femme");
}
if(strcmp(text4,"2")==0)
{
gtk_label_set_text(GTK_LABEL(output8),"Homme");
}


sprintf(text5, "%d", etud.payer);
if(strcmp(text5,"1")==0)
{
gtk_label_set_text(GTK_LABEL(output14),"par tranche");
}
if(strcmp(text5,"2")==0)
{
gtk_label_set_text(GTK_LABEL(output14),"par mois");
}
if(strcmp(text5,"3")==0)
{
gtk_label_set_text(GTK_LABEL(output14),"par année");
}


}
}
fclose(f);
  return FALSE;
}



/*****************/




gboolean
on_safaflissModifier_focus_in_event    (GtkWidget       *button,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
if (flagmodif == 0){
GtkWidget *output1, *output3, *output4, *output5, *output6, *output7, *output8, *output9, *output10, *output11, *output12, *output13, *output14, *output15, *output16, *output88, *win, *entree;
entree = lookup_widget (button, "FSentry1nonmodifiable") ;
output1 = lookup_widget (button, "FSentry10nom") ;
output3 = lookup_widget (button, "FSentry11prenom") ;
output4 = lookup_widget (button, "FSentry12cin") ;

output5=lookup_widget (button,"FSspinbutton4jour");
output6=lookup_widget (button,"FSspinbutton5mois");
output7=lookup_widget (button,"FSspinbutton6ans");

output8=lookup_widget (button,"FSradiobutton3femme");
output88=lookup_widget (button,"FSradiobutton4homme");

output9 = lookup_widget (button, "FSentry19ville") ;
output10 = lookup_widget (button, "FSentry20tel") ;
output11 = lookup_widget (button, "FSentry21contact") ;
output12 = lookup_widget (button, "FSentry22sante") ;

output13= lookup_widget (button, "FScombobox1niveaumo");
output14= lookup_widget (button, "FScombobox2payermo");

output15= lookup_widget (button, "FScombobox1chambremodifier");


output16 = lookup_widget (button, "FSentry36nchambre");
FILE *f=NULL;
etudiant etud;
f=fopen("etudiant.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d %d %s %s %s %s %s %d %s %s \n",etud.id,etud.nom,etud.prenom,etud.carteid,&etud.naissance.jour,&etud.naissance.mois,&etud.naissance.annee,&etud.sexe,etud.ville,etud.tel,etud.contact,etud.sante,etud.niveau,&etud.payer,etud.chambre,etud.numch)!=EOF)
{
if ((strcmp(etud.id,ident)==0))
{
gtk_entry_set_text(GTK_ENTRY(entree),etud.id);
gtk_entry_set_text(GTK_ENTRY(output3),etud.prenom);
gtk_entry_set_text(GTK_ENTRY(output1),etud.nom);
gtk_entry_set_text(GTK_ENTRY(output4),etud.carteid);

gtk_spin_button_set_value(output5,etud.naissance.jour);
gtk_spin_button_set_value(output6,etud.naissance.mois);
gtk_spin_button_set_value(output7,etud.naissance.annee);

if(etud.sexe==1)
{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output8),TRUE);}
else if (etud.sexe==2)
{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output88),TRUE);}


gtk_entry_set_text(GTK_ENTRY(output9),etud.ville);
gtk_entry_set_text(GTK_ENTRY(output10),etud.tel);
gtk_entry_set_text(GTK_ENTRY(output11),etud.contact);
gtk_entry_set_text(GTK_ENTRY(output12),etud.sante);

if (strcmp(etud.niveau,"1")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output13),0);
}
if (strcmp(etud.niveau,"2")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output13),1);
}
if (strcmp(etud.niveau,"3")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output13),2);
}
if (strcmp(etud.niveau,"4")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output13),3);
}
if (strcmp(etud.niveau,"5")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output13),4);
}


if (etud.payer=1)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output14),0);
}
if (etud.payer=2)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output14),1);
}
if (etud.payer=3)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output14),2);
}



if (strcmp(etud.chambre,"1")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output15),0);
}
if (strcmp(etud.chambre,"2")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output15),1);
}
if (strcmp(etud.chambre,"3")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(output15),2);
}



gtk_entry_set_text(GTK_ENTRY(output16),etud.numch);
}
}
fclose(f);
}
flagmodif = 1;
  return FALSE;
}



/*****************/




gboolean
on_safaflisssure_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{

  return FALSE;
}




/*****************/




void
on_FSbutton1window2oui_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
etudiant etud;
GtkWidget * windowsure;
GtkWidget * windowfoyer, *window8;
windowsure=lookup_widget (button,"safaflisswindow1ouinon");
supprimer(etud,ident);
test=2;
window8=create_Flisssafawindow1modif_ajout_supp();
gtk_widget_show (window8);
gtk_widget_destroy(windowsure);
windowfoyer=create_safaflissespacefoyer();
//gtk_widget_show (windowfoyer);
}



/*****************/




void
on_FSbutton2window2non_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowsure;
GtkWidget * windowfoyer;
windowsure=lookup_widget (button,"safaflisswindow1ouinon");
gtk_widget_destroy(windowsure);
windowfoyer=create_safaflissespacefoyer();
//gtk_widget_show (windowfoyer);
}




/*****************/




gboolean
on_FStreeview1liste_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
  
  return FALSE;
}


/*****************/


gboolean
on_Flisssafawindow1modif_ajout_supp_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget *output;
output = lookup_widget (widget, "FSlabel37messagemod_aj_supp") ;
if(test==1)
{
gtk_label_set_text(GTK_LABEL(output),"La modification a été effectuée avec succés");
test=0;
}
if(test==2)
{
gtk_label_set_text(GTK_LABEL(output),"La suppression a été effectuée avec succés");
test=0;
}
if(test==3)
{
gtk_label_set_text(GTK_LABEL(output),"L'ajout a été effectué avec succés");
test=0;
}
  return FALSE;
}


/*****************/



void
on_FSbutton1retourner_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowretour;
windowretour=lookup_widget (button,"safaflissaffichage");
gtk_widget_destroy(windowretour);
}


/*****************/



void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{tab1[0]=1;}
else
tab1[0]=0;
}



/*****************/



void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}

/*****************/


void
on_FSbutton2envoyerwww_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


/*****************/



void
on_safaflissModifier_destroy           (GtkObject       *object,
                                        gpointer         user_data)
{
flagmodif =0;
}


void
on_FSentry1chercher_changed            (GtkEditable     *editable,
                                        gpointer         user_data)
{
/*GtkWidget *iden;
GtkWidget *treeview1, *windowfoyer, *w1,*chercher;
etudiant etud ;
char identtt[20];
char safarecherche[20]="a";
iden=lookup_widget (editable,"FSentry1chercher");
//iden = lookup_widget (editable,"FSentry1chercher");
gtk_entry_set_text(GTK_ENTRY(iden),safarecherche);
strcpy(safarecherche,gtk_entry_get_text(GTK_ENTRY(iden)));
w1 = lookup_widget(editable,"safaflissespacefoyer");
windowfoyer=create_safaflissespacefoyer();
gtk_widget_show (windowfoyer);
gtk_widget_hide(w1);

iden=lookup_widget (GTK_WIDGET(editable),"FSentry1chercher");
gtk_entry_set_text(GTK_ENTRY(iden),safarecherche);

treeview1 = lookup_widget(windowfoyer,"FStreeview1liste");
vider (treeview1);
afficher1(treeview1,safarecherche);*/
/*GtkWidget *treeview1, *windowfoyer;
GtkWidget *iden;

char safarecherche[20]="a";
treeview1 = lookup_widget(windowfoyer,"FStreeview1liste");
iden = lookup_widget (GTK_WIDGET(editable),"FSentry1chercher");
afficher1(treeview1,safarecherche);
strcpy(safarecherche,gtk_entry_get_text(GTK_ENTRY(safarecherche)));
afficher1(treeview1,safarecherche);*/
}



