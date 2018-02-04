#include "dbroutines.h"

#include <iostream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int myupdatedb(sqlite3* db, int pid, float lat, float lon) {
    // update database
    sqlite3_stmt *stmt;

    int Err;

    // Create a prepared statement.
    Err = sqlite3_prepare_v2(db, "insert into coordinates values (?, ?, ?)", -1, &stmt, NULL);
    if (Err != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare data: %s\n", sqlite3_errmsg(db));
        //sqlite3_close(db);
    }

    // Bind our string to the statement.
    Err = sqlite3_bind_int(stmt, 1, pid);
    Err = sqlite3_bind_double(stmt, 2, lat);
    Err = sqlite3_bind_double(stmt, 3, lon);
    if (Err != SQLITE_OK)
    {
        fprintf(stderr, "Failed to bind data: %s\n", sqlite3_errmsg(db));
    }

    // Execute the statement.
    Err = sqlite3_step(stmt);
    if (Err != SQLITE_DONE)
    {
        fprintf(stderr, "Failed to run query: %s\n", sqlite3_errmsg(db));
    }

    // Free the prepared statement.
    Err = sqlite3_finalize(stmt);
}
