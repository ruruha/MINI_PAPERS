Axiomatic definition of LIFO and proof that stack satisfies LIFO



1. Abstract
    stack is the element data structure we learn at very first class, it is said that satisfies LIFO. 
    **LIFO is... the property everybody 'knows', Last Input First Out. But, this is not a strict definition, and nobody asks for it.**
    So, I tried to mathmatically define LIFO and stack satisfies that.



2. Area of discussion
    In this context, we assume that every abstraction that OS and computer system gives are trustable enough, 
    which means we have about 256GB memory space available... and every varible names are linked to memory address by compiler.
    This could be false of course, but this is kind of 'axiom' that system gives us to discuss only about data structure's properties.

    **So, what area do we discuss?: we have 'infinite' memory space and we can link there with variable names, just thick of what C does.**



3. Stack data structure

    The following is well_known implementation of Stack
    struct Stack{
        int size;
        int capacity;
        int* arr;
    };
    void push(struct& Stack, int data){
        if(Stack->size < Stack-> capacity) Stack -> arr[Stack->size++] = data;
    }
    int pop(struct& Stack){
        if(!Stack->size) Stack-> arr[--Stack->size];
        else return Null;  // assume that 'Null' is defined to some useless data.
    }



4. LIFO's axiomatic definition  
    Before we discuss about Stack above, think about what we want to that, it's LIFO.
    But what if LIFO? Is it well_defined at every inputs? And can be mathmatically defined?
    I will suggest a definition of that.



    Let's say that LIFO is a function, which maps sequences of finite instructions to sequences of results.
    LIFO: A -> B,
    A = ({<>}) + (INST) + (INST * INST) + (INST * INST * INST) ..... 
    INST means all 'pop' and 'push' instructions, (INST * INST) means 2-length sequence of elements of INST.
    So, A is the Union of all definte sequences of 'pop' and 'push'.
    B = ({<>}) + (N) + (N * N) + (N * N * N) ..... (N is set of all numbers)
    So, B is all finite sequence of all integers.
    {<>} is empty sequence.

    LIFO is mapping between A and B. And I suggest some axioms of this.



    **1. LIFO returns '<>', an empty sequence when input sequence is empty, or it is full of only 'pop' or 'push'**
    This is like a return condition of recursive function.
    When input sequence is empty, or full of only one type of instructions, it returns empty sequence.

    Next axiom is better to write as some formula

    **2. LIFO(A1 + <push(a), pop> + A2) = <a> + LIFO(A1 + A2), for <push(a), pop> is the first subsequence of whole instruction sequece. where A1 and A2 are elements of A.**
    This means LIFO's input can be separated into two parts when there is <push, pop> subsequence.
    And the result can be separated also.

    These two are all, really, our LIFO's abstract concept can be summarized to that two axioms.


5. I'll do later
    Define state of Stack, and Stack satisfied LIFO using state_preservation concept of stack.
    My first commit, this seems too trivial and i have no idea how far i could do this... ㅠㅠ