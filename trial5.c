#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
typedef struct student
{
    int Roll_No;
    char name[20];
    struct subject{
        int scode;
        char sname[20];
        int mark;
        }sub[3];
    }student;

void create()
{
    student *s;
    FILE *fp;
    fp = fopen("Mystudents.csv","w");
    printf("Enter how many students you want:");
    scanf("%d", &n);
    fflush(stdin);
    s = (student*)calloc(n,sizeof(student));
    for(i = 0; i<n; i++)
    {
        scanf("Enter Roll No. %d", &s[i]);
        scanf("Enter Name : %[^\n]s", s[i].name);
        for(j+0; j<3; j++)
        {
            //printf("Enter marks of subject %d " (j+1));
            scanf("%d", &s[i].sub[j].mark);

        }
        fwrite(&s[i],sizeof(student),1,fp);
    }
}
void main()
{
    FILE *fp;
    fp = fopen("Mystudents.csv","r");
    
}

