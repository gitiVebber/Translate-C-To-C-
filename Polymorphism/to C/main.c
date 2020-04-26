#include <stdio.h>
#include "poly.h"
#include <stdlib.h>

void doPrePostFixer(){
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    PrePostFixer_ctor_this_charPtr_charPtr(&angleBrackets,"<<< ", " >>>");
    angleBrackets.m_defaultTextFormatter.m_textFormatter.vptr->m_print(&angleBrackets,"Hello World!");
    PrePostFixer_print_this_long_charPtr(&angleBrackets,-777,'\0');
    PrePostFixer_print_this_long_charPtr(&angleBrackets,350,'#');
    PrePostFixer_print_this_long_charPtr(&angleBrackets,3.14,'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    PrePostFixer_dctor_this(&angleBrackets);
}

void doPrePostDollarFixer() {
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
    PrePostDollarFixer_ctor_this_charPtr_charPtr(&asterisks,"***** ", " *****");
    PrePostDollarFixer_print_this_int_char(&asterisks, -777 ,PrePostDollarFixer_DEFAULT_SYMBOL);
    PrePostDollarFixer_print_this_int_char(&asterisks, 350 ,'#');
    PrePostDollarFixer_print_this_double_char(&asterisks, 3.14f ,PrePostDollarFixer_DEFAULT_SYMBOL);

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    PrePostDollarFixer_dctor_this(&asterisks);


}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    PrePostChecker_ctor_this(&check);
    PrePostChecker_printThisSymbolUsingFunc_this(&check);
    PrePostChecker_printThisSymbolDirectly_this(&check);
    PrePostChecker_printDollarSymbolByCastDirectly_this(&check);
    PrePostChecker_printDollarSymbolByScopeDirectly_this(&check);
    PrePostChecker_printDollarSymbolByCastUsingFunc_this(&check);
    PrePostChecker_printDollarSymbolByScopeUsingFunc_this(&check);
    printf("\n--- end doPrePostChecker() ---\n\n");
    PrePostChecker_dtor_this(&check);
}

void doFormatterDynamicArray(){
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray_();
    int i = 0;
    for (; i < 3; ++i)
        formatters[i].m_textFormatter.vptr->m_print(&formatters[i],"Hello World!");
    for (i = 0; i < 3;i++)
        formatters[i].m_textFormatter.vptr->m_dctor(&formatters[i]);

    free(formatters);


    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}
void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
    PrePostFloatDollarFixer_ctor_this_kcharPtr_kcharPtr(&hashes,"### ", " ###");

    PrePostFloatDollarFixer_print_this_float(&hashes,-777);
    PrePostFloatDollarFixer_print_this_float_char(&hashes,350,'#');
    PrePostFloatDollarFixer_print_this_float(&hashes,3.14f);
    PrePostDollarFixer hashes2;
    PrePostDollarFixer_cctor_this_other(&hashes2,&hashes.m_PrePostDollarFixer);
    /*ask.....*/
    PrePostDollarFixer_print_this_double_char(&hashes2, 7.5, PrePostDollarFixer_getDefult_symbol_());
    PrePostDollarFixer_print_this_int_char(&hashes2, 100, PrePostDollarFixer_getDefult_symbol_());


    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    PrePostDollarFixer_dctor_this(&hashes2);
    PrePostFloatDollarFixer_dtor_this(&hashes);
}

void doFormatterPtrs(){
   /* printf("\n--- start doFormatterPtrs() ---\n\n");
    DefaultTextFormatter* pfmt[] =
            {
                    malloc(sizeof(PrePostDollarFixer)),
                    malloc(sizeof(Multiplier)),
                    malloc(sizeof(PrePostChecker))
            };
    PrePostDollarFixer_ctor_this_charPtr_charPtr(&pfmt[0],"!!! "," !!!");
    for (int i = 0; i < 3; ++i)
    {
        pfmt[i]->m_textFormatter.vptr->m_print(&pfmt[1],"Hello World!");
    }
        for (int i = 0; i < 3; ++i)
        pfmt[i]->print("Hello World!");
    for (int i = 2; i >= 0; --i)
        delete pfmt[i];
    printf("\n--- end doFormatterPtrs() ---\n\n");*/
}
void runAsPrePostFixerRef(const PrePostFixer* const pp){
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((VTable_PrePostFixer*)(pp->m_defaultTextFormatter.m_textFormatter.vptr))->m_print_this_long_char(pp,123,((VTable_PrePostFixer*)(pp->m_defaultTextFormatter.m_textFormatter.vptr))->m_getDefaultSymbol_());

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}
void runAsPrePostHashFixerRef(const PrePostHashFixer* const pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    PrePostHashFixer_print_this_int_char(pp,123,PrePostHashFixer_DEFAULT_SYMBOL);
    ((VTable_PrePostFixer*)(pp->m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr))->m_print_this_long_char(pp,123,((VTable_PrePostFixer*)(pp->m_PrePostDollarFixer.m_PrePostFixer.m_defaultTextFormatter.m_textFormatter.vptr))->m_getDefaultSymbol_());


    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* const pp) {
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    PrePostDollarFixer_print_this_int_char(pp,123,PrePostDollarFixer_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");

}

int main() {
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    PrePostHashFixer_ctor_this_int(&hfix,4);
	//runAsPrePostFixerRef(&hfix);
	runAsPrePostDollarFixerRef(&hfix);
//	runAsPrePostDollarFixerObj(hfix);
	runAsPrePostHashFixerRef(&hfix);

    printf("\n--- End main() ---\n\n");

    return 0;
}
