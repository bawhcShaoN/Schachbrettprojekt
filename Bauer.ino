#if CONFIG_FREERTOS_UNICORE
    static const BaseType_t app_cpu=0;
#else
    static const BaseType_t app_cpu=1;
#endif

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS 14
#define TFT_dc 19
#define TFT_mosi 23
#define TFT_sclk 18
#define TFT_rst 22
//static TaskHandle_t task_1 = NULL;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,TFT_dc,TFT_mosi,TFT_sclk,TFT_rst);
static TaskHandle_t task_1 = NULL;
void Bauernumwandlung(int f);
void Bauer(int f, int *waag1,int *senk1, int *waag,int *senk, int *lopo, int *waago, int *senko, int geschlagene_Figur, int *Figur);

int Figur[32];
void setup() {
  // put your setup code here, to run once:
  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(15, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
   tft.initR(INITR_GREENTAB);
  Serial.begin(115200);
  for(int i=9;i<=16;i++){
    Figur[i]=1;
  }
  for(int i=25;i<=32;i++){
    Figur[i]=1;
  }
  Figur[5]=2;
  Figur[21]=2;
  Figur[2]=3;
  Figur[7]=3;
  Figur[18]=3;
  Figur[23]=3;
  Figur[3]=4;
  Figur[6]=4;
  Figur[19]=4;
  Figur[22]=4;
  Figur[4]=5;
  Figur[20]=5;
  Figur[8]=6;
  Figur[1]=6;
  Figur[17]=6;
  Figur[24]=6;
  xTaskCreatePinnedToCore(startTask1,
                          "Task 1",
                          8192,
                          NULL,
                          1,
                          &task_1,
                          app_cpu);
 
}
  int check=0;
  int f=9;
  int waag[32];
  int senk[32];
  int waag1[32];
  int senk1[32];
  int waago[32];
  int senko[32];
  int lopo[1];
  int geschlageneFigur=0;
  int z[1];

  
void loop() {
  // put your main code here, to run repeatedly:

}
void startTask1(void *parameter){
  while(1){
  for(int i=0; i<=32;i++){
      senk1[i]=0;
      waag1[i]=0;
      senk[i]=0;
      waag[i]=0;
  }
  
  senko[f]=1;
  waago[f]= 1;
  lopo[0]=0;
  geschlageneFigur=5;
  senk1[f]=5;
  waag1[f]=4;
  senk[f]=4;
  waag[f]= 5;
  waag[geschlageneFigur]=4;
  senk[geschlageneFigur]=4;
  waago[geschlageneFigur]=6;
  senko[geschlageneFigur]=4;
  if(Figur[f]==1){
  Bauer( f, waag1, senk1,  waag, senk, lopo, waago, senko, geschlageneFigur, Figur, z);
  }
  Serial.println(lopo[0]);
  Serial.println(z[0]);  
  Serial.println(Figur[f]);
}}
int Zustand=0;
int Zustand1=0;
int Zustand2=0;
//float i=0;
//float i1=0;
//float i2=0;

void Bauernumwandlung(int f){
       int i=1;
       int k=0;
       int j=0;
       char w[6]={' ',' ','-',' ',' ',' '};
        
        String string2;
        String stringone="Dame";
        String stringtwo="Turm";
        String stringthree="Pferd";
        String stringfour="Laeufer";
        //String string = "Moin";
        Serial.print("Herold");
        while(i!=8){        
        k=i;
        String stringeins="Zu welcher Figur sollder Bauer umgewandelt werden?";
        String stringone="Dame";
        String stringtwo="Turm";
        String stringthree="Pferd";
        String stringfour="Laeufer";
        
       Zustand=digitalRead(33);
        if(Zustand==HIGH){
          if(i==6){
            i=1;
          }
          i++;
        }
        Zustand1=digitalRead(32);
        if(Zustand1==HIGH){
            if(i==1){
              i=6;
            }
            i--;
        }
        Zustand2=digitalRead(35);
        if(Zustand2==HIGH){
            Figur[f]=i;
            
            
        if(i==2){
           string2="die Dame";
        }
        if(i==3){
           string2=" den Turm";
        }
        if(i==4){
           string2="das Pferd";
        }
        if(i==5){
           string2="den Laeufer";
        }
        String string1=String("Sie haben sich fuer "+string2+" entschieden");
        digitalWrite(15, HIGH);
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        tft.fillScreen(ST7735_BLACK); 
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(0,10);
        tft.println(string1);
        i=8;
        }
        if(i==6){
          i--;
        }
        
        if(i==1){
          i++;
        }
        w[2]=' ';
        w[3]=' ';
        w[4]=' ';
        w[5]=' ';
        w[i]='-';
        String ersteStelle=String(w[2]);
        String zweiteStelle=String(w[3]);
        String dritteStelle=String(w[4]);
        String vierteStelle=String(w[5]);
        if(k==(i+1) or k==(i-1) or j!=1){
        String string=String(stringeins+"                                     "+stringone+ersteStelle+"                                     "+stringtwo+zweiteStelle+"                                     "+stringthree+dritteStelle+"                                    "+stringfour+vierteStelle);
        Serial.print(i);
        digitalWrite(15, HIGH);
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        tft.fillScreen(ST7735_BLACK); 
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(0,10);
        tft.println(string);
        j=1;}}
        
}

        


void Bauer(int f, int *waag1,int *senk1, int *waag,int *senk, int *lopo, int *waago, int *senko, int geschlagene_Figur, int *Figur, int *z){
    //i=micros();
    int i=0;
    if(waago[f]==1){
     
        //lopo=8;
     
     if(waag1[f]==waago[f]){
          if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]){//Steht Figur auf Feld der geschlagenen Figur 
              if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]-1){ 
                  Serial.println(" Es wurde Figur auf waag[f]senk[f] geschlagen 1");
              }
              else if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]+1){
                  Serial.println(" Figur wurde auf waag[f]senk[f] geschlagen 2");
              }
              else{
                z[0]=1;
                Serial.println("Unrechtmaessig");
              }
          }
          else if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]){
            Serial.println("Figur ist nur um ein Feld vorgerückt");
            z[0]=2;
          }
          else if(waag[f]==waag1[f]+2){
             for(int i=0;i<=31;i++){
                if(waag[f]+1==waag[i] and senk[f]==senk[i]){
                    z[0]=1;
                    Serial.println("Figur ist über ander gesprungen");
                    lopo[0]=1;
                }
            }
            if(lopo[0]!=1){
              z[0]=2;
              Serial.println("Figur ist um zwei Felder vorgerückt");
            }
          }
          else {
            z[0]=1;
            Serial.println("Zug war unrechtmäßig");
          }
        }
        else {
          if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]){
            if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]-1){ 
              Serial.println(" Es wurde Figur auf waag[f]senk[f] geschlagen");
            }
            else if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]+1){
              Serial.println("Figur wurde auf waag[f]senk[f] geschlagen");
            }
          }
          else if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]-1){ 
            Serial.println("POINT");
            if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]+1){
              Serial.println("POINT1");
              if(senko[geschlagene_Figur]==senk[geschlagene_Figur] and waago[geschlagene_Figur]==waag[geschlagene_Figur]+2){
                Serial.println("En Passant");
                z[0]=3;
              }
            }
          }
          else if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]+1){
            Serial.println("POINT2");
            if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]+1){
              Serial.println("POINT3");
              if(senko[geschlagene_Figur]==senk[geschlagene_Figur] and waago[geschlagene_Figur]==waag[geschlagene_Figur]+2){
                Serial.println("En Passant");
                z[0]=3;
              }
            }
          }
          else if(waag[f]==waag1[f]+1 and senk[f]==senk1[f]){
            Serial.println("Figur ist nur um ein Feld vorgerückt");
            z[0]=2;
          }
          else {
            z[0]=1;
            Serial.println("Zug war unrechtmäßig");
          }
        }
        if(waag[f]==7 and z[0]==2){
          Bauernumwandlung(f);
          Serial.print("Moin");
        }
    }
     
    
 if(waago[f]==6){
  
  if(senk1[f]==senko[f]){
       if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]){//Steht Figur auf Feld der geschlagenen Figur 
          if(waag[f]==waag1[f]-1 and senk[f]==senk1[f]-1){ 
              Serial.println(" Es wurde Figur auf waag[f]senk[f] geschlagen");
          }
          else if(waag[f]==waag1[f]-1 and senk[f]==senk1[f]+1){
            Serial.println("Figur wurde auf waag[f]senk[f] geschlagen");
          }
          }
          else if(waag[f]==waag1[f]-1){
            z[0]=2;
            Serial.println("Figur ist nur um ein Feld vorgerückt");
          }
          else if(waag[f]==waag1[f]-2){
             for(int i=0;i<=31;i++){
                if(waag[f]-1==waag[i] and senk[f]==senk[i]){
                    z[0]=1;
                    Serial.println("Figur ist über ander gesprungen");
                    lopo[0]=1;
                }
            }
            if(lopo[0]!=1){
              z[0]=2;
              Serial.println("Figur ist um zwei Felder vorgerückt");
            }
          }
          else {
            z[0]=1;
            Serial.println("Zug war unrechtmäßig");
          }
        }
        else {
          if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]){
            if(waag[f]==waag1[f]-1 and senk[f]==senk1[f]-1){ 
              Serial.println(" Es wurde Figur auf waag[f]senk[f] geschlagen");
            }
            else if(waag[f]==waag1[f]-1 and senk[f]==senk1[f]+1){
              Serial.println("Figur wurde auf waag[f]senk[f] geschlagen");
            }
          }
          else if(waag[f]==waag1[f]-1 and senk[f]==senk1[f]-1){ 
            if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]-1){
              if(senko[geschlagene_Figur]==senk[geschlagene_Figur] and waago[geschlagene_Figur]==waag[geschlagene_Figur]-2){
                z[0]=3;
                Serial.println("En Passant");
              }
            }
          }
          else if(waag[f]==waag1[f]-1 and senk[f]==senk1[f]+1){
            if(senk[f]==senk[geschlagene_Figur] and waag[f]==waag[geschlagene_Figur]-1){
              if(senko[geschlagene_Figur]==senk[geschlagene_Figur] and waago[geschlagene_Figur]==waag[geschlagene_Figur]-2){
                z[0]=3;
                Serial.println("En Passant");
              }
            }
          }
          else if(waag[f]==waag1[f]-1){
            z[0]=2;
            Serial.println("Figur ist nur um ein Feld vorgerückt");
          }
          else {
            z[0]=1;
            Serial.println("Zug war unrechtmäßig");
          }
      }
      if(waag[f]==0 and z[0]==2){
        Bauernumwandlung(f);
        Serial.print("Moin");
     }
   }
  // i1=micros();
   //i2=i1-i;
   //Serial.print(i2);
 
}
