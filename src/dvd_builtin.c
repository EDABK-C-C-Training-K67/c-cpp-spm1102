#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<dirent.h>
#include"dvd_shell.h"


//Definition of builtin functions
char* builtin_str[] = {"cd", "help", "exit", "ls", "cls","pwd"};
int dvd_cd(char** args){
    if(args[1] == NULL){
        fprintf(stderr, "dvd: expected argument to \"cd\"\n");
    }
    else{
        if(chdir(args[1]) != 0){
            perror("dvd");
        }
    }
    return 1;
}

int dvd_help(char** args){
    int i;
    printf("Do Viet Dung's DVD\n");
    printf("Type a program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");
    
    for(i = 0; i < dvd_num_builtins(); i++){
        printf(" %s\n", builtin_str[i]);
    }
    printf("Use the man command for information on other program.\n");
    return 1;
}

int dvd_exit(char** args){
    return 0;
}

int dvd_ls(char** args){
    DIR* dir;
    struct dirent* entry;

    // Open current directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 0;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 1;
}

int dvd_cls(char** args){
    system("cls");
    return 1;
}

int dvd_pwd(char** args){
    char cwd[1024]; 
    if(getcwd(cwd, sizeof(cwd)) != NULL){
         printf("%s", cwd);
    } else {
        perror("getcwd");
    }
    return 1;
}