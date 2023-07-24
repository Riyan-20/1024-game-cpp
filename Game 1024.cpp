#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int getRandomNumber()
{
    srand(time(NULL));
    int randNum;
    for(int i=0;i<10000;i++)
    {
        randNum=rand() % 3;
        if(randNum != 0){
        break;}
    }
    return randNum;
}

void getRandomIndex(int board[4][4], int &num1, int &num2)
{
    srand(time(NULL));
    //number between 0 and 5
    for(int i=0;i<10000;i++)
    {
        num1=rand() % 4;
        num2=rand() % 4;
        if(board[num1][num2] == 0){
        break;}
    }
}

//void printBoard(int board[][4])
//{
//    cout << endl;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            cout << "     " << board[i][j] << "     ";
//        }
//        cout << endl
//             << endl
//             << endl;
//    }
//}

void printGridBoard(int board[4][4])
{
    cout<<endl;
	cout<<"\t\t\t\t\t ENTER Q TO QUIT THE GAME."<<endl;
	cout<<"\t\t\t\t\t ENTER U TO MOVE UPWARD."<<endl;
	cout<<"\t\t\t\t\t ENTER D TO MOVE DOWNWARD."<<endl;
	cout<<"\t\t\t\t\t ENTER L TO MOVE LEFT."<<endl;
	cout<<"\t\t\t\t\t ENTER R TO MOVE RIGHT."<<endl;
	cout<<endl<<endl;
    for (int i=0;i<4;i++){
    cout<<"\t\t\t\t\t---------------------------------"<<endl;
    cout<<"\t\t\t\t\t";
    for (int j=0;j<4;j++){
    cout<<"|";
    if(board[i][j]==0){
    	cout<<"       ";
	}else{
		if (board[i][j]>0 && board[i][j]<10){
		cout<<"   "<<board[i][j]<<"   ";}
		if (board[i][j]>=10 && board[i][j]<100){
		cout<<"   "<<board[i][j]<<"  ";}
		if (board[i][j]>=100 && board[i][j]<1000){
		cout<<"  "<<board[i][j]<<"  ";}
		if (board[i][j]>=1000 && board[i][j]<10000){
		cout<<"  "<<board[i][j]<<" ";}}
	}
    cout<<"|";
    cout<<endl;
    }
    cout<<"\t\t\t\t\t---------------------------------"<<endl;
}


void shiftToLeft(int board[4][4])
{
    //shift all elements to the right
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == 0 && board[i][j+1] == 0 && board[i][j+2] == 0) //if it has three zeros
            {
                for(int k=j;k<3;k++) //shift right till second 0
                {
                    board[i][k] = board[i][k+1];
                }
                board[i][3] = 0;
                for(int k=j;k<3;k++) //till 1st 0
                {
                    board[i][k] = board[i][k+1];
                }
                board[i][3] = 0;
                for(int k=j;k<3;k++) //shift right till rightmost
                {
                    board[i][k] = board[i][k+1];
                }
                board[i][3] = 0;
            }
            else if(board[i][j] == 0 && board[i][j+1] == 0) //if 2 indexes have 0
            {
                for(int k=j;k<3;k++) //shift right till first 0
                {
                    board[i][k] = board[i][k+1];
                }
                board[i][3] = 0;
                for(int k=j;k<3;k++) //till rightmost
                {
                    board[i][k] = board[i][k+1];
                }
                board[i][3] = 0;
            }
            else if(board[i][j] == 0)
            {
                for(int k=j;k<3;k++) //shift till rightmost
                {
                    board[i][k] = board[i][k+1];
                }
                board[i][3] = 0;
            }
        }
    }
    //if two adjacent elements are the same, combine them
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j] == board[i][j+1])
            {
                board[i][j] = board[i][j] + board[i][j+1]; //add both
                for(int k=j+1;k<4;k++)
                {
                    board[i][k] = board[i][k+1]; //shift right to cover empty spaces
                }
                board[i][3] = 0; //set last element to 0
            }
        }
    }
    int num1, num2;
    getRandomIndex(board, num1, num2);
    board[num1][num2] = getRandomNumber();
}

void shiftToRight(int board[4][4])
{
    //shift all elements to the left
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>0;j--)
        {
            if(board[i][j] == 0 && board[i][j-1] == 0 && board[i][j-2] == 0) //if it has three zeros
            {
                for(int k=j;k>0;k--) //shift left till second 0
                {
                    board[i][k] = board[i][k-1];
                }
                board[i][0] = 0;
                for(int k=j;k>0;k--) //till 1st 0
                {
                    board[i][k] = board[i][k-1];
                }
                board[i][0] = 0;
                for(int k=j;k>0;k--) //shift left till rightmost
                {
                    board[i][k] = board[i][k-1];
                }
                board[i][0] = 0;
            }
            else if(board[i][j] == 0 && board[i][j-1] == 0) //if 2 indexes have 0
            {
                for(int k=j;k>0;k--) //shift left till first 0
                {
                    board[i][k] = board[i][k-1];
                }
                board[i][0] = 0;
                for(int k=j;k>0;k--) //till rightmost
                {
                    board[i][k] = board[i][k-1];
                }
                board[i][0] = 0;
            }
            else if(board[i][j] == 0)
            {
                for(int k=j;k>0;k--) //shift till rightmost
                {
                    board[i][k] = board[i][k-1];
                }
                board[i][0] = 0;
            }
        }
    }
    //if two adjacent elements are the same, combine them
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            if(board[i][j] == board[i][j-1])
            {
                board[i][j] = board[i][j] + board[i][j-1]; //add both
                for(int k=j-1;k>=0;k--)
                {
                    board[i][k] = board[i][k-1]; //shift left to cover empty spaces
                }
                board[i][0] = 0; //set last element to 0
            }
        }
    }
    int num1, num2;
    getRandomIndex(board, num1, num2);
    board[num1][num2] = getRandomNumber();
}

void shiftUpwards(int board[4][4])
{
    //shift all elements upwards
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[j][i] == 0 && board[j+1][i] == 0 && board[j+2][i] == 0) //if it has three zeros
            {
                for(int k=j;k<3;k++) //shift up till second 0
                {
                    board[k][i] = board[k+1][i];
                }
                board[3][i] = 0;
                for(int k=j;k<3;k++) //till 1st 0
                {
                    board[k][i] = board[k+1][i];
                }
                board[3][i] = 0;
                for(int k=j;k<3;k++) //shift up till 1st index
                {
                    board[k][i] = board[k+1][i];
                }
                board[3][i] = 0;
            }
            else if(board[j][i] == 0 && board[j+1][i] == 0) //if 2 indexes have 0
            {
                for(int k=j;k<3;k++) //shift up till first 0
                {
                    board[k][i] = board[k+1][i];
                }
                board[3][i] = 0;
                for(int k=j;k<3;k++) //till 1st
                {
                    board[k][i] = board[k+1][i];
                }
                board[3][i] = 0;
            }
            else if(board[j][i] == 0)
            {
                for(int k=j;k<3;k++) //shift up till 1st index
                {
                    board[k][i] = board[k+1][i];
                }
                board[3][i] = 0;
            }
        }
    }
    //if two adjacent elements are the same, combine them
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[j][i] == board[j+1][i])
            {
                board[j][i] = board[j][i] + board[j+1][i]; //add both
                for(int k=j+1;k<3;k++)
                {
                    board[k][i] = board[k+1][i]; //shift up to cover empty spaces
                }
                board[3][i] = 0; //set last element to 0
            }
        }
    }
    int num1,num2;
    getRandomIndex(board, num1, num2);
    board[num1][num2] = getRandomNumber();
}

void shiftDownwards(int board[4][4])
{
    //shift all elements downwards
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>0;j--)
        {
            if(board[j][i] == 0 && board[j - 1][i] == 0 && board[j - 2][i] == 0) //if it has three zeros
            {
                for(int k=j;k>0;k--) //shift down till second 0
                {
                    board[k][i] = board[k-1][i];
                }
                board[0][i] = 0;
                for(int k=j;k>0;k--) //till 1st 0
                {
                    board[k][i] = board[k-1][i];
                }
                board[0][i] = 0;
                for(int k=j;k>0;k--) //shift down till last index
                {
                    board[k][i] = board[k-1][i];
                }
                board[0][i] = 0;
            }
            else if(board[j][i] == 0 && board[j-1][i] == 0) //if 2 indexes have 0
            {
                for(int k=j;k>0;k--) //shift down till first 0
                {
                    board[k][i] = board[k-1][i];
                }
                board[0][i] = 0;
                for (int k=j;k>0;k--) //till last index
                {
                    board[k][i]=board[k-1][i];
                }
                board[0][i] = 0;
            }
            else if(board[j][i] == 0)
            {
                for(int k=j;k>0;k--) //shift down till last index
                {
                    board[k][i] = board[k-1][i];
                }
                board[0][i]=0;
            }
        }
    }
    //if two adjacent elements are the same, combine them
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>0;j--)
        {
            if(board[j][i] == board[j-1][i])
            {
                board[j][i] = board[j][i] + board[j-1][i]; //add both
                for(int k=j-1;k>0;k--)
                {
                    board[k][i] = board[k-1][i]; //shift down to cover empty spaces
                }
                board[0][i]=0; //set last element to 0
            }
        }
    }
    int num1,num2;
    getRandomIndex(board, num1, num2);
    board[num1][num2]=getRandomNumber();
}

void getInput(int board[4][4])
{
    char input='0';
    cout<<endl;
    bool check=true;
    while(1)
    {   if(check==true){
    	cout<<endl<<"\t\t\t\t\t\t ENTER A KEY : "; 
		cin>>input;}
    	
    	if(input=='q' || input=='l' || input=='r' || input=='u' || input=='d')
	{   check=true;
        if(input=='l')
        {
            shiftToLeft(board);
            break;
        }
        else if(input=='r')
        {
            shiftToRight(board);
            break;
        }
        else if(input=='u')
        {
            shiftUpwards(board);
            break;
        }
        else if(input=='d')
        {
            shiftDownwards(board);
            break;
        }
        else if(input=='q')
        {
            cout<<endl<<"Quitting..."<<endl;
            exit(0);
        }
    }
    else{
    	check=false;
    	cout<<endl<<"\t\t\t\t\t\t ENTER A VALID KEY : ";
    	cin>>input;
		}
    }
}

void mainGame()
{
	char input;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t 1024 GAME"<<endl<<endl;
	cout<<"\t\t\t\t\t ENTER S TO START GAME"<<endl<<endl;
	cout<<"\t\t\t\t\t ENTER KEY : ";
    cin>>input;
    
    for(int i=1;i!=0;)
	{
    if(input=='s'){
    system("cls");
    break;
	}
	else{
		cout<<endl<<"\t\t\t\t\t ENTER A VALID KEY : ";
		cin>>input;}
	}
	
    int board[4][4];
    int num1, num2;

    //initialize board
    for (int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            board[i][j]=0;
        }
    }
    cout<<endl;
    getRandomIndex(board, num1, num2);
    board[num1][num2] = getRandomNumber();
    getRandomIndex(board, num1, num2);
    board[num1][num2] = getRandomNumber();

    while(1)
    {   
        system("cls");
        printGridBoard(board);
        cout<<endl;
        getInput(board);
        
     if(board[0][0]>0 && board[0][1]>0 && board[0][2]>0 && board[0][3]>0 &&
       board[1][0]>0 && board[1][1]>0 && board[1][2]>0 && board[1][3]>0 &&
       board[2][0]>0 && board[2][1]>0 && board[2][2]>0 && board[2][3]>0 &&
       board[3][0]>0 && board[3][1]>0 && board[3][2]>0 && board[3][3]>0  ){
   	   cout<<endl<<"\t\t\t\t\t\t GAME OVER!!!"<<endl;
   	break;
    }
    
    bool flag=false;
    
	for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	if(board[i][j]==1024){
	flag=true;
	}}
	if(flag==true){
	break;
	}}
	if(flag==true){
	cout<<endl<<"\t\t\t\t\t\t YOU WON THE GAME!!!"<<endl;
	break;}
  }
}

int main()
{
    mainGame();
    return 0;
}
