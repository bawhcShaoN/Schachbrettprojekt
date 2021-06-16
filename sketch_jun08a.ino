#include <SPI.h>
#include <MFRC522.h>
 
#define RST_PIN   9     // SPI Reset Pin
#define SS_PIN    10    // SPI Slave Select Pin
 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Instanz des MFRC522 erzeugen

const int switch_1 = ;
const int switch_2 = ;
const int switch_3 = ;
const int switch_4 = ;

void setup() {
  // Diese Funktion wird einmalig beim Start ausgeführt
  Serial.begin(9600);  // Serielle Kommunikation mit dem PC initialisieren
  SPI.begin();         // Initialisiere SPI Kommunikation
  mfrc522.PCD_Init();  // Initialisiere MFRC522 Lesemodul
  pinMode(switch_1, OUTPUT);
  pinMode(switch_2, OUTPUT);
  pinMode(switch_3, OUTPUT);
  pinMode(switch_4, OUTPUT);
}
 
void loop() {
  // Diese Funktion wird in Endlosschleife ausgeführt
 
  // Nur wenn eine Karte gefunden wird und gelesen werden konnte, wird der Inhalt von IF ausgeführt
  // PICC = proximity integrated circuit card = kontaktlose Chipkarte
 for(int i=0; i<4; i++){
  if(i==0){
      digitalWrite(switch_1, HIGH);
      digitalWrite(switch_2, HIGH);
      digitalWrite(switch_3, LOW);
      digitalWrite(switch_4, LOW);
    }
  if(i=1){
      digitalWrite(switch_1, HIGH);
      digitalWrite(switch_2, LOW);
      digitalWrite(switch_3, HIGH);
      digitalWrite(switch_4, LOW);
    }
  if(i=2){
      digitalWrite(switch_1, LOW);
      digitalWrite(switch_2, HIGH);
      digitalWrite(switch_3, LOW);
      digitalWrite(switch_4, HIGH);
    }
  if(i=3){
      digitalWrite(switch_1, LOW);
      digitalWrite(switch_2, LOW);
      digitalWrite(switch_3, HIGH);
      digitalWrite(switch_4, HIGH);
    }  
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() ) {
    Serial.print("Gelesene UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      
    } 
    Serial.println(); 
    
    // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
    mfrc522.PICC_HaltA();
    delay(1000);
  }
  }
}
