#include <stdio.h>
#include <stdlib.h>
#define MAX 99

/*Estruturas*/

typedef struct aluno{
    int num_aluno;
    int ano_matricula;
    char curso[3];
    char regime[MAX];
    int special_permission;/*0 if false & 1 if true*/
}Aluno;

typedef struct data{
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
}Data;

typedef struct disciplinas{
    char nome[MAX];
    char docente_resp[MAX];
}Disciplina;

typedef struct exame{
    char disciplina[MAX];
    char epoca[MAX];
    char sala[MAX];
    int duracao;
    Data data;
}Exame;

/*Listas */

typedef struct lnodeA *ListA;
typedef struct lnodeA {
    Aluno aluno;
    ListA next;
}List_node_aluno;

typedef struct lnodeE *ListE;
typedef struct lnodeE{
    Exame exame;
    ListE next;
}List_node_exame;

typedef struct lnodeD *ListD;
typedef struct lnodeD {
    Disciplina disc;
    ListD next;
}List_node_disc;

/*Criar Listas*/

ListA cria_listaAluno(void){
    ListA aux = (ListA)malloc(sizeof(List_node_aluno));
    if (aux!=NULL){
        aux->next = NULL;
    }
    return aux;
}

ListE cria_listaExam(void){
    ListE aux = (ListE)malloc(sizeof(List_node_exame));
    if (aux!=NULL){
        aux->next = NULL;
    }
    return aux;
}

ListD cria_listaDisc(void){
    ListD aux = (ListD)malloc(sizeof(List_node_disc));
    if (aux!=NULL){
        aux->next = NULL;
    }
    return aux;
}

/*Inserir em listas*/

void insere_fim_lista_aluno(ListA lista, Aluno a){
    ListA lst = (ListA)malloc(sizeof(List_node_aluno));
    ListA aux= lista->next;
    ListA aux2;
    lst->aluno = a;
    if (aux == NULL){
        lista->next = lst;
        lst->next = NULL;
        return;
    }
    while (aux){
        aux2 = aux;
        aux = lista->next;
    }
    lst->next = aux2;
    printf("Teste 2 %d",lst->aluno.ano_matricula);
    aux2 = lst;
}

void insere_fim_lista_disc(ListD lista, Disciplina a){
    ListD lst = (ListD)malloc(sizeof(List_node_disc));
    ListD aux= lista->next;
    ListD aux2;
    lst->disc = a;
    if (aux == NULL){
        lista->next = lst;
        lst->next = NULL;
        return;
    }
    while (aux){
        aux2 = aux;
        aux = lista->next;
    }
    lst->next = aux2;
    printf("Teste 2 %d",lst->disc.nome);
    aux2 = lst;
}
/*
void insereFimLista(ListA lista, Aluno b){
    ListA n;
    n = (ListA)malloc(sizeof(List_node_aluno));
    n->aluno = b;
    n->next = lista->next;
    if (n->next == null){
        lista->next = n;
    }

}
*/


