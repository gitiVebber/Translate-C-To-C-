#ifndef TASK3_POLY_H
#define TASK3_POLY_H
#include <stdlib.h>

extern int DefaultTextFormatter_Ider_next_id;
#define PrePostDollarFixer_DEFAULT_SYMBOL '$'
#define PrePostHashFixer_DEFAULT_SYMBOL '#'
#define PrePostFloatDollarFixer_DEFAULT_SYMBOL '@'


typedef struct TextFormatter TextFormatter;
typedef struct DefaultTextFormatter DefaultTextFormatter;
typedef struct PrePostFixer PrePostFixer;
typedef struct PrePostDollarFixer PrePostDollarFixer;
typedef struct PrePostHashFixer PrePostHashFixer;
typedef struct PrePostFloatDollarFixer PrePostFloatDollarFixer;
typedef struct PrePostChecker PrePostChecker;

/***********pointers to Functions********************/
typedef void (*TextFormatter_print_this_char)(struct TextFormatter* this, const char* text);
typedef void (*TextFormatter_dctor)(struct TextFormatter* this);
typedef void (*PrePostFixer_print_this_long_char)(struct TextFormatter* this, long num,const char text);
typedef char (*PrePostFixer_getDefaultSymbol_)();

/********virtual tables**********************/
typedef struct
{
    TextFormatter_print_this_char m_print;
    TextFormatter_dctor m_dctor;
} VTable_TextFormatter;

typedef struct
{
    VTable_TextFormatter m_vtable_TextFormatter;
    PrePostFixer_print_this_long_char m_print_this_long_char;
    PrePostFixer_getDefaultSymbol_ m_getDefaultSymbol_;
}VTable_PrePostFixer;



/**********structs****************/
struct TextFormatter
{
    VTable_TextFormatter* vptr;
};

struct DefaultTextFormatter
{
    struct TextFormatter m_textFormatter;
    int m_id;
};

struct PrePostFixer{
    DefaultTextFormatter m_defaultTextFormatter;
    char * m_pre;
    char * m_post;
};

struct PrePostDollarFixer{
    PrePostFixer m_PrePostFixer;
};

struct PrePostHashFixer{
    PrePostDollarFixer m_PrePostDollarFixer;
    int precision;
};

struct PrePostFloatDollarFixer{
    PrePostDollarFixer m_PrePostDollarFixer;
};
struct PrePostChecker{
    PrePostFloatDollarFixer m_PrePostFloatDollarFixer;
};

/******TextFormatter functions defenition*********/
void TextFormatter_ctor_this(struct TextFormatter* const this);
void virtualNotImlemented(const struct TextFormatter* const this,const char* text);
void TextFormatter_dctor_this(struct TextFormatter* const this);
/***operator=*/

/************DefultTextFormatter functions defenition***********/
void DefaultTextFormatter_Ctor_this(DefaultTextFormatter* const this);
void DefaultTextFormatter_C_CtorDefaultTextFormatter_this_other(DefaultTextFormatter* const this,const DefaultTextFormatter* const other);
DefaultTextFormatter* DefaultTextFormatter_operatorassigment_this_other(DefaultTextFormatter* const this,const DefaultTextFormatter* const other);
void DefaultTextFormatter_Dtor__this(DefaultTextFormatter* const this);
void DefaultTextFormatter_print_this_charPtr(const DefaultTextFormatter* const this, const char * text);

DefaultTextFormatter* generateFormatterArray_();

/***********PrePost functions defenition********/
void PrePostFixer_ctor_this_charPtr_charPtr(PrePostFixer* const this,const char* prefix, const char* postfix);
void PrePostFixer_cctor_this_other(PrePostFixer* const this,const PrePostFixer* const other);
void PrePostFixer_dctor_this(PrePostFixer* this);
void PrePostFixer_print_this_charPtr(PrePostFixer* this,const char* const text);
void PrePostFixer_print_this_long_charPtr(PrePostFixer* this,long num,const char* const symbol);
char PrePostFixer_getDefultSymbol_();

/***********PrePostDollarFixer functions defenition********/
void PrePostDollarFixer_ctor_this_charPtr_charPtr(PrePostDollarFixer * const this,const char* prefix, const char* postfix);
void PrePostDollarFixer_cctor_this_other(PrePostDollarFixer* const this,const PrePostDollarFixer* const other);
void PrePostDollarFixer_dctor_this(PrePostDollarFixer* this);
void PrePostDollarFixer_print_this_int_char(const PrePostDollarFixer* const this,int num, char symbol);
void PrePostDollarFixer_print_this_long_char(const PrePostDollarFixer* const this,long num, char symbol);
void PrePostDollarFixer_print_this_double_char(const PrePostDollarFixer* const this,double num, char symbol);
char PrePostDollarFixer_getDefult_symbol_();

/************PrePostHashFixer functions implementations***********/
void PrePostHashFixer_ctor_this_int(PrePostHashFixer* const this,int prc);
void PrePostHashFixer_dtor_this(PrePostHashFixer* this);
void PrePostHashFixer_print_this_int_char(const PrePostHashFixer* const this,int num,char symbol);
void PrePostHashFixer_print_this_long_char(const PrePostHashFixer* const this,long num,char symbol);
char PrePostHashFixer_getDefult_symbol_();

/**********PrePostFloatDollarFixer function implementations***********/
void PrePostFloatDollarFixer_ctor_this_kcharPtr_kcharPtr(PrePostFloatDollarFixer * const this,char* prefix,char * postfix);
void PrePostFloatDollarFixer_cctor_this_other(PrePostFloatDollarFixer * const this,const PrePostFloatDollarFixer* const other);
void PrePostFloatDollarFixer_dtor_this(PrePostFloatDollarFixer* this);
void PrePostFloatDollarFixer_print_this_float(const PrePostFloatDollarFixer* const this, float num);
void PrePostFloatDollarFixer_print_this_float_char(const PrePostFloatDollarFixer* const this, float num,char symbol);
char PrePostFloatDollarFixer_getDefaultSymbol_this(const PrePostFloatDollarFixer* const this);

/***********PrePostChecker functions defenitions**************************/
void PrePostChecker_ctor_this(PrePostChecker*const this);
void PrePostChecker_dtor_this(PrePostChecker* this);
void PrePostChecker_printThisSymbolUsingFunc_this(const PrePostChecker*const this);
void PrePostChecker_printThisSymbolDirectly_this(const PrePostChecker*const this);
void PrePostChecker_printDollarSymbolByCastUsingFunc_this(const PrePostChecker*const this);
void PrePostChecker_printDollarSymbolByScopeUsingFunc_this(const PrePostChecker*const this);
void PrePostChecker_printDollarSymbolByCastDirectly_this(const PrePostChecker*const this);
void PrePostChecker_printDollarSymbolByScopeDirectly_this(const PrePostChecker*const this);
#endif TASK3_POLY_H