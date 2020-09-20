#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>
#include <sqlext.h>

WCHAR szDSN[] = L"Driver={Microsoft Excel Driver (*.xls)};DSN='';CREATE_DB=\"C:\\test\\newfile.xls\";DBQ=C:\\test\\newfile.xls;READONLY=0;";

BOOL ExecuteSql(HDBC hDbc, LPWSTR query){

    RETCODE rc;
    HSTMT hStmt;
    WCHAR bufstate[10]=L"";
    WCHAR buferr[1024]=L"";
    SQLINTEGER i;
    SQLSMALLINT cch;
    BOOL result;

    wprintf(L">%s\n", query);

    /* Prepare SQL query */
    rc = SQLAllocStmt(hDbc,&hStmt);

    if(!SQL_SUCCEEDED(rc)){
        wprintf(L"SQLAllocStmt failed\n");
        return FALSE;
    }

    rc = SQLPrepare(hStmt, query, SQL_NTS);

    if(!SQL_SUCCEEDED(rc)){
        wprintf(L"SQLPrepare failed\n");
        SQLFreeHandle(SQL_HANDLE_STMT,hStmt);
        return FALSE;
    }

    /* Excecute the query */
    rc = SQLExecute(hStmt);

    if (SQL_SUCCEEDED(rc)) {
        wprintf(L"SQL Success\n");
        result = TRUE;
    }
    else{
        SQLGetDiagRec(SQL_HANDLE_STMT,hStmt,1,bufstate,&i,buferr,sizeof(buferr)/sizeof(buferr[0]),&cch);
        wprintf(L"SQL Error. Code: %d; Message: %s\n",i,buferr);
        result = FALSE;
    }

    SQLFreeHandle(SQL_HANDLE_STMT,hStmt);
    return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL,"Russian");
HENV    hEnv;
HDBC    hDbc;

/* ODBC API return status */
RETCODE rc;

int     iConnStrLength2Ptr;
WCHAR    szConnStrOut[256];

/* Allocate an environment handle */
rc = SQLAllocEnv(&hEnv);
/* Allocate a connection handle */
rc = SQLAllocConnect(hEnv, &hDbc);

/* Connect to the database */
rc = SQLDriverConnect(hDbc, NULL, (WCHAR*)szDSN,
    SQL_NTS, (WCHAR*)szConnStrOut,
    255, (SQLSMALLINT*)&iConnStrLength2Ptr, SQL_DRIVER_NOPROMPT);

if (SQL_SUCCEEDED(rc))
{
    wprintf(L"Successfully connected to database. Data source name: \n  %s\n",
        szConnStrOut);

    ExecuteSql(hDbc,L"CREATE TABLE [Test] ([Name] TEXT, [Surname] TEXT)");
    ExecuteSql(hDbc,L"INSERT INTO [Test] VALUES ('John','Smith')");
}
else
{
    wprintf(L"Couldn't connect to %s.\n",szDSN);
}

/* Disconnect and free up allocated handles */
SQLDisconnect(hDbc);
SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

getchar();
return 0;
}
