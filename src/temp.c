#include <stdio.h>

 #include <stdio.h>
#include <windows.h> // for Sleep on Windows

void fakeLoading()
{
    printf("Initializing");
    fflush(stdout);

    for (int i = 0; i < 3; i++)
    {
        Sleep(1000);
        printf(".");
        fflush(stdout);
    }

    Sleep(500); // small pause before overwrite
    printf("\rInitialized     \n"); // \r returns to line start, extra spaces clear leftover dots
}
void fakeLoading2()
{
    printf("Calculating");
    for (int i = 0; i < 3; i++)
    {
        fflush(stdout);
        Sleep(400); // or use _sleep(1000) on Windows
        printf(".");
    }
    Sleep(500);
    printf("\r");
}
 int main(){
    printf("Enter your birth month:- \n");
        printf(" 1. January \t 2. February \t 3. March \n 4. April \t 5. May \t 6. June \n 7. July \t 8. August \t 9. September \n10. October \t 11. November \t 12. Desember\n");;
    printf("1. Addition \t\t2. Subtraction \t\t 3. Multiplication \n4. Division \t\t5. Factorial \t\t 6. Average \n7. Power \t\t8. Prime Number Checker  9. Digits Sum \n10. Age Calculator \t11. Leap Year Checker \t 12. Show Previous Answer \n");
            printf("Enter the number beside the operation to perform it:- \n");
    fakeLoading2();
    printf("THe answer is 34");
     return 0;
}