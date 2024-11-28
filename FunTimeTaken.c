#include <stdio.h>
#include <time.h>


void TimeTaken() {
   
    for (volatile long i = 0; i < 100000000; i++); // Busy-wait loop
}

int main() {
    // Start time for the entire program
    clock_t programStartTime = clock();

    // Start time for the function
    clock_t functionStartTime = clock();
    
    // Call the function
    TimeTaken();
    
    // End time for the function
    clock_t functionEndTime = clock();

    // End time for the entire program
    clock_t programEndTime = clock();

    // Calculate elapsed time for the function
    double functionElapsedTime = (double)(functionEndTime - functionStartTime) / CLOCKS_PER_SEC;

    // Calculate total elapsed time for the program
    double programElapsedTime = (double)(programEndTime - programStartTime) / CLOCKS_PER_SEC;

    // Print the source code
    printf("Source Code:\n");
    printf("#include <stdio.h>\n");
    printf("#include <time.h>\n\n");
    printf("void process() {\n");
    printf("    for (volatile long i = 0; i < 100000000; i++);\n");
    printf("}\n\n");
    printf("int main() {\n");
    printf("    clock_t programStartTime = clock();\n");
    printf("    clock_t functionStartTime = clock();\n");
    printf("    process();\n");
    printf("    clock_t functionEndTime = clock();\n");
    printf("    clock_t programEndTime = clock();\n");
    printf("}\n");

    
    printf("\nElapsed time for the function: %.6f seconds\n", functionElapsedTime);
    printf("Total elapsed time for the program: %.6f seconds\n", programElapsedTime);

    return 0;
} 