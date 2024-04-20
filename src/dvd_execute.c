#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<dirent.h>
#include<windows.h>
#include"dvd_shell.h"

int (*builtin_func[])(char**) = {
    &dvd_cd,
    &dvd_help,
    &dvd_exit,
    &dvd_ls,
    &dvd_cls
};

static char* builtin_str[] = {"cd", "help", "exit", "ls", "cls"};

int dvd_num_builtins(){
    return sizeof(builtin_str) / sizeof(char*);
}

int dvd_launch(char** args) {
    PROCESS_INFORMATION processInfo;
    STARTUPINFO startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);


    if (!CreateProcess(NULL, args[1], NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo)) {
        fprintf(stderr, "Failed to create process. Error code: %lu\n", GetLastError());
        return 1;
    }
    WaitForSingleObject(processInfo.hProcess, INFINITE);

    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);

    return 1;
}


int dvd_execute(char** args){
    int i;

    if(args == NULL || args[0] == NULL){
        return 1;
    }
    for(i = 0; i < dvd_num_builtins(); i++){
        if(strcmp(args[0], builtin_str[i]) == 0){
            return (*builtin_func[i])(args);
        }
    }
    return dvd_launch(args);
}


//Parsing line into token
#define DVD_TOK_BUFSIZE 64
#define DVD_TOK_DELIM "\t\r\n\a"
char** dvd_split_line(char* line){
    int bufsize = DVD_TOK_BUFSIZE, position = 0;
    char** tokens = malloc(bufsize * sizeof(char*));
    char* token;

    if(!tokens){
        fprintf(stderr, "dvd: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DVD_TOK_DELIM);
    while(token != NULL){
        tokens[position] = strdup(token);
        position++;

        if(position >= bufsize){
            bufsize += DVD_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if(!tokens){
                fprintf(stderr, "dvd: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DVD_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

//read command line
#define DVD_RL_BUFSIZE 1024
char* dvd_read_line(void){
    int bufsize = DVD_RL_BUFSIZE;
    int position = 0;
    char* buffer = malloc(sizeof(char) * bufsize);
    int c;

    if(!buffer){
        fprintf(stderr, "dvd: allocation error\n");
        exit(EXIT_FAILURE);
    }
    while(1){
        c = getchar();
        if(c == EOF || c =='\n'){
            buffer[position] = '\0';
            return buffer;
        }
        else{
            buffer[position] = c;
        }
        position++;
        
        if(position >= bufsize - 1){
            bufsize += DVD_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer){
                fprintf(stderr,"dvd: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void dvd_loop(void){
    char* line;
    char** args;
    int status;

    do{
        printf("> ");
        line = dvd_read_line();
        args = dvd_split_line(line);
        status = dvd_execute(args);

        free(line);
        free(args);
    }
    while(status);
}
