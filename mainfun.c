#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>



#define MAXRANDOMVALUE 3
#define MAXPREV 500


void loading();
void registration();
void login();
void start_page();
void main_menu();

void draw_rectangle();
void rps();

void ttt();
int checkwin();
void board();


int findlen(int n);
int morevalue(int k);
void addrandomno();
void rupdate();
void createprev(int ***p);
void updatearrtoprev(int ***p);
void resetgame();
int two048();

void shuffle();
int scramble();
int scramblem(char word[]);

int quiz();

void hs();

int higherlower();



//===========================================Home Page===================================================
void start_page()
{
    loading();
    system("cls");
    fflush(stdin);
    char choice_ne;
    printf("----------------WeLcOmE To ThE WoRlD Of gAmEs-------------------\n");
    printf("For new player (Press N)\n");
    printf("For existing user (Press E)\n");
    printf("To Quit(Press Q)\n");
    printf("Enter your choice:");
    scanf("%c",&choice_ne);
    if(choice_ne=='N'){
        registration();
    }
    else if(choice_ne=='E'){
        login();
    }
    else if(choice_ne=='Q'){
        exit(1);

    }
    else{
        printf("Invalid Input!!!\nTry again!!!\n");
        
        start_page();
    }
}




//================================================loading animation====================================================

void loading(){
    system("cls");
    int s=-33;
    printf("Loading....\n");
    for(int i=0,j;i<35;i++)
    {
        printf("%c",s);
        j=i;
        if(i%2!=0 && i<20){
            Sleep(750);

        }


    }
    printf("\n ");
}




//=============================================registration page====================================================
struct gamer
{
    char name[50];
    char pass[50];
};

void registration()
{
    system("cls");
    fflush(stdin);
    struct gamer g1;
    FILE *file_pointer1 =fopen("username_password","a");
    if(file_pointer1==NULL){
        printf("File not found");
        registration();
    }
    printf("------------Registration Page---------------\n");
    char new_name[100],password[50];
    printf("Enter Username:");
    scanf(" %[^\n]",&g1.name);
    printf("\nEnter Password:");
    scanf(" %[^\n]",&g1.pass);
    fwrite(&g1,sizeof(struct gamer),1,file_pointer1);
    fclose(file_pointer1);
    login();
    
}





//====================================================login page=====================================================
void login()
{
    system("cls");
    fflush(stdin);
    FILE *file_pointer2=fopen("username_password","r");
    FILE *check=fopen("username_password","r");
    char *internal_file;
    printf("------------Login Page---------------\n");
    char username[50],password[50];
    printf("Enter Username:");
    scanf("%[^\n]",&username);
    printf("\nEnter Password:");
    scanf(" %[^\n]",&password);
    struct gamer g2;
    struct gamer *p=&g2;
    
    while(fread(&g2 ,sizeof(struct gamer),1,file_pointer2)==1){
        if(strcmp(username,g2.name)==0 && strcmp(password,g2.pass)==0){
            fclose(file_pointer2);
            main_menu();
            return;
        }
    }
    printf("wrong username or password");
    char c;
    printf("do you have an existing account(Y/N)?");
    scanf("%c",&c);
    if(c=='Y'){
        login();
    }
    else{
        registration();
    }
}




//====================================================main menu===================================================
void main_menu()
{
    system("cls");
    fflush(stdin);
    printf("- - - - - - - - - - - - Main Menu- - - - - - - - - - - - - -\n");
    printf("1-> ROCK PAPER SCISSORS\n2-> TIC TAC TOE\n3-> 2048\n4-> CYBER QUIZ\n5-> HIGHER LOWER\n6-> SCRAMBLE\n");
    int choice;
    printf("Choose your game : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            loading();
            rps();
            break;
        case 2:
            loading();
            ttt();
            break;
        case 3:
            loading();
            two048();
            break;
        case 4:
            loading();
            quiz();
            break;
        case 5:
            higherlower();
            loading();
            break;
        case 6:
            loading();
            scramble();
            break;
        default:
            printf("No such option found\nTry Again");
            main_menu();
            break;
    }
}




//============================================= rock paper scissors================================================


// Function to draw a rectangle using ASCII characters
void draw_rectangle(int width, int height, char *text) {

  // Draw the top border of the rectangle

  for (int i = 0; i < width; i++) {
    printf("*");
  }
  printf("\n");

  // Draw the middle of the rectangle

  for (int i = 0; i < height - 2; i++) {
    printf("*");
    for (int j = 0; j < width - 2; j++) {
      // If we're in the middle of the rectangle, print the text

      if (i == (height - 2) / 2 && j >= (width - strlen(text)) / 2 && j < ((width - strlen(text)) / 2 + strlen(text))) {
        printf("%c", text[j - (width - strlen(text)) / 2]);
      } else {
        printf(" ");
      }
    }
    printf("*\n");
  }

  // Draw the bottom border of the rectangle

  for (int i = 0; i < width; i++) {
    printf("*");
  }
  printf("\n");
}

void rps(){
    system("cls");
    fflush(stdin);
    srand(time(NULL));
    char x;

    //Recieving and displaying initial input from user

    printf("Enter Your Choice[R/P/S]: ");
    scanf(" %c",&x);
    if(x == 'R'){
        printf("*** You chose ROCK ***\n");
    }
    else if (x == 'P'){
        printf("*** You chose PAPER ***\n");
    }
    else if(x == 'S'){
        printf("*** You chose SCISSORS ***\n");
    }
    else {
        printf("INVALID INPUT\n[Input is Case-Sensitive] \n");
    }
  
    // Generate a random number between 0 and 2

    int Rand_No = rand() % 3;
    char Rand_Ch;

     // Map the random number to a character in the set {'R', 'S', 'P'}
    switch (Rand_No) {
    case 0:
      Rand_Ch = 'R';
      break;
    case 1:
      Rand_Ch = 'S';
      break;
    case 2:
      Rand_Ch = 'P';
      break;
    }

    //Comparing and displaying the outcomes
    if(x == 'R'){
        if(Rand_Ch == 'S'){
        printf("*** The Opponent chose SCISSORS ***\n");
        draw_rectangle(30,10,"YOU WON (^__^)");
        }
        else if (Rand_Ch == 'P'){
        printf("*** The Opponent chose PAPER ***\n");
        draw_rectangle(30,10,"YOU LOST (T__T)");
        }
        else if(Rand_Ch == 'R'){
        printf("*** The Opponent chose ROCK ***\n");
        draw_rectangle(30,10,"IT'S A DRAW (-_-)");
        }
     }
     else if(x == 'S'){
        if(Rand_Ch == 'S'){
        printf("*** The Opponent chose SCISSORS ***\n");
        draw_rectangle(30,10,"IT'S A DRAW (-_-)");
         }
        else if (Rand_Ch == 'P'){
        printf("*** The Opponent chose PAPER ***\n");
        draw_rectangle(30,10,"YOU WON (^__^)");
        }
        else if(Rand_Ch == 'R'){
        printf("*** The Opponent chose ROCK ***\n");
        draw_rectangle(30,10,"YOU LOST (T__T)");
        }
     }
     else if(x == 'P'){
          if(Rand_Ch == 'S'){
            printf("*** The Opponent chose SCISSORS ***\n");
            draw_rectangle(30,10,"YOU LOST (T__T)");
          }
          else if (Rand_Ch == 'P'){
            printf("*** The Opponent chose PAPER ***\n");
            draw_rectangle(30,10,"IT'S A DRAW (-_-)");
          }
          else if(Rand_Ch == 'R'){
            printf("*** The Opponent chose ROCK ***\n");
            draw_rectangle(30,10,"YOU WON (^__^)");
          }
     }
    

    char choice;
    printf("Do you wanna go again(Y/ANY OTHER KEY):");
    scanf(" %c",&choice);
    if(choice=='Y'){
        rps();
    }
    else
        main_menu();
}




//====================================== tic tac toe ================================================================


char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

/*********************************************
/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT

**********************************************/
/* second function starts */

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}



void ttt()
{
    system("cls");
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        /* input values means X and 0*/

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        // checking the values
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();
    printf("Do you wanna play again(Y/any other key):");
    scanf("%c",&choice);
    if (choice=='Y'){
      ttt();
    }
    else
      main_menu();

}




//=================================================2048===========================================================

int arr[4][4]={0},c[4],temp=0,len=0,score=0,highscore=0,count=0,ch=0;//COUNT WILL COUNT THE NO OF STEPS


void print()
{
        int i,j,k,len1;

        printf("\n\t\t\t\t\t===============2048==============\n");
          printf("\t\t\t\t\tYOUR SCORE=%d\n\t\t\t\t\t",score);
          if(score<highscore)
          {
              printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore);
          }
          else
          {
              highscore=score;
              printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore);
          }
    printf("\t\t\t\t\t---------------------------------\n");
    for (i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(j==0)
            {
                printf("\t\t\t\t\t|");
            }
            if(arr[i][j]!=0)
            {
                len1=findlen(arr[i][j]);
                //printf("%d:",len);

                for(k=0;k<4-len;k++)
                {
                    printf(" ");
                }
                printf("%d",arr[i][j]);

                for(k=0;k<4-len;k++)
                {
                    printf(" ");
                }
                for(k=0;k<len-1;k++)
                {
                    printf(" ");
                }
                printf("|");
            }
            else
            {
                for(k=0;k<8-2*len-1;k++){
                printf(" ");}printf("|");
            }
            len=0;
        }
        if(i!=3)
        {
        printf("\n");
    printf("\t\t\t\t\t---------------------------------\n");
        }

    }
    printf("\n\t\t\t\t\t---------------------------------\n");
     printf("\t\t\t\t\tPREV-> P\t\t\t\t\t\n");
     printf("\t\t\t\t\tRESTART-> R\t\t\t\t\t\n");
     printf("\t\t\t\t\tEXIT-> U\t\t\t\t\t\n");
    printf("\t\t\t\t\tENTER YOUR CHOISE -> W,S,A,D\n\t\t\t\t\t");

}
void movevalue(int k)
{
    int i;
    if(k==3 )
    {
        return;
    }
    for(i=k;i<4;i++)
    {
        if(c[i]!=0)
        {
            movevalue(i+1);
            for(;i<4;i++)
            {
                if(c[i+1]!=0)
                {
                    break;
                }
                    c[i+1]=c[i];
                    c[i]=0;
            }


        }
    }
}
int findlen(int n)
{

        if(n==0)
        {

            return len;
        }
        else
        {
            len++;
            findlen(n/10);
        }
}
void addrandomno()
{
    int no;
     srand(time(NULL));
    int i,j; //RANDOM INDEX
    do
    {
    i=(rand ())%(MAXRANDOMVALUE+1);
    j=(rand ())%(MAXRANDOMVALUE+1);
    }
    while(arr[i][j]!=0);
   //printf("%d %d",i,j);
    no=2*((rand ()%10)+1);
    if(no==3 || no==2)
    {
        arr[i][j]=4;
    }
    else
    {
        arr[i][j]=2;
    }
}
void rupdate()
{
    int i,j;
    for(i=3;i>0;i--)
    {
        if(c[i]==c[i-1] )
        {
            c[i]+=c[i-1];
            score=score+c[i];
            if(score>highscore)
            {

            }
            temp=1;
            c[i-1]=0;
        }
        else if(c[i-1]==0 && c[i]!=0 )
        {
            c[i-1]=c[i];
            c[i]=0;
            temp=1;
        }
        else if(c[i]==0)
        {
            temp=1;
        }
    }
        movevalue(0);

}
void createprev(int ***p)
{
      int i,j,k;
      FILE *ptr;
      ptr=fopen("hstr.txt","a");
      fprintf(ptr,"%d ",score);
      fclose(ptr);

    if(count==MAXPREV+1)
    {
        for(i=MAXPREV;i>0;i--)
        {
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                        p[i][j][k]=p[i-1][j][k];
                }
            }

        }
        count=MAXPREV;
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            p[MAXPREV-count][i][j]=arr[i][j];
        }

    }
}
void updatearrtoprev(int ***p)
{
    int data,i,j;
    if(count==0)
    {
        printf("\n\t\t\t\t\t****FURTHER MORE PREV NOT POSSIBLE******");
        return;
    }
    FILE *ptr=fopen("hstr.txt","r+");
        for(i=0;i<count;i++)
        {
            fscanf(ptr,"%d ",&data);
        }
        score=data;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            arr[i][j]=p[MAXPREV-count][i][j];
        }
    }
    count--;
}
void resetgame()
{
            int i,j;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    arr[i][j]=0;

                }
            }
            system("cls") ;
            score=0;
            addrandomno();

}
int two048()
{
    system("cls");
    int i,j,k,m,n,same=0;
    char choise,s=-33,reschk;
   printf("\n\t\t\t\t\t===============2048==============\n");
   printf("\n\t\t\t\t\tWELCOME TO PUZZLE 2048");
    printf("\n\t\t\t\t\t> DEVELOPED BY :- GAMEHUB");
    printf("\n\t\t\t\t\t> CONTROLS");
    printf("\n\t\t\t\t\t  FOR MOVES:- 'W','S','A','D'");
    printf("\n\t\t\t\t\t  GO BACKWARD:- 'P'");
    printf("\n\t\t\t\t\t  RESTAT THE GAME:- 'R'");
    printf("\n\t\t\t\t\t  EXIT:-'U'");

    printf("\n\n\t\t\t\t\tPRESS ANY KEY TO START THE GAME....\n\t\t\t\t\t");

    getch();
    system("cls") ;
     printf("\n\t\t\t\t\t===============2048==============\n");
    printf("\n\n\t\t\t\t\tLOADING...\n\n\t\t\t\t\t");
    for(int i=0,j;i<35;i++)
    {
        printf("%c",s);
        j=i;
        if(i%2!=0 && i<20){
            Sleep(1);
        }

    }
    Sleep(1);
    system("cls") ;
    int ***p;
    p=(int ***)malloc(sizeof(int *)*(MAXPREV+1));
    for(int i=0;i<MAXPREV+1;i++)
    {
        *(p+i)=(int **)malloc(sizeof(int *)*4);
    }
    for(int i=0;i<MAXPREV+1;i++)
    {
        for(int j=0;j<4;j++)
        {
            p[i][j]=(int *)malloc(sizeof(int)*4);
        }
    }
    createprev(p);

    FILE *ptr;
    ptr=fopen("highscore.txt","r");
    fscanf(ptr,"%d",&highscore);
    fclose(ptr);
    ptr=fopen("hstr.txt","w");
    fclose(ptr);
    addrandomno();
    print();
    while(1)
    {
            if(score>highscore)
            {

            ptr=fopen("highscore.txt","w");
            fprintf(ptr,"%d",score);
            fclose(ptr);
            }
        choise=getch();
        if(choise=='D' || choise =='d')
        {
            count++;ch++;
              createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[i][j];
                }
                    rupdate();
                for(k=0;k<4;k++)
                {
                    arr[i][k]=c[k];
                }
            }
        }
        else if(choise=='a' || choise=='A')
        {
            count++;
            ch++;
            createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[i][j];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                    arr[i][3-k]=c[k];
                }
            }
        }
        else if(choise=='s' || choise =='S')
        {
            count++;ch++;

               createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[j][i];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                    arr[k][i]=c[k];
                }
            }
        }
        else if(choise=='w' || choise=='W')
        {
            count++;ch++;

              createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[j][i];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                  arr[3-k][i]=c[k];
                }
            }
        }
        else if(choise=='p' || choise =='p')
        {

            updatearrtoprev(p);

            temp=8;
        }
        else if(choise=='R' || choise=='r')
        {
            count=0;
            resetgame();
            print();
            continue;
        }
        else if(choise=='u'||choise=='U')
        {
            main_menu();
        }

            if(temp==1)
            {
                temp=0;
                system("cls") ;
                printf("\n%c\n",choise);
                addrandomno();
                print();

            }
            else if(temp==8)
            {
                temp=0;
                print();
            }
            else
            {
                for(m=0;m<4;m++)
                {
                    for(n=3;n>0;n--)
                    {
                        if(arr[m][n]==arr[m][n-1] || arr[m][n]==0 || arr[m][n-1]==0)
                        {
                                same=1;
                                break;
                        }
                        if(arr[n][m]==arr[n-1][m] || arr[m][n]==0 || arr[m][n-1]==0)
                        {
                            same=1;
                            break;
                        }
                    }
                    if(same==1)
                        break;
                }
               if(same==1)
                {
                    printf("\n\t\t\t\t\t============INVALID KEY==========\n");
                    same=0;


                }
                else
                {
                    printf("\n\t\t\t\t\t=============GAME OVER============");
                    printf("\n\n\t\t\t\t\tWANT TO PLAY MORE?? Y/N??\n\t\t\t\t\t");
                    reschk=getch();
                    switch (reschk)
                    {
                        case 'Y':
                        case 'y':resetgame(); print();break;
                        case 'n':
                        case 'N':main_menu();
                    }
                    continue;

                }
            }
    }
    return 0;
}




//==================================================quiz=====================================================

int quiz()
{
    system("cls");
    int i;
    int ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10;
    int point1,point2,point3,point4,point5,point6,point7,point8,point9,point10;
    int point01,point02,point03,point04,point05,point06,point07,point08,point09,point010;
    int total;
    printf("\t\t\t C PROGRAMMIMG MINI PROJECT QUIZ GAME\n\n");
    printf("\t\t\t WELCOME TO QUIZ GAME\n\n");


    printf(">Press 1 to start quiz\n");
    printf(">Press 0 to quit the quiz game\n");
    printf("[Press 0 at any stage to exit the quiz]\n");
    printf("Enter your choice: ");
    scanf("%d",&i);
    if(i==1)
    {
        printf("The Quiz Has Started:\n\n");

    }
    else if(i==0)
    {
        printf("The Quiz Has Ended");
        main_menu();
    }
    else
    {
        printf("Invalid Value");
    }
    if(i==1)
    {


    printf("*************************\n");
    printf("1) Who is the Father of Computer?\n\n");
    printf("1) Allen Turing\n");
    printf("2) Charles Babbage\n");
    printf("3) Simur Cray\n");
    printf("4)Augusta Adaming\n");
    }
    printf("\n\nEnter Your Answer:");
    scanf("%d",&ans1);
    if(ans1==2)
    {
        
        printf("Correct Answer\n");
        
        point1=5;
        printf("You Have Scored %d Point \n\n",point1);

    }
    else if(ans1==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point1=0;
        printf("\n You have scored %d point \n\n",point1);
    }
    printf("**************************\n");
    printf("\t\t\t\t Second MCQS\n");
    printf("**************************\n");
    printf("2)WWW Stands for?\n\n");
    printf("1) World Whole Web\n");
    printf("2) Wide World Web\n");
    printf("3) Web World Wibe\n");
    printf("4) World Wide Web\n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans2);
    if(ans2==4)
    {
        printf("Correct Answer\n");
        point2=5;
        printf("You Have Scored %d Point \n\n",point2);

    }
    else if(ans2==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point2=0;
        printf("\n You have scored %d point \n\n ",point2);
    }

    printf("**************************\n");
    printf("\t\t\t\t Third MCQS\n");
    printf("**************************\n");
    printf("3) __ is a picture in which the flows of computational paths are depicted \n\n");
    printf("1) Algorithm \n");
    printf("2) Program \n");
    printf("3) Code \n");
    printf("4) Flow chart \n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans3);
    if(ans3==4)
    {
        printf("Correct Answer\n");
        point3=5;
        printf("You Have Scored %d Point \n\n",point3);

    }
    else if(ans3==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point3=0;
        printf("\n You have scored %d point \n\n ",point3);
    }
    printf("**************************\n");
    printf("\t\t\t\t Fourth MCQS\n");
    printf("**************************\n");
    printf("4)If the function returns no value then it is called _.\n\n");
    printf("1) Data type function \n");
    printf("2) Calling function \n");
    printf("3) Main function \n");
    printf("4) Void function \n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans4);
    if(ans4==4)
    {
        printf("Correct Answer\n");
        point4=5;
        printf("You Have Scored %d Point \n\n",point4);

    }
    else if(ans4==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point4=0;
        printf("\n You have scored %d point \n\n ",point4);
    }
    printf("**************************\n");
    printf("\t\t\t\t Fifth MCQS\n");
    printf("**************************\n");
    printf("5)Who is the father of C language? \n\n");
    printf("1) Steve Jobs\n");
    printf("2) James Gosling\n");
    printf("3) Dennis Ritchie\n");
    printf("4) Rasmus Lerdorf\n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans5);
    if(ans5==3)
    {
        printf("Correct Answer\n");
        point5=5;
        printf("You Have Scored %d Point \n\n",point5);

    }
    else if(ans5==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point5=0;
        printf("\n You have scored %d point \n\n ",point5);
    }
    printf("**************************\n");
    printf("\t\t\t\t Sixth MCQS\n");
    printf("**************************\n");
    printf("6) All keywords in C are in _\n\n");
    printf("1) LowerCase letters\n");
    printf("2) UpperCase letters\n");
    printf("3) Camelcase letters\n");
    printf("4) none \n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans6);
    if(ans6==1)
    {
        printf("Correct Answer\n");
        point6=5;
        printf("You Have Scored %d Point \n\n",point6);

    }
    else if(ans6==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point6=0;
        printf("\n You have scored %d point \n\n ",point6);
    }

    printf("**************************\n");
    printf("\t\t\t\t Seventh MCQS\n");
    printf("**************************\n");
    printf("2) Which of the following cannot be a variable name in C?\n\n");
    printf("1) volatile\n");
    printf("2) true\n");
    printf("3) friend\n");
    printf("4) export\n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans7);
    if(ans7==1)
    {
        printf("Correct Answer\n");
        point7=5;
        printf("You Have Scored %d Point \n\n",point7);

    }
    else if(ans7==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point7=0;
        printf("\n You have scored %d point \n\n ",point7);
    }
    printf("**************************\n");
    printf("\t\t\t\t Eight MCQS\n");
    printf("**************************\n");
    printf("8) Which keyword is used to prevent any changes in the variable within a C program?\n\n");
    printf("1) immutable \n");
    printf("2) mutable\n");
    printf("3) const\n");
    printf("4) volatile \n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans8);
    if(ans8==3)
    {
        printf("Correct Answer\n");
        point8=5;
        printf("You Have Scored %d Point \n\n",point8);

    }
    else if(ans8==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point8=0;
        printf("\n You have scored %d point \n\n ",point8);
    }
    printf("**************************\n");
    printf("\t\t\t\t Ninth MCQS\n");
    printf("**************************\n");
    printf("9) Which of the following is not possible statically in C language?\n\n");
    printf("1) Jagged Array\n");
    printf("2) Rectangular array\n");
    printf("3) Cuboidal array\n");
    printf("4) Multidimensional array \n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans9);
    if(ans9==1)
    {
        printf("Correct Answer\n");
        point9=5;
        printf("You Have Scored %d Point \n\n",point9);

    }
    else if(ans9==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point9=0;
        printf("\n You have scored %d point \n\n ",point9);
    }
    printf("**************************\n");
    printf("\t\t\t\t Tenth  MCQS\n");
    printf("**************************\n");
    printf("10) How are Strings represented in memory of C ?\n\n");
    printf("1) An array of characters \n");
    printf("2) The object of some class \n");
    printf("3) Same as other primitive data types\n");
    printf("4) LinkedList of characters \n");

    printf("\n\n Enter Your Answer:");
    scanf("%d",&ans10);
    if(ans10==1)
    {
        printf("Correct Answer\n");
        point10=5;
        printf("You Have Scored %d Point \n\n",point10);

    }
    else if(ans10==0){
        main_menu();
    }
    else
    {
        printf("Wrong Answer");
        point10=0;
        printf("\n You have scored %d point \n\n ",point10);
    }
    total=point1+point2+point3+point4+point5+point6+point7+point8+point9+point10;
    printf("***********************\n");
    printf("\t\t\t\t Your total score is: %d\n",total);
    printf("************************\n");
    char option;
    printf("Do you wanna play again(Y/N):");
    scanf(" %c",&option);
    if(option=='Y'){
        quiz();
    } 
    else{
    main_menu();
    }
    return 0;

}




//===========================================higher lower=============================================================

int higherlower()
{
    loading();
    system("cls");
	srand (time(NULL));	

	int n = rand() % 100 + 1,
	    c = -1;
    int count=0;

	while ( n != c )
	{
		if ( c == -1)
			printf("Guess a number 1-100\n");
		else if (c > n)
			printf("Too high!\n");
		else if (c < n)
			printf("Too low!\n");

		printf("Enter your guess: ");
		scanf ("%d",&c);
        count++;
	}


	printf("Winner! Yes, the answer was %d \nGuesses taken:%d\n",n,count);
    char choice;
    printf("Do you want to play again(Y/N)?");
    scanf(" %c",&choice);
    if(choice=='Y'){
        higherlower();
    }
    else{
        main_menu();
    }
}





//=============================================scramble=============================================================
//two player game(pending)

void shuffle(char *word) {
    int length = strlen(word);
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap characters
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}
int scramblem(char word[]){
    system("cls");
    char originalWord[50];
// Save the original word before shuffling
    strcpy(originalWord, word);

    // Shuffle the word
    shuffle(word);

    // Display the scrambled word
    printf("Scrambled word: %s\n", word);

    // Get the user's guess
    char guess[50];
    printf("Your guess: ");
    scanf(" %s", guess);

    // Check if the guess is correct
    if (strcmp(guess, originalWord) == 0) {
        printf("Congratulations! You guessed correctly.\n");
    } else {
        printf("Sorry, incorrect guess. The correct word is: %s\n", originalWord);
    }
    char choice;
    printf("Do you want to play again(Y/N)?");
    scanf("%c",&choice);
    if (choice=='Y'){
        scramble();
    }
    else{
        main_menu();
    }
    return 0;   
}
int scramble() {
    system("cls");
    char word[50];
    

    // Seed the random number generator
    srand(time(NULL));

    // Get a word from the user
    printf("Enter a word for the word scramble game: ");
    scanf(" %s", word);
    scramblem(word);
    return 0;
}

//==================================================main=======================================================================

int main()
{
    start_page();
    return 0;
}
/*******************************************************************
END OF PROJECT
 ********************************************************************/
