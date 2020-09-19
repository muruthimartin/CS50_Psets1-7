#include<stdio.h>
#include<cs50.h>
int main(void)
{
    //load the get_string function from the cs50 library
    string name = get_string("What's your name?\n");
    
    printf("hello, %s\n", name);
}