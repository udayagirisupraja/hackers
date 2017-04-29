#include <stdio.h>
#include <string.h>
#include <stdlib.h>            // only for exit(0) function //

int select(char);
long int r_fact(int);
long int r_power(int, int);
long int r_sum(int);
long int r_mul(int, int);
void l_pyrm(int);
int  l_linearsearch(int a[16], int, int);
void l_name(char*, int);
void l_printno(int, int);
void c_age(int);
int  c_isprime(int n);
void c_iseven(int);
void c_max(int a[]);
void f_name(char *, char *);
int  f_cpy(char *, char *);
int  f_merge(char *, char *, char *);
int  f_countwords(char *);

int main(int argc, char *argv[2]) {
    if (argc != 2) {
        printf("\nplease enter 2 arguments [./a.out and category]\n\n");
        return 0;
    }

    char str[10];
    strcpy(str, argv[1]);
    while (1) {
        if (strcmp(str, "recursion") == 0)
            select ('r');
        if (strcmp(str, "loops") == 0)
            select ('l');
        if (strcmp(str, "condition") == 0)
            select ('c');
        if (strcmp(str, "files") == 0)
            select ('f');
        if (strcmp(str, "exit") == 0)  
            exit(0);                                       // exits or come out from the entire progrram //
        else
            printf("\nNOTE : categories are \n condition\n loops\n recursion\n files\n exit\n");
        printf("\nEnter the category you want to select\n");
        scanf("%s", str);
    }

    return 0;
}

int select(char ch) {
    int n;
    int x;
    int y;
    char ch1;
    long int z;
    int a[23];
    char st[34];
    char st1[15];
    char st2[15];
    switch (ch) {
        case 'r': printf("\nSelect among\n1.Factorial \n2.Power \n3.Addition of n natural numbers \n4.Multiplication\n");
                  scanf("%d", &n);
                  switch (n) {
                      case 1:
                          printf("\nEnter number to find factorial\n");
                          scanf("%d", &x);
                          z = r_fact(x);
                          printf("Factorial of %d is %ld\n", x, z);
                          break;
                      case 2:      
                          printf("\nEnter  x and y to calaulate x power y\n");
                          scanf("%d%d", &x, &y);
                          z = r_power(x,y);
                          printf("%d to the power %d is %ld\n", x, y, z);
                          break;
                      case 3:
                          printf("\nEnter x for adding x natural numbers\n");                  
                          scanf("%d", &x);
                          z = r_sum(x);
                          printf("Addition of %d natural numbers is %ld\n", x, z);
                          break;                                                                                       
                      case 4:
                          printf("\nEnter x and y for the product\n");
                          scanf("%d%d", &x, &y);
                          z = r_mul(x, y);
                          printf("Product of %d and %d is %ld\n", x, y, z);
                          break;
                  }
                  break;
                  
        case 'l': printf("\nSelect among\n1.Pyramid \n2.Linearsearch \n3.Prints name for selected no.of times \n4.Printing numbers for a given range\n");
                  scanf("%d", &n);
                  switch(n) {
                      case 1:
                          printf("\nEnter the limit for the pyramid\n");
                          scanf("%d", &x);
                          l_pyrm(x);
                          break;
                      case 2:
                          printf("\nEnter no.of  elements in the array\n");
                          scanf("%d", &n);
                          if (n == 0) {
                              printf("In valid number of elements\n\n");
                              break;
                          }
                          printf("Enter %d elements\n", n);
                          for (x = 0; x < n; x++)
                              scanf("%d", &a[x]);
                          printf("Enter the element to be searched\n");
                          scanf("%d", &y);
                          l_linearsearch(a, n, y);
                          break;                
                      case 3:
                          printf("\nEnter the name\n");
                          scanf("%s", st);                  // note: no space should be given while giving strings //
                          printf("Enter the no.of times that the  %s to be printed\n", st);
                          scanf("%d", &n);
                          l_name(&st[0], n);
                          break;
                      case 4:
                          printf("\nEnter the starting value\n");
                          scanf("%d", &x);
                          printf("Enter the ending value\n");
                          scanf("%d", &y);
                          l_printno(x, y);
                          break;
                  }
                 break;
        case 'c': printf("Select among\n1.Checking eligibility for voting \n2.Checking the given number for prime\n3.Checking whether the number is even or not \n4.Find maximum of three numbers\n");
                  scanf("%d", &n);
                  switch(n) {
                      case 1:
                          printf("\nEnter the age of a person\n");
                          scanf("%d", &x);
                          c_age(x);
                          break;
                      case 2:
                          printf("\nEnter the number to check for prime\n");
                          scanf("%d", &x);
                          c_isprime(x);
                          break;
                      case 3:
                          printf("\nEnter a number for checking it\n");
                          scanf("%d", &x);
                          c_iseven(x);
                          break;
                      case 4:
                          printf("\nEnter 3 numbers to find maximum number\n");
                          for (x = 0; x < 3; x++)
                              scanf("%d", &a[x]);
                          c_max(a);         
                          break;
                  }
                  break;
        case 'f': printf("Select among\n1.Displaying the name \n2.Copying one file to the other \n3.Merging of two files \n4.Count the no.of words\n");
                  scanf("%d", &n);
                  switch(n) {
                      case 1:
                          printf("\nEnter the file name\n");
                          scanf("%s", st1);
                          printf("Enter the name to be printed\n");
                          scanf("%s", st);
                          f_name(&st[0], &st1[0]);                                          
                          break;
                      case 2:
                          printf("\nEnter the file name to read\n");
                          scanf("%s", st1);
                          printf("Enter the file name to be copied\n");
                          scanf("%s", st);
                          f_cpy(&st1[0], &st[0]);
                          break;
                      case 3:
                          printf("\nEnter the first file name\n");
                          scanf("%s", st1);
                          printf("\nEnter the second file name\n");
                          scanf("%s", st);
                          printf("Enter the file name to be merged\n");
                          scanf("%s", st2);
                          f_merge(&st1[0], &st[0], &st2[0]);
                          break;
                      case 4:
                              printf("\nEnter the file name\n");
                              scanf("%s", st1);
                              x = f_countwords(&st1[0]);
                              printf("Number of words in %s file is %d\n", st1, x);
                              break;
                  }
                  break;
    }
    printf("\nSelect among the following\n1. Continue in same topic\n2. Select another topic\n3. TO EXIT\n");
    scanf("%d", &n);
    if (n == 1)
        select(ch);
    if (n == 2)
        return 0;
    if (n == 3)
        exit(0);
}

long int r_fact(int n) {
    if (n == 1)
        return 1;
    else
        return (n * r_fact(n - 1));
}

long int r_mul(int m, int  n) {
    if (n == 1)
        return m;
    else
        return (m + r_mul(m, n - 1));
}
            
long int r_sum(int n) {
    if (n == 1) 
        return 1;
    else
        return (n + r_sum(n - 1));
}

long int r_power(int x, int y) {
    if (y == 0)
        return 1;
    else 
        return (x * r_power(x , y - 1));
}

void l_pyrm(int x) {
    int i;
    int j;
    int k; 
    // pyramid limit is 70 lines //
    for (i = 0; i < x; i++) {
        for (k = x; k > i; k--) 
            printf(" ");
        for (j = 0; j <= i; j++) 
            printf(" *");

        printf("\n");
    }
}

int l_linearsearch(int a[2], int x, int etbs) {
    int i;
    int j;
    if (x == 0) {
        printf(" Please enter valid number\n");                      // if no.of elements is ZERO //
        return 0;
    }
    for (i = 0; i < x; i++) {
        if (etbs == a[i]) {
            printf("\n Element found at %d location\n", i + 1);
            return 0;
        }
    }
    printf("Element %d not found\n", etbs);
    return 0;
}

void l_name(char *name, int n) {
    int i;
    for (i = 0; i < n; i++) 
        printf("%s ", name);

    printf("\n");
}

void l_printno(int m, int n) {
    int i;
    printf("Numbers in between %d and %d are :\n", m, n);
    for (i = m; i <= n; i++) 
        printf("%d ", i);

    printf("\n");
} 

void c_age(int age) {
    if (age >= 18)
        printf("Person is eligible for voting\n");
    else
        printf("Person is not eligible for voting\n");
}

int c_isprime(int n) {
    int count_fac = 0;
    int i;
    if (n == 0 || n == 1) {
        printf("1 and o are exceptional cases and not prime numbers\n");
        return 0;
    }
    for (i = 2; i < n; i++) 
        if (n % i == 0) {
            printf("%d is not prime number\n", n);
            return 0;
        }
    printf("%d is prime number\n", n);
    return 0;
}

void c_iseven(int num) {
    if (num % 2 == 0)
        printf("it is an even number\n");
    else
        printf("it is an odd number\n");
}

void c_max(int a[3]) {
    if (a[0] == a[1] && a[1] == a[2]) 
        printf("entered numbers are equal\n");
    if (a[0] > a[1] && a[0] > a[2])
        printf("%d is larger among given numbers\n", a[0]);
    if (a[1] > a[2])
        printf("%d is larger among given numbers\n", a[1]);
    else
        printf("%d is larger among given numbers\n", a[2]);
}
void f_name(char *name, char *f_name) {
    FILE *fp;
    fp = fopen(f_name, "a");
    fputs(name, fp);
    printf("%s name is successfully copied to %s file\n", name, f_name);
    fclose(fp);
}

int f_cpy(char *file1, char *file2) {
    FILE *fp1;
    FILE *fp2;
    char ch;
    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("%s file do not exists\n", file1);
        return 0;
    } 
    fp2 = fopen(file2, "a");
    while ((ch = fgetc(fp1)) != EOF)
        fputc(ch, fp2);
    printf("%s is successfuly copied to %s\n", file1, file2);
    fclose(fp1);
    fclose(fp2);
}

int f_merge(char *file1, char *file2, char *file3) {
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if (fp1 == NULL || fp2 == NULL) {
        printf("Please enter exisisting files\n");                // files which are in your current postion //
        return 0;
    }
    char ch;
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");
    fp3 = fopen(file3, "a");
    while ((ch = fgetc(fp1)) != EOF) {
        putchar(ch);
        fputc(ch, fp3);
    }
    while ((ch = fgetc(fp2)) != EOF) {
        putchar(ch);
        fputc(ch, fp3);
    }
    printf("%s and %s are successfully merged to %s\n", file1, file2, file3);                                           
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int f_countwords(char *file) {
    FILE *fp;

    int count = 0;
    char ch;
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("%s file do not exists\n", file);
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
        if (ch == ' ' || ch == '\n')                 // if words in your files are separated by single space [' '] //
            count++;
    
    fclose(fp);
    return count;
}
