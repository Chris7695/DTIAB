//
// DTIAB is a tool that converts any integer to its binary representation.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct moduloResults {
    int result, rest;
};

typedef struct moduloResults Struct;

// moduloINT gibt sowohl Quotient und Rest als Struct zurück.
Struct moduloINT(int in)
{
    Struct s;
    s.rest = in % 2;
    s.result = in / 2;

    return s;
}

// sizeArray bestimmt die benötigte Binary Array Größe.
int sizeArray(int in)
{
    int i = 0;
    while (in > 0)
    {
        in = in / 2;
        i++;
    }

    return i;
}

int main(int argc, char *argv[]) {
    int i, length = 0;
    Struct st;

    if (argc != 2) {
        printf("falsche Argumentanzahl, Format: %s <WERT>", argv[0]);
        return 1;
    }

    // Eingabe Wert
    st.result = atoi(argv[1]);

    int arraySize = sizeArray(st.result);

    // Binary Array
    bool binaryArray[arraySize], binaryArrayR[arraySize];

    for (i = 0; st.result > 0; i++) {
        st = moduloINT(st.result);
        binaryArrayR[i] = st.rest;
    }

    length = sizeof(binaryArrayR)-1;

    for (i = 0; i <= length; i++)
    {
	binaryArray[i] = binaryArrayR[length-i];
        printf("%d", binaryArray[i]);
    }
}
