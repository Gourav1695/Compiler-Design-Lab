
int Const_Number = 200;

int mult(int n, int m)
{
    return (n * m);
}

int name()
{
    printf("Gourav Kumar Shaw");
    return 0;
}


int main()
{
    int a = 20;
    float b = (a + 30.0) * 200;
    char c = 'a';
    c = 'b';
    if (a == 40)
    {
        printf("a is 40");
    }
    else if (a > 40)
    {
        printf("a is greater than 40");
    }
    else
    {
        printf("a is less than 40");
    }

    for (int i = 1; i < 10; i++)
    {
        printf("Iterative statements");
        for (int j = 1; j < 10; j++)
        {
            printf("Iterative statements");
        }
    }

    int counter = 0;
    while (counter < 10)
    {
        printf("Iterative statements");
        counter = counter + 1;
    }

    name();
    int x = mult(10, 20);
    return 0;
}