#include <stdio.h>
#include <stdlib.h>


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

    // int tab[9][9] = {
    //     {7, 0, 0, 0, 0, 0, 3, 0, 0},
    //     {0, 0, 5, 0, 0, 9, 2, 0, 1},
    //     {0, 9, 0, 4, 0, 0, 0, 0, 0},
    //     {0, 0, 2, 0, 0, 4, 9, 0, 5},
    //     {6, 0, 0, 0, 7, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 8, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 3, 0},
    //     {2, 0, 0, 6, 0, 0, 1, 0, 8},
    //     {0, 0, 8, 0, 0, 0, 0, 4, 0}
    // };

    int tab[9][9] = {
        {9, 1, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 7, 9, 6, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 6, 4, 3, 0, 9, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 4, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 5, 0, 0},
        {8, 0, 0, 5, 4, 0, 0, 3, 0}
    };

    int(*table)[9] = malloc(9 * sizeof(int[9]));
    if (table != NULL)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                table[i][j] = tab[i][j];
            }
        }
    }

    int solution [9][9] = {
    {9, 7, 3, 2, 5, 8, 4, 6, 1},
    {2, 1, 4, 9, 3, 6, 7, 8, 5},
    {6, 5, 8, 7, 1, 4, 3, 9, 2},
    {8, 6, 9, 5, 4, 1, 2, 3, 7},
    {7, 3, 1, 6, 2, 9, 5, 4, 8},
    {5, 4, 2, 8, 7, 3, 6, 1, 9},
    {1, 9, 5, 3, 6, 7, 8, 2, 4},
    {4, 2, 6, 1, 8, 5, 9, 7, 3},
    {3, 8, 7, 4, 9, 2, 1, 5, 6}
    };
    
    //printf("%d ", 8/3);


    //print_table(table);

    int* p_to_empty_cell = find_empty_cell(table);
    
    
    for (int i = 0; i < 2; i++){
        printf("%d ", p_to_empty_cell[i]);
    }

    free(p_to_empty_cell);
    
    solver(table);
    
    
    
    return 0;
}