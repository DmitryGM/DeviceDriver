#include <stdio.h>

int is_digit(char ch)
{
    return '0' <= ch && ch <= '9';
}

int ch_to_int(char ch)
{
    return (int) (ch - '0');
}

int sum(char *string)
{
    int sum = 0;
    size_t i = 0;
    while (string[i] != '\0')
    {
        int acc = 0;

        while (is_digit(string[i]))
        {
            acc *= 10;
            acc += ch_to_int(string[i]);
            i++;
        }

        sum += acc;

        while (!is_digit(string[i]) && string[i] != '\0')
            i++;
    }

    return sum;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Waits for a string argument to be passed\n");
        return 1;
    }

    char *input = argv[1];

    int a = sum(input);
    printf("sum = %d\n", a);

    return 0;
}
