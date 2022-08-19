#include <stdio.h>
#include <string.h>

int main(){
    int scelta;
    char username[172],password[172];

    memset(password,0,0xac);
    memset(username,0,0xac);
    puts("\nCiao!\n");
    puts("> inserisci 0 o 1 per creare delle nuove credenziali\n");
    puts("> inserisci 2 per aggiornare l'username\n");
    puts("> inserisci 3 per aggiornare la password");

    scanf("%d",&scelta);

    if (scelta == 0) new_credentials(&username,&password); 
    else if (scelta == 1) new_credentials_canary();
    else if (scelta == 2) change_username();
    else if (scelta == 3) change_password();
}
