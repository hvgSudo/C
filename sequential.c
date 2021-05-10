#include <stdio.h>
#include <stdlib.h>

const int RECORD_COUNT = 5;
const char *FILENAME = "students";

const char *STUDENT_FORMAT_IN = " %[^,], %lli";   // Input is expected of the form (Name, PRN)

const char *FILE_READ_FORMAT = " Name: %[^,], PRN: %lli";
const char *FILE_WRITE_FORMAT = "Name: %s, PRN: %lli\n";
const char *FORMAT_OUT = "%s, %lli\n";

typedef struct {
    char name[20];
    long long int prn;
} Student;


// Search for entry in file
void search();

// Take and write input and output to a file
void initCode() {
    #ifndef DIRECT
    freopen("/mnt/d/codes/c/inputC.txt", "r", stdin);
    freopen("/mnt/d/codes/c/outputC.txt", "w", stdout);
    #endif
}

// PROGRAM DRIVER
int main(void) {
    initCode();

    // Open file in write mode
    FILE *out = fopen(FILENAME, "w");

    // Check whether the file was opened successfully or not
    if (out == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read records from STDIN and write to the FILE
    for (int i = 0; i < RECORD_COUNT; ++i) {

        Student st;
        printf("\nEnter record: ");
        scanf(STUDENT_FORMAT_IN, &st.name, &st.prn);
        printf(FORMAT_OUT, st.name, st.prn);

        fprintf(out, FILE_WRITE_FORMAT, st.name, st.prn);
    }

    // Close the file
    fclose(out);

    // Test search functionality
    printf("\nTesting search record functionality.\n");
    search();
    search();
    search();

    return 0;
}

// ----------------------
//  FUNCTION DEFINITIONS
// ----------------------

void search() {
    
    long long int prn;

    // Ask for PRN of record to be searched
    printf("\nEnter PRN: ");
    scanf("%lli", &prn);
    printf("%lli", prn);

    // Open file in read mode
    FILE *in = fopen(FILENAME, "r");

    // Check whether the file was opened successfully or not
    if (in == NULL) {
        exit(EXIT_FAILURE);
    }

    // Search for the record
    Student st;
    while (fscanf(in, FILE_READ_FORMAT, &st.name, &st.prn) != EOF) {

        if (prn == st.prn) {
            printf("\nMatch has been found!\n");
            printf(FILE_WRITE_FORMAT, st.name, st.prn);
            fclose(in);
            return;
        }
    }

    // Close the file
    fclose(in);
    printf("\nMatch not found!\n");
}

// END OF PROGRAM
