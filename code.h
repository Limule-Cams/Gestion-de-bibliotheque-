#ifndef __CODE_H__
#define __CODE_H__

typedef struct Livre{
    char titre[20];
    char auteur[20];
    struct Livre * next;
}Listliv;

typedef struct Bibio{
    char ctliv[10];
    int nbliv;
    Listliv *info;
    struct Bibio* suiv;
}*Biblio, Bibli;


//fonctions
Biblio initBiblio(void);
Biblio rechCat(Bibli *bl, char *ctlib);
void ajoutCat(Biblio *bl, char *ctliv);
void ajoutLivre(Biblio *bl, char *ctliv, char *auteur,char *titre);
void supprimCat(Biblio *bl ,char *ctLiv);
void afficheLivre(Biblio bl ,char *ctLiv);
int totalLivres(Biblio bl);


#endif