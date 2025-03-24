#include<stdio.h>
#include"Gestiopers.h"
#include"GestioClient.h"
#include"Fichier.h"
#include <unistd.h>
#include<windows.h>
const char *EMPLOYER = "baseEmploye.csv";
const char *CLIENT = "baseClient.csv";
const char *ARCHIVE = "nomArchive.csv";

int main(){
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
    employer employ;
    client clt;
    int a,b,c,d;
    printf("---------------------------------------\n");
    printf("BIENVENUE DANS NOTRE PRESTIGIEUSE HOTEL\n");
    printf("----------------------------------------\n");
//Auth() on appelle la fonction authentification
    Menu1:
    printf("Vous etes un :\n");
    printf("1.Client\n");
    printf("2.Membre du personnel\n");
    printf("3.Administrateur\n");
    scanf("%d",&a);
    system("cls");
    service:
    switch(a){
        case 1:
        printf("quelle service voulez-vous?\n");
        printf("1.reservation\n");
        printf("2.commande\n");
        printf("3.quitter\n");
        scanf("%d",&b);
        system("cls");
//on appelle la fonction reservation et commande en fonction de la valeur de b
        if(b=1);
           // reservation();
        if(b=2);
            //commande();
        if(b=3){
            exit(0);
        }else{
            goto service;
        }
        break;
        case 2:
//on appelle la fonction profil_personnel
        break;
        case 3:
        Admin:
        printf("Que voulez-vous faire?\n");
        printf("1.Ajouter un membre du personnel\n");
        printf("2.Modifier le profile d'un membre du personnel\n");
        printf("3.Supprimer un membre du personnel\n");
        printf("4.Consulter mes employes\n");
        printf("5.Consulter les archives du personnel\n");
        printf("6.quitter\n");
        scanf("%d",&c);
        system("cls");
        switch (c)
        {
        case 1:
            Formulaire(&employ);
            AfficheBase("EMPLOYER");
            AjouterEmployer(employ);
            break;
        case 2:
            //MiseJourEmployer(EMPLOYER);
            break;
        case 3:
            printf("entrez l'identifiant numerique de l'employer a modifier");
            scanf("%d",&d);
            //supprimeEtArchive(EMPLOYER,ARCHIVE,d);
            break;
        case 4:
           //AfficheBase(EMPLOYER);
             break;
        case 5:
            //AfficheBase(ARCHIVE);
            break;
        case 6:
            exit(0);
        default:
            goto Admin;
            break;
        }
    break;
    default:
    printf("choix indisponible, veuillez reesayer");
    goto Menu1;
    break;
    }   
return 0;
    
}