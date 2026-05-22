#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    // n = number of processes
    // m = number of resource types

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m], available[m];
    int finish[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    // Initialize Finish array
    for(i = 0; i < n; i++)
    {
        int flag = 0;

        for(j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    // Deadlock Detection Algorithm
    int work[m];

    for(i = 0; i < m; i++)
        work[i] = available[i];

    int found;

    do
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    // Check Deadlock
    int deadlock = 0;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            printf("\nProcess P%d is deadlocked", i);
        }
    }

    if(deadlock == 0)
        printf("\nNo Deadlock Detected\n");

    return 0;
}
