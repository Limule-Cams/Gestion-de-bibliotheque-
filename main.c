#include <stdio.h>
#include <stdlib.h>
#include "code.h"


int main(){
    int i=0;
    Biblio ma_biblio = initBiblio();
    ajoutCat(&ma_biblio, "Programme");
    ajoutCat(&ma_biblio, "Pc");
    ajoutCat(&ma_biblio, "analyse");
    //-----------------------------------------------------------------------
    ajoutLivre(&ma_biblio, "Programme", "Cams12@", "Algebre");
    ajoutLivre(&ma_biblio, "Programme", "seg_fault", "PWN");
    ajoutLivre(&ma_biblio, "Pc", "C0d_OX", "systeme");
    ajoutLivre(&ma_biblio, "Pc", "CODXY", "web");
    //------------------------------------------------------------------------
    afficheLivre(ma_biblio, "Programme");
    afficheLivre(ma_biblio, "Pc");
    afficheLivre(ma_biblio, "analyse");
    //________________________________________________________________________
    i = totalLivres(ma_biblio);
    printf("\nle nbre de livre dans la biblio est: %d ", i);
    supprimCat(&ma_biblio, "Programme");
    supprimCat(&ma_biblio, "Pc");
    supprimCat(&ma_biblio, "analyse");
    return 0;
}