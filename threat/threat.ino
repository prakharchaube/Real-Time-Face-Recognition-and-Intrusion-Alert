const int led=13;
const int led2=12;
const int peizo=8;
int value=0;
int flag = 0;



void setup() 

   { 

      Serial.begin(9600); 

      pinMode(led, OUTPUT);

      pinMode(led2,OUTPUT);

      pinMode(peizo,OUTPUT);
      digitalWrite(led, LOW);

      Serial.println("Connection established...");

   }

 

void loop() 
{
     while (Serial.available())
     {
        value = Serial.read();
     }

     
     if(value=='1')
     {
      digitalWrite(peizo, LOW);
      digitalWrite(led2, LOW);
      if (flag == 0)
      {
        digitalWrite (led, HIGH);
        
        flag = 1;
      }
     }

     

     if (value == '2'){
        digitalWrite(led, LOW);
        digitalWrite (led2, HIGH);
        tone(peizo,1000);
        delay(100);
        digitalWrite(led2,LOW);
        tone(peizo,22000);
        delay(100);
        digitalWrite (led2, HIGH);
        tone(peizo,1000);
        flag = 0;
     }

   }
