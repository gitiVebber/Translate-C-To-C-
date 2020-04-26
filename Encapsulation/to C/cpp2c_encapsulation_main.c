#include <stdio.h>
#include <string.h>
#include "cpp2c_encapsulation_defs.h"
char isFirst=0;
Box largeBox;
Box box99;

void void_thisFunc()
{
    
    printf("\n--- thisFunc() ---\n\n"); 
    if (isFirst==0)
    {
    void_Box_Box_double_double_double(&box99,99.0, 99.0, 99.0);
    isFirst=1;
    }
    Box_operator_equal_mult_Box_double(&box99, 10);
}

void void_doBoxes()
{
    Box b1;
    Box b2;
    Box b3;
    Box b4;
    Box copy;
    

    printf("\n--- Start doBoxes() ---\n\n");

    void_Box_Box_double(&b1,3);
    void_Box_Box_double_double_double(&b2,4, 5, 6);
    

    
    printf("b1 volume: %f\n", b1.width * b1.height * b1.length);
    printf("b2 volume: %f\n", b2.width * b2.height * b2.length);

    Box_operator_equal_mult_Box_double(&b1,1.5);
    Box_operator_equal_mult_Box_double(&b2,0.5);

    printf("b1 volume: %f\n", b1.width * b1.height * b1.length);
    printf("b2 volume: %f\n", b2.width * b2.height * b2.length);

    Box_operator_equal_(&b3 , &b2);
    Box_operator_equal_(&b4,&b3);
    Box_CopyBox_Box(&copy,&b2);
    Box_operator_equal_mult_Box_double(&copy,3);
    Box_CopyBox_Box(&b2,&copy);
    void_dis_Box_Box(&copy);
    printf("b3 %s b4\n",b1.width==b2.width && b1.height==b2.height && b1.length==b2.length  ? "equals" : "does not equal");

    Box_operator_equal_mult_Box_double(&b3,1.5);
    Box_operator_equal_mult_Box_double(&b4 ,0.5);
    printf("Now, b3 %s b4\n", b3.width==b4.width && b3.height==b4.height && b3.length==b4.length? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    void_dis_Box_Box(&b4);
    void_dis_Box_Box(&b3);
    void_dis_Box_Box(&b2);
    void_dis_Box_Box(&b1);
}

void void_doShelves_()
{
    Box aBox;
    Box bBox;
    Box cBox;
	 
    Shelf aShelf;
    

    printf("\n--- start doShelves() ---\n\n");

    void_Box_Box_double(&aBox, 5.0);
    void_Shelf_Shelf_(&aShelf);
    void_print_Shelf_(&aShelf);
    void_setBox_Shelf_int_Box_(&aShelf,1,largeBox);
    void_setBox_Shelf_int_Box_(&aShelf,0,aBox);
    void_print_Shelf_(&aShelf);
    message="This is the total volume on the shelf:";
    void_print_Shelf_(&aShelf);
    message="Shelf's volume:";
    void_print_Shelf_(&aShelf);

   
    void_Box_Box_double_double_double(&bBox,2,4,6);
    void_setBox_Shelf_int_Box_(&aShelf,1,bBox);
    void_dis_Box_Box(&bBox);
    void_Box_Box_double(&cBox,2);
    void_setBox_Shelf_int_Box_(&aShelf,2,cBox);
    void_dis_Box_Box(&cBox);
    void_print_Shelf_(&aShelf);
    printf("\n--- end doShelves() ---\n\n");
    void_dis_Shelf_Shelf(&aShelf);
    void_dis_Box_Box(&aBox);
}

int main()
{
   void_Box_Box_double_double_double(&largeBox,10.0, 20.0, 30.0);
   printf("\n--- Start main() ---\n\n");
   void_doBoxes();
   void_thisFunc();
   void_thisFunc();
   void_thisFunc();

   void_doShelves_();
        
   printf("\n--- End main() ---\n\n");
   
   void_dis_Box_Box(&box99);
   void_dis_Box_Box(&largeBox);

return 0;	
}
