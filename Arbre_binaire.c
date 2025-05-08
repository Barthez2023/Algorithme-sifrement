/*ici on va implelmenter les abres binaires basee sur une logique differentes les elements seront ajouter de facon trier dans l'arbre
le premier elmement sera ajouter ensuite avant d'ajouter le second element on vas faire le controle si l'element a inserrer est plus 
garnd que la racinne alors on l'ajoute a droite si non on l'ajoute a gauche et ainsi de suite */
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct arbre
{
    int value;
    struct arbre *left;
    struct arbre *right;
}arbre;
//creation d'un arbre vide
arbre *new_tree(int x){
    arbre *tr=malloc(sizeof(*tr));
    if(tr==NULL){
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    tr->value=x;
    tr->left=NULL;
    tr->right=NULL;
    return tr;
}
void insertion(arbre **racine,int value){
    arbre *tr,*cmp;
    tr=new_tree(value);
    if (*racine==NULL)
    {
       *racine=tr;
       return ;
    }
    cmp=*racine;
    while (1)
    {
        if (tr->value<cmp->value)
        {
            if (cmp->left==NULL)
            {
                cmp->left=tr;
                break;
            }
            else
            {
                cmp=cmp->left;
            }
        }
        else
        {
            if (cmp->right==NULL)
            {
                cmp->right=tr;
                break;
            }
            else
            {
                cmp=cmp->right;
            }
        }
    }
}

void Inorder_tarama(arbre *racine){           
    if (racine==NULL)
    {
        return;
    }
    Inorder_tarama(racine->left);
    printf("%d ",racine->value);
    Inorder_tarama(racine->right);
}


void postorder_tarama(arbre *racine){           
    if (racine==NULL)
    {
        return;
    }
    postorder_tarama(racine->left);
    postorder_tarama(racine->right);
    printf("%d ",racine->value);

}

void Preorder_tarama_recu(arbre *racine){           
    if (racine==NULL)
    {
        return;
    }
    printf("%d ",racine->value);
    Preorder_tarama_recu(racine->left);
    Preorder_tarama_recu(racine->right);
}

int sum_element(arbre *racine){
    arbre *ptr=racine;
    if (ptr==NULL)
    {
        return 0;
    }
    return ptr->value+sum_element(ptr->left)+sum_element(ptr->right);
}
int min_arbre(arbre *racine){
    while (racine->left!=NULL)
    {
        racine=racine->left;
    }
    return racine->value;
}
int min_arbre_rec(arbre *racine){
    if (racine==NULL)
    {
       exit(1);
    }
    if (racine->left==NULL)
    {
        return racine->value;
    }
    min_arbre_rec(racine->left);
}
int max_arbre(arbre *racine){
    while (racine->right!=NULL)
    {
        racine=racine->right;
    }
    return racine->value;
}
int max_arbre_rec(arbre *racine){
    if (racine==NULL)
    {
       exit(1);
    }
    if (racine->right==NULL)
    {
        return racine->value;
    }
    max_arbre_rec(racine->right);
}

int main(){
    arbre *Arbre=NULL;
    insertion(&Arbre,23);
    insertion(&Arbre,18);
    insertion(&Arbre,44);
    insertion(&Arbre,12);
    insertion(&Arbre,20);
    insertion(&Arbre,35);
    insertion(&Arbre,52);
    Inorder_tarama(Arbre);
    printf("\n");
    postorder_tarama(Arbre);
    printf("\n");
    Preorder_tarama_recu(Arbre);
    printf("\n");
    printf("La somme des elemnts present dans le garphe est: %d\n",sum_element(Arbre));
    printf("La value minimal du  garphe est: %d\n",min_arbre(Arbre));
    printf("La value minimal du  garphe par reccursion  est: %d\n",min_arbre_rec(Arbre));
    printf("La valeur maximal du garphe est: %d\n",max_arbre(Arbre));
    printf("La value maximal du  garphe par reccursion  est: %d\n",max_arbre_rec(Arbre));
   


}


