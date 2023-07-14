// HW 7, CS 201
// By Samuel Hunt

/* This program plays a game of Cauldron Quest. The program was coded based
off of the design document ideas found in Lab 12 Schematics.txt */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int objectPosition1;
int objectPosition2;
int objectPosition3;
int objectinput;
int objectinput2;
int tempPosition;
bool loopCheck = true;
bool objRevealed1 = false;
bool objRevealed2 = false;
bool objRevealed3 = false;

// This class helps handle the positions of the bottles.
class Movement {
  public:
  int objectPosition1;
  int objectPosition2;
  int objectPosition3;
};

// This class handles everything the magic dice (black dice) needs to do.
class magicDice {
  public:
  int dice1;
  int dice2;
  int dice3;
  int choice;

  int randomChoice() {
    int number = rand() % 6 + 1;
    return number;
  }

  void revealCharm (string obj1, string obj2, string obj3) {
    cout << "Which bottle do you want flipped on? (1-3): ";
    cin >> objectinput;
    cout << endl;

    if (objectinput == 1) {
      cout << "The " << obj1 << " bottle has been revealed!" << endl;
      objRevealed1 = true;
    }

    if (objectinput == 2) {
      cout << "The " << obj2 << " bottle has been revealed!" << endl;
      objRevealed2 = true;
    }

    if (objectinput == 3) {
      cout << "The " << obj3 << " bottle has been revealed!" << endl;
      objRevealed3 = true;
    }
  }

  void swampCharm(string obj1, string obj2, string obj3) {
    cout << "Which 2 bottles do you want swapped?" << endl;
    cout << "From 1 to 3, choose 1st bottle: ";
    cin >> objectinput;
    cout << "From 1 to 3, choose 2nd bottle: ";
    cin >> objectinput2;

    if (objectinput == 1 and objectinput2 == 2) {
      cout << endl << obj1 << " and " << obj2 << " have swapped places."
      << endl;
      tempPosition = objectPosition1;
      objectPosition1 = objectPosition2;
      objectPosition2 = tempPosition;
      cout << obj1 << " is now at space " << objectPosition1 << endl;
      cout << obj2 << " is now at space " << objectPosition2 << endl;
    }

    if (objectinput == 1 and objectinput2 == 3) {
      cout << endl << obj1 << " and " << obj3 << " have swapped places."
      << endl;
      tempPosition = objectPosition1;
      objectPosition1 = objectPosition3;
      objectPosition3 = tempPosition;
      cout << obj1 << " is now at space " << objectPosition1 << endl;
      cout << obj3 << " is now at space " << objectPosition3 << endl;
    }

    if (objectinput == 2 and objectinput2 == 1) {
      cout << endl << obj2 << " and " << obj1 << " have swapped places."
      << endl;
      tempPosition = objectPosition1;
      objectPosition1 = objectPosition2;
      objectPosition2 = tempPosition;
      cout << obj2 << " is now at space " << objectPosition2 << endl;
      cout << obj1 << " is now at space " << objectPosition1 << endl;
    }

    if (objectinput == 2 and objectinput2 == 3) {
      cout << endl << obj2 << " and " << obj3 << " have swapped places."
      << endl;
      tempPosition = objectPosition2;
      objectPosition2 = objectPosition3;
      objectPosition3 = tempPosition;
      cout << obj2 << " is now at space " << objectPosition2 << endl;
      cout << obj3 << " is now at space " << objectPosition3 << endl;
    }

    if (objectinput == 3 and objectinput2 == 1) {
      cout << endl << obj3 << " and " << obj1 << " have swapped places."
      << endl;
      tempPosition = objectPosition1;
      objectPosition1 = objectPosition3;
      objectPosition3 = tempPosition;
      cout << obj3 << " is now at space " << objectPosition3 << endl;
      cout << obj1 << " is now at space " << objectPosition1 << endl;
    }

    if (objectinput == 3 and objectinput2 == 2) {
      cout << endl << obj3 << " and " << obj2 << " have swapped places."
      << endl;
      tempPosition = objectPosition2;
      objectPosition2 = objectPosition3;
      objectPosition3 = tempPosition;
      cout << obj3 << " is now at space " << objectPosition3 << endl;
      cout << obj2 << " is now at space " << objectPosition2 << endl;
    }
  }

  void superPowerCharm(string obj1, string obj2, string obj3) {
    cout << "You can move a potion 6 spaces!" << endl;
    cout << "Which potion do you want to move? (1-3): ";
    cin >> objectinput;

    if (objectinput == 1) {
      cout << "Moving " << obj1 << " 6 spaces." << endl;
      objectPosition1 += 6;
      cout << obj1 << " is now at space " << objectPosition1 << endl;
    }

    if (objectinput == 2) {
      cout << "Moving " << obj2 << " 6 spaces." << endl;
      objectPosition2 += 6;
      cout << obj2 << " is now at space " << objectPosition2 << endl;
    }

    if (objectinput == 3) {
      cout << "Moving " << obj3 << " 6 spaces." << endl;
      objectPosition3 += 6;
      cout << obj3 << " is now at space " << objectPosition3 << endl;
    }
  }

  void rerolls(string obj1, string obj2, string obj3) {
    cout << "Dice rolls are " << dice1 << ", " << dice2 << ", and " << dice3 << endl << endl;

    if (dice1 % 2 == 0 and dice2 % 2 == 0 and dice3 % 2 == 0) {
      cout << "All dice are even!" << endl;
      revealCharm(obj1, obj2, obj3);
    }

    else if (dice1 % 2 == 1 and dice2 % 2 == 1 and dice3 % 2 == 1) {
      cout << "All dice are odd!" << endl;
      swampCharm(obj1, obj2, obj3);
    }

    else if (dice1 + dice2 + dice3 == 12) {
      cout << "Dice equal up to 12!" << endl;
      superPowerCharm(obj1, obj2, obj3);
    }

    else {
      cout << "No match." << endl;
      cout << "Choose dice to reroll: ";
      cin >> choice;
      cout << "Rerolling dice " << choice << endl;

      if (choice == 1) {
        dice1 = randomChoice();
      }

      if (choice == 2) {
        dice2 = randomChoice();
      }

      if (choice == 3) {
        dice3 = randomChoice();
      }

      rerolls(obj1, obj2, obj3);
    }
  }

  void blackDice(string obj1, string obj2, string obj3) {
    dice1 = randomChoice();
    dice2 = randomChoice();
    dice3 = randomChoice();

    cout << "Dice rolls are " << dice1 << ", " << dice2 << ", and " << dice3 << endl << endl;

    if (dice1 % 2 == 0 and dice2 % 2 == 0 and dice3 % 2 == 0) {
      cout << "All dice are even!" << endl;
      revealCharm(obj1, obj2, obj3);
    }

    else if (dice1 % 2 == 1 and dice2 % 2 == 1 and dice3 % 2 == 1) {
      cout << "All dice are odd!" << endl;
      swampCharm(obj1, obj2, obj3);
    }

    else if (dice1 + dice2 + dice3 == 12) {
      cout << "Dice equal up to 12!" << endl;
      superPowerCharm(obj1, obj2, obj3);
    }

    else {
      cout << "No match." << endl;
      cout << "Choose dice to reroll: ";
      cin >> choice;
      cout << "Rerolling dice " << choice << endl;

      if (choice == 1) {
        dice1 = randomChoice();
      }

      if (choice == 2) {
        dice2 = randomChoice();
      }

      if (choice == 3) {
        dice3 = randomChoice();
      }

      rerolls(obj1, obj2, obj3);
    }
  }
};

// This class handles everything the action dice (white dice) needs to do.
class actionDice {
  public:
  int dice1;
  int dice2;
  string diceValue1;
  string diceValue2;

  int randomChoice() {
    int number = rand() % 6 + 1;
    return number;
  }

  void whiteDice(string obj1, string obj2, string obj3) {
    dice1 = randomChoice();
    dice2 = randomChoice();

    if (dice1 <= 4) {
      diceValue1 = "Potion";
    }

    if (dice1 >= 5) {
      diceValue1 = "Wizard Hat";
    }

    if (dice2 == 1 || dice2 == 5 || dice2 == 6) {
      diceValue2 = "Lightning";
    }

    if (dice2 == 2 || dice2 == 3) {
      diceValue2 = "3";
    }

    if (dice2 == 4) {
      diceValue2 = "4";
    }

    cout << "1st dice roll is " << diceValue1 << endl;
    cout << "2nd dice roll is " << diceValue2 << endl << endl;

    if (diceValue1 == "Potion" and diceValue2 == "Lightning") {
      cout << "Ok, time to roll the magic dice!" << endl;
      magicDice roll;
      roll.blackDice(obj1, obj2, obj3);
    }

    if (diceValue1 == "Wizard Hat" and diceValue2 == "Lightning") {
      cout << "Wizard's path is not used here. Rerolling..." << endl;
    }

    if (diceValue1 == "Wizard Hat" and diceValue2 == "3") {
      cout << "Wizard is not used here. Rerolling..." << endl << endl;
    }

    if (diceValue1 == "Wizard Hat" and diceValue2 == "4") {
      cout << "Wizard is not used here. Rerolling..." << endl << endl;
    }

    if (diceValue1 == "Potion" and diceValue2 == "3") {
      cout << "You can move a potion 3 spaces!" << endl;
      cout << "Which potion do you want to move? (1-3): ";
      cin >> objectinput;

      if (objectinput == 1) {
        cout << "Moving " << obj1 << " 3 spaces." << endl;
        objectPosition1 += 3;
        cout << obj1 << " is now at space " << objectPosition1 << endl;
      }

      if (objectinput == 2) {
        cout << "Moving " << obj2 << " 3 spaces." << endl;
        objectPosition2 += 3;
        cout << obj2 << " is now at space " << objectPosition2 << endl;
      }

      if (objectinput == 3) {
        cout << "Moving " << obj3 << " 3 spaces." << endl;
        objectPosition3 += 3;
        cout << obj3 << " is now at space " << objectPosition3 << endl;
      }
    }

    if (diceValue1 == "Potion" and diceValue2 == "4") {
      cout << "You can move a potion 4 spaces!" << endl;
      cout << "Which potion do you want to move? (1-3): ";
      cin >> objectinput;

      if (objectinput == 1) {
        cout << "Moving " << obj1 << " 4 spaces." << endl;
        objectPosition1 += 4;
        cout << obj1 << " is now at space " << objectPosition1 << endl;
      }

      if (objectinput == 2) {
        cout << "Moving " << obj2 << " 4 spaces." << endl;
        objectPosition2 += 4;
        cout << obj2 << " is now at space " << objectPosition2 << endl;
      }

      if (objectinput == 3) {
        cout << "Moving " << obj3 << " 4 spaces." << endl;
        objectPosition3 += 4;
        cout << obj3 << " is now at space " << objectPosition3 << endl;
      }
    }
  }
};

// This class randomizes and returns to main() the objects
// that the game will use.
class RandomObjects {
  public:

  string pickObjects() {
    int Object = rand() % 6 + 1;

    string stringObject = " ";

    if (Object == 1) {
      stringObject = "Rotten Egg";
    }
    else if (Object == 2) {
      stringObject = "Poison Mushroom";
    }
    else if (Object == 3) {
      stringObject = "Horned Toad";
    }
    else if (Object == 4) {
      stringObject = "Horned Newt";
    }
    else if (Object == 5) {
      stringObject = "Dandelion Root";
    }
    else if (Object == 6) {
      stringObject = "Bat Wing";
    }

    return stringObject;
  }
};

// Once the game is over, this class is called to let the
// user know that the game is over.
class winCon {
  public:
  void allDone () {
    cout << endl << "Congrats! You have won the game!" << endl;
    cout << "All done. Have a great day!" << endl;
  }
};

// The main function starts the game, gives the 3 object values for
// other classes to use, and calls for winCon to end the game
// once all 3 objects hit 11 spaces or more and all 3 objects
// have been revealed.
int main() {
  cout << "Welcome to Cauldron Quest" << endl;
  cout << "Let's get started!" << endl << endl;

  srand(time(0));

  RandomObjects choose;
  string firstObject = choose.pickObjects();
  string secondObject = choose.pickObjects();
  string thirdObject = choose.pickObjects();

  while (firstObject == thirdObject or firstObject == secondObject
  or secondObject == thirdObject) {
    firstObject = choose.pickObjects();
    secondObject = choose.pickObjects();
    thirdObject = choose.pickObjects();
  }

  cout << "Objects for this game are: " << endl << firstObject <<
  ", " << secondObject << ", and " << thirdObject << "!" << endl;

  actionDice roll;

  while (loopCheck) {
    cout << endl << "Rolling the Action Dice:" << endl;
    roll.whiteDice(firstObject, secondObject, thirdObject);

    if (objectPosition1 >= 11 and objectPosition2 >= 11 and
    objectPosition3 >= 11 and objRevealed1 and objRevealed2
    and objRevealed3) {
      winCon done;
      done.allDone();
      loopCheck = false;
    }
  }

}
