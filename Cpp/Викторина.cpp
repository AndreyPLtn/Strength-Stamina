#include <iostream>
#include <string>

using namespace std;
//Игра(программа)-викторина
int main() {
//Определяем переменные и типы данных
	string name;
    char ans1, ans2, ans3, ans4;
    int score = 0;
	cout << "Enter ur name: ";
	getline(cin, name);
	//Вопрос 1
	cout << "1) Congratulations, you have been successfully logged in.";
	cout << "Who developed the welding machine and when?\n";
	cout << "\n a) Henry Loid\n b) Howard Birmengen\n c) Henry Howard\n\n";
	
	cout << "Enter the right answer (a/b/c): ";
	cin >> ans1;
	if (ans1 == 'c') {
		cout << "Well done, choice is correct!\n";
		score++;
	} else {
		cout << "Try again, answer is incorrect\n";
	}
    cout << endl;

    // Вопрос 2
    cout << "2) -Why are the birches making such a ______ in Russia?-\n" << endl << "Enter a word so that the sentence is correct in meaning\n";
    cout << " a) buzz\n b) noise\n c) drinking\n\n";
    //Drinking - its means БУХТЕТЬ;
    cout << "Enter your answer (a/b/c): ";
    cin >> ans2;
    if (ans2 == 'b') {
        cout << "Well done, choice is correct!\n";
        score++;
    }
    else {
        cout << "Try again, answer is incorrect\n";
    }
    cout << endl;

    //Вопрос 3
    cout << "3)Who was Balda in the Russian folk tale?\n";
    cout << " a) slave\n b) sole trader\n c) worker\n\n";
    cout << "Enter the right answer (a/b/c): ";
    cin >> ans3;
    if (ans3 == 'c') {
        cout << "Well done, choice is correct!\n";
        score++;
    }
    else {
        cout << "Try again, answer is incorrect\n";
    }
    //Вопрос 4
    cout << "3)Who was the Great Wall of China built to fight against?\n";
    cout << " a) Mongols\n b) Udmurts\n c) Yakuts\n d) Nanaits \n\n";
    cout << "Enter the right answer (a/b/c/d): ";
    cin >> ans4;
    if (ans4 == 'a') {
        cout << "Well done, choice is correct!\n";
        score++;
    }
    else {
        cout << "Try again, answer is incorrect\n";
    }
// Показывает результат викторины
    cout << "Congratulations, " << name << "! You scored " << score << " out of 4.\n";
    if (score == 4) {
        cout << "Ultramind Pro max!\n";
    }
    else if (score == 3) {
        cout << "Ultramind Pro!\n";
    }
    else if (score == 2) {
        cout << "Ultramind!\n\n";
    }
    else {
        cout << "\nGG WP\n";
    }
    return 0;
}
    
