#include <stdio.h> //use printf
#include <conio.h> //use getch
#include <stdlib.h> //use random
#include <time.h> //use time
#define MaxData 100 // Define Max Data
#define MaxRow 10 //0..9 in Decimal base
#define MaxCol 20 //0..19
int Data[MaxData];
int Radix[MaxRow][MaxCol]; //Radix is temporary tank. The size is [0..MaxRow,0..MaxCol]
int N,N1;
void ClearStackPT() //Clear every block=0 and use Radix[0] for SP
{
 int i;
 for(i=0;i<MaxRow;i++)          // แก้: i<=MaxRow -> i<MaxRow
  Radix[i][0]=0;                // แก้: NULL -> 0
}
void PrepareRawData(int N2)
{
 int i;
 srand(time(NULL));
 for (i=0;i<N2;i++)
  Data[i]=(rand() % 899)+100;
}
void DispData(int N2)
{
 int i;
 for(i=0;i<N2;i++)
  printf("%3d ",Data[i]);
 printf("\n");
}
void Push(int Rad, int Dat) //Put data into Parallel Stack by keep SP at (Rad,0)
{
 int SP;
 SP=Radix[Rad][0]+1;
 Radix[Rad][0]=SP;
 Radix[Rad][SP]=Dat;
}
void ReadStack()
{
 int i,j,k,SP;
 k=0;
 for(i=0;i<MaxRow;i++)          // แก้: i<=MaxRow -> i<MaxRow
 {
  SP=Radix[i][0];
  for(j=1;j<=SP;j++)
  {
   Data[k]=Radix[i][j];
   k++;
  }
 }
}
void RadixSort(int N2)
{
 int Digit,i,RadixNo;
 char Txt[4];                   // แก้: Txt[2] -> Txt[4]
 for(Digit=2;Digit>=0;Digit--)
 {
  printf("[Digit : %d]==>\n",3-Digit);
  for(i=0;i<N2;i++)
  {
   itoa(Data[i],Txt,10); //convert Integer to Text [itoa(input,output,base)]
   RadixNo=Txt[Digit]-48;
   Push(RadixNo,Data[i]);
  }
  ReadStack();
  DispData(N2);
  ClearStackPT();
 }
}
int main()
{
 printf("ASCENDING RADIX SORT\n");
 printf("=====================================================================\n");
 N=16;
 N1=N;
 PrepareRawData(N);
 printf("Raw Data...\n");
 DispData(N);
 printf("---------------------------------------------------------------------\n");
 printf("Processing Data...\n");
 RadixSort(N);
 printf("-------------------------------------------------------------Finished\n");
 printf("Sorted Data : \n");
 DispData(N1);
 getch();
 return(0);
}