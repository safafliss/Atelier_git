#include <gtk/gtk.h>


void
on_FSbutton9trier_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_flisssafabutton2statistique_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_flisssafabutton3ajouter_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_flisssafabutton4ajouter_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton8supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton7modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton10retour_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1ajout_ins_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2log_auth_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSradiobutton2homme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FSradiobutton1femme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_FSbutton4enregistrer_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_FStreeview1liste_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_flisssafabutton1ajouter_clicked     (GtkButton       *button,
                                        gpointer         user_data);


void
on_flisssafabutton2chercher_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1afficher22_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1oui_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2non_clicked                (GtkButton       *button,
                                        gpointer         user_data);


void
on_FSradiobutton3femme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FSradiobutton4homme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_FSbutton2okii9_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FSbutton1actualiser_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FSbutton3supprimerfoyer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1modifierfoyer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2afficherfoyer_clicked      (GtkButton       *button,
                                        gpointer         user_data);



gboolean
on_safaflissstatistique_focus_in_event (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_safaflissaffichage_focus_in_event   (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_safaflissModifier_focus_in_event    (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_safaflisssure_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);


void
on_FSbutton1window2oui_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2window2non_clicked         (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_FStreeview1liste_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);


gboolean
on_Flisssafawindow1modif_ajout_supp_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_FSbutton1retourner_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2envoyerwww_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_safaflissModifier_destroy           (GtkObject       *object,
                                        gpointer         user_data);

void
on_FSentry1chercher_changed            (GtkEditable     *editable,
                                        gpointer         user_data);
