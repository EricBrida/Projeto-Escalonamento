#include <stdio.h>
#include <stdlib.h>

#define size 10
#define TRUE 1
#define FALSE 0

struct escalo{

    int processo;
    int tempo, tep, turn;
    int prior;

};

struct escalo pr[size];

int tam = 0;
int quantum = 0;
int i = 0, j = 0;
int pos = 0;
int pri[size];

//Inserir Processos
void inserir(){

    int check = 0, regula = 0;
    int pri = 0;
    int verifica = 1;

    if(tam == size){

        printf("FILA CHEIA");

    } else {

        printf("Insira o tempo de processo: ");
        scanf("%d", &pr[tam].tempo);

        rep:

        printf("Insira a prioridade do processo(1 a 10): ");
        scanf("%d", &pri);

        if(pri < 1 || pri > 10){

            system("cls || clear");

            printf("Prioridades Apenas de 1 a 10\n\n");

            goto rep;

        }

        if(tam == 0){

            pr[tam].prior = pri;

        }

        for(int i = 0; i < tam; i++){

            if(pri == pr[i].prior){

                system("cls || clear");

                printf("Prioridade Cadastrada\n\n");

                goto rep;

            }else{

                pr[tam].prior = pri;

            }

        }

        /*
        for(int i = 0; i < tam; i++){
            printf("%d", pr[tam].prior = pri);
        }
        */

        pr[tam].processo = tam + 1;

        tam++;

    }

}

void limpar(){

    if(tam == 0){

        printf("NAO HA NADA QUE LIMPAR\n\n");

    }

    else{

        for(i = 0; i < tam; i++){

            pr[i].processo = 0;
            pr[i].tempo = 0;
            pr[i].tep = 0;
            pr[i].turn = 0;
            pr[i].prior = 0;

        }

        printf("LIMPEZA FEITA COM SUCESSO\nProcessos Limpos: %d\n\n", tam);

        tam = 0;

    }

    getch();

}

//Mostrar valores inseridos
void mostrar(){

        if(tam == 0){

            printf("FILA VAZIA");

        }else{

            printf("\tPROCESSOS INSERIDOS\n");
            printf("--------------------------------------------\n\n");

            for(int i = 0; i < tam; i++){

                printf("Processo %d\n", pr[i].processo);
                printf("Tempo de processo: %d\n", pr[i].tempo);
                printf("Prioridade: %d\n\n", pr[i].prior);
                printf("--------------------------------------------\n\n");

            }

        }

    getch();

}

//Mostrar valores inseridos no escalonamento circular
void cr(){

    int vetorcr[size], temporest[size];
    int lim = 0, maior = 0;
    int cont[size], fix[size], crt[size];
    float tmr = 0, tme = 0, max = 0;

    for(i = 0; i < tam; i++){

        vetorcr[i] = 0;
        temporest[i] = 0;
        cont[i] = 0;
        fix[i] = 0;
        crt[i] = 0;

    }

    printf("Qual o valor do quantum que deseja utilizar: ");
    scanf("%d", &quantum);

    for(i = 0; i < tam; i++){

            if(pr[i].tempo > maior){

            maior = pr[i].tempo;

        }

    }

    max = round(maior / (float) quantum);

    pos = 0;

    system("cls || clear");

    for(i = 0; i < tam; i++){

        for(j = 0; j < pr[i].tempo; j++){

            printf("Executando Processo %d\n", i + 1);

        }

    }

    getch();

    system("cls || clear");

    for(i = 0; i < tam; i++){

        temporest[i] = pr[i].tempo;

    }

    loopc:

    for(i = 0; i < tam; i++){

        if(temporest[i] < quantum && fix[i] == 0){

            crt[i] = quantum - temporest[i];

            temporest[i] = (temporest[i] + crt[i]) - quantum;

            pos = pos + (quantum - crt[i]);

            fix[i]++;

        }

        if(temporest[i] > 0 && cont[i] == 0){

            temporest[i] = temporest[i] - quantum;

            pos = pos + quantum;

        }

        if(temporest[i] == 0 && cont[i] == 0){

                pr[i].turn = pos;

                cont[i]++;

        }

        if(temporest[i] < 0 && cont[i] == 0){

            pr[i].turn = pos;

            cont[i]++;

        }

        printf("\n\nProcesso: %d - Turnaround: %d\n", pr[i].processo, pr[i].turn);
        printf("Impar: %d    -", fix[i]);
        printf("\n");
        getch();

    }

    if(lim != max){

        lim++;

        goto loopc;

    }

    getch();

    system("cls || clear");

    for(i = 0; i < tam; i++){

        pr[i].tep = pr[i].turn - pr[i].tempo;

        printf("Processo: %d - Turnaround: %d\n", pr[i].processo, pr[i].turn);
        printf("Processo: %d - Tempo de Espera(TEP): %d\n", pr[i].processo, pr[i].tep);

        tmr = tmr + (float)pr[i].turn;

        tme = tme + (float)pr[i].tep;
    }

    tmr = tmr / (float)tam;

    tme = tme/ (float)tam;

    printf("\nTempo Medio de Retorno (TMR): %.2f\n", tmr);

    printf("Tempo Medio de Espera (TME): %.2f\n", tme);
    printf("Tempo de Processamento de Cada Processo: ");

    for(i = 0; i < tam; i++){

        printf(" %d -", pr[i].tempo);

    }

    printf("\nTempo Total de Processamento: %d\n\n", pos);

        /*

        printf("\n\n");
        printf("Max: %f\n", max);
        printf("Pos: %d\n", pos);
        printf("Quantum: %d\n", quantum);
        printf("Lim: %d", lim);

        */

    getch();

}

//Mostrar valores inseridos no escalonamento circular por prioridade
void cr_pr(){

    int priorm[size], temporest[size];
    int lim = 0, maior = 0, bigger = 0;
    int cont[size], fix[size], crt[size];
    float tmr = 0, tme = 0, max = 0;

    int proname[size], time[size];

    for(i = 0; i < tam; i++){

        temporest[i] = 0;
        cont[i] = 0;
        fix[i] = 0;
        crt[i] = 0;
        proname[i]= 0;
        time[i] = 0;
        priorm[i] = 0;

        priorm[i] = pr[i].prior;
        proname[i] = pr[i].processo;
        time[i] = pr[i].tempo;

    }

      for(i = 0; i < tam; i++) {

          for(j = i + 1; j < tam; j++) {

             if(pr[i].prior < pr[j].prior) {

                bigger = priorm[i];
                priorm[i] = priorm[j];
                priorm[j] = bigger;

                bigger = proname[i];
                proname[i] = proname[j];
                proname[j] = bigger;

                bigger = time[i];
                time[i] = time[j];
                time[j] = bigger;

             }

          }

    }

    for(i = 0; i < tam; i++){

        printf("\nProcesso: %d\n", proname[i]);
        printf("\nTempo de execucao: %d\n", time[i]);
        printf("\nPrioridade: %d\n", priorm[i]);

        printf("-------------------------------------------------\n");

    }

    getch();

    printf("Qual o valor do quantum que deseja utilizar: ");
    scanf("%d", &quantum);

    for(i = 0; i < tam; i++){

            if(time[i] > maior){

            maior = time[i];

        }

    }

    max = round(maior / (float) quantum);

    pos = 0;

    system("cls || clear");

    for(i = 0; i < tam; i++){

        for(j = 0; j < time[i]; j++){

            printf("Executando Processo %d\n", proname[i]);

        }

    }

    getch();

    system("cls || clear");

    for(i = 0; i < tam; i++){

        temporest[i] = time[i];

    }

    loopc:

    for(i = 0; i < tam; i++){

        if(temporest[i] < quantum && fix[i] == 0){

            crt[i] = quantum - temporest[i];

            temporest[i] = (temporest[i] + crt[i]) - quantum;

            pos = pos + (quantum - crt[i]);

            fix[i]++;

        }

        if(temporest[i] > 0 && cont[i] == 0){

            temporest[i] = temporest[i] - quantum;

            pos = pos + quantum;

        }

        if(temporest[i] == 0 && cont[i] == 0){

            pr[i].turn = pos;

            cont[i]++;
            fix[i]++;

        }

        if(temporest[i] < 0 && cont[i] == 0){

            pr[i].turn = pos;

            cont[i]++;
            fix[i]++;

        }

        printf("\n\nProcesso: %d - Turnaround: %d\n", proname[i], pr[i].turn);
        printf("Impar: %d    -", fix[i]);
        printf("\n");
        getch();

    }

    if(lim != max){

        lim++;

        goto loopc;

    }

    getch();

    system("cls || clear");

    for(i = 0; i < tam; i++){

        pr[i].tep = pr[i].turn - time[i];

        printf("Processo: %d - Turnaround: %d\n", proname[i], pr[i].turn);
        printf("Processo: %d - Tempo de Espera(TEP): %d\n", proname[i], pr[i].tep);

        tmr = tmr + (float)pr[i].turn;

        tme = tme + (float)pr[i].tep;
    }

    tmr = tmr / (float)tam;

    tme = tme/ (float)tam;

    printf("\nTempo Medio de Retorno (TMR): %.2f\n", tmr);

    printf("Tempo Medio de Espera (TME): %.2f\n", tme);
    printf("Tempo de Processamento de Cada Processo: ");

    for(i = 0; i < tam; i++){

        printf(" %d -", time[i]);

    }

    printf("\nTempo Total de Processamento: %d\n\n", pos);

        /*

        printf("\n\n");
        printf("Max: %f\n", max);
        printf("Pos: %d\n", pos);
        printf("Quantum: %d\n", quantum);
        printf("Lim: %d", lim);

        */

    getch();

}

int main(){

    int menu = 0;

        do{

            menuz:

            system("cls || clear");

            printf("\t MENU ESCALONAMENTO \n\n");
            printf("1- Inserir\n");
            printf("2- Limpar Processos\n");
            printf("3- Mostrar\n");
            printf("4- Circular\n");
            printf("5- Circular por prioridade\n");
            printf("6- Sair\n\n");
            scanf("%d", &menu);

            switch(menu){

            case 1:

                system("cls || clear");

                inserir();

            break;

            case 2:

                system("cls || clear");

                limpar();

            break;

            case 3:

                system("cls || clear");

                mostrar();

            break;


            case 4:

                system("cls || clear");

                cr();

            break;


            case 5:

                system("cls || clear");

                cr_pr();

            break;


            case 6:

                system("cls || clear");

            break;


            default:

                system("cls || clear");

                printf("Opcao Invalida...\n\n");
                sleep(2);

                system("cls || clear");

                printf("Retornando ao menu...\n\n");
                sleep(2);

                goto menuz;

            break;

            }

        }while(menu != 6);

}
