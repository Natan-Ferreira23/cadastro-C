#include <stdio.h>
#include <stdlib.h>
double aumento(double salario,double incremento);
void aposentar(int contribuicao, int nasc,char sexo);
struct funcionarios{
    char nome [50];
    char cargo [30];
    char setor [30];
    char sexo;
    int id;
    int nascimento;
    int tempoServico;
    int tempoNaEmpresa;
    double salario;
    int workSemFerias;
 };
int main(){
    int i,escolha=0,ide,totalfunc=0;
    double aumen,teste,total;
    struct funcionarios funcionario[3];
    for(i=0;i<3;i++){
        funcionario[i].id= -1;
    }
    while(escolha!=8){
        printf("----------------------- Menu -----------------------\n");
        printf("1- Cadastrar funcionario\n");
        printf("2- Buscar funcionario trazendo todas as informacoes\n");
        printf("3- Remover funcionario\n");
        printf("4- Aumento de salario\n");
        printf("5- Verificar se pode aposentar\n");
        printf("6- Verificar se pode pegar ferias\n");
        printf("7- Verificar o total de funcionarios:\n");
        printf("8- Sair do menu \n");
        printf("Escolha um item do menu:");
        scanf("%d",&escolha);
        printf("---------------------------------------------------\n");
        if(escolha==1){
            for(i=0;i<3;i++){
                if(funcionario[i].id==-1){
                    funcionario[i].id=i+1;
                    printf("-- Ainda temos vagas podemos cadastrar -- \n");
                    printf(" -- ID do funcionario: %d --\n",funcionario[i].id);
                    printf(" Digite o nome do funcionario: ");
                    scanf(" %[^\n]s",funcionario[i].nome);
                    fflush(stdin);
                    printf(" Digite o cargo do funcionario: ");
                    scanf(" %[^\n]s",funcionario[i].cargo);
                    fflush(stdin);
                    printf(" Digite o setor do funcionario: ");
                    scanf(" %[^\n]s",funcionario[i].setor);
                    fflush(stdin);
                    printf(" Digite seu ano de nascimento: ");
                    scanf("%d",&funcionario[i].nascimento);
                    printf(" Digite o salario: ");
                    scanf("%lf",&funcionario[i].salario);
                    break;
                }
                else if(i==2){
                    printf(" Todas as vagas estao cheias\n");
                }
            }
        }
        if(escolha==2){
            printf(" Digite o ID do funcionario que quer buscar:");
            scanf("%d",&ide);
                for(i=0;i<=ide;i++){
                    if(ide==funcionario[i].id){
                        printf("-- Dados do funcionario --\n");
                        printf("ID: %d\nNome funcionario: %s\nCargo: %s\nSetor: %s\nData nascimento: %d\nSalario: %.2lf \n",funcionario[i].id,funcionario[i].nome,funcionario[i].cargo, funcionario[i].setor,funcionario[i].nascimento,funcionario[i].salario);
                        break;
                    }
                    else if(i=ide){
                        printf(" Nao encontrado\n");
                    }
                }
        }
        if(escolha==3){
            printf("Qual o ID do funcionario que deseja remover?:");
            scanf("%d",&ide);
            for(i=0;i<3;i++){
                if(ide==funcionario[i].id){
                    funcionario[i].id=-1;
                    break;
                }
                else if(i==2){
                    printf("Funcionario nao encontrado");
                }
            }
        }
        if(escolha==4){
            printf("Qual Funcionario deseja aumentar o salario?(ID):");
            scanf("%d",&ide);
            printf("Informe em porcentagem quanto deseja aumentar do salario:");
            scanf("%lf",&aumen);
            aumen/=100;
            aumen+=1.0;
            for(i=0;i<3;i++){
                if(ide==funcionario[i].id){
                    funcionario[i].salario=aumento(funcionario[i].salario,aumen);
                    break;
                }
                else if(i==2){
                    printf("Funcionario nao encontrado");
                }
            }
        }
        if(escolha==5){
            printf("-- Verficiando se pode aposentar --\n");
            printf(" Digite o ID do funcionario: ");
            scanf("%d",&ide);
           for(i=0;i<3;i++){
             if(funcionario[i].id==ide){
                 printf(" Digite o tempo de contribuicao do funcionario: ");
                 scanf("%d",&funcionario[i].tempoServico);
                 printf(" Informe seu sexo(M/F):");
                 scanf(" %c",&funcionario[i].sexo);
                 aposentar(funcionario[i].tempoServico,funcionario[i].nascimento,funcionario[i].sexo);
                 break;
             }
           }
        }
    if(escolha==6){
            printf("Digite seu id de funcionario: ");
            scanf("%d",&ide);
        for(i=0;i<=ide;i++){
            if(ide==funcionario[i].id){
                printf("%s quantos meses esta sem pegar ferias: ", funcionario[i].nome);
                scanf("%d",&funcionario[i].workSemFerias);
            if(funcionario[i].workSemFerias>6){
                printf(" Voce esta a mais de 6 meses sem pegar ferias, pode pegar !!\n");
            }
            else if (funcionario[i].workSemFerias<=6 && funcionario[i].workSemFerias>=0){
                printf(" Voce ja pegou ferias em algum momento dos ultimos 6 meses, aguarde dar 6 meses completos \n");
            }
            else{
                printf(" Insira um valor valido \n");
            }
            break;
            }
            else if (i==ide){
                printf(" O funcionario nao foi encontrado");
            }
        }
    }

        if(escolha==7){
            for(i=0;i<3;i++){
                if(funcionario[i].id!=-1){
                    totalfunc++;
                }
            }
            printf("Total de Funcionarios:%d\n",totalfunc);
        }
    }
return 0;
}
double aumento(double salario,double incremento){
    double total;
    total=salario*incremento;
    return total;
}
void aposentar(int contribuicao, int nasc,char sexo){
int idade=2023-nasc;
if(sexo=='m' || sexo=='M' || sexo=='f' || sexo=='F'){
    if(idade>65 && contribuicao>35 && (sexo=='M' || sexo=='m')){
        printf("Sim\n");
    }
    else if(idade>60 && contribuicao>30 && (sexo=='F' || sexo=='f')){
        printf("Sim\n");
    }
    else{
        printf("Nao\n");
    }
}
else{
    printf("Sexo informado errado\n");
}
}
