/*--- stacks.h ---------------------------- Listing 2-6 ---------
 *  Header file for stack operations
 *-------------------------------------------------------------*/

#ifndef STACKS_H
#define STACKS_H    1

//#ifdef IN_STACK_LIB
//#define StkExtern
//#else
//#define StkExtern   extern
//#endif

#define TEXT_SIZE 20    /* the maximum size of our text string */

struct stack_struct {
    struct StkElement *base;        /* point to base of stack */
    int stack_size;  /* number of elements */
    int min_stack;   /* bottom-most element */
    int max_stack;   /* last possible element */
    int top;         /* current top */
};

typedef struct stack_struct Stack;

void ClearStack(Stack *);

Stack *CreateStack(int);

int PopElement(Stack *, struct StkElement *);

int PushElement(Stack *, struct StkElement *);

struct StkElement *
ViewElement(Stack *, int);

/*--- Application-specific material goes below ---*/

struct StkElement {
    struct StkElement *link[2];
    char text[20];
};

#endif
