#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
   srand(time(NULL));

   cout << "Welcome to Home Cricket!\n";
   cout << "+++++++++++++++++++++++++\n";

   char player_call;
   int player_choice;
   int computer_choice = rand() % 2;

   cout << "Toss time!\n";
   cout << "Call Heads(H) or Tails(T): ";
   cin >> player_call;

   if (player_call != 'H' && player_call != 'T') {
      cout << "Invalid Call. Please enter H or T.\n";
      return 0;
   }

   cout << "You called " << player_call << ". ";

   int toss_result = rand() % 2;

   if (toss_result == 0) {
      cout << "It's Heads.\n";
   } else {
      cout << "It's Tails.\n";
   }

   if ((player_call == 'H' && toss_result == 0) || (player_call == 'T' && toss_result == 1)) {
      cout << "You won the toss!\n";
      cout << "Choose 1 to Bat or 2 to Bowl: ";
      cin >> player_choice;

      if (player_choice != 1 && player_choice != 2) {
         cout << "Invalid Choice. Please enter 1 or 2.\n";
         return 0;
      }

      if (player_choice == 1) {
         cout << "You chose to Bat first!\n";
      } else {
         cout << "You chose to Bowl first!\n";
      }
   } else {
      cout << "Computer won the toss!\n";
      cout << "Computer chose to ";

      if (computer_choice == 0) {
         cout << "Bat first!\n";
      } else {
         cout << "Bowl first!\n";
      }
   }

   cout << "Let's start the match!\n";

   cout << "First Innings!\n";
   cout << "You are the batting team. Score as many runs as you can.\n";

   int player_run = 0;
   int player_wickets = 10;
   int balls_left = 60;

   while (player_wickets > 0 && balls_left > 0) {
      int player_input;

      cout << "Enter your run from 1 to 6: ";
      cin >> player_input;

      if (player_input < 1 || player_input > 6) {
         cout << "Invalid run. Please enter a number from 1 to 6.\n";
         continue;
      }

      int computer_input = rand() % 6 + 1;
      cout << "Computer run: " << computer_input << '\n';

      if (player_input == computer_input) {
         cout << "You're out!\n";
         player_wickets--;
      } else {
         player_run += player_input;
      }
      balls_left--;

      cout << "Your total run: " << player_run << " (" << player_wickets << " wickets left, " << balls_left << " balls left)\n";
   }
   
   cout << "First Innings Score: " << player_run << " for " << 10 - player_wickets << " wickets\n";

   int target = player_run + 1;

   cout << "Match Target is: " << target << '\n';

   cout << "Second Innings!\n";
   cout << "You are the bowling team. Try to stop the computer from reaching the target.\n";
   
   int computer_run = 0;
   int computer_wickets = 10;
   balls_left = 60;

   while (computer_wickets > 0 && balls_left > 0 && computer_run < target) {
      int player_input;

      cout << "Enter your run from 1 to 6: ";
      cin >> player_input;

      if (player_input < 1 || player_input > 6) {
         cout << "Invalid run. Please enter a number from 1 to 6.\n";
         continue;
      }

      int computer_input = rand() % 6 + 1;
      cout << "Computer run: " << computer_input << '\n';

      if (player_input == computer_input) {
         cout << "Computer is out!\n";
         computer_wickets--;
      } else {
         computer_run += computer_input;
      }
      balls_left--;

      cout << "Computer total run: " << computer_run << " for " << 10 - computer_wickets << " wickets (" << balls_left << " balls left)\n";
   }

   cout << "Match Result: ";
   
   if (computer_wickets == 0) {
      cout << "Congratulations! You win by " << player_run - computer_run << " runs!\n";
   } else if (computer_run >= target) {
      cout << "Computer Wins!\n";
   } else if (balls_left == 0) {
      cout << "All balls finished! Computer couldn't reach the target.\n";
   } else {
      cout << "It's a Draw!\n";
   }

   cout << "Thanks for playing Home Cricket!\n";
   
   return 0;
}
