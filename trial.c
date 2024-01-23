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

struct score {
    int score;
};

struct student {
    char *rollno;
    char *name;
    char *subject;
    struct score *scores;
    int count;
};

int
main(void)
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
    char name1[1000];
    char subject[100];
    char marks[10];
    scanf("%s %s %s %s",&rollno, &name1, &subject, &marks);

    //char names[] = { "Joe Math 52 85\nBilly Phy 65 70\nSophia Chem 86 71" };

    fprintf(inFile, "%s %s %s %s\n", rollno, name1, subject, marks);
    
    fclose(inFile);

    inFile = fopen("Subject.txt", "r");
    if (inFile == NULL) {
        printf("Error!");
        exit(1);
    }

    while (1) {
        // get a line
        cp = fgets(buf,sizeof(buf),inFile);
        if (cp == NULL)
            break;

        // get the student name
        cp = strtok(buf,delim);
        if(strcmp(cp,"23CS01001") !=0)
        {
            continue;
        }
        else
        

        // allocate new student record
        students = realloc(students, sizeof(struct student) * (student_count + 1));
        who = &students[student_count];
        student_count += 1;

        // save the student name
        who->x = strdup(cp);
        

        // get the subject and save it
        cp = strtok(NULL,delim);
        if (cp == NULL)
            break;
        who->subject = strdup(cp);

        // clear out the scores array
        who->count = 0;
        who->scores = NULL;

        // get all scores
        while (1) {
            cp = strtok(NULL,delim);
            if (cp == NULL)
                break;

            // increase the size of the scores array for this student
            who->scores = realloc(who->scores,
                sizeof(struct score) * (who->count + 1));
            score = &who->scores[who->count];
            who->count += 1;

            score->score = atoi(cp);
        }
    }

    fclose(inFile);

    for (who = &students[0];  who < &students[student_count];  ++who) {
        printf("%10s %10s", who->name, who->subject);

        for (score = who->scores;  score < &who->scores[who->count];  ++score)
            printf("%4d",score->score);

        printf("\n");
    }

    return 0;
}