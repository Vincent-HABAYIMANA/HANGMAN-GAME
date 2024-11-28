#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib> 
#include <ctime>  
#include <algorithm> 
#include <cctype>   

using namespace std;

int main() {
    
    list<string> wordList;wordList.push_back("doctor");
wordList.push_back("artist");
wordList.push_back("calculator");
wordList.push_back("science");
wordList.push_back("giraffe");
wordList.push_back("puzzle");
wordList.push_back("scientist");
wordList.push_back("architect");
wordList.push_back("university");
wordList.push_back("motorcycle");
wordList.push_back("headphones");
wordList.push_back("textbook");
wordList.push_back("suitcase");
wordList.push_back("vacation");
wordList.push_back("moonlight");
wordList.push_back("astronaut");
wordList.push_back("musician");
wordList.push_back("microscope");
wordList.push_back("journal");
wordList.push_back("spaceship");


    char playAgain;
    do {
        
        srand(static_cast<unsigned int>(time(0)));
        vector<string> wordVector(wordList.begin(), wordList.end());
        string word = wordVector[rand() % wordVector.size()];
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        string guessedWord(word.length(), '_'); 
        string incorrectGuesses = "";       
        int guessesLeft = word.length()+3;     

        cout << "\nWelcome to Hangman!";
        cout << "\nThe word has " << word.length() << " letters.\n";
        while (guessesLeft > 0) {
            cout << "\nWord: ";
            for (size_t i = 0; i < guessedWord.length(); ++i) {
                cout << guessedWord[i] << " ";
            }
            cout << "\nIncorrect Guesses: " << incorrectGuesses;
            cout << "\nGuesses Left: " << guessesLeft;

            char guess;
            cout << "\nGuess a letter: ";
            cin >> guess;
            if (!isalpha(guess)) {
                cout << "Invalid input! Please enter a letter.\n";
                continue;
            }

            guess = tolower(guess);
            if (guessedWord.find(guess) != string::npos || incorrectGuesses.find(guess) != string::npos) {
                cout << "You already guessed that letter! Try again.\n";
                continue;
            }
            bool correct = false;
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    guessedWord[i] = guess; 
                    correct = true;
                }
            }

            if (correct) {
                cout << "Good guess!\n";
            } else {
                cout << "Incorrect guess!\n";
                incorrectGuesses += guess; 
                guessesLeft--;
            }

            if (guessedWord == word) {
                cout << "Congratulations! You are winner of this game now🙏🙏🙏🙏🙏🙏🙏!";
                break;
            }
        }
        if (guessesLeft == 0) {
            cout << "\nGame over! You lost😥😥😥😥😥😥😥😥😥😥😥!! The word was \"" << word << "\".\n";
        }

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        playAgain = tolower(playAgain);

    } while (playAgain == 'y');
    cout<<"Thanks for join us!";

    return 0;
}
