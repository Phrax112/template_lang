#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32

static char buffer[2048];

char* readline (char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1]='\0';
    return cpy;
}

void add_history(char* unused) {}

#elif __APPLE__
#include <editline/readline.h>

#else
#include <editline/editline.h>
#include <editline/readline.h>
#endif

int addNums(int x,int y) {
    return x+y;
}

int subNums(int x, int y) {
    return x-y;
}
int multiply(int x, int y) {
    return x*y;
}

int divide(int x, int y) {
    return x/y;
}

int parseInput(char* input) {
   char funcName[]="n";
   int num1,num2,res;
   sscanf(input,"%i %i %s",&num1,&num2,funcName);
   if (strcmp(funcName,"-") == 0) {
       res = subNums(num1, num2);
   } else if (strcmp(funcName,"+") == 0) { 
       res = addNums(num1, num2);
   } else if (strcmp(funcName,"*") == 0) {
       res = multiply(num1, num2);
   } else if (strcmp(funcName,"%") == 0) {
        res = divide(num1, num2);
   }  else {
        res=0;    
   }   
   return res;
}

int main(int argc, char** argv) {
    puts("P v0.1 - gmoynihan");
    puts("Press \\\\ to exit");
    while (1) {
        char* input=readline("p)");
        add_history(input);
        if (strcmp("\\\\",input) == 0) {
            break;
        }
        if (strlen(input) == 0) {
            continue;
        }
        printf("%i\n", parseInput(input));
        free(input);
    }
    return 0;
}
