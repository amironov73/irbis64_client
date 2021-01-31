// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <stdio.h>
#include <string.h>

#include "irbis64_client.h"

int main (int argc, char **argv)
{
    int rc;
    const char *hostname = "127.0.0.1";
    const char *username = "librarian";
    const char *password = "secret";
    char answer[32000], record[3200];
    char *panswer = answer, *precord = record;
    int answerSize = 32000, recordSize = 32000;
    int fieldIndex;

    if (argc > 1) {
        hostname = (const char *) argv[1];

        if (argc > 2) {
            username = (const char *) argv[2];

            if (argc > 3) {
                password = (const char *) argv[3];
            }
        }
    }

    memset(answer, 0, answerSize);

    rc = IC_reg(hostname, "6666", 'C', username, password, &panswer, answerSize);
    printf ("IC_reg=%d\n", rc);
    if (rc >= 0) {
        printf("\n%s", answer);
    }

    printf ("\n");
    rc = IC_maxmfn("IBIS");
    printf ("IC_maxmfn=%d\n", rc);

    printf ("\n");
    rc = IC_read("IBIS", 1, 0, &precord, recordSize);
    printf ("IC_read=%d\n", rc);
    if (rc >= 0) {
        fieldIndex = IC_fieldn(record, 200, 1);
        printf ("IC_fieldn=%d\n", fieldIndex);
        if (fieldIndex > 0) {
            memset(answer, 0, answerSize);
            rc = IC_field(record, fieldIndex, 'a', answer, answerSize);
            printf ("IC_field=%d\n", rc);
            if (rc >= 0) {
                printf ("IC_field=%s", answer);
            }
        }
    }

    printf ("\n");
    rc = IC_unreg(username);
    printf ("IC_unreg=%d\n", rc);

    printf("Hello, IRBIS64!\n");

    return 0;
}
