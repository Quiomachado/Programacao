#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 141

int main(int argc, char *argv[])
{
    char *linhas[MAX_SIZE]={NULL}, buffer[MAX_SIZE], *nome=NULL, *apelido=NULL;
    int flag=0, nLinhas=0;
    printf("Num. de argumentos = %d\n\n", argc);
    FILE * res;
    if((res = fopen("RunResults_out.txt", "r"))==NULL) //Erro no caso de nao encontrar o ficheiro
    {
        printf("Nao foi possivel abrir o ficheiro \"RunResults.txt\"");
        return 1;
    }
    while(fgets(buffer, MAX_SIZE-1, res)!=NULL)
    {
        linhas[nLinhas] = (char *) calloc(MAX_SIZE, sizeof(char));
        strcpy(linhas[nLinhas], buffer);
        nLinhas++;
    }
    for(int i=0; i < nLinhas;i++)
    {
        nome = strstr(linhas[i], argv[1]);
        apelido = strstr(linhas[i], argv[2]);
        if(nome!=NULL && apelido!=NULL)
        {
            flag = i;
            break;
        }
    }
    printf("Posicao Geral: %s\n", strtok(linhas[flag], "\t"));
    strtok(NULL, "\t");
    printf("Posicao no seu escalao: %s\n", strtok(NULL, "\t"));
    for(int i=0; i<nLinhas;i++)
    {
        free(linhas[i]);
    }
    fclose(res);
    return 0;
}
