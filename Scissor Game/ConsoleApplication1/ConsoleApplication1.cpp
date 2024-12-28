#include <iostream>
using namespace std;

enum enTools { Stone = 1, Paper = 2, Scissor = 3 };

struct stWinCounter {
	short ComputerWinTimes = 0, PlayerWinTimes = 0, Draw = 0;
};

int ReadPositiveNumber(string Message) {
	int Number;
	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);
	return Number;

}

int ReadNumberInRange(string Message) {

	int Number;
	do
	{
		cout << Message;
		cin >> Number;

	} while (Number < 1 || Number > 3);
	return Number;

}

int RandomNumber(int From, int To) {

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short MachineChoice() {

	short Computer = RandomNumber(1, 3);
	return Computer;
	
}

short PlayerChoice() {

	short Choice;

	//cout << "Your choice [1]: Stone, [2]: Paper, [3]: Scissor? " << endl;
	//cin >> Choice;
	Choice = ReadNumberInRange("Your choice [1]: Stone, [2]: Paper, [3]: Scissor? ");

	return Choice;
}

string WhoWon(short ComputerChoice, short MyChoice) {

	if (ComputerChoice == MyChoice)
	{
		return "No Winner";
	}
	else if (ComputerChoice == 1 && MyChoice == 2 || ComputerChoice == 2 && MyChoice == 3 || ComputerChoice == 3 && MyChoice == 1)
	{
		return "Player";
	}
	else if (!(ComputerChoice == 1 && MyChoice == 2) || !(ComputerChoice == 2 && MyChoice == 3) || !(ComputerChoice == 3 && MyChoice == 1))
	{
		return "Computer";
	}
}

string ChoiceType(int Number) {

	switch (Number)
	{
	case 1:
		return "Stone";
		break;
	case 2:
		return "Paper";
		break;
	case 3:
		return "Scissor";
		break;
	default:
		return " ";
		break;
	}
}

void CurrentResult(short RoundNumber, short ComputerChoice, short MyChoice, stWinCounter& WinTimes){

	string WinningResult = WhoWon(ComputerChoice, MyChoice);

	if (WinningResult == "Computer") {
		cout << "\a";
		system("color 4F"); // red
		WinTimes.ComputerWinTimes++;
	}
	else if (WinningResult == "Player")
	{
		system("color 2F"); // Green
		WinTimes.PlayerWinTimes++;
	}
	else if (WinningResult == "No Winner") {
		system("color 6F"); // YEllow
		WinTimes.Draw++;
	}

	cout << "----------- Round [" << RoundNumber << "] -----------\n";
	cout << "Player Choice : " << ChoiceType(MyChoice) << endl;
	cout << "Computer Choice : " << ChoiceType(ComputerChoice) << endl;
	cout << "Round Winner : [" << WinningResult << "]" << endl;
	cout << "----------------------------------------------" << endl;

}

void StartGame(short RoundsNumber, stWinCounter& WinTimes) {

	for (short RoundNumber = 1; RoundNumber <= RoundsNumber; RoundNumber++)
	{
		cout << "\nRound [" << RoundNumber << "] begins:" << endl;
		short ComputerChoice = MachineChoice();
		short MyChoice = PlayerChoice();
		CurrentResult(RoundNumber, ComputerChoice, MyChoice, WinTimes);
	}

}

string FinalWinner(stWinCounter WinTimes) {

	if (WinTimes.ComputerWinTimes < WinTimes.PlayerWinTimes)
	{
		return "Player";
	}
	else if (WinTimes.ComputerWinTimes > WinTimes.PlayerWinTimes) {
		return "Computer";
	}
	else
	{
		return "Draw";
	}

}

void FinalResult(int RoundsNumber, stWinCounter WinTimes) {

	cout << "\t\t\t\t---------------------------------------------------------------\n";
	cout << "\t\t\t\t                  + + + G A M E  O V E R  + + +                \n";
	cout << "\t\t\t\t---------------------------------------------------------------\n";
	cout << "\t\t\t\t------------------------ [ Game Result ] ----------------------\n";
	cout << "\t\t\t\tGame Rounds : " << RoundsNumber << endl;
	cout << "\t\t\t\tPlayer Won Times : " << WinTimes.PlayerWinTimes << endl;
	cout << "\t\t\t\tComputer Won Times : " << WinTimes.ComputerWinTimes << endl;
	cout << "\t\t\t\tDraw Times : " << WinTimes.Draw << endl;
	cout << "\t\t\t\tFinal Winner : " << FinalWinner(WinTimes) << endl;

}

void ResetScreen() {
	system("cls");
	system("color 0F"); // BLACK
}

bool MoreRounds() {

	char answer;
	do
	{
		cout << "\t\t\t\tDo you want to play more rounds? if [Yes] : tap (Y/y), [No] : tap (N/n)";
		cin >> answer;

	} while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

	if (answer == 'Y' || answer == 'y')
	{
		return 1;
	}
	return 0;
}

void Game() {

	stWinCounter WinTimes;

	do
	{
		ResetScreen();
		short RoundsNumber = ReadPositiveNumber("Please enter how many rounds you wanna play? : ");
		StartGame(RoundsNumber, WinTimes);
		FinalResult(RoundsNumber, WinTimes);

	} while (MoreRounds());
}

int main()
{
	srand((unsigned)time(NULL));
	Game();
}
