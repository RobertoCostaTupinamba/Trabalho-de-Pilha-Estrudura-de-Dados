#include <stdio.h>
#include <stdlib.h>
#define MAX 3
struct FilaEspera
{
    int vaga[MAX];
    int inicio;
    int fim;

};

struct Estacionamento
{
    int topo;
    int dados[MAX];

};

void InserirNaPilha(int PlacaM,struct Estacionamento *p1);

int removerDaPilha(struct Estacionamento*p2);

int inserirFilaDeEspera(int PlacaZ,struct FilaEspera *espera);

void menu();

void inserirNaFila(struct FilaEspera *f1, int PlacaX);

int removerComTrocaFila(struct FilaEspera *f5,int *PlacaK);

int menuChegouCarro(struct Estacionamento *f2,int Placay);

int estacionamentoCheio (struct Estacionamento *pilha);

int menuRemover();

void listaDeCarros(struct Estacionamento *estacionamento,struct FilaEspera *filaespera);

int filacheia (struct FilaEspera *fila);

int main()
{

    char opc;
    int Placa;

    struct FilaEspera filaEspera;
    filaEspera.fim=0;
    filaEspera.inicio=0;

    struct Estacionamento pilhaEstacionamento;
    pilhaEstacionamento.topo=-1;

    struct FilaEspera filaAUX;
    filaAUX.fim=0;
    filaAUX.inicio=0;

    struct Estacionamento movimento;
    movimento.topo=-1;

    struct FilaEspera FilaMovimento;
    FilaMovimento.fim=0;
    FilaMovimento.inicio=0;

    struct Estacionamento pilhaAUX;
    pilhaAUX.topo=-1;

    do
    {

        system("cls");
        menu();
        scanf("%s",&opc);

        if(opc=='C' || opc=='c')
        {

            printf("Digite a placa do carro\n");
            scanf("%d",&Placa);

            int i,ok,flag,j,retornoFuncao;

            for(j=0; j<=1; j++)
            {
                //Testando placa no estacionamento
                do
                {
                    ok=0;
                    for(i=0; i<=pilhaEstacionamento.topo; i++)
                    {
                        if(pilhaEstacionamento.dados[i]==Placa)
                        {
                            do
                            {
                                printf("Esta placa ja esta registrada\nDigite outra placa\n\n");
                                scanf("%d",&Placa);
                                ok=1;
                            }
                            while(pilhaEstacionamento.dados[i]==Placa);
                        }
                    }
                    flag=0;
                }
                while(ok==1);
                //Testando placa na fila de espera
                if(flag==0)
                {

                    do
                    {
                        ok=0;
                        for(i=0; i<=pilhaEstacionamento.topo; i++)
                        {
                            if(pilhaEstacionamento.dados[i]==Placa)
                            {
                                do
                                {
                                    printf("Esta placa ja esta registrada\nDigite outra placa\n\n");
                                    scanf("%d",&Placa);
                                    ok=1;
                                }
                                while(pilhaEstacionamento.dados[i]==Placa);
                            }
                        }
                    }
                    while(ok==1);

                }
            }

            retornoFuncao=menuChegouCarro(&pilhaEstacionamento,Placa);

            if(retornoFuncao==1)
            {
                InserirNaPilha(Placa,&pilhaEstacionamento);
                printf("\n\nChegou um carro!!\n");
                printf("Carro foi estacionado\n\n\n");
                system("pause");
                movimento.topo++;
                movimento.dados[movimento.topo]=0;
            }
            else if(retornoFuncao==2)
            {

            }
            else if(retornoFuncao==3)
            {
                inserirFilaDeEspera(Placa,&filaEspera);
                system("pause");
            }
            else
            {

            }
        }
        else if(opc=='p' || opc=='P')
        {

            int verificar=estacionamentoCheio(&pilhaEstacionamento);
            int pegar=menuRemover();

            if(pegar==1)
            {
                if(verificar!=2)
                {
                    printf("Qual a placa do carro?\n");
                    scanf("%d",&Placa);

                    int con=0;
                    int saiuDaFilaDeEspera;

                    int estacCheio=estacionamentoCheio(&pilhaEstacionamento);
                    int filaEsperaComCarros=filacheia(&filaEspera);

                    if(estacCheio==1 && filaEsperaComCarros!=2)
                    {
                        int ok=0;
                        do
                        {

                            if(pilhaEstacionamento.dados[pilhaEstacionamento.topo]==Placa)
                            {

                                int guarda=removerDaPilha(&movimento);
                                removerDaPilha(&pilhaEstacionamento);
                                printf("O carro com a placa %d foi retirado\n\n",Placa);
                                printf("O carro fez %d movimentos\n\n",guarda);
                                system("pause");
                                ok=1;
                            }
                            else
                            {
                                inserirNaFila(&filaAUX,pilhaEstacionamento.dados[pilhaEstacionamento.topo]);
                                removerDaPilha(&pilhaEstacionamento);
                                inserirNaFila(&FilaMovimento,movimento.dados[movimento.topo]);
                                removerDaPilha(&movimento);
                            }

                        }
                        while(ok!=1);

                        do
                        {
                            int guarda=removerComTrocaFila(&filaAUX,&filaAUX.vaga[0]);
                            InserirNaPilha(guarda,&pilhaEstacionamento);
                            guarda=removerComTrocaFila(&FilaMovimento,&FilaMovimento.vaga[0]);
                            InserirNaPilha(guarda+1,&movimento);
                        }
                        while(filaAUX.fim!=0);

                        //PEGA DA FILA DE ESPERA
                        saiuDaFilaDeEspera=removerComTrocaFila(&filaEspera,&filaEspera.vaga[0]);
                        InserirNaPilha(saiuDaFilaDeEspera,&pilhaEstacionamento);
                        movimento.topo++;
                        movimento.dados[movimento.topo]=0;

                    }
                    else
                    {
                        int ok=0;
                        do
                        {
                            if(pilhaEstacionamento.dados[pilhaEstacionamento.topo]==Placa)
                            {
                                int guarda=removerDaPilha(&movimento);
                                removerDaPilha(&pilhaEstacionamento);
                                printf("O carro com a placa %d foi retirado\n\n",Placa);
                                printf("O carro fez %d movimentos\n\n",guarda);
                                system("pause");
                                ok=1;
                            }
                            else
                            {
                                inserirNaFila(&filaAUX,pilhaEstacionamento.dados[pilhaEstacionamento.topo]);
                                removerDaPilha(&pilhaEstacionamento);
                                inserirNaFila(&FilaMovimento,movimento.dados[movimento.topo]);
                                removerDaPilha(&movimento);
                            }
                        }
                        while(ok!=1);

                        do
                        {
                            int guarda=removerComTrocaFila(&filaAUX,&filaAUX.vaga[0]);
                            InserirNaPilha(guarda,&pilhaEstacionamento);
                            guarda=removerComTrocaFila(&FilaMovimento,&FilaMovimento.vaga[0]);
                            InserirNaPilha(guarda+1,&movimento);
                        }
                        while(filaAUX.fim!=0);
                    }
                }
                else
                {
                    printf("Estacionamento ta vazio\n");
                    system("pause");
                }
            }
            else
            {
                int verificar=filacheia(&filaEspera);
                if(verificar!=2)
                {

                    printf("Qual a placa do carro?\n");
                    scanf("%d",&Placa);
                    int con=0;
                    do
                    {

                        if(filaEspera.vaga[0]==Placa)
                        {
                            removerComTrocaFila(&filaEspera,&filaEspera.vaga[0]);
                            printf("Qual a placa do carro?\n");
                            scanf("%d",&Placa);
                        }
                        else
                        {

                            InserirNaPilha(filaEspera.vaga[0],&pilhaAUX);
                            removerComTrocaFila(&filaEspera,&filaEspera.vaga[0]);
                            int CarroVolto=removerDaPilha(&pilhaAUX);
                            inserirNaFila(&filaEspera,CarroVolto);

                        }
                        con++;
                    }
                    while(con<=filaEspera.fim);
                }
                else
                {
                    printf("\nFila de espera vazia\n");
                    system("pause");
                }
            }

        }
        else if(opc=='l' || opc=='L')
        {
            listaDeCarros(&pilhaEstacionamento,&filaEspera);
        }

    }
    while(opc!='S' && opc!='s');

    return 0;
}

void menu()
{
    printf("C- Chegou um carro\n");
    printf("P- Retirar carro do estacionamento\n");
    printf("L- Lista de carros estacionados\n");
    printf("S- Sair\n");
}

void InserirNaPilha(int PlacaM,struct Estacionamento *p1)
{

    system("cls");
    (*p1).dados[(++(*p1).topo)]=PlacaM;

}

int removerDaPilha(struct Estacionamento *p2)
{


    return((*p2).dados[(*p2).topo--]);
}

int removerComTrocaFila(struct FilaEspera *f5,int *PlacaK)
{

    if((*f5).inicio==(*f5).fim)
    {
        return 0;
    }
    else
    {
        int a=0;
        if(a==0)
        {
            *PlacaK=(*f5).vaga[(*f5).inicio];
            a=*PlacaK;
        }
        for(int i=0; i<MAX-1; i++)
        {
            (*f5).vaga[i]=(*f5).vaga[i+1];
        }
        (*f5).fim--;
        return a;
    }

}

int inserirFilaDeEspera(int PlacaZ,struct FilaEspera *espera)
{

    if((*espera).fim==MAX)
    {
        return 0;
    }
    else
    {
        (*espera).vaga[(*espera).fim]=PlacaZ;
        (*espera).fim++;
        return 1;
    }

}

void inserirNaFila(struct FilaEspera *f1, int PlacaX)
{

    system("cls");

    if((*f1).fim==MAX)
    {
        printf("O estacionamento está cheio\n");
        system("pause");
    }
    else
    {
        (*f1).vaga[(*f1).fim]=PlacaX;
        (*f1).fim++;
    }
}

int menuChegouCarro(struct Estacionamento *p2,int Placay)
{

    system("cls");
    int opc;

    int verificar=estacionamentoCheio(&(*p2));

    if(verificar!=1)
    {
        printf("\nHa vagas no estaciomento!!!\n\n");
        printf("*********************************\n");
        printf("     Deseja estacionar o carro?  \n");
        printf("1-SIM                            \n");
        printf("2-NAO                            \n");
        printf("*********************************\n");
        scanf("%d",&opc);
        if(opc==1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        printf("\nNao ha vagas no estacionamento!!!!\n\n");
        printf("****************************************************\n");
        printf("      Deseja colocar o carro na fila de espera?     \n");
        printf("1-SIM                                               \n");
        printf("2-NAO                                               \n");
        printf("****************************************************\n");
        scanf("%d",&opc);
        if(opc==1)
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
}

int estacionamentoCheio (struct Estacionamento *pilha)
{
    if((*pilha).topo==MAX-1)
    {
        return 1;
    }
    else if((*pilha).topo==-1)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


int menuRemover()
{

    system("cls");
    printf("Deseja remover de qual estacionamento?\n");
    printf("1-Para remover do estacionamento\n");
    printf("2-Para remover da fila de espera\n");
    int opc;
    scanf("%d",&opc);

    if(opc==1)
    {
        return 1;
    }
    else
    {
        return 2;
    }

}

void listaDeCarros(struct Estacionamento *estacionamento,struct FilaEspera *filaespera)
{

    printf("Lista de carros no estacionamento: \n");
    int i;
    for(i=0; i<=(*estacionamento).topo; i++)
    {
        printf("%d ",(*estacionamento).dados[i]);
    }
    printf("\n\n");

    if((*filaespera).fim==0)
    {
        printf("Fila de espera esta vazia\n\n");
        system("pause");
    }
    else
    {
        printf("\nCarros na fila de espera:\n");
        for(i=0; i<(*filaespera).fim; i++)
        {
            printf("%d ",(*filaespera).vaga[i]);
        }
        printf("\n\n");
        system("pause");
    }

}
int filacheia (struct FilaEspera *fila)
{
    if((*fila).fim==MAX)
    {
        return 1;
    }
    else if((*fila).fim==0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
