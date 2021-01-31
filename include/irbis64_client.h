// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#ifndef IRBIS64_CLIENT_H
#define IRBIS64_CLIENT_H

#if defined(_WIN64) || defined(__WIN64__)
#error 64-bit mode not supported!
#endif

#define IRBIS_IMPORT /* __declspec(dllimport) */
#define IRBIS_CALL   __stdcall

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
IRBIS_IMPORT int IC_isbusy (void);

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
IRBIS_IMPORT int IC_clearresourse (void);

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

#endif // IRBIS64_CLIENT_H
