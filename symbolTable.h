#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h" 


// Attributes structure for symbol table entries
typedef struct attributes {
    variable_type type;
    bool constant;
    int line;
    bool isDeclared;
    value_type value;
    int offset;  // Add this line
} attributes;

// Symbol node structure (linked list for chaining)
typedef struct symbol_node {
    char name[50];
    attributes* attri;
    struct symbol_node* next;
} symbol_node;

// Symbol table structure
typedef struct {
    symbol_node** head;
    long int size;
    long int count;
} symbolTable;

// Function declarations
long int hash_func(char* str, long int table_size);
bool is_prime(long int num);
int nextPrime(long int num);
symbolTable* createTable();
void destroyTable(symbolTable* table);
symbol_node* enter(symbolTable* table, char* name, variable_type type, bool con);
symbol_node* lookup(symbolTable* table, char* name);
void set_attributes(symbol_node* entry, variable_type type);
variable_type get_attributes(symbol_node* entry);
void resizeTable(symbolTable* table);
void emit(const char* format, ...);
extern symbol_node* lookup_symbol(symbolTable* table, const char* name);


#endif
