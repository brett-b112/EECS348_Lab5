#include <stdio.h>

int main() {
    int score;
    int combinations[10000][5]; // Assuming a maximum of 10000 combinations with up to 6 plays

    while (1) {
		printf("Enter 1 or 0 to quit: \n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }

            
            int count = 0; // Count of valid combinations
            
            // Use nested loops to generate combinations
            for (int td = 0; td * 6 <= score; td++) { //Starts with 0 touchdowns and iterates.
                for (int fg = 0; fg * 3 <= score; fg++) {//Starts with 0 fieldgoals and iterates.
                    for (int safety = 0; safety * 2 <= score; safety++) {//Starts with 0 safeties.
                        for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {//Starts with 0 touchdowns and twopoints.
                            for (int td1fg = 0; td1fg * 7 <= score; td1fg++) {//Starts with 0 touchdowns and 1pt fg and iterates throguh increasing.
                                int total = (td * 6) + (fg * 3) + (safety * 2) + (td2pt * 8) + (td1fg * 7);
                                if (total == score) { // If total is the score it and stores it.
                                    combinations[count][0] = td;
                                    combinations[count][1] = fg;
                                    combinations[count][2] = safety;
                                    combinations[count][3] = td2pt;
                                    combinations[count][4] = td1fg;
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
            
            // Print the valid combinations with scoring play names
            printf("possible combinations of scoring plays:\n");
            for (int i = 0; i < count; i++) {//This loops through the current comvinations and then prints them.
                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                       combinations[i][3], combinations[i][4], combinations[i][0],
                       combinations[i][1], combinations[i][2]);
            }

    }
    
    return 0;
}

