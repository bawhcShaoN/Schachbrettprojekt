#include <TimerOne.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <MFRC522.h>
/*
#define RST_PIN   9     // SPI Reset Pin
#define SS_PIN    10    // SPI Slave Select Pin
 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Instanz des MFRC522 erzeugen
*/
//Deklariere Pins für Display
#define TFT_CS 10
#define TFT_MISO 19 
#define TFT_RST 22
#define TFT_MOSI 23  
#define TFT_SCLK 18

//
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,TFT_DC,TFT_RST);

//#include <Fonts/FreeSerif18pt7b.h> //Schriftart auswählen

int TIMER1_ISR_FLAG=0;
//int tmax=0;//max. Zeit die vergehen soll
//int dt=1;
int t=0;//vergehende zeit
int t1=0;//vergehende zeit
int m=0;
int s=0;
int h=0;
void Timer1_ISR(){
  TIMER1_ISR_FLAG=1;
}

void setup(void) {
  // put your setup code here, to run once:
 tft.initR(INITR_GREENTAB);
 //tft.fillScreen(ST7735_BLACK);//Hintergrund
 //tft.setTextWrap(false);//Damit Text nicht in nächster Zeile Weitergeht
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 pinMode(4,INPUT);
 
 Serial.begin(9600);
 Timer1.initialize(1000000);
 Timer1.attachInterrupt(Timer1_ISR);
// mfrc522.PCD_Init();  // Initialisiere MFRC522 Lesemodul
 //tft.fillScreen(ST7735_BLACK);
          
}
int Poti=0;
int j=0;
int m1=0;
int s1=0;

int Zeit=s+(m*60), Zeit1=0;
int Z=0, Z1=0;
int l=0, i=0;
int k=0, g=0;
int Zustand=0, Zustand1=0;
int waagrecht=1;
int senkrecht=1;
int sensorValue=0;
void loop() {
  // put your main code here, to run repeatedly:
    //Potiwert wird eingelesen
  if(i<=3){
  sensorValue=analogRead(A1);
  if(i==0){
  s=map(sensorValue, 0, 681, 0, 59);
  Serial.println("Sekunde");
  Serial.println(s);
  Zustand=digitalRead(6);
  if(Zustand==HIGH){
    i=1;
  }}
  if(i==1){
    if(t==0){
    delay(1000);t=1;}
    m=map(sensorValue, 0, 1023, 0, 90);
    Serial.println("Minute");
    Serial.println(m);
    Zustand=digitalRead(6);
    if(Zustand==HIGH){
      i=2;
    }
  }
  if(i==2){
  s1=map(sensorValue, 0, 1023, 0, 90);
  Serial.println("Sekunde1");
  Serial.println(s1);
  Zustand=digitalRead(5);
  if(Zustand==HIGH){
    i=3;
    digitalWrite(4,HIGH);
  }
  }
  if(i==3){
  m1=map(sensorValue, 0, 1023, 0, 90);
  Serial.println("Minute1");
  Serial.println(m1);
  Zustand=digitalRead(5);
  if(Zustand==HIGH){
    i=4;
    digitalWrite(4, LOW);
  }}
  String stringmin=String(m);
  String stringsek=String(s);
  String stringmin1=String(m1);
  String stringsek1=String(s1);
  String stringone=String("   "+stringmin+":"+stringsek+"       "+stringmin1+":"+stringsek1);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.setCursor(0,60);
  tft.println(stringone);
  }
    if(i==4){
      if(TIMER1_ISR_FLAG==1){
        TIMER1_ISR_FLAG=0;
        t1=t;
        t=t+1;
        
        if(t=t1+1){ 
          //Serial.println(Zeit);         
          Zeit--;
          if(k==0){
          Zustand=digitalRead(2);
          if(Zustand == HIGH){
             g=0;
             k=1;
          }
          else{
              s--;
          }}
          if(k==1){
          Zustand1=digitalRead(3);
          if(Zustand1 == HIGH){
              g=1;
              k=0;
          }
          else{
            s1--;
          }
          }
          
          if(s==0){
            if(m==0){
            m--;}
            s=59;
          }
          if(s1==0){
            if(m1==0){
            m1--;}
            s1=59;
          }
          
          String stringmin=String(m);
          String stringsek=String(s);
          String stringmin1=String(m1);
          String stringsek1=String(s1);
          String stringone=String("   "+stringmin+":"+stringsek+"       "+stringmin1+":"+stringsek1);
          
          //String string4="Hello World";
          //String string5;
          
          tft.fillScreen(ST7735_BLACK);
          tft.setTextColor(ST7735_RED);
          tft.setTextSize(1);
          tft.setCursor(0,10);
          tft.println(stringone);
          
          /*
            for(int b=0; b<8;b++){
              k=b/2;
              if(k%2==1){digitalWrite(7,HIGH);}else{digitalWrite(7, LOW);}
              k=k/2;
              if(k%2==1){digitalWrite(6,HIGH);}else{digitalWrite(6, LOW);}
              k=k/2;
              if(k%2==1){digitalWrite(5,HIGH);}else{digitalWrite(5, LOW);}
              if(b=0){
                  String string3(m1);
                  String string4(s1);
                  String string5(string1 + ":" + string2);
                  tft.fillScreen(ST7735_BLACK);
                  tft.setTextColor(ST7735_WHITE);
                  tft.setTextSize(2);
                  tft.setCursor(0,0);
                  tft.println(string5);
              }
              if(b=1){
                  String string3(m1);
                  String string4(s1);
                  String string6(string3 + ":" + string4);
                  tft.fillScreen(ST7735_BLACK);
                  tft.setTextColor(ST7735_WHITE);
                  tft.setTextSize(2);
                  tft.setCursor(0,0);
                  tft.println(string5);
              }
              if(b>=2 and b>=5){
                 if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() ) {
                   Serial.print("Gelesene UID:");
                   for (byte i = 0; i < mfrc522.uid.size; i++) {
                    // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
                    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                    Serial.print(mfrc522.uid.uidByte[i], DEC);
                   } 
                   Serial.println(); 
                           
                // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
                   mfrc522.PICC_HaltA();
                   delay(1000);
                 }
                 if(b>=2 and b<=3){
                    senkrecht=1;
                    waagrecht++;
                    if(waagrecht=2){
                      waagrecht=1;
                    }
                 }
                 if(b>=4 and b<=5){
                    senkrecht=2;
                    waagrecht++;
                    if(waagrecht=2){
                      waagrecht=1; 
                    }
                 }
                 //-- Vergleich mit gespeicherten Werten
                 for(j=0;j<=32;j++){
                  for(int d=0;d<=16;d++){
                    if(mfrc522.uid.uidByte[d]=f[j][d]){
                      e++;
                      if(e=15){
                        senk[j]=senkrecht;
                        waag[j]=waagrecht;
                        e=0;
                      }
                    }
                  }      
                }
              }
              if(b=7){
                for(j=0;j<=32;j++){
                  if(senk1[j]!=senk[j] or waag1[j]!=waag[j]){
                    
                    tft.fillScreen(ST7735_BLACK);
                    tft.setTextColor(ST7735_WHITE);
                    tft.setTextSize(2);
                    tft.setCursor(0,0);
                    tft.println();
                  }
                }
              }
        }*/
      }
    }}
 }
