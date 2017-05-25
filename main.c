#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    int choice;
    /*Abrir ficheiros e preencher as listas com as informaçoes dos ficheiros*/
    ListA listaAluno = cria_listaAluno();
    ListE listaExame = cria_listaExam();
    ListD listaDisc = cria_listaDisc();
    a:
    choice = menu();
    if(choice == 1){
        int choice2 = menu_alunos();
        if(choice2 == 4){
            printf("Returning to menu...\n");
            goto a;
        }
        else if(choice2 == 1){
            new_aluno(listaAluno);
            goto a;
        }
        else if(choice2 == 2){
            del_aluno();
            goto a;
        }
        else if(choice2 == 3){
            print_alunos(listaAluno);
            goto a;
        }
        else{
            printf("Opção inválida, voltando ao menu\n");
            goto a;
        }
    }
    if(choice == 2){
        int choice2 = menu_disciplinas();
        if(choice2 == 4){
            printf("Returning to menu...\n");
            goto a;
        }
        else if(choice2 == 1){
            new_disc();
            goto a;
        }
        else if(choice2 == 2){
            del_disc();
            goto a;
        }
        else if(choice2 ==3){
            list_disc();
            goto a;
        }
        else{
            printf("Opção inválida, voltando ao menu\n");
            goto a;
        }
    }
    if(choice == 3){
        int choice2 = menu_exames();
        if (choice2 == 4){
            printf("Returning to menu...\n");
            goto a;
        }
        else if(choice2 == 1){
            new_exam();
            goto a;
        }
        else if (choice2 == 2){
            del_exam();
            goto a;
        }
        else if (choice2 == 3){
            list_exam();
            goto a;
        }
        else{
            printf("Opção inválida, voltando ao menu\n");
            goto a;
        }
    }
    if(choice == 4){
        printf("Saindo...");
        exit;
    }
    /*Guardar as novas listas nos ficheiros para a informção ficar guardada*/
}


int menu(){
    int choice;
    printf("\n-----//MENU//-----\n");
    printf("1:Editar Alunos\n");
    printf("2:Editar Disciplinas\n");
    printf("3:Editar Exames\n");
    printf("4:Sair do Programa\n");
    printf("------------------\n");
    printf("O que pretende fazer?\n");
    scanf("%d",&choice);
    if(choice<1 || choice > 4){
        printf("Escolha inválida\n");
        exit;
    }
    return choice;
}

int menu_alunos(){
    int choice2;
    printf("-----//ALUNOS//-----\n");
    printf("1:Criar Alunos\n");
    printf("2:Apagar Alunos\n");
    printf("3:Listar Alunos\n");
    printf("4:Sair do Programa\n");
    printf("--------------------\n");
    printf("O que pretende fazer?\n");
    scanf("%d",&choice2);
    if(choice2==4){
        exit;
    }
    return choice2;
}

int menu_disciplinas(){
    int choice2;
    printf("-----//DISCIPLINAS//-----\n");
    printf("1:Criar Disciplina\n");
    printf("2:Apagar Disciplina\n");
    printf("3:Listar Disciplina\n");
    printf("4:Sair do Programa\n");
    printf("-------------------------\n");
    scanf("%d",&choice2);

    return choice2;
}

int menu_exames(){
    int choice2;
    printf("-----//EXAMES//-----\n");
    printf("1:Criar Exames\n");
    printf("2:Apagar Exames\n");
    printf("3:Listar Exames\n");
    printf("4:Sair do Programa\n");
    printf("--------------------\n");
    scanf("%d",&choice2);
    return choice2;

}

void new_aluno(ListA listaAluno){
    int num_aluno;
    int ano_matricula;
    char curso[3];
    char regime[MAX];
    int special_permission;
    Aluno newAluno;
    printf("\nInsira o numero do aluno:");
    scanf("%d",&num_aluno);
    printf("\nInsira o curso a que pertence");
    scanf("%s",&curso);
    /*if( curso!="LEI"|| curso != "LDM" ){
        printf("\nCurso invalido, saindo.");
        exit;
    }*/
    printf("\nInsira o número da matricula:");
    scanf("%d", &ano_matricula);
    printf("\nInsira o regime em que o aluno estuda:");
    scanf("%s", &regime);
    printf("\nTem permissão para especial? (0 se não tiver , 1 se tiver)\n");
    scanf("%d",&special_permission);
    /*if(special_permission!=0 && special_permission!= 1){
        printf("\nPermissao invalida");
        exit;
    }*/
    newAluno.num_aluno = num_aluno;
    strcpy(newAluno.regime,regime);
    strcpy(newAluno.curso,curso);
    newAluno.ano_matricula = ano_matricula;
    newAluno.special_permission = special_permission;
    printf("Teste %d",newAluno.ano_matricula);
    insere_fim_lista_aluno(listaAluno, newAluno);
    /*dar append na lista ligada de alunos e + e segue*/
    printf("\nAluno Criado com sucesso!\n");
    return;
}

void new_disc(){
    char nome[MAX];
    char docente_resp[MAX];
    printf("\nInsira o nome da Disciplina:\n");
    scanf("%s",&nome);
    printf("\nInsira o nome do docente responsável:\n");
    scanf("%s",&docente_resp);
    struct disciplinas newDisc;
    strcpy(newDisc.nome,nome);
    strcpy(newDisc.docente_resp,docente_resp);
    return;
}

void new_exam(){
    char disciplina[MAX];
    char epoca[MAX];
    char sala[MAX];
    printf("\nInsira a disciplina a que pertence:");
    scanf("%s",&disciplina);
    printf("\nInsira a epoca do exame:");
    scanf("%s",&epoca);
    printf("\nInsira a sala");
    scanf("%s",&sala);
    struct exame newExam;
    strcpy(newExam.disciplina, disciplina);
    strcpy(newExam.epoca, epoca);
    strcpy(newExam.sala, sala);
    return;
    /*falta a data*/
}

void del_aluno(){
    return;
}

void print_alunos(ListA lista){
    if(lista->next == NULL){
        printf("Não existem alunos");
        exit(0);
    }
    ListA lst = lista->next;
    if(lst== NULL){
        printf("Swag");
    }
    printf("[");
    while(lst){
        printf("%d\t",lst->aluno.ano_matricula);
        lst=lst->next;
    }
    printf("]");
}


void del_disc(){
    return;
}

void list_disc(){
    return;
}

void del_exam(){
    return;
}

void list_exam(){
    return;
}
