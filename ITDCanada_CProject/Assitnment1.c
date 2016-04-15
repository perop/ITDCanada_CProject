//
//  Assitnment1.c
//  ITDCanada_CProject
//
//  Created by TakahashiMai on 2016-04-13.
//  Copyright © 2016 TakahashiMai. All rights reserved.
//

#include "Assitnment1.h"


enum col_name{

    ID,
    ATTENDANCE,
    QUIZE1,
    QUIZE2,
    MID_TERM,
    FINAL_TEST,
    FINAL_MARK  };


bool searchStudentId(int a[ROW_ASSIGNMENT][COL_ASSIGNMENT], int typedNum) {
    for (int i = 0; i < ROW_ASSIGNMENT; i++) {
        if (typedNum == a[i]) {
            return true;
        }
    }
    return false;
}
bool createTwoDimensionalArray(int a[ROW_ASSIGNMENT][COL_ASSIGNMENT], int id){
    
    size_t i, j;
    
    for (i = 0; i < ROW_ASSIGNMENT; i++) {
        if (id == a[i][0]) { //Duplication Check
            return false;
        }
        if (a[i][0] == 0) {
            for (j = 0 ; j < COL_ASSIGNMENT ; j++) {
                int mark;
                int sum = 0;
                switch (j) {
                    case ID:
                        mark = id;
                        break;
                        
                    case ATTENDANCE:
                        printf("Enter the mark for attendance from 0 to 10 for Student: %d\n", id);
                        scanf("%d", &mark);
                        if (mark == -1 || mark < 0 || mark >10) {
                            puts("Wrong Number!(from 0 to 10)");
                            j--;
                        }
                        break;
                    case QUIZE1:
                        printf("Enter the mark Quiz1 from 0 to 10 for Student: %d\n", id);
                        scanf("%d", &mark);
                        if (mark == -1 || mark < 0 || mark >10) {
                            puts("Wrong Number!(from 0 to 10)");
                            j--;
                        }
                        
                        break;
                        
                    case QUIZE2:
                        printf("Enter the mark Quiz2 from 0 to 10 for Student: %d\n", id);
                        scanf("%d", &mark);
                        if (mark == -1 || mark < 0 || mark >10) {
                            puts("Wrong Number!(from 0 to 10)");
                            j--;
                        }
                        
                        break;
                        
                    case MID_TERM:
                        printf("Enter the mark mid-term from 0 to 30 for Student: %d\n", id);
                        scanf("%d", &mark);
                        if (mark == -1 || mark < 0 || mark > 30) {
                            puts("Wrong Number!(from 0 to 30)");
                            j--;
                        }
                        break;
                        
                    case FINAL_TEST:
                        printf("Enter the mark mid-term from 0 to 40 for Student: %d\n", id);
                        scanf("%d", &mark);
                        if (mark == -1 || mark < 0 || mark > 40) {
                            puts("Wrong Number!(from 0 to 40)");
                            j--;
                        }
                        
                        break;
                        
                    case FINAL_MARK:
                        for (int x = 0; x < COL_ASSIGNMENT; x++) {
                            sum += a[i][j];
                        }
                        
                        break;
                        
                        
                    default:
                        break;
                }
                a[i][j] = mark;
                printf("a[%ld][%ld] = %d\n\n", i, j ,a[i][j]);
            }
            return true;
            
        }
    }
    return true;
}


void getStudentIds(int a[ROW_ASSIGNMENT]){
    
    size_t i;
    
    for (i =0; i < ROW_ASSIGNMENT; i++) {
        printf("Enter the Number from 100 to 999 for No.%ld StudentID\n", i);
        scanf("%d", &a[i]);
        if(100 > a[i] || a[i] >= 1000 || a[i] == -1){
            puts("Wrong Number!");
            i--;
        }
        
    }
    
}

int mainAssignment1(void){
    
    int studentIds[ROW_ASSIGNMENT] = {};
    int twoDim[ROW_ASSIGNMENT][COL_ASSIGNMENT] = {};
    size_t i, j;
    
    // Create and initialize one Dimentional array
    getStudentId(studentIds);
    
    // Find Students in one Dementional Array
    for (i = 0;i < ROW_ASSIGNMENT ;i++ ){
        int id;
        printf("Type student ID that you want to search for.\n");
        scanf("%d", &id);
        if (id != -1 && searchStudentId(studentIds, id)) {
            //int yesOrNo;
            puts("Found Student number in oneDimentionArray!!\n");
            //Initializing the two dimensional array
            
            if (createTwoDimensionalArray(twoDim, id)){
                printf("Succsess to make Student %d marks!\n", id);
                
            }else{
                puts("Fauled to make Student marks!");
                i--;
            }
        }else{
            puts("Wrong Number! or No result! Try it again!!");
            i--;
        }
    }
    
    //Printing
    //putStudentIds(studentIds, twoDim);
    
    for (i =0; i < ROW_ASSIGNMENT ; i++) {
        printf("Student Number is %03d\n", studentIds[i]);
    }
    
    for (i =0; i < ROW_ASSIGNMENT ; i++) {
        for (j = 0; j < COL_ASSIGNMENT ; j++) {
            if (j == COL_ASSIGNMENT -1) {
                printf("%3d\n", twoDim[i][j]);
            }else{
                printf("%3d", twoDim[i][j]);
            }
        }
    }
    return 0;
}

