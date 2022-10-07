// C++ code
//
const int PIN_LED1=4;
  const int PIN_LED2=5;
  const int PIN_LED3=6;
  const int PIN_LED4=7;
  const int PIN_LED5=8;
  const int PINBUZZ=3;
const int BUTTON=2;
  int HUMEDAD=A0;
int SENSOR;

//int isPressed=TRUE;


void setup()
{
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  pinMode(PIN_LED5, OUTPUT);
  pinMode(PINBUZZ, OUTPUT);
  pinMode(HUMEDAD, INPUT);
  pinMode(BUTTON, INPUT);
  
  
  Serial.begin(9600);
  
}

void loop()
{
  Serial.print("boton: ");
  Serial.println(BUTTON);
  int SENSOR=analogRead(HUMEDAD);
  Serial.print("valor: ");
  Serial.println(SENSOR);
  
 //ENCIENDE LAS LUCES 
  if (SENSOR>0&&SENSOR<175){
    digitalWrite(PIN_LED1, HIGH);}
  
  if (SENSOR>175&&SENSOR<350){
    digitalWrite(PIN_LED2, HIGH);}
  
  if (SENSOR>350&&SENSOR<525){
    digitalWrite(PIN_LED3, HIGH);}
  
  if (SENSOR>525&&SENSOR<700){
    digitalWrite(PIN_LED4, HIGH);}
  
  if (SENSOR>700&&SENSOR<875){
    digitalWrite(PIN_LED5, HIGH);}
  
//ACTIVA LA ALARMA CON EL 20%  
  if(SENSOR<175){
    tone(PINBUZZ,1000, 100);
    analogWrite(PINBUZZ, HIGH);
    delay(1000);
    
    /*analogWrite(PINBUZZ, HIGH);
    delay(5000);*/
  }

  
  if(SENSOR>176){
  analogWrite(PINBUZZ, LOW);}
  
  //ACTIVA ALARMA CON EL 80%
  if(SENSOR>700){
    tone(PINBUZZ,1500, 1500);
    analogWrite(PINBUZZ, HIGH);
    delay(2000);
  }
  
  if(SENSOR<699){
  analogWrite(PINBUZZ, LOW);}
}


//DESACTIVAR CON BOTON
