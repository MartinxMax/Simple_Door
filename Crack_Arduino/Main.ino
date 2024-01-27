#include <LCDWIKI_GUI.h>
#include <LCDWIKI_KBV.h>
#include <Wire.h>

LCDWIKI_KBV mylcd(240, 320, A3, A2, A1, A0, 13);

#define BLACK 0x0000
#define GREEN 0x07E0
#define YELLOW 0xFFE0
#define MAGENTA 0xF81F
#define RED 0xF800

void reloadInk(int size) {
  mylcd.Set_Text_colour(GREEN);
  mylcd.Set_Text_Size(size);
  mylcd.Print_String("-(||||||||||]====|", 0, 50);
}

void printStatus(const char* status) {
  mylcd.Set_Text_colour(YELLOW);
  mylcd.Set_Text_Size(3);
  mylcd.Print_String(status, 0, 200);
  mylcd.Set_Text_Size(5);
}

void startButton() {
  int handlePosition = 340;
  int handle2Position = 216;
  int num = 0;

  while (num < 5) {
    if (digitalRead(12) == LOW) {
      mylcd.Set_Text_colour(GREEN);
      mylcd.Set_Text_Size(3);
      handlePosition -= 20;
      handle2Position -= 36;
      num++;
      mylcd.Print("| ", handlePosition, 50);
      mylcd.Print("  ", handle2Position, 50);
 
    } else {
      handlePosition = 340;
      handle2Position = 216;
      num = 0;
      reloadInk(3);
    }
  }
}

void handleInjection() {
unsigned long startTime = millis();
char runTimeStr[30];
  mylcd.Set_Text_colour(GREEN);
  mylcd.Set_Text_Size(3);

  for (int cracknum = 0; cracknum <= 255; cracknum++) {
    printStatus("---[Injecting...]---");

    if (digitalRead(12) != LOW) {
      printStatus("---[Empty...]---");
      break;
    }

    mylcd.Set_Text_colour(MAGENTA);
    mylcd.Set_Text_Size(3);
    char hexString[20];

    sprintf(hexString, "Payload:[0x%02X]  ", cracknum);
    mylcd.Print(hexString, 0, 100);
   
    Wire.beginTransmission(0x27);
    Wire.write(cracknum);
    Wire.endTransmission();
  
    unsigned long currentTime = millis();
    unsigned long runTime = currentTime - startTime;
    sprintf(runTimeStr, "Time:[%lums]   ", runTime);
    mylcd.Print(runTimeStr, 0, 150);
      delay(500);
 
  }

  mylcd.Set_Text_colour(RED);
  mylcd.Set_Text_Size(5);
}

void setup() {
  Wire.begin();
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(12, HIGH);
  digitalWrite(10, LOW);
  
  Serial.begin(9600);

  mylcd.Init_LCD();
  //Serial.println(mylcd.Read_ID(), HEX);
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Rotation(1);

  displayHeader();
}

void displayHeader() {
  mylcd.Set_Text_Mode(0);
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_colour(RED);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Set_Text_Size(3);
  mylcd.Print_String("S-H4CK13@Maptnh", 0, 0);
 
  mylcd.Set_Text_colour(MAGENTA);
  mylcd.Print("Payload:[Null]    ", 0, 100);
  mylcd.Print("Time:[Null]       ", 0, 150);
}
 unsigned char i = 0;
void loop() {
  
  reloadInk(3);
  printStatus("----[Full...]----");
  startButton();
  handleInjection();
  printStatus("---[Empty...]---");

  while (digitalRead(12) == LOW)
   ;
}
