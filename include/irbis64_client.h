// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#ifndef IRBIS64_CLIENT_H
#define IRBIS64_CLIENT_H

#if defined(_WIN64) || defined(__WIN64__)
#error 64-bit mode not supported!
#endif

#define IRBIS_IMPORT /* __declspec(dllimport) */
#define IRBIS_CALL   __stdcall

#ifdef __cplusplus
extern "C" {
#endif

// ===================================================================
// Функции общего назначения
// ===================================================================

// Регистрация клиента на сервере
IRBIS_IMPORT int IRBIS_CALL IC_reg
    (
        const char *host,
        const char *port,
        char arm,
        const char *user,
        const char *password,
        char **answer,
        int bufSize
    );

// Раз-регистрация клиента на сервере (сигнал об окончании работы)
IRBIS_IMPORT int IRBIS_CALL IC_unreg
    (
        const char *user
    );

// Установка интервала подтверждения
IRBIS_IMPORT int IRBIS_CALL IC_set_client_time_live
    (
        int option
    );

// Установка времени появления заставки ожидания
IRBIS_IMPORT int IRBIS_CALL IC_set_show_waiting
    (
        int option
    );

// Установка режима работы через Web-шлюз
IRBIS_IMPORT int IRBIS_CALL IC_set_webserver
    (
        int option
    );

// Установка имени шлюза при работе через Web-шлюз
IRBIS_IMPORT int IRBIS_CALL IC_set_webcgi
    (
        const char *cgi
    );

// Установка режима ожидания ответа от сервера
IRBIS_IMPORT int IRBIS_CALL IC_set_blocksocket
    (
        int option
    );

// Определение завершения очередного обращения к серверу
IRBIS_IMPORT int IC_isbusy(void);

// Обновление INI-файла - профиля пользователя на сервере
IRBIS_IMPORT int IRBIS_CALL IC_update_ini
    (
        const char *cgi
    );

// ===================================================================
// Функции работы с ресурсами
// ===================================================================

// Чтение текстового ресурса (файла)
IRBIS_IMPORT int IRBIS_CALL IC_getresourse
    (
        int path,
        const char *database,
        const char *filename,
        char **answer,
        int bufSize
    );

// Очистка памяти кэша
IRBIS_IMPORT int IC_clearresourse(void);

// Групповое чтение текстовых ресурсов
IRBIS_IMPORT int IRBIS_CALL IC_getresoursegroup
    (
        char **context,
        char **answer,
        int bufSize
    );

// Чтение двоичного ресурса
IRBIS_IMPORT int IRBIS_CALL IC_getbinaryresourse
    (
        int path,
        const char *database,
        const char *filename,
        char **answer,
        int bufSize
    );

// Запись текстового ресурса на сервер
IRBIS_IMPORT int IRBIS_CALL IC_putresourse
    (
        int path,
        const char *database,
        const char *filename,
        const char *answer
    );

// ===================================================================
// Функции для работы с файлом документов (мастер-файлом) базы данных
// ===================================================================

// Чтение записи
IRBIS_IMPORT int IRBIS_CALL IC_read
    (
        const char *database,
        int mfn,
        int lock,
        char **answer,
        int bufSize
    );

// Чтение записи с расформатированием
IRBIS_IMPORT int IRBIS_CALL IC_readformat
    (
        const char *database,
        int mfn,
        int lock,
        const char *format,
        char **record,
        int recordBufSize,
        char **formatted,
        int formattedBufSize
    );

// Запись/обновление записи в базе данных
IRBIS_IMPORT int IRBIS_CALL IC_update
    (
        const char *database,
        int lock,
        int ifUpdate,
        char **answer,
        int bufSize
    );

// Групповая запись/обновление записей в базе данных
IRBIS_IMPORT int IRBIS_CALL IC_updategroup
    (
        const char *database,
        int lock,
        int ifUpdate,
        char **answer,
        int bufSize
    );

// Разблокировать запись
IRBIS_IMPORT int IRBIS_CALL IC_runlock
    (
        const char *database,
        int mfn
    );

// Актуализировать запись
IRBIS_IMPORT int IRBIS_CALL IC_ifupdate
    (
        const char *database,
        int mfn
    );

// Получить максимальный MFN базы данных
IRBIS_IMPORT int IRBIS_CALL IC_maxmfn
    (
        const char *database
    );

// ===================================================================
// Функции для работы с записью
// ===================================================================

// Определить порядковый номер поля в записи
IRBIS_IMPORT int IRBIS_CALL IC_fieldn
    (
        const char *record,
        int tag,
        int occurrence
    );

// Прочитать значение заданного поля/подполя
IRBIS_IMPORT int IRBIS_CALL IC_field
    (
        const char *record,
        int fieldIndex,
        char delimiter,
        char *answer,
        int bufSize
    );

// ===================================================================
// Функции поиска
// ===================================================================

// Прямой (по словарю) поиск записей по заданному поисковому выражению
IRBIS_IMPORT int IRBIS_CALL IC_search
    (
        const char *database,
        const char *expression,
        int numberOfRecords,
        int firstRecord,
        const char *format,
        char *answer,
        int bufSize
    );

// Прямой (по словарю) поиск записей по заданному поисковому выражению
IRBIS_IMPORT int IRBIS_CALL IC_searchscan
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
    );

// ===================================================================
// Функции форматирования
// ===================================================================

// Расформатирование записи, заданной по номеру (mfn)
IRBIS_IMPORT int IRBIS_CALL IC_sformat
    (
        const char *database,
        int mfn,
        const char *format,
        char *answer,
        int bufSize
    );

// Расформатирование группы записей
IRBIS_IMPORT int IRBIS_CALL IC_sformatgroup
    (
        const char *database,
        const char *mfnList,
        const char *format,
        char *answer,
        int bufSize
    );

// ===================================================================
// Функции пакетной обработки
// ===================================================================

IRBIS_IMPORT int IRBIS_CALL IC_print
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
    );

// Формирование выходной формы в виде статистических распределений
IRBIS_IMPORT int IRBIS_CALL IC_stat
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
    );

// Выполнение задания на глобальную корректировку
IRBIS_IMPORT int IRBIS_CALL IC_gbl
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
    );

// ===================================================================
// Функции администратора
// ===================================================================

// Перезапустить сервер ИРБИС64
IRBIS_IMPORT int IC_adm_restartServer();

// Получить список удаленных документов
IRBIS_IMPORT int IRBIS_CALL IC_adm_getDeletedList
    (
        const char *database,
        char *answer,
        int bufSize
    );

// Получить общие сведения о базе данных: списки удаленных/
// заблокированных/неактуализированных, максимальный MFN
// и признак монопольной блокировки
IRBIS_IMPORT int IRBIS_CALL IC_adm_getAllDeletedLists
    (
        const char *database,
        char *answer,
        int bufSize
    );

// Опустошить базу данных
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbEmpty
    (
        const char *database
    );

// Удалить базу данных
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbDelete
    (
        const char *database
    );

// Создать новую базу данных электронного каталога
IRBIS_IMPORT int IRBIS_CALL IC_adm_newDb
    (
        const char *database,
        const char *description,
        int reader
    );

// Снять монопольную блокировку базы данных
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbUnlock
    (
        const char *database
    );

// Снять блокировку заданных записей
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbUnlockMfn
    (
        const char *database,
        const char *mfnList
    );

// Создать словарь базы данных заново
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbStartCreateDictionry
    (
        const char *database
    );

// Реорганизовать словарь базы данных
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbStartReorgDictionry
    (
        const char *database
    );

// Реорганизовать файл документов базы данных
IRBIS_IMPORT int IRBIS_CALL IC_adm_dbStartReorgMaster
    (
        const char *database
    );

// Получить список зарегистрированных (текущих) клиентов
IRBIS_IMPORT int IRBIS_CALL IC_adm_getClientList
    (
        char *answer,
        int bufSize
    );

// Получить список клиентов для доступа к серверу
IRBIS_IMPORT int IRBIS_CALL IC_adm_getClientsList
    (
        char *answer,
        int bufSize
    );

// Получить список запущенных процессов на сервере
IRBIS_IMPORT int IRBIS_CALL IC_adm_getProcessList
    (
        char *answer,
        int bufSize
    );

// Обновить список клиентов для доступа к серверу
IRBIS_IMPORT int IRBIS_CALL IC_adm_setClientsList
    (
        const char *clientMnu
    );

// ===================================================================
// Вспомогательные функции
// ===================================================================

// Подтверждение регистрации
IRBIS_IMPORT int IC_nooperation();

// Получить элемент исходной ссылки
IRBIS_IMPORT int IRBIS_CALL IC_getposting
    (
        const char *posting,
        int type
    );

// Заменить реальные разделители строк $0D0A на псевдоразделители $3130
IRBIS_IMPORT char* IRBIS_CALL IC_reset_delim
    (
        char *line
    );

// Заменить псевдоразделители $3130 на реальные разделители строк $0D0A
IRBIS_IMPORT char* IRBIS_CALL IC_delim_reset
    (
        char *line
    );

#ifdef __cplusplus
}
#endif

#endif // IRBIS64_CLIENT_H
