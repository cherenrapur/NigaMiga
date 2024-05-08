

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char*       buffer;
    uint32_t    buffer_length;
    uint32_t    input_length;
} InputBuffer;

/**
 * @brief Used to initialize cmd buffer
 *
 * @return Pointer to newly initialized buffer
 * */
InputBuffer* init_input_buffer()
{
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    if(input_buffer == NULL)
    {
        perror("Error initializing buffer.\n");
        exit(EXIT_FAILURE);
    }
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

void read_input_buffer(InputBuffer* input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer),&(input_buffer->buffer_length),stdin);
    if(bytes_read <= 0)
    {
        perror("Error handling input.\n");
        exit(EXIT_FAILURE);
    }
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read-1] = '\0';
}

void print_prompt() { printf("cmd: "); }

void close_input_buffer(InputBuffer* input_buffer)
{
    printf("Program exited successfully.\n");
    free(input_buffer->buffer);
    free(input_buffer);
}

