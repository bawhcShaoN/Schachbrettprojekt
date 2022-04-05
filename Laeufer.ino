void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}
  int check=0;
  int f=4;
  int waag[32];
  int senk[32];
  int waag1[32];
  int senk1[32];
  int lopo[1];
void loop() {
  // put your main code here, to run repeatedly:
for(int i=0; i<=32;i++){
      senk1[i]=0;
      waag1[i]=0;
      senk[i]=0;
      waag[i]=0;
  }
  senk1[f]=4;
  waag1[f]=4;
  senk[f]=6;
  waag[f]= 2;
  lopo[0]=0;
  Laeufer( f, waag1, senk1,  waag, senk, lopo);
  Serial.println(lopo[0]);
}


void Laeufer(int f, int *waag1,int *senk1, int *waag,int *senk, int *lopo){
    int k[13];
    int g[13];
    int u=senk1[f];
    int v=waag1[f];
    int h=0;
    int t=0;
    int z=0;
    int o=0;
    if(waag[f]==waag1[f] or senk[f]==senk1[f]){
        Serial.println("Figur ist nicht Quer gefahren, Illegaler Zug");
    }
    else{
      for(int i=0;i<=3;i++){   
        u=senk1[f];
        v=waag1[f];
          if(i==0){
            for(int j=0; j<=7;j++){
              h++;
              u++;
              v++;
              k[h]=u;
              g[h]=v;
              if(u==0 or v==7 or u==7 or v==0){
                  j=7;
              }
            }
          }
          if(i==1){
            for(int j=0; j<=7;j++){
              h++;
              u++;
              v--;
              k[h]=u;
              g[h]=v;
              if(u==0 or v==7 or u==7 or v==0){
                  j=7;
              }
            }
          }
          if(i==2){
           for(int j=0; j<=7;j++){
              h++;
              u--;
              v++;
              k[h]=u;
              g[h]=v;
              if(u==0 or v==7 or u==7 or v==0){
                  j=7;
              }
            }
          }
          if(i==3){
           for(int j=0; j<=7;j++){
              h++;
              u--;
              v--;
              k[h]=u;
              g[h]=v;
              if(u==0 or v==7 or u==7 or v==0){
                  j=7;
              }
           }
          }
      }
      o=sizeof(k);
      for(int i=0; i<=o;i++){
        if(senk[f]==k[i] and waag[f]==g[i]){
         t++;
        }
      }
      if(t!=1){
        Serial.println("Zug war nicht rechtmäßig");
      }
      else{
      
      if(waag1[f]>waag[f] and senk[f]<senk1[f]){
        for(int i=waag1[f]; i<=waag[f];i--){
            z++;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==z and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 5");
        }
       }
      else if(waag1[f]>waag[f] and senk[f]>senk1[f]){
        for(int i=waag[f]; i<=waag1[f];i--){
            z--;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==z and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 6");
        }        
      }
      else if(waag1[f]<waag[f] and senk[f]>senk1[f]){
        for(int i=waag[f]; i<=waag1[f];i--){
            z--;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==z and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 7");
        }
      }
      else if(waag1[f]<waag[f] and senk[f]<senk1[f]){
        for(int i=waag[f]; i<=waag1[f];i--){
            z++;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==z and j!=f){
               Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 8");
        }
      }
    /*
    else 
      if(senk[geschlagene_Figur]=senk[f] and waag[geschlagene_Figur]=waag[f]){
          //Figur geschlagene Figur wurde von Figur f geschlagen
      }
      else if{
        //Zug war rechtmäßig
      }
    }*/ 
}
}
}
