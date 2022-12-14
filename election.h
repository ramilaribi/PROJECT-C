#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
char jour[20];
char mois[20];
char annee[20];
}dater;
typedef struct
{
char idr[20];
char nombres_habitants[20];
char municipaliter[20];
char nbr_conseillers[20];
dater dr;
}election;

void afficher_Election(GtkWidget *liste);
void ajouter_Election(election e );
void supprimer_election(election e);
election chercher_election( char idr[]);


#endif
