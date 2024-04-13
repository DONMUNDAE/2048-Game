#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

int check(int temp[4][4],int a[4][4]){
    int f1=1;
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(temp[i][j]!=a[i][j]){
                    f1=0;
                    break;
            }
        }
    }
    return f1;
}
int checkover(int a[4][4]){
    int f1=0,g1=0,g2=0;
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(a[i][j]==2048){
                    f1=2;
                    break;
                }
            }
            if(f1==2) break;
        }
        if(f1!=2){
     for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(a[i][j]==0){
                    f1=1;
                    break;
                }
            }
            if(f1) break;
        }
    
     for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]==a[i+1][j]){
                    g1=1;
                    break;
                }
            }
            if(g1) break;
        }
      for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                if(a[i][j]==a[i][j+1]){
                    g2=1;
                    break;
                }
            }
            if(g2) break;
        }
        if(f1||g1||g2) return 1;
        else return 0;
        }
        else
            return 2;
}

void disp(int a[4][4]){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
     for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                cout<<" | "<<a[i][j];
            
            cout<<" | "<<endl;
        }

}

void addblock(int a[4][4]){
    int li,ri;
    srand(time(0));
    while(1){
        li=rand()%4;
        ri=rand()%4;
        if(a[li][ri]==0){
            a[li][ri]=2;
            break;
        }
    }
}
void up(int a[4][4]){
    int li;
     for(int j=0;j<4;j++){
        li=0;
            for(int i=1;i<4;i++){
                if(a[i][j]!=0){
                    if(a[i-1][j]==0 || a[i-1][j]==a[i][j]){
                        if(a[i-1][j]==a[i][j]){
                            a[li][j]=a[i][j]*2;
                            a[i][j]=0;
                            
                        }
                        else{
                            if(a[li][j]==0){
                                a[li][j]=a[i][j];
                                a[i][j]=0;
                            }
                             else if(a[li][j]!=a[i][j]){
                                a[++li][j]=a[i][j];
                                a[i][j]=0;
                             }
                            else{
                                a[li][j]=2*a[i][j];
                                a[i][j]=0;
                            }
                        }
                        
                    }
                    else   li++;
                }
                
            }
          
        }
}
void down(int a[4][4]){
    int li;
     for(int j=0;j<4;j++){
        li=3;
            for(int i=2;i>-1;i--){
                if(a[i][j]!=0){
                    if(a[i+1][j]==0 || a[i+1][j]==a[i][j]){
                        if(a[i+1][j]==a[i][j]){
                            a[li][j]=a[i][j]*2;
                            a[i][j]=0;
                            
                        }
                        else{
                            if(a[li][j]==0){
                                a[li][j]=a[i][j];
                                a[i][j]=0;
                            }
                             else if(a[li][j]!=a[i][j]){
                                a[--li][j]=a[i][j];
                                a[i][j]=0;
                             }
                            else{
                                a[li][j]=2*a[i][j];
                                a[i][j]=0;
                            }
                        }
                        
                    }
                    else   li--;
                }
                
            }
          
        }
}

void left(int a[4][4]){
     int li;
     for(int i=0;i<4;i++){
        li=0;
            for(int j=1;j<4;j++){
                if(a[i][j]!=0){
                    if(a[i][j-1]==0 || a[i][j-1]==a[i][j]){
                        if(a[i][j-1]==a[i][j]){
                            a[i][li]=a[i][j]*2;
                            a[i][j]=0;
                            
                        }
                        else{
                            if(a[i][li]==0){
                                a[i][li]=a[i][j];
                                a[i][j]=0;
                            }
                             else if(a[i][li]!=a[i][j]){
                                a[i][++li]=a[i][j];
                                a[i][j]=0;
                             }
                            else{
                                a[i][li]=2*a[i][j];
                                a[i][j]=0;
                            }
                        }
                        
                    }
                    else   li++;
                }
                
            }
          
        }
}

void right(int a[4][4]){
     int li;
     for(int i=0;i<4;i++){
        li=3;
            for(int j=2;j>-1;j--){
                if(a[i][j]!=0){
                    if(a[i][j+1]==0 || a[i][j+1]==a[i][j]){
                        if(a[i][j+1]==a[i][j]){
                            a[i][li]=a[i][j]*2;
                            a[i][j]=0;
                            
                        }
                        else{
                            if(a[i][li]==0){
                                a[i][li]=a[i][j];
                                a[i][j]=0;
                            }
                             else if(a[i][li]!=a[i][j]){
                                a[i][--li]=a[i][j];
                                a[i][j]=0;
                             }
                            else{
                                a[i][li]=2*a[i][j];
                                a[i][j]=0;
                            }
                        }
                        
                    }
                    else   li--;
                }
                
            }
          
        }
}


int main(){
    cout<<"\n\n\n\n\n\t2048\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");

    int i1,i2,i3,i4;
    int a[4][4]={0},temp[4][4];
    srand(time(0));
    i1=rand()%4;
    i2=rand()%4;
    while(1){
        i3=rand()%4;
        i4=rand()%4;
        if(i3!=i1&&i4!=i2)
        break;
    }
    a[i1][i2]=2;
    a[i3][i4]=4;
    disp(a);

    int ch;
    while(1){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                temp[i][j]=a[i][j];
            }
        }
        ch=getch();
        if(ch==119) up(a);
        if(ch==115) down(a);
        if(ch==97) left(a);
        if(ch==100) right(a);
        if(ch==27) break;

        if(!check(temp,a))
            addblock(a);
    
        disp(a);

        if(checkover(a)==0){
            cout<<"\n\n\n\n\n\t\t\tGAME OVER!!!\n\n\n";
            getch();
            break;
        }
        else if (checkover(a)==2){
             cout<<"\n\n\n\n\n\t\t\tYOU WON!!!!!\n\n\n";
            getch();
            break;
        }

            
        
    }
    return 0;
}