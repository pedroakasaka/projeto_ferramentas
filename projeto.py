from time import sleep
import sys


#VARIAVEIS
contador_aluguel=0
categoria_ferramenta=[]
numero_dias=[]
cliente_frequente=[]
valor_orcamento=[]
media_alugueis=0
media_clientesfreq=0
maior_valor=0
aluguel_mais_sete=0
soma_dias = 0
percentual=0

def titulo(titulo):
    print('-' * 40)
    print(f'{titulo:^40}')
    print('-' * 40)
def loading_inicial():
    print("\nINICIANDO PROGRAMA", end="")
    for _ in range(3):  
        sleep(0.5)   
        print(".", end="")
        sys.stdout.flush()  
    print("CONCLUIDO!")
def loading_exit():
    print("\nFINALIZANDO O PROGRAMA", end="")
    for _ in range(3):  
        sleep(0.5)   
        print(".", end="")
        sys.stdout.flush()  
    print("CONCLUIDO!")      
def loading_menu(escolha_nome):
    print(f"CARREGANDO A OPÇÃO {escolha_nome}", end="")
    for _ in range(3):  
        sleep(1)   
        print(".", end="")
        sys.stdout.flush()  
    print("CONCLUIDO!") 

loading_inicial()

while True:
    
    #TITULO
    titulo(titulo="FERRAMENTAS FATEC")
    
    #MENU
    print("""
[0]Sair   
[1]Inserir mais registros 
[2]Apresentar resultados
[3]Ordenar os registros pelo valor total do aluguel (decrescente)
[4]Imprimir registros de alugueis
    """)

    #VALIDAÇÃO DA ESCOLHA
    escolha=int(input("ESCOLHA UMA OPÇÃO: "))

    if escolha == 1:
        loading_menu(escolha_nome="[1] - INSERIR MAIS REGISTROS")

    if escolha == 2:
        loading_menu(escolha_nome="[2] - APRESENTANDO RESULTADOS")

    if escolha == 3:
        loading_menu(escolha_nome="[3] - ORDENAR REGISTROS EM ORDEM DECRESCENTE")

    if escolha == 4:
        loading_menu(escolha_nome="[4] - IMPRIMINDO REGISTRO DE ALUGUEIS")





    while escolha not in range(0,5):
        print(f"{escolha} é uma opção invalida, tente novamente")
        escolha=int(input("ESCOLHA UMA OPÇÃO: "))

    if escolha==0:
        loading_exit()
        print("Obrigado pela preferencia!")
        break
    if escolha==1:
        titulo(titulo="INSERIR MAIS REGISTROS")
        contador_aluguel+=1
        print(f"Numero do aluguel: {contador_aluguel}")

    #CATEGORIA
        categoria_ferramenta.append(int(input("""
[1]Ferramentas manuais
[2]Ferramentas eletricas
[3]Equipamentos pesados   

Escolha: \n""")))    
        while categoria_ferramenta[-1] not in range(1,4):
            print(f"{categoria_ferramenta[-1]} é uma opção invalida, tente novamente")
            categoria_ferramenta[-1]=int(input("ESCOLHA UMA OPÇÃO: "))                                                        

    #NUMERO DE DIAS
        numero_dias.append((int(input("Digite o numero de dias "))))
    
    #Cliente frequente
        cliente_frequente.append((int(input("Cliente frequente? [1-Sim] [2-Não] "))))
        while cliente_frequente[-1] not in range(1,3):
            print(f"{cliente_frequente[-1]} é uma opção invalida, tente novamente")
            cliente_frequente[-1]=int(input("ESCOLHA UMA OPÇÃO: "))    
    
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
        titulo(titulo="APRESENTAR RESULTADOS")
        print("\n")
    #MEDIA DO VALOR DE TODOS OS ALUGUEIS
        for i in valor_orcamento:
            media_alugueis=sum(valor_orcamento)/contador_aluguel
        print(f"A media do valor de todos os alugueis é: {media_alugueis}")
        sleep(0.5)
    #A média dos aluguéis para clientes frequentes
        soma_clientesfreq=0
        cont_clientesfreq=0
        for i in range(contador_aluguel):
            if cliente_frequente[i]==1:
                soma_clientesfreq+=valor_orcamento[i]
                cont_clientesfreq+=1
        if cont_clientesfreq>0:
            media_clientesfreq=soma_clientesfreq/cont_clientesfreq
            print(f"Media clientes frequentes: {media_clientesfreq}")
            sleep(1)
        else:
            print("Não há clientes frequentes")
            sleep(1)
    #O numero do aluguel com maior valor
        for i in range(contador_aluguel):
            if contador_aluguel==0:
                maior_valor=i
            elif valor_orcamento[-1]>maior_valor:
                maior_valor=i
        print(f"O numero do aluguel com maior valor é {maior_valor}")
        sleep(1)
    #O percentual dos aluguéis com duração acima de 7 dias em relação ao número total de aluguéis.
        for i in range(contador_aluguel):  
            if numero_dias[i]>7:
                aluguel_mais_sete+=1
        percentual=(aluguel_mais_sete/contador_aluguel)*100
        print(f"O  O percentual dos aluguéis com duração acima de 7 dias em relação ao número total de aluguéis: {percentual} % ")
        sleep(1)


    #5. O total geral de dias alugados.
        soma_dias=sum(numero_dias)
        print(f"Total de dias alugado: {soma_dias}")
        sleep(1)
        
    if escolha==3:
        titulo(titulo="ORDENAR POR ORDEM DECRESCENTE")
        print("\n")
       
        tuplas = [(valor, idx) for idx, valor in enumerate(valor_orcamento)]
        
        tuplas.sort(reverse=True)

        for idx, (valor, original_idx) in enumerate(tuplas, start=1):
            print(f"Aluguel {original_idx+1}: Valor total = {valor}")
    
    if escolha==4:
        titulo(titulo="IMPRIMIR REGISTROS DE ALUGUEIS")
        print("=-"*30)
        #aluguel
        for i in range(contador_aluguel):
            print(f"\nAluguel: {i+1}")
            
        #categoria    
            print("Categoria de ferramenta: ",end="")
            if categoria_ferramenta[i]==1:
                print(f"Ferramentas manuais")
            elif categoria_ferramenta[i]==2:
                print(f"Ferramentas eletricas")
            elif categoria_ferramenta[i]==3:
                print(f"Equipamentos pesados")
            else:
                print("Categoria invalida")

        #Quantidade dias    
            print(f"Quantidade de dias: {numero_dias[i]}")
        #Cliente frequente
            print("Cliente frequente: ",end="")
            if cliente_frequente[i]==1:
                print("Sim")
            elif cliente_frequente[i]==2:
                print("Não")
            else:
                print("Tipo de cliente invalido")    
        #valor            
            print(f"Valor: {valor_orcamento[i]}")
            


