#include <stdio.h>
#include <stdlib.h>

 struct funcionarios{
   char nome [20];
    char cargo [30];
    char setor [30];
    int id;
    int nascimento;
   int tempoServico;
   int tempoNaEmpresa;
   double salario;
   int workSemFerias;
 };
int main (){
 struct funcionarios funcionario[3];
 int i,escolha,ide;
 for(i=0;i<3;i++){
    funcionario[i].id= -1;
 }
while(escolha!=8) {
printf("--- Menu ---\n");
printf("1- Cadastrar funcionario\n");
printf("2- Buscar funcionario trazendo todas as informacoes \n");
printf("3- Remover funcionario \n");
printf("4- Aumento de salario \n");
printf("5- Verificar se pode aposentar \n");
printf("6- Verificar se pode pegar ferias \n");
printf("7- Verificar o total de funcionarios: \n");
printf("8- Sair do menu \n");
printf(" Escolha um item do menu: ");
scanf("%d",&escolha);
printf(" ---------- \n");

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
        scanf("%[^\n]s",funcionario[i].cargo);
        fflush(stdin);
        printf(" Digite o setor do funcionario: ");
        scanf("%[^\n]s",funcionario[i].setor);
        fflush(stdin);

        printf(" Digite sua data de nascimento: ");
        scanf("%d",&funcionario[i].nascimento);
        printf(" Digite o salario: ");
        scanf("%d",&funcionario[i].salario);
        break;
     }
     else if(i==2){
        printf(" Todas as vagas estao cheias\n");
     }
   }
}
if(escolha==2){
    printf(" Digite o ID do funcionario que quer buscar ");
    scanf("%d",&ide);
    for(i=0;i<=ide;i++){
        if(ide==funcionario[i].id){
            printf("-- Dados do funcionario --");
            printf("ID: %d; Nome funcionario: %s\n Cargo: %s\n Setor: %s\n Data nascimento: %d\n Salario: %d \n ",funcionario[i].id,funcionario[i].nome,funcionario[i].cargo, funcionario[i].setor,funcionario[i].nascimento,funcionario[i].salario);
        }
    }
}
}


return 0;
}
