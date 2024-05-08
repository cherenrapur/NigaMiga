
#ifndef NIGAMIGA_META_CMD_H
#define NIGAMIGA_META_CMD_H

#include <string.h>
#include "statement.h"
#include "cmdLine/cmdLine_Buffer.h"

typedef enum{
    STATEMENT_META_SUCCESS,
    STATEMENT_META_FAILURE
} MetaStatementType;

MetaStatementType check_meta_command(InputBuffer* input_buffer, Statement* statement);
void prepare_meta_command();
void execute_meta_exit(InputBuffer* input_buffer);

#endif //NIGAMIGA_META_CMD_H
