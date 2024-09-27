#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j, contador, aux, opc, opc2;
    int contador_aluguel = 0;
    int categoria_ferramenta[100];
    int numero_dias[100];
    int cliente_frequente[100];
    float valor_orcamento[100];

    while(1){
        // Menu
        printf("\n[0]SAIR\n[1]INSERIR MAIS REGISTROS\n[2]APRESENTAR RESULTADOS\n[3]ORDENAR OS REGISTROS PELO VALOR TOTAL DO ALUGUEL(DECRESCENTE)\n[4]IMPRIMIR REGISTRO DE ALUGUEIS\nDIGITE UMA OPÇÃO: ");
        scanf("%d",&opc);

        // Verificação de opção inválida
        if (opc < 0 || opc > 4) {
            printf("OPÇÃO INVALIDA, TENTE NOVAMENTE!\n");
        }

        // Sair do programa
        if (opc == 0) {
            break;
        }

        // Inserir registros
        if (opc == 1){
            system("cls");
            contador_aluguel++;
            printf("\nNUMERO DO ALUGUEL: %d\n", contador_aluguel);

            // Categoria
            printf("\n[1]FERRAMENTAS MANUAIS\n[2]FERRAMENTAS ELETRICAS\n[3]EQUIPAMENTOS PESADOS\nESCOLHA UMA OPÇÃO: ");
            scanf("%d", &categoria_ferramenta[contador_aluguel]);
            while (categoria_ferramenta[contador_aluguel] < 1 || categoria_ferramenta[contador_aluguel] > 3) {
                printf("%d É UMA OPÇÃO INVALIDA!\nESCOLHA UMA OPÇÃO ENTRE 1 A 3: ", categoria_ferramenta[contador_aluguel]);
                scanf("%d", &categoria_ferramenta[contador_aluguel]);
            }

            // Número de dias
            printf("DIGITE O NUMERO DE DIAS DO ALUGUEL: ");
            scanf("%d", &numero_dias[contador_aluguel]);

            // Cliente frequente
            printf("CLIENTE FREQUENTE? [1-SIM/2-NÃO]");
            scanf("%d", &cliente_frequente[contador_aluguel]);
            while (cliente_frequente[contador_aluguel] < 1 || cliente_frequente[contador_aluguel] > 2) {
                printf("%d É UMA OPÇÃO INVALIDA!\nESCOLHA UMA OPÇÃO ENTRE 1 OU 2: ", cliente_frequente[contador_aluguel]);
                scanf("%d", &cliente_frequente[contador_aluguel]);
            }

            // Valor das categorias
            if (categoria_ferramenta[contador_aluguel] == 1) {
                valor_orcamento[contador_aluguel] = (15 * numero_dias[contador_aluguel]);
            } else if (categoria_ferramenta[contador_aluguel] == 2) {
                valor_orcamento[contador_aluguel] = (40 * numero_dias[contador_aluguel]);
            } else if (categoria_ferramenta[contador_aluguel] == 3) {
                valor_orcamento[contador_aluguel] = (100 * numero_dias[contador_aluguel]);
            }

            // Descontos
            if (numero_dias[contador_aluguel] > 7) {
                valor_orcamento[contador_aluguel] = valor_orcamento[contador_aluguel] - (valor_orcamento[contador_aluguel] * 0.10);
            }
            if (cliente_frequente[contador_aluguel] == 1) {
                valor_orcamento[contador_aluguel] = valor_orcamento[contador_aluguel] - (valor_orcamento[contador_aluguel] * 0.15);
            }

            system("cls");
        }

        // Apresentar resultados
        if (opc == 2) {
            system("cls");
            printf("--------------------\n");
            printf("APRESENTANDO RESULTADOS\n");
            printf("--------------------\n");

            float soma_aluguel = 0;
            float media_alugueis = 0;
            float soma_clientesfreq = 0;
            float media_clientesfreq = 0;
            int cont_clientesfreq = 0;
            int aluguel_mais_sete = 0;
            float percentual = 0;
            int soma_dias = 0;
            int maior_valor = 0;
            int indice_maior_valor = 0;

            // Média do valor de todos os aluguéis
            for (i = 1; i <= contador_aluguel; i++) {
                soma_aluguel += valor_orcamento[i];
            }
            media_alugueis = soma_aluguel / contador_aluguel;
            printf("A MEDIA DO VALOR DE TODOS OS ALUGUEIS É: %.2f\n", media_alugueis);

            // Média dos aluguéis para clientes frequentes
            for (i = 1; i <= contador_aluguel; i++) {
                if (cliente_frequente[i] == 1) {
                    soma_clientesfreq += valor_orcamento[i];
                    cont_clientesfreq++;
                }
            }
            if (cont_clientesfreq > 0) {
                media_clientesfreq = soma_clientesfreq / cont_clientesfreq;
                printf("MEDIA CLIENTES FREQUENTES: %.2f\n", media_clientesfreq);
            } else {
                printf("NÃO HÁ CLIENTES FREQUENTES!\n");
            }

            // Número do aluguel com maior valor
            for (i = 1; i <= contador_aluguel; i++) {
                if (valor_orcamento[i] > maior_valor) {
                    maior_valor = valor_orcamento[i];
                    indice_maior_valor = i;
                }
            }
            printf("O NUMERO DO ALUGUEL COM MAIOR VALOR É: %d\n", indice_maior_valor);

            // Percentual dos aluguéis com duração acima de 7 dias
            for (i = 1; i <= contador_aluguel; i++) {
                if (numero_dias[i] > 7) {
                    aluguel_mais_sete++;
                }
            }
            percentual = ((float) aluguel_mais_sete / contador_aluguel) * 100;
            printf("O PERCENTUAL DOS ALUGUÉIS COM DURAÇÃO ACIMA DE 7 DIAS: %.2f%%\n", percentual);

            // Total geral de dias alugados
            for (i = 1; i <= contador_aluguel; i++) {
                soma_dias += numero_dias[i];
            }
            printf("TOTAL DE DIAS ALUGADOS: %d\n", soma_dias);

            while (1) {
                printf("DIGITE [1] PARA VOLTAR AO MENU PRINCIPAL: ");
                scanf("%d", &opc2);
                if (opc2 == 1) {
                    system("cls");
                    break;
                }
            }
        }

        // Ordenar registros pelo valor total do aluguel
        if (opc == 3) {
            system("cls");
            printf("--------------------------------\n");
            printf("ORDENANDO POR ORDEM DECRESCENTE\n");
            printf("--------------------------------\n");

            // Ordenação Bubble Sort
            for (i = 1; i <= contador_aluguel - 1; i++) {
                for (j = 1; j <= contador_aluguel - i; j++) {
                    if (valor_orcamento[j] < valor_orcamento[j + 1]) {
                        // Troca os valores de aluguel
                        float temp_valor = valor_orcamento[j];
                        valor_orcamento[j] = valor_orcamento[j + 1];
                        valor_orcamento[j + 1] = temp_valor;

                        // Troca as categorias associadas ao aluguel
                        int temp_categoria = categoria_ferramenta[j];
                        categoria_ferramenta[j] = categoria_ferramenta[j + 1];
                        categoria_ferramenta[j + 1] = temp_categoria;

                        // Troca os dias associados ao aluguel
                        int temp_dias = numero_dias[j];
                        numero_dias[j] = numero_dias[j + 1];
                        numero_dias[j + 1] = temp_dias;

                        // Troca a informação se o cliente é frequente ou não
                        int temp_frequente = cliente_frequente[j];
                        cliente_frequente[j] = cliente_frequente[j + 1];
                        cliente_frequente[j + 1] = temp_frequente;
                    }
                }
            }

            printf("Registros ordenados com sucesso!\n");

            // Exibir os registros ordenados
            for (i = 1; i <= contador_aluguel; i++) {
                printf("\nALUGUEL %d: VALOR TOTAL = %.2f\n", i, valor_orcamento[i]);
            }
        }

        // Imprimir registros
        if (opc == 4) {
            system("cls");
            printf("--------------------\n");
            printf("IMPRIMINDO REGISTROS DE ALUGUEIS\n");
            printf("--------------------\n");

            for (i = 1; i <= contador_aluguel; i++) {
                printf("\nNUMERO DO ALUGUEL: %d\n", i);

                printf("CATEGORIA: ");
                if (categoria_ferramenta[i] == 1) {
                    printf("FERRAMENTAS MANUAIS\n");
                } else if (categoria_ferramenta[i] == 2) {
                    printf("FERRAMENTAS ELETRICAS\n");
                } else if (categoria_ferramenta[i] == 3) {
                    printf("EQUIPAMENTOS PESADOS\n");
                }

                printf("NUMERO DE DIAS: %d\n", numero_dias[i]);

                printf("CLIENTE FREQUENTE? ");
                if (cliente_frequente[i] == 1) {
                    printf("SIM\n");
                } else if (cliente_frequente[i] == 2) {
                    printf("NÃO\n");
                }

                printf("VALOR TOTAL: %.2f\n", valor_orcamento[i]);
            }
        }
    }

    return 0;
}