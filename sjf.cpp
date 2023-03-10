// https://www.javatpoint.com/sjf-cpu-scheduling-program-in-cpp

#include <bits/stdc++.h>  
using namespace std;  

//structure for every process  
struct Process 
    {  
   int pid; // Process ID  
   int bt; // Burst Time  
   int art; // Arrival Time  
    };  


void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
    {  
   for (int i = 0; i < n; i++)  
   tat[i] = proc[i].bt + wt[i];  
    }  


//waiting time of all process  
void findWaitingTime(Process proc[], int n, int wt[]) 
    {  
   int rt[n];  
   for (int i = 0; i < n; i++)  
   rt[i] = proc[i].bt;  
   int complete = 0, t = 0, minm = INT_MAX;  
   int shortest = 0, finish_time;  
   bool check = false;  
   while (complete != n) {  
      for (int j = 0; j < n; j++) {  
         if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {  
            minm = rt[j];  
            shortest = j;  
            check = true;  
         }  
      }  
      if (check == false) {  
         t++;  
         continue;  
      }  
      // decrementing the remaining time  
      rt[shortest]--;  
      minm = rt[shortest];  
      if (minm == 0)  
         minm = INT_MAX;  
         // If a process gets completely  
         // executed  
         if (rt[shortest] == 0) {  
            complete++;  
            check = false;  
            finish_time = t + 1;  
            // Calculate waiting time  
            wt[shortest] = finish_time -  
            proc[shortest].bt -  
            proc[shortest].art;  
            if (wt[shortest] < 0)  
               wt[shortest] = 0;  
         }  
         // Increment time  
         t++;  
   }  
}  
// Function to calculate average time  
void findavgTime(Process proc[], int n) {  
   int wt[n], tat[n], total_wt = 0,  
   total_tat = 0;  
   // Function to find waiting time of all  
   // processes  
   findWaitingTime(proc, n, wt);  
   // Function to find turn around time for  
   // all processes  
   findTurnAroundTime(proc, n, wt, tat);  
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";  
   for (int i = 0; i < n; i++) {  
      total_wt = total_wt + wt[i];  
      total_tat = total_tat + tat[i];  
      cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;  
   }  
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;  
}  


// main function  
int main() 
    {  
   Process proc[] = { { 1, 5, 1 }, { 2, 3, 1 }, { 3, 6, 2 }, { 4, 5, 3 } };  
   int n = sizeof(proc) / sizeof(proc[0]);  
   findavgTime(proc, n);  
   return 0;    
    } 

/*
Start  
Step 1-> Declare a struct Process  
   Declare pid , bt , art  
Step 2-> In function findTurnAroundTime ( Process proc [ ] , int n , int wt [ ] , int tat [ ] )  
   Loop For i = 0 and i < n and i++  
      Set tat [ i ] = proc [ i ].bt + wt [ i ]  
Step 3-> In function findWaitingTime ( Process proc [ ] , int n , int wt [ ] )  
   Declare rt [ n ]  
   Loop For i = 0 and i < n and i++  
      Set rt [ i ] = proc [ i ].bt  
      Set complete = 0 , t = 0 , minm = INT_MAX  
      Set shortest = 0 , finish_time  
      Set bool check = false  
      Loop While ( complete != n )  
         Loop For j = 0 and j < n and j++  
            If (proc [ j ].art <= t ) && ( rt [ j ] < minm ) && rt [ j ] > 0 then ,  
               Set minm = rt [ j ]  
               Set shortest = j  
               Set check = true  
            If check == false then ,  
               Increment t by 1  
               Continue  
               Decrement the value of rt [ shortest ] by 1  
               Set minm = rt [ shortest ]  
            If minm == 0 then ,  
               Set minm = INT_MAX  
               If rt [ shortest ] == 0 then ,  
               Increment complete by 1  
               Set check = false  
               Set finish_time = t + 1  
               Set wt [ shortest ] = finish_time - proc [ shortest ].bt - proc [ shortest ].art  
            If wt [ shortest ] < 0  
               Set wt [ shortest ] = 0  
               Increment t by 1  
Step 4-> In function findavgTime ( Process proc [ ] , int n )  
   Declare and set wt [ n ] , tat [ n ] , total_wt = 0 , total_tat = 0  
   Call findWaitingTime ( proc , n , wt )  
   Call findTurnAroundTime ( proc , n , wt , tat )  
   Loop For i = 0 and i < n and i++  
      Set total_wt = total_wt + wt [ i ]  
      Set total_tat = total_tat + tat [ i ]  
      Print proc [ i ].pid , proc [ i ].bt , wt [ i ] , tat [ i ]  
      Print Average waiting time i.e. , total_wt / n  
      Print Average turn around time i.e. , total_tat / n  
Step 5-> In function int main ( )  
   Declare and set Process proc [ ] = { { 1 , 5 , 1 } , { 2 , 3 , 1 } , { 3 , 6 , 2 } , { 4 , 5 , 3 } }  
   Set n = sizeof ( proc ) / sizeof ( proc [ 0 ] )  
   Call findavgTime ( proc , n )  
Stop  
*/