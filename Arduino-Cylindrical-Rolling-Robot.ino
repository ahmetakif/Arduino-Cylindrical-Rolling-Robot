const int soli = 6;
const int sagi = 2;
const int solg = 7;
const int sagg = 4;
const int buzzer = 11;
const int ensag = 3;
const int ensol = 5;

String readString;

int hiz;

void setup() 
{
  Serial.begin(9600);
  pinMode(soli , OUTPUT); 
  pinMode(sagi , OUTPUT);
  pinMode(solg , OUTPUT); 
  pinMode(sagg , OUTPUT);
  pinMode(ensol , OUTPUT); 
  pinMode(ensag , OUTPUT);
  pinMode(buzzer , OUTPUT);  
}
void loop() 
{
  while (Serial.available()) 
  {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  if (readString.length() >0) 
  {
    Serial.println(readString);

    if (readString == "zero")     
    {
      hiz = 0;
    }
    if (readString == "ten")     
    {
      hiz = 25;
    }
    if (readString == "twenty")     
    {
      hiz = 50;
    }
    if (readString == "thirty")     
    {
      hiz = 75;
    }
    if (readString == "fourty")     
    {
      hiz = 100;
    }
    if (readString == "fifty")     
    {
      hiz = 125;
    }
    if (readString == "sixty")     
    {
      hiz = 150;
    }
    if (readString == "seventy")     
    {
      hiz = 175;
    }
    if (readString == "eighty")     
    {
      hiz = 200;
    }
    if (readString == "ninety")     
    {
      hiz = 225;
    }
    if (readString == "hundred")     
    {
      hiz = 255;
    }
    if (readString == "forward")     
    {
      digitalWrite(soli , HIGH);
      digitalWrite(sagi , HIGH);
      analogWrite(ensol , hiz);
      analogWrite(ensag , hiz);
    }
    if (readString == "backward")     
    {
      digitalWrite(solg , HIGH);
      digitalWrite(sagg , HIGH);
      analogWrite(ensol , hiz);
      analogWrite(ensag , hiz);
    }
    if (readString == "left")     
    {
      digitalWrite(solg , HIGH);
      digitalWrite(sagi , HIGH);
      analogWrite(ensol , hiz);
      analogWrite(ensag , 0);
    }
    if (readString == "right")     
    {
      digitalWrite(soli , HIGH);
      digitalWrite(sagg , HIGH);
      analogWrite(ensag , hiz);
      analogWrite(ensol , 0);
    }
    if (readString == "leftforward")     
    {
      digitalWrite(soli , HIGH);
      analogWrite(ensol , hiz);
      analogWrite(ensag , 0);
    }
    if (readString == "rightforward")     
    {
      digitalWrite(sagi , HIGH);
      analogWrite(ensag , hiz);
      analogWrite(ensol , 0);
    }
    if (readString == "leftbackward")     
    {
      digitalWrite(solg , HIGH);
      analogWrite(ensol , hiz);
      analogWrite(ensag , 0);
    }
    if (readString == "rightbackward")     
    {
      digitalWrite(sagg , HIGH);
      analogWrite(ensag , hiz);
      analogWrite(ensol , 0);
    }
    if (readString == "stop")     
    {
      digitalWrite(soli , LOW);
      digitalWrite(sagi , LOW);
      digitalWrite(solg , LOW);
      digitalWrite(sagg , LOW);
      analogWrite(ensol , 0);
      analogWrite(ensag , 0);
    }
    if (readString == "sound")     
    {
      digitalWrite(buzzer , HIGH);
    }
    if (readString == "shutup")     
    {
      digitalWrite(buzzer , LOW);
    }
    readString="";
  } 
}
