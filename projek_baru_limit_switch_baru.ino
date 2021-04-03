int irsensor = 13;
int valuesensor = 0;

int motor1 = 8;
int motor2 = 9;

int input1 = A0;
int input2 = A1;
int enL = 4;
int enR = 5;

int value1 = 0;
int value2 = 0;

int limit1 = 2;
int limit2 = 3;

int buttonup = 6;
int buttondown = 7;

int kunci = 10;

int valuekunci = 0;

int up = 0;
int down = 0;

int valuelimit1 = 0;
int valuelimit2 = 0;

int state = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;
int state6 = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode (motor1, OUTPUT);
  pinMode (motor2, OUTPUT);
  
  pinMode (kunci, INPUT);
  pinMode (input1, INPUT);
  pinMode (input2, INPUT);
  pinMode (limit1, INPUT_PULLUP);
  pinMode (limit2, INPUT_PULLUP);
  
  pinMode (enL, OUTPUT);
  pinMode (enR, OUTPUT);

  pinMode (irsensor, INPUT);

  pinMode (buttonup, INPUT_PULLUP);
  pinMode (buttondown, INPUT_PULLUP);

  digitalWrite (motor1, LOW);
  digitalWrite (motor2, HIGH);
  Serial.begin (9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value1 = analogRead (input1);
  value2 = analogRead (input2);
  valuelimit1 = digitalRead (limit1);
  valuelimit2 = digitalRead (limit2);
  up = digitalRead (buttonup);
  down = digitalRead (buttondown);
  valuekunci = digitalRead (kunci);
  valuesensor = digitalRead (irsensor);
  

  //Serial.println (distance);

  if (valuesensor == LOW && state5 == 0){
    delay (5000);
    state6 = 1;
    state5 = 1;
    state3 = 0;
    }


  if (state6 == 1){
    digitalWrite (motor1, LOW);
    digitalWrite (motor2, HIGH);
    digitalWrite (enL, HIGH);
    digitalWrite (enR, HIGH);
    Serial.println ("motor up auto");
    }

  

  

  if (valuekunci == HIGH){
    manual ();
    }


 if (valuekunci == LOW){   

  if (valuesensor == HIGH){
  if (value1 >= 500 ){
    state = 1;
    digitalWrite (motor1, LOW);
    digitalWrite (motor2, HIGH);
    
    }
  

  if (value1 <=100 ) {
    state = 1;
    digitalWrite (motor1, HIGH);
    digitalWrite (motor2, LOW);
    Serial.println ("tukar down");

    if (valuesensor == HIGH){
      state5 == 0;
      }
    }
    

  
  if (state == 1 && value2 >=500){
    state2 = 1;
    state3 = 0;
    
    }


  if (state2 == 1){
    digitalWrite (enL, HIGH);
    digitalWrite (enR, HIGH);
    Serial.println ("down tel");
  }

 }
 }
 

  if (valuelimit1 == LOW || valuelimit2 == LOW && state3 == 0){
    state2 = 0;
    state3 = 1;
    state4 = 0;
    state5 = 0;
    digitalWrite (enL, LOW);
    digitalWrite (enR, LOW);
    Serial.println("motor stop");
    }

  

}

void manual (){
    if (up == LOW){
    state4 = 1;
    
    }

  if (down == LOW){
    state4 = 2;
    
    }

  if (valuesensor == HIGH){
  if (state4 == 1){
   
    digitalWrite (motor1, LOW);
    digitalWrite (motor2, HIGH);
    digitalWrite (enL, HIGH);
    digitalWrite (enR, HIGH);
    Serial.println ("up");
    }
  }
  else if (state4 == 2){
  
    digitalWrite (motor1, HIGH);
    digitalWrite (motor2, LOW);
    digitalWrite (enL, HIGH);
    digitalWrite (enR, HIGH);
    Serial.println ("down");

    if (valuesensor == HIGH){
      state5 == 0;
      }
    }
  }
