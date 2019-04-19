#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() 
{
      int ArTime[20], BurTime[20];
      int i, least, count = 0, t, n,plus=0;
      double WtTime = 0, TurnAroundTime = 0, end;
      int flag=0;
      float AvgWT, Avg_TAT;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n); 
      system("clear");
      printf("\nEnter Details of %d Processes\n", n);
   //Taking Input of Arrival Time and Burst Time
 int num;
   int temp[20];
   int sumburst=0;
      for(i = 0; i < n; i++)
      {
           A : printf("\nEnter Arrival Time:\t");
            scanf("%d", &ArTime[i]);
            if(ArTime[i]==0)
            {
                  system("clear");
                  printf("You have enter ARRIVAL TIM as 0. \n\n ");
                 B : printf("\nEnter a vaild input for : ");
                  printf("\n Press 1 : Enter Again ARRIVAL TIME");
                  printf("\n Press 2 : To EXIT \n\n");
                  printf("INPUT :: ");
                  scanf("%d",&num);
                  switch (num)
                  {
                  case 1 : goto A;
                        break;
                  case 2 : exit(0);
                  default:
                  printf("INVAILD INPUT\n\n");
                  goto B;
                        break;
                  }

            }

            printf("Enter Burst Time:\t");
            scanf("%d", &BurTime[i]); 
            sumburst=sumburst+BurTime[i];
            temp[i] = BurTime[i];
      }
    
    system("clear");
     BurTime[19] = 999999;  //initializing last as any random HUGE VALUE
    printf("\n\n\t\t:: COMPLETION OF PROCESS :: \n\n ");
     printf("\nProcess\t    Burst Time    \tWaiting Time\tTurn Around Time");
     int wt,TAT;
      for(t = 0; count != n; t++)
      {  
            least = 19;
            for(i = 0; i < n; i++)    //LOOP to check process by process
            {
                  if((ArTime[i] <= t) && (BurTime[i] < BurTime[least]) && (BurTime[i] > 0))
                      //1) Checking Arival time should be less than currently ongoing time
                      //2) Burst time of current process should be less than of the least
                      //3) Burst time should be of any +ve value of time.
                  {
                        least = i;   // if these condition satisfy then current will be least now
                  }
            }
            
            BurTime[least]--;
            if(BurTime[least] == 0)
            {
                  count++;
                  end = t + 1;
                 if(count==1)
                 {
                  wt=WtTime;
                  WtTime = WtTime + end - ArTime[least] - temp[least];      //Calculating WAITING TIME
                  wt=WtTime-wt;
                  AvgWT = AvgWT+wt;
                  TAT=TurnAroundTime;
                  TurnAroundTime = TurnAroundTime + end - ArTime[least];    //Calculating TURN AROUND TIME
                  TAT=TurnAroundTime-TAT;
                  Avg_TAT = Avg_TAT+TAT;
                  sleep(1);
                  printf("\nP%d\t\t  %d\t\t    %d\t\t%d",(least+1),temp[least],wt,TAT);
                 }
                 else{
                  flag++;
                 plus=plus+2;
                  wt=WtTime;
                  WtTime = WtTime + end - ArTime[least] - temp[least];      //Calculating WAITING TIME
                  wt=WtTime-wt+plus;
                  AvgWT = AvgWT+wt;
                  TAT=TurnAroundTime;
                  TurnAroundTime = TurnAroundTime + end - ArTime[least];    //Calculating TURN AROUND TIME
                  TAT=TurnAroundTime-TAT+plus-1;
                  Avg_TAT = Avg_TAT+TAT; 
                  sleep(1);
                  printf("\nP%d\t\t  %d\t\t    %d\t\t%d",(least+1),temp[least],wt,TAT);
                 }
                  
            }
      }
   
        
    int totalexecution=sumburst+(flag*2)+1;
                AvgWT = AvgWT/n;             // AVERAGE WAITING TIME
      Avg_TAT = Avg_TAT/n;             // AVERAGE TURN AROUND TIME
      sleep(1);
      
      printf("\n\n\nTOTAL TIME OF EXECUTION : %d",totalexecution);
      printf("\n\n||Average Waiting Time    :\t%lf||\n", AvgWT);
      sleep(1);
      printf("||Average Turnaround Time :\t%lf||\n", Avg_TAT);
      return 0;
}