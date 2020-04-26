#include "poly.h"

#include <stdio.h>

int DefaultTextFormatter_Ider_next_id=0;

/*******initialize tables******************/
VTable_TextFormatter TextFormatter_table={
        virtualNotImlemented,
        TextFormatter_dctor_this

};
VTable_TextFormatter DefaultTextFormatter_table={
        DefaultTextFormatter_print_this_charPtr,
        DefaultTextFormatter_Dtor__this

};
VTable_PrePostFixer PrePostFixer_table={
        {
                PrePostFixer_print_this_charPtr,
                PrePostFixer_dctor_this
        },
        PrePostFixer_print_this_long_charPtr,
        PrePostFixer_getDefultSymbol_
};
VTable_PrePostFixer PrePostDollarFixer_table={
        {
                PrePostFixer_print_this_charPtr,
                PrePostDollarFixer_dctor_this
        },
        PrePostDollarFixer_print_this_long_char,
        PrePostDollarFixer_getDefult_symbol_
};
VTable_PrePostFixer PrePostHashFixer_table={
        {
                PrePostFixer_print_this_charPtr,
                PrePostHashFixer_dtor_this,
        },
        PrePostHashFixer_print_this_long_char,
        PrePostHashFixer_getDefult_symbol_

};
VTable_PrePostFixer PrePostFloatDollarFixer_table={
        {
                PrePostFixer_print_this_charPtr,
                PrePostFloatDollarFixer_dtor_this,
        },
        PrePostDollarFixer_print_this_long_char,
        PrePostFloatDollarFixer_getDefaultSymbol_this

};
VTable_PrePostFixer PrePostChecker_table={
        {
                PrePostFixer_print_this_charPtr,
                PrePostChecker_ctor_this
        },
        PrePostDollarFixer_print_this_long_char,
        PrePostFloatDollarFixer_getDefaultSymbol_this
};



/************TextFormatter functions's implementations**********/
void TextFormatter_ctor_this(struct TextFormatter* const this){
    this->vptr=&TextFormatter_table;
}
void virtualNotImlemented(const struct TextFormatter* const this,const char* text){
    printf("You called a pure virtual function!!!");
    exit(1);
}
void TextFormatter_dctor_this(struct TextFormatter* const this){  }

/************DefaultTextFormatter functions's implementations**********/
void DefaultTextFormatter_Ctor_this(DefaultTextFormatter* const this){
    TextFormatter_ctor_this(&this->m_textFormatter);
    this->m_textFormatter.vptr=&DefaultTextFormatter_table;
    this->m_id=DefaultTextFormatter_Ider_next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->m_id);

}
void DefaultTextFormatter_C_CtorDefaultTextFormatter_this_other(DefaultTextFormatter* const this,const DefaultTextFormatter* const other){
    TextFormatter_ctor_this(&this->m_textFormatter);
    this->m_textFormatter.vptr=&DefaultTextFormatter_table;
    this->m_id=DefaultTextFormatter_Ider_next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->m_id,this->m_id );

}
DefaultTextFormatter* DefaultTextFormatter_operatorassigment_this_other(DefaultTextFormatter* const this,const DefaultTextFormatter* const other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->m_id, this->m_id);
    return this;

}
void DefaultTextFormatter_Dtor__this(DefaultTextFormatter* const this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->m_id);
    this->m_textFormatter.vptr=&DefaultTextFormatter_table;
    TextFormatter_dctor_this(&this->m_textFormatter);

}
void DefaultTextFormatter_print_this_charPtr(const DefaultTextFormatter* const this, const char * text){
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}
DefaultTextFormatter* generateFormatterArray_(){
    DefaultTextFormatter* ptr=(DefaultTextFormatter* )malloc(3*sizeof(DefaultTextFormatter));
    int i = 0;
    for (; i < 3; ++i) {
        DefaultTextFormatter_Ctor_this(&ptr[i]);
    }
    return ptr;
}

/**************PrePost functions's implementations**********/
void PrePostFixer_ctor_this_charPtr_charPtr(PrePostFixer* const this,const char* prefix, const char* postfix){
    DefaultTextFormatter_Ctor_this(&this->m_defaultTextFormatter);
    this->m_defaultTextFormatter.m_textFormatter.vptr=&PrePostFixer_table;
    this->m_pre=prefix;
    this->m_post=postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", (this->m_pre), (this->m_post));
}
void PrePostFixer_cctor_this_other(PrePostFixer* const this,const PrePostFixer* const other){
    DefaultTextFormatter_C_CtorDefaultTextFormatter_this_other(&this->m_defaultTextFormatter,&other->m_defaultTextFormatter);
    this->m_pre=other->m_pre;
    this->m_post=other->m_post;
}
void PrePostFixer_dctor_this(PrePostFixer* this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);

    this->m_defaultTextFormatter.m_textFormatter.vptr=&PrePostFixer_table;

    DefaultTextFormatter_Dtor__this(&this->m_defaultTextFormatter);
}
void PrePostFixer_print_this_charPtr(PrePostFixer* this,const char* const text){
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->m_pre, text, this->m_post);
}
char PrePostFixer_getDefultSymbol_(){
    return '\0';
}

void PrePostFixer_print_this_long_charPtr(PrePostFixer* this,long num,const char* const symbol){
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->m_pre, symbol, num, this->m_post);
    }
    else
    {
        printf("%-60s | ","[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->m_pre, num, this->m_post);
    }
}

/**************PrePostDollar functions's implementations**********/
void PrePostDollarFixer_ctor_this_charPtr_charPtr(PrePostDollarFixer * const this,const char* prefix, const char* postfix){
    PrePostFixer_ctor_this_charPtr_charPtr(&this->m_PrePostFixer,prefix,postfix);
    this->m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostDollarFixer_table;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->m_PrePostFixer.m_pre, this->m_PrePostFixer.m_post);

}
void PrePostDollarFixer_cctor_this_other(PrePostDollarFixer* const this,const PrePostDollarFixer* const other){
    PrePostFixer_cctor_this_other(&this->m_PrePostFixer,&other->m_PrePostFixer);
    this->m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostDollarFixer_table;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->m_PrePostFixer.m_pre, this->m_PrePostFixer.m_pre);

}
void PrePostDollarFixer_dctor_this(PrePostDollarFixer* this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->m_PrePostFixer.m_pre, this->m_PrePostFixer.m_post);

    this->m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostDollarFixer_table;

    PrePostFixer_dctor_this(&this->m_PrePostFixer);
}
void PrePostDollarFixer_print_this_int_char(const PrePostDollarFixer * const this,int num, char symbol){
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    ((VTable_PrePostFixer*)this->m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr)->m_print_this_long_char(this,num,symbol);
    PrePostDollarFixer_print_this_long_char(this,(long)num, symbol);
}
void PrePostDollarFixer_print_this_long_char(const PrePostDollarFixer * const this,long num, char symbol){
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->m_PrePostFixer.m_pre, symbol, num, this->m_PrePostFixer.m_post);
    }
    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->m_PrePostFixer.m_pre, num, this->m_PrePostFixer.m_post);
    }
}
void PrePostDollarFixer_print_this_double_char(const PrePostDollarFixer* const this,double num, char symbol){
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%F%s\n", this->m_PrePostFixer.m_pre, symbol, num, this->m_PrePostFixer.m_post);

}
char PrePostDollarFixer_getDefult_symbol_(){
    return PrePostDollarFixer_DEFAULT_SYMBOL;
}
/**********PrePostHashFixer functions implementation*********/
void PrePostHashFixer_ctor_this_int(PrePostHashFixer* const this,int prc){
    PrePostDollarFixer_ctor_this_charPtr_charPtr(&this->m_PrePostDollarFixer,"===> ", " <===");
    this->m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostHashFixer_table;
    this->precision=prc;
}
void PrePostHashFixer_dtor_this(PrePostHashFixer* this){
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->m_PrePostDollarFixer.m_PrePostFixer.m_pre, this->m_PrePostDollarFixer.m_PrePostFixer.m_post);
    this->m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostHashFixer_table;
    PrePostDollarFixer_dctor_this(&this->m_PrePostDollarFixer);
}
void PrePostHashFixer_print_this_int_char(const PrePostHashFixer* const this,int num,char symbol){
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*F]%s\n", this->m_PrePostDollarFixer.m_PrePostFixer.m_pre, symbol, this->precision, num, this->m_PrePostDollarFixer.m_PrePostFixer.m_post);
}
void PrePostHashFixer_print_this_long_char(const PrePostHashFixer* const this,long num,char symbol){
    printf("%-60s | ","[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*F]%s\n", this->m_PrePostDollarFixer.m_PrePostFixer.m_pre, symbol, this->precision, num, this->m_PrePostDollarFixer.m_PrePostFixer.m_post);
}
char PrePostHashFixer_getDefult_symbol_(){
    return PrePostHashFixer_DEFAULT_SYMBOL;
}

/**********PrePostFloatFixer functions implementation*********/
void PrePostFloatDollarFixer_ctor_this_kcharPtr_kcharPtr(PrePostFloatDollarFixer * const this,char* prefix,char * postfix){
    PrePostDollarFixer_ctor_this_charPtr_charPtr(&this->m_PrePostDollarFixer,prefix,postfix);
    this->m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostFloatDollarFixer_table;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->m_PrePostDollarFixer.m_PrePostFixer.m_pre, this->m_PrePostDollarFixer.m_PrePostFixer.m_post);

}
void PrePostFloatDollarFixer_dtor_this(PrePostFloatDollarFixer* this){
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->m_PrePostDollarFixer.m_PrePostFixer.m_pre, this->m_PrePostDollarFixer.m_PrePostFixer.m_post);
    this->m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostFloatDollarFixer_table;
    PrePostDollarFixer_dctor_this(&this->m_PrePostDollarFixer);
}
void PrePostFloatDollarFixer_print_this_float(const PrePostFloatDollarFixer* const this, float num){
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    PrePostFloatDollarFixer_print_this_float_char(this, num, PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}
void PrePostFloatDollarFixer_print_this_float_char(const PrePostFloatDollarFixer* const this, float num,char symbol){
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2F%s\n", this->m_PrePostDollarFixer.m_PrePostFixer.m_pre, symbol, num, this->m_PrePostDollarFixer.m_PrePostFixer.m_post);

}
char PrePostFloatDollarFixer_getDefaultSymbol_this(const PrePostFloatDollarFixer* const this){
    return PrePostFloatDollarFixer_DEFAULT_SYMBOL;
}

/**********PrePostChecker function's implementations*******************/
void PrePostChecker_ctor_this(PrePostChecker*const this){
    PrePostFloatDollarFixer_ctor_this_kcharPtr_kcharPtr(&this->m_PrePostFloatDollarFixer,"[[[[ ", " ]]]]");
    this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostChecker_table;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer.m_pre, this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer.m_post);

}
void PrePostChecker_dtor_this(PrePostChecker* this){
    this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr=&PrePostChecker_table;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer.m_pre, this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer.m_post);
    PrePostFloatDollarFixer_dtor_this(&this->m_PrePostFloatDollarFixer);
}
void PrePostChecker_printThisSymbolUsingFunc_this(const PrePostChecker*const this){
    printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_getDefaultSymbol_this(&this->m_PrePostFloatDollarFixer));
}
void PrePostChecker_printThisSymbolDirectly_this(const PrePostChecker*const this){
    printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}
void PrePostChecker_printDollarSymbolByCastUsingFunc_this(const PrePostChecker*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_getDefaultSymbol_this((PrePostDollarFixer*)&this->m_PrePostFloatDollarFixer));
}
void PrePostChecker_printDollarSymbolByScopeUsingFunc_this(const PrePostChecker*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_getDefult_symbol_());

}
void PrePostChecker_printDollarSymbolByCastDirectly_this(const PrePostChecker*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);

}
void PrePostChecker_printDollarSymbolByScopeDirectly_this(const PrePostChecker*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);

}