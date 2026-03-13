#include <stdio.h>

int main() {
    int n,i,t=0,complete=0,k;
    int at[20],bt[20],rt[20],ct[20],tat[20],wt[20];
    float avg_tat=0,avg_wt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(complete<n){
        k=-1;

        for(i=0;i<n;i++){
            if(at[i]<=t && rt[i]>0){
                if(k==-1 || rt[i]<rt[k])
                    k=i;
            }
        }

        if(k==-1){
            t++;
            continue;
        }

        rt[k]--;
        t++;

        if(rt[k]==0){
            complete++;
            ct[k]=t;
            tat[k]=ct[k]-at[k];
            wt[k]=tat[k]-bt[k];

            avg_tat+=tat[k];
            avg_wt+=wt[k];
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT = %.2f\n",avg_wt/n);

    return 0;
}











