#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() 
{
      int ArTime[20], BurTime[20];
      int i, least, count = 0, t, n;
      double WtTime = 0, TurnAroundTime = 0, end;
      float AvgWT, Avg_TAT;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n); 
      system("clear");
      printf("\nEnter Details of %d Processes\n", n);
   //Taking Input of Arrival Time and Burst Time

   int temp[20];
      for(i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &ArTime[i]);

            printf("Enter Burst Time:\t");
            scanf("%d", &BurTime[i]); 
            temp[i] = BurTime[i];
      }
    
    system("clear");
     BurTime[19] = 999999;  //initializing last as any random HUGE VALUE
    printf("\n\n\t\t:: COMPLETION OF PROCESS :: \n\n ");
     printf("\nProcess\t    Burst Time    \tWaiting Time\tTurn Around Time");
     
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
                  
                  int wt=WtTime;
                  WtTime = WtTime + end - ArTime[least] - temp[least];      //Calculating WAITING TIME
                  wt=WtTime-wt;
                  int TAT=TurnAroundTime;
                  TurnAroundTime = TurnAroundTime + end - ArTime[least];    //Calculating TURN AROUND TIME
                  TAT=TurnAroundTime-TAT;
                  sleep(1);
                  printf("\nP%d\t\t  %d\t\t    %d\t\t%d",(least+1),temp[least],wt,TAT);
                  
            }
      }
    
    
    
      AvgWT = WtTime / n;                         // AVERAGE WAITING TIME
      Avg_TAT = TurnAroundTime / n;              // AVERAGE TURN AROUND TIME
      sleep(1);
      printf("\n\n||Average Waiting Time    :\t%lf||\n", AvgWT);
      sleep(1);
      printf("||Average Turnaround Time :\t%lf||\n", Avg_TAT);
      return 0;
}