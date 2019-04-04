#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void print_item(int c, const char* d, double p, FILE* f)
{
    fprintf(f, "%5d %-16s %8.2f %8.2f\n", c, d, p, p*c);
}

void print_wherever(const int* cs, const char** ds, const double* ps, size_t n, FILE* f)
{
    for(size_t i = 0; i < n; i++)
    {
        print_item(cs[i], ds[i], ps[i], f);
    }

}

int main()
{
    // use the stdout ptr to print wherever:

    int quantities[] = {10, 8, 9};
    const char* descriptions[] = {"pants", "shirts", "shoes"};
    double unitPrices[] = {80, 90, 250};

    FILE* f = fopen("store", "w");

    print_wherever(quantities, descriptions, unitPrices, 3, f);
    fclose(f);
}