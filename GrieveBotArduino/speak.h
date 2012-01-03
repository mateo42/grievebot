//Define the Pin Numbers of the Voicebox shield for the sketch.

//#define RDY  13
#define RES  3
#define SPK  4

//Pin 2 of the shield should be wired to the TTS256 chip.
#define txPin 2

//Create a SoftSerial Object to send strings to the TTS256 chip.
SoftwareSerial speakjet = SoftwareSerial(0, txPin);

void speakjet_init(){
   //Configure the pins for the SpeakJet module
  pinMode(txPin, OUTPUT);
  pinMode(SPK, INPUT);
  
  //Set up a serial port to talk from Arduino to the SpeakJet module on pin 3.
  speakjet.begin(9600);    
    
  //Configure the Ready pin as an input
  //pinMode(RDY, INPUT);
  
  //Configure Reset line as an output
  pinMode(RES, OUTPUT);
         
  //All I/O pins are configured. Reset the SpeakJet module
  digitalWrite(RES, LOW);
  delay(100);
  digitalWrite(RES, HIGH);
  delay(1000); 
  //digitalWrite(13, LOW);
}

void speak(String &m){
  
  speakjet.flush();
  Serial.print("Speaking: ");
  
  speakjet.println(m);

  // Wait for it to finish speaking
  while(digitalRead(SPK)) {
    Serial.print('.');
    delay(300);
  }
  
  delay(300);
  Serial.println(m);
}

