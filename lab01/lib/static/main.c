#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "library.c"


static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxy";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}
char* rand_string_alloc(size_t size)
{
    char *s = malloc(size + 1);
    if (s) {
        rand_string(s, size);
    }
    return s;
}










int main(){
    PhoneBook * phoneBook = createPB('l');
    addContactToPhoneBook(phoneBook,"przemek","moskala", "mail", "123123123","12-23-2222","adr");


    for(int i =0 ;i <25; i++)
        addContactToPhoneBook(phoneBook,rand_string_alloc(rand()%10+3),rand_string_alloc(rand()%1+3),rand_string_alloc(rand()%10+3),rand_string_alloc(9),rand_string_alloc(10),rand_string_alloc(rand()%10+3));
    printContact(searchContact(phoneBook, "przemek", "moskala"));
    displayPhoneBook(phoneBook);



}