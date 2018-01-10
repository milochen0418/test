#define RX_PIN     0
#define TX_PIN     1
#define RESET_PIN  2
#define LED_PIN   13

void setup()
{
  digitalWrite(RX_PIN, LOW);
  pinMode(RX_PIN, INPUT);
  digitalWrite(TX_PIN, LOW);
  pinMode(TX_PIN, INPUT);
  digitalWrite(RESET_PIN, HIGH);
  pinMode(RESET_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  static bool ready = 1;
  static unsigned long int timeout = 0;
  static unsigned long int blink_to = 0;

  if (! digitalRead(RX_PIN))  
  {
    if (ready)
    {
      digitalWrite(RESET_PIN, LOW);
      delayMicroseconds(5);
      digitalWrite(RESET_PIN, HIGH);

      ready = 0;
    }
    timeout = millis() + 1000;  
  }
  
  if (millis() > timeout)
    ready = 1;
 
  if (millis() > blink_to)
  { 
    blink_to = millis() + (ready ? 500 : 50);
    digitalWrite(LED_PIN, ! digitalRead(LED_PIN));
  }
}
