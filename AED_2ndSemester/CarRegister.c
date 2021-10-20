// AED, 1st Exercise
// Lucca Giffoni, 156.564, NA

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int index = 0;

// Cars register
void main()
{
    // Permission to use accents
    setlocale(LC_ALL, "");

    // Declaring variables
    int userOption;

    // Header and Main Menu
    clearConsole();
    printf("-------------------------- Banco de Carros --------------------------\n");
    printf("\n1. Novo registro\n2. Alterar registro\n3. Verificar registro\n4. Apagar registro\n5. Sair\n");
    printf("\nPor favor, digite o número correspondente ao que você quer fazer: ");
    scanf("%d", &userOption);

    // Verifying user's response
    if(userOption > 5 || userOption < 1)
    {
        while(userOption > 5 || userOption < 1)
        {
            // Cleaning console to keep it user-friendly
            clearConsole();
            printf("-------------------------- Banco de Carros --------------------------\n");
            printf("\n1. Novo registro\n2. Alterar registro\n3. Verificar registro\n4. Apagar registro\n5. Sair\n");
            printf("\nPor favor, digite o número válido, correspondente ao que você deseja fazer: ");
            scanf("%d", &userOption);
        }
    }

    // Switch case using user's response
    switch (userOption)
    {
        int aux;
        char* plate[6];

        case 1:
        createRegister();
        break;

        case 2:
        printf("\nPara fazer a consulta sobre um registro, por favor digite a placa do carro usando somente números e letras, sem o traço: ");
        scanf("%d", &aux);

        editRegister(aux);
        break;

        case 3:
        printf("\nPara fazer a consulta sobre um registro, por favor digite a placa do carro usando somente números e letras, sem o traço: ");
        scanf("%s", &plate);

        verifyRegister(plate);
        break;

        case 4:
        printf("\nPara fazer a consulta sobre um registro, por favor digite a placa do carro usando somente números e letras, sem o traço: ");
        scanf("%d", &aux);

        deleteRegister(aux);
        break;

        case 5:
        exit(0);
        break;
    }
}

// Creating the struct
struct Register
{
    char licensePlate[6];
    char brand[15];
    char model[25];
    char airConditioning[3];
    int fabricationYear;
    int quilometersTraveled;
    int doorsCount;
};

// Add new register function
void createRegister()
{
    // Cleaning console to keep it user-friendly
    clearConsole();
    printf("-------------------------- Banco de Carros --------------------------\n");
    printf("Criando Registro:\n");

    FILE *carros;
    carros = fopen("carros.txt", "a");

    if(carros == NULL)
    {
        printf("Ocorreu um erro na criação do arquivo.");
        exit(1);
    }

    // Declaring and allocating space for my struct
    struct Register *RegisterCode[index];
    RegisterCode[index] = (struct Register *) malloc(sizeof(struct Register));

    // Get all user's input
    printf("\nDigite a placa do carro: ");
    scanf("%s", RegisterCode[index]->licensePlate);
    fprintf(carros, "%s/", RegisterCode[index]->licensePlate);

    printf("Digite a marca do carro: ");
    scanf("%s", RegisterCode[index]->brand);
    fprintf(carros, "%s/", RegisterCode[index]->brand);

    printf("Digite o modelo do carro: ");
    scanf("%s", RegisterCode[index]->model);
    fprintf(carros, "%s/", RegisterCode[index]->model);

    printf("O carro tem ar-condicionado (sim/nao): ");
    scanf("%s", RegisterCode[index]->airConditioning);
    fprintf(carros, "%s/", RegisterCode[index]->airConditioning);

    printf("Digite a quilometragem rodada do carro: ");
    scanf("%i", &RegisterCode[index]->quilometersTraveled);
    fprintf(carros, "%i/", RegisterCode[index]->quilometersTraveled);

    printf("Digite o ano de fabricação do carro: ");
    scanf("%i", &RegisterCode[index]->fabricationYear);
    fprintf(carros, "%i/", RegisterCode[index]->fabricationYear);

    printf("Digite a quantidade de portas do carro: ");
    scanf("%i", &RegisterCode[index]->doorsCount);
    fprintf(carros, "%i\n", RegisterCode[index]->doorsCount);

    fclose(carros);
    index++;
    leaveOrRestart();
}

// Verify a register function
void verifyRegister(char* usersLicensePlate)
{
    // Cleaning console to keep it user-friendly
    clearConsole();
    printf("-------------------------- Banco de Carros --------------------------\n");
    printf("Verificando Registro:\n");

    // Declaring and opening the file
    FILE* arquivo = fopen("carros.txt", "r");
    if(arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }

    // Declaring variables to help on string division
    char linha[1024];
    char* strArray[1024];
    int i = 0;

    // Dividing string into small string and allocating'em in an array
    while(fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        strArray[i] = &linha;
        // Verifying success of divide and conquer: printf("%s", strArray[i]);
        i++;
    }

    // Searching for my string
    int l = 0;

    for(int k = 0; k < sizeof(strArray); k++)
    {
        if(strstr(strArray[k], usersLicensePlate))
        {
            int init_size = strlen(strArray[k]);
            char delim[] = "/";

            char *ptr = strtok(strArray[k], delim);
            printf("\n\nDados registrados para o veículo com a placa %s\n\n", usersLicensePlate);

            while(ptr != NULL)
            {
                printf("%s\n", ptr);
                ptr = strtok(NULL, delim);
            }

            for(int m = 0; m < sizeof(ptr); m++)
            {
                while(ptr != NULL)
                {
                    switch(m)
                    {
                        case 0:
                        printf("Placa: %s", ptr);
                        // ptr = strtok(NULL, delim);
                        break;

                        case 1:
                        printf("Marca: %s", ptr);
                        // ptr = strtok(NULL, delim);
                        break;
                    }
                }
            }

            break;
        }
        else
        {
            continue;
        }

        k++;
    }
}

// Edit a register function
void editRegister(int usersLicensePlate)
{
    // Cleaning console to keep it user-friendly
    clearConsole();
    printf("-------------------------- Banco de Carros --------------------------\n");
    printf("Editando Registro:\n");

    leaveOrRestart();
}

// Delete a register function
void deleteRegister(int usersLicensePlate)
{
    // Cleaning console to keep it user-friendly
    clearConsole();
    printf("-------------------------- Banco de Carros --------------------------\n");
    printf("Deletando Registro:\n");

    leaveOrRestart();
}

// Leave it or restart it function
void leaveOrRestart()
{
    // Let user decide what to do now
    int aux;
    printf("\n\nPara sair do aplicativo, digite 0 ou, para voltar para o menu inicial, digite 1: ");
    scanf("%d", &aux);

    // Restarting the application or finishing it
    if(aux == 0)
    {
        // Leaving application
        exit(0);
    }
    else if(aux == 1)
    {
        // Restarting application
        main();
    }
    else
    {
        // Verifying user's response
        while(0 < aux < 1)
        {
            // Cleaning console to keep it user-friendly
            clearConsole();
            printf("\nPara sair do aplicativo, digite 0 ou, para voltar para o menu inicial, digite 1: ");
            scanf("%d", aux);
        }
    }
}

// Funtion to clean the console
void clearConsole()
{
    system("@cls||clear");
}
