//***************************************************
//* Programmer: Emil Gram Jensen
//* Class: Software (Gruppe 8)
//* Programming Assignment: Eksamensopgave 1
//* Date: 2021
//***************************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void scan_data(char *operator, double * operand);
void do_next_op(char operator, double operand, double *akkumlator);
void run_calculator(double akkumulator, char operator);
int is_binary(char operator);
void clear_console();

int main(void)
{
    double operand, akkumulator = 0.0;
    char operator;

    clear_console();

    while (operator!= 'q')
    {
        scan_data(&operator, & operand);

        do_next_op(operator, operand, &akkumulator);

        run_calculator(akkumulator, operator);
    }
}

void run_calculator(double akkumulator, char operator)
{

    printf("%s %lf", (operator== 'q' ? "Final result is: " : "Result so far is: "), akkumulator);
}

void scan_data(char *operator, double * operand)
{

    printf("\nEnter operator, and an optional operand: ");

    scanf(" %c", operator);
    *operand = 0.0;

    if (is_binary(*operator))
        scanf(" %lf", operand);
}

void do_next_op(char operator, double operand, double *akkumlator)
{

    switch (operator)
    {
    case '+':
        *akkumlator += operand;
        break;
    case '-':
        *akkumlator -= operand;
        break;
    case '*':
        *akkumlator *= operand;
        break;
    case '/':
        *akkumlator /= (operand ? operand : 1);
        break;
    case '^':
        *akkumlator = pow(*akkumlator, operand);
        break;
    case '#':
        *akkumlator = (*akkumlator > 0 ? sqrt(*akkumlator) : *akkumlator);
        break;
    case '%':
        *akkumlator = *akkumlator * -1;
        break;
    case '!':
        *akkumlator = 1 / *akkumlator;
        break;
    default:
        break;
    }
}

// Funktionen tjekker om den indtastede operator er binær.
// Kunne også laves med en switch eller et if-statement i stedet for at tjekke i et array.
int is_binary(char operator)
{

    const char BINARY_OPERATORS[] = {'+', '-', '*', '/', '^'};

    for (int i = 0; i < sizeof(BINARY_OPERATORS); i++)
        if (BINARY_OPERATORS[i] == operator)
            return 1;

    return 0;
}

/************************************************************
 * Function: clear_console()
 * Description: Clears the console
 *************************************************************/
void clear_console()
{
#ifdef _WIN32
    system("cls");
#else // In any other OS
    system("clear");
#endif
}