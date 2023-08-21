  // Funcionalidades implementadas até então
  //  Inserir professor
  //  Inserir aluno
  //  Inserir disciplina
  //  Exibir professor
  //  Exibir aluno
  //  Exibir disciplina
  
  //  Problemas notados e funcionalidades a implementar:
  //-1 - Programa quebra ao inserir letra em alguns menus Switch Case
  // 0 - Usar doppelganger no cadastro pessoa;
  // 1 - Verificação de professor existente para disciplina parou de funcionar (pedir matricula ao inves de nome)
  // 2 - Melhorar a legibilidade do código/Modularizar mais
  // 3 - Excesso de laços desnecessários?
  // 4 - Fazer um vetor dentro de uma função e passar para a matriz original somente se tudo der certo
  // 5 - Opção de voltar é atualizar, voltar tudo é excluir
  // 6 - Se ater ao projeto principal e se preocupar com essas funcionalidades depois

  // !!falta funcionalidades de atualizar e excluir!!
  // Lembrete: implementar opção de voltar após entrar nas opções de inserir
  // criar funções para cada operação de verificação?
  
  // EXCLUIR ESPAÇAMENTOS APÓS DIGITAR ALGUM NOME COMPLETO ETC
  // nota de bug: caso o nome seja inserido "aBCDEF V" (primeira letra minuscula e outras maiusculas), o programa aceita
  
  // Atualizar aluno
  // Primeiro eu preciso encontrar o aluno com algum dado dele, como matricula (sistema de busca)
  // Segundo eu preciso saber qual informação precisa ser alterada (Selecao com switch case?)
  // Terceiro preciso alterar com uma OPCAO VALIDA e salvar
  // Tambem e preciso ter uma opção de voltar a qualquer momento ou cancelar o que esta sendo feito
  // Talvez uma confirmacao no final perguntando se quer salvar ou nao?
  
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  
  #define max 100
  #define n_alunos 4
  #define n_profs 3
  #define n_disci 3
  
  #define cad_a_sucesso -1
  #define cad_invalido -2
  
  typedef struct pessoa
  {
    long int matricula;
    char cpf[12];
    int nascimento_dia;
    char cpf_formatado[15];
    int nascimento_mes;
    char nome[max];
    int nascimento_ano;
    char sexo;
  }  pessoa;
  
  typedef struct disciplina
  {
    char nome[max];
    int semestre;
    char codigo[9];
    long int matriculaProfessor;
    
  }  disciplina;
  
  int menuPrincipal();

  int menuAtualizar();

  int menuExibicao();


  void listarPorSexo(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at);

  void listarOrdemABC();

  void listarNascimento();

//   int buscaPessoa();


  int cadastrar(pessoa pessoa_main[], int a_cad, pessoa pessoa_comp[], int p_cad, int windows, int ano_at, int aluno, int* continuar, int i, int escolha_att);

  int procurarPessoa(int aluno, long int matricula, pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int a_cad);

  void mostrarUmaPessoa(pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int i);

  void exibirPessoa(int aluno, int a_cad);

  int excluirPessoa(pessoa alvoExclusao[], int posicaoVetor, int a_cad);
  
  
  int menuAlunos();

  void exibirAlunos(pessoa alunos[], int a_cad, int ano_at, int mes_at, int dia_at);
  
  
  int menuProfessores();
  
  void exibirProfessores(pessoa professores[], int p_cad, int ano_at, int mes_at, int dia_at);
  
  
  int menuDisciplinas();
  
  int cadastrarDrisciplina(disciplina disciplinas[], int d_cad, pessoa professores[], int p_cad, int windows);
  
  void exibirDisciplinas(disciplina disciplinas[], int d_cad, pessoa professores[], int p_cad, int windows);

  int procurarDisciplina(disciplina disciplinaBuscada[], char codigo[], int d_cad);
  
  // int atualizarDisciplina();
  
  // int excluirDisciplina();
  
  
  void limparTela(int windows);
  
  void limparBuffer();
  
  void delay(long int secs);
  
  void pressKey();

  void fixQuebraLinhaFgets(char alvo[]);
  
  
  int main (void)
  {
    // DEFINIR SISTEMA
    int windows = 0;
    pessoa alunos[n_alunos];
    pessoa professores[n_profs];
    disciplina disciplinas[n_disci];

    // Data/hora

    struct tm *data_hora_atual;

    time_t segundos;

    time(&segundos);

    data_hora_atual = localtime(&segundos);

    int ano_at = data_hora_atual -> tm_year + 1900;
    int mes_at = data_hora_atual -> tm_mon + 1;
    int dia_at = data_hora_atual -> tm_mday;

    // Data/hora

    int a_cad = 2, p_cad = 2, d_cad = 2;
    int escolha = -1;
    int aluno = -1;
    int opcao = 0;
    int continuar;
  
    // TESTES
        // Alunos 
            // Aluno 1
            strcpy(alunos[0].cpf, "12345678912");
            strcpy(alunos[0].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[0].matricula = 213546789; 
            strcpy(alunos[0].nome, "Pedro Albuquerque");
            alunos[0].nascimento_dia = 19;
            alunos[0].nascimento_mes = 2;
            alunos[0].nascimento_ano = 1999;
            alunos[0].sexo = 'F';
  
            // Aluno 2
            strcpy(alunos[1].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[1].matricula = 363546789;
            strcpy(alunos[1].nome, "Pedro Pascal");
            alunos[1].nascimento_dia = 7;
            alunos[1].nascimento_mes = 6;
            alunos[1].nascimento_ano = 2002;
            alunos[1].sexo = 'M';
  
        // Professores
            // Professor 1
            strcpy(professores[0].cpf, "92345678911");
            strcpy(professores[0].cpf_formatado, "xxx.xxx.xxx-xx");
            professores[0].matricula = 373546789;
            strcpy(professores[0].nome, "Professor Prof");
            professores[0].nascimento_dia = 7;
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
            disciplinas[0].matriculaProfessor = 373546789;
            strncpy(disciplinas[0].codigo, "matpoenb", sizeof(disciplinas[0].codigo) - 1);
            disciplinas[0].semestre = 1;
            
            // Disciplina 2
            strcpy(disciplinas[1].nome, "Programacao");
            disciplinas[1].matriculaProfessor = 835467893;
            strncpy(disciplinas[1].codigo, "logpoenb", sizeof(disciplinas[1].codigo) - 1);
            disciplinas[1].semestre = 1;
    // TESTES
    
      limparTela(windows);
      int sair = 0;
      while (!sair)
      {
          printf("Menu Principal\n");
          escolha = menuPrincipal();
  
          limparTela(windows);
  
          switch (escolha) 
          {
              case 0:
              {
                  printf("Programa finalizado.\n");
                  sair = 1;
              }
              break;
    
              case 1:
              {
                  int sairAluno = 0;
                  int escolha_aluno;
  
                  limparTela(windows);
                  
                  while(!sairAluno)
                  {
                      printf("Modulo de Alunos\n");
                      escolha_aluno = menuAlunos();
                      aluno = 1;
  
                      switch(escolha_aluno)
                      {
                          case 0:
                          {
                              sairAluno = 1;
                              limparTela(windows);
                          }
                          break;
                          
                          case 1:
                          {
                            limparTela(windows);
                            continuar = 1;
                            int i = a_cad;

                            while (i < n_alunos && continuar && a_cad < n_alunos)
                            {
                                limparTela(windows);
                                a_cad = cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, i, opcao);
                                i = a_cad;
                            }
                            
                            if (a_cad >= n_alunos && continuar)
                            {
                                int contagem_reg = 3;
                                while (contagem_reg > 0) 
                                {
                                    printf("Limite de cadastros atingido! Voltando em %d...", contagem_reg);
                                    delay(1);
                                    limparTela(windows);
                                    contagem_reg--;
                                }
                            }
                          }
                          break;
  
                          case 2:
                          {
                            limparTela(windows);
                            long int matricula = 0;

                            printf("Digite a Matricula do Aluno que Deseja Atualizar: ");
                            scanf("%ld", &matricula);
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Aluno nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                scanf("%d", &tentarNovamente);
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    scanf("%d", &tentarNovamente);
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Aluno que Deseja Atualizar: ");
                                    scanf("%ld", &matricula);
                                    retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }

                                int sairAtualizar = 0;
                                int escolha_att;
                                while (!sairAtualizar && retorno != -2 && retorno != -1)
                                {
                                    limparTela(windows);
                                    printf("Menu de Atualizar\n");
                                    escolha_att = menuAtualizar();
                                    switch (escolha_att)
                                        {
                                        case 0:
                                            sairAtualizar = 1;
                                            limparTela(windows);
                                            break;

                                        case 1:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        case 2:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 3:
                                            limparTela(windows);
                                            continuar = 1;
                                            
                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 4:
                                            limparTela(windows);
                                            continuar = 1;
                                            
                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 5:
                                            limparTela(windows);
                                            continuar = 1;
                                            
                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        default:
                                            break;
                                        }
                                }
                            
                              
                            limparTela(windows);
                          }
                          break;
  
                          case 3:
                          {
                            int sair_e_aluno = 0;
                            int escolha_e_aluno;
                            while (!sair_e_aluno)
                            {
                                limparTela(windows);
                                printf("Exibicao Alunos\n");
                                escolha_e_aluno = menuExibicao();
                                switch (escolha_e_aluno)
                                {
                                    case 0:
                                    {
                                        sair_e_aluno = 1;
                                        limparTela(windows);
                                    }
                                        break;

                                    case 1:
                                    {
                                        limparTela(windows);

                                        exibirAlunos(alunos, a_cad, ano_at, mes_at, dia_at);

                                        limparTela(windows);
                                    }
                                        break;
                                        
                                    case 2:
                                    {
                                        
                                    }
                                        break;
                                        
                                    case 3:
                                    {
                                        limparTela(windows);

                                        listarPorSexo(aluno, alunos, a_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }  
                                        break;
                                    
                                    case 4:
                                    {
                                        limparTela(windows);

                                        listarOrdemABC(aluno, alunos, a_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }

                                    case 5:
                                    {
                                        limparTela(windows);
                                        listarNascimento(aluno, alunos, a_cad, dia_at, mes_at, ano_at);
                                        limparTela(windows);
                                    }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            
                            
                            limparTela(windows);

                          }
                          break;
                          
                          case 4:
                          {
                            limparTela(windows);
                            long int matricula = 0;

                            while (1)
                            {
                                char exibir;
                                limparBuffer();
                                printf("Deseja exibir os alunos? S/N: ");
                                scanf("%c", &exibir);
                                if (exibir == 's' || exibir == 'S')
                                {
                                    exibirAlunos(alunos, a_cad, ano_at, mes_at, dia_at);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }

                            printf("\n\nDigite a Matricula do Aluno que Deseja Excluir: ");
                            scanf("%ld", &matricula);
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Aluno nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                scanf("%d", &tentarNovamente);
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    scanf("%d", &tentarNovamente);
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Aluno que Deseja Excluir: ");
                                    scanf("%ld", &matricula);
                                    retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }
                              limparTela(windows);
                            
                              a_cad = excluirPessoa(alunos, retorno, a_cad);

                              limparTela(windows);
                          }
                          break;
  
                          default:
                          {
                              limparTela(windows);
                          }
                          break;
                      }
                  }
              limparTela(windows);
              }
              break;


            
    
              case 2:
              {
                  int sairProf = 0;
                  int escolha_prof;
                  int aluno = 0;
  
                  limparTela(windows);
                  
                  while (!sairProf)
                  {
                      printf("Modulo de Professores\n");
                      escolha_prof = menuProfessores();
  
                      switch(escolha_prof)
                      {
                          case 0:
                          {
                              sairProf = 1;
                              limparTela(windows);
                          }
                          break;
                          
                          case 1:
                          {
                            limparTela(windows);

                            int continuar = 1;
                            int i = p_cad;

                            while (i < n_profs && continuar && p_cad < n_profs)
                            {
                                limparTela(windows);
                                p_cad = cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, i, opcao);
                                i = p_cad;
                            }
                            
                            if (p_cad >= n_profs && continuar)
                            {
                                int contagem_reg = 3;
                                while (contagem_reg > 0) 
                                {
                                    printf("Limite de cadastros atingido! Voltando em %d...", contagem_reg);
                                    delay(1);
                                    limparTela(windows);
                                    contagem_reg--;
                                }
                            }
                          }
                          break;
  
                          case 2:
                          {
                            limparTela(windows);
                            long int matricula = 0;

                            while (1)
                            {   
                                char exibir;
                                limparBuffer();
                                printf("Deseja exibir os professores? S/N: ");
                                scanf("%c", &exibir);
                                if (exibir == 's' || exibir == 'S')
                                {
                                    aluno = 0;
                                    exibirProfessores(professores, p_cad, ano_at, mes_at, dia_at);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }

                            exibirProfessores(professores, p_cad, ano_at, mes_at, dia_at);
                            printf("\n\nDigite a Matricula do Professor que Deseja Atualizar: ");
                            scanf("%ld", &matricula);
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Professor nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                scanf("%d", &tentarNovamente);
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    scanf("%d", &tentarNovamente);
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Professor que Deseja Atualizar: ");
                                    scanf("%ld", &matricula);
                                    retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }

                                int sairAtualizar = 0;
                                int escolha_att;
                                while (!sairAtualizar && retorno != -2 && retorno != -1)
                                {
                                    limparTela(windows);
                                    printf("Menu de Atualizar\n");
                                    escolha_att = menuAtualizar();
                                    switch (escolha_att)
                                        {
                                        case 0:
                                            sairAtualizar = 1;
                                            limparTela(windows);
                                            break;

                                        case 1:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        case 2:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 3:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 4:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 5:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        default:
                                            break;
                                        }
                                }
                            
                              
                            limparTela(windows);
                          }
                          break;
  
                          case 3:
                          {
                            int sair_e_prof = 0;
                            int escolha_e_prof;
                            while (!sair_e_prof)
                            {
                                limparTela(windows);
                                printf("Exibicao Professores\n");
                                escolha_e_prof = menuExibicao();
                                switch (escolha_e_prof)
                                {
                                    case 0:
                                    {
                                        sair_e_prof = 1;
                                        limparTela(windows);
                                    }
                                        break;

                                    case 1:
                                    {
                                        limparTela(windows);
                                        exibirProfessores(professores, p_cad, ano_at, mes_at, dia_at);
                                        limparTela(windows);
                                    }
                                        break;
                                        
                                    case 2:
                                    {

                                    }
                                        break;
                                        
                                    case 3:
                                    {
                                        limparTela(windows);
                                        listarPorSexo(aluno, professores, p_cad, dia_at, mes_at, ano_at);
                                        limparTela(windows);
                                    }  
                                        break;
                                    
                                    case 4:
                                    {
                                        limparTela(windows);

                                        listarOrdemABC(aluno, professores, p_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }

                                    case 5:
                                    {
                                        limparTela(windows);
                                        listarNascimento(aluno, professores, p_cad, dia_at, mes_at, ano_at);
                                        limparTela(windows);
                                    }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                              limparTela(windows);
                          }
                          break;
                          
                          case 4:
                          {
                            limparTela(windows);
                            aluno = 0;
                            long int matricula = 0;

                            printf("Digite a Matricula do Professor que Deseja Excluir: ");
                            scanf("%ld", &matricula);
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Professor nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                scanf("%d", &tentarNovamente);
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    scanf("%d", &tentarNovamente);
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Professor que Deseja Excluir: ");
                                    scanf("%ld", &matricula);
                                    retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }
                              limparTela(windows);

                              p_cad = excluirPessoa(professores, retorno, p_cad);

                              limparTela(windows);
                          }
                          break;
  
                          default:
                          {
                              limparTela(windows);
                          }
                          break;
                      }
                  }
                  limparTela(windows);
              }
              break;
    
              case 3:
              {
                  int sairDisci = 0;
                  int escolha_disci;
  
                  limparTela(windows);
                  
                  while (!sairDisci)
                  {
                      printf("Modulo de Disciplinas\n");
                      escolha_disci = menuDisciplinas();
  
                      switch(escolha_disci)
                      {
                          case 0:
                          {
                              sairDisci = 1;
                              limparTela(windows);
                          }
                          break;
                          
                          case 1:
                          {
                              limparTela(windows);
                              d_cad = cadastrarDrisciplina(disciplinas, d_cad, professores, p_cad, windows);
                              limparTela(windows);
                          }
                          break;
  
                          case 2:
                          {
                              
                              limparTela(windows);
                          }
                          break;
  
                          case 3:
                          {
                              limparTela(windows);
                              exibirDisciplinas(disciplinas, d_cad, professores, p_cad, windows);
                              limparTela(windows);
                          }
                          break;
                          
                          case 4:
                          {
                            limparTela(windows);
                            int retorno;
                            char codigo[9];
                            printf("Digite o Codigo da Discpilina: ");
                            scanf("%s", codigo);
                            retorno = procurarDisciplina(disciplinas, codigo, d_cad);
                            printf ("\nRetorno %d", retorno);
                            pressKey();
                            limparTela(windows);
                          }
                          break;
  
                          default:
                          {
                              limparTela(windows);
                          }
                          break;
                      }
                  }
                  limparTela(windows);
              }
              break;
    
              case 4:
              {
                  
              }
              break;
    
              case 5:
              {
                  
              }
              break;
      
              default:
                  break;
          }
      }
      return 0;
  }
  
  // MENUS
  int menuPrincipal()
  {
      int escolha = -1;
      printf("======================\n\n");
      printf("0 - Sair\n\n");
      printf("1 - Modulo de Alunos\n\n");
      printf("2 - Modulo de Professores\n\n");
      printf("3 - Modulo de Disciplinas\n\n");
      printf("======================\n\n");
  
      printf("Qual deseja acessar?: ");
      scanf("%d", &escolha);
  
      limparBuffer();
  
      return escolha;
  }
  
  
  int menuAlunos()
  {
      int escolha_aluno = -1;
      printf("======================\n\n");
      printf("0 - Voltar\n\n");
      printf("1 - Inserir Alunos\n\n");
      printf("2 - Atualizar Alunos\n\n");
      printf("3 - Exibicao\n\n");
      printf("4 - Excluir Alunos\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      scanf("%d", &escolha_aluno);
  
      return escolha_aluno;
  }

  int menuExibicao()
  {
      int escolha_exibicao = -1;
      printf("======================\n\n");
      printf("0 - Voltar\n\n");
      printf("1 - Ordem Padrao (Ordem de Cadastro)\n\n");
      printf("2 - Buscar por Nome\n\n");
      printf("3 - Ordenar por Sexo\n\n");
      printf("4 - Ordenar por Nome\n\n");
      printf("5 - Ordenar por Nascimento\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      scanf("%d", &escolha_exibicao);
  
      return escolha_exibicao;
  }


  int menuAtualizar()
  {
      int escolha_att = -1;
      printf("======================\n\n");
      printf("0 - Voltar\n\n");
      printf("1 - Atualizar Nome\n\n");
      printf("2 - Atualizar Sexo\n\n");
      printf("3 - Atualizar Data de Nascimento\n\n");
      printf("4 - Atualizar Matricula\n\n");
      printf("5 - Atualizar CPF\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      scanf("%d", &escolha_att);
  
      return escolha_att;
  }
  
  
  int menuProfessores()
  {
      int escolha_prof = -1;
      printf("======================\n\n");
      printf("0 - Voltar\n\n");
      printf("1 - Inserir Professores\n\n");
      printf("2 - Atualizar Professores\n\n");
      printf("3 - Exibicao\n\n");
      printf("4 - Excluir Professores\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      scanf("%d", &escolha_prof);
  
      return escolha_prof;
  }
  
  
  int menuDisciplinas()
  {
      int escolha_disci = -1;
      printf("======================\n\n");
      printf("0 - Voltar\n\n");
      printf("1 - Inserir Disciplinas\n\n");
      printf("2 - Atualizar Disciplinas\n\n");
      printf("3 - Exibir Disciplinas\n\n");
      printf("4 - Excluir Disciplinas\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      scanf("%d", &escolha_disci);
  
      return escolha_disci;
  }
  
  // Funcoes
  
  void limparTela(int windows)
  {
      if (windows)
      {
          system("cls");
      }else system("clear");
  }
  
  
  void delay(long int secs) 
  {
      long int end = time(0) + secs;
      while (time(0) < end);
  }
  
  
  void limparBuffer()
  {
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
  }
  
  
  void pressKey()
  {
      printf("\nPressione qualquer tecla para continuar.");
      limparBuffer();
  }

  
  void fixQuebraLinhaFgets(char alvo[])
  {
    size_t ln = strlen(alvo) -1;
    if (alvo[ln] == '\n')
    alvo[ln] = '\0'; 
  }


  // Funcionalidades
  void listarPorSexo(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at)
  {
    char sexo;
    int verificado = 0;
    printf("Digite 'F' para Feminino e 'M' para Masculino: "); limparBuffer();
    scanf("%c", &sexo);
    while (!verificado)
    {
        if (sexo != 'f' && sexo != 'F' && sexo != 'm' && sexo != 'M')
        {
            printf("\nOpcao invalida. Tente Novamente (F/M): "); limparBuffer();
            scanf("%c", &sexo);
        }
        else 
        {
            verificado = 1;
        }
    }

    limparBuffer();
    
    for (int i = 0; i < cad; i++)
    {
        if (sexo == 'f' || sexo == 'F')
        {
            if (pessoasOrdenar[i].sexo == 'f' || pessoasOrdenar[i].sexo == 'F')
            {
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoasOrdenar, dia_at, mes_at, ano_at, i);
            }
            if (i == (cad-1))
            {
                pressKey();
            }
        }
        else if (sexo == 'm' || sexo == 'M')
        {
            if (pessoasOrdenar[i].sexo == 'm' || pessoasOrdenar[i].sexo == 'M')
            {
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoasOrdenar, dia_at, mes_at, ano_at, i);
            }
            if (i == (cad-1))
            {
                pressKey();
            }
        }
    }
  }


void listarNascimento(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at)
{
    int ordem = -1;
    int verificado = 0;
    pessoa ordenado[cad];
    pessoa chave[1];

    printf("Ordenar por Nascimento\n");
    printf("======================\n\n");
    printf("0 - Voltar\n\n");
    printf("1 - Ordem Crescente\n\n");
    printf("2 - Ordem Decrescente\n\n");
    printf("======================\n\n");

    printf("Como deseja ordenar?: "); limparBuffer();
    scanf("%d", &ordem);

    while (!verificado)
    {
        if (ordem > 2 || ordem < 0)
        {
            printf("\nOpcao invalida. Tente Novamente: "); limparBuffer();
            scanf("%d", &ordem);
        }
        else 
        {
            verificado = 1;
        }
    }

    for (int i = 0; i < cad; i++)
    {
        ordenado[i] = pessoasOrdenar[i];
    }
    

    if (ordem == 1)
    {
         for (int i = 0; i < cad - 1; i++)
        {
            if (ordenado[i].nascimento_ano > ordenado[i+1].nascimento_ano)
            {

                chave[0] = ordenado[i];
                ordenado[i] = ordenado[i+1];
                ordenado[i+1] = chave[0];
            }
            else if (ordenado[i].nascimento_mes > ordenado[i+1].nascimento_mes)
            {
                chave[0] = ordenado[i];
                ordenado[i] = ordenado[i+1];
                ordenado[i+1] = chave[0];
            }
            else if (ordenado[i].nascimento_dia > ordenado[i+1].nascimento_dia)
            {
                chave[0] = ordenado[i];
                ordenado[i] = ordenado[i+1];
                ordenado[i+1] = chave[0];
            }
        }
    }

    if (ordem == 2)
    {
         for (int i = 0; i < cad - 1; i++)
        {
            if (ordenado[i].nascimento_ano < ordenado[i+1].nascimento_ano)
            {
                chave[0] = ordenado[i];
                ordenado[i] = ordenado[i+1];
                ordenado[i+1] = chave[0];
            }
            else if (ordenado[i].nascimento_mes < ordenado[i+1].nascimento_mes)
            {
                chave[0] = ordenado[i];
                ordenado[i] = ordenado[i+1];
                ordenado[i+1] = chave[0];
            }
            else if (ordenado[i].nascimento_dia < ordenado[i+1].nascimento_dia)
            {
                chave[0] = ordenado[i];
                ordenado[i] = ordenado[i+1];
                ordenado[i+1] = chave[0];
            }
        }

    }
    
    if (aluno)
    {
        exibirAlunos(ordenado, cad, ano_at, mes_at, dia_at);   
    }
    if (!aluno)
    {
        exibirProfessores(ordenado, cad, ano_at, mes_at, dia_at);  
    }
}


void listarOrdemABC(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at)
{
    int resultadoCmp;
    pessoa ordenado[cad];
    
    for (int i = 0; i < cad - 1; i++)
    {   
        
        for (int j = i+1; j < cad; j++)
        {
            resultadoCmp = strcmp(pessoasOrdenar[i].nome, pessoasOrdenar[j].nome);

            if (resultadoCmp > 0)
            {
                ordenado[i] = pessoasOrdenar[j];
                strcpy(ordenado[i].nome, pessoasOrdenar[j].nome);

                ordenado[j] = pessoasOrdenar[i];
                strcpy(ordenado[j].nome, pessoasOrdenar[i].nome);
            }
            
            else if (resultadoCmp < 0)
            {
                ordenado[j] = pessoasOrdenar[i];
                strcpy(ordenado[j].nome, pessoasOrdenar[i].nome);
                
                ordenado[i] = pessoasOrdenar[j];
                strcpy(ordenado[i].nome, pessoasOrdenar[j].nome);
            }

            else
            {
                ordenado[i] = pessoasOrdenar[i];
                strcpy(ordenado[i].nome, pessoasOrdenar[i].nome);
                
                ordenado[i] = pessoasOrdenar[i];
                strcpy(ordenado[i].nome, pessoasOrdenar[i].nome);
            }
            
        }
    }

    if (aluno)
    {
        exibirAlunos(ordenado, cad, ano_at, mes_at, dia_at);   
    }
    if (!aluno)
    {
        exibirProfessores(ordenado, cad, ano_at, mes_at, dia_at);  
    }
}

  int procurarPessoa(int aluno, long int matricula, pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int a_cad)
  {
    // Retorno -2 Matricula Invalida
    // Retorno -1 Operacao cancelada
    for (int i = 0; i < a_cad; i++)
    {
        char SeN;

        char SimNao()
        {
            char SeN;
            printf("Deseja Continuar? S/N: ");
            scanf("%c", &SeN);
            while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
            {
                printf("\n\nOpcao invalida. Digite 'S' para SIM e 'N' para NAO: ");
                scanf("%c", &SeN);
            }
            return SeN;
        }

        if (matricula == pessoaBuscada[i].matricula)
        {
            if (aluno)
            {
                printf("Aluno Encontrado!\n\n");
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoaBuscada, dia_at, mes_at, ano_at, i);

                SeN = SimNao();
                if (SeN == 's' || SeN == 'S')
                {
                    return i;
                }
                else if (SeN == 'n' || SeN == 'N')
                {
                    return -1;
                }
            }
            else if (!aluno)
            {
                printf("Professor Encontrado!\n\n");
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoaBuscada, dia_at, mes_at, ano_at, i);

                SeN = SimNao();
                if (SeN == 's' || SeN == 'S')
                {
                    return i;
                }
                else if (SeN == 'n' || SeN == 'N')
                {
                    return -1;
                }
            }
        }
    }

    return -2;
  }

  
  void mostrarUmaPessoa(pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int i)
    {
        int idade;
        printf("\n\nNome: ");puts(pessoaBuscada[i].nome);
        
        idade = ano_at - pessoaBuscada[i].nascimento_ano;
        if (pessoaBuscada[i].nascimento_mes >= mes_at){
            if (pessoaBuscada[i].nascimento_mes > mes_at) idade -= 1;
            if (pessoaBuscada[i].nascimento_mes == mes_at){
                if (pessoaBuscada[i].nascimento_dia > dia_at) idade -= 1;}}
        printf("\nData de Nascimento: %02d/%02d/%d\n\nIdade: %d anos", pessoaBuscada[i].nascimento_dia, pessoaBuscada[i].nascimento_mes, pessoaBuscada[i].nascimento_ano, idade);

        if (pessoaBuscada[i].sexo == 'M' || pessoaBuscada[i].sexo == 'm')
        {
            printf("\n\nSexo: Masculino");
        }else printf("\n\nSexo: Feminino");

        printf("\n\nMatricula: %ld", pessoaBuscada[i].matricula);

        printf("\n\nCPF: %s", pessoaBuscada[i].cpf_formatado);
        printf("\n\n");
    }


  void exibirPessoa(int aluno, int a_cad)
    {
        if (aluno)
        {
            printf("--------Aluno %d--------", a_cad+1);
        }else printf("--------Professor %d--------", a_cad+1);
    }
  

  int cadastrar(pessoa pessoa_main[], int a_cad, pessoa pessoa_comp[], int p_cad, int windows, int ano_at, int aluno, int* continuar, int i, int escolha_att)
  {
    int espaco = 0;

    // pessoa doppelganger[1];

    exibirPessoa(aluno, a_cad);
    
    if (escolha_att == 1 || escolha_att == 0)
    {
        printf("\nInsira seu nome: "); limparBuffer();
        fgets(pessoa_main[i].nome, max, stdin);
        fixQuebraLinhaFgets(pessoa_main[i].nome);
        
        for (int j = 0; pessoa_main[i].nome[j] != '\0'; j++)
        {
            while (!((pessoa_main[i].nome[j] >= 'A' && pessoa_main[i].nome[j] <= 'Z') || (pessoa_main[i].nome[j] >= 'a' && pessoa_main[i].nome[j] <= 'z') || (pessoa_main[i].nome[j] == ' ')))
            {
                printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                fgets(pessoa_main[i].nome, max, stdin);
                fixQuebraLinhaFgets(pessoa_main[i].nome);
            }
            if (pessoa_main[i].nome[j] == ' ')
            {
                if ((pessoa_main[i].nome[j+1] >= 'A' && pessoa_main[i].nome[j+1] <= 'Z') || (pessoa_main[i].nome[j+1] >= 'a' && pessoa_main[i].nome[j+1] <= 'z'))
                {
                    espaco++;
                }
            }
        }
        while (espaco < 1 || pessoa_main[i].nome[0] <'A' || pessoa_main[i].nome[0] > 'Z')
            {
                if (pessoa_main[i].nome[0] <'A' || pessoa_main[i].nome[0] > 'Z')
                {
                    printf("\nSeu nome esta em minusculo!\n\nInsira novamente:  ");
                    fgets(pessoa_main[i].nome, max, stdin);
                    fixQuebraLinhaFgets(pessoa_main[i].nome);
                }
                for (int j = 0; pessoa_main[i].nome[j] != '\0'; j++)
                {
                    if (!((pessoa_main[i].nome[j] >= 'A' && pessoa_main[i].nome[j] <= 'Z') || (pessoa_main[i].nome[j] >= 'a' && pessoa_main[i].nome[j] <= 'z') || (pessoa_main[i].nome[j] == ' ')))
                    {
                        printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                        fgets(pessoa_main[i].nome, max, stdin);
                        fixQuebraLinhaFgets(pessoa_main[i].nome);
                    }
                    if (pessoa_main[i].nome[j] == ' ')
                    {
                        if ((pessoa_main[i].nome[j+1] >= 'A' && pessoa_main[i].nome[j+1] <= 'Z') || (pessoa_main[i].nome[j+1] >= 'a' && pessoa_main[i].nome[j+1] <= 'z'))
                        {
                            espaco++;
                        }
                    }
                }
                if (espaco < 1)
                {
                    printf("\nVoce deve inserir seu nome completo!\n\nInsira novamente:  ");
                    
                    fgets(pessoa_main[i].nome, max, stdin);
                    fixQuebraLinhaFgets(pessoa_main[i].nome);
                    limparBuffer();
                }
            }
        espaco = 0;

        limparTela(windows);
    }

    if (escolha_att == 2 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);
        
        printf("\nQual o seu sexo? F (Feminino), M (Masculino): ");
        scanf("%c", &pessoa_main[i].sexo); limparBuffer();
        while (pessoa_main[i].sexo != 'm' && pessoa_main[i].sexo != 'M' && pessoa_main[i].sexo != 'f' && pessoa_main[i].sexo != 'F')
        {
            printf("\nSomente as opcoes F (Feminino) e M (Masculino) sao aceitas!\n\nInsira novamente:  ");
            scanf("%c", &pessoa_main[i].sexo); limparBuffer();
        }

        limparTela(windows);
    }

    if (escolha_att == 3 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);

        printf("\nInsira sua data de nascimento DD MM AAAA espacando devidamente: ");
        scanf(" %d%d%d", &pessoa_main[i].nascimento_dia, &pessoa_main[i].nascimento_mes, &pessoa_main[i].nascimento_ano); limparBuffer();

        // FAZER UMA FUNÇÂO DE VERIFICAÇÂO DE DATA

        int validDate = 0;
        while (!validDate)
        {
            int validacao = 0;
            if (pessoa_main[i].nascimento_ano > 1900 && pessoa_main[i].nascimento_ano <= ano_at)
            {
                validacao++;
            }
            
            if ((pessoa_main[i].nascimento_mes == 1 || pessoa_main[i].nascimento_mes == 3 || pessoa_main[i].nascimento_mes == 5 || 
                pessoa_main[i].nascimento_mes == 7 || pessoa_main[i].nascimento_mes == 8 || pessoa_main[i].nascimento_mes == 10 || 
                pessoa_main[i].nascimento_mes == 12)  &&  (pessoa_main[i].nascimento_dia >= 1 && pessoa_main[i].nascimento_dia <= 31))
            {
                validacao++;
            }
            else if ((pessoa_main[i].nascimento_mes == 4 || pessoa_main[i].nascimento_mes == 6 || pessoa_main[i].nascimento_mes == 9 || 
                    pessoa_main[i].nascimento_mes == 11)  &&  (pessoa_main[i].nascimento_dia >= 1 && pessoa_main[i].nascimento_dia <= 30))
                {
                    validacao++;
                }
            else if ((pessoa_main[i].nascimento_mes == 2)  &&  (pessoa_main[i].nascimento_dia >= 1 && pessoa_main[i].nascimento_dia <= 28))
                {
                    validacao++;
                }
            else if ((pessoa_main[i].nascimento_mes == 2 && pessoa_main[i].nascimento_dia == 29) && (pessoa_main[i].nascimento_ano % 4 == 0))
                {
                    validacao++;
                }
            
            else if(validacao != 2)
            {
                validacao = 0;
                printf("\n\nData invalida!\n\nInsira Novamente no modo DD MM AAAA: ");
                scanf(" %d%d%d", &pessoa_main[i].nascimento_dia, &pessoa_main[i].nascimento_mes, &pessoa_main[i].nascimento_ano); limparBuffer();
            } 
            if (validacao == 2)
                {
                    validDate = 1;
                }
        }
        
        limparTela(windows);
    }

    if (escolha_att == 4 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);
    // ALERTA QUANDO ALGUÉM DIGITAR UM VALOR COMO 123 será considerado válido
        printf("\nInsira sua matricula (9 digitos): ");
        scanf(" %ld", &pessoa_main[i].matricula); limparBuffer();
        for (int j = 0, t1 = 0, t2 = 0, t3 = 0; t1 == 0 || t2 == 0 || t3 == 0; j++)
        {
            t1 = 0; t2 = 0; t3 = 0;
            for(int j = 0; j < a_cad; j++)
            {
                
                if (j == i)j++;
                if (pessoa_main[i].matricula == pessoa_main[j].matricula)
                {
                    printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                    scanf(" %ld", &pessoa_main[i].matricula); limparBuffer();
                }else t1++;
                
            }
            for(int j = 0; j < p_cad; j++)
            {
                if (j == i)j++;
                if (pessoa_main[i].matricula == pessoa_comp[j].matricula)
                {
                    printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                    scanf(" %ld", &pessoa_main[i].matricula); limparBuffer();
                }else t2++;
            }

            if (pessoa_main[i].matricula <= 0 || pessoa_main[i].matricula > 999999999)
            {
                printf("\n\nMatricula invalida!\n\nInsira novamente: ");
                scanf(" %ld", &pessoa_main[i].matricula); limparBuffer();
            }else t3++;
        }

        limparTela(windows);
    }

    if (escolha_att == 5 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);

        printf("\nInsira seu CPF sem formatacao (11 Digitos): ");
        scanf(" %s", pessoa_main[i].cpf); limparBuffer();
        
        for (int j = 0; pessoa_main[i].cpf[j] != '\0'; j++)
        {
            if (strlen(pessoa_main[i].cpf) != 11)
            {
                printf("\n\nCPF invalido!\n\nInsira novamente: ");
                scanf(" %s", pessoa_main[i].cpf); limparBuffer();
            }

            for(int j = 0; j < a_cad; j++)
            {
                if (j == i)j++;
                if (strcmp(pessoa_main[i].cpf, pessoa_main[j].cpf) == 0)
                {
                    printf("\n\nCPF ja existente!\n\nInsira novamente: ");
                    scanf(" %s", pessoa_main[i].cpf); limparBuffer();
                }
            }
            for(int j = 0; j < p_cad; j++)
            {
                if (j == i)j++;
                if (strcmp(pessoa_main[i].cpf, pessoa_comp[j].cpf) == 0)
                {
                    printf("\n\nCPF ja existente!\n\nInsira novamente: ");
                    scanf(" %s", pessoa_main[i].cpf); limparBuffer();
                }
            }
        }
    
        sprintf(pessoa_main[i].cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", pessoa_main[i].cpf[0], pessoa_main[i].cpf[1], 
        pessoa_main[i].cpf[2], pessoa_main[i].cpf[3], pessoa_main[i].cpf[4], 
        pessoa_main[i].cpf[5], pessoa_main[i].cpf[6], pessoa_main[i].cpf[7], 
        pessoa_main[i].cpf[8], pessoa_main[i].cpf[9], pessoa_main[i].cpf[10]);

        limparTela(windows);
    }

        int contagem_reg = 3;
        while (contagem_reg > 0) 
        {
        if (aluno)
        {
            printf("Aluno %d ", a_cad+1);
        }else printf("Professor %d ", a_cad+1);
        
        printf("cadastrado com sucesso! Voltando em %d...", contagem_reg);
        delay(1);
        limparTela(windows);
        contagem_reg--;
        }

        
    if (escolha_att == 0)
    {
        a_cad++; // passa para a próxima posição do vetor dizendo que a anterior ja esta ocupada por um cadastro
        char SeN;
        printf("Deseja realizar um novo cadastro? 's' para Sim, 'n' para Nao: ");
        scanf("%c", &SeN);
        // SeN = getch();
        while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
        {
            printf("\n\nOpcao invalida. Digite 's' para SIM e 'n' para NAO: ");
            scanf("%c", &SeN);
            // SeN = getch();
        }
        if (SeN == 'n' || SeN == 'N')
        {   
            *continuar = 0;
            limparTela(windows);
        }
    }
    else 
    {
        printf("Cadastro Atualizado com sucesso!");
        pressKey();
        *continuar = 0;
    }

    if (escolha_att == 0)
    {
        return a_cad;
    }
    return 0;
  }


  int excluirPessoa(pessoa alvoExclusao[], int posicaoVetor, int a_cad)
  {
    if (posicaoVetor < (a_cad - 1))
    {
        while (posicaoVetor < (a_cad -1))
        {
            alvoExclusao[posicaoVetor] = alvoExclusao[posicaoVetor + 1];
            posicaoVetor++;
        }
        a_cad--;
        return a_cad;
    }
    else if (posicaoVetor == (a_cad - 1))
    {
        a_cad--;
        return a_cad;
    }
    
    return 0;
  }
  
  
  void exibirAlunos(pessoa alunos[], int a_cad, int ano_at, int mes_at, int dia_at)
  {
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
      limparBuffer();
      pressKey();
  }
  
  
  void exibirProfessores(pessoa professores[], int p_cad, int ano_at, int mes_at, int dia_at)
  {
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
      limparBuffer();
      pressKey();
  }


  int cadastrarDrisciplina(disciplina disciplinas[], int d_cad, pessoa professores[], int p_cad, int windows)
  {
      int continuar = 1;
      int i = d_cad;
  
      while (i < n_disci && continuar && d_cad < n_disci)
      {
          printf("--------Disciplina %d--------", d_cad+1);
  
          printf("\nInsira o nome da disciplina: "); limparBuffer();
          fgets(disciplinas[i].nome, max, stdin); 
          fixQuebraLinhaFgets(disciplinas[i].nome); 
  
          for (int j = 0; j < n_disci; j++)
          {
              if (i == j)j++;
              if (strcmp(disciplinas[i].nome, disciplinas[j].nome) == 0)
              {
                  printf("\n\nNome ja existente!\n\nInsira novamente: ");
                  fgets(disciplinas[i].nome, max, stdin); limparBuffer();
                  fixQuebraLinhaFgets(disciplinas[i].nome);
              }
              while (disciplinas[i].nome[0] < 'A' || disciplinas[i].nome[0] > 'Z')
              {
                  if (disciplinas[i].nome[0] < 'A' || disciplinas[i].nome[0] > 'Z')
                  {
                      printf("\nA primeira letra esta em minusculo!\n\nInsira novamente:  ");
                      fgets(disciplinas[i].nome, max, stdin); limparBuffer();
                      fixQuebraLinhaFgets(disciplinas[i].nome);
                  }
                  for (int j = 0; disciplinas[i].nome[j] != '\0'; j++)
                  {
                      if (!((disciplinas[i].nome[j] >= 'A' && disciplinas[i].nome[j] <= 'Z') || (disciplinas[i].nome[j] >= 'a' && disciplinas[i].nome[j] <= 'z') || (disciplinas[i].nome[j] == ' ')))
                      {
                          printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                          fgets(disciplinas[i].nome, max, stdin); limparBuffer();
                          fixQuebraLinhaFgets(disciplinas[i].nome);
                      }
                  }
              }
          }
  
          limparTela(windows);
          printf("--------Disciplina %d--------", d_cad+1);
  
          printf("\nInsira o codigo da disciplina 8 digitos: "); limparBuffer();
          fgets(disciplinas[i].codigo, 9, stdin);
          fixQuebraLinhaFgets(disciplinas[i].codigo);
  
          for (int j = 0, verify = 0; j < d_cad; j++)
          {
              while (verify < 2)
              {
                  verify = 0;
                  if (strlen(disciplinas[i].codigo) == 8)
                  {
                      printf("\n\nO codigo precisa ter 8 digitos.\n\nInsira novamente: ");
                      fgets(disciplinas[i].codigo, 9, stdin); limparBuffer();
                      fixQuebraLinhaFgets(disciplinas[i].codigo);
                  }else verify++;
  
                  for (int k = 0; k < d_cad; k++)
                  {
                      if (i == k)k++;
                      if (strcmp(disciplinas[i].codigo, disciplinas[k].codigo) == 0)
                      {
                          printf("\n\nCodigo ja existente!\n\nInsira novamente: "); limparBuffer();
                          fgets(disciplinas[i].codigo, 9, stdin); 
                          fixQuebraLinhaFgets(disciplinas[i].codigo);
                      }else verify++;
                  }
              }
          }
  
          limparTela(windows);
          printf("--------Disciplina %d--------", d_cad+1);
  
          printf("\nInsira a matricula do professor da disciplina de %s: ", disciplinas[i].nome); 
          scanf(" %ld", &disciplinas[i].matriculaProfessor);
          for (int k = 0, continuare = 1; k < p_cad && continuare; k++)
          {
              while (disciplinas[i].matriculaProfessor != professores[k].matricula)
              {
                  printf("\n\nMatricula Invalida. Verifique se digitou corretamente.\n\nInsira novamente: ");
                  scanf(" %ld", &disciplinas[i].matriculaProfessor);
              }
  
              if (disciplinas[i].matriculaProfessor == professores[k].matricula)
              {
                  continuare = 0;
              }
          }
  
          limparTela(windows);
          printf("--------Disciplina %d--------", d_cad+1);
  
          printf("\nInsira o semestre da disciplina. Ex: 1, 2, 3... : "); limparBuffer();
          scanf("%d", &disciplinas[i].semestre); 
  
          while (disciplinas[i].semestre < 1 || disciplinas[i].semestre > 14)
          {
              printf("\n\nOpcao invalida!\nInsira novamente: "); limparBuffer();
              scanf("%d", &disciplinas[i].semestre); 
          }
  
          int contagem_reg = 3;
          while (contagem_reg > 0) 
          {
              printf("Disciplina %d cadastrada com sucesso! Voltando em %d...", d_cad+1, contagem_reg);
              delay(1);
              limparTela(windows);
              contagem_reg--;
          }
  
          d_cad++;
          limparBuffer();
          char SeN;
          printf("Deseja cadastrar mais uma disciplina? 's' para Sim, 'n' para Nao: ");
          scanf("%c", &SeN);
          // SeN = getch();
          while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
          {
              printf("\n\nOpcao invalida. Digite 's' para SIM e 'n' para NAO: ");
              scanf("%c", &SeN);
              // SeN = getch();
          }
          if (SeN == 'n' || SeN == 'N')
          {   
              continuar = 0;
              limparTela(windows);
          }
      }
  
  
      if (d_cad >= n_disci && continuar)
      {
          int contagem_reg = 3;
          while (contagem_reg > 0) 
          {
              printf("Limite de disciplinas atingido! Voltando em %d...", contagem_reg);
              delay(1);
              limparTela(windows);
              contagem_reg--;
          }
      }
      return d_cad;
      limparTela(windows);
  }

  
  void exibirDisciplinas(disciplina disciplinas[], int d_cad, pessoa professores[], int p_cad, int windows)
  {
      for (int i = 0; i < d_cad; i++)
      {
          printf("--------------Disciplina %d--------------", i+1);
          printf("\nNome: "); puts(disciplinas[i].nome);
          
          printf("\nCodigo: "); puts(disciplinas[i].codigo);
          
  
          printf("\nProfessor: ");
          for (int j = 0; j < p_cad; j++)
          {
              if (disciplinas[i].matriculaProfessor == professores[j].matricula)
              {
                  puts(professores[j].nome);
              }
          }
  
          printf("\nSemestre: %d", disciplinas[i].semestre);
          printf("\n\n");
      }
      limparBuffer();
      pressKey();
      limparTela(windows);
  }


  int procurarDisciplina(disciplina disciplinaBuscada[], char codigo[], int d_cad)
  {
    for (int i = 0; i < d_cad; i++)
    {
        int comparacao;
        comparacao = strcmp(codigo, disciplinaBuscada[i].codigo);
        if(comparacao == 0)
        {
            printf("disciplina econtrada");
            pressKey();
            return i;
        }
        else 
        {
            printf("Disciplina nao encontrada");
            pressKey();
            return -1;
        }
    }
    return 0;
  }