#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


typedef struct {
    char nome[50];
    int num_assento;
    char data[20];
    char hora[20];
    int situacao;
} participante;

int main() {

    system("color F0");

    //INFORMACOES DO LOCAL
    char data[] = "indefinido",
         hora[] = "indefinido",
         local[90]="indefinido";

    //LUGARES
    int fileira = 40, coluna = 40;     //  var pra tamanho do lugar
    int lugar[fileira][coluna];        //  para verificacao se esta disponivel ou nao
    int i = 0,j = 0, vf = 0;           // vf verifica se a data, hora e local foram definidos
    int *p_vf;    //VF PONTEIRO

    p_vf = &vf;  //VF

    for(i=0; i<2; i++) {
        logo();
        printf("\n\n                             \\ Carregando. \n\n");
        printf("\n\t\t(COLOQUE A QUANTIDADE DE LUGARES PRIMEIRO)     ");
        Sleep(250);
        system("cls");
        logo();
        printf("\n\n                             | Carregando.. \n\n ");
        printf("\n\t\t(COLOQUE A QUANTIDADE DE LUGARES PRIMEIRO)    ");
        Sleep(250);
        system("cls");
        logo();
        printf("\n\n                             / Carregando...  \n\n");
        printf("\n\t\t(COLOQUE A QUANTIDADE DE LUGARES PRIMEIRO)    ");
        Sleep(250);
        system("cls");
        
        
    }


    //PEGAR NUMERO DE FILEIRAS E COLUNA
    printf("\n  ///////////// DEFINIR NUMERO DE FILEIRAS E COLUNAS \\\\\\\\\\\\\\\\\\\\\\\\\\\\ ");
    printf("\n\n    NUMERO DE FILEIRAS: ");
    scanf("%i", &fileira);
    printf("    NUMERO DE COLUNAS: ");
    scanf("%i", &coluna);

    fflush(stdin);

    for(i=0; i<fileira; i++) {
        for(j=0; j<coluna; j++) {
            lugar[i][j] = 0;
        }
    }
    system("cls");

    //LIMPAR TODAS AS POSICOES
    for(i=0; i<fileira; i++) {
        for(j=0; j<coluna; j++) {
            lugar[i][j] = 0;
        }
    }

    // VALORES DAS CADEIRAS

    int tot_cont = 1;
    int num_das_cadeiras[fileira][coluna];

    for(i=0; i<fileira; i++) {
        for(j=0; j<coluna; j++) {
            num_das_cadeiras[i][j] = tot_cont++;
        }
    }

    int total_de_lugares_disponivel;                //
    total_de_lugares_disponivel = fileira * coluna; // NUMEROS DE LUGARES DISPONIVEIS
    printf("%i", total_de_lugares_disponivel);      //



    participante participante[total_de_lugares_disponivel]; // VARIAVEL DE PARTICIPANTE
    int enum_dos_participante= 0;

    int f, c; // variaveis pra escolha do lugar
    int aux_qnt; // variavel pro vetor de participante

    int sair;
    int qnt_compra = 1;

    int op = 0;
    int total_para_mostrar= 0;


    //qnt de lugares reservados para DEFICIENTES
    int qnt_reservado_para_deficientes = (total_de_lugares_disponivel*5)/100;
    int lugares_JA_reservados = 0;


      //qnt de lugares reservados para CONVIDADOS
    int qnt_reservado_para_convidados = 2 * coluna;
    int lugares_JA_reservados_convidados = 0;

    //printf("lugares para convidados: %i", qnt_reservado_para_convidados);

    while(1) {

        printf("\n  ///////////// CONTROLE DE ENTRADA \\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
        // MENU
        do {
        	printf("\t\t == RESERVAR == \n");
            printf("\n  \t [1] PARTICIPANTE  [2] DEFICIENTE  ");
            printf("\n  \t     [3] CONVIDADO/PROFESSOR \n");
            
            printf("\n\n\t\t == DADOS == \n");
            printf("\n  \t [4] MOSTRAR PARTICIPANTES");
            printf("\n  \t [5] MOSTRAR TOTAL DA OCUPACAO \n\t\t NUMERO TOTAL: %i/%i", total_para_mostrar, total_de_lugares_disponivel);
            
            printf("\n\n\t\t == CONFIG == \n");
            printf("\n  \t [6] DEFINIR DATA, HORA E LOCAL\n");

            printf("\n\n [7] Sair do programa");

            printf("\n\n HORA: %s DATA: %s LOCAL: %s", hora,data,local);

            scanf("%i", &op);

            system("cls");

        } while(op != 1 && op != 2 && op != 3 && op != 4&& op != 5 && op != 6 && op != 7 );


        //ESCOLHAS DO MENU
        switch(op) {

        case 1: // RESERVAR PARA PARTICIPANTES ID:0 ====================================
            if(vf == 0) { //verificar se a data foi colocada
                 system("color FC");
                printf("\n\n   DEFINA A DATA E HORA PRIMEIRO >.< (6+enter)  \n\n");
                Sleep(250);
                system("color F0");
            } else {	
            
               printf(" \n\n _____________ RESERVAR PARA PARTICIPANTES _____________\n");
            printf(" \n\n (Primeiras 2 FILEIRAS reservadas para convidados e professores)\n\n");

                printf("Nome: ");
                scanf("%s", &participante[enum_dos_participante].nome);
                strcpy(participante[enum_dos_participante].data,  data);
                strcpy(participante[enum_dos_participante].hora,  hora);

                for(i=0; i<qnt_compra; i++) {

                    fflush(stdin);
                    //SCANEIA A FILEIRA QUE QUER RESERVAR :::
                    printf("Fileira: ");
                    scanf("%i", &f);
                    fflush(stdin);
                    printf("Coluna: ");
                    scanf("%i", &c);


                    // VERIFICAR E RESERVAR LUGAR :::

                    if(lugar[f-1][c-1] == 0 && f > 2 && c <= coluna && total_para_mostrar<=total_de_lugares_disponivel) {
           
                        printf("Lugar reservado");               
                        
                        lugar[f-1][c-1] = 1;

                        // algo que numera a cadeira
                        participante[enum_dos_participante].num_assento = num_das_cadeiras[f-1][c-1];
                       
                       //Situacao do participante (0 = participante, 1 = deficiente, 2 = convidado)
                        participante[enum_dos_participante].situacao = 0;
                       
                        total_para_mostrar++; //pegar quantidade pra mostrar ali embaixo dps
                        enum_dos_participante++; //  enumeracao pra nao sobrepor vetor

                    } else {
                        printf(" \n Lugar indisponivel OU Fileira indisponivel \n ");
                    }
                }
            }
            break;
        case 2:	// RESERVAR PRA DEFICIENTES ID:1 ==================================================
             if(vf == 0) { //verificar se a data foi colocada
              system("color FC");
                printf("\n\n   DEFINA A DATA E HORA PRIMEIRO >.< (6+enter)  \n\n");
                Sleep(500);
                system("color F0");
            } else {	
            
                printf("\n\n_____________ RESERVAR PARA DEFICIENTES _____________ \n");
                printf(" \n\n (Primeiras 2 FILEIRAS reservadas para convidados e professores)\n\n");

                printf("Nome: ");
                scanf("%s", &participante[enum_dos_participante].nome);
                strcpy(participante[enum_dos_participante].data,  data);
                strcpy(participante[enum_dos_participante].hora,  hora);

                for(i=0; i<qnt_compra; i++) {

                    fflush(stdin);
                    //SCANEIA A FILEIRA QUE QUER RESERVAR :::
                    printf("Fileira: ");
                    scanf("%i", &f);
                    fflush(stdin);
                    printf("Coluna: ");
                    scanf("%i", &c);
                    
                    // VERIFICAR E RESERVAR LUGAR :::

                    if(lugar[f-1][c-1] == 0 && f <= fileira && c <= coluna && lugares_JA_reservados<=qnt_reservado_para_deficientes-1) {

                        printf("Lugar reservado");
                        lugar[f-1][c-1] = 1;

                        // algo que numera a cadeira
                        participante[enum_dos_participante].num_assento = num_das_cadeiras[f-1][c-1];
                        
                        //Situacao do participante (0 = participante, 1 = deficiente, 2 = convidado
                        participante[enum_dos_participante].situacao = 1;
                        
                       lugares_JA_reservados++; // DEFICIENTES NUMERACAO
                        total_para_mostrar++; //pegar quantidade pra mostrar ali embaixo dps
                        enum_dos_participante++; //  enumeracao pra nao sobrepor vetor

                    } else {
                        printf("Lugar indisponivel");
                    }
                }
            }

            break;
        case 3:// RESERVAR PRA CONVIDADO ID:2 =================================
             if(vf == 0) { //verificar se a data foi colocada
              system("color FC");
                printf("\n\n   DEFINA A DATA E HORA PRIMEIRO >.< (6+enter)  \n\n");
                Sleep(500);
                system("color F0");
            } else {	
            
                printf("\n\n_____________ RESERVAR PARA CONVIDADO/PROFESSOR _____________ \n");
                 printf("\n\n SOMENTE AS 2 PRIMEIRAS FILEIRAS DISPONIVEL \n");

                printf("Nome: ");
                scanf("%s", &participante[enum_dos_participante].nome);
                strcpy(participante[enum_dos_participante].data,  data);
                strcpy(participante[enum_dos_participante].hora,  hora);

                for(i=0; i<qnt_compra; i++) {

                    fflush(stdin);
                    //SCANEIA A FILEIRA QUE QUER RESERVAR :::
                    printf("Fileira: ");
                    scanf("%i", &f);
                    fflush(stdin);
                    printf("Coluna: ");
                    scanf("%i", &c);
                    
                    // VERIFICAR E RESERVAR LUGAR :::
                    if(lugar[f-1][c-1] == 0 && f <= 2 && c <= coluna && lugares_JA_reservados_convidados<=qnt_reservado_para_convidados) {

                        printf("Lugar reservado");
                        lugar[f-1][c-1] = 1;

                        // algo que numera a cadeira
                        participante[enum_dos_participante].num_assento = num_das_cadeiras[f-1][c-1];
                        
                        //Situacao do participante (0 = participante, 1 = deficiente, 2 = convidado)
                        participante[enum_dos_participante].situacao = 2;
                        
                        lugares_JA_reservados_convidados++; // CONVIDADOS NUMERACAO
                        total_para_mostrar++; //pegar quantidade pra mostrar ali embaixo dps
                        enum_dos_participante++; //  enumeracao pra nao sobrepor vetor

                    } else {
                        printf("Lugar indisponivel ou fileira indisponivel");
                    }
                }
            }

	
            break;
        case 4:// MOSTRAR PARTICIPANTES  000000
        
        printf(" -----------------LISTA DE PARTICIPANTES--------------------");
         printf("\n\n \t\t  Voltar menu (1+enter) \n\n");
    
        printf(" __________________ PARTICIPANTES ____________________\n");
        for(i=0; i<total_para_mostrar; i++){ // MOSTRAR PARTICIPANTES
           if(participante[i].situacao == 0){
           	    printf("\nNOME: %s", participante[i].nome);
                printf("\nHORA: %s", participante[i].hora);
                printf("\nASSENTO: %i", participante[i].num_assento);
                printf("\nDATA: %s\n\n", participante[i].data);
		   }   
          }
        
         printf(" ____________________ DEFICENTES _____________________ \n");
         for(i=0; i<total_para_mostrar; i++){ // MOSTRAR DEFICIENTES
           if(participante[i].situacao == 1){
           	    printf("\nNOME: %s", participante[i].nome);
                printf("\nHORA: %s", participante[i].hora);
                printf("\nASSENTO: %i", participante[i].num_assento);
                printf("\nDATA: %s\n\n", participante[i].data);
		   }
          }
          
                printf(" ____________________ CONVIDADOS _____________________ \n");
         for(i=0; i<total_para_mostrar; i++){ // MOSTRAR CONVIDADOS
           if(participante[i].situacao == 2){
           	    printf("\nNOME: %s", participante[i].nome);
                printf("\nHORA: %s", participante[i].hora);
                printf("\nASSENTO: %i", participante[i].num_assento);
                printf("\nDATA: %s\n\n", participante[i].data);
		   }
          }

                 //voltar menu
            scanf("%i", &sair);
            if(sair == 1) {
                system("cls");
            }else{
            	system("cls");
			}
        
            break;
        case 6: // DEFINIR HORA DATA LOCAL
            definir_HORA_DATA_LOCAL(hora, data, local, p_vf);
            break;
            
            case 5://MOSTRAR LUGARES

            printf("\n  ///////////// RELATORIO DO DIA \\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");

            printf("\n \t QUANTIDADE TOTAL DE LUGARES: %i/%i", total_para_mostrar, total_de_lugares_disponivel);
            printf("\n \t LUGARES PARA DEFICIENTES: %i/%i(Cerca de 5%%)",lugares_JA_reservados, qnt_reservado_para_deficientes);
            printf("\n \t CONVIDADOS: %i/%i", lugares_JA_reservados_convidados,qnt_reservado_para_convidados);
            
            printf("\n\n \t    voltar menu(1+enter)\n\n");

            for(i=0; i<fileira; i++) {
                printf("\n\t");
                for(j=0; j<coluna; j++) {
                    printf("%i", lugar[i][j]);
                }
            }
                //voltar menu
            scanf("%i", &sair);
            if(sair == 1) {
                system("cls");
            }else{
            	system("cls");
			}
            	break;
            	
            case 7: // SAIR PROGRAMA
             exit(0);
            	break;


        default:
            printf("dnv");
        }
    }
    return 0;
}
// ***[ FUNCOES E PROCEDIMENTOS ]***

//===  PROCEDIMENTO QUE DEFINI HORARIO, DATA E LOCAL ===
void definir_HORA_DATA_LOCAL(char *hora, char *data, char *local, int *p_vf) {

    printf("\n  ///////////// DEFINIR DATA, HORA E LOCAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\ ");

    printf("\n\n      HORARIO DO EVENTO: ");

    scanf("%s", hora);

    printf("\n\n      DATA DO EVENTO: ");
    scanf("%s", data);

    fflush(stdin);

    printf("\n\n      LOCAL: ");
    gets(local);

    system("cls");

    *p_vf = 1;
}


void logo() {
    printf("\n     °                   _______  *      ______ "  );
    printf("\n  *       *     ####### /   ___/       /  ____/ ####   *    °    .  ");
    printf("\n      @       ######## /  /           /  /_    ######          @  ");
    printf("\n    .        ######## |  |        *  /  _ /   ########       .    ");
    printf("\n      ´   *   ####### |  |____      /  /___  ########   *        * ");
    printf("\n  *             ###### \\______/ O  /______/ O #####          *   ");
    printf("\n\n       ¨   .       SOFTWARE DE CONTROLE DE ENTRADA  *    @    ´   ¨");
    printf("\n\n    .          *            version 0.10.10       .        *    ");
}


