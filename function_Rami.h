#ifndef FUNCTION_RAMI_H_INCLUDED
#define FUNCTION_RAMI_H_INCLUDED
typedef struct
{
int mois;
int jour ;
int annee ;
}date ;
typedef struct
{
int id;
date date_debut_fin ;
char municipalite[25];
int nombres_conseilleurs ;
}election ;

int ajouter_election(election E , char elections [50]);
#endif // FUNCTION_RAMI_H_INCLUDED

