#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char Nom[100];
    char Prenom[100];
    int Age;
    int salaire;
    int Id;
    char Poste[100];
}employer;
typedef struct {
    char Nom[100];
    char Prenom[100];
    int Age;
    char profession[100];
    int Id;
    char espace[100];
}client;
/**
*@brief creation d'un type client et afficher et recupere les infos des client
**/
void FormulaireClient(client clt){
    printf("entrer votre nom\n");
    scanf("%s",clt.Nom);
    printf("entrer votre Prenom \n");
    scanf("%s",clt.Prenom);
    printf("entrer votre Age\n");
    scanf("%d",clt.Age);
    printf("entrer votre profession\n");
    scanf("%s",clt.profession);
    printf("entrer l'espace que vous voulez louer ou reserver\n");
    scanf("%s",clt.espace);

};
/**
*@brief enregistre les infos des clients dans un fichier autre que celui des employer
**/
void AjouterClient(client clt){
    // Ouvrir le fichier en mode ajout
    FILE *fichier = fopen("baseclient.csv", "a+");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Écrire les données dans le fichier
    fprintf(fichier, "%d; %s; %s; %d; %s; %s \n", clt.Id, clt.Nom, clt.Prenom, clt.Age, clt.profession, clt.espace);

    // Fermer le fichier
    fclose(fichier);


};
/**
*@brief reserver des clients
**/
void reservation(){

};
/**
*@brief commande des clients
**/
void commande(){

};
/**
*@brief affiche les infos des clients dans son profile
**/
void AfficheClient(){

};

