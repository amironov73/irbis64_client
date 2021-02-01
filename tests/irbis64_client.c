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

// ������ ���������� ������� �� ������
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

//===================

int IRBIS_CALL IC_search
    (
        const char *database,
        const char *expression,
        int numberOfRecords,
        int firstRecord,
        const char *format,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_searchscan
    (
        const char *database,
        const char *expression,
        int numberOfRecords,
        int firstRecord,
        const char *format,
        int minMfn,
        int maxMfn,
        const char *sequential,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_sformat
    (
        const char *database,
        int mfn,
        const char *format,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_sformatgroup
    (
        const char *database,
        const char *mfnList,
        const char *format,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_print
    (
        const char *database,
        const char *table,
        const char *head,
        const char *modelField,
        const char *searchExpression,
        int minMfn,
        int maxMfn,
        const char *sequential,
        const char *mfnList,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_stat
    (
        const char *database,
        const char *statForm,
        const char *searchExpression,
        int minMfn,
        int maxMfn,
        const char *sequential,
        const char *mfnList,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_gbl
    (
        const char *database,
        int ifUpdate,
        const char *globalCorrection,
        const char *searchExpression,
        int minMfn,
        int maxMfn,
        const char *sequential,
        const char *mfnList,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IC_adm_restartServer()
{
    return 0;
}

int IRBIS_CALL IC_adm_getDeletedList
    (
        const char *database,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_getAllDeletedLists
    (
        const char *database,
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbEmpty
    (
        const char *database
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbDelete
    (
        const char *database
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_newDb
    (
        const char *database,
        const char *description,
        int reader
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbUnlock
    (
        const char *database
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbUnlockMfn
    (
        const char *database,
        const char *mfnList
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbStartCreateDictionry
    (
        const char *database
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbStartReorgDictionry
    (
        const char *database
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_dbStartReorgMaster
    (
        const char *database
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_getClientList
    (
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_getClientsList
    (
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_getProcessList
    (
        char *answer,
        int bufSize
    )
{
    return 0;
}

int IRBIS_CALL IC_adm_setClientsList
    (
        const char *clientMnu
    )
{
    return 0;
}

int IC_nooperation()
{
    return 0;
}

int IRBIS_CALL IC_getposting
    (
        const char *posting,
        int type
    )
{
    return 0;
}

char* IRBIS_CALL IC_reset_delim
    (
        char *line
    )
{
    return line;
}

char* IRBIS_CALL IC_delim_reset
    (
        char *line
    )
{
    return line;
}
