/**
*   DJB2 testing
*   Max Kelly
*
*   for more explanation on DJB2:
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
*   This is the algorithm to implement DJB2.  The key difference between this and DJB2a is that DJB2 uses XOR instead of +.
*   Yes, the numbers 5381 and 33 are import here.  Why?  It has to do with math I am unfamiliar with
*   You can get one possible answer here: http://stackoverflow.com/questions/1579721/why-are-5381-and-33-so-important-in-the-djb2-algorithm
*   In case the above link is taken down, I will include the answer below in a giant block comment after all my code
*/
unsigned long hash(unsigned char *str){
    unsigned long hash = 5381;
    int c;

    while(c = *str++){ // iterate through the string
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

int main(int argc, char *argv[])
{
    const char *msg = "this is a stupid game. i hate it and we should stop playing it";
    printf("This will make an DJB2 hash\n");
    printf("orig msg: %s", msg);
    // this function will return the hash
    unsigned *encrypt = hash(msg);

    printf("\n\n\nThe DJB2 code generated by the msg is: \n");
//    printf("%s\n", encrypt);
    printf("%lu\n",hash(msg));

    printf("\n");
    printf("The msg should be successfully encrypted with DJB2\n");
    system("pause");  //  uncomment this when ready to throw on GitHub
    return 0;
}


/**
*
*  Explanation for 5381 and 33 in case of missing link:
* DJBX33A (Daniel J. Bernstein, Times 33 with Addition)
*
* This is Daniel J. Bernstein's popular `times 33' hash function as
* posted by him years ago on comp.lang.c. It basically uses a function
* like ``hash(i) = hash(i-1) * 33 + str[i]''. This is one of the best
* known hash functions for strings. Because it is both computed very
* fast and distributes very well.
*
* The magic of number 33, i.e. why it works better than many other
* constants, prime or not, has never been adequately explained by
* anyone. So I try an explanation: if one experimentally tests all
* multipliers between 1 and 256 (as RSE did now) one detects that even
* numbers are not useable at all. The remaining 128 odd numbers
* (except for the number 1) work more or less all equally well. They
* all distribute in an acceptable way and this way fill a hash table
* with an average percent of approx. 86%.
*
* If one compares the Chi^2 values of the variants, the number 33 not
* even has the best value. But the number 33 and a few other equally
* good numbers like 17, 31, 63, 127 and 129 have nevertheless a great
* advantage to the remaining numbers in the large set of possible
* multipliers: their multiply operation can be replaced by a faster
* operation based on just one shift plus either a single addition
* or subtraction operation. And because a hash function has to both
* distribute good _and_ has to be very fast to compute, those few
* numbers should be preferred and seems to be the reason why Daniel J.
* Bernstein also preferred it.
*
*
* -- Ralf S. Engelschall <rse@engelschall.com>
*
*
*Magic Constant 5381:
*
*  1. odd number
*
*  2. prime number
*
*  3. deficient number
*
*  4. 001/010/100/000/101 b
*
*
*
*   And lastly, there is this final explanation proving that 5381 is just there for gits and shigs
*
* [...] practically any good multiplier works. I think you're worrying about the fact that 31c + d doesn't cover any reasonable range of hash values if c and d are between 0 and 255. That's why, when I discovered the 33 hash function and started using it in my compressors, I started with a hash value of 5381. I think you'll find that this does just as well as a 261 multiplier.
*/