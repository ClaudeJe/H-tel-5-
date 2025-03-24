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
*@brief afficher et recupere les infos des employer
**/
void Formulaire(employer *employ) {
    printf("Entrer le nom de l'employé :\n");
    scanf("%s", employ->Nom);

    printf("Entrer le prénom de l'employé :\n");
    scanf("%s", employ->Prenom);

    printf("Entrer l'âge de l'employé :\n");
    scanf("%d", &(employ->Age));

    printf("Entrer le poste de l'employé :\n");
    scanf("%s", employ->Poste);

    printf("Entrer le salaire de l'employé :\n");
    scanf("%d", &(employ->salaire));
}

/**
*@brief enregistre les infos des employer
**/
int AjouterEmployer(employer employ) {
    FILE *fichier = fopen("baseEmploye.csv", "a+");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier\n");
        return 1;
    }

    fprintf(fichier, "%s; %s; %d; %d; %s\n",
            employ.Nom, employ.Prenom, employ.Age, employ.salaire, employ.Poste);

    fclose(fichier);
    return 0;
}

/**
*@brief affiche les infos des employer
**/
void AfficheBase(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    char ligne[1024];

    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nomFichier);
        return;
    }

    printf("Contenu du fichier :\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }

    fclose(fichier);
}

/**
*@brief modifie les champs des employer
**/
void MiseJourEmployer(const char *nomFichier, const char *ligneRecherche, const char *nouvelleLigne) {
    FILE *fichier = fopen(nomFichier, "r");
    FILE *temporaire = fopen("temp.csv", "w");
    char buffer[1024];
    int modifie = 0;

    if (fichier == NULL || temporaire == NULL) {
        printf("Erreur : Impossible d'ouvrir les fichiers nécessaires.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fichier)) {
        if (strstr(buffer, ligneRecherche)) {
            fprintf(temporaire, "%s\n", nouvelleLigne);
            modifie = 1;
        } else {
            fprintf(temporaire, "%s", buffer);
        }
    }

    fclose(fichier);
    fclose(temporaire);

    if (modifie) {
        remove(nomFichier);
        rename("temp.csv", nomFichier);
        printf("Mise à jour réussie.\n");
    } else {
        remove("temp.csv");
        printf("Aucune correspondance trouvée.\n");
    }
}
/**
*@brief supprime des employer
**/
void SupprimerEtArchiver(const char *nomFichier, const char *nomArchive, const char *ligneASupprimer) {
    FILE *fichier = fopen(nomFichier, "r");
    FILE *temporaire = fopen("temp.csv", "w");
    FILE *archive = fopen(nomArchive, "a+");
    char buffer[1024];
    int trouve = 0;

    if (fichier == NULL || temporaire == NULL || archive == NULL) {
        printf("Erreur : Impossible d'ouvrir les fichiers nécessaires.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fichier)) {
        if (strstr(buffer, ligneASupprimer)) {
            fprintf(archive, "%s", buffer);
            trouve = 1;
        } else {
            fprintf(temporaire, "%s", buffer);
        }
    }

    fclose(fichier);
    fclose(temporaire);
    fclose(archive);

    if (trouve) {
        remove(nomFichier);
        rename("temp.csv", nomFichier);
        printf("Donnée supprimée et archivée avec succès.\n");
    } else {
        remove("temp.csv");
        printf("Aucune donnée trouvée correspondant à '%s'.\n", ligneASupprimer);
    }
}


