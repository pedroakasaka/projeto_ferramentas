#include<stdlib.h>
#include<stdio.h>
#include <locale.h>

int main(){


    setlocale(LC_ALL, "Portuguese");


    int op,cont = 0;
    int contador_aluguel = 0;
    int categoria_ferramenta[100];
    int numero_dias[100];
    char cliente_frequente[100];
    int valor_orcamento[100];
    int media_alugueis[100];


    //LAÇO DE REPETIÇÃO
    for(;;){
    //MENU
    printf("[0]Sair\n[1]Inserir mais registros\n[2]Apresentar resultados\n[3]Ordenar os registros pelo valor total do aluguel (decrescente)\n[4]Imprimir registros de alugueis\nDIGITE UMA OPÇÃO: ");
    scanf("%d",&op);

        //PARA O PROGRAMA SE O USUARIO DIGITAR [0]
        if(op == 0){
            break;
        }

        //OPÇÕES DO MENU
        switch(op){
            case 1:
                //CONTADOR DE ALUGUEIS
                    contador_aluguel+=1;
                    printf("Numero do aluguel: %d\n",contador_aluguel);
            
                //CATEGORIA
                    printf("[1]Ferramentas Manuais\n[2]Ferramentas Elétricas\n[3]Equipamentos Pesados\nESCOLHA UM: ");
                    scanf("%d",&categoria_ferramenta[cont]);
                
                //NUMERO DE DIAS
                    printf("Digite o numero de dias: ");
                    scanf("%d",&numero_dias[cont]);

                //CLIENTE FREQUENTE
                    printf("Cliente frequente? [S/N]");
                    scanf("%d",&cliente_frequente[cont]);

                    //VALOR CATEGORIAS
                    if(categoria_ferramenta[cont]==1){
                        valor_orcamento[cont] = (15*numero_dias[cont]);
                    }
                    else if(categoria_ferramenta[cont]==2){
                        valor_orcamento[cont] = (40*numero_dias[cont]);
                    }
                    else if(categoria_ferramenta[cont]){
                        valor_orcamento[cont] = (100*numero_dias[cont]);
                    }

                    //DESCONTOS
                    if numero_dias[cont] > 7{
                        valor_orcamento[cont] = valor_orcamento[cont] - (valor_orcamento[cont]*0.10);
                    }
                    if cliente_frequente[cont] == 'S'{
                        valor_orcamento[cont] = valor_orcamento[cont] - (valor_orcamento[cont]*0.15);
                    }
        }
    }








    return 0;
}
