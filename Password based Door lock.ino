#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Define the length of the password
#define Password_Length 5

// Initialize a Servo object to control the door lock
Servo myservo;

// Initialize a LiquidCrystal object to control the LCD display
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Variable to store the current position of the servo motor
int pos = 0;

// Arrays to store the entered password and the master password
char Data[Password_Length];
char Master[Password_Length] = "1234";

// Variables to keep track of the data count and the master password count
byte data_count = 0, master_count = 0;

// Boolean variables to check if the password is correct and to track the door status
bool Pass_is_good;
bool door = false;

// Variable to store the key pressed on the keypad
char customKey;

/*--- Preparing the keypad ---*/

// Define the number of rows and columns in the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pins connected to the rows and columns of the keypad
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

// Create a Keypad object to handle keypad input
Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/*--- Main Action ---*/
void setup()
{
  // Attach the servo motor to pin 9 with specific range limits
  myservo.attach(9, 2000, 2400);

  // Close the servo (lock the door)
  ServoClose();

  // Initialize the LCD with a 16x2 size (16 columns, 2 rows)
  lcd.begin(16, 2);

  // Display the initial message on the LCD
  lcd.print("Protected Door");

  // Call the loading function to simulate loading on the LCD
  loading("Loading");

  // Clear the LCD screen
  lcd.clear();
}

void loop()
{
  // Check if the door is currently open
  if (door == true)
  {
    // Get the key pressed on the keypad
    customKey = customKeypad.getKey();

    // If the '#' key is pressed, close the door
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("Door is closed");
      delay(3000);
      door = false;
    }
  }
  else
  {
    // If the door is closed, allow the user to attempt to open it
    Open();
  }
}

// Function to simulate a loading process on the LCD
void loading (char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

// Function to clear the entered data after an attempt
void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

// Function to close the servo motor (lock the door)
void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    myservo.write(pos);
  }
}

// Function to open the servo motor (unlock the door)
void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    myservo.write(pos);  
  }
}

// Function to handle the process of opening the door
void Open()
{
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  
  // Get the key pressed on the keypad
  customKey = customKeypad.getKey();
  
  // If a key is pressed, store it in the Data array and display it on the LCD
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  // Check if the entire password has been entered
  if (data_count == Password_Length - 1)
  {
    // Compare the entered password with the master password
    if (!strcmp(Data, Master))
    {
      // If the password is correct, open the door
      lcd.clear();
      ServoOpen();
      lcd.print(" Door is Open ");
      door = true;
      
      // Wait for 5 seconds before closing the door automatically
      delay(5000);
      loading("Waiting");
      lcd.clear();
      lcd.print(" Time is up! ");
      delay(1000);
      ServoClose();
      door = false;      
    }
    else
    {
      // If the password is incorrect, display an error message
      lcd.clear();
      lcd.print(" Wrong Password ");
      door = false;
    }

    // Delay to allow the user to see the message, then clear the data
    delay(1000);
    lcd.clear();
    clearData();
  }
}
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Define the length of the password
#define Password_Length 5

// Initialize a Servo object to control the door lock
Servo myservo;

// Initialize a LiquidCrystal object to control the LCD display
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Variable to store the current position of the servo motor
int pos = 0;

// Arrays to store the entered password and the master password
char Data[Password_Length];
char Master[Password_Length] = "1234";

// Variables to keep track of the data count and the master password count
byte data_count = 0, master_count = 0;

// Boolean variables to check if the password is correct and to track the door status
bool Pass_is_good;
bool door = false;

// Variable to store the key pressed on the keypad
char customKey;

/*--- Preparing the keypad ---*/

// Define the number of rows and columns in the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pins connected to the rows and columns of the keypad
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

// Create a Keypad object to handle keypad input
Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/*--- Main Action ---*/
void setup()
{
  // Attach the servo motor to pin 9 with specific range limits
  myservo.attach(9, 2000, 2400);

  // Close the servo (lock the door)
  ServoClose();

  // Initialize the LCD with a 16x2 size (16 columns, 2 rows)
  lcd.begin(16, 2);

  // Display the initial message on the LCD
  lcd.print("Protected Door");

  // Call the loading function to simulate loading on the LCD
  loading("Loading");

  // Clear the LCD screen
  lcd.clear();
}

void loop()
{
  // Check if the door is currently open
  if (door == true)
  {
    // Get the key pressed on the keypad
    customKey = customKeypad.getKey();

    // If the '#' key is pressed, close the door
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("Door is closed");
      delay(3000);
      door = false;
    }
  }
  else
  {
    // If the door is closed, allow the user to attempt to open it
    Open();
  }
}

// Function to simulate a loading process on the LCD
void loading (char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

// Function to clear the entered data after an attempt
void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

// Function to close the servo motor (lock the door)
void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    myservo.write(pos);
  }
}

// Function to open the servo motor (unlock the door)
void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    myservo.write(pos);  
  }
}

// Function to handle the process of opening the door
void Open()
{
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  
  // Get the key pressed on the keypad
  customKey = customKeypad.getKey();
  
  // If a key is pressed, store it in the Data array and display it on the LCD
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  // Check if the entire password has been entered
  if (data_count == Password_Length - 1)
  {
    // Compare the entered password with the master password
    if (!strcmp(Data, Master))
    {
      // If the password is correct, open the door
      lcd.clear();
      ServoOpen();
      lcd.print(" Door is Open ");
      door = true;
      
      // Wait for 5 seconds before closing the door automatically
      delay(5000);
      loading("Waiting");
      lcd.clear();
      lcd.print(" Time is up! ");
      delay(1000);
      ServoClose();
      door = false;      
    }
    else
    {
      // If the password is incorrect, display an error message
      lcd.clear();
      lcd.print(" Wrong Password ");
      door = false;
    }

    // Delay to allow the user to see the message, then clear the data
    delay(1000);
    lcd.clear();
    clearData();
  }
}
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Define the length of the password
#define Password_Length 5

// Initialize a Servo object to control the door lock
Servo myservo;

// Initialize a LiquidCrystal object to control the LCD display
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Variable to store the current position of the servo motor
int pos = 0;

// Arrays to store the entered password and the master password
char Data[Password_Length];
char Master[Password_Length] = "1234";

// Variables to keep track of the data count and the master password count
byte data_count = 0, master_count = 0;

// Boolean variables to check if the password is correct and to track the door status
bool Pass_is_good;
bool door = false;

// Variable to store the key pressed on the keypad
char customKey;

/*--- Preparing the keypad ---*/

// Define the number of rows and columns in the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pins connected to the rows and columns of the keypad
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

// Create a Keypad object to handle keypad input
Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/*--- Main Action ---*/
void setup()
{
  // Attach the servo motor to pin 9 with specific range limits
  myservo.attach(9, 2000, 2400);

  // Close the servo (lock the door)
  ServoClose();

  // Initialize the LCD with a 16x2 size (16 columns, 2 rows)
  lcd.begin(16, 2);

  // Display the initial message on the LCD
  lcd.print("Protected Door");

  // Call the loading function to simulate loading on the LCD
  loading("Loading");

  // Clear the LCD screen
  lcd.clear();
}

void loop()
{
  // Check if the door is currently open
  if (door == true)
  {
    // Get the key pressed on the keypad
    customKey = customKeypad.getKey();

    // If the '#' key is pressed, close the door
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("Door is closed");
      delay(3000);
      door = false;
    }
  }
  else
  {
    // If the door is closed, allow the user to attempt to open it
    Open();
  }
}

// Function to simulate a loading process on the LCD
void loading (char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

// Function to clear the entered data after an attempt
void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

// Function to close the servo motor (lock the door)
void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    myservo.write(pos);
  }
}

// Function to open the servo motor (unlock the door)
void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    myservo.write(pos);  
  }
}

// Function to handle the process of opening the door
void Open()
{
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  
  // Get the key pressed on the keypad
  customKey = customKeypad.getKey();
  
  // If a key is pressed, store it in the Data array and display it on the LCD
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  // Check if the entire password has been entered
  if (data_count == Password_Length - 1)
  {
    // Compare the entered password with the master password
    if (!strcmp(Data, Master))
    {
      // If the password is correct, open the door
      lcd.clear();
      ServoOpen();
      lcd.print(" Door is Open ");
      door = true;
      
      // Wait for 5 seconds before closing the door automatically
      delay(5000);
      loading("Waiting");
      lcd.clear();
      lcd.print(" Time is up! ");
      delay(1000);
      ServoClose();
      door = false;      
    }
    else
    {
      // If the password is incorrect, display an error message
      lcd.clear();
      lcd.print(" Wrong Password ");
      door = false;
    }

    // Delay to allow the user to see the message, then clear the data
    delay(1000);
    lcd.clear();
    clearData();
  }
}
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Define the length of the password
#define Password_Length 5

// Initialize a Servo object to control the door lock
Servo myservo;

// Initialize a LiquidCrystal object to control the LCD display
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Variable to store the current position of the servo motor
int pos = 0;

// Arrays to store the entered password and the master password
char Data[Password_Length];
char Master[Password_Length] = "1234";

// Variables to keep track of the data count and the master password count
byte data_count = 0, master_count = 0;

// Boolean variables to check if the password is correct and to track the door status
bool Pass_is_good;
bool door = false;

// Variable to store the key pressed on the keypad
char customKey;

/*--- Preparing the keypad ---*/

// Define the number of rows and columns in the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pins connected to the rows and columns of the keypad
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

// Create a Keypad object to handle keypad input
Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/*--- Main Action ---*/
void setup()
{
  // Attach the servo motor to pin 9 with specific range limits
  myservo.attach(9, 2000, 2400);

  // Close the servo (lock the door)
  ServoClose();

  // Initialize the LCD with a 16x2 size (16 columns, 2 rows)
  lcd.begin(16, 2);

  // Display the initial message on the LCD
  lcd.print("Protected Door");

  // Call the loading function to simulate loading on the LCD
  loading("Loading");

  // Clear the LCD screen
  lcd.clear();
}

void loop()
{
  // Check if the door is currently open
  if (door == true)
  {
    // Get the key pressed on the keypad
    customKey = customKeypad.getKey();

    // If the '#' key is pressed, close the door
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("Door is closed");
      delay(3000);
      door = false;
    }
  }
  else
  {
    // If the door is closed, allow the user to attempt to open it
    Open();
  }
}

// Function to simulate a loading process on the LCD
void loading (char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

// Function to clear the entered data after an attempt
void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

// Function to close the servo motor (lock the door)
void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    myservo.write(pos);
  }
}

// Function to open the servo motor (unlock the door)
void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    myservo.write(pos);  
  }
}

// Function to handle the process of opening the door
void Open()
{
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  
  // Get the key pressed on the keypad
  customKey = customKeypad.getKey();
  
  // If a key is pressed, store it in the Data array and display it on the LCD
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  // Check if the entire password has been entered
  if (data_count == Password_Length - 1)
  {
    // Compare the entered password with the master password
    if (!strcmp(Data, Master))
    {
      // If the password is correct, open the door
      lcd.clear();
      ServoOpen();
      lcd.print(" Door is Open ");
      door = true;
      
      // Wait for 5 seconds before closing the door automatically
      delay(5000);
      loading("Waiting");
      lcd.clear();
      lcd.print(" Time is up! ");
      delay(1000);
      ServoClose();
      door = false;      
    }
    else
    {
      // If the password is incorrect, display an error message
      lcd.clear();
      lcd.print(" Wrong Password ");
      door = false;
    }

    // Delay to allow the user to see the message, then clear the data
    delay(1000);
    lcd.clear();
    clearData();
  }
}
