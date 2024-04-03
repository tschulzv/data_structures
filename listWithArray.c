
//***********************************************/
/** LIST ADT - ARRAY IMPLEMENTATION (Static List)
 * Tania Schulz
 **/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct _List {
	int *arr; // item array
    int size; 
    int max;
} AList;
typedef AList* List;


int isFull(List l){
    return l->size == l->max;
}

int isEmpty(List l){
    return l->size == 0;
}

int isNull(List l){
    return l == NULL;
}

List create(){
    // creating new list, assigning memory and checking if memory was assigned
    List new;
    new = (List)malloc(sizeof(struct _List));
    if (isNull(new)){return NULL;}
    // giving the new list initial values
    new -> size = 0;
    new -> max = MAX;
    new -> arr = (int*)malloc(sizeof(int) * new->max);
    return new;
}

int printList(List l){
    // if list is null, return
    if (l == NULL) {return 1;}
    // print values
    for (int i = 0; i < l->size; i++){
        printf("Position [%d]: %d \n", i, l->arr[i]);
    }
    return 0;
}

int insert(List l, int x, int pos){
    if (isNull(l) || isFull(l)) {return 1;}
    // auxiliary array 
    int* aux;
    aux = (int*)malloc(sizeof(int) * l->max);
    aux = (int*)l->arr; // copy of the array
    for(int i = l->size + 1; i > pos; i--){
        // n element in new array is n - 1 position in original array
        aux[i] = l->arr[i - 1]; 
    }
    aux[pos] = x; // the x element is assigned to its position
    // elements previous to [pos] stay the same
    l -> size++;
    l -> arr = aux;
    return 0;
}

int delete(List l, int index){
    if (isNull(l) || isEmpty(l)) {return 1;}
    int* aux; 
    aux = (int*)malloc(sizeof(int) * l->max);
    aux = l->arr;
    
    // copy n element from original array to n-1 element in aux array
    for (int i = l -> size - 1 ; i > index; i--){
        aux[i - 1] = l->arr[i];
    }
    l->size--;
    l->arr = aux;
    return 0;
}

int search(List l, int x){
    if (isNull(l)) { return 1; }
    for (int i = 0; i < l -> size; i++){
        if (l->arr[i] == x) {
            printf("Found in index [%d]\n", i);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

int dispose(List l){
    if (isNull(l)) { return 1; }
    free(l->arr);
    free(l);
    return 0;
}

int main()
{
    List list;
    list = create();
    insert(list, 8, 0);
    insert(list, 2, 1);
    insert(list, 5, 2);
    printList(list);
    insert(list, 7, 2);
    insert(list, 9, 0);
    search(list, 3);
    search(list, 9);
    search(list, 5);
    dispose(list);
    return 0;
}
