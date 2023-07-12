#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#include <stdbool.h>


void print_table(int (*table)[9]){
    
    printf("\n");
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf(" %d ", table[i][j]);

            if (j == 2 || j == 5){
                printf(" | ");
            }

            if ((i == 2 && j == 8) || (i == 5 && j == 8)){
                printf("\n -  -  -  -  -  -  -  -  -  -  - ");
            }
        }
        printf("\n");
        printf("\n");
    }

}

int* find_empty_cell(int (*table)[9]){
    
    int* empty_cell = malloc(2 * sizeof(int)); 

    int break_var = 0;

    //finds the first empty cell in the table
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (table[i][j] == 0){
                //printf("(%d, %d)\n", i+1, j+1);
                empty_cell[0] = i;
                empty_cell[1] = j;
                
                break_var = 1;
                break;
            }
        }

    if (break_var){
        break; 
    }
    }

    if (break_var)
        return empty_cell;
    
    else if (!break_var){
        empty_cell[0] = 100;
        empty_cell[1] = 100;
        return empty_cell;
    }

}


int valid(int (*table)[9], int pos[], int option) {
    // Check for row
    for (int i = 0; i < 9; i++) {
        if (table[pos[0]][i] == option && pos[1] != i) {
            return 0; 
        }
    }

    // Check for column
    for (int i = 0; i < 9; i++) {
        if (table[i][pos[1]] == option && pos[0] != i) {
            return 0; 
        }
    }

    // Check for square
    int square_row = pos[0] / 3;
    int square_col = pos[1] / 3;
    for (int i = square_row * 3; i < square_row * 3 + 3; i++) {
        for (int j = square_col * 3; j < square_col * 3 + 3; j++) {
            if (table[i][j] == option && (pos[0] != i || pos[1] != j)) {
                return 0;
            }
        }
    }

    return 1;
}

int solver(int (*table)[9]) {
    int (*tab)[9] = malloc(9 * sizeof(int[9]));
    if (tab != NULL) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                tab[i][j] = table[i][j];
            }
        }
    }

    //print_table(tab);

    int* p_to_empty_cell = find_empty_cell(tab);

    if (p_to_empty_cell[0] == 100 && p_to_empty_cell[1] == 100) {
        printf("\n");
        printf("----------SOLVED TABLE-----------");//33 - 12 = 21
        printf("\n");
        print_table(tab);
        return 1;
    } 
    
    else {
        p_to_empty_cell = find_empty_cell(table);
    }

    for (int i = 1; i <= 9; i++) {
        if (valid(tab, p_to_empty_cell, i)) {
            tab[p_to_empty_cell[0]][p_to_empty_cell[1]] = i;

            if (solver(tab)) {
                return 1;
            }

            tab[p_to_empty_cell[0]][p_to_empty_cell[1]] = 0;



        }
    }

    //print_table(tab);

    free(tab);

    return 0;
}



int ** get_tab(const char* filename) {
    
    FILE* file = fopen(filename, "r");

    int ** error_code = malloc(2* sizeof(int*));

    for (int i = 0; i < 2; i++) {
        error_code[i] = malloc(2 * sizeof(int));
    }
    
    if (error_code != NULL){
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                error_code[i][j] = 100;
            }
        }
    }
    
    // for (int i = 0; i < 2; i++) {
    //     free(error_code[i]); 
    // }

    // free(error_code);
    
    
    int** table = malloc(9 * sizeof(int*));

    // printf("%d, %d\n", error_code[0][0], error_code[1][0]);
    

    if (file == NULL) {
        printf("Error: Cannot open  '%s'. Check that you have typed in the correct filename\n", filename);
        return error_code;
    }

    
    if (table == NULL) {
        printf("ERROR: Failure to allocate memory. Check that the file is in the reight format\n");
        fclose(file);
        return error_code;
    }

    char line[256];
    
    for (int i = 0; i < 9; i++){
        if (fgets(line, sizeof(line), file) == NULL){
            printf("Error: Failure to read line %d from the file.\n", i + 1);
            
            for (int j = 0; j < i; j++){
                free(table[j]);
            
            }
            
            free(table);
            fclose(file);
            return error_code;
        }

        table[i] = malloc(9 * sizeof(int));

        if (table[i] == NULL){
            printf("ERROR: Failure to allocate memory. Check that the file is in the reight format\n");
            
            for (int j = 0; j < i; j++){
                free(table[j]);
            }
            
            free(table);
            fclose(file);
            return NULL;
        }

        int num;

        char* token = strtok(line, ", \n");

        for (int j = 0; j < 9; j++){
            if (token == NULL){
                printf("Error: Wrong format on line %d of the file\n", i + 1);
                
                
                for (int k = 0; k <= i; k++) {
                    free(table[k]);
                }

                free(table);
                fclose(file);
                return error_code;
            }


            sscanf(token, "%d", &num);
            table[i][j] = num;
            token = strtok(NULL, ", \n");
        }
    }

    fclose(file);
    return table;
}


int main() {
    printf("Hellow, World!\n");

    // int tab[9][9]  = {
    // {0, 7, 0, 0, 0, 0, 0, 0, 0},
    // {0, 0, 0, 0, 0, 0, 7, 8, 5},
    // {6, 0, 8, 0, 0, 0, 0, 9, 2},
    // {0, 6, 0, 5, 0, 0, 0, 3, 0},
    // {7, 0, 0, 6, 0, 9, 0, 4, 8},
    // {5, 4, 0, 8, 7, 0, 6, 1, 9},
    // {1, 9, 5, 3, 6, 7, 0, 2, 0},
    // {0, 0, 6, 0, 0, 0, 0, 7, 3},
    // {0, 8, 7, 0, 9, 0, 0, 5, 6}
    // };

    char input[100];
    int ** tab;

    printf("SudokuSolver3000\n");
    
    bool run = true;

    while(run){
        printf("\n1: Upload file \t2: Exit\n");
        scanf("%s", input);
        
        
        while(strcmp(input, "1") == 0){
            printf("Enter the name of your file: \n");
            
            scanf("%s", input);

            int table_menu =1;
            
            const char * filename = input;
            tab = get_tab(filename);

            if(tab[0][0] == 100 && tab[1][0] == 100){
                // printf("%d, %d\n", tab[0][0], tab[1][0]);
                // printf("aryaegdaeysabsd\n");
                table_menu =0;
                strcpy(input, "0");
                break;
            }

            else if(tab[0][0] != 100 && tab[1][0] != 100){
           
            

            int(*table)[9] = malloc(9 * sizeof(int[9]));

           

            if (table != NULL){
                //  printf("%d, %d\n", tab[0][0], tab[1][0]);
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        table[i][j] = tab[i][j];
                    }
                }
            }
            
           

            while(table_menu == 1){
                printf("1: see table\t 2: Solve table\t 3: Go back\n");
                scanf("%s", input);

                if(strcmp(input, "1") == 0){
                    print_table(table);
                }

                if(strcmp(input, "2") == 0){
                    solver(table);
                }

                if(strcmp(input, "3") == 0){
                    table_menu =0;
                    strcpy(input, "0");
                }
            }
           
            if (table_menu = 0){
                strcpy(input, "0");
                break;
            }
            }

        }
        
        if(strcmp(input, "1") ){
            if(strcmp(input, "2") == 0){
            run = false;
            break;
            }
            
            if(strcmp(input, "3") ){
                // printf("Invalid input. Please try again.\n");
                strcpy(input, "0");
            }

        }

        


    }

    


    // const char * filename = input;
    // int ** tab = get_tab(filename);

    

    // int(*table)[9] = malloc(9 * sizeof(int[9]));
    // if (table != NULL)
    // {
    //     for (int i = 0; i < 9; i++)
    //     {
    //         for (int j = 0; j < 9; j++)
    //         {
    //             table[i][j] = tab[i][j];
    //         }
    //     }
    // }


    

    
    //print_table(table);

    // int* p_to_empty_cell = find_empty_cell(table);
    
    // for (int i = 0; i < 2; i++){
    //     printf("%d ", p_to_empty_cell[i]);
    // }

    // free(p_to_empty_cell);

    // print_table(table);
    
    // solver(table);
    
    
    
    return 0;
}