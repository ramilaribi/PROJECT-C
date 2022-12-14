#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"election.h"

int cons=10;
int consm=22;
election er;
void
on_radior2_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=12;
}
}


void
on_radior3_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=16;
}
}


void
on_radior6_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=40;
}
}


void
on_radior5_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=30;
}
}


void
on_radior4_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=22;
}
}


void
on_radior1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=10;
}
}


void
on_radior7_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=60;
}
}


void
on_afficherr1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(objet,"ajouter_election");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(objet,"afficher_election");
	affiche=create_afficher_election();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeviewr");
	afficher_Election(treeview);
}


void
on_confirmerr1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
election e;
char conseiller[50];
char joure[50];
char moise[50];
char an[50];
int j,m,a;
GtkWidget *id , *municipalite ,*jour, *mois, *annee, *alert ,*alert1;
GtkWidget *window;

window=lookup_widget(objet,"ajouter_election");
id=lookup_widget(objet,"idr1");
municipalite=lookup_widget(objet,"comboboxr1");
jour=lookup_widget(objet,"spinbutton1");
mois=lookup_widget(objet,"spinbutton21");
annee=lookup_widget(objet,"spinbutton3");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
alert=lookup_widget(objet,"alertr1");
alert1=lookup_widget(objet,"alertr2");


sprintf(conseiller,"%d",cons);
sprintf(joure,"%d",j);
sprintf(moise,"%d",m);
sprintf(an,"%d",a);


strcpy(e.nbr_conseillers,conseiller);
strcpy(e.idr,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.municipaliter,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
gtk_label_set_text(GTK_LABEL(alert),"ajout avec succés");
gtk_label_set_text(GTK_LABEL(alert1),e.nbr_conseillers);

strcpy(e.dr.jour,joure);
strcpy(e.dr.mois,moise);
strcpy(e.dr.annee,an);

supprimer_election(e);
ajouter_Election(e);
}


void
on_retourr2_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu, *affiche;
affiche=lookup_widget(objet,"afficher_election");

gtk_widget_destroy(affiche);
menu=create_menu();
gtk_widget_show(menu);
}


void
on_chercherr1_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget* inputIDchercher ;
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
	  GtkWidget *ra1,*ra2,*ra3,*ra4,*ra5,*ra6,*ra7;
	  GtkWidget *nbc;

	inputIDchercher=lookup_widget(button,"idr2") ;
	ra1=lookup_widget(button, "radior8");
	ra2=lookup_widget(button, "radior9");
	ra3=lookup_widget(button, "radior10");
	ra4=lookup_widget(button, "radior11");
	ra5=lookup_widget(button, "radior12");
	ra6=lookup_widget(button, "radior13");
	ra7=lookup_widget(button, "radior14");
	nbc=lookup_widget(button, "alertr3");
//declarer 
        char idch[50];
	int  j1, m1, a1;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function chercher_election
	er=chercher_election(idch);
	if(strcmp(er.idr,"-1")!=0)

	{
	GtkWidget *erreurModification;
erreurModification= lookup_widget (button ,"alertr5");

gtk_label_set_text(GTK_LABEL(erreurModification),"Cette election existe !");
gtk_widget_show (erreurModification);

	j1 = atoi (er.dr.jour);
	 m1 = atoi (er.dr.mois);
	 a1 = atoi (er.dr.annee);
         

	 SJ=lookup_widget(button, "spinr4");
         gtk_spin_button_set_value(SJ,j1);
	 SM=lookup_widget(button, "spinr5");
         gtk_spin_button_set_value(SM,m1);
	 SA=lookup_widget(button, "spinr6");
         gtk_spin_button_set_value(SA,a1);
	output=lookup_widget(button,"alertr3");
     if(strcmp(er.nbr_conseillers,"10")==0)
       {
        
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra1),TRUE);
	
       }
     else if(strcmp(er.nbr_conseillers,"12")==0)
       {
        
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra2),TRUE);
	}
      else if(strcmp(er.nbr_conseillers,"16")==0)
       {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra3),TRUE);
	}
 	else if(strcmp(er.nbr_conseillers,"22")==0)
       {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra4),TRUE);
	}
	 else if(strcmp(er.nbr_conseillers,"30")==0)
       {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra5),TRUE);
	}
	 else if(strcmp(er.nbr_conseillers,"40")==0)
       {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra6),TRUE);
	}
           else {
             
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra7),TRUE);
	
            }

	 COX=lookup_widget(button,"comboboxr2");
	 if(strcmp(er.municipaliter,"Ariana")==0){
         	gtk_combo_box_set_active(COX,1);}
	 else if(strcmp(er.municipaliter,"gabes")==0){
         	gtk_combo_box_set_active(COX,2);}
	else if(strcmp(er.municipaliter,"Jendouba")==0){
         	gtk_combo_box_set_active(COX,3);}
	 else if(strcmp(er.municipaliter,"Tunis")==0){
         	gtk_combo_box_set_active(COX,4);}
	 else {
         	gtk_combo_box_set_active(COX,5);}

	}
	else{
	GtkWidget *erreurModification;
erreurModification= lookup_widget (button ,"alertr5");
gtk_label_set_text(GTK_LABEL(erreurModification),"Cette election n'existe pas ");
gtk_widget_show (erreurModification);

	}



}



void
on_afficherr2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *modif;
	GtkWidget *affiche;
	GtkWidget *treeview;

	modif=lookup_widget(objet,"modifier_election");

	gtk_widget_destroy(modif);
	affiche=lookup_widget(objet,"afficher_election");
	affiche=create_afficher_election();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeviewr");
	afficher_Election(treeview);
}


void
on_modifierr1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
election err;
char conseiller[50];
char joure[50];
char moise[50];
char an[50];
int j,m,a;
GtkWidget *id , *municipalite ,*jour, *mois, *annee, *alert ,*alert1;
GtkWidget *window;

window=lookup_widget(button,"modifier_election");
id=lookup_widget(button,"idr2");
municipalite=lookup_widget(button,"comboboxr2");
jour=lookup_widget(button,"spinr4");
mois=lookup_widget(button,"spinr5");
annee=lookup_widget(button,"spinr6");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
alert=lookup_widget(button,"alertr4");
alert1=lookup_widget(button,"alertr3");


sprintf(conseiller,"%d",cons);
sprintf(joure,"%d",j);
sprintf(moise,"%d",m);
sprintf(an,"%d",a);


strcpy(err.nbr_conseillers,conseiller);
strcpy(err.idr,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(err.municipaliter,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
gtk_label_set_text(GTK_LABEL(alert),"modifie avec success ");
gtk_label_set_text(GTK_LABEL(alert1),err.nbr_conseillers);

strcpy(err.dr.jour,joure);
strcpy(err.dr.mois,moise);
strcpy(err.dr.annee,an);

supprimer_election(er);
ajouter_Election(err);

}


void
on_radior13_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=40;
}
}


void
on_radior10_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=16;
}
}


void
on_radior14_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=60;
}
}


void
on_radior12_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=30;
}
}


void
on_radior9_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=12;
}
}


void
on_radior8_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=10;
}
}


void
on_radior11_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
cons=22;
}
}


void
on_Retourr_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
affiche=lookup_widget(objet,"afficher_election");

gtk_widget_destroy(affiche);
ajout=create_ajouter_election();
gtk_widget_show(ajout);
}


void
on_modifierr2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifie, *affiche;
affiche=lookup_widget(objet,"afficher_election");

gtk_widget_destroy(affiche);
modifie=create_modifier_election();
gtk_widget_show(modifie);
}


void
on_treeviewr_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *id;
        gchar *nbr_conseiller;
        gchar *municipalite;
	gchar *jour;
	gchar *mois;
	gchar *annee;

	election e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &municipalite , 2, &nbr_conseiller , 3, &jour, 4, &mois, 5, &annee, -1);
	
	strcpy(e.idr,id);
	strcpy(e.nbr_conseillers,nbr_conseiller);
	strcpy(e.municipaliter,municipalite);
	strcpy(e.dr.jour,jour);
	strcpy(e.dr.mois,mois);
	strcpy(e.dr.annee,annee);
	
}
	supprimer_election(e);

	afficher_Election(treeview);
}



