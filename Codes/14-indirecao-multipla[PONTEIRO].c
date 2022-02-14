#include <stdio.h>

typedef struct{
    char *name; // Nome do empregado
    int id; // ID do empregado
}EMPLOYEE;

int main(){

    EMPLOYEE emp1={"Jhon",1001}, emp2={"Alex",1002}, emp3={"Taylor",1003};
    EMPLOYEE *arr[3]={&emp1, &emp2, &emp3};
    EMPLOYEE **ptr=arr;
    int i;

    for ( i = 0; i < 3; i++){

        printf("Employee number %d: %s %d\n", i+1, (**(ptr+i)).name, (**(ptr+i)).id);
        
    }
    
    return 0;

}