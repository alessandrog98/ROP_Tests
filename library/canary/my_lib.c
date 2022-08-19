/* my_lib.c */

#include "my_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char badchars[] = "\x62\x69\x73\x6e\x2f\x68";

void change_username(){
    char new_usr[120];
    int over;

    memset(new_usr,0,0x78);
    puts("Inserisci il nuovo username:");
    read(0,new_usr,0x200);
    puts("Grazie!\nUsername:");
    printf(new_usr);
}

void change_password(){
    char new_psw[120];
    int over;

    memset(new_psw,0,0x78);
    puts("Inserisci la nuova password:");
    over = read(0,new_psw,0x200);
    check(over, new_psw);
    puts("Grazie!\nPassword: ");
    printf(new_psw);
}

void new_credentials(char *usr, char *psw){
   
    puts("Inserisci l'username:");
    read(0,usr,0x20);
    puts("Grazie!\nUsername: ");
    printf(usr);

    puts("\nInserisci la password:");
    read(0,psw,0x178);
    puts("Grazie!\nPassword: ");
    printf(psw);

}

void new_credentials_canary(){
    char *conf;
    char username[16];
    char password[3];
    
    puts("\nInserisci l'username:");
    read(0,username,0x10);
    printf(username);
    puts("\nInserisci la password:");
    read(0,password,0x10);
    printf(password);
    puts("\nConferma password:");
    read(0,conf,0x100);
}

void check(int dim, char *str){
    int x,y;
    for (x = 0; x < dim; x ++) {
        for (y = 0; y < 6; y ++) {
            if (str[x] == badchars[y]) {
                str[x] -= str[x];
            }
        }
    }
}

void secret_function(char * str1, char* str2[], char* str3[]){
    puts("\nreally secret function !!!");
    execve(str1, str2, str3);
}