#include<stdio.h>

void insert(int*, int(*)[], int, int);
void delete_pos(int*, int(*)[], int);
int search_element(int, int[], int);

int i;
char c;

void main() 
{
    int n, array[20], choice, element, pos, result, count, temp = 0;
    printf("Enter the size of the array(upto 18 elements): ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &array[i]);
    }
    count = n - 1;
    printf("\nThe array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    do
    {
        printf("\n1. Insert element at any position");
        printf("\n2. Insert element at the beginning");
        printf("\n3. Insert element at the end");
        printf("\n4. Delete element by first occurrence");
        printf("\n5. Delete element by position");
        printf("\n6. Search element by its position");
        printf("\n7. Search position of the element");
        printf("\n8. Revert the array");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                    printf("\nEnter the position at which you want to insert: ");
                    scanf("%d", &pos);
                    if (pos > n) {
                        printf("\nThe array has only %d elements", n);
                        break;
                    }
                    printf("\nEnter the element you want to insert: ");
                    scanf("%d", &element);
                    printf("\nThe array was: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    insert(&n, &array, element, pos);
                    printf("\nThe new array is: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    break;
            case 2:
                    printf("\nEnter the element you want to insert: ");
                    scanf("%d", &element);
                    printf("\nThe array was: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    insert(&n, &array, element, 1);
                    printf("\nThe new array is: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    break;
            case 3:
                    printf("\nEnter the element you want to insert: ");
                    scanf("%d", &element);
                    printf("\nThe array was: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    insert(&n, &array, element, n + 1);
                    printf("\nThe new array is: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    break;
            case 4:
                    printf("\nEnter the element you want to delete: ");
                    scanf("%d", &element);
                    printf("\nThe array was: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    result = search_element(n, array, element);
                    delete_pos(&n, &array, result);
                    printf("\nThe new array is: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    break;
            case 5:
                    printf("\nEnter the position of the element you want to delete: ");
                    scanf("%d", &pos);
                    if (pos > n)
                    {
                        printf("\nThe array has only %d elements", n);
                        break;
                    }
                    printf("\nThe array was: ");
                    for (i = 0; i < n; i++) 
                        printf("%d ", array[i]);
                    delete_pos(&n, &array, pos);   
                    printf("\nThe new array is: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", array[i]);                 
                    break;
            case 6:
                    printf("\nEnter the position of the element you want to search: ");
                    scanf("%d", &pos);
                    if (pos > n){
                        printf("\nThe position entered is out of scope");
                        break;
                    }
                    if (pos != 0 && !(pos > n))
                        printf("\nThe element at %d position is %d", pos, array[pos - 1]);
                    break;
            case 7:
                    printf("\nEnter the element whose position you want to know: ");
                    scanf("%d", &element);
                    result = search_element(n, array, element);
                    if (result != 0)
                    {
                        printf("\n%d is present at %d poistion", element, result);
                    }
                    else
                    {
                        printf("\n%d is not present in the array", element);
                    }
                    
                    break;
            case 8:
                    printf("\nOriginal array: ");
                    for (i = 0; i < n; i++) 
                    {
                        printf("%d ", array[i]);
                    }
                    printf("\nReverted array: ");
                    for (i = n - 1; i >= 0; i--) 
                    {
                        printf("%d ", array[i]);
                    }
                    break;
            default:
                    printf("Wrong choice");
        }
        printf("\nDo you want to perform more operations(y/n): ");
        fflush(stdin);
        scanf("%c", &c);
    } while (c == 'y' || c == 'Y');
}

int search_element(int n, int array[], int element) 
{
    for (i = 0; i < n; i++) 
    {
        if (element == array[i])
        {
            return(i+1);
        }
    }
    if (i == n)
    {
        printf("\nElement not found");
        return(0);
    }
}

void delete_pos(int *n, int (*array)[], int pos)
{
    for (i = 0; i < *n; i++)
        if (i + 1 == pos)
            break;
    if (i < *n)
    {
        *n = *n - 1;
        for (int j = i; j < *n; j++)
            (*array)[j] = (*array)[j + 1]; 
    }
}

void insert(int *n, int (*array)[], int element, int pos)
{
    *n = *n + 1;
    for (i = *n; i >= pos; i--)
        (*array)[i] = (*array)[i - 1];
    (*array)[pos - 1] = element;
}