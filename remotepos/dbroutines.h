#ifndef DBROUTINES_H
#define DBROUTINES_H

#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int myupdatedb(sqlite3* db, int pid, float lat, float lon);

#endif // DBROUTINES_H
