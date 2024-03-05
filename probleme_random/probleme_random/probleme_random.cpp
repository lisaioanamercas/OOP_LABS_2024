#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int Atoi(char c)
{
    int x = 0;
    if (c >= '0' and c <= '9')
        x = (c - '0');
    return x;
}

int main()
{
    FILE* fp;///pointer la un obiect de tipul file
    int sum = 0;
    if (fopen_s(&fp, "in.txt", "r") != 0)
    {
        printf("%s", "Eroare. Nu am putut deschide fisierul.\n");
    }
    else
    {
        printf("Am deschis fisierul cu succes!\n");
        char str[200];
        while (fgets(str, 200, fp) != NULL)
        {
            //printf("am citit din fisier: %s\n", str);
            int n = strlen(str)-1, nr = 0;
            for (int i = 0; i < n; i++)
            {
                nr = nr * 10 + Atoi(str[i]);
            }
            //printf("Numarul obtinut in urma Atoi este: %d\n", nr);
            sum += nr;
            ///acum in str la prima iterare a whilelului am primul numar din fisier scris ca si string
            ///ce vreau sa fac -> vreau sa iau fiecare caracter din str pana la ultimul cu un for
            /// si apoi sa il transform pe fiecare in intul lui
            /// apoi sa le fac adaugarea la dreapta si sa le adaug in numarul meu normal
            /// si dupa ce am ajuns fresh sa il adun la suma la sfarsitul whileului :)
        }
        printf("Suma dorita este: %d\n", sum);
    }
    ///functie care sa parcurga sirul caracter cu caracter -> sa fac nr obtinut si sa faca suma !
    return 0;
}