const int LED_PIN = 7;
const int TEMPERATURE_PIN = A1;
const int TRESHOLD_UPPER = 60;
const int TRESHOLD_LOWER = 40;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    int Cels = analogRead(TEMPERATURE_PIN);
    Serial.println(Cels);
    if(Cels <= TRESHOLD_LOWER){
          digitalWrite(LED_PIN,LOW);
    }else if(Cels >=TRESHOLD_UPPER){
          digitalWrite(LED_PIN,HIGH);
    }

}
