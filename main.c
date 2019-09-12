#include <stdio.h>
#include <string.h>

int main() {
    FILE *myfile = fopen("out.top.txt","r");
    FILE *myFileWithOnlyTheStuffINeed = fopen("temp.txt", "w+");
    char a[500];
    char b[500];
    char c[500];
    char ch[500];

    int count = 0;
    while (fgets(ch, 500, myfile)){
        count++;
        if (count > 5){
            fputs(ch, myFileWithOnlyTheStuffINeed);
        }
    }
    rewind(myFileWithOnlyTheStuffINeed);

    while (fscanf(myFileWithOnlyTheStuffINeed, "%s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s  %s",a,b,c)!= EOF) {
        if (!strncmp(b, "root", 500))
            printf("%s %s %s\n", a, b, c);
    }
}