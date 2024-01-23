#include <stdio.h>
#include <string.h>


struct person {
    int id;
    char fname[20];
    char lname[20];
};
 
int main()
{
    FILE *outfile;
 
    // open file for writing
    outfile = fopen("person.bin", "w");
    
 
    struct person input1 = { 1, "rohan", "sharma" };
 
    // write struct to file
    int flag = 0;
    flag = fwrite(&input1, sizeof(struct person), 1,
                  outfile);
    if (flag) {
        printf("Contents of the structure written "
               "successfully");
    }
    else
        printf("Error Writing to File!");
 
    // close file
    fclose(outfile);
 
    return 0;
}