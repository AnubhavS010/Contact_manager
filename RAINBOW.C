#include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<dos.h>
 char i;
  struct dat
 {
   int serial;
   char category[20];
   char name[30];
   char gender[20];
   int age;
   char phone[20];
   char city[50];
 }obj;
 void add_contact()
 {
    FILE *fp;
    window(1,1,80,25);
    textbackground(BLACK);
    clrscr();
    textcolor(11);
    gotoxy(30,5);
    cprintf("ADD NEW CONTACT");
    gotoxy(20,6);
    cprintf("---------------------------------------");
    gotoxy(23,8);
    cprintf("SERIAL:");
      gotoxy(23,9);
    cprintf("CATEGORY [FRIEND/RELATIVE/COLLEAGUE/FAMILY]:");
      gotoxy(23,10);
    cprintf("NAME:");
      gotoxy(23,11);
    cprintf("GENDER:");
      gotoxy(23,12);
    cprintf("AGE:");
      gotoxy(23,13);
    cprintf("PHONE:");
      gotoxy(23,14);
    cprintf("city:");
      gotoxy(20,15);
    cprintf("---------------------------------------");

    gotoxy(30,8);
     scanf("%d",&obj.serial);
     fflush(stdin);
     gotoxy(67,9);
     scanf("%s",obj.category);
     fflush(stdin);
     gotoxy(28,10);
      scanf("%s",obj.name);
      fflush(stdin);
      gotoxy(30,11);
     scanf("%s",obj.gender);
     fflush(stdin);
      gotoxy(27,12);
     scanf("%d",&obj.age);
     fflush(stdin);
      gotoxy(29,13);
     scanf("%s",obj.phone);
     fflush(stdin);
      gotoxy(31,14);
      scanf("%s",obj.city);
      fflush(stdin);
     fp=fopen("info.txt","ab");
     fwrite(&obj,sizeof(obj),1,fp);
     gotoxy(23,16);
     textcolor(WHITE+BLINK);
     cprintf("DATA STORED!,PRESS ANY KEY TO EXIT...");
     fclose(fp);

}
void show_list()
{
static int i;
FILE *fp;
 window(1,1,80,25);
 clrscr();
 textbackground(BLACK);
 textcolor(11);
 gotoxy(30,5);
 cprintf("LIST OF CONTACTS") ;
 gotoxy(1,6);
 cprintf("---------------------------------------------------------------------------------");
gotoxy(12,7);
 cprintf("SNO   CATEGORY   NAME   GENDER   AGE        CITY        PHONE ");
 gotoxy(1,8);
 cprintf("---------------------------------------------------------------------------------");
gotoxy(12,9);
textcolor(WHITE);
fp=fopen("info.txt","rb");
i=9;
while(fread(&obj,sizeof(obj),1,fp)!=NULL)
{
 gotoxy(12,i);
printf("%d   %s     %s      %s     %d        %s    %s",obj.serial,obj.category,obj.name,obj.gender,obj.age,obj.city,obj.phone);
i+=2;
}
fclose(fp);

 }
 void remove_name()
 {

     int n;
     int found=0;
     char flag,nona;
      FILE *fp1;
      FILE *fp2;
    window(1,1,80,25);
    textbackground(BLACK);
    clrscr();
    textcolor(11);
    gotoxy(31,5);
    cprintf("DELETE A CONTACT");
    gotoxy(17,6);
    cprintf("----------------------------------------------");
    gotoxy(22,7);
    cprintf("WHAT IS THE SERIAL NUMBER OF CONTACT ?");
    scanf("%d",&n);
    fp1=fopen("info.txt","rb");
    while(fread(&obj,sizeof(obj),1,fp1)!=NULL)
    {
  if(obj.serial==n)
{
      gotoxy(25,9);
    cprintf("SERIAL:");
    printf("%d",obj.serial);
      gotoxy(25,11);
    cprintf("CATEGORY [FRIEND/RELATIVE/COLLEAGUE/FAMILY]:");
      printf("%s",obj.category);
      gotoxy(25,13);
    cprintf("NAME:");
      printf("%s",obj.name);
      gotoxy(25,15);
    cprintf("GENDER:");
      printf("%s",obj.gender);
      gotoxy(25,17);
    cprintf("AGE:");
      printf("%d",obj.age);
      gotoxy(25,19);
    cprintf("PHONE:");
      printf("%s",obj.phone);
      gotoxy(25,21);
    cprintf("CITY:");
      printf("%s",obj.city);
      gotoxy(17,22);
      cprintf("---------------------------------------------");
      gotoxy(20,23);
      textcolor(RED+BLINK);
      found=1;
      }
      }
      if(found==0)
      {
      textcolor(RED+BLINK);
      gotoxy(22,12);
       cprintf("CONTACT NOT FOUND,PRESS ANY KEY TO EXIT..");
       fclose(fp1);

       }
       else if(found==1)
       {
       cprintf("DO YOU WANT TO DELETE THIS CONTACT ?(Y/N)");
       flag=getch();

      if(flag=='y'||flag=='Y')
      {
  rewind(fp1);
  fp2=fopen("temp.txt","wb");
  fp1=fopen("info.txt","rb");
  while(fread(&obj,sizeof(obj),1,fp1)!=NULL)
  {
       if(obj.serial!=n)

         fwrite(&obj,sizeof(obj),1,fp2);

  }
  fclose(fp1);
  fclose(fp2);
  remove("info.txt");
  rename("temp.txt","info.txt");
  gotoxy(25,24);
  cprintf("DELETED!");
  }
   else
   {
       gotoxy(25,24);
       cprintf("operation canceled !");
       if(kbhit())
       exit(0);
   }
   }

 getch();
 }


 void search_contact()

 {
     char naam[20];
     FILE *fp1;
     window(1,1,80,25);
     textbackground(BLACK);
     clrscr();
     textcolor(11);
     gotoxy(30,5);
     cprintf("SEARCH A CONTACT");
     gotoxy(15,6);
     cprintf("-------------------------------------------------");
     gotoxy(27,7);
     textcolor(WHITE);
     cprintf("ENTER CONTACT NAME: ");
       scanf("%s",naam);
       fp1=fopen("info.txt","rb");
       while(fread(&obj,sizeof(obj),1,fp1)!=NULL)
       {
      if(strcmpi(naam,obj.name)==0)
  {
  textcolor(11);
   gotoxy(28,9);
  cprintf("SERIAL:");
  printf("%d",obj.serial);
      gotoxy(28,11);
    cprintf("CATEGORY [FRIEND/RELATIVE/COLLEAGUE/FAMILY]:");
      printf("%s",obj.category);
      gotoxy(28,13);
    cprintf("NAME:");
      printf("%s",obj.name);
      gotoxy(28,15);
    cprintf("GENDER:");
      printf("%s",obj.gender);
      gotoxy(28,17);
    cprintf("AGE:");
      printf("%d",obj.age);
      gotoxy(28,19);
    cprintf("PHONE:");
      printf("%s",obj.phone);
      gotoxy(28,21);
    cprintf("CITY:");
      printf("%s",obj.city);
      gotoxy(17,22);
      cprintf("-----------------------------------------------");
      textcolor(RED+BLINK);
      gotoxy(29,23);
      cprintf("CONTACT FOUND!");
      gotoxy(25,24);
      cprintf("PRESS ANY KEY TO EXIT");
      }
      else if(strcmpi(naam,obj.name)==1)
      {
      gotoxy(29,23);
      textcolor(RED+BLINK);
      cprintf("NOT FOUND!") ;
      gotoxy(25,24);
      cprintf("PRESS ANY KEY TO EXIT");
      }

  }
  }
  void edit_contact()
  {
  int flag;
  int pos;
  FILE *fp1;
   window(1,1,80,25);
   clrscr();
   textbackground(BLACK);
   textcolor(11);
   gotoxy(30,2);
   cprintf("EDIT CONTACT");
   printf("\n");
   cprintf("--------------------------------------------------------------------------------");
   gotoxy(25,4);
   cprintf("ENTER SERIAL NUMBER:");
   scanf("%d",&flag);

    fp1=fopen("info.txt","r+b");
       while(fread(&obj,sizeof(obj),1,fp1)!=NULL)
       {
      if(obj.serial==flag)
  {
  textcolor(11);
  gotoxy(4,5);
  cprintf("OLD DATA\n");
       cprintf("\n\n");
   gotoxy(4,6);
  cprintf("SERIAL:");
  printf("%d",obj.serial);
      gotoxy(4,7);
    cprintf("CATEGORY:");
      printf("%s",obj.category);
      gotoxy(4,8);
    cprintf("NAME:");
      printf("%s",obj.name);
      gotoxy(4,9);
    cprintf("GENDER:");
      printf("%s",obj.gender);
      gotoxy(4,10);
    cprintf("AGE:");
      printf("%d",obj.age);
      gotoxy(4,11);
    cprintf("PHONE:");
      printf("%s",obj.phone);
      gotoxy(4,12);
    cprintf("CITY:");
      printf("%s",obj.city);
      gotoxy(4,13);
      cprintf("------------------------------------------------------------------------");
       gotoxy(63,5);
       cprintf("NEW DATA");
       break;
     }
   else
   {
       gotoxy(25,6);
       textcolor(RED+BLINK);
     cprintf("CONTACT NOT FOUND !");
     sleep(2);
     exit(0);
   }
  }
    pos=ftell(fp1);
    fseek(fp1,pos-sizeof(obj),SEEK_SET);

    gotoxy(63,6);
    cprintf("SERIAL:");
      gotoxy(63,7);
    cprintf("CATEGORY:");
      gotoxy(63,8);
    cprintf("NAME:");
      gotoxy(63,9);
    cprintf("GENDER:");
      gotoxy(63,10);
    cprintf("AGE:");
      gotoxy(63,11);
    cprintf("PHONE:");
      gotoxy(63,12);
    cprintf("city:");

      gotoxy(70,6);
     scanf("%d",&obj.serial);
      gotoxy(72,7);
     scanf("%s",obj.category);
       gotoxy(68,8);
      scanf("%s",obj.name);
      gotoxy(70,9);
     scanf("%s",obj.gender);

      gotoxy(67,10);
     scanf("%d",&obj.age);

      gotoxy(69,11);
     scanf("%s",obj.phone);

      gotoxy(68,12);
      scanf("%s",obj.city);

     fwrite(&obj,sizeof(obj),1,fp1);
     gotoxy(25,14);
     textcolor(RED+BLINK);
     cprintf("DATA IS UPDATED!");
     sound(i);
     nosound();
}
 void main()
 {
  char x[4]="8055";
   char pass[30],ch;
   int i,j;
   int choice;
   window(1,1,80,25);
   textbackground(8);
   clrscr();
   window(14,10,70,17);
   textbackground(BLACK);
   clrscr();
   gotoxy(1,2);
    textcolor(11);
   cprintf(">>>>>>>>>>>>>>>>>>>> W E L C O M E <<<<<<<<<<<<<<<<<<<<<");
   gotoxy(17,4);
   textcolor(11);
   cprintf("Enter Password:");
   i=0;
   while(1)
   {
   ch=getch();
   if(ch==13)
   {
     pass[i]='\0';
     break;
   }
     pass[i++]=ch;
     printf("*");

   }
   if(strcmp(x,pass)==0)
   {
   gotoxy(18,6);
     textcolor(WHITE);
   gotoxy(16,7);
  cprintf("just a moment");
  textcolor(WHITE);
   for(i=1;i<=20;i++)
   {
   cprintf(".");
   delay(100);
   }
   window(1,1,80,25);

   textbackground(BLACK);
   clrscr();
   }
   else
   {
   gotoxy(16,6);
   textcolor(WHITE+BLINK);
    cprintf("Incorrect Password :(");
    sleep(2);
    exit(0);
 }
 gotoxy(14,5);
 textcolor(11);
 cprintf("<<<<<<<<<<<< THE CONTACT MANAGEMENT SYSTEM >>>>>>>>>>>>>");
 gotoxy(34,8);
 textcolor(YELLOW);
 cprintf("Version 1.0");
 gotoxy(27,11);
 textcolor(11);
 cprintf("Developed by: ANUBHAV SHARMA");
 gotoxy(15,15);
  cprintf("LOADING ");
 textcolor(YELLOW);
 for(i=1;i<=50;i++)
 {
 cprintf(">");
 delay(200);
 sound(i);
 }
 nosound();
window(1,1,80,25);
 textbackground(BLACK);
 clrscr();
 gotoxy(35,5);
 textcolor(11);
 cprintf("OPERATIONS");
 gotoxy(16,6);
 textcolor(11);
 cprintf("------------------------------------------------");
 gotoxy(25,8);
 textcolor(WHITE);
 cprintf("1. ADD NEW CONTACT");
 gotoxy(25,10);
 cprintf("2. EDIT EXISTING CONTACT");
 gotoxy(25,12);
 cprintf("3. REMOVE A CONTACT");
 gotoxy(25,14);
 cprintf("4. SEARCH");
 gotoxy(25,16);
 cprintf("5.LIST OF ALL CONTACTS");
 gotoxy(25,18);
 cprintf("6. EXIT");
 gotoxy(16,20);
  textcolor(11);
 cprintf("------------------------------------------------");
 gotoxy(26,22);
 textcolor(WHITE);
 cprintf("Enter your choice:");
 scanf("%d",&choice);
 if(choice==1)
 {
 add_contact();
 }
 else if(choice==5)
 {
    show_list();
}
else if(choice==3)
{
     remove_name();
 }
 else if(choice==4)
 {
  search_contact();
  }
  else if(choice ==6)
  {
  exit(0);
  }
  else if(choice==2)
  {
     edit_contact();
     }

 getch();
 }

