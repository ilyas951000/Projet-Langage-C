#include <stdio.h>       
#include <stdlib.h>    
#include <string.h>          
#include <time.h>            
#include "commands.h"        

const char* handle_ping_command() {
    return "Pong!";  // Retourne  chaîne de caractères pour répondre à la commande !ping.
}

const char* handle_help_command() {
    return "Les commandes disponibles sont :\n"
           "!ping : Vérifie si le bot répond.\n"
           "!help : Affiche cette liste d'aide.\n"
           "!pileouface : Joue à pile ou face.\n"
           "!roll X Y : Génère un nombre aléatoire entre X et Y.\n"
           "!pfc <0|1|2> : Joue à Pierre-Feuille-Ciseaux contre le bot.\n";
    // Retourne une liste des commandes disponibles lorsque la commande !help est appelée.
}

const char* handle_pileouface_command() {
    // Génére un résultat aléatoire pour "Pile ou Face".
    return (rand() % 2 == 0) ? "Résultat : Pile !" : "Résultat : Face !";
}

const char* handle_roll_command(const char* command) {
    static char response[256];  // Tableau statique pour stocker la réponse qui sera renvoyée.
    int x, y;

    // Lit les valeurs X et Y de la commande, qui sont les bornes pour la génération du nombre aléatoire.
    if (sscanf(command, "!roll %d %d", &x, &y) != 2) {
        return "Usage : !roll X Y (où X et Y sont des entiers, X < Y)";  
    }

    // Vérifie si X est inférieur à Y, sinon, la commande est incorrecte.
    if (x >= y) {
        return "Erreur : X doit être inférieur à Y.";
    }

    // Génère un nombre aléatoire entre X et Y inclus.
    int resultat = (rand() % (y - x + 1)) + x;
    snprintf(response, sizeof(response), "Vous avez roulé : %d", resultat);  // Crée la réponse à afficher.
    return response; 
}

const char* handle_pfc_command(int joueur_choix) {
    static char response[256];  // Tableau statique pour stocker la réponse qui sera renvoyée.
    const char* choix[] = {"Pierre", "Feuille", "Ciseaux"};  // Tableau contenant les choix possibles.
    int bot_choix = rand() % 3;  // Choix aléatoire du bot (0 = Pierre, 1 = Feuille, 2 = Ciseaux).

    // Vérifie si le choix du joueur est valide (0, 1 ou 2).
    if (joueur_choix < 0 || joueur_choix > 2) {
        return "Choix invalide. Réessayez avec 0 (Pierre), 1 (Feuille), ou 2 (Ciseaux).";
    }

    // Crée une réponse qui montre les choix du joueur et du bot.
    snprintf(response, sizeof(response),
             "Vous avez choisi : %s\nLe bot a choisi : %s\n",
             choix[joueur_choix], choix[bot_choix]);

    // Détermine le résultat de la partie (match nul, victoire ou défaite).
    if (joueur_choix == bot_choix) {
        strcat(response, "C'est un match nul !");
    } else if ((joueur_choix == 0 && bot_choix == 2) ||
               (joueur_choix == 1 && bot_choix == 0) ||
               (joueur_choix == 2 && bot_choix == 1)) {
        strcat(response, "Vous gagnez !");
    } else {
        strcat(response, "Vous perdez !");
    }

    return response; 
}
