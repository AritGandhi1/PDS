/*#include <stdio.h>
#include <string.h>
struct Students{
	int id;
	char name[50];
	float mark;
	}std[2];

int main(void)
{
    int age;
    FILE *fp1;
    char name[21];
    scanf("%s %d", name, &age);
    fp1 = fopen("record.dat" , "w");    
    fprintf(fp1,"%d", age);
    int score = 0;
    //fgets(name, 21, fp1);
    //fscanf(fp1,"%s %d",name, &score);
    //printf("%s\n", name);
    
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *rollno;
    char *pass;
};

int main(void)
{
    FILE *inFile;
    struct student *students = NULL;
    int student_count = 0;
    struct student *who;
    struct score *score;
    const char *delim = " \t\n";
    char *cp;
    char buf[1000];

    inFile = fopen("Subject.txt", "a");
    if (inFile == NULL) {
        printf("Error!");
        exit(1);
    }
    char rollno[20];
    char password[1000];
    scanf("%s %s",&rollno, &password);

    //char names[] = { "Joe Math 52 85\nBilly Phy 65 70\nSophia Chem 86 71" };

    fprintf(inFile, "%s %s\n", rollno, password);
    
    fclose(inFile);

    inFile = fopen("Subject.txt", "r");
    if (inFile == NULL) 
    {
        printf("Error!");
        exit(1);
    }
    char RollNo[10];
    char PassWord[20];
    scanf("%s %s", &RollNo, &PassWord);
    while (1) {
        // get a line
        cp = fgets(buf,sizeof(buf),inFile);
        if (cp == NULL)
            break;

        // get the student name
        cp = strtok(buf,delim);
        if(strcmp(cp,RollNo) !=0)
        {
            continue;
        }
        else
        

        // allocate new student record
        // students = realloc(students, sizeof(struct student) * (student_count + 1));
        // who = &students[student_count];
        // student_count += 1;

        // save the student name
        //who->rollno = strdup(cp);
        

        // get the subject and save it
        cp = strtok(NULL,delim);
        if (cp == NULL)
            break;
        //who->pass = strdup(cp);
        if(strcmp(cp,PassWord)==0)
        printf("Yes");

        // clear out the scores array
        //who->count = 0;
        //who->scores = NULL;

        // get all scores
        //while (1) {
        //    // cp = strtok(NULL,delim);
        //     if (cp == NULL)
        //         break;

        //     // increase the size of the scores array for this student
        //     who->scores = realloc(who->scores,
        //         sizeof(struct score) * (who->count + 1));
        //     score = &who->scores[who->count];
        //     who->count += 1;

        //     score->score = atoi(cp);
        // }
    }

    fclose(inFile);

    return 0;
}