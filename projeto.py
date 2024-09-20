contador_aluguel=0
categoria_ferramenta=[]
numero_dias=[]
cliente_frequente=[]
valor_orcamento=[]
media_alugueis=0

media_clientesfreq=0

while True:

    #MENU
    print("""
    [0]Sair   
    [1]Inserir mais registros 
    [2]Apresentar resultados
    [3]Ordenar os registros pelo valor total do aluguel (decrescente)
    [4]Imprimir registros de alugueis
    """)

    #VALIDAÇÃO DA ESCOLHA
    escolha=int(input("Escolha a sua opção "))
    while escolha not in range(0,5):
        print(f"{escolha} é uma opção invalida, tente novamente")
        escolha=int(input("Escolha a sua opção "))

    if escolha==0:
        break
    if escolha==1:
        contador_aluguel+=1
        print(f"Numero do aluguel: {contador_aluguel}")

    #CATEGORIA
        categoria_ferramenta.append(int(input("""
[1]Ferramentas manuais
[2]Ferramentas eletricas
[3]Equipamentos pesados   

Escolha:""")))                                                            

    #NUMERO DE DIAS
        numero_dias.append((int(input("Digite o numero de dias "))))
    
    #Cliente frequente
        cliente_frequente.append((int(input("Cliente frequente? [1-Sim] [2-Não] "))))
    
        #VALOR CATEGORIAS
        if categoria_ferramenta[-1]==1:
            valor_orcamento.append(15*numero_dias[-1])
        elif categoria_ferramenta[-1]==2:
            valor_orcamento.append(40*numero_dias[-1])
        elif categoria_ferramenta[-1]==3:
            valor_orcamento.append(100*numero_dias[-1])

        #DESCONTOS
        if numero_dias[-1]>7:
            valor_orcamento[-1]=valor_orcamento[-1]- (valor_orcamento[-1]*0.10)
        if cliente_frequente[-1]==1:
            valor_orcamento[-1]=valor_orcamento[-1]- (valor_orcamento[-1]*0.15)

    if escolha==2:
    #MEDIA DO VALOR DE TODOS OS ALUGUEIS
        for i in valor_orcamento:
            media_alugueis=sum(valor_orcamento)/contador_aluguel
        print(f"A media do valor de todos os alugueis é: {media_alugueis}")
    #A média dos aluguéis para clientes frequentes
        soma_clientesfreq=0
        cont_clientesfreq=0
        for i in range(contador_aluguel):
            if cliente_frequente[i]==1:
                soma_clientesfreq+=valor_orcamento[i]
                cont_clientesfreq+=1
        if cont_clientesfreq>0:
            media_clientesfreq=soma_clientesfreq/cont_clientesfreq
            print(f"soma clientes frequentes {soma_clientesfreq}")
            print(f"Media clientes frequentes: {media_clientesfreq}")
        else:
            print("Não há clientes frequentes")
    #O numero do aluguel com maior valor

#CONFERENCIA
print(f""" 
categoria da ferramenta
{categoria_ferramenta}
numero de dias
{numero_dias}
cliente frequente
{cliente_frequente}
valor orçamento
{valor_orcamento}
""")
