#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int i,j,contador,aux,opc,opc2;
    int maior;
    int indice_maior;
    int impresso[100];
    int contador_aluguel=0;
    int categoria_ferramenta[100];
    int numero_dias[100];
    int cliente_frequente[100];
    float valor_orcamento[100];
    int maior_valor = 0;
    int aluguel_mais_sete = 0;
    int soma_dias = 0;
    float soma_aluguel = 0;
    float media_alugueis = 0;
    float media_clientesfreq = 0;
    float percentual = 0;
    float soma_clientesfreq = 0;
    int cont_clientesfreq = 0;
    int indice_maior_valor = 0;

    while(1){
        //titulo
        printf("--------------------");
        printf("FERRAMENTAS FATEC");
        printf("--------------------");


        //menu
        printf("\n[0]SAIR\n[1]INSERIR MAIS REGISTROS\n[2]APRESENTAR RESULTADOS\n[3]ORDENAR OS REGISTROS PELO VALOR TOTAL DO ALUGUEL(DECRESCENTE)\n[4]IMPRIMIR REGISTRO DE ALUGUEIS\nDIGITE UMA OPÇÃO: ");
        scanf("%d",&opc);


        //verificação
        if (opc < 0 || opc > 5){
            printf("OPÇÃO INVALIDA, TENTE NOVAMENTE!\n");
        }

        //para o programa
        if (opc == 0){
            break;
        }

        //inserir mais registros;
        if (opc == 1){
            system("cls");
            printf("--------------------");
            printf("INSERIR MAIS REGISTROS");
            printf("--------------------");
            contador_aluguel+=1;
            printf("\nNUMERO DO ALUGUEL: %d\n",contador_aluguel);


            //categoria;
            printf("\n[1]FERRAMENTAS MANUAIS\n[2]FERRAMENTAS ELETRICAS\n[3]EQUIPAMENTOS PESADOS\nESCOLHA UMA OPÇÃO: ");
            scanf("%d",&categoria_ferramenta[contador_aluguel]);
            while (categoria_ferramenta[contador_aluguel] < 1 || categoria_ferramenta[contador_aluguel] > 3){
                printf("%d É UMA OPÇÃO INVALIDA!\nESCOLHA UMA OPÇÃO ENTRE 1 A 3: ",categoria_ferramenta[contador_aluguel]);
                scanf("%d",&categoria_ferramenta[contador_aluguel]);
            }

            //numero dias;
            printf("DIGITE O NUMERO DE DIAS DO ALUGUEL: ");
            scanf("%d",&numero_dias[contador_aluguel]);

            //cliente frequente;
            printf("CLIENTE FREQUENTE? [1-SIM/2-NÃO]");
            scanf("%d",&cliente_frequente[contador_aluguel]);
            while (cliente_frequente[contador_aluguel] < 1 || cliente_frequente[contador_aluguel] > 2){
                printf("%d É UMA OPÇÃO INVALIDA!\nESCOLHA UMA OPÇÃO ENTRE 1 OU 2: ",categoria_ferramenta[contador_aluguel]);
                scanf("%d",&cliente_frequente[contador_aluguel]);
            }

            //valor categorias;
            if (categoria_ferramenta[contador_aluguel] == 1){
                valor_orcamento[contador_aluguel] = (15*numero_dias[contador_aluguel]);
            }
            else if(categoria_ferramenta[contador_aluguel] == 2){
                valor_orcamento[contador_aluguel] = (40*numero_dias[contador_aluguel]);
            }
            else if(categoria_ferramenta[contador_aluguel] == 3){
                valor_orcamento[contador_aluguel] = (100*numero_dias[contador_aluguel]);
            }

            //descontos;
            if (numero_dias[contador_aluguel] > 7){
                valor_orcamento[contador_aluguel] = valor_orcamento[contador_aluguel] - (valor_orcamento[contador_aluguel]*0.10);
            }
            if (cliente_frequente[contador_aluguel] == 1){
                valor_orcamento[contador_aluguel] = valor_orcamento[contador_aluguel] - (valor_orcamento[contador_aluguel]*0.15);
            }
            system("cls");

            } //fim da opc 1;


        //apresentar resultados;
        if (opc == 2){
            system("cls");
            printf("--------------------");
            printf("APRESENTANDO RESULTADOS");
            printf("--------------------\n");

            //media do valor de todos os alugueis;
            for(i=1; i<=contador_aluguel; i++){
                soma_aluguel += valor_orcamento[i];
            }
            media_alugueis = soma_aluguel/contador_aluguel;
            printf("\nA MEDIA DO VALOR DE TODOS OS ALUGUEIS É: %.2f\n",media_alugueis);


            //média dos aluguéis para clientes frequentes;
            for(i=1; i<=contador_aluguel; i++){
                if (cliente_frequente[i] == 1){
                    soma_clientesfreq += valor_orcamento[i];
                    cont_clientesfreq += 1;
                }
            }
            if (cont_clientesfreq > 0){
                media_clientesfreq = soma_clientesfreq/cont_clientesfreq;
                printf("\nMEDIA CLIENTES FREQUENTES: %.2f\n\n", media_clientesfreq);
                }
            else{
                printf("\nNÃO HÁ CLIENTES FREQUENTES!\n\n");
                }

            //numero do aluguel com mair valor;
            for(i=1; i<=contador_aluguel; i++){
                if(valor_orcamento[i] > maior_valor){
                       maior_valor = valor_orcamento[i];
                       indice_maior_valor = i;
                    }
            }
            printf("O NUMERO DO ALUGUEL COM MAIOR VALOR É: %d\n\n",indice_maior_valor);


            //percentual dos alugueis com duração acima de 7 dias em relação ao número total de aluguéis;
            for(i=1; i<=contador_aluguel; i++){
                if (numero_dias[i] > 7){
                    aluguel_mais_sete += 1;
               }
               }
               percentual = (aluguel_mais_sete/contador_aluguel)*100;
               printf("O PERCENTUAL DOS ALUGUÉIS COM DURAÇÃO ACIMA DE 7 DIAS EM RELAÇÃO AO NÚMERO TOTAL DE ALUGUÉIS: %.2f\n\n",percentual);


            //total geral de dias alugados;
            for(i=1; i<=contador_aluguel; i++){
                soma_dias += numero_dias[i];
            }
            printf("TOTAL DE DIAS ALUGADOS: %d\n\n",soma_dias);

            while(1){
                printf("DIGITE [1] PARA VOLTAR AO MENU PRINCIPAL: ");
                scanf("%d",&opc2);
                if (opc2 == 1){
                    system("cls");
                    break;
                }
            }
        
        } //fim da opc 2;


        //ordenar itens por ordem decrescente;
            if (opc == 3) {
            system("cls");
            printf("--------------------------------\n");
            printf("ORDENANDO POR ORDEM DECRESCENTE\n");
            printf("--------------------------------\n");

            // Criar um array para armazenar os índices originais dos aluguéis
            int indices[contador_aluguel];
            for (i = 1; i <= contador_aluguel; i++) {
                indices[i] = i; // Aluguel 1, 2, 3, ...
            }

            // Loop de ordenação (Bubble Sort)
            for (i = 1; i <= contador_aluguel - 1; i++) {
                for (j = 1; j <= contador_aluguel - i - 1; j++) {
                    // Comparar para ordenar em ordem decrescente com base no valor do orçamento
                    if (valor_orcamento[j] < valor_orcamento[j]) {
                    // Trocar os valores de aluguel
                    float temp_valor = valor_orcamento[j];
                    valor_orcamento[j] = valor_orcamento[j];
                    valor_orcamento[j] = temp_valor;

                    // Trocar os índices (para manter a referência original do aluguel)
                    int temp_index = indices[j];
                    indices[j] = indices[j];
                    indices[j] = temp_index;

                    // Trocar as categorias associadas ao aluguel
                    int temp_categoria = categoria_ferramenta[j];
                    categoria_ferramenta[j] = categoria_ferramenta[j];
                    categoria_ferramenta[j] = temp_categoria;

                    // Trocar os dias associados ao aluguel
                    int temp_dias = numero_dias[j];
                    numero_dias[j] = numero_dias[j];
                    numero_dias[j] = temp_dias;

                    // Trocar a informação se o cliente é frequente ou não
                    int temp_frequente = cliente_frequente[j];
                    cliente_frequente[j] = cliente_frequente[j];
                    cliente_frequente[j] = temp_frequente;
            }
        }
    }

        // Mostrar os registros ordenados com base no valor do orçamento
        for(i=1; i<= contador_aluguel; i++){
            printf("\nALUGUEL %d: VALOR TOTAL = %.2f\n", indices[i],valor_orcamento[i]);
        }


        }//fim da opc 3;


        //imprimir registro de alugueis;
        if (opc == 4){
            system("cls");
            printf("--------------------");
            printf("IMPRIMINDO REGISTROS DE ALUGUEIS");
            printf("--------------------");

            //aluguel;
            for(i=1; i<=contador_aluguel; i++){
               printf("\nALUGUEL: %d\n",i);

            //categoria;
            printf("CATEGORIA DE FERRAMENTA: ");
                if (categoria_ferramenta[i] == 1){
                    printf("FERRAMENTAS MANUAIS \n");
                }
                else if (categoria_ferramenta[i] == 2){
                    printf("FERRAMENTAS ELETRICAS \n");
                }
                else if (categoria_ferramenta[i] == 3){
                    printf("EQIPAMENTOS PESADOS \n");
                }

            //quantidade de dias;
            printf("QUANTIDADE DE DIAS: %d\n",numero_dias[i]);

            //cliente frequente;
            printf("CLIENTE FREQUENTE: ");
            if (cliente_frequente[i] == 1){
                printf("SIM\n");
            }
            else if (cliente_frequente[i] == 2){
                printf("NÃO\n");
            }

            //valor;
            printf("VALOR: %.2f\n",valor_orcamento[i]);

            printf("------------------------------------------------------------------------");

            }

            while(1){
                printf("\nDIGITE [1] PARA VOLTAR AO MENU PRINCIPAL: ");
                scanf("%d",&opc2);
                if (opc2 == 1){
                    system("cls");
                    break;
                }
            }

        } //fim da opc 4;



} //fim do while

    return 0;

} //fim do int main()
