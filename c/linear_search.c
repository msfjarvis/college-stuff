#include<stdio.h>
#include<conio.h>
void main()
{
    int array[10];
    int i, key, found = 0;
 
   
    printf("Enter the elements one by one : \n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Input array is \n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("Enter the element to be searched : \n");
    scanf("%d", &key);
    /*  Linear search begins */
    for (i = 0; i < 10 ; i++)
    {
        if (key == array[i] )
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
        printf("Element is present in the array\n");
    else
        printf("Element is not present in the array\n");
getch();
}
