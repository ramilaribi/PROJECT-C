#include"election.h"
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"

enum
{
	
	EID,
	ENOMBRES_COSEILLE,
	EMUNICIPALITE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS,
};
////*******/////ajouter_rami
void ajouter_Election(election e )
{
   FILE * f=fopen("election.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s\n",e.idr,e.municipaliter,e.nbr_conseillers,e.dr.jour,e.dr.mois,e.dr.annee);
        fclose(f);
      
    }
   return;
}
////////afficher_rami
void afficher_Election(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	

	char id[20];
	char municipalite[20];
        char nbr_conseillers[20];
	char jour[20];
	char mois[20];
	char annee[20];

	store=NULL;
	FILE* f=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nbr_conseillers", renderer, "text", ENOMBRES_COSEILLE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text", EMUNICIPALITE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	
       store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("election.txt","r");
	if(f==NULL)
	{return;
	}	
	else 
	{

		f=fopen("election.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s\n",id,nbr_conseillers,municipalite,jour,mois,annee)!=EOF)
		{	gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, EID, id, ENOMBRES_COSEILLE,nbr_conseillers, EMUNICIPALITE, municipalite, EJOUR, jour, EMOIS, mois, EANNEE, annee, -1);
		}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
	}
}
///////////////supprimer_rami////////////////


void supprimer_election(election e)
    {   election e1;
	FILE *f, *g;
	f=fopen("election.txt","r");
	g=fopen("election1.txt","w");
	if(f==NULL || g==NULL)
	  { return;
	  }
	else
	{ while(fscanf(f,"%s %s %s %s %s %s\n",e1.idr,e1.municipaliter,e1.nbr_conseillers,e1.dr.jour,e1.dr.mois,e1.dr.annee)!=EOF)
	   {
if( strcmp(e.idr,e1.idr)!=0 ||  strcmp(e.municipaliter,e1.municipaliter)!=0 ||strcmp(e.nbr_conseillers,e1.nbr_conseillers)!=0 || strcmp(e.dr.jour,e1.dr.jour)!=0 ||strcmp(e.dr.mois,e1.dr.mois)!=0 || strcmp(e.dr.annee,e1.dr.annee)!=0) 
fprintf(g,"%s %s %s %s %s %s\n",e1.idr,e1.municipaliter,e1.nbr_conseillers,e1.dr.jour,e1.dr.mois,e1.dr.annee);
	   }
fclose(f);
fclose(g);
remove("election.txt");
rename("election1.txt","election.txt");
	}
    }
/////////////chercher_rami/////
election chercher_election( char idr[])
{
	
    election e;
    int tr=0;
    FILE * f=fopen("election.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%s %s %s %s %s %s\n",e.idr,e.nbr_conseillers,e.municipaliter,e.dr.jour,e.dr.mois,e.dr.annee)!=EOF )
        {
            if(strcmp(e.idr,idr)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
    {
       strcpy(e.idr,"-1");
    }
    return e;

}
int modifier_election( char * filename,char idr[],election er )
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouvelection.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",e.idr,e.nbr_conseillers,e.municipaliter,e.dr.jour,e.dr.mois,e.dr.annee)!=EOF )
        {
            if(strcmp(e.idr, idr)==0)
            {
              fprintf(f2,"%s %s %s %s %s %s\n",er.idr,er.nbr_conseillers,er.municipaliter,er.dr.jour,er.dr.mois,er.dr.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s\n",e.idr,e.nbr_conseillers,e.municipaliter,e.dr.jour,e.dr.mois,e.dr.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouvelection.txt", filename);
    return tr;

}

	
