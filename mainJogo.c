#include <stdio.h>                                  //Diogo Ventura 62413 Francisco Ribeiro 62695                                             
#include <stdlib.h>
#include <string.h>
#include "iterador.h"
#include "sequencia.h"
#include "equipa.h"
#include "participante.h"
#include "talhao.h"
#include "terreno.h"
#include "jogo.h"

jogo ler_ficheiro_equipas();
void menu(jogo j);

int main(){
    menu(ler_ficheiro_equipas());
    return 0;
}

jogo ler_ficheiro_equipas(){
    FILE *file;
    char line[100];
    int num_elem_equipa = 0, i = 0, cmd1 = 0, cmd2 = 0, cmd3 = 0, n_equipa = 1, numTotalEquipas = 0;
    char nome_participante[40], nome_equipa[40];
    jogo j = 0;

    j = criaJogo(50);
    file = fopen("teams.txt", "r");
    
    if(file == NULL){
        printf("file can't be opened \n");
        exit (0);
    }
    cmd1 = 1;
    cmd2 = 0;
    cmd3 = 0;
    i=0;

    while(fgets(line, 100, file)){ 
        if(cmd3 == 1){
            line[strlen(line)] = '\0';
            strcpy(nome_participante, line);
            if(nome_participante[strlen(nome_participante)-1] == ' ' || nome_participante[strlen(nome_participante)-1] == '\n' || nome_participante[strlen(nome_participante)-1] == '\t')
                nome_participante[strlen(nome_participante)-1] = '\0';
            criaParticipantesEquipa(daEquipaFicheiro(j, n_equipa), nome_participante);
            i++;
        }
        if(cmd2 == 1){
            line[strlen(line)] = '\0';
            strcpy(nome_equipa, line);
            nome_equipa[strlen(nome_equipa)] = '\0';
            if(nome_equipa[strlen(nome_equipa)-1] == ' ' || nome_equipa[strlen(nome_equipa)-1] == '\n' || nome_equipa[strlen(nome_equipa)-1] == '\t')
                nome_equipa[strlen(nome_equipa)-1] = '\0';
            numTotalEquipas++;
            criaEquipaJogo(j, n_equipa, num_elem_equipa, nome_equipa);
            cmd2 = 0;
            cmd3 = 1;
        }
        if(cmd1 == 1){
            num_elem_equipa = atoi(line); // converte a string para inteiro
            cmd1 = 0;
            cmd2 = 1;
        }
        if(i == num_elem_equipa){
            n_equipa++;
            i = 0;
            cmd3 = 0;
            cmd1 = 1;
        }
    }
    guardaNumTotalEquipas(numTotalEquipas, j);
    fclose(file);
    return j;
}

void menu(jogo j){
    int l=0, c=0, num_equipas_Jogar, cmd=1, salto_linha=0, salto_coluna=0, aux=0, num_equipa, escavacao=0;
    char linha_comando[100], comando[30], nome_equipa[40], string[10], nome_participante[40];
    int tesouros, equipas_jogar_inteiro[5000];
    terreno ter = 0;
    equipa e = 0;
    
    scanf("%d %d", &l, &c);
    ter = criaTerreno(ter, l, c);
    //GUARDA OS TESOUROS NO TERRENO
    for(int i=0; i<l;i++){
        for(int j = 0; j < c; j++){
            scanf("%d ", &tesouros);
            preenchePosicaoTalhao(ter, i, j, tesouros);
        }
    }
    riquezaTotal(ter);
    riquezaTotalParaRiquezaAtual(ter);

    //GUARDA O NUMERO DE EQUIPAS E AS EQUIPAS QUE VAO JOGAR
    scanf(" %d", &num_equipas_Jogar);
    for(int q=1;q<=num_equipas_Jogar;q++){
        scanf("%d", &aux);
        equipas_jogar_inteiro[q]=aux;
    }
    for(int h=1;h<=num_equipas_Jogar;h++){
        guardaEquipaJogo(j, nomeEquipa(daEquipaFicheiro(j, equipas_jogar_inteiro[h])), daEquipaFicheiro(j, equipas_jogar_inteiro[h]));
    }

    //ESCOLHE O COMANDO A SER EXECUTADO EX: escavacao 1 1 nomeEquipa OU estrela nomeEquipa OU terreno OU riqueza OU sair
    while(cmd){
        scanf(" %[^\n]", linha_comando);
        sscanf(linha_comando, "%s", comando);
        if(numPalavra(linha_comando) == 1){
            strcpy(comando, linha_comando);
            if(strcmp("riqueza", comando) == 0){
                printf("Riqueza enterrada: %d\n", daRiquezaAtual(ter));
            }
                
            else if(strcmp("terreno", comando) == 0){
                for(int i=0;i<linhasTerreno(ter);i++){
                    for(int j=0;j<colunasTerreno(ter);j++){
                        if(escreverMatrizComSinais(ter, i, j) == 1)
                            printf("*");
                        else
                            printf("-");
                        
                    }
                    printf("\n");
                }
            }
            else if(strcmp("sair", comando) == 0){
                if(seEquipasTodasDesqualificadas(j)){
                    printf("Todas as equipas foram expulsas.\n");
                }
                else{
                    if(daRiquezaAtual(ter) > 0){
                        printf("Ainda havia tesouros por descobrir...\n");
                    }
                    else{
                        printf("Todos os tesouros foram descobertos!\n");
                    }
                    // CLASSIFICACAO DAS EQUIPAS
                    printf("classificacao\n");
                    iterador it = organizaEquipas(j);
                    while(temSeguinteIterador(it)!=0){
                        e = (equipa)seguinteIterador(it);
                        if(verificaEquipa(j, nomeEquipa(e))){
                            if(EquipaDesclassificada(e) == 0)
                                printf("%s: %d pts; %d descl.; %d com lic.\n", nomeEquipa(e), pontuacaoEquipa(e), numParticipantesExpulsos(e), numParticipantesComLicenca(e));
                        }
                    }
                    destroiIterador(it);
                }
                cmd = 0;
            }
            else if(strcmp("reforco", comando) == 0){
                scanf(" %[^\n]", nome_equipa);
                scanf(" %[^\n]", nome_participante);
                if(verificaEquipa(j, nome_equipa) == 1){
                    if(EquipaDesclassificada(devolveEquipaJogo(j, nome_equipa)) == 1)
                        printf("Equipa invalida\n");
                    else{
                        if(verificaNomeParticipanteEquipa(devolveEquipaJogo(j, nome_equipa), nome_participante) == 1){
                            printf("Arqueologo invalido\n");
                            continue;
                        }
                        else{
                            criaParticipantesEquipa(devolveEquipaJogo(j, nome_equipa), nome_participante);
                            adicionaMembroEquipa(devolveEquipaJogo(j, nome_equipa));
                        }
                    }
                }
                else
                    printf("Equipa invalida\n");
            }
            else
                printf("Comando invalido\n");
        }
        else{//obrigatoriamente mais de uma palavra
            if(strcmp("escavacao", comando) == 0){
                if(sscanf(linha_comando,"%s %d %d %[^\n]", string, &salto_linha, &salto_coluna, nome_equipa) != 4){ 
                    printf("Falta algum argumento no comando escavacao\n");
                    continue; //sai do if e nao do while
                }
                if(salto_linha==0 && salto_coluna==0){
                    printf("Salto invalido\n");
                    continue;
                }
                if(verificaEquipa(j, nome_equipa)){//verifica se a equipa existe no jogo (dicionario)
                    if(EquipaDesclassificada(devolveEquipaJogo(j, nome_equipa)) !=1 ){
                        escavacao=escavacaoEquipa(j, nome_equipa, salto_linha, salto_coluna, ter);
                        if(escavacao == 1)
                            printf("%s foi expulsa\n", nome_equipa);
                    }
                    else 
                        printf("Equipa invalida\n");    
                }
                else
                    printf("Equipa invalida\n");
            }
            else if(strcmp("estrela", comando) == 0){
                if(sscanf(linha_comando, "%s %[^\n]", string, nome_equipa) != 2){
                    printf("Falta algum argumento no comando estrela\n");
                    continue;
                }
                if(verificaEquipa(j, nome_equipa) == 0){
                    printf("Equipa invalida\n");
                    continue;
                }
                if(EquipaDesclassificada(devolveEquipaJogo(j, nome_equipa)) != 1){
                    if(verificaEquipa(j, nome_equipa)){
                        printf("Estrela de %s: %s\n", nome_equipa, estrelaEquipa(devolveEquipaJogo(j, nome_equipa)));
                    }
                    else
                        printf("Equipa invalida\n");
                }
                else
                    printf("Equipa invalida\n");
            }
            else if(strcmp("equipa", comando) == 0){
                if(sscanf(linha_comando, "%s %d", string, &num_equipa) != 2){
                    printf("Falta algum argumento no comando equipa\n");
                    continue;
                }
                if(num_equipa<=0 || num_equipa>escreveNumTotalEquipas(j)){
                    printf("Equipa inexistente\n");
                    continue;
                }
                else if(verificaEquipa(j, nomeEquipa(daEquipaFicheiro(j, num_equipa))) == 1){
                    printf("Equipa invalida\n");
                    continue;
                }
                else
                    guardaEquipaJogo(j, nomeEquipa(daEquipaFicheiro(j, num_equipa)), daEquipaFicheiro(j, num_equipa));
            }
            else
                printf("Comando invalido\n");
        }
    }
    destroiJogo(j);
    destroiTerreno(ter);
}                                                                                       //Diogo Ventura 62413 Francisco Ribeiro 62695   
