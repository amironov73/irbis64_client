#define IRBIS_CALL   __stdcall

int IRBIS_CALL IC_reg
    (
        const char *host,
        const char *port,
        char arm,
        const char *user,
        const char *password,
        char *answer,
        int bufSize
    )
{
   return 0;
}

int IRBIS_CALL IC_unreg
        (
            const char *user
        )
{
   return 0;
}

int IRBIS_CALL IC_set_client_time_live
    (
        int option
    )
{
   return 0;
}

int IRBIS_CALL IC_set_show_waiting
    (
        int option
    )
{
   return 0;
}

int IRBIS_CALL IC_set_webserver
    (
        int option
    )
{
   return 0;
}

int IRBIS_CALL IC_set_webcgi
    (
        const char *cgi
    )
{
   return 0;
}

int IRBIS_CALL IC_set_blocksocket
    (
        int option
    )
{
   return 0;
}

int IC_isbusy (void)
{
   return 0;
}

int IRBIS_CALL IC_update_ini
    (
        const char *cgi
    )
{
   return 0;
}

int IRBIS_CALL IC_getresourse
    (
        int path,
        const char *database,
        const char *filename,
        char **answer,
        int bufSize
    )
{
   return 0;
}

int IC_clearresourse (void)
{
   return 0;
}

int IRBIS_CALL IC_getresoursegroup
    (
        char **context,
        char **answer,
        int bufSize
    )
{
   return 0;
}

int IRBIS_CALL IC_getbinaryresourse
    (
        int path,
        const char *database,
        const char *filename,
        char **answer,
        int bufSize
    )
{
   return 0;
}

// «апись текстового ресурса на сервер
int IRBIS_CALL IC_putresourse
    (
        int path,
        const char *database,
        const char *filename,
        const char *answer
    )
{
   return 0;
}

int IRBIS_CALL IC_read
    (
        const char *database,
        int mfn,
        int lock,
        char **answer,
        int bufSize
    )
{
   return 0;
}

int IRBIS_CALL IC_readformat
    (
        const char *database,
        int mfn,
        int lock,
        const char *format,
        char **record,
        int recordBufSize,
        char **formatted,
        int formattedBufSize
    )
{
   return 0;
}

int IRBIS_CALL IC_update
    (
        const char *database,
        int lock,
        int ifUpdate,
        char **answer,
        int bufSize
    )
{
   return 0;
}

int IRBIS_CALL IC_updategroup
    (
        const char *database,
        int lock,
        int ifUpdate,
        char **answer,
        int bufSize
    )
{
   return 0;
}

int IRBIS_CALL IC_runlock
    (
        const char *database,
        int mfn
    )
{
   return 0;
}

int IRBIS_CALL IC_ifupdate
    (
        const char *database,
        int mfn
    )
{
   return 0;
}

int IRBIS_CALL IC_maxmfn
    (
        const char *database
    )
{
   return 0;
}

int IRBIS_CALL IC_fieldn
    (
        const char *record,
        int tag,
        int occurrence
    )
{
   return 0;
}

int IRBIS_CALL IC_field
    (
        const char *record,
        int fieldIndex,
        char delimiter,
        char *answer,
        int bufSize
    )
{
   return 0;
}

