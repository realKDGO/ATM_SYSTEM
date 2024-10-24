//ATM SYSTEM NI KD :>
//I use double instead of float because double is more precise than float.
//Last Edited Oct 24, 2024
//Added some Error Trapping to prevent crashing. ^_^
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

 //No Starting Balance
 double balance;// = 10000.00; //With starting balance.
 int Pin = 7878; //Pin before showing the menu.

 //Function to check pin.
 int checkPin() {
  int pin, attempts = 0;
  clrscr();

  //Function to allow user to enter pin for 3 attempts.
  while(attempts < 3) {
   printf("Enter your 4-digit pin: ");
   scanf("%d",&pin);
   clrscr();

  if(pin == Pin) {
   return 1;//Pin is correct.
} else {
   printf("Incorrect Pin. Try again.\n");
   attempts++;
  }
 }
 return 0;
}

 void Menu() {
  printf("\n*=====ATM MENU=====*\n");
  printf("1. Deposit Money\n");
  printf("2. Withdraw Money\n");
  printf("3. Check Balance\n");
  printf("4. Exit\n");
  printf("*==================*\n");
  printf("Choose an option: ");
}

 //Function to deposit money.
 void deposit() {
  double deposit;
  clrscr();

  printf("Enter amount to deposit: ");
  scanf("%lf",&deposit);


  if(deposit <= 0) {
   printf("Error: Invalid deposit amount!\n");
} else {
   balance += deposit;
   printf("\nSuccessful deposit!\nPhp%.2f is your new balance.\n",balance);
  }
}

 //Function to withdraw money.
 void withdraw() {
  double withdraw;
  clrscr();

  printf("Enter amount to withdraw: ");
  scanf("%lf",&withdraw);

  if(withdraw <= 0) {
   printf("Error: Invalid amount to withdraw! Try again.\n");
} else if(withdraw > balance) {
   printf("Insufficient balance!\n");
} else {
   balance -= withdraw;
   printf("\nThe withdrawal was successful!\nPhp%.2f is your new balance.\n",balance);
  }
}

 //Function to check balance.
 void checkBalance() {
  clrscr();
  printf("\nPhp%.2f is your current balance.\n",balance);
}
//Start of Error Trapping.
//Function to Clear Input Buffer. (Error Trapping.)
void clrIB() {
 char ch;
 //Read and discard characters from the buffer until a newline or EOF is encountered.
 while((ch = getchar()) != '\n' && ch != EOF);
}

 //Main
 int main() {
  int option;
  clrscr();

 //Verify the menu before accessing menu.
 if(checkPin() == 0) {
  //This function is incorrect attempts. Program will exit after 3 incorrect attempts.
  printf("Too many incorrect attempts. System exiting...\n");
  return 0;
}

 do{
  Menu();
  //Checks if the user input is a valid integer. If it's not the condition is true, and the error handling code is executed.
  if(scanf("%d",&option) != 1) {
  clrscr();
  printf("Error: Invalid Input! Letters, Strings, & Special Characters Are Not Allowed.");
  clrIB();//Calling the function. Clears the invalid input from the buffer.
  continue;//Skips to the next iteration, Re-displaying the menu.
  //End of Error Trapping.
}

  switch(option) {
   case 1:
    deposit();
    break;
   case 2:
    withdraw();
    break;
   case 3:
    checkBalance();
    break;
   case 4:
    printf("Thank You! Goodbye.");
    sleep(2);
    printf("\nProgram Exiting...");
    sleep(1);
    break;
   default:
    clrscr();
    printf("Error: Invalid option! Please Choose Between (1, 2, 3, & 4).");
  }
} while(option != 4);

 return 0;
}
