//Prototype of builtin functions
int dvd_cd(char** args);
int dvd_help(char** args);
int dvd_exit(char** args);
int dvd_ls(char** args);
int dvd_cls(char** args);

//prototype of function carrying out basic functions of shell

//read command
char* dvd_read_line(void);

//parsing into arguments
char** dvd_split_line(char* line);

//create a process
int dvd_launch(char** args);

//execute the command
int dvd_execute(char** args);

//working loop
void dvd_loop(void);