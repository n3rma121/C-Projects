#include <iostream>
#include <random>

char getUserChoice();
void chooseWinner(char player, char computer);
char computerChoice();
void showChoice(char choice);
void playAgain();

int main(){
    
   char player;
   char computer;

   std::cout << "**********************************\n";
   std::cout << "Welcome to Rock Paper Scissor Game\n";
   std::cout << "**********************************\n";
   
   player = getUserChoice();
   std::cout << "You choose: ";
   showChoice(player); 

    computer = computerChoice();
    std::cout << "Computer's choice: ";
    showChoice(computer);

    chooseWinner(player, computer);

    playAgain();  
}

char getUserChoice(){

    char player;

    do
    {
        std::cout << "Choose one of the following \n";
        std::cout << "'r' for rock\n";
        std::cout <<"'p' for paper\n";
        std::cout << "'s' for scissor\n";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

void showChoice(char choice){
    switch (choice)
    {
    case 'r':
        std::cout << "Rock\n";
        break;
    
    case 'p': 
        std::cout << "Paper\n";
        break;

    case 's':
        std::cout << "Scissors\n";
        break;

    default:
        std::cout << "Invalid choice!";
        break;
    }
}

char computerChoice(){
    std::mt19937 mt{ std:: random_device{}()};
    
    std::uniform_int_distribution<int> choice{1,3};

    int computer = choice(mt);

    switch (computer)
    {
    case 1:
        return 'r';
    
    case 2:
        return 'p';
    
    case 3:
        return 's';

     default:
        return 0;
    }
   
}


void chooseWinner(char player, char computer){

    switch (player)
    {
    case 'r' :  if(computer == 'r'){
                    std::cout << "It's a tie!\n";
                }else if(computer == 'p'){
                    std::cout << "You lose!\n";
                }else{
                    std::cout << "You win!\n";
                }
        break;
        case 'p' :  if(computer == 'p'){
                    std::cout << "It's a tie!\n";
                }else if(computer == 's'){
                    std::cout << "You lose!\n";
                }else{
                    std::cout << "You win!\n";
                }
        break;
        case 's' :  if(computer == 's'){
                    std::cout << "It's a tie!\n";
                }else if(computer == 'r'){
                    std::cout << "You lose!\n";
                }else{
                    std::cout << "You win!\n";
                }
        break;
    
    default:
        break;
    }
}


void playAgain(){

    char play;

    std::cout << "Enter 'y' to play again and 'n' to exit: \n";
    std::cin >> play;
    
    if(play == 'n'){
        std::cout << "Thanks for playing the game.";
        exit(1);
    }else   
        main();
}

