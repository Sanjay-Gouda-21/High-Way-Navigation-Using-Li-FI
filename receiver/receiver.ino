#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED_PIN 8
#define BUZZ 9
#define LDR_PIN A0
#define THRESHOLD 100
#define PERIOD 10

bool previous_state;
bool current_state;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZ,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("High-Way Navigat");
  lcd.setCursor(0, 1);
  lcd.print("ion Using Li-Fi");
  delay(1500);
  lcd.clear();
}

void loop()
{
  current_state = get_ldr();
  if (!current_state && previous_state)
  {
    print_byte(get_byte());
  }
  previous_state = current_state;
}

bool get_ldr()
{
  int voltage = analogRead(LDR_PIN);
  return voltage > THRESHOLD ? true : false;
}

char get_byte()
{
  char ret = 0;
  delay(PERIOD * 1.5);
  for (int i = 0; i < 8; i++)
  {
    ret = ret | get_ldr() << i;
    delay(PERIOD);
  }
  return ret;
}

void print_byte(char my_byte)
{
char buff[2];
  sprintf(buff, "%c", my_byte);
  Serial.print(buff);
  if(my_byte == 'A'){
    lcd.clear();
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZ,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Loc :- Honnavar");
     lcd.setCursor(0, 1);
  lcd.print("L-Bhatkal R-Kumta");
  }
  else if(my_byte == 'B'){
    lcd.clear();
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZ,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Loc :- Kumta");
     lcd.setCursor(0, 1);
  lcd.print("L-Sirsi R-Ankola");
  }
  else if(my_byte == 'C'){
    lcd.clear();
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZ,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Loc :- Ankola");
     lcd.setCursor(0, 1);
  lcd.print("L-Karwar R-Yellapur");
  }
  
  else if(int st=digitalRead(LDR_PIN)==0){  
    my_byte = '/0';
    lcd.clear();
    digitalWrite(LED_PIN,LOW);
    digitalWrite(BUZZ,LOW);
    delay(500);
}
}
