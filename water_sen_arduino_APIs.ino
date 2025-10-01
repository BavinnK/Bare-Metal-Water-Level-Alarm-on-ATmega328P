int analogPin = 1;
int led = 12; 
int val = 0; 
int data = 0; 
void setup ()
{
pinMode (led, OUTPUT); 
Serial.begin (9600); 
}
void loop ()
{
val = analogRead (analogPin);

if (val> 700) {
digitalWrite (led, HIGH); 
}

else {
digitalWrite (led, LOW); 
}
data = val; 
Serial.println (data); 
delay (100);
}