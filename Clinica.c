
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/*Funcao para limpar tela*/
void limparTela(){

    system("cls");

}

/*Funcao para limpar o buffer*/
void limparBuffer(){

    fflush(stdin);

}



// Variáveis globais para armazenar prontuários
#define MAX_PRONTUARIOS 100
#define MAX_HISTORICO 1000

char prontuarioCpf[MAX_PRONTUARIOS][100];          // CPF dos prontuários
char prontuarioHistorico[MAX_PRONTUARIOS][MAX_HISTORICO]; // Histórico médico
int totalProntuarios = 0;                          // Contador de prontuários


// Criar um novo prontuário para um paciente
// cpf  -> vetor de CPFs de pacientes cadastrados
// cont -> quantidade de pacientes cadastrados
void criarProntuario(char cpf[][100], int cont) {
    char cpfBusca[100];
    char voltar;

    printf("\nDigite o CPF do paciente para criar o prontuario: ");
    scanf("%99s", cpfBusca);
    limparBuffer();

    // Verifica se o paciente existe
    int pacienteExiste = 0;
    for (int i = 0; i < cont; i++) {
        if (strcmp(cpf[i], cpfBusca) == 0) {
            pacienteExiste = 1;
            break;
        }
    }
    if (!pacienteExiste) {
        printf("Paciente nao encontrado.\n");
        printf("Digite 'v' para voltar: ");
        scanf(" %c", &voltar);
        limparBuffer();

        limparTela();
        return;
    }

    // Verifica se o prontuário já foi criado
    for (int i = 0; i < totalProntuarios; i++) {
        if (strcmp(prontuarioCpf[i], cpfBusca) == 0) {
            printf("Prontuario já existe para este paciente.\n");
            printf("Digite 'v' para voltar: ");
            scanf(" %c", &voltar);
            limparBuffer();

            limparTela();
            return;
        }
    }

    // Cria o prontuário
    strcpy(prontuarioCpf[totalProntuarios], cpfBusca);
    prontuarioHistorico[totalProntuarios][0] = '\0'; // histórico vazio
    totalProntuarios++;

    printf("Prontuario criado com sucesso!\n");
    printf("Digite 'v' para voltar: ");
    scanf(" %c", &voltar);
    limparBuffer();

    limparTela();
}

// Adicionar informações ao prontuário
void adicionarInformacaoProntuario() {
    char cpfBusca[100];
    char voltar;

    printf("\nDigite o CPF do paciente: ");
    scanf("%99s", cpfBusca);
    limparBuffer();

    for (int i = 0; i < totalProntuarios; i++) {
        if (strcmp(prontuarioCpf[i], cpfBusca) == 0) {
            char novaInfo[500];

            printf("Digite a nova informacao medica: ");
            scanf(" %[^\n]", novaInfo);
            limparBuffer();

            strcat(prontuarioHistorico[i], "\n- ");
            strcat(prontuarioHistorico[i], novaInfo);

            printf("Informacao adicionada com sucesso!\n");
            printf("Digite 'v' para voltar: ");
            scanf(" %c", &voltar);
            limparBuffer();

            limparTela();
            return;
        }
    }

    printf("Prontuario nao encontrado.\n");
    printf("Digite 'v' para voltar: ");
    scanf(" %c", &voltar);
    limparBuffer();

    limparTela();
}



// Exibir histórico médico do prontuário
void exibirProntuario() {
    char cpfBusca[100];
    char voltar;

    printf("\nDigite o CPF do paciente: ");
    scanf("%99s", cpfBusca);
    limparBuffer();

    for (int i = 0; i < totalProntuarios; i++) {
        if (strcmp(prontuarioCpf[i], cpfBusca) == 0) {
            printf("\n--- Prontuario Medico ---\n");
            printf("CPF: %s\n", prontuarioCpf[i]);
            printf("Historico: %s\n", prontuarioHistorico[i]);
            printf("Digite 'v' para voltar: ");
            scanf(" %c", &voltar);
            limparBuffer();

            limparTela();
            return;
        }
    }

    printf("Prontuario nao encontrado.\n");
    printf("Digite 'v' para voltar: ");
    scanf(" %c", &voltar);
    limparBuffer();

    limparTela();
}



// Função para buscar e exibir prontuário pelo CPF
void buscarProntuarioPorCPF()
{
    char cpfBusca[100];  // Variável para armazenar o CPF digitado pelo usuário
    char voltar;         // Variável para capturar a tecla de voltar

    // Solicita o CPF do paciente (ou 'v' para voltar)
    printf("\nDigite o CPF do paciente (ou 'v' para voltar): ");
    scanf("%99s", cpfBusca);
    limparBuffer();

    // Se o usuário digitar 'v' ou 'V', retorna para o menu principal
    if (strcmp(cpfBusca, "v") == 0 || strcmp(cpfBusca, "V") == 0) {

        limparTela();
        return; // Sai da função sem fazer nada
    }

    // Percorre todos os prontuários cadastrados para buscar o CPF
    for (int i = 0; i < totalProntuarios; i++)
    {
        // Compara o CPF digitado com o CPF do prontuário na posição i
        if (strcmp(prontuarioCpf[i], cpfBusca) == 0)
        {
            // Se encontrar, exibe os dados do prontuário
            printf("\n--- Prontuario Médico ---\n");
            printf("CPF: %s\n", prontuarioCpf[i]);
            printf("Histórico: %s\n", prontuarioHistorico[i]);

            // Solicita para o usuário digitar 'v' para voltar ao menu
            printf("\nDigite 'v' para voltar: ");
            scanf(" %c", &voltar);
            limparBuffer();

            limparTela();
            return; // Sai da função após exibir o prontuário
        }
    }

    // Caso não encontre o prontuário, informa o usuário
    printf("Prontuario nao encontrado.\n");
    printf("Digite 'v' para voltar: ");
    scanf(" %c", &voltar);
    limparBuffer();

    limparTela();
}







void cancelarConsulta(char agendarNome[][100], char nascimento[][100], 
                     char especialidade[][100], char horario[][100], 
                     char local[][100], char consulta[][100], int *cont2) {
    
    // Struct temporária (usada apenas nesta função)
    typedef struct {
        char nome[100];
        char dataNascimento[100];
        char especialidade[100];
        char horario[100];
        char local[100];
        char id[100];
    } ConsultaTemp;
    
    if (*cont2 == 0) {
        printf("\nNenhuma consulta agendada para cancelar!\n");
        return;
    }

    // Mostrar consultas existentes
    printf("\n--- Consultas Agendadas ---\n");
    for (int i = 0; i < *cont2; i++) {
        printf("[%d] %s (ID: %s)\n", i+1, agendarNome[i], consulta[i]);
    }

    int numero;
    printf("\nDigite o numero da consulta a cancelar: ");
    scanf("%d", &numero);
    limparBuffer();
    
    if (numero < 1 || numero > *cont2) {
        printf("\nNumero invalido!\n");
        return;
    }
    
    int indice = numero - 1;
    
    // Usando a struct temporária apenas para organizar os dados
    ConsultaTemp consultaCancelada;
    strcpy(consultaCancelada.nome, agendarNome[indice]);
    strcpy(consultaCancelada.dataNascimento, nascimento[indice]);
    strcpy(consultaCancelada.especialidade, especialidade[indice]);
    strcpy(consultaCancelada.horario, horario[indice]);
    strcpy(consultaCancelada.local, local[indice]);
    strcpy(consultaCancelada.id, consulta[indice]);
    
    // Mostrar dados (opcional)
    printf("\nDados da consulta a cancelar:\n");
    printf("Nome: %s\n", consultaCancelada.nome);
    printf("Data Nasc.: %s\n", consultaCancelada.dataNascimento);
    printf("Especialidade: %s\n", consultaCancelada.especialidade);
    printf("Horario: %s\n", consultaCancelada.horario);
    printf("Local: %s\n", consultaCancelada.local);
    
    // Confirmação
    printf("\nTem certeza que deseja cancelar? (s/n): ");
    char confirmacao;
    scanf("%c", &confirmacao);
    limparBuffer();
    
    if (confirmacao != 's' && confirmacao != 'S') {
        printf("\nCancelamento abortado!\n");
        return;
    }
    
    // Remover a consulta (trabalhando diretamente com suas matrizes originais)
    for (int i = indice; i < *cont2 - 1; i++) {
        strcpy(agendarNome[i], agendarNome[i+1]);
        strcpy(nascimento[i], nascimento[i+1]);
        strcpy(especialidade[i], especialidade[i+1]);
        strcpy(horario[i], horario[i+1]);
        strcpy(local[i], local[i+1]);
        strcpy(consulta[i], consulta[i+1]);
    }
    
    (*cont2)--;
    printf("\nConsulta cancelada com sucesso!\n");

    limparTela();
}









int main(){

    char cpfAgendar[100][100];
    char medico[100][100];
    char agendarNome[100][100]; 
    char consulta[100][100];
    char local[100][100];
    char especialidade[100][100];
    char nascimento[100][100];
    char horario[100][100];
    int cont2 = 0;

    int idadePaciente[100];
    char nomePaciente[100][100];
    char cpf[100][100];
    int menu;
    int i = 0;
    int cont = 0;
    char consult[12];
    char adicionar;
    char voltar;
    int c;
    


    /*Menu para acessar as informacoes com um laco de repeticao do while, para saber quando finalizar o programa*/
    do{
        printf("\n=========================================");
        printf("\n| Bem-Vindo ao sistema da Clinica System |");
        printf("\n|========================================|");
        printf("\n| 1 - Cadastrar Paciente                 |");
        printf("\n| 2 - Buscar Paciente                    |");
        printf("\n| 3 - Listar Paciente                    |");
        printf("\n| 4 - Agendar Consulta                   |");
        printf("\n| 5 - Exibir consulta                    |");
        printf("\n| 6 - Cancelar Consulta                  |");
        printf("\n| 7 - Criar Prontuario                   |");
        printf("\n| 8 - Adicionar informacao no Prontuario |");
        printf("\n| 9 - Exibir Prontuario                  |");
        printf("\n| 10 - Busca Prontuario por CPF          |");
        printf("\n| 0 - Sair                               |");
        printf("\n=========================================");
        printf("\nEscolha: ");
        scanf("%d", &menu);
        limparBuffer();

        /*Switch para acessar os menus*/
        switch(menu){


            /*caso 1 vai cadastrar o paciente*/
            case 1:

                limparTela();

                do{
                    printf("Digite o nome do paciente: ");
                    fgets(nomePaciente[i], 100, stdin);

                    printf("Digite a idade do paciente: ");
                    scanf("%d", &idadePaciente[i]);
                    limparBuffer();
                    
                    printf("Digite o CPF do paciente (apenas numeros): ");
                    scanf("%99s", cpf[i]);
                    limparBuffer();
                    

                    printf("Voce deseja adicionar mais um paciente[s/n]: ");
                    scanf("%c", &adicionar);
                    limparBuffer();

                    limparTela();

                    cont++;
                    i++;

                 }while(adicionar != 'n');

                break;
    	    

            /*Caso 2 vai buscar o paciente pelo cpf*/
            case 2:

                limparTela();


                /*A pessoa ira digitar o cpf para realizar a busca do paciente*/
                printf("Digite o CPF do paciente que voce deseja consultar: ");
                scanf("%11s", &consult);
                limparBuffer();


                /*laco for para acessar cada posicao*/
                for(i = 0; i < cont; i++){
                    

                    /*condicional para saber se existe algum cpf que a pessoa consultou*/
                    if(strcmp(consult, cpf[i]) == 0){

                        limparTela();

                        printf("NOME: %s", nomePaciente[i]);
                        printf("IDADE: %d\n", idadePaciente[i]);
                        printf("CPF: %s\n", cpf[i]);

                        printf("Digite 'v' para voltar: ");
                        scanf("%c", &voltar);
                        limparBuffer();


                        break;


                    }
                }


                /*Esse laco ira verificar todas as posicoes tambem*/
                for(i = 0; i < cont; i++){

                    /*Essa condicao e caso nao tenha nenhum cpf*/
                    if(strcmp(consult, cpf[i]) != 0 && i == cont -1){

                        limparTela();

                        printf("Nenhum usuario cadastrado!\n\n");
                            
                        printf("Digite 'v' para voltar: ");
                        scanf("%c", &voltar);
                        limparBuffer();

                    }

                }
                    
                

                break;

        /*caso 3 vai listar os pacientes*/
        case 3:

            limparTela();

            /*Existe um if e else para saber se ja tem um usuario cadastrado, se tiver vai exibir se nao vai informar que nao existe nenhum usuario cadastrado*/
            if(cont > 0){

            for(i = 0; i < cont; i++){

                printf("NOME: %s", nomePaciente[i]);
                printf("IDADE: %d\n", idadePaciente[i]);
                printf("CPF: %s\n\n", cpf[i]);

            }

            }else{

                printf("Nenhum usuario cadastrado!");
            }
        
            break;


            /*Caso 4 para agendar consulta*/
            case 4:
            
                limparTela();

                do{
                    printf("Digite o nome do paciente: ");
                    scanf("%99[^\n]s", agendarNome[i]);
                    limparBuffer();

                    printf("Digite a data de nascimento[dd/mm/aaaa]: ");
                    scanf("%99s", nascimento[i]);
                    limparBuffer();

                    printf("Digite a especialidade medica: ");
                    scanf("%99[^\n]s", especialidade[i]);
                    limparBuffer();

                    printf("Digite o horario da consulta[00:00]: ");
                    scanf("%99s", horario[i]);
                    limparBuffer();

                    printf("Digite o local da consulta: ");\
                    scanf("%99[^\n]s", local[i]);
                    limparBuffer();

                    printf("Digite o id da consulta: ");
                    scanf("%99s", consulta[i]);
                    limparBuffer();

                    printf("\nConsulta agendada com sucesso!\n");

                    printf("\nVoce deseja agendar mais uma consula[s/n]: ");
                    scanf("%c", &adicionar);
                    limparBuffer();

                    limparTela();

                    cont2++;
                    i++;

                }while(adicionar != 'n');

                

                break;


        case 5:

            limparTela();

            for(i = 0; i < cont2; i++){

                printf("NOME: %s\n", agendarNome[i]);
                printf("DATA DE NASCIMENTO: %s\n", nascimento[i]);
                printf("ESPECIALIDADE: %s\n", especialidade[i]);
                printf("HORARIO: %s\n", horario[i]);
                printf("LOCAL: %s\n", local[i]);
                printf("ID: %s\n\n", consulta[i]);
            }

            printf("\nDigite 'v' para voltar: ");
            scanf("%c", &voltar);

            break;


            case 6:

                limparTela();
                cancelarConsulta(agendarNome, nascimento, especialidade, horario, local, consulta, &cont2);
                printf("Digite 'v' para voltar: ");
                scanf("%c", &voltar);
                limparBuffer();

                limparTela();


                break;

            case 7:

            limparTela();

                criarProntuario(cpf, cont);
                break;

            case 8:

                limparTela();

                adicionarInformacaoProntuario();
                break;

            case 9:

                limparTela();

                exibirProntuario();
                break;

            case 10:

                limparTela();

                buscarProntuarioPorCPF();
                break;

            default:

                printf("Opcao invalida!");
                break;
        }

    

    }while(menu != 0);



    return 0;
}

