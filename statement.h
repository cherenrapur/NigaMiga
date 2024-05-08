
#ifndef NIGAMIGA_STATEMENT_H
#define NIGAMIGA_STATEMENT_H

typedef enum {
    STATEMENT_EXIT,
    STATEMENT_INFO,
    STATEMENT_UNDEFINED
} StatementType;

typedef struct {
    StatementType type;
} Statement;


#endif //NIGAMIGA_STATEMENT_H
