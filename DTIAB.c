//
// DTIAB is a tool that converts any integer to its binary representation.
//

#include <stdio.h>
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

int main() {
    int i, length = 0;
    Struct st;

    // Eingabe Wert
    st.result = 333;

    int arraySize = sizeArray(st.result);

    // Binary Array
    bool binaryArray[arraySize];

    for (i = 0; st.result > 0; i++) {
        st = moduloINT(st.result);
        binaryArray[i] = st.rest;
    }

    length = sizeof(binaryArray);

    for (i = 0; i <= length-1; i++)
    {
        printf("%d", binaryArray[i]);
    }
}
