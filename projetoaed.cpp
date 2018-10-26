#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <dos.h>
#include <string.h>

typedef struct
{
    int id;
    int contErrorChassi;
    int contErrorPaint;
    int contErrorFix;
    int contErrorMotor;
    int contErrorInt;
} carro;

struct no
{
    struct no *ant;
    carro dado;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;

} listalinearde;

void startProcess(listalinearde *q, int d);
void firstProcess(carro *n);
void secondProcess(carro *n);
void thirdProcess(carro *n);
void fourthProcess(carro *n);
void fifthProcess(carro *n);
void createList(listalinearde *q);
int insertList(listalinearde *q, carro d);
int searchList(listalinearde q, int d);
int  removeList(listalinearde *q, int d);
void showList(listalinearde *q);
void showStatusCar(listalinearde *q, int d);
void windowedStatus(listalinearde *q);
void windowedProcessStatus(listalinearde *q);
//Funções Sonoras
void enterProcess();
void sucess();
void error();




//Processo principal
int main()
{
    int cont;
    cont = 1;
    listalinearde estacionamento;
   //Cria a lista, fazendo com que Inicio e Fim aponte para NULL
    createList(&estacionamento);
    setlocale(LC_ALL, "Portuguese");
    initwindow(1160,700,"Indústria Automobilística",10,10);
    readimagefile("fundoinicial.jpg",0,0,1200,700);
    readimagefile("buttonupstartprocess.jpg",1007,0,1157,100);
    readimagefile("buttonupcarreport.jpg",1007,105,1157,205);
    readimagefile("buttonupprocessreport.jpg",1007,210,1157,310);
    readimagefile("buttonupexit.jpg",1007,315,1157,415);
    do
    {
        if((mousex() >= 1007 && mousex() <= 1157 && mousey() >= 0 && mousey() <= 100 && ismouseclick(WM_LBUTTONDOWN)))
        {
            readimagefile("buttondownstartprocess.jpg",1007,0,1157,100);
            readimagefile("buttonupcarreport.jpg",1007,105,1157,205);
            readimagefile("buttonupprocessreport.jpg",1007,210,1157,310);
            clearmouseclick(WM_LBUTTONDOWN);
            startProcess(&estacionamento, cont);
            cont=cont+1;
        }
        if((mousex() >= 1007 && mousex() <= 1157 && mousey() >= 105 && mousey() <= 205 && ismouseclick(WM_LBUTTONDOWN)))
        {
            readimagefile("buttondowncarreport.jpg",1007,105,1157,205);
            readimagefile("buttonupstartprocess.jpg",1007,0,1157,100);
            readimagefile("buttonupprocessreport.jpg",1007,210,1157,310);
            clearmouseclick(WM_LBUTTONDOWN);
            windowedStatus(&estacionamento);
        }
        if((mousex() >= 1007 && mousex() <= 1157 && mousey() >= 210 && mousey() <= 310 && ismouseclick(WM_LBUTTONDOWN)))
        {
            readimagefile("buttondownprocessreport.jpg",1007,210,1157,310);
            readimagefile("buttonupstartprocess.jpg",1007,0,1157,100);
            readimagefile("buttonupcarreport.jpg",1007,105,1157,205);
            clearmouseclick(WM_LBUTTONDOWN);
            windowedProcessStatus(&estacionamento);
       }
    }
    while(!(mousex() >= 1007 && mousex() <= 1157 && mousey() >= 315 && mousey() <= 415 && ismouseclick(WM_LBUTTONDOWN)));
    readimagefile("buttonupstartprocess.jpg",1007,0,1157,100);
    readimagefile("buttonupcarreport.jpg",1007,105,1157,205);
    readimagefile("buttonupprocessreport.jpg",1007,210,1157,310);
    readimagefile("buttonupexit.jpg",1007,315,1157,415);
    readimagefile("buttondownexit.jpg",1007,315,1157,415);
    delay(250);
    readimagefile("buttonupexit.jpg",1007,315,1157,415);
    delay(250);


}
//Função para começar o processo de criação da linha de produção
void startProcess(listalinearde *q, int d)
{

    int sair;
    sair = 0;
    //contador de carros
    carro car;
    car.id = 0;

    //soma para o contador de carros
    int soma;
    soma = 0;

    //Variáveis do outtext
    char errosFirstProcess[1], errosSecondProcess[1], errosThirdProcess[1], errosFourthProcess[1], errosFifthProcess[1];
    //Variável da alternativa
    int alt;
    int status;


    /*Zerando as variaveis contadoras de erro para que possam acumular os valores*/
    car.contErrorChassi = 0;
    car.contErrorPaint = 0;
    car.contErrorFix = 0;
    car.contErrorMotor = 0;
    car.contErrorInt = 0;




    /*Mostra na tela o número de erros de cada processo*/
    //1
    sprintf(errosFirstProcess, "%d", car.contErrorChassi);
    outtextxy(225,593,errosFirstProcess);
    //2
    sprintf(errosSecondProcess, "%d", car.contErrorPaint);
    outtextxy(225,616,errosSecondProcess);
    //3
    sprintf(errosThirdProcess, "%d", car.contErrorFix);
    outtextxy(225,640,errosThirdProcess);
    //4
    sprintf(errosFourthProcess, "%d", car.contErrorMotor);
    outtextxy(225,661,errosFourthProcess);
    //5
    sprintf(errosFifthProcess, "%d", car.contErrorInt);
    outtextxy(225,681,errosFifthProcess);


    delay(500);

    enterProcess();


    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*primeiro processo da linha de produção*/
    firstProcess(&car);

    //
    printf("\nErros no processo de criação do chassi: %2d\n", car.contErrorChassi);
    printf("\nErros no processo de pintura da carroceria: %2d\n", car.contErrorPaint);
    printf("\nErros no processo de fixação da carroceria: %2d\n", car.contErrorFix);
    printf("\nErros no processo de instalação do motor, rodas e transmissão: %2d\n", car.contErrorMotor);
    printf("\nErros no processo de montagem do interior: %2d\n", car.contErrorInt);
    //
    /*Mostra na tela os erros de cada processo*/
    //1
    sprintf(errosFirstProcess, "%d", car.contErrorChassi);
    outtextxy(225,593,errosFirstProcess);
    //2
    sprintf(errosSecondProcess, "%d", car.contErrorPaint);
    outtextxy(225,616,errosSecondProcess);
    //3
    sprintf(errosThirdProcess, "%d", car.contErrorFix);
    outtextxy(225,640,errosThirdProcess);
    //4
    sprintf(errosFourthProcess, "%d", car.contErrorMotor);
    outtextxy(225,661,errosFourthProcess);
    //5
    sprintf(errosFifthProcess, "%d", car.contErrorInt);
    outtextxy(225,681,errosFifthProcess);
    /*--------------------------------------------------------------------------------------------------------------------------------------*/

    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*indo para o segundo processo da linha de produção*/
    secondProcess(&car);
    //
    printf("\nErros no processo de criação do chassi: %2d\n", car.contErrorChassi);
    printf("\nErros no processo de pintura da carroceria: %2d\n", car.contErrorPaint);
    printf("\nErros no processo de fixação da carroceria: %2d\n", car.contErrorFix);
    printf("\nErros no processo de instalação do motor, rodas e transmissão: %2d\n", car.contErrorMotor);
    printf("\nErros no processo de montagem do interior: %2d\n", car.contErrorInt);
    //
    /*Mostra na tela os erros de cada processo*/

    //2
    sprintf(errosFirstProcess, "%d", car.contErrorChassi);
    outtextxy(225,593,errosFirstProcess);
    //2
    sprintf(errosSecondProcess, "%d", car.contErrorPaint);
    outtextxy(225,616,errosSecondProcess);
    //3
    sprintf(errosThirdProcess, "%d", car.contErrorFix);
    outtextxy(225,640,errosThirdProcess);
    //4
    sprintf(errosFourthProcess, "%d", car.contErrorMotor);
    outtextxy(225,661,errosFourthProcess);
    //5
    sprintf(errosFifthProcess, "%d", car.contErrorInt);
    outtextxy(225,681,errosFifthProcess);
    /*--------------------------------------------------------------------------------------------------------------------------------------*/

    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*indo para o terceiro processo da linha de produção*/
    thirdProcess(&car);

    //
    printf("\nErros no processo de criação do chassi: %2d\n", car.contErrorChassi);
    printf("\nErros no processo de pintura da carroceria: %2d\n", car.contErrorPaint);
    printf("\nErros no processo de fixação da carroceria: %2d\n", car.contErrorFix);
    printf("\nErros no processo de instalação do motor, rodas e transmissão: %2d\n", car.contErrorMotor);
    printf("\nErros no processo de montagem do interior: %2d\n", car.contErrorInt);
    //
    /*Mostra na tela os erros de cada processo*/
    //3
    sprintf(errosFirstProcess, "%d", car.contErrorChassi);
    outtextxy(225,593,errosFirstProcess);
    //2
    sprintf(errosSecondProcess, "%d", car.contErrorPaint);
    outtextxy(225,616,errosSecondProcess);
    //3
    sprintf(errosThirdProcess, "%d", car.contErrorFix);
    outtextxy(225,640,errosThirdProcess);
    //4
    sprintf(errosFourthProcess, "%d", car.contErrorMotor);
    outtextxy(225,661,errosFourthProcess);
    //5
    sprintf(errosFifthProcess, "%d", car.contErrorInt);
    outtextxy(225,681,errosFifthProcess);
    /*--------------------------------------------------------------------------------------------------------------------------------------*/

    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*indo para  o quarto processo da linha de produção*/
    fourthProcess(&car);

    //
    printf("\nErros no processo de criação do chassi: %2d\n", car.contErrorChassi);
    printf("\nErros no processo de pintura da carroceria: %2d\n", car.contErrorPaint);
    printf("\nErros no processo de fixação da carroceria: %2d\n", car.contErrorFix);
    printf("\nErros no processo de instalação do motor, rodas e transmissão: %2d\n", car.contErrorMotor);
    printf("\nErros no processo de montagem do interior: %2d\n", car.contErrorInt);
    //
    /*Mostra na tela os erros de cada processo*/

    //4
    sprintf(errosFirstProcess, "%d", car.contErrorChassi);
    outtextxy(225,593,errosFirstProcess);
    //2
    sprintf(errosSecondProcess, "%d", car.contErrorPaint);
    outtextxy(225,616,errosSecondProcess);
    //3
    sprintf(errosThirdProcess, "%d", car.contErrorFix);
    outtextxy(225,640,errosThirdProcess);
    //4
    sprintf(errosFourthProcess, "%d", car.contErrorMotor);
    outtextxy(225,661,errosFourthProcess);
    //5
    sprintf(errosFifthProcess, "%d", car.contErrorInt);
    outtextxy(225,681,errosFifthProcess);
    /*--------------------------------------------------------------------------------------------------------------------------------------*/

    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*indo para o quinto processo da linha de produção*/

    fifthProcess(&car);
    printf("\nO carro foi montado com sucesso!!!\n");
    printf("\n********Relatório de erros*********\n");
    printf("\nErros no processo de criação do chassi: %2d\n", car.contErrorChassi);
    printf("\nErros no processo de pintura da carroceria: %2d\n", car.contErrorPaint);
    printf("\nErros no processo de fixação da carroceria: %2d\n", car.contErrorFix);
    printf("\nErros no processo de instalação do motor, rodas e transmissão: %2d\n", car.contErrorMotor);
    printf("\nErros no processo de montagem do interior: %2d\n", car.contErrorInt);
    /*Mostra na tela os erros de cada processo*/
    //1
    sprintf(errosFirstProcess, "%d", car.contErrorChassi);
    outtextxy(225,593,errosFirstProcess);
    //2
    sprintf(errosSecondProcess, "%d", car.contErrorPaint);
    outtextxy(225,616,errosSecondProcess);
    //3
    sprintf(errosThirdProcess, "%d", car.contErrorFix);
    outtextxy(225,640,errosThirdProcess);
    //4
    sprintf(errosFourthProcess, "%d", car.contErrorMotor);
    outtextxy(225,661,errosFourthProcess);
    //5
    sprintf(errosFifthProcess, "%d", car.contErrorInt);
    outtextxy(225,681,errosFifthProcess);
    delay(1000);

    soma = soma + d;
    car.id = car.id + soma;
    printf("\nO carro produzido possui o id: %d", car.id);
    delay(1000);
    insertList(q, car);
    readimagefile("buttonupstartprocess.jpg",1007,0,1157,100);
    readimagefile("buttonupcarreport.jpg",1007,105,1157,205);
    readimagefile("sucessmapa.jpg",0,0,1000,585);
}


/*Função para o primeiro processo da linha de produção*/
void firstProcess(carro *n)
{
    enterProcess();
    int x1,x2,y1,y2,s;
    x1=900;
    y1=190;
    x2=950;
    y2=240;

    do
    {
        srand(time(NULL));
        s = rand()%5;
        Sleep(500);
        printf("\n%3d\n", s);
        Sleep(150);

        if(s == 0)/*Erro 0*/
        {
            do
            {
                readimagefile("montagemchassi.jpg",x1,y1,x2,y2);
                x1=x1-5;
                x2=x2-5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);
            }
            while(x1>695);

            readimagefile("montagemchassifailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 0\n");
            delay(500);
            x1=900;
            y1=190;
            x2=950;
            y2=240;
            error();
            n->contErrorChassi = n->contErrorChassi + 1;
        }
        if(s == 1)/*Erro 1*/
        {
            do
            {
                readimagefile("montagemchassi.jpg",x1,y1,x2,y2);
                x1=x1-5;
                x2=x2-5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);




            }
            while(x1>695);

            readimagefile("montagemchassifailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 1\n");
            delay(500);
            x1=900;
            y1=190;
            x2=950;
            y2=240;
            error();
            n->contErrorChassi = n->contErrorChassi + 1;
        }
    }
    while(s == 0 || s == 1);

    if(s == 2 || s == 3 || s == 4)/*OK!*/
    {
        do
        {
            readimagefile("montagemchassi.jpg",x1,y1,x2,y2);
            x1=x1-5;
            x2=x2-5;
            delay(50);
            readimagefile("mapa.jpg",0,0,1000,585);




        }
        while(x1>695);

        readimagefile("montagemchassisucess.jpg",x1,y1,x2,y2);
        printf("\nOK\n");
        delay(500);
        x1=900;
        y1=190;
        x2=950;
        y2=240;
    }

    sucess();
    printf("\nO número de erros no processo 1 foram de: %d", n->contErrorChassi);
    delay(500);
}

/*Função para o segundo processo da linha de produção*/
void secondProcess(carro *n)
{
    enterProcess();
    int x1,x2,y1,y2,s;

    x1=635;
    y1=190;
    x2=685;
    y2=240;

    do
    {
        srand(clock());
        s = rand()%5;
        Sleep(500);
        printf("\n%3d\n", s);
        if(s == 0)/*Erro 0*/
        {
            do
            {
                readimagefile("paintcarro.jpg",x1,y1,x2,y2);
                x1=x1-5;
                x2=x2-5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1>385);

            readimagefile("paintcarrofailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 0\n");
            delay(500);
            x1=635;
            y1=190;
            x2=685;
            y2=240;
            error();
            n->contErrorPaint = n->contErrorPaint + 1;
        }
        if(s == 1)/*Erro 1*/
        {
            do
            {
                readimagefile("paintcarro.jpg",x1,y1,x2,y2);
                x1=x1-5;
                x2=x2-5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1>385);

            readimagefile("paintcarrofailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 1\n");
            delay(500);
            x1=635;
            y1=190;
            x2=685;
            y2=240;
            error();
            n->contErrorPaint = n->contErrorPaint + 1;
        }
    }
    while(s == 0 || s == 1);

    if(s == 2 || s == 3 || s == 4)/*OK!*/
    {
        do
        {
            readimagefile("paintcarro.jpg",x1,y1,x2,y2);
            x1=x1-5;
            x2=x2-5;
            delay(50);
            readimagefile("mapa.jpg",0,0,1000,585);

        }
        while(x1>385);

        readimagefile("paintcarrosucess.jpg",x1,y1,x2,y2);
        printf("\nOK\n");
        delay(500);
        x1=635;
        y1=190;
        x2=685;
        y2=240;
    }

    sucess();
    printf("\nO número de erros no processo 2 foram de: %d", n->contErrorPaint);
    delay(500);
}

/*função para o terceiro processo da linha de produção*/
void thirdProcess(carro *n)
{
    enterProcess();
    int x1,x2,y1,y2,s;


    x1=325;
    y1=190;
    x2=375;
    y2=240;

    do
    {
        srand(clock());
        s = rand()%5;
        Sleep(500);
        printf("\n%3d\n", s);

        if(s == 0)/*Erro 0*/
        {
            do
            {
                readimagefile("fixcarroceria.jpg",x1,y1,x2,y2);
                x1=x1-5;
                x2=x2-5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1>160);

            readimagefile("fixcarroceriafailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 0\n");
            delay(500);
            x1=325;
            y1=190;
            x2=375;
            y2=240;
            n->contErrorFix = n->contErrorFix + 1;
            error();
            printf("Erro para retornar ao 2: %d", n->contErrorFix);
            secondProcess(n);
        }
        if(s == 1)/*Erro 1*/
        {
            do
            {
                readimagefile("fixcarroceria.jpg",x1,y1,x2,y2);
                x1=x1-5;
                x2=x2-5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1>160);

            readimagefile("fixcarroceriafailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 1\n");
            delay(500);
            x1=325;
            y1=190;
            x2=375;
            y2=240;
            error();
            n->contErrorFix = n->contErrorFix + 1;
        }
    }
    while(s == 0 || s == 1);

    if(s == 2 || s == 3 || s == 4)/*OK!*/
    {
        do
        {
            readimagefile("fixcarroceria.jpg",x1,y1,x2,y2);
            x1=x1-5;
            x2=x2-5;
            delay(50);
            readimagefile("mapa.jpg",0,0,1000,585);

        }
        while(x1>160);

        readimagefile("fixcarroceriasucess.jpg",x1,y1,x2,y2);
        printf("\nOK\n");
        delay(500);
        x1=325;
        y1=190;
        x2=375;
        y2=240;
    }
    sucess;
    printf("\nO número de erros no processo 3 foram de: %d", n->contErrorFix);
    delay(500);
}

/*função para o quarto processo da linha de produção*/
void fourthProcess(carro *n)
{
    enterProcess();
    int x1,x2,y1,y2,s;


    x1=160;
    y1=325;
    x2=210;
    y2=375;

    do
    {
        srand(clock());
        s = rand()%5;
        Sleep(500);
        printf("\n%3d\n", s);

        if(s == 0)/*Erro 0*/
        {
            do
            {
                readimagefile("instmtr.jpg",x1,y1,x2,y2);
                x1=x1+5;
                x2=x2+5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1<325);

            readimagefile("instmtrfailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 0\n");
            delay(500);
            x1=160;
            y1=325;
            x2=210;
            y2=375;
            error();
            n->contErrorMotor = n->contErrorMotor + 1;
        }
        if(s == 1)/*Erro 1*/
        {
            do
            {
                readimagefile("instmtr.jpg",x1,y1,x2,y2);
                x1=x1+5;
                x2=x2+5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1<325);

            readimagefile("instmtrfailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 1\n");
            delay(500);
            x1=160;
            y1=325;
            x2=210;
            y2=375;
            error();
            n->contErrorMotor = n->contErrorMotor + 1;
        }
    }
    while(s == 0 || s == 1);

    if(s == 2 || s == 3 || s == 4)/*OK!*/
    {
        do
        {
            readimagefile("instmtr.jpg",x1,y1,x2,y2);
            x1=x1+5;
            x2=x2+5;
            delay(50);
            readimagefile("mapa.jpg",0,0,1000,585);

        }
        while(x1<325);

        readimagefile("instmtrsucess.jpg",x1,y1,x2,y2);
        printf("\nOK\n");
        delay(500);
        x1=160;
        y1=325;
        x2=210;
        y2=375;
    }

    sucess();
    printf("\nO número de erros no processo 4 foram de: %d", n->contErrorMotor);
    delay(500);
}

/*função para o quinto processo da linha de produção*/
void fifthProcess(carro *n)
{
    enterProcess();
    int x1,x2,y1,y2,s;


    x1=380;
    y1=325;
    x2=430;
    y2=375;

    do
    {
        srand(clock());
        s = rand()%5;
        Sleep(500);
        printf("\n%3d\n", s);


        if(s == 0)/*Erro 0*/
        {
            do
            {
                readimagefile("interior.jpg",x1,y1,x2,y2);
                x1=x1+5;
                x2=x2+5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1<655);

            readimagefile("interiorfailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 0\n");
            delay(500);
            x1=380;
            y1=325;
            x2=430;
            y2=375;
            error();
            n->contErrorInt = n->contErrorInt + 1;
        }
        if(s == 1)/*Erro 1*/
        {
            do
            {
                readimagefile("interior.jpg",x1,y1,x2,y2);
                x1=x1+5;
                x2=x2+5;
                delay(50);
                readimagefile("mapa.jpg",0,0,1000,585);

            }
            while(x1<655);

            readimagefile("interiorfailed.jpg",x1,y1,x2,y2);
            printf("\nFALHA! ERRO 1\n");
            delay(500);
            x1=380;
            y1=325;
            x2=430;
            y2=375;
            error();
            n->contErrorInt = n->contErrorInt + 1;
        }
    }
    while(s == 0 || s == 1);

    if(s == 2 || s == 3 || s == 4)/*OK!*/
    {
        do
        {
            readimagefile("interior.jpg",x1,y1,x2,y2);
            x1=x1+5;
            x2=x2+5;
            delay(50);
            readimagefile("mapa.jpg",0,0,1000,585);

        }
        while(x1<655);

        readimagefile("interiorsucess.jpg",x1,y1,x2,y2);
        printf("\nOK\n");
        delay(500);
        x1=380;
        y1=325;
        x2=430;
        y2=375;
    }

    sucess();
    printf("\nO número de erros no processo 5 foram de: %d", n->contErrorInt);
    delay(500);
}
void createList(listalinearde *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

int insertList(listalinearde *q, carro d)
{
    struct no *aux;
    aux = (struct no*) malloc(sizeof(struct no));
    if (aux == NULL)
        return 0;

    if (q->inicio == NULL)
    {
        aux->dado = d;
        aux->prox = NULL;
        aux->ant = NULL;
        q->inicio = aux;
        q->fim = aux;
        return 1;
    }

    aux->dado = d;
    aux->prox = NULL;
    q->fim->prox = aux;
    aux->ant = q->fim;
    q->fim = aux;
    return 1;
}

void showList(listalinearde *q)
{
    struct no *aux;

    aux = q->inicio;
    if (aux == NULL)
        printf("\nEstacionamento vazio...\n\n");
    else
    {
        while (aux != NULL)
        {
            printf("%3d,", aux->dado.id);
            aux = aux->prox;
        }
    }
}

void showStatusCar(listalinearde *q, int d)
{
    struct no *aux;
    aux = q->inicio;

    if (aux == NULL)
        readimagefile("void.jpg",0,0,1000,585);

    while (aux!=NULL)
    {
        if (aux->dado.id == d)
        {
            printf("\nO id do carro é:%3d", aux->dado.id);
            printf("\nO número de erros no processo 1-(Montagem do Chassi), foram de:%3d", aux->dado.contErrorChassi);
            printf("\nO número de erros no processo 2-(Pintura da Carroceria), foram de:%3d", aux->dado.contErrorPaint);
            printf("\nO número de erros no processo 3-(Fixação do Chassi), foram de:%3d", aux->dado.contErrorFix);
            printf("\nO número de erros no processo 4-(Instalação de Motor, Rodas e Transmissão), foram de:%3d", aux->dado.contErrorMotor);
            printf("\nO número de erros no processo 5-(Montagem do Interior), foram de:%3d", aux->dado.contErrorInt);
            printf("\nO número totais de erros na montagem do carro %d, foram de:%3d", aux->dado.id, aux->dado.contErrorChassi+aux->dado.contErrorPaint+aux->dado.contErrorFix+aux->dado.contErrorMotor+aux->dado.contErrorInt);

        }
        aux = aux->prox;
    }

    printf("\nUm carro com este id não existe no estacionamento!...\n");
}
void enterProcess()
{
    Beep(750,650);
    Beep(750,650);
}
void sucess()
{
    Beep(900,450);
}
void error()
{
    Beep(900,450);
    Beep(900,450);
}
void windowedStatus(listalinearde *q)
{

    char carId[1], errorChassi[1], errorPaint[1], errorFix[1], errorMotor[1], errorInt[1], errorTotal[1];
    int cont, total, car;
    cont = 0;
    car=0;
    total=0;
    struct no *aux;

    aux = q->inicio;
    if(aux == NULL)
    {
        readimagefile("voidpark.jpg",0,0,1000,585);
    }
    else
    {

        readimagefile("status.jpg",0,0,1000,585);
        readimagefile("buttonupprev.jpg",510,430,599,480);
        readimagefile("buttonupshowcar.jpg",610,430,790,480);
        readimagefile("buttonupnext.jpg",800,430,879,480);

        do
        {
            sprintf(carId, "%d", aux->dado.id);
            outtextxy(460,195,carId);
            sprintf(errorChassi, "%d",aux->dado.contErrorChassi);
            outtextxy(460,242,errorChassi);
            sprintf(errorPaint, "%d",aux->dado.contErrorPaint);
            outtextxy(460,287,errorPaint);
            sprintf(errorFix, "%d",aux->dado.contErrorFix);
            outtextxy(460,330,errorFix);
            sprintf(errorMotor, "%d",aux->dado.contErrorMotor);
            outtextxy(460,373,errorMotor);
            sprintf(errorInt, "%d",aux->dado.contErrorInt);
            outtextxy(460,413,errorInt);
            total = aux->dado.contErrorChassi+aux->dado.contErrorPaint+aux->dado.contErrorFix+aux->dado.contErrorMotor+aux->dado.contErrorInt;
            sprintf(errorTotal, "%d",total);
            outtextxy(460,453,errorTotal);

            //clique que mostra o carro anterior
            if((mousex() >= 510 && mousex() <= 599 && mousey() >= 430 && mousey() <= 480 && ismouseclick(WM_LBUTTONDOWN)))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                aux = aux->ant;
                readimagefile("status.jpg",0,0,1000,585);
                readimagefile("buttondownprev.jpg",510,430,599,480);
                delay(125);
                readimagefile("buttonupprev.jpg",510,430,599,480);
                readimagefile("buttonupshowcar.jpg",610,430,790,480);
                readimagefile("buttonupnext.jpg",800,430,879,480);
            }

            //clique que mosta o carro sucessor
            if((mousex() >= 800 && mousex() <= 879 && mousey() >= 430 && mousey() <= 480 && ismouseclick(WM_LBUTTONDOWN)))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                readimagefile("status.jpg",0,0,1000,585);
                readimagefile("buttondownnext.jpg",800,430,879,480);
                delay(125);
                readimagefile("buttonupprev.jpg",510,430,599,480);
                readimagefile("buttonupshowcar.jpg",610,430,790,480);
                readimagefile("buttonupnext.jpg",800,430,879,480);
            }
            //clique que remove o carro do estacionamento(lista)
            if((mousex() >= 610 && mousex() <= 790 && mousey() >= 430 && mousey() <= 480 && ismouseclick(WM_LBUTTONDOWN)))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                removeList(q, aux->dado.id);
                readimagefile("status.jpg",0,0,1000,585);
                readimagefile("buttondownshowcar.jpg",610,430,790,480);
                delay(125);
                readimagefile("buttonupprev.jpg",510,430,599,480);
                readimagefile("buttonupshowcar.jpg",610,430,790,480);
                readimagefile("buttonupnext.jpg",800,430,879,480);
                readimagefile("removecar.jpg",580,190,820,410);
                delay(500);
                readimagefile("status.jpg",0,0,1000,585);
                readimagefile("buttonupprev.jpg",510,430,599,480);
                readimagefile("buttonupshowcar.jpg",610,430,790,480);
                readimagefile("buttonupnext.jpg",800,430,879,480);
                aux = aux->prox;
            }

        }while(aux!=NULL);
        clearmouseclick(WM_LBUTTONDOWN);
        readimagefile("mapa.jpg",0,0,1000,585);
        readimagefile("buttonupcarreport.jpg",1007,105,1157,205);
    }

}

void windowedProcessStatus(listalinearde *q)
{
    struct no *aux;
    int contChassi = 0, contPaint = 0, contFix = 0, contMotor = 0, contInt = 0;
    char errorChassi[1], errorPaint[1], errorFix[1], errorMotor[1], errorInt[1];


    aux = q->inicio;
    if(aux == NULL)
    {
        //foto dizendo que não há erros nos processos
        readimagefile("voidpark.jpg",0,0,1000,585);
    }
    else
    {

        readimagefile("statusprocess.jpg",0,0,1000,585);

        do
        {
            contChassi = aux->dado.contErrorChassi + contChassi;
            contPaint = aux->dado.contErrorPaint + contPaint;
            contFix = aux->dado.contErrorFix + contFix;
            contMotor = aux->dado.contErrorMotor + contMotor;
            contInt = aux->dado.contErrorInt + contInt;
            aux = aux->prox;
        }
        while(aux!=NULL);

        do
        {
            sprintf(errorChassi, "%d", contChassi);
            outtextxy(835,208,errorChassi);

            sprintf(errorPaint, "%d", contPaint);
            outtextxy(835,245,errorPaint);

            sprintf(errorFix, "%d", contFix);
            outtextxy(835,282,errorFix);

            sprintf(errorMotor, "%d", contMotor);
            outtextxy(835,312,errorMotor);

            sprintf(errorInt, "%d", contInt);
            outtextxy(835,342,errorInt);
        }
        while(!(mousex() >= 850 && mousex() <= 900 && mousey() >= 160 && mousey() <= 210 && ismouseclick(WM_LBUTTONDOWN)));
        clearmouseclick(WM_LBUTTONDOWN);
        readimagefile("mapa.jpg",0,0,1000,585);
        readimagefile("buttonupprocessreport.jpg",1007,210,1157,310);
    }
}
int  removeList(listalinearde *q, int d)
{
    struct no *aux, *anterior, *atual;

    printf("\nTentando remover o dado = %d", d);

    if (q->inicio == NULL)
    {
        printf("\nLista vazia! Não pode remover...\n");
        return 0;
    }

    if (d == q->inicio->dado.id)
    {
        aux = q->inicio;
        // lista tem somente um no
        if (q->inicio == q->fim)
        {
            q->inicio = NULL;
            q->fim = NULL;
        }
        else // lista tem mais que um no
        {
            q->inicio = q->inicio->prox;
            q->fim->prox = NULL;
            q->inicio->ant = NULL;
        }
        free(aux);
        printf(" -- Dado removido...");
        return 1;
    }
    anterior = q->inicio;
    atual = q->inicio->prox;
    do
    {
        anterior = atual;
        atual = atual->prox;
    } while (d != atual->dado.id && atual != q->inicio);

    // Volta completa na lista e dado nao existe
    if (atual == q->inicio)
    {
        printf(" -- Dado não encontrado...");
        return 0;
    }

    // remocao do ultimo no da lista
    if (atual == q->fim)
    {
        aux = q->fim;
        q->fim = anterior;
        q->fim->prox = NULL;
        q->inicio->ant = NULL;
        free(aux);
        printf(" -- Dado removido...");
        return 1;
    }

    // remocao de no do meio da lista
    aux = atual;
    anterior->prox = atual->prox;
    atual->prox->ant = anterior;
    free(aux);
    printf(" -- Dado removido...");
    return 1;
}
