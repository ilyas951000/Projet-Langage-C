#ifndef COMMANDS_H
#define COMMANDS_H


// Cette fonction est utilisée pour gérer la commande "!ping".
const char* handle_ping_command();
// Cette fonction est utilisée pour gérer la commande "!help".
const char* handle_help_command();
// Cette fonction est utilisée pour gérer la commande "!pileouface".
const char* handle_pileouface_command();
// et retourne une chaîne de caractères. Elle est utilisée pour gérer la commande "!roll".
const char* handle_roll_command(const char* command);
// et retourne une chaîne de caractères. Elle est utilisée pour gérer la commande "!pfc" avec un choix de 0, 1 ou 2.
const char* handle_pfc_command(int joueur_choix);

#endif // COMMANDS_H
