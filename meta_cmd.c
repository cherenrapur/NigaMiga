

#include "meta_cmd.h"
#include "cmdLine/cmdLine_Buffer.h"

MetaStatementType check_meta_command(InputBuffer* input_buffer, Statement* statement)
{
    if(strncmp(input_buffer->buffer, ".exit", 5) == 0)
    {
        statement->type = STATEMENT_META_SUCCESS;
    }
    else if(strncmp(input_buffer->buffer, ".help", 5) == 0)
    {
        statement->type = STATEMENT_META_SUCCESS;
    }
    else
    {
        statement->type = STATEMENT_META_FAILURE;
    }
}

void prepare_meta_command()
{

}
void execute_meta_exit(InputBuffer* input_buffer)
{
    close_input_buffer(input_buffer);
}
