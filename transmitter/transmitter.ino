#define LED_PIN1 3
#define LED_PIN2 4
#define LED_PIN3 5
#define PERIOD 10


char* string1 = "AAA";
char* string2 = "BBB";
char* string3 = "CCC";
int string1_length;
int string2_length;
int string3_length;

void setup() 
{
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  string1_length = strlen(string1);
  string2_length = strlen(string2);
  string3_length = strlen(string3);
  Serial.begin(9600);
}

void loop() 
{
  for(int i = 0; i < string1_length; i ++)
  {
    send_byte(string1[i], LED_PIN1);
  
  }
  delay(200);
  for(int i = 0; i < string2_length; i ++)
  {
    send_byte(string2[i], LED_PIN2);
  }
  delay(200);
  for(int i = 0; i < string3_length; i ++)
  {
    send_byte(string3[i], LED_PIN3);
  }
  delay(200);
}

void send_byte(char my_byte,int LED_PINX)
{
  digitalWrite(LED_PINX, LOW);
  delay(PERIOD);

 
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(LED_PINX, (my_byte&(0x01 << i))!=0 );
    delay(PERIOD);
  }

  digitalWrite(LED_PINX, HIGH);
  delay(PERIOD);

}