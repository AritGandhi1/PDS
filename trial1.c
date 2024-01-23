#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct Students{
	int id;
	char name[50];
	float mark;
	}std[2];

int main() 
{ 
    
    //char str[80]; 
    FILE* ptr; 
    /*ptr = fopen("Hello.txt", "a"); 
  
      // fseek function used 
    //fseek(ptr, 11, SEEK_SET); 
    
      // puts programming in place of at position defined  
      // After 11 elements 
    //fputs("Programming  ", ptr);
    for(int i=0;i<2;i++){
    printf("\nEnter ID :");
    //fprintf(fp1,"Hi");
    scanf("%d",&std[i].id);
    
    printf("\nEnter name :");
    scanf("%s",&std[i].name);
    printf("\nEnter mark :");
    scanf("%f",&std[i].mark);
    //fwrite(&std[i],sizeof(std[i]),1,ptr);
    fprintf(ptr,"%d %s %f\n", std[i].id,std[i].name, std[i].mark);
} 
    fclose(ptr); */
  
      // Reading the file 
    ptr = fopen("Hello.txt", "r"); 
    int n;
    printf("Input the id you want");
    scanf("%d", &n);
    printf("%d", n);
    char ch;
    int s;
    for(int i = 0; i<=100; i++)
    {
        if(fscanf("%d", s) == n)
        {
            fseek(ptr, i, SEEK_SET);
            break;
        }
        fseek(ptr, i, SEEK_SET);
        
        // if (*fgets(str, 1, ptr) == n) { 
        // puts(str); 
        // break;
    } 
    char str[80];
    if (fgets(str, 80, ptr) != NULL) { 
        puts(str); 
    } 
  
      // Close the opened file 
    fclose(ptr); 
    
    return 0; 
}