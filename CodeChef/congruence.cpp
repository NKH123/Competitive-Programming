#include <stdio.h>

int inverse(int a, int b)
{
    int inv = -1;
    int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;

    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
        inv = t1;

    if (inv < 0)
        inv = inv + a;

    return inv;
}

int gcd(int a, int b)
{
    int q, r;
    while (b > 0)
    {
        q = a / b;
        r = a - q * b;
        a = b;
        b = r;
    }
    return a;
}

// C program to find general solution to given Linear Congruence Equation
int main()
{
    int a, b, c, d, n, a1, b1, n1, x0;
    char ch;
    int inv;

    while (!feof(stdin))
    {
        fscanf(stdin, "%dx", &a);
        ch = getc(stdin);

        if (ch == '+')
        {
            fscanf(stdin, "%d=%d(mod %d)\n", &c, &b, &n);
            fprintf(stdout, "%dx+%d=%d(mod %d)\n", a, c, b, n);
            b = b - c;
            if (b < 0)
                b = b + n;
        }
        else
        {
            fscanf(stdin, "%d(mod %d)\n", &b, &n);
            fprintf(stdout, "%dx=%d(mod %d)\n", a, b, n);
        }

        fprintf(stdout, "Reduced Equation: %dx=%d(mod %d)\n", a, b, n);
        d = gcd(a, n);
        fprintf(stdout, "GCD(%d, %d) = %d\n", a, n, d);

        if ((n % b == 0) || (d % b == 0))
        {
            fputs("The given equation has No solution.\n", stdout);
            continue;
        }

        a1 = a / d;
        b1 = b / d;
        n1 = n / d;

        fprintf(stdout, "Reduced Equation: %dx=%d(mod %d)\n", a1, b1, n1);

        inv = inverse(n1, a1);
        fprintf(stdout, "inv(%d) = %d\n", a1, inv);

        x0 = (b1 * inv) % n1;
        fprintf(stdout, "General Solution: "
                    "x = %d + %dk where k is any integer\n\n", x0, n / d);
    }

    return 0;
}