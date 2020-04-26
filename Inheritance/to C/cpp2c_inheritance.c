#include <stdio.h>
#include "cpp2c_inheritance_defs.h"
void void_doMaterials_()
{
	Materials mat;
    Material_t mat1;
    Material_t mat2;
    typedef struct{ Materials mat; Material_t mat_t; }MatTest;
  
  
	printf("\n--- Start doMaterials() ---\n\n");

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(enum Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));
    init_Material_t_Material_t_Types_(&mat1,OTHER);
    init_Material_t_Material_t_Types_(&mat2,METAL);
    printf("\n--- End doMaterials() ---\n\n");
}

void void_doPhysicalBox_()
{ 
	PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    void_PhysicalBox_PhysicalBox_double_double_double_Types_(&pb1,8, 6, 4,PLASTIC);
    void_PhysicalBox_PhysicalBox_Materials(&pb2,WOOD);
    void_PhysicalBox_PhysicalBox_double_double_double_(&pb3,7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox_operator_equal_(&pb4,&pb1);
    void_printp_ptrPhysicalBox(&pb4);
    void_printp_ptrPhysicalBox(&pb1);
   
    printf("pb4 %s pb1\n", pb4.box.width == pb1.box.width && pb4.box.height == pb1.box.height && pb4.box.length == pb1.box.length && pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    PhysicalBox_operator_equal_(&pb4, &pb3);
    void_printp_ptrPhysicalBox(&pb4);
    void_printp_ptrPhysicalBox(&pb3);
    printf("pb4 %s pb3\n", pb4.box.width == pb3.box.width && pb4.box.height == pb3.box.height && pb4.box.length == pb3.box.length && pb4.material.material == pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
}
int main()
{
	printf("\n--- Start main() ---\n\n");
    void_doMaterials_();
    void_doPhysicalBox_();
return 0;
}
