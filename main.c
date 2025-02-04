#include <stdio.h>           
#include <stdlib.h>         
#include <string.h>          
#include <time.h>            
#include <locale.h>          
#include "commands.h"       

int main() {
    setlocale(LC_ALL, "");  // Gère l'affichage des caractères spéciaux en fonction de la locale du système
    setbuf(stdout, NULL);   // Désactive le buffering de sortie pour que les données soient immédiatement affichées sans attendre.

    char command[256];      // Déclaration d'un tableau pour stocker la commande entrée par l'utilisateur.
    srand(time(NULL));      // Initialisation du générateur de nombres aléatoires avec le temps actuel pour garantir une variation à chaque exécution.

    while (fgets(command, sizeof(command), stdin)) {  // Boucle qui lit la commande entrée par l'utilisateur.
        command[strcspn(command, "\r\n")] = 0;         

        if (strcmp(command, "exit") == 0) {  
            printf("Bot arrêté.\n\n");       // Affiche un message pour informer l'utilisateur de l'arrêt du bot.
            break;                           
        }

        if (strcmp(command, "!ping") == 0) {  // Si la commande est "!ping", on appelle la fonction handle_ping_command.
            printf("%s\n\n", handle_ping_command());  
        } else if (strcmp(command, "!help") == 0) {  // Si la commande est "!help", on appelle handle_help_command.
            printf("%s\n\n", handle_help_command());
        } else if (strcmp(command, "!pileouface") == 0) {  // Si la commande est "!pileouface", on appelle handle_pileouface_command.
            printf("%s\n\n", handle_pileouface_command());
        } else if (strncmp(command, "!roll", 5) == 0) {  // Si la commande commence par "!roll", on appelle handle_roll_command avec l'argument complet.
            printf("%s\n\n", handle_roll_command(command));
        } else if (strncmp(command, "!pfc", 4) == 0) {  // Si la commande commence par "!pfc", on essaie d'extraire un entier après cette commande.
            int choix;
            if (sscanf(command, "!pfc %d", &choix) == 1) {  // Si on a réussi à extraire un entier (0, 1 ou 2), on appelle handle_pfc_command.
                printf("%s\n\n", handle_pfc_command(choix));
            } else {  // Si l'extraction a échoué, on affiche un message d'erreur sur l'utilisation correcte de la commande.
                printf("Usage : !pfc 0|1|2\n\n");
            }
        } else {  
            printf("Commande inconnue : %s\n\n", command);  
        }
    }
    return 0;  
}
