#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct data{
   int CRN;
   char Prefix[10];
   int hour;
};

void printInvoice(int id){
   float price=0;
               printf("\t\tVELENCE COMMUNITY COLLEGE\n\t\t\tORLANDO FL 10101\n");
               printf("\t\t---------------------------\n\n");
               printf("\t\t Fee invoice prepared for student V%d\n\n",id);
               printf("\t\t 1 credit Hour =$120.25\n\n");
               printf("\t\tCRN\tCR_PREFIX\tCR_HOURS\n");

               printf("\n\t\t\t Health & id fees $ 35.00\n\n");
               printf("\t\t------------------------------\n");
               printf("\t\t\t Total payments\t$ %.2f\n\n",price+35);
}

int main(){
   struct data d[12];
   d[0].CRN=4587;
   strcpy(d[0].Prefix ,"MAT 236");
   d[0].hour = 4;
   d[1].CRN=4599;
   strcpy(d[1].Prefix,"COP 220");
   d[1].hour = 3;
   d[2].CRN=8997;
   strcpy(d[2].Prefix,"GOL 124");
   d[2].hour = 1;
   d[3].CRN=9696;
   strcpy(d[3].Prefix,"COP 100");
   d[3].hour = 5;
   d[4].CRN=4580;
   strcpy(d[4].Prefix,"MAT 230");
   d[4].hour = 3;
   d[5].CRN=4581;
   strcpy(d[5].Prefix,"MAT 231");
   d[5].hour = 4;
   d[6].CRN=4582;
   strcpy(d[6].Prefix,"MAT 232");
   d[6].hour = 2;
   d[7].CRN=4583;
   strcpy(d[7].Prefix,"MAT 233");
   d[7].hour = 2;
   d[8].CRN=3587;
   strcpy(d[8].Prefix,"MAT 256");
   d[8].hour = 4;
   d[9].CRN=4519;
   strcpy(d[9].Prefix,"COP 420");
   d[9].hour = 3;
   d[10].CRN=6997;
   strcpy(d[10].Prefix,"GOL 127");
   d[10].hour = 1;
   d[11].CRN=9494;
   strcpy(d[11].Prefix,"COP 101");
   d[11].hour = 3;

   char choice;
   int id,num,i,j,not_found;

   while(1){ not_found=0;
       printf("Enter student id\n");
       scanf("%d",&id);
       printf("Enter how many courses upto 3\n");
       scanf("%d",&num);
       if(num>3||num<=0){
           printf("Invalid number of course\n");
           printInvoice(id);
       }
       else{
           printf("Enter the %d course numbers \n",num);
           int course[num];
           for(i=0;i<num;i++){
               scanf("%d",&course[i]);
           }
           int total_hour=0;
           for(i=0;i<num;i++){
               for(j=0;j<12;j++){
                   if(d[j].CRN==course[i]){
                       total_hour+=d[j].hour;
                       break;
                   }
               }
               if(j==12){
                   not_found=1;
                   break;
               }
           }
           if(not_found){
               printf("invalid crn(s)\n\n");
           }
           else{
               if(total_hour>7){
               printf("Sorry,we cannot process more than seven hour\n\n");
           }
           else{
               float price=0;
               printf("\t\tVELENCE COMMUNITY COLLEGE\n\t\t\tORLANDO FL 10101\n");
               printf("\t\t---------------------------\n\n");
               printf("\t\t Fee invoice prepared for student V%d\n\n",id);
               printf("\t\t 1 credit Hour =$120.25\n\n");
               printf("\t\tCRN\tCR_PREFIX CR_HOURS\n");
               for(i=0;i<num;i++){
                   printf("\t\t%d\t",course[i]);
                   for(j=0;j<12;j++){
                       if(course[i]==d[j].CRN){
                           printf("%s\t\t%d\t$ %f\n",d[j].Prefix,d[j].hour,d[j].hour*120.25);
                           price+=d[j].hour*120.25;
                           break;
                       }
                   }
               }
               printf("\n\t\t\t\t Health & id fees $ 35.00\n\n");
               printf("\t\t--------------------------------------------------------\n");
               printf("\t\t\t Total payments\t\t$ %.2f\n\n",price+35);
           }
           }

       }

       printf("Would you like to print another invoice ? Y=yes N=no\n\n");
       scanf(" %c",&choice);
       if(choice=='Y')continue;
       if(choice=='N')break;
       printf("Invalid choice\n");
       break;



   }
   printf("\ngoodbye!");
   return 0;
}
