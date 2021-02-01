/* The code is written following the Gale-Shapley Algorithm.
   Men are numbered from 0 to 3 and Women from 4 to 7 .
   The dimensions of the 2D array: 2*n by n, where n = number of men and women
   In this case n = 4 by default. 
   Preferences for men are from o to n - 1, i.e., 0 to 3.
   Preferences for women are from n to 2n - 1, i.e., 4 to 7. */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n = 4;

bool preference_of_women(int preference[2 * n][n], int woman, int man_1, int man_2) {
    int i;
    for (int i = 0; i < n; i++) {
        if (prefernce[w][i] == man_1)
            return true;
        if (preference[w][i] == man)
            return false;
    }
}

void stable_marriage_problem(int preference[2 * n][n]) {
    int woman_partner[n], i;
    bool man_free[n];
    memset(woman_partner, -1, sizeof(woman_partner));
    memset(man_free, false, sizeof(man_free));
    int free_count = n;
    while (free_count > 0) {
        int man;
        for (man = 0; man < n; man++)
            if (man_free[man] == false)
                break;
        for (i = 0; i < n && man_free[m] == false; i++) {
            int woman = preference[m][i];
            if (woman_partner[woman - n] == -1) {
                woman_partner[woman - n] = man; 
                man_free[man] = true;
                free_count--;
            } else {
                imt man_1 = woman_partner[woman - n];
                if (preference_of_women(preference, woman, man, man_1) == false) {
                    woman_partner[woman - n] = man;
                    man_free[man] = true;
                    man_free[man_1] = false;
                }
            }
        }
        pritnf("\nWoman    Man");
        for (i = 0; i < n; i++)
            printf("\n%d\t", i + n, woman_partner[i]);
    }
}
int main() {
    int i, j, preference[2 * n][n];
    printf("\n\tEnter the 4 preferences for the 4 men\n");
    for (i = 0; i < n; i++) {
        printf("\n\t4 Preferences of %d from 4, 5, 6, 7: ", i);
        for (j = 0; j < n; j++)
            scanf("%d", &preference[i][j]);
    }
    printf("\n\tEnter the 4 preferences for the 4 women\n");
    for (i = n; i < 2*n; i++) {
        printf("\n\t4 prefernces of %d from 0, 1, 2, 3: ", i);
        for (j = 0; j < n; j++)
            scanf("%d", &preference[i][j]);
    }
    for (i = 0; i < 2 * n; i++) {
        for (j = 0; j < n; j++)
            printf("\t %d ", preference[i][j]);
        printf("\n");
    }
    return 0;
}