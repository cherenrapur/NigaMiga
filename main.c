

#include <stdio.h>
#include "cmdLine/cmdLine_Buffer.h"
#include "statement.h"
#include "meta_cmd.h"

int main() {

    InputBuffer* inputBuffer = init_input_buffer();
    Statement statement;
    while(1)
    {
        print_prompt();
        read_input_buffer(inputBuffer);
        if(inputBuffer->buffer[0] == '.')
        {
            //first check if meta command is working
            switch(check_meta_command(inputBuffer, &statement))
            {
                case(STATEMENT_META_SUCCESS):
                    prepare_meta_command(inputBuffer);
                    continue;
                case(STATEMENT_META_FAILURE):
                    printf("Unrecognized meta command '%s'.\n", inputBuffer->buffer);
                    continue;
            }
        }
        //then execute
        switch(statement.type)
        {
            case(STATEMENT_META_EXIT):
                execute_meta_exit(inputBuffer);
                continue;
            case(STATEMENT_META_INFO):
                printf("Info command be here...\n");
                break;
            case(STATEMENT_META_UNDEFINED):
                printf("Show all commands here...\n");
        }
    }
    return 0;
}
