
#ifndef NIGAMIGA_CMDLINE_BUFFER_H
#define NIGAMIGA_CMDLINE_BUFFER_H

#include <sys/unistd.h>

typedef struct{
    char*       buffer;
    uint32_t    buffer_length;
    uint32_t    input_length;
} InputBuffer;

InputBuffer* init_input_buffer();
void read_input_buffer(InputBuffer* input_buffer);
void print_prompt();
void close_input_buffer(InputBuffer* input_buffer);

#endif //NIGAMIGA_CMDLINE_BUFFER_H
