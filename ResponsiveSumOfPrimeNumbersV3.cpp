#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
using namespace std;
int main()
{
    int iGivenNum, iCounter = 1, iBuffer = 0, iSum = 0, iPrimeNumberCnt = 0, iRowSum = 0, iPageNumber = 1, iYCord = 12, iXCord = 58, iXCordBuffer = 35, iYCordBuffer=28, iHeight=39, iWidth=15;
    _getch();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Requesting to OS 
    CONSOLE_SCREEN_BUFFER_INFO BufInfo;
    SMALL_RECT srctWindow;
    cout << "                                   *****Welcome to my Program*****";
    cout << "\n                        This Program Prints the sum of first n Prime Numbers";
    cout << "\n                          Before we start, let's see what are Prime Numbers?";
    cout << "\n            Prime numbers are the positive integers having only two factors, 1 and the integer itself.";
    cout << "\n\n Let's look at an example ";
    cout << " \n Consider a Integer : 5 \n";
    cout << " Factors of 5 : 1,5 \n Hence it is a prime number \n";
    cout << "\n Let's look at another example \n";
    cout << " Consider a Integer : 6 \n";
    cout << " Factors of 6 : 1,2,3 \n Hence it is not a prime number. Also called as composite number. ";
    cout << "\n Hence Smallest Prime Number is 2.\n";
    cout << " Till How many prime numbers you want to find it's sum ? : "; // Needs to be modified
    cin >> iGivenNum;
    system("cls");
    cout << "\n\nPage Number : 1\n\n\n\n\n\n";
    cout << "\n                                  Prime Numbers         Row Total\n\n\n";
    for (int iNumCnt = 2; iNumCnt > 0; iNumCnt++) // Always true loop

    {
        if (!GetConsoleScreenBufferInfo(hConsole, &BufInfo))
        {
            cout << "GetConsoleScreenBufferInfo failed  " << GetLastError();
            return 1;
        }
        srctWindow = BufInfo.srWindow;
        if ((srctWindow.Right - srctWindow.Left) > 70 || (srctWindow.Bottom - srctWindow.Top) > 25)
        {
            int iflag = 0;
            for (int iDivisorCnt = 2; iDivisorCnt < (iNumCnt / 2); iDivisorCnt++)        // Checking whether prime or not
            {
                if ((iNumCnt % iDivisorCnt) == 0)             // Not a prime number
                {
                    iflag = 1;
                    break;
                }

            }
            if (iflag == 0 && !(iGivenNum == iBuffer))                     // Prime Number
            {
                iSum = iSum + iNumCnt;
                iRowSum = iRowSum + iNumCnt;

                if (iCounter == 1)
                {
                    cout << "                                   " << iNumCnt;
                    
                }
                else if (iCounter >= 2 && iCounter <= 4)
                {

                    cout << "+" << iNumCnt;
                    

                }
                else if (iCounter == 5)
                {

                    cout << "+" << iNumCnt;
                    COORD coordScreen = { 58, iYCord }; // home for the cursor
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                    if (hConsole == INVALID_HANDLE_VALUE)
                    {
                        cout << "GetStdHandle failed with \n" << GetLastError();
                        return 1;
                    }
                    SetConsoleCursorPosition(hConsole, coordScreen);

                    cout << setw(9) << iRowSum << endl << endl;
                    iCounter = 0;
                    iRowSum = 0;
                    iYCord = iYCord + 2;
                    


                }
                iBuffer++;
                iCounter++;
                iPrimeNumberCnt++;
            }

            if (iPrimeNumberCnt == 25)
            {
                cout << "\n\n                                          Grand Total --> " << setw(9) << iSum << endl;
                iYCord = iYCord + 17;
                iPrimeNumberCnt = 0;
                cout << "\nPress any key to continue...\n\n";
                _getch();
                iPageNumber++;
                if (!GetConsoleScreenBufferInfo(hConsole, &BufInfo))
                {
                    cout << "GetConsoleScreenBufferInfo failed  " << GetLastError();
                    return 1;
                }
                srctWindow = BufInfo.srWindow;

                if ((srctWindow.Right - srctWindow.Left) > 70 || (srctWindow.Bottom - srctWindow.Top) > 25)
                {
                    cout << "\nPage Number : " << iPageNumber << "\n\n\n";
                    cout << "\n                                            Opening Total : " << iSum;
                    cout << "\n\n\n                                  Prime Numbers                Row Total\n\n\n";
                }
                else if ((srctWindow.Right - srctWindow.Left) < 70 || (srctWindow.Bottom - srctWindow.Top) < 25)
                {
                    COORD coordScreen = { iXCordBuffer , iYCordBuffer }; // home for the cursor
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                    if (hConsole == INVALID_HANDLE_VALUE)
                    {
                        cout << "GetStdHandle failed with \n" << GetLastError();
                        return 1;
                    }
                    SetConsoleCursorPosition(hConsole, coordScreen);

                    cout << "\n  Page Number : " << iPageNumber << "\n\n\n";
                    cout << "\n    Opening Total : " << iSum;
                    cout << "\n\n\n            Prime Numbers            Row Total\n\n\n";
                }



            }
            else if (iGivenNum == iBuffer)         // Printing Sum                              
            {
                cout << "\n\n                                          Grand Total --> " << setw(9) << iSum << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "\n";
                }
                break;
            }
        }

        srctWindow = BufInfo.srWindow;
        if (!GetConsoleScreenBufferInfo(hConsole, &BufInfo))
        {
            cout << "GetConsoleScreenBufferInfo failed  " << GetLastError();
            return 1;
        }
        else if ((srctWindow.Right - srctWindow.Left) < 70 || (srctWindow.Bottom - srctWindow.Top) < 25)
        {

            if (!GetConsoleScreenBufferInfo(hConsole, &BufInfo))
            {
                cout << "GetConsoleScreenBufferInfo failed  " << GetLastError();
                return 1;
            }
            srctWindow = BufInfo.srWindow;            
            if (hConsole == INVALID_HANDLE_VALUE)
            {
                cout << "GetStdHandle failed with \n" << GetLastError();
                return 1;
            }
            int iflag = 0;
            for (int iDivisorCnt = 2; iDivisorCnt < (iNumCnt / 2); iDivisorCnt++)        // Checking whether prime or not
            {
                if ((iNumCnt % iDivisorCnt) == 0)             // Not a prime number
                {
                    iflag = 1;
                    break;
                }

            }
            if (iflag == 0 && !(iGivenNum == iBuffer))                     // Prime Number
            {
                iSum = iSum + iNumCnt;
                iRowSum = iRowSum + iNumCnt;

                if (iCounter == 1)
                {
                    iYCordBuffer = iYCordBuffer + 11;
                    COORD coordScreen = { iWidth, iHeight }; // home for the cursor
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleCursorPosition(hConsole, coordScreen);
                    cout << "Hello";
                    cout << "1" << iNumCnt;
                    iXCord = iXCord + 1;
                }
                else if (iCounter >= 2 && iCounter <= 4)
                {
                    
                    cout << "+" << iNumCnt;
                    //iXCord = iXCord + 2;

                }
                else if (iCounter == 5)
                {
                   
                    cout << "+" << iNumCnt;
                    COORD coordScreen = { iXCord, iYCord }; // home for the cursor
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                    if (hConsole == INVALID_HANDLE_VALUE)
                    {
                        cout << "GetStdHandle failed with \n" << GetLastError();
                        return 1;
                    }
                    //SetConsoleCursorPosition(hConsole, coordScreen);
                    cout << setw(9) << iRowSum << endl << endl;
                    iCounter = 0;
                    iRowSum = 0;
                    iYCord = iYCord + 2;


                }
                iBuffer++;
                iCounter++;
                iPrimeNumberCnt++;
            }

            if (iPrimeNumberCnt == 25)
            {
                cout << "\n\n                                          Grand Total --> " << setw(9) << iSum << endl;
                iYCord = iYCord + 17;
                iPrimeNumberCnt = 0;
                cout << "\nPress any key to continue...\n\n";
                _getch();
                iPageNumber++;
                if (!GetConsoleScreenBufferInfo(hConsole, &BufInfo))
                {
                    cout << "GetConsoleScreenBufferInfo failed  " << GetLastError();
                    return 1;
                }
                srctWindow = BufInfo.srWindow;
                if ((srctWindow.Right - srctWindow.Left) > 70 || (srctWindow.Bottom - srctWindow.Top) > 25)
                {
                    cout << "\nPage Number : " << iPageNumber << "\n\n\n";
                    cout << "\n                                            Opening Total : " << iSum;
                    cout << "\n\n\n                                  Prime Numbers                Row Total\n\n\n";
                }
                else if ((srctWindow.Right - srctWindow.Left) < 70 || (srctWindow.Bottom - srctWindow.Top) < 25)
                {
                    COORD coordScreen = { 30 , iYCordBuffer }; // home for the cursor
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                    if (hConsole == INVALID_HANDLE_VALUE)
                    {
                        cout << "GetStdHandle failed with \n" << GetLastError();
                        return 1;
                    }
                    SetConsoleCursorPosition(hConsole, coordScreen);

                    cout << "\n          Page Number : " << iPageNumber << "\n\n\n";
                    cout << "\n    Opening Total : " << iSum;
                    cout << "\n\n\n            Prime Numbers            Row Total\n\n\n";
                }


            }
            else if (iGivenNum == iBuffer)         // Printing Sum                              
            {
                cout << "\n\n                                          Grand Total --> " << setw(9) << iSum << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "\n";
                }
                break;
            }
        }





    }
}
