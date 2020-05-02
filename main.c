#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void railFence2level(char *msg, char *cipherText, int length, int railsA, int railsB, int dir, FILE *out);
void railFence(char *msg, char *cipherText, int length, int rails, FILE *out);

int main(){


    FILE *input, *out;

    input = fopen("fileinput.txt", "r");

    if(input == NULL) {
        perror("fopen()");
        return 1;
    }

   out = fopen("fileoutput.txt", "w");
   if(out == NULL){
        perror("fopen()");
        return 1;
   }

    int i = 0;
    char c;
    char msg[1000];

    fscanf(input, "%c", &c);
    while(!feof(input) && i < 999) {
        msg[i] = c;
        i++;
        fscanf(input, "%c", &c);
    }
    msg[i] = 0; // NULL terminator

    fprintf(out, "Input File Message: %s\n\n", msg);
    printf("Input File Message: %s\n", msg);




int levelsinput;
int railsA;
int railsB;
int dir;
int length;

char cipherText[1000];



printf("\nEnter '0' for single level cipher or '1' for 2-level cipher:   ");
scanf("%d", &levelsinput);


printf("\nEnter Rails A: ");
scanf("%d", &railsA);
length = strlen(msg);

if(levelsinput == 1){
printf("\nEnter Rails B: ");
scanf("%d", &railsB);
}

printf("\nEnter Direction ('0' for Encrypt & '1' for Decrypt):  ");
scanf("%d", &dir);

if(levelsinput == 1){
railFence2level(msg, cipherText, length, railsA, railsB, dir, out);
}
if(levelsinput == 0){
        railFence(msg, cipherText, length, railsA, out);
// input the funciton here. ensure all variables are consistent across all funcitons.
}
}


void railFence(char *msg, char *cipherText, int length, int railsA, FILE *out)
{

    int i, j, count;
    int matrixarray[100][1000];
    printf("\nMessage length: %d\n\nOutput Message: \n\n", length);
        fprintf(out, "Message Length: %d\n\nOutput Message: \n\n", length);


for(i=0; i<railsA; i++)
{
    for(j=0; j<length;j++)
    {
        matrixarray[i][j]=0;
    }
}
count = 0;
j = 0;
while(j<length)
{
    if(count%2==0)
    {
        for(i=0; i<railsA;i++)
        {
            matrixarray[i][j] = (int)msg[j];
            j++;
        }
    }
    else
    {
        for(i=railsA-2; i>0; i--)
        {
            matrixarray[i][j] = (int)msg[j];
            j++;
        }
    }
count ++;
}
for(i=0; i<railsA;i++)
{
    for(j=0;j<length;j++)
    {
        if(matrixarray[i][j] != 0) {
            *cipherText = matrixarray[i][j];
            printf("%c", *cipherText);
            fprintf(out, "%c", *cipherText); }
    }
}
printf("\n");

}



void railFence2level(char *msg, char *cipherText, int length, int railsA, int railsB, int dir, FILE *out)
{

    int i, j, k,  count, m=0;
    int matrixarray[100][1000];
    printf("\nMessage length: %d\n\nOutput Message: \n\n", length);
    fprintf(out, "Message Length: %d\n\nOutput Message: \n\n", length);

if(dir == 0 ){

for(i=0; i<railsA; i++)
{
    for(j=0; j<length;j++)
    {
        matrixarray[i][j]=0;
    }
}
count = 0;
j = 0;

while(j<length)
{

    for(i=0; i<railsA;i++)
        {
            matrixarray[i][j] = (int)msg[j];
            j++;
        }

    for(i=railsA-2; i>((railsA-railsB)-1); i--)
        {

            matrixarray[i][j] = (int)msg[j];
            j++;

        }

    for(i=(railsA-railsB)+1 ; i<railsA; i++)
    {
        matrixarray[i][j] = (int)msg[j];
        j++;
    }

    for(i=railsA-2; i>0; i--)
    {
        matrixarray[i][j] = (int)msg[j];
        j++;
    }


}


for(i=0; i<railsA;i++)
{

        for(j=0;j<length;j++)
    {
        if(matrixarray[i][j] != 0) {
            *cipherText = matrixarray[i][j];
            printf("%c", *cipherText);
            fprintf(out, "%c", *cipherText); }
    }
}
printf("\n");

}

if(dir == 1){

    for(i=0; i<railsA; i++)
{
    for(j=0; j<length;j++)
    {
        matrixarray[i][j]=0;
    }
 }
count = 0;
j = 0;

while(j<length)
{
    for(i=0; i<railsA;i++)
        {
            matrixarray[i][j] = 'x';
            j++;
        }

    for(i=railsA-2; i>((railsA-railsB)-1); i--)
        {

            matrixarray[i][j] = 'x';
            j++;

        }

    for(i=(railsA-railsB)+1 ; i<railsA; i++)
    {
        matrixarray[i][j] = 'x';
        j++;
    }

    for(i=railsA-2; i>0; i--)
    {
        matrixarray[i][j] = 'x';
        j++;
    }


}


for(i=0; i<railsA; ++i)
{
    for(j=0; j<length; ++j)
    {
        if(matrixarray[i][j] == 'x'){
            matrixarray[i][j] = (int)msg[m];
            m++;
        }
    }
}

j=0;
while(j<length)
{

    for(i=0; i<railsA;i++)
        {
            if(matrixarray[i][j] != 'x'){
            printf("%c", matrixarray[i][j]);
            fprintf(out, "%c", matrixarray[i][j]);
            j++;
            }
        }

    for(i=railsA-2; i>((railsA-railsB)-1); i--)
        {
           if(matrixarray[i][j] != 'x'){
            printf("%c", matrixarray[i][j]);
            fprintf(out, "%c", matrixarray[i][j]);
            j++;
            }

        }

    for(i=(railsA-railsB)+1 ; i<railsA; i++)
    {
        if(matrixarray[i][j] != 'x'){
            printf("%c", matrixarray[i][j]);
            fprintf(out, "%c", matrixarray[i][j]);
            j++;
            }
    }

    for(i=railsA-2; i>0; i--)
    {
    if(matrixarray[i][j] != 'x'){
            printf("%c", matrixarray[i][j]);
            fprintf(out, "%c", matrixarray[i][j]);
            j++;
            }
    }



}
}
printf("\n");

}
