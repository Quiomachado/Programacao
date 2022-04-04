#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 140

void ler_ficheiro(char *[MAX_SIZE], int);
void ordenar_ficheiro(char *[MAX_SIZE], char *[MAX_SIZE]);
void escrever_ficheiro(char* [MAX_SIZE]);

int main()
{
    char *linhas[140]={NULL}, *linhas_ord[140];
    int nLinhas=0;

    ler_ficheiro(linhas, nLinhas);
    ordenar_ficheiro(linhas, linhas_ord);
    escrever_ficheiro(linhas_ord);
}

void ler_ficheiro(char *linhas[MAX_SIZE], int nLinhas)
{
    int i=0;
    char  input[MAX_SIZE];
    FILE * res;
    if((res = fopen("RunResults.txt", "r"))==NULL) //Erro no caso de nao encontrar o ficheiro
    {
        printf("Nao foi possivel abrir o ficheiro \"RunResults.txt\"");
        return;
    }

    while(fgets(input, MAX_SIZE, res) != NULL) //Ler e guardar o ficheiro no ponteiro **linhas
    {
        if(i>0) {
            linhas[nLinhas] = (char *) calloc(MAX_SIZE, sizeof(char));
            strcpy(linhas[nLinhas], input);
            nLinhas++;
        }
        i++;
    }
    fclose(res);
}

void ordenar_ficheiro(char *linhas[MAX_SIZE], char *linhas_ord[MAX_SIZE])
{
    int i, j, k=0, flag;
    char* escaloes[]={"F20", "F40", "F45", "M20", "M35", "M40", "M45", "M50", "M55", "M60"};
    char escalao[3];
    unsigned int size;

    for(i = 0;i < 10; i++)
    {
        for(j = 0;j < MAX_SIZE; j++)
        {
            sscanf(linhas[j], "%*d\t%s\t%*d\t%*d\t%*s\t%*c\t%*s", escalao);

            flag = strcmp(escalao, escaloes[i]);

            if((flag==0) && (strcmp(escalao," ")!=0))
            {
                size = strlen(linhas[j])+1;
                linhas_ord[k] = (char*) calloc(size, sizeof(char));
                strcpy(linhas_ord[k], linhas[j]);
                k++;
            }
        }
    }
    for(i=0; i<MAX_SIZE; i++)
    {
        free(linhas[i]);
    }
}

void escrever_ficheiro(char* linhas_ord[MAX_SIZE])
{
    FILE *res_out;
    res_out = fopen("RunResults_out.txt", "w");

    if(res_out==NULL)
    {
        printf("Erro ao abrir o ficheiro");
        return;
    }
    for(int i = 0; i < MAX_SIZE; i++)
    {
        fprintf(res_out,"%s",linhas_ord[i]);
    }
    for(int i=0; i<MAX_SIZE; i++)
    {
        free(linhas_ord[i]);
    }
    fclose(res_out);
}
















