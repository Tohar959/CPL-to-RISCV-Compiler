#include "symbolTable.h"
#include <stdarg.h> 

// Hash function for symbols
long int hash_func(char* str, long int table_size) {
    long int sum = 0;
    while (*str) {
        sum += (unsigned char)(*str);
        str++;
    }
    return sum % table_size;
}

// Check if a number is prime
bool is_prime(long int num) {
    if (num < 2)
        return false;

    if (num == 2 || num == 3)
        return true;

    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Get the next prime number greater than or equal to num
int nextPrime(long int num) {
    while (!is_prime(num)) {
        num++;
    }
    return num;
}

// Create a new symbol table
symbolTable* createTable() {
    const int init_size = 11;
    long int my_size = nextPrime(init_size);

    symbolTable* newTable = (symbolTable*)malloc(sizeof(symbolTable));
    if (!newTable) {
        fprintf(stderr, "Error in memory allocation for table\n");
        return NULL;
    }

    newTable->head = (symbol_node**)malloc(sizeof(symbol_node*) * my_size);
    if (!newTable->head) {
        fprintf(stderr, "Error in memory allocation for table head\n");
        free(newTable);
        return NULL;
    }

    newTable->size = my_size;
    newTable->count = 0;

    for (int i = 0; i < my_size; i++) {
        newTable->head[i] = NULL;
    }

    return newTable;
}

// Destroy a symbol table and free memory
void destroyTable(symbolTable* table) {
    if (!table) {
        fprintf(stderr, "Cannot delete an empty table\n");
        return;
    }

    for (long int i = 0; i < table->size; i++) {
        symbol_node* currentSymbol = table->head[i];
        while (currentSymbol) {
            symbol_node* tmp = currentSymbol->next;
            if (currentSymbol->attri)
                free(currentSymbol->attri);
            free(currentSymbol);
            currentSymbol = tmp;
        }
    }

    free(table->head);
    free(table);
}

// Lookup a symbol in the table
symbol_node* lookup(symbolTable* table, char* name) {
    if (!table || !name) {
        fprintf(stderr, "Invalid table or name\n");
        return NULL;
    }

    long int index = hash_func(name, table->size);
    symbol_node* current_node = table->head[index];

    while (current_node) {
        if (strcmp(current_node->name, name) == 0) {
            current_node->attri->isDeclared = true;
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

// Enter a new symbol into the table
symbol_node* enter(symbolTable* table, char* name, variable_type type, bool con) 
{
    if (type <= T_NONE || type > T_STRING) {
        fprintf(stderr, "INVALID TYPE %d for variable %s\n", type, name);
        return NULL;
    }
    if (!table || !name) {
        fprintf(stderr, "Invalid table or name\n");
        return NULL;
    }

    // Check if symbol already exists
    symbol_node* existing = lookup(table, name);
    if (existing) {
        return existing;
    }

    // Create a new symbol node
    symbol_node* newSymbol = (symbol_node*)malloc(sizeof(symbol_node));
    if (!newSymbol) {
        fprintf(stderr, "Error: Memory allocation failed for symbol.\n");
        return NULL;
    }

    newSymbol->attri = (attributes*)malloc(sizeof(attributes));
    if (!newSymbol->attri) {
        free(newSymbol);
        return NULL;
    }

    // Initialize all attributes
    strncpy(newSymbol->name, name, 9);
    newSymbol->name[9] = '\0';
    fprintf(stderr, "ENTER: Storing %s as type %d (received type %d)\n",
        name, type, type);
    if (type == T_NONE) {
        fprintf(stderr, "CRITICAL ERROR: T_NONE type passed to enter()\n");
        fprintf(stderr, "Current declaration: %s\n", name);
        fprintf(stderr, "Call stack should show how this happened\n");
        return NULL;
    }

    newSymbol->attri->type = type;
    fprintf(stderr, "SYMTAB: %s stored as type %d\n", name, type);
    newSymbol->attri->constant = con;
    newSymbol->attri->isDeclared = true;
    newSymbol->attri->line = 0;
    newSymbol->attri->offset = 0;
    memset(&newSymbol->attri->value, 0, sizeof(value_type));

    if (newSymbol->attri->type != type) {
        fprintf(stderr, "ERROR: Type mismatch! Expected %d got %d\n",
            type, newSymbol->attri->type);
    }

    long int index = hash_func(name, table->size);
    newSymbol->next = table->head[index];
    table->head[index] = newSymbol;

    table->count++;
    return newSymbol;
}

void set_attributes(symbol_node* entry, variable_type type)
{
    if (!entry)
    {
        fprintf(stderr, "There is no symbol\n");
        exit(EXIT_FAILURE);
    }

    if (entry->attri->constant == true)
    {
        fprintf(stderr, "The symbol is constant you cant change attribute");
        exit(EXIT_SUCCESS);
    }

    entry->attri->type = type;
}

variable_type get_attributes(symbol_node* entry)
{
    if (entry == NULL)
        return T_UNDEF;

    return entry->attri->type;
}





symbol_node* lookup_symbol(symbolTable* table, const char* name) {
    return lookup(table, (char*)name);
}


void resizeTable(symbolTable* table)
{
    long int oldSize = table->size;
    symbol_node** oldT = table->head;
    table->size = nextPrime(table->size * 2);
    table->head = (symbol_node**)malloc(sizeof(symbol_node*) * table->size);
    if (!table->head)
    {
        fprintf(stderr, "Malloc exception\n");
        exit(EXIT_FAILURE);
    }

    for (long int i = 0; i < table->size; i++)
    {
        table->head[i] = NULL;
    }

    table->count = 0;

    for (long int i = 0; i < oldSize; i++)
    {
        symbol_node* current_symbol = oldT[i];
        while (current_symbol)
        {
            symbol_node* next_symbol = current_symbol->next;
            long int nIndx = hash_func(current_symbol->name, table->size);
            current_symbol->next = table->head[nIndx];
            table->head[nIndx] = current_symbol;
            table->count++;
            current_symbol = next_symbol;
        }
    }

    free(oldT);
}