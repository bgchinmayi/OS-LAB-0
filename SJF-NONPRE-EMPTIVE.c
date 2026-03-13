#include <stdio.h>

int main() {
    int n,i,j;
    int at[20],bt[20],ct[20],tat[20],wt[20],rt[20];
    float avg_tat=0,avg_wt=0,avg_rt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }

    int time = 0;

    for(i=0;i<n;i++){
        int min = i;

        for(j=i+1;j<n;j++){
            if(bt[j] < bt[min])
                min = j;
        }

        int temp;

        temp = bt[i]; bt[i] = bt[min]; bt[min] = temp;
        temp = at[i]; at[i] = at[min]; at[min] = temp;

        if(time < at[i])
            time = at[i];

        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
        avg_rt += rt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT = %.2f",avg_wt/n);
    printf("\nAverage RT = %.2f",avg_rt/n);

    return 0;
}
