// EXCLUIR ESPAÇAMENTOS APÓS DIGITAR ALGUM NOME COMPLETO ETC
// nota de bug: caso o nome seja inserido "aBCDEF V" (primeira letra minuscula e outras maiusculas), o programa aceitara

// Funcionalidades implementadas até então
//  inserir professor
//  inserir aluno
//  inserir disciplina
//  exibir professor
//  exibir aluno
//  exibir disciplina

// !!falta funcionalidades de atualizar e excluir!!
// Lembrete: É bom implementar opção de voltar após entrar nas opções de inserir

// !!##criar funções para cada operação de verificação##!! 

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
#define n_alunos 10
#define n_profs 10
#define n_disci 10

struct pessoa
{
    long int matricula;
    char cpf[12];
    int nascimento_dia;
    char cpf_formatado[15];
    int nascimento_mes;
    char nome[max];
    int nascimento_ano;
    char sexo;
};

typedef struct pessoa pessoa;

struct disciplina
{
    char nome[max];
    int semestre;
    char professor[max];
    char codigo[9];
};

typedef struct disciplina disciplina;

int main (void)
{
    pessoa alunos[n_alunos];
    pessoa professores[n_profs];
    disciplina disciplinas[n_disci];
    
    int a_cad = 2, p_cad = 2, d_cad = 2;
    int escolha = 0;
    int tela = 1;
    const int p = 1;
    int espaco = 0;
    const int ano_at = 2023, mes_at = 07, dia_at = 18;
    int continuar = 1;

    // TESTES
        // Alunos 
            // Aluno 1
            strcpy(alunos[0].cpf, "12345678912");
            strcpy(alunos[0].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[0].matricula = 213546789; 
            strcpy(alunos[0].nome, "Aluno Aluno");
            alunos[0].nascimento_dia = 19;
            alunos[0].nascimento_mes = 02;
            alunos[0].nascimento_ano = 1999;
            alunos[0].sexo = 'F';

            // Aluno 2
            strcpy(alunos[1].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[1].matricula = 363546789;
            strcpy(alunos[1].nome, "Aluno Aula");
            alunos[1].nascimento_dia = 07;
            alunos[1].nascimento_mes = 06;
            alunos[1].nascimento_ano = 2002;
            alunos[1].sexo = 'M';

        // Professores
            // Professor 1
            strcpy(professores[0].cpf, "92345678911");
            strcpy(professores[0].cpf_formatado, "xxx.xxx.xxx-xx");
            professores[0].matricula = 373546789;
            strcpy(professores[0].nome, "Professor Prof");
            professores[0].nascimento_dia = 07;
            professores[0].nascimento_mes = 10;
            professores[0].nascimento_ano = 1985;
            professores[0].sexo = 'M';

            // Professor 2
            strcpy(professores[1].cpf_formatado, "xxx.xxx.xxx-xx");
            professores[1].matricula = 835467893;
            strcpy(professores[1].nome, "Prof Proof");
            professores[1].nascimento_dia = 29;
            professores[1].nascimento_mes = 12;
            professores[1].nascimento_ano = 1961;
            professores[1].sexo = 'F';

        // Disciplinas
            // Disciplina 1
            strcpy(disciplinas[0].nome, "Matematica");
            strcpy(disciplinas[0].professor, "Aurelina Franciscalva");
            strcpy(disciplinas[0].codigo, "matpoenb");
            disciplinas[0].semestre = 1;
            
            // Disciplina 2
            strcpy(disciplinas[1].nome, "Programacao");
            strcpy(disciplinas[1].professor, "Aurelino Franciscalvo");
            strcpy(disciplinas[1].codigo, "logpoenb");
            disciplinas[1].semestre = 1;



    // TESTES
    
    while (p == 1)
    {
        while (tela == 1)
        {
            printf("======================\n");
            printf("1 - Cadastro de Alunos\n\n");
            printf("2 - Cadastro de Professores\n\n");
            printf("3 - Cadastro de Disciplinas\n\n");
            printf("4 - Finalizar Programa\n\n");
            printf("======================\n\n");
            printf("Qual deseja acessar?: ");
            scanf("%d", &escolha);
            system("cls");

            switch(escolha)
            {
            case 1:
                tela = 2;
                break;

            case 2:
                tela = 3;
                break;

            case 3:
                tela = 4;
                break;

            case 4:
                printf("Programa finalizado.\n");
                return 0;
                break;
            
            default:
                break;
            }
        }

        while (tela == 2)
        {
            continuar = 1;
            system("cls");
            printf("======================\n1 - Inserir Aluno\n\n2 - Atualizar Aluno\n\n3 - Excluir Aluno\n\n4 - Exibir Alunos\n\n5 - Voltar\n\n----------------------\n----------------------\n\nQual deseja acessar?: ");
            scanf("%d", &escolha);system("cls");

            switch(escolha)
            {
            case 1: // inserir Aluno
                for (int i = a_cad; i < n_alunos && continuar == 1; i++)
                {
                    printf("\n--------Aluno %d--------", a_cad+1);

                    printf("\n\nInsira seu nome: "); fflush(stdin);
                    // fgets(alunos[i].nome, max, stdin); 
                    scanf("%99[^\n]s", alunos[i].nome); fflush(stdin);
                    // strcat(alunos[i].nome, "\0");
                    for (int j = 0; alunos[i].nome[j] != '\0'; j++)
                    {
                        while (!((alunos[i].nome[j] >= 'A' && alunos[i].nome[j] <= 'Z') || (alunos[i].nome[j] >= 'a' && alunos[i].nome[j] <= 'z') || (alunos[i].nome[j] == ' ')))
                        {
                            printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                            // fgets(alunos[i].nome, max, stdin);
                            scanf("%99[^\n]s", alunos[i].nome); fflush(stdin);
                            // strcat(alunos[i].nome, "\0");
                        }
                        if (alunos[i].nome[j] == ' ')
                        {
                            if ((alunos[i].nome[j+1] >= 'A' && alunos[i].nome[j+1] <= 'Z') || (alunos[i].nome[j+1] >= 'a' && alunos[i].nome[j+1] <= 'z'))
                            {
                                espaco++;
                            }
                        }
                    }
                    while (espaco < 1 || alunos[i].nome[0] <'A' || alunos[i].nome[0] > 'Z')
                        {
                            if (alunos[i].nome[0] <'A' || alunos[i].nome[0] > 'Z')
                            {
                                printf("\nSeu nome esta em minusculo!\n\nInsira novamente:  ");
                                // fgets(alunos[i].nome, max, stdin);
                                scanf("%99[^\n]s", alunos[i].nome); fflush(stdin);
                                // strcat(alunos[i].nome, "\0");
                            }
                            for (int j = 0; alunos[i].nome[j] != '\0'; j++)
                            {
                                if (!((alunos[i].nome[j] >= 'A' && alunos[i].nome[j] <= 'Z') || (alunos[i].nome[j] >= 'a' && alunos[i].nome[j] <= 'z') || (alunos[i].nome[j] == ' ')))
                                {
                                    printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                                    // fgets(alunos[i].nome, max, stdin);
                                    scanf("%99[^\n]s", alunos[i].nome); fflush(stdin);
                                    // strcat(alunos[i].nome, "\0");
                                }
                                if (alunos[i].nome[j] == ' ')
                                {
                                    if ((alunos[i].nome[j+1] >= 'A' && alunos[i].nome[j+1] <= 'Z') || (alunos[i].nome[j+1] >= 'a' && alunos[i].nome[j+1] <= 'z'))
                                    {
                                        espaco++;
                                    }
                                }
                                }
                                if (espaco < 1)
                                {
                                    printf("\nVoce deve inserir seu nome completo!\n\nInsira novamente:  ");
                                    
                                    scanf("%99[^\n]s", alunos[i].nome); fflush(stdin);
                                    // strcat(alunos[i].nome, "\0");
                            }
                        }
                    espaco = 0;

                    system("cls");printf("\n--------Aluno %d--------", a_cad+1);
                    
                    printf("\nQual o seu sexo? F (Feminino), M (Masculino): ");
                    scanf("%c", &alunos[i].sexo); fflush(stdin);
                    while (alunos[i].sexo != 'm' && alunos[i].sexo != 'M' && alunos[i].sexo != 'f' && alunos[i].sexo != 'F')
                    {
                        printf("\nSomente as opcoes F (Feminino) e M (Masculino) sao aceitas!\n\nInsira novamente:  ");
                        scanf("%c", &alunos[i].sexo); fflush(stdin);
                    }

                    system("cls");printf("\n--------Aluno %d--------", a_cad+1);

                    fflush(stdin);
                    printf("\nInsira sua data de nascimento DD/MM/AAAA espacando devidamente: ");
                    scanf(" %d%d%d", &alunos[i].nascimento_dia, &alunos[i].nascimento_mes, &alunos[i].nascimento_ano); fflush(stdin);
                    while (alunos[i].nascimento_ano > ano_at || alunos[i].nascimento_mes > 12 || alunos[i].nascimento_mes < 1 || alunos[i].nascimento_dia < 1 || alunos[i].nascimento_dia > 31 || (ano_at - alunos[i].nascimento_ano) > 150)
                    {
                        printf("\n\nData invalida!\n\nInsira Novamente no modo DD/MM/AAAA: ");
                        scanf(" %d%d%d", &alunos[i].nascimento_dia, &alunos[i].nascimento_mes, &alunos[i].nascimento_ano); fflush(stdin);
                    }

                    system("cls");printf("\n--------Aluno %d--------", a_cad+1);
// ALERTA QUANDO ALGUÉM DIGITAR UM VALOR COMO 123 será considerado válido
                    printf("\nInsira sua matricula (9 digitos): ");
                    scanf(" %ld", &alunos[i].matricula); fflush(stdin);
                    for (int j = 0, t1 = 0, t2 = 0, t3 = 0; t1 == 0 || t2 == 0 || t3 == 0; j++)
                    {
                        t1 = 0; t2 = 0; t3 = 0;
                        for(int j = 0; j < a_cad; j++)
                        {
                            
                            if (j == i)j++;
                            if (alunos[i].matricula == alunos[j].matricula)
                            {
                                printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                                scanf(" %ld", &alunos[i].matricula); fflush(stdin);
                            }else t1++;
                            
                        }
                        for(int j = 0; j < p_cad; j++)
                        {
                            if (j == i)j++;
                            if (alunos[i].matricula == professores[j].matricula)
                            {
                                printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                                scanf(" %ld", &alunos[i].matricula); fflush(stdin);
                            }else t2++;
                        }

                        if (alunos[i].matricula <= 0 || alunos[i].matricula > 999999999)
                        {
                            printf("\n\nMatricula invalida!\n\nInsira novamente: ");
                            scanf(" %ld", &alunos[i].matricula); fflush(stdin);
                        }else t3++;
                    }

                    system("cls");printf("\n--------Aluno %d--------", a_cad+1);

                    printf("\n\nInsira seu CPF sem formatacao (11 Digitos): ");
                    scanf(" %s", alunos[i].cpf); fflush(stdin);
                    // strcat(alunos[i].cpf, "\0");
                    
                    for (int j = 0; alunos[i].cpf[j] != '\0'; j++)
                    {
                        if (strlen(alunos[i].cpf) != 11)
                        {
                            printf("\n\nCPF invalido!\n\nInsira novamente: ");
                            scanf(" %s", alunos[i].cpf); fflush(stdin);
                            // strcat(alunos[i].cpf, "\0");
                        }

                        for(int j = 0; j < a_cad; j++)
                        {
                            if (j == i)j++;
                            if (strcmp(alunos[i].cpf, alunos[j].cpf) == 0)
                            {
                                printf("\n\nCPF ja existente!\n\nInsira novamente: ");
                                scanf(" %s", alunos[i].cpf); fflush(stdin);
                                // strcat(alunos[i].cpf, "\0");
                            }
                        }
                        for(int j = 0; j < p_cad; j++)
                        {
                            if (j == i)j++;
                            if (strcmp(alunos[i].cpf, professores[j].cpf) == 0)
                            {
                                printf("\n\nCPF ja existente!\n\nInsira novamente: ");
                                scanf(" %s", alunos[i].cpf); fflush(stdin);
                                // strcat(alunos[i].cpf, "\0");
                            }
                        }
                    }
                    
                    sprintf(alunos[i].cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", alunos[i].cpf[0], alunos[i].cpf[1], 
                    alunos[i].cpf[2], alunos[i].cpf[3], alunos[i].cpf[4], 
                    alunos[i].cpf[5], alunos[i].cpf[6], alunos[i].cpf[7], 
                    alunos[i].cpf[8], alunos[i].cpf[9], alunos[i].cpf[10]);

                    system("cls");

                    int contagem_reg = 3;
                    while (contagem_reg > 0) 
                    {
                        printf("Aluno %d cadastrado com sucesso! Voltando em %d...", a_cad+1, contagem_reg);
                        Sleep(1000);
                        system("cls");
                        contagem_reg--;
                    }

                    a_cad++; // passa para a próxima posição do vetor dizendo que a anterior ja esta ocupada por um cadastro
                    char SeN;
                    printf("Deseja cadastrar mais um aluno? 's' para Sim, 'n' para Nao: ");
                    // scanf("%c", &SeN);
                    SeN = getch();
                    while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
                    {
                        printf("\n\nOpcao invalida. Digite 's' para SIM e 'n' para NAO: ");
                        // scanf("%c", &SeN);
                        SeN = getch();
                    }
                    if (SeN == 'n' || SeN == 'N')
                    {   
                        continuar = 0;
                        system("cls");
                    }
                }
                if (a_cad >= n_alunos)
                {
                    int contagem_reg = 3;
                    while (contagem_reg > 0) 
                    {
                        printf("Limite de alunos atingido! Voltando em %d...", contagem_reg);
                        Sleep(1000);
                        system("cls");
                        contagem_reg--;
                    }
                }
                
                break;

            case 2: // Atualizar aluno
                // Primeiro eu preciso encontrar o aluno com algum dado dele, como matricula (sistema de busca)
                // Segundo eu preciso saber qual informação precisa ser alterada (Selecao com switch case?)
                // Terceiro preciso alterar com uma OPCAO VALIDA e salvar
                // Tambem e preciso ter uma opção de voltar a qualquer momento ou cancelar o que esta sendo feito
                // Talvez uma confirmacao no final perguntando se quer salvar ou nao?
                break;

            case 3:

                printf("1-Place holder\n");
                break;

            case 4: // mostrar Alunos
                for (int i = 0, idade = 0; i < a_cad; i++)
                {
                    printf("--------------Aluno %d--------------", i+1);
                    printf("\n\nNome: ");puts(alunos[i].nome);
                    
                    idade = ano_at - alunos[i].nascimento_ano;
                    if (alunos[i].nascimento_mes >= mes_at){
                        if (alunos[i].nascimento_mes > mes_at) idade -= 1;
                        if (alunos[i].nascimento_mes == mes_at){
                            if (alunos[i].nascimento_dia > dia_at) idade -= 1;}}
                    printf("\nData de Nascimento: %02d/%02d/%d\n\nIdade: %d anos", alunos[i].nascimento_dia, alunos[i].nascimento_mes, alunos[i].nascimento_ano, idade);

                    if (alunos[i].sexo == 'M' || alunos[i].sexo == 'm')
                    {
                        printf("\n\nSexo: Masculino");
                    }else printf("\n\nSexo: Feminino");

                    printf("\n\nMatricula: %ld", alunos[i].matricula);

                    printf("\n\nCPF: %s", alunos[i].cpf_formatado);
                    printf("\n\n");
                }
                system("pause");
                break;

            case 5:
                tela = 1;
                break;
            
            default:
                break;
            }
        }
        
        while (tela == 3)
        {
            system("cls");
            printf("======================\n1 - Inserir Professor\n\n2 - Atualizar Professor\n\n3 - Excluir Professor\n\n4 - Exibir Professores\n\n5 - Voltar\n\n----------------------\n----------------------\n\nQual deseja acessar?: ");
            scanf("%d", &escolha);system("cls");

            switch(escolha)
            {
            case 1: // inserir professor
                for (int i = a_cad; i < n_profs && continuar == 1; i++)
                {
                    printf("\n--------Professor %d--------", a_cad+1);

                    printf("\n\nInsira seu nome: "); fflush(stdin);
                    // fgets(professores[i].nome, max, stdin); 
                    scanf("%99[^\n]s", professores[i].nome); fflush(stdin);
                    // strcat(professores[i].nome, "\0");
                    for (int j = 0; professores[i].nome[j] != '\0'; j++)
                    {
                        while (!((professores[i].nome[j] >= 'A' && professores[i].nome[j] <= 'Z') || (professores[i].nome[j] >= 'a' && professores[i].nome[j] <= 'z') || (professores[i].nome[j] == ' ')))
                        {
                            printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                            // fgets(professores[i].nome, max, stdin);
                            scanf("%99[^\n]s", professores[i].nome); fflush(stdin);
                            // strcat(professores[i].nome, "\0");
                        }
                        if (professores[i].nome[j] == ' ')
                        {
                            if ((professores[i].nome[j+1] >= 'A' && professores[i].nome[j+1] <= 'Z') || (professores[i].nome[j+1] >= 'a' && professores[i].nome[j+1] <= 'z'))
                            {
                                espaco++;
                            }
                        }
                    }
                    while (espaco < 1 || professores[i].nome[0] <'A' || professores[i].nome[0] > 'Z')
                        {
                            if (professores[i].nome[0] <'A' || professores[i].nome[0] > 'Z')
                            {
                                printf("\nSeu nome esta em minusculo!\n\nInsira novamente:  ");
                                // fgets(professores[i].nome, max, stdin);
                                scanf("%99[^\n]s", professores[i].nome); fflush(stdin);
                                // strcat(professores[i].nome, "\0");
                            }
                            for (int j = 0; professores[i].nome[j] != '\0'; j++)
                            {
                                if (!((professores[i].nome[j] >= 'A' && professores[i].nome[j] <= 'Z') || (professores[i].nome[j] >= 'a' && professores[i].nome[j] <= 'z') || (professores[i].nome[j] == ' ')))
                                {
                                    printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                                    // fgets(professores[i].nome, max, stdin);
                                    scanf("%99[^\n]s", professores[i].nome); fflush(stdin);
                                    // strcat(professores[i].nome, "\0");
                                }
                                if (professores[i].nome[j] == ' ')
                                {
                                    if ((professores[i].nome[j+1] >= 'A' && professores[i].nome[j+1] <= 'Z') || (professores[i].nome[j+1] >= 'a' && professores[i].nome[j+1] <= 'z'))
                                    {
                                        espaco++;
                                    }
                                }
                                }
                                if (espaco < 1)
                                {
                                    printf("\nVoce deve inserir seu nome completo!\n\nInsira novamente:  ");
                                    
                                    scanf("%99[^\n]s", professores[i].nome); fflush(stdin);
                                    // strcat(professores[i].nome, "\0");
                            }
                        }
                    espaco = 0;

                    system("cls");printf("\n--------Professor %d--------", a_cad+1);
                    
                    printf("\nQual o seu sexo? F (Feminino), M (Masculino): ");
                    scanf("%c", &professores[i].sexo); fflush(stdin);
                    while (professores[i].sexo != 'm' && professores[i].sexo != 'M' && professores[i].sexo != 'f' && professores[i].sexo != 'F')
                    {
                        printf("\nSomente as opcoes F (Feminino) e M (Masculino) sao aceitas!\n\nInsira novamente:  ");
                        scanf("%c", &professores[i].sexo); fflush(stdin);
                    }

                    system("cls");printf("\n--------Professor %d--------", a_cad+1);

                    fflush(stdin);
                    printf("\nInsira sua data de nascimento DD/MM/AAAA espacando devidamente: ");
                    scanf(" %d%d%d", &professores[i].nascimento_dia, &professores[i].nascimento_mes, &professores[i].nascimento_ano); fflush(stdin);
                    while (professores[i].nascimento_ano > ano_at || professores[i].nascimento_mes > 12 || professores[i].nascimento_mes < 1 || professores[i].nascimento_dia < 1 || professores[i].nascimento_dia > 31 || (ano_at - professores[i].nascimento_ano) > 150)
                    {
                        printf("\n\nData invalida!\n\nInsira Novamente no modo DD/MM/AAAA: ");
                        scanf(" %d%d%d", &professores[i].nascimento_dia, &professores[i].nascimento_mes, &professores[i].nascimento_ano); fflush(stdin);
                    }

                    system("cls");printf("\n--------Professor %d--------", a_cad+1);

                    printf("\nInsira sua matricula (9 digitos): ");
                    scanf(" %ld", &professores[i].matricula); fflush(stdin);
                    for (int j = 0, teste = 0; teste == 0; j++)
                    {
                        for(int j = 0; j < a_cad; j++)
                        {
                            if (j == i)j++;
                            if (alunos[i].matricula == alunos[j].matricula)
                            {
                                printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                                scanf(" %ld", &professores[i].matricula); fflush(stdin);
                            }
                            
                        }
                        for(int j = 0; j < p_cad; j++)
                        {
                            if (j == i)j++;
                            if (professores[i].matricula == alunos[j].matricula)
                            {
                                printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                                scanf(" %ld", &professores[i].matricula); fflush(stdin);
                            }
                        }

                        if (professores[i].matricula <= 0 || professores[i].matricula > 999999999)
                        {
                            printf("\n\nMatricula invalida!\n\nInsira novamente: ");
                            scanf(" %ld", &professores[i].matricula); fflush(stdin);
                        }
                    }
                    
                    system("cls");printf("\n--------Professor %d--------", a_cad+1);

                    printf("\n\nInsira seu CPF sem formatacao (11 Digitos): ");
                    scanf(" %s", professores[i].cpf); fflush(stdin);
                    // strcat(professores[i].cpf, "\0");
                    
                    for (int j = 0; professores[i].cpf[j] != '\0'; j++)
                    {
                        if (strlen(professores[i].cpf) != 11)
                        {
                            printf("\n\nCPF invalido!\n\nInsira novamente: ");
                            scanf(" %s", professores[i].cpf); fflush(stdin);
                            // strcat(professores[i].cpf, "\0");
                        }
                        
                        for(int j = 0; j < p_cad; j++)
                        {
                            if (j == i)j++;
                            if (strcmp(professores[i].cpf, professores[j].cpf) == 0)
                            {
                                printf("\n\nCPF ja existente!\n\nInsira novamente: ");
                                scanf(" %s", professores[i].cpf); fflush(stdin);
                                // strcat(professores[i].cpf, "\0");
                            }
                        }
                        for(int j = 0; j < a_cad; j++)
                        {
                            if (j == i)j++;
                            if (strcmp(professores[i].cpf, alunos[j].cpf) == 0)
                            {
                                printf("\n\nCPF ja existente!\n\nInsira novamente: ");
                                scanf(" %s", professores[i].cpf); fflush(stdin);
                                // strcat(professores[i].cpf, "\0");
                            }
                        }
                    }
                    
                    sprintf(professores[i].cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", professores[i].cpf[0], professores[i].cpf[1], 
                    professores[i].cpf[2], professores[i].cpf[3], professores[i].cpf[4], 
                    professores[i].cpf[5], professores[i].cpf[6], professores[i].cpf[7], 
                    professores[i].cpf[8], professores[i].cpf[9], professores[i].cpf[10]);

                    system("cls");

                    int contagem_reg = 3;
                    while (contagem_reg > 0) 
                    {
                        printf("Professor %d cadastrado com sucesso! Voltando em %d...", a_cad+1, contagem_reg);
                        Sleep(1000);
                        system("cls");
                        contagem_reg--;
                    }

                    p_cad++; // passa para a próxima posição do vetor dizendo que a anterior ja esta ocupada por um cadastro

                    printf("Deseja cadastrar mais um professor? 1 para Sim, 0 para Nao: ");
                    scanf("%d", &continuar);
                    while (continuar != 1 && continuar != 0)
                    {
                        printf("\n\nOpcao invalida. Digite 1 para SIM e 0 para NAO: ");
                        scanf("%d", &continuar);
                    }
                }
                if (p_cad >= n_profs)
                {
                    int contagem_reg = 3;
                    while (contagem_reg > 0) 
                    {
                        printf("Limite de professores atingido! Voltando em %d...", contagem_reg);
                        Sleep(1000);
                        system("cls");
                        contagem_reg--;
                    }
                }
                continuar = 1;
                break;

            case 2:
                printf("1-Place holder\n");
                break;

            case 3:

                printf("1-Place holder\n");
                break;

            case 4: // Mostrar professor
                for (int i = 0, idade = 0; i < p_cad; i++)
                {
                    printf("--------------Professor %d--------------", i+1);
                    printf("\n\nNome: "); puts(professores[i].nome);
                    
                    idade = ano_at - professores[i].nascimento_ano;
                    if (professores[i].nascimento_mes >= mes_at){
                        if (professores[i].nascimento_mes > mes_at) idade -= 1;
                        if (professores[i].nascimento_mes == mes_at){
                            if (professores[i].nascimento_dia > dia_at) idade -= 1;}}
                    printf("\nData de Nascimento: %02d/%02d/%d\n\nIdade: %d anos", professores[i].nascimento_dia, professores[i].nascimento_mes, professores[i].nascimento_ano, idade);

                    if (professores[i].sexo == 'M' || professores[i].sexo == 'm')
                    {
                        printf("\n\nSexo: Masculino");
                    }else printf("\n\nSexo: Feminino");

                    printf("\n\nMatricula: %ld", professores[i].matricula);

                    printf("\n\nCPF: %s", professores[i].cpf_formatado);
                    printf("\n\n");
                }
                system("pause");
                break;

            case 5:
                tela = 1;
                break;
            
            default:
                break;
            }
        }

        while (tela == 4)
        {
            system("cls");
            printf("======================\n1 - Inserir Disciplina\n\n2 - Atualizar Disciplina\n\n3 - Excluir Disciplina\n\n4 - Exibir Disciplinas\n\n5 - Voltar\n\n----------------------\n----------------------\n\nQual deseja acessar?: ");
            scanf("%d", &escolha);system("cls");

            switch(escolha)
            {
            case 1: // Inserir disciplina
                for (int i = 0; i < d_cad && continuar == 1; i++)
                {
                    printf("\n--------Disciplina %d--------", d_cad+1);

                    printf("\n\nInsira o nome da disciplina: "); fflush(stdin);
                    scanf("%99[^\n]s", disciplinas[i].nome); fflush(stdin);
                    // strcat(disciplinas[i].nome, "\0");

                    for (int j = 0; j < n_disci; j++)
                    {
                        if (i == j)j++;
                        if (strcmp(disciplinas[i].nome, disciplinas[j].nome) == 0)
                        {
                            printf("\n\nNome ja existente!\n\nInsira novamente: ");
                            scanf("%99[^\n]s", disciplinas[i].nome); fflush(stdin);
                            // strcat(disciplinas[i].nome, "\0");
                        }
                        while (disciplinas[i].nome[0] <'A' || disciplinas[i].nome[0] > 'Z')
                        {
                        if (disciplinas[i].nome[0] <'A' || disciplinas[i].nome[0] > 'Z')
                        {
                            printf("\nA primeira letra esta em minusculo!\n\nInsira novamente:  ");
                            scanf("%99[^\n]s", disciplinas[i].nome); fflush(stdin);
                            // strcat(disciplinas[i].nome, "\0");
                        }
                        for (int j = 0; disciplinas[i].nome[j] != '\0'; j++)
                        {
                        if (!((disciplinas[i].nome[j] >= 'A' && disciplinas[i].nome[j] <= 'Z') || (disciplinas[i].nome[j] >= 'a' && disciplinas[i].nome[j] <= 'z') || (disciplinas[i].nome[j] == ' ')))
                        {
                            printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                            scanf("%99[^\n]s", disciplinas[i].nome); fflush(stdin);
                            // strcat(disciplinas[i].nome, "\0");
                        }
                        }
                        }
                    }

                    system("cls");printf("\n--------Disciplina %d--------", d_cad+1);

                    printf("\n\nInsira o codigo da disciplina 8 digitos: "); fflush(stdin);
                    scanf("%8[^\n]s", disciplinas[i].codigo); fflush(stdin);
                    // strcat(disciplinas[i].codigo, "\0");

                    for (int j = 0; j < n_disci; j++)
                    {
                        if (strlen(disciplinas[i].codigo) != 8)
                        {
                            printf("\n\nO codigo precisa ter 8 digitos.\n\nInsira novamente: ");
                            scanf("%8[^\n]s", disciplinas[i].codigo); fflush(stdin);
                            // strcat(disciplinas[i].codigo, "\0");
                        }

                        for (int j = 0; j < d_cad; j++)
                        {
                            if (i == j)j++;
                            if (strcmp(disciplinas[i].codigo, disciplinas[j].codigo) == 0)
                            {
                                printf("\n\nCodigo ja existente!\n\nInsira novamente: ");
                                scanf(" %s", disciplinas[i].codigo); fflush(stdin);
                                // strcat(disciplinas[i].codigo, "\0");
                            }
                        }
                    }

                    system("cls");printf("\n--------Disciplina %d--------", d_cad+1);
                
                    printf("\n\nInsira o nome do professor da disciplina de %s: ", disciplinas[i].nome); fflush(stdin);
                    scanf("%99[^\n]s", disciplinas[i].professor); fflush(stdin);
                    // strcat(disciplinas[i].professor, "\0");

                    for (int j = 0; j < p_cad; j++)
                    {
                        while (strcmp(disciplinas[i].professor, professores[j].nome) != 0)
                        {
                            printf("\n\nProfessor nao existe.\n\nInsira novamente: ");
                            scanf("%99[^\n]s", disciplinas[i].professor); fflush(stdin);
                            // strcat(disciplinas[i].professor, "\0");
                        }
                    }

                    system("cls");printf("\n--------Disciplina %d--------", d_cad+1);

                    printf("\n\nInsira o semestre da disciplina. Ex: 1, 2, 3... : "); fflush(stdin);
                    scanf("%d", &disciplinas[i].semestre); fflush(stdin);

                    while (disciplinas[i].semestre < 1 || disciplinas[i].semestre > 14)
                    {
                        printf("\n\nOpcao invalida!\nInsira novamente: "); fflush(stdin);
                        scanf("%d", &disciplinas[i].semestre); fflush(stdin);
                    }

                    int contagem_reg = 3;
                    while (contagem_reg > 0) 
                    {
                        printf("Disciplina %d cadastrada com sucesso! Voltando em %d...", a_cad+1, contagem_reg);
                        Sleep(1000);
                        system("cls");
                        contagem_reg--;
                    }

                    d_cad++;

                    printf("Deseja cadastrar mais uma Disciplina? 1 para Sim, 0 para Nao: ");
                    scanf("%d", &continuar);
                    while (continuar != 1 && continuar != 0)
                    {
                        printf("\n\nOpcao invalida. Digite 1 para SIM e 0 para NAO: ");
                        scanf("%d", &continuar);
                    }
                }
                if (d_cad >= n_disci)
                {
                    int contagem_reg = 3;
                    while (contagem_reg > 0) 
                    {
                        printf("Limite de disciplinas atingido! Voltando em %d...", contagem_reg);
                        Sleep(1000);
                        system("cls");
                        contagem_reg--;
                    }
                }
                continuar = 1;
                break;

            case 2:
                printf("1-Place holder\n");
                break;

            case 3:

                printf("1-Place holder\n");
                break;

            case 4: // Exibir disciplinas
                for (int i = 0; i < d_cad; i++)
                {
                    printf("--------------Disciplina %d--------------", i+1);
                    printf("\n\nNome: "); puts(disciplinas[i].nome);
                    
                    printf("\nCodigo: %s", disciplinas[i].codigo);

                    printf("\n\nProfessor: "); puts(disciplinas[i].professor);

                    printf("\nSemestre: %d", disciplinas[i].semestre);
                    printf("\n\n");
                }
                system("pause");
                break;

            case 5:
                tela = 1;
                break;
            
            default:
                break;
            }
        }
    }
    return 0;
}