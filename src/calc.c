#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>
int addition(int a);
int subtraction(int a);
long multiplication(int a);
float division();
unsigned long long factorial();
float average(int a);
long long power();
void prime_check();
int digit_sum();
void age_calc();
void leap_yr_check();
void QuadraticEqSolver();
void flushInput()
{
    while (getchar() != '\n')
        ;
}
// global variables
int day, month, year;
long long int_prev_value = 0;
float float_prev_value = 0.0;
int last_operation = 0;
void fetchCurrentDate()
{
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}
void welcomeScreen()
{
    fetchCurrentDate(); // sets curr_day, curr_month, curr_year

    printf("\n");
    printf("\t\t====================================\n");
    printf("\t\t||  Welcome to Kush's Calculator  ||\n");
    printf("\t\t====================================\n");
    printf("\t\t||    Today's Date: %02d/%02d/%04d    ||\n", day, month, year);
    printf("\t\t====================================\n");

    printf("Choose the operation you want to perform (Enter 0 to EXIT):-\n");
}

void fakeLoading1()
{
    printf("Loading Calculator");
    fflush(stdout);

    for (int i = 0; i < 3; i++)
    {
        Sleep(700);
        printf(".");
        fflush(stdout);
    }

    Sleep(500); // small pause before overwrite
    printf("\rCalculator Ready to Compute.      \n"); // \r returns to line start, extra spaces clear leftover dots
}
void fakeLoading2()
{
    printf("Calculating");
    for (int i = 0; i < 3; i++)
    {
        fflush(stdout);
        Sleep(300); // or use _sleep(1000) on Windows
        printf(".");
    }
    Sleep(200);
    printf("\r");
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

int addition(int how_num)
{
    int nums[how_num], sum = 0, ret_val;
    last_operation = 1;
    for (int i = 0; i < how_num; i++)
    {
        do
        {
            printf("Enter num%d:- ", i + 1);
            ret_val = scanf("%d", &nums[i]);
            if (ret_val != 1)
            {
                printf("Invalid Input! Enter valid numbers and try again.\n");
                flushInput();
            }

        } while (ret_val != 1);
        sum += nums[i];
    }
    return sum;
}
int subtraction(int how_num)
{
    int nums[how_num], sub, ret_val;
    for (int i = 0; i < how_num; i++)
    {
        do
        {
            printf("Enter num%d:- ", i + 1);
            ret_val = scanf("%d", &nums[i]);
            if (ret_val != 1)
            {
                printf("Invalid Input! Enter valid numbers and try again.\n");
                flushInput();
            }

        } while (ret_val != 1);
    }
    sub = nums[0];
    for (int i = 1; i < how_num; i++)
    {
        sub -= nums[i];
    }
    return sub;
    // printf("Work in progress, will be available soon");
}
long multiplication(int how_num)
{
    int nums[how_num], multi = 1, ret_val;
    for (int i = 0; i < how_num; i++)
    {
        do
        {
            printf("Enter num%d:- ", i + 1);
            ret_val = scanf("%d", &nums[i]);
            if (ret_val != 1)
            {
                printf("Invalid Input! Enter valid numbers and try again.\n");
                flushInput();
            }

        } while (ret_val != 1);
        multi *= nums[i];
    }

    return multi;
    // printf("Work in progress, will be available soon");
}
float division()
{
    int divident, ret_val;
    float divisor;

    do
    {
        printf("Enter the divident(number you want to divide):- ");
        ret_val = scanf("%d", &divident);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
    } while (ret_val != 1);

    do
    {
        printf("Enter the divisor(number you want to divide the prev number with):- ");
        ret_val = scanf("%f", &divisor);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
        if (divisor == 0)
        {
            printf("Divisor can't be zero. Try again.\n");
        }

    } while (ret_val != 1 || divisor == 0);

    return (divident / divisor);
    // printf("Work in progress, will be available soon");
}
unsigned long long factorial()
{
    int num, ret_val; // i will try to make fact as long in future
    unsigned long long fact = 1;
    do
    {
        printf("Enter the number:- ");
        ret_val = scanf("%d", &num);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
        if (num < 0)
        {
            printf("The factorial for negative numbers is not defined. Try Again.\n");
        }

    } while (ret_val != 1 || num < 0);
    for (int i = num; i > 0; i--)
    {
        fact *= i;
    }
    return fact;
    // printf("Work in progress, will be available soon");
}
float average(int how_man_nums)
{
    float avg;
    int sum = 0;
    int nums[how_man_nums], ret_val;
    for (int i = 0; i < how_man_nums; i++)
    {
        do
        {
            printf("Enter num%d:- ", i + 1);
            ret_val = scanf("%d", &nums[i]);
            if (ret_val != 1)
            {
                printf("Invalid Input! Enter valid numbers and try again.\n");
                flushInput();
            }

        } while (ret_val != 1);
        sum += nums[i];
    }
    avg = sum / how_man_nums;
    return avg;
    // printf("Work in progress, will be available soon");
}
long long power()
{

    int base, power, ret_val;

    do
    {
        printf("Enter the base number:- ");
        ret_val = scanf("%d", &base);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
    } while (ret_val != 1);

    do
    {
        printf("Enter the power:- ");
        ret_val = scanf("%d", &power);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }

    } while (ret_val != 1);

    return pow(base, power);
    // printf("Work in progress, will be available soon");
}

void prime_check()
{
    int num, is_prime = 1, ret_val;
    do
    {
        printf("Enter the number to check:- ");
        ret_val = scanf("%d", &num);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
    } while (ret_val != 1 || num < 0);

    fakeLoading2();
    if (num <= 1)
    {
        printf("%d is NOT a Prime number.", num);
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            is_prime = 0;
            break;
        }
    }

    if (is_prime)
    {
        printf("%d IS a Prime number.\n", num);
    }
    else
    {
        printf("%d is NOT a Prime number.\n", num);
    }

    // printf("Work in progress, will be available soon");
}

int digit_sum()
{
    int num, sum = 0, ret_val;
    do
    {
        printf("Enter the number to get its digit sum:- \n");
        ret_val = scanf("%d", &num);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
        if (num < 0)
        {
            printf("Please enter a non-negative number.\n");
        }

    } while (ret_val != 1 || num < 0);

    while (num != 0)
    {
        sum += num % 10; // get the last digit
        num /= 10;       // remove the last digit
    }

    return sum;

    // printf("Work in progress, will be available soon");
}
void age_calc()
{
    int bir_year, bir_month, bir_date, ret_val;
    fetchCurrentDate();
    int curr_year = year, curr_month = month, curr_date = day;
    int age_year, age_month, age_day;
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    do
    {
        printf("Enter your birth day date:- \n");
        ret_val = scanf("%d", &bir_date);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid day and try again.\n");
            flushInput();
        }
        if (bir_date < 1 || bir_date > 31)
        {
            printf("Please enter a valid date. Try again\n");
        }

    } while (ret_val != 1 || bir_date < 1 || bir_date > 31);

    do
    {
        printf("Enter your birth month:- \n");
        printf("1. January \t 2. February \t 3. March \n4. April \t 5. May \t 6. June \n7. July \t 8. August \t 9. September \n10. October \t 11. November \t 12. December\n");
        ;
        ret_val = scanf("%d", &bir_month);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid number and try again.\n");
            flushInput();
        }
        if (bir_month < 1 || bir_month > 12)
        {
            printf("Please enter a valid month. Try again.\n");
        }

    } while (ret_val != 1 || bir_month < 1 || bir_month > 12);

    do
    {
        printf("Enter your birth year:- \n");
        ret_val = scanf("%d", &bir_year);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
        if (bir_year < 1)
        {
            printf("Please enter a non-negative number.\n");
        }

    } while (ret_val != 1 || bir_year < 0);

    fakeLoading2();
    // leap year
    if (bir_year % 4 == 0 && bir_year % 100 != 0 || bir_year % 400 == 0)
    {
        month_days[2] = 29;
    }

    if (curr_month < bir_month)
    {
        age_year = curr_year - bir_year - 1;
        age_month = bir_month - curr_month;
    }
    else if (curr_month > bir_month)
    {
        age_year = curr_year - bir_year;
        age_month = curr_month - bir_month;
    }
    else if (curr_month == bir_month)
    {
        age_year = curr_year - bir_year;
        age_month = 0;
    }

    if (curr_date >= bir_date)
    {
        age_day = curr_date - bir_date;
    }
    else if (curr_date < bir_date)
    {
        // age_day = 30 - bir_date + curr_date;
        age_day = month_days[bir_month] - bir_date + curr_date;
        age_month -= 1;
    }

    printf("Your age is %d years %d months and %d days.", age_year, age_month, age_day);

    // printf("Work in progress, will be available soon\n");
}
void leap_yr_check()
{
    fetchCurrentDate();
    int bir_year, ret_val;
    do
    {
        printf("Enter the year to check:- \n");
        ret_val = scanf("%d", &bir_year);
        if (ret_val != 1)
        {
            printf("Invalid Input! Enter valid numbers and try again.\n");
            flushInput();
        }
        if (bir_year < 1)
        {
            printf("Please enter a non-negative number.\n");
        }

    } while (ret_val != 1 || bir_year < 0);

    fakeLoading2();
    // Main Logic
    if (bir_year > year)
    {
        if ((bir_year % 4 == 0 && bir_year % 100 != 0) || (bir_year % 400 == 0))
        {
            printf("%d will be a LEAP YEAR.\n", bir_year);
        }
        else
        {
            printf("%d won't be a LEAP YEAR.\n", bir_year);
        }
    }
    else if (bir_year == year)
    {
        if ((bir_year % 4 == 0 && bir_year % 100 != 0) || (bir_year % 400 == 0))
        {
            printf("%d is a LEAP YEAR.\n", bir_year);
        }
        else
        {
            printf("%d is NOT a LEAP YEAR.\n", bir_year);
        }
    }
    else
    {
        if ((bir_year % 4 == 0 && bir_year % 100 != 0) || (bir_year % 400 == 0))
        {
            printf("%d was a LEAP YEAR.\n", bir_year);
        }
        else
        {
            printf("%d wasn't a LEAP YEAR.\n", bir_year);
        }
    }
}
void QuadraticEqSolver()
{
    printf("Work in progress, full version will be available soon...\n");
    int a, b, c;
    printf("Enter the values of a,b and c:- ");
    printf("a :- ");
    scanf("%d", &a);
    printf("b :- ");
    scanf("%d", &b);
    printf("c :- ");
    scanf("%d", &c);

    double root1, root2, discriminant;

    discriminant = (b * b) - (4 * a * c);

    if (discriminant >= 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        if (root1 == root2)
        {
            printf("The roots are real and equal...\n");
        }
        else
        {
            printf("The roots are real and unique...\n");
        }
        printf("x = %f \n", root1);
        printf("x = %f \n", root2);
    }
    else
    {
        double real_part = -b / 2 * a;
        double imaginary_part = sqrt(abs(discriminant)) / 2 * a;

        printf("The roots are complex and unique...\n");

        printf("x =  %f +  %f i\n", real_part, imaginary_part);
        printf("x = %f - %f i\n", real_part, imaginary_part);
    }
}
