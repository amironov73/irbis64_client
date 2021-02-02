// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <stdio.h>
#include <string.h>

#include "irbis64_client.h"

#define DB "IBIS"

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

    rc = IC_set_show_waiting (-1);
    printf ("IC_set_show_waiting=%d\n", rc);

    rc = IC_set_blocksocket (1);
    printf ("IC_set_blocksocket=%d\n\n", rc);

    if (argc > 1) {
        hostname = (const char *) argv[1];

        if (argc > 2) {
            username = (const char *) argv[2];

            if (argc > 3) {
                password = (const char *) argv[3];
            }
        }
    }

    // Подключение к серверу
    memset (answer, 0, answerSize);
    rc = IC_reg (hostname, "6666", 'A', username, password, &panswer, answerSize);
    printf ("IC_reg=%d\n", rc);
    if (rc < 0) {
        printf ("EXIT\n");
        return 1;
    } else {
        printf("\n%s", answer);
    }

    // Получение максимального MFN для базы данных
    printf ("\n");
    rc = IC_maxmfn (DB);
    printf ("IC_maxmfn=%d\n", rc);

    // Чтение записи с сервера
    printf ("\n");
    rc = IC_read (DB, 1, 0, &precord, recordSize);
    printf ("IC_read=%d\n", rc);
    if (rc >= 0) {

        // Доступ к полям записи
        fieldIndex = IC_fieldn (record, 200, 1);
        printf ("IC_fieldn=%d\n", fieldIndex);
        if (fieldIndex > 0) {
            memset(answer, 0, answerSize);
            rc = IC_field (record, fieldIndex, 'a', answer, answerSize);
            printf ("IC_field=%d\n", rc);
            if (rc >= 0) {
                printf ("IC_field=%s", answer);
            }
        }
    }

    // Форматирование записи по ее MFN
    printf ("\n");
    memset (answer, 0, answerSize);
    rc = IC_sformat (DB, 1, "@brief", answer, answerSize);
    printf ("IC_sformat=%d\n", rc);
    if (rc >= 0) {
        printf ("IC_sformat=%s\n", answer);
    }

    // Поиск
    printf ("\n");
    memset (answer, 0, answerSize);
    rc = IC_search (DB, "\x4B\x3D\xD0\xB1\xD0\xB5\xD1\x82\xD0\xBE\xD0\xBD\x24", 10, 1, "@brief",
        answer, answerSize);
    printf ("IC_search=%d\n", rc);
    if (rc >= 0) {
        printf ("IC_search=%s\n", answer);
    }

    // Получение списка серверных процессов
    printf ("\n");
    memset (answer, 0, answerSize);
    rc = IC_adm_getProcessList (answer, answerSize);
    printf ("IC_adm_getProcessList=%d\n", rc);
    if (rc >= 0) {
        printf ("IC_adm_getProcessList=%s\n", answer);
    }

    // Отключение от сервера
    printf ("\n");
    rc = IC_unreg(username);
    printf ("IC_unreg=%d\n", rc);

    printf ("\nThat's All, Folks!\n\n");

    return 0;
}
