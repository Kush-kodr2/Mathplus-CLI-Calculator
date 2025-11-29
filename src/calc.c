#include <stdio.h>
#include <math.h>
#include "operations.h"

// Global variable definitions
int day, month, year;
long long int_prev_value = 0;
float float_prev_value = 0.0;
int last_operation = 0;

// Helper function definition
void flushInput()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    int operation, ret_value, how_man_nums;
    int choice; // choice after first execution
    int add_ans, sub_ans, mul_ans, pow_ans;
    unsigned long long fac_ans;
    float avg_ans;
    int has_run_before = 0;
    int exit_program = 0;
    enum ResultType
    {
        NONE,
        INT_RESULT,
        FLOAT_RESULT
    };
    enum ResultType prev_type = NONE;
    fakeLoading1();
    welcomeScreen();

    while (!exit_program)
    {
        if (has_run_before)
        {
            while (1)
            {

                printf("\n What would you like to do next:- \n");
                printf("1. REDO Last Operation.\n");
                printf("2. Go back to Operations Menu.\n");
                printf("3. EXIT Program.\n");
                scanf("%d", &choice);
                flushInput();

                if (choice == 1)
                {
                    if (last_operation == 0)
                    {
                        printf("No previous operation to redo yet.\n");
                    }
                    else
                    {
                        printf("Repeating last operation:\n");

                        switch (last_operation)
                        {
                        case 1:
                            add_ans = addition(how_man_nums);
                            fakeLoading2();
                            printf("The RESULT is %d\n", add_ans);
                            int_prev_value = add_ans;
                            prev_type = INT_RESULT;
                            break;
                        case 2:

                            sub_ans = subtraction(how_man_nums);
                            fakeLoading2();
                            printf("The RESULT is %d\n", sub_ans);
                            int_prev_value = sub_ans;
                            prev_type = INT_RESULT;
                            break;
                        case 3:

                            mul_ans = multiplication(how_man_nums);
                            fakeLoading2();
                            printf("The RESULT is %d\n", mul_ans);
                            int_prev_value = mul_ans;
                            prev_type = INT_RESULT;
                            break;
                        case 4:
                        {
                            float div_ans = division();
                            fakeLoading2();
                            printf("The RESULT is %.2f\n", div_ans);
                            float_prev_value = div_ans;
                            prev_type = FLOAT_RESULT;
                        }
                        break;
                        case 5:
                            fac_ans = factorial();
                            fakeLoading2();
                            printf("The RESULT is %d\n", fac_ans);
                            int_prev_value = fac_ans;
                            prev_type = INT_RESULT;
                            break;
                        case 6:
                            avg_ans = average(how_man_nums);
                            fakeLoading2();
                            printf("The RESULT is %.2f\n", avg_ans);
                            float_prev_value = avg_ans;
                            prev_type = FLOAT_RESULT;
                            break;
                        case 7:
                            pow_ans = power();
                            fakeLoading2();
                            printf("The RESULT is %d\n", pow_ans);
                            int_prev_value = pow_ans;
                            prev_type = INT_RESULT;
                            break;
                        case 8:
                            prime_check();
                            prev_type = NONE;
                            break;
                        case 9:
                        {
                            int dig_sum_ans = digit_sum();
                            fakeLoading2();
                            printf("The RESULT is %d\n", dig_sum_ans);
                            int_prev_value = dig_sum_ans;
                            prev_type = INT_RESULT;
                        }
                        break;
                        case 10:
                            age_calc();
                            break;
                            prev_type = NONE;
                        case 11:
                            leap_yr_check();
                            break;
                            prev_type = NONE;
                        case 12:
                            QuadraticEqSolver();
                            break;
                            prev_type = NONE;

                        default:
                            printf("Unknown operation. Can't redo.\n");
                        }
                    }
                    continue;
                }

                else if (choice == 2)
                {
                    break;
                }
                else if (choice == 3)
                {
                    printf("Exiting Program...... \nThanks for using Kush's Calculator, Hope it had helped you....\n");
                    exit_program = 1;
                    break;
                }
                else
                {
                    printf("Invalid Input!");
                }
            }
            if (exit_program)
            {
                break;
            }
        }

        do
        {
            printf("=============================================================\n");
            printf("1. Addition \t\t2. Subtraction \t\t 3. Multiplication \n4. Division \t\t5. Factorial \t\t 6. Average \n7. Power \t\t8. Prime Number Checker  9. Digits Sum \n10. Age Calculator \t11. Leap Year Checker \t12. Quadratic Equation Solver (in progress) \t\n13. Show Previous Answer \n");
            printf("=============================================================\n");
            printf("Enter the number beside the operation to perform it (Enter 0 to exit program):- \n");
            ret_value = scanf("%d", &operation);
            if (ret_value != 1) // checks if input is int
            {
                printf("Invalid Input! Enter a valid number. \n");
            }
            else if (operation < 0 || operation > 13)
            {
                printf("Invalid Input! Please enter a valid number for given operations.\n");
            }

            flushInput();

            // Clears the scanf function after each loop to avoid scanf buffer issues

        } while (ret_value != 1 || operation < 0 || operation > 13);
        if (operation == 0)
        {
            printf("Exiting Program...... \nThanks for using Kush's Calculator, Hope it had helped you....\n");
            exit_program = 1;
            break;
        }

        else if (operation == 1)
        {
            printf("You have chosen ADDITION....\n");
            printf("HOW MANY numbers do you want to add:- \n");
            do
            {
                ret_value = scanf("%d", &how_man_nums);

                if (ret_value != 1)
                {
                    printf("Invalid Input, Enter a valid number.\n");
                    flushInput();
                }
                else if (how_man_nums < 2)
                {
                    printf("You must add at least two numbers. Try again.\n");
                }
            } while (ret_value != 1 || how_man_nums < 2);

            // last_operation = 1;
            add_ans = addition(how_man_nums);
            fakeLoading2();
            printf("The result is %d\n", add_ans);
            int_prev_value = add_ans;
            prev_type = INT_RESULT;
        }
        else if (operation == 2)
        {
            printf("You have chosen SUBTRACTION....\n");
            printf("HOW MANY numbers do you want to subtract:- \n");
            do
            {
                ret_value = scanf("%d", &how_man_nums);

                if (ret_value != 1)
                {
                    printf("Invalid Input, Enter a valid number.\n");
                    flushInput();
                }
                else if (how_man_nums < 2)
                {
                    printf("You must subtract at least two numbers. Try again.\n");
                }
            } while (ret_value != 1 || how_man_nums < 2);

            last_operation = 2;
            sub_ans = subtraction(how_man_nums);
            fakeLoading2();
            printf("The result is %d\n", sub_ans);
            int_prev_value = sub_ans;
            prev_type = INT_RESULT;
        }
        else if (operation == 3)
        {
            printf("You have chosen MULTIPLICATION....\n");
            printf("HOW MANY numbers do you want to multiply:- \n");
            do
            {
                ret_value = scanf("%d", &how_man_nums);

                if (ret_value != 1)
                {
                    printf("Invalid Input, Enter a valid number.\n");
                    flushInput();
                }
                else if (how_man_nums < 2)
                {
                    printf("You must multiply at least two numbers. Try again.\n");
                }
            } while (ret_value != 1 || how_man_nums < 2);

            last_operation = 3;
            mul_ans = multiplication(how_man_nums);
            fakeLoading2();
            printf("The result is %d\n", mul_ans);
            int_prev_value = mul_ans;
            prev_type = INT_RESULT;
        }
        else if (operation == 4)
        {
            printf("You have chosen DIVISION....\n");
            last_operation = 4;
            float div_ans = division();
            fakeLoading2();
            printf("The result is %.2f\n", div_ans);
            float_prev_value = div_ans;
            prev_type = FLOAT_RESULT;
        }
        else if (operation == 5)
        {
            printf("You have chosen FACTORIAL....\n");
            last_operation = 5;
            fac_ans = factorial();
            fakeLoading2();
            printf("The result is %d\n", fac_ans);
            int_prev_value = fac_ans;
            prev_type = INT_RESULT;
        }
        else if (operation == 6)
        {
            printf("You have chosen AVERAGE....\n");

            printf("HOW MANY numbers do you want to get average of:- \n");
            do
            {
                ret_value = scanf("%d", &how_man_nums);

                if (ret_value != 1)
                {
                    printf("Invalid Input, Enter a valid number.\n");
                    flushInput();
                }
                else if (how_man_nums < 2)
                {
                    printf("You must add at least two numbers. Try again.\n");
                }
            } while (ret_value != 1 || how_man_nums < 2);

            last_operation = 6;
            avg_ans = average(how_man_nums);
            fakeLoading2();
            printf("The result is %.2f\n", avg_ans);
            float_prev_value = avg_ans;
            prev_type = FLOAT_RESULT;
        }
        else if (operation == 7)
        {
            printf("You have chosen POWER....\n");

            last_operation = 7;
            pow_ans = power();
            fakeLoading2();
            printf("The result is %d\n", pow_ans);
            int_prev_value = pow_ans;
            prev_type = INT_RESULT;
        }

        else if (operation == 8)
        {
            printf("You have chosen PRIME NUM. CHECKER....\n");
            last_operation = 8;
            prime_check();
        }

        else if (operation == 9)
        {
            printf("You have chosen DIGITS SUM....\n");
            last_operation = 9;
            int dig_sum_ans = digit_sum();
            fakeLoading2();
            printf("The result is %d\n", dig_sum_ans);
            int_prev_value = dig_sum_ans;
            prev_type = INT_RESULT;
        }
        else if (operation == 10)
        {
            printf("You have chosen AGE CALCULATOR....\n");
            last_operation = 10;
            age_calc();
        }
        else if (operation == 11)
        {
            printf("You have chosen LEAP YEAR CHECKER....\n");
            last_operation = 11;
            leap_yr_check();
        }
        else if (operation == 12)
        {
            printf("You have chosen QUADRATIC EQUATION SOLVER....\n");
            last_operation = 12;
            QuadraticEqSolver();
        }

        else if (operation == 13)
        {
            if (!has_run_before)
            {
                printf("No previous result yet.\n");
            }

            else if (has_run_before && int_prev_value)
            {
                printf("Previous result: %d\n", int_prev_value);
            }
            else if (has_run_before && float_prev_value)
            {
                printf("Previous result: %.2f\n", float_prev_value);
            }
            else
            {
                printf("Previous result not available for that operation.\n");
            }

            // printf("The last result was %d. \n", prev_value);
        }
        else
        {
            printf("Invalid Input.");
        }
        has_run_before = 1;
    }

    return 0;
}
