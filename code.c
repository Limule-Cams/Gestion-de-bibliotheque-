#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"


Biblio initBiblio(void){
    return NULL;
}

Biblio rechCat(Bibli *bl, char *ctlib){
    Bibli *cat = bl;
    while (cat!=NULL) {
        if (strcmp(cat->ctliv, ctlib)==0) {
            return cat;
        }
        cat = cat->suiv;
    }
    return NULL;
}

void ajoutCat(Biblio *bl, char *ctliv){
    Biblio cat = malloc(sizeof(*cat));
    strcpy(cat->ctliv, ctliv);
    cat->nbliv=0;
    cat->suiv=NULL;
    cat->info=NULL;
    if ((*bl)==NULL) {
        (*bl)=cat;
    }else {
        Biblio elm = (*bl);
        while (elm->suiv!=NULL) {
            elm = elm->suiv;
        }
        elm->suiv=cat;
    }
}
void ajoutLivre(Biblio *bl, char *ctliv, char *auteur, char *titre) {
    Biblio cat = rechCat(*bl, ctliv);
    if (cat == NULL) {
        fprintf(stderr, "La catégorie n'existe pas.\n");
        exit(EXIT_FAILURE);
    }

    Listliv *new = malloc(sizeof(Listliv));
    strcpy(new->titre, titre);
    strcpy(new->auteur, auteur);
    new->next = cat->info;
    cat->info = new;
    if(cat->info==NULL)
        cat->info = new;

    cat->nbliv++;
}


void afficheLivre(Biblio bl, char *ctLiv) {
    Biblio cat = rechCat(bl, ctLiv);
    if (cat == NULL) {
        fprintf(stderr, "La catégorie %s n'existe pas.\n", ctLiv);
        return;
    }

    Listliv *livre = cat->info;
    while (livre != NULL) {
        printf("Titre: %s, Auteur: %s\n", livre->titre, livre->auteur);
        livre = livre->next;
    }
}
   
void supprimCat(Biblio *bl, char *ctLiv) {
    Biblio cat = rechCat(*bl, ctLiv);
    Listliv *s = NULL;
    if (cat == NULL) {
        fprintf(stderr, "La catégorie n'existe pas.\n");
        return;
    }else{

        if((*bl)==cat){
        (*bl)=(*bl)->suiv;
            for(s=cat->info;s!=NULL;s=s->next)
                free(s);
            free(cat);
        }else{
            Biblio elm = (*bl);
            while(elm->suiv!=cat)
                elm=elm->suiv;
            elm->suiv=cat->suiv;
            for(s=cat->info;s!=NULL;s=s->next)
                free(s);
            free(cat);
        }   

    }
}

int totalLivres(Biblio bl){
    int i=0;Biblio  elm = NULL; Listliv *c = NULL;
    for(elm=bl;elm!=NULL;elm=elm->suiv){
        for(c=elm->info; c!=NULL;c=c->next)
            i+=1;
    }
    return i;
}