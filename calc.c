#include <stdio.h>
int main()
{
    int stack[1000];

    int cein = 0; /*  cein . This is  cell.Then (cein-1) top of stack*/
    while (!feof(stdin))
    {
        int c = getchar();
        int x;
        switch (c)
        {
        case ' ':
        case '\n':
            break;
        case '=':
            printf("Result = %d\n", stack[cein - 1]);
            cein = cein - 1;
            break;
        case '*':
            stack[cein - 2] = stack[cein - 1] * stack[cein - 2];
            cein = cein - 1;
            break;
        case '/':
            stack[cein - 2] = stack[cein - 2] / stack[cein - 1];
            cein = cein - 1;
            break;
        case '+':
            stack[cein - 2] = stack[cein - 2] + stack[cein - 1];
            cein = cein - 1;
            break;
        case '-':
            stack[cein - 2] = stack[cein - 2] - stack[cein - 1];
            cein = cein - 1;
            break;

        default:
            ungetc(c, stdin);
            if (scanf("%d", &x) != 1)
            {
                fprintf(stderr, "It's not possible to read integer values\n");
                return -1;
            }
            else
            {
                stack[cein] = x;
                cein = cein + 1;
            }
        }
    }
    printf("Result = %d\n", stack[cein - 1]);
    return 0;
}
