#include<stdio.h>
#include<string.h>

int getDigitCount(int number) {
    int count=0;
    while(number!=0) {
        count++;
        number/=10;
    }
    return count;
}

void incrementMiddleMembers(int numberArr[], int n) {
    if(n%2==0) {
        numberArr[n/2 - 1]++;
    } 
    numberArr[n/2]++;
}

int joinNumberArr(int numberArr[], int digitCount) {
    int number=0;
    for(int i=0; i<digitCount; i++) {
        number = number*10 + numberArr[i];
    }
    return number;
}

void formPalindrome(int numberArr[5], int n) {
    for(int i=0; i<n/2; i++){
        numberArr[n-i-1] = numberArr[i];
    }
}

int getNextPalindrome(int number) {

    int temp = number, digitCount=getDigitCount(number);
    int numberArr[digitCount];

    for(int i=digitCount-1; i>=0 && temp!=0; i--) {
        numberArr[i] = temp%10;
        temp/=10;
    }

    formPalindrome(numberArr, digitCount);

    int palindromeNo = joinNumberArr(numberArr, digitCount);

    if(palindromeNo < number) {
        incrementMiddleMembers(numberArr, digitCount);
        palindromeNo = joinNumberArr(numberArr, digitCount); 
    }

    return palindromeNo;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Next Palindrome number = %d\n\n", getNextPalindrome(number));
}