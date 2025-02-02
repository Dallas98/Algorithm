/*--- llapp.c ----------------------------- Listing 3-5 ---------
 *  Application-specific functions for linked-lists.
 *  Here used for hash table of words and word counts.
 *-------------------------------------------------------------*/

#include <stdlib.h>         /* for free() */
#include <string.h>         /* for strcmp() and strdup() */

#include "LLGEN.H"
#include "LLAPP.H"


void * CreateData1 ( void * data )
{
    struct NodeData1 * new_data;

    /*--- allocate the data structure ---*/

    new_data = (pND1) malloc ( sizeof ( struct NodeData1 ));

    if ( new_data == NULL )
        return ( NULL );

    /*--- move the values into the data structure ---*/
    new_data->tele =  strdup ( (char *) ((pND1) data)->tele );
    new_data->age =  strdup ( (char *) ((pND1) data)->age );
    new_data->name =  strdup ( (char *) ((pND1) data)->name );
    if ( new_data->tele == NULL )   /* error copying string */
    {
        free ( new_data );
        return ( NULL );
    }
    else
        return ( new_data );
}

int DeleteData1 ( void * data )
{
    /*
     * In this case, NodeData1 consists of: a pointer and an int.
     * The integer will be returned to memory when the node
     * is freed. However, the string must be freed manually.
     */

     free ( ((pND1) data)->name );
    free ( ((pND1) data)->age );
    free ( ((pND1) data)->tele );
     return ( 1 );
}
/*---------------------------------------------------------------
 * This function determines what to do when inserting a node
 * into a list if an existing node with the same data is found
 * in the list. In this case, since we are counting words, if a
 * duplicate word is found, we simply increment the counter.
 *
 * Note this function should return one of the following values:
 *      0       an error occurred
 *      1       delete the duplicate node
 *      2       insert the duplicate node
 * Any other processing on the duplicate should be done in this
 * function.
 *-------------------------------------------------------------*/

int DuplicatedNode1 ( Link new_node, Link list_node )
{            /* adding an occurrence to an existing word */

    return ( 1 );
}

int NodeDataCmp1 ( void *first, void *second )
{
    char *a = ((pND1)first)->tele;
    char *b = (char *)second;

    return ( strcmp ( ((pND1) first)->tele,
                      (char *)second));
}

/*=== Now the functions for the second linked list ===*/

void * CreateData2 ( void * data )
{
    struct NodeData2 * new_data;

    /*--- allocate the data structure ---*/

    new_data = (pND2) malloc ( sizeof ( struct NodeData2 ));

    if ( new_data == NULL )
        return ( NULL );

    /*--- move the values into the data structure ---*/
    new_data->word =  strdup ( (char *) ((pND1) data)->tele );

    if ( new_data->word == NULL )   /* error copying string */
    {
        free ( new_data );
        return ( NULL );
    }
    else
        return ( new_data );
}

int DeleteData2 ( void * data )
{
    /*
     * In this case, NodeData2 consists of a pointer.
     * The string must be freed manually.
     */

     free ( ((pND2) data)->word );
     return ( 1 );
}

/* do nothing on a duplicated nodes */
int DuplicatedNode2 ( Link new_node, Link list_node )
{
    return ( 1 );
}

int NodeDataCmp2 ( void *first, void *second )
{
    return ( strcmp ( ((pND2) first)->word,
                      ((pND2) second)->word ));
}
