// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <strings.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';
int words_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //get the hash index
    int index = hash(word);

     node *cursor = table[index];

     while (cursor  != NULL)
     {
         if (strcasecmp(cursor->word, word) == 0)
         {
             return true;
         }
         cursor = cursor->next;
     }

     return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //our hash function will be the sum of ascii values
    int ascii_sum = 0;
    for (int i = 0; i < strlen(word); i++ )
    {
        ascii_sum += tolower(word[i]);

    }
    //ensure that the hash value does not outbond the predefined N value
    return (ascii_sum % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //open the dictionary file and handle error if file does not open
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
       return false;
    }
    //read the file word by word
    //create a buffer called word first

    char word[LENGTH + 1];

    //use the fscan f function to read through the file until you reach end of line

    while (fscanf(dict_file, "%s", word) != EOF)
    {
        //create a node and copy the word into the node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;

        }
        strcpy(n->word, word);
        n->next = NULL;

        //obtain an index for the hash
        int index = hash(word);

        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        words_count++;
    }
    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        // free the node without orphaning any node, you do that by creating a tmp node.
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}


