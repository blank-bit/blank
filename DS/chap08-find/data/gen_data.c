#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#include "keytype.h"

const KeyType limit = 65535u;
const unsigned maxn = 20480u;
const unsigned size = sizeof(KeyType);
const char *datafile = "benchmark.data";

int main(int argc, char *argv[])
{
    FILE *fp;
    KeyType len, d;
    
    if (argc < 2)
    {
        printf("Usage: gen_data <number of data>\n");
        exit(0);
    }

    len = atoi(argv[1]);
    if (len > maxn)
    {
        printf("The number of data(%u) is too large, please choose one less than %u\n", len, maxn);
        exit(0);
    }

    srand(time(NULL));

    fp = fopen(datafile, "wb"); //"wt"
    fwrite(&len, size, 1, fp); //byte stream
    for (int i = 0; i < len; ++i)
    {
        d = rand() % limit;
        fwrite(&d, size, 1, fp);
    }
    fclose(fp);

    printf("All data was written into file %s\n"
    "*** Note: the value of the first %u bytes is the count of data\n", datafile, size);

    return 0;
}