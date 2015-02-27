const int pingPin = 7;
//rgb display
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
//speaker pin and different tones in the array to play
int speakerOut = 12;               
int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
//pin that the dc motor goes to 
int motorPin = 6;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  

  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  
  Serial.print(inches);
  Serial.print("inches, ");
  Serial.println();


// multiple while loops for callibration of the distances and change in speed tone and light visuals
   while(inches<=3)
      {
        Serial.print("red zone");
        Serial.println();
        //digitalWrite(motorPin,250);
        setColor(0, 0, 255); // red
        analogWrite(motorPin,0);  
         redBeep();
         analogWrite(motorPin,0);
         delay(1);
        break;
       }   
    
    
  while(inches > 3 && inches <=8)
       {
        Serial.print("orange zone");
        Serial.println();
        setColor(10 , 80, 110); // purple
        //analogWrite(motorPin,80);
        yellowBeep();
         analogWrite(motorPin,100);
        delay(1);
        break;
       }
       
   while(inches > 8 && inches <=12)
       {
        Serial.print("orange zone");
        Serial.println();
        setColor(10 , 80, 150); // purple
        //analogWrite(motorPin,150);
        yellowBeep1();
        analogWrite(motorPin,190);
          delay(1);
        break;
       }
   while(inches > 12 && inches <=15)
       {
        Serial.print("orange zone");
        Serial.println();
        setColor(10 , 80, 150); // purple
        //analogWrite(motorPin, 200);
        yellowBeep2();
        analogWrite(motorPin,200);
        delay(1);
        break;
       }      
       
       
   while(inches > 15 && inches <= 50)
       {
        Serial.print("green light");
        Serial.println();
        setColor(0,255,0);
        analogWrite(motorPin,250);
         delay(1);
         break;
       }





//without this delay ; at green it flickers red
//so theres a need to delay the proccesses during the loop execution 
// of some sort to constantly run through the loop when it breaks in the while
//i chose 1/1000 second to have the fastest reaction time between while loops
delay(1);  
  
}

long microsecondsToInches(long microseconds)
{
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per second
  return (microseconds / 74 / 2);
}
//if ever wanting to use centinmeters
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  //the distance of the object we take half of the distance travelled.
  return (microseconds / 29 / 2);
}
//rgb display function

void setColor(int red, int green, int blue)
{
  //defining the colors//
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
//physically writing the values you want to pass through the parameters for the light manipulation
//method call is setColor(int,int,int);
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}


void redBeep(){
    analogWrite(speakerOut, 0);              
    analogWrite(speakerOut,500);
    delayMicroseconds(tones[1432]);
    analogWrite(speakerOut, 0);
    delayMicroseconds(0);
        
}

void yellowBeep(){
    analogWrite(speakerOut, 0);              
    analogWrite(speakerOut,500);
    delayMicroseconds(tones[1432]);
    analogWrite(speakerOut, 0);
    delayMicroseconds(tones[1136]);
     delay(200);
}

void yellowBeep1(){
    analogWrite(speakerOut, 0);              
    analogWrite(speakerOut,500);
    delayMicroseconds(tones[1432]);
    analogWrite(speakerOut, 0);
    delayMicroseconds(tones[1136]);
    delay(600);
}

void yellowBeep2(){
    analogWrite(speakerOut, 0);              
    analogWrite(speakerOut,500);
    delayMicroseconds(tones[1432]);
    analogWrite(speakerOut, 0);
    delayMicroseconds(1000);
     delay(1000);
}


