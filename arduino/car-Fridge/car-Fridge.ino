int analogInput = A0;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0; //  
float R2 = 7500.0; // 
int value = 0;
const int LED_PIN = 7;
const int TEMPERATURE_PIN = A1;
const int TRESHOLD_UPPER = 60;
const int TRESHOLD_LOWER = 40;
const int TRESHOLD_LOWER_VOLTMETER = 13; 
const int TRESHOLD_UPPER_VOLTMETER = 20;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED_PIN,OUTPUT);
    pinMode(analogInput, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   
   if(vin >= TRESHOLD_LOWER_VOLTMETER && vin < TRESHOLD_UPPER_VOLTMETER){
    int Cels = analogRead(TEMPERATURE_PIN);
    if(Cels <= TRESHOLD_LOWER){
          digitalWrite(LED_PIN,LOW);
    }else if(Cels >=TRESHOLD_UPPER){
          digitalWrite(LED_PIN,HIGH);
    }
    Serial.println(Cels);
    }  
    delay(500);  
}
