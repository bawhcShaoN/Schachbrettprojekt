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

void Dame(int f, int *waag1,int *senk1, int *waag,int *senk, int *lopo){
  int k=senk[f];
     if((waag[f]!=waag1[f] and senk[f]==senk1[f]) or (senk[f]!=senk1[f] and waag[f]==waag1[f]) or (senk[f]!=senk1[f] and waag1[f]!=waag[f])){     
     if(waag[f]!=waag1[f] and senk[f]==senk1[f]){
       if(waag1[f]<=waag[f]){
        for(int i=waag1[f]+1; i<=waag[f];i++){
          for(int j=0; j<=31 ;j++){
            if(waag[j]==i and j!=f){
              Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
            }
          }
        }
        if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 1");
        }
      }
      
      else if(waag1[f]>=waag[f]){
        for(int i=waag1[f]; i<=waag[f];i--){
          for(int j=0; j<=31 ;j++){
            if(waag[j]==i and j!=f){
              Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
            }   
          }
        }
        if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 2");
        }
      }
      /*else {
        /*if(senk[geschlagene_Figur]==senk[f] and waag[geschlagene_Figur]==waag[f]){
          //Figur geschlagene Figur wurde von Figur f geschlagen
        }
        //else{
          Serial.println("Figur ist Rechtmäßig gezogen 1");
          i[1]++;
        //}
      }*/
    }
    if(waag[f]==waag1[f] and senk[f]!=senk1[f]){
      if(senk1[f]<=senk[f]){
        for(int i=senk1[f]; i<=senk[f];i++){
          for(int j=0; j<=31 ;j++){
            if(senk[j]==i and j!=f){
              Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
            }
          }
        }
        if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 3");
        }
      }
      else if(senk1[f]>=senk[f]){
        for(int i=senk1[f]; i<=senk[f];i--){
          for(int j=0; j<=31 ;j++){
            if(senk[j]==i and j!=f){
              Serial.println("Figur ist über eine andere Gesprungen");
              lopo[0]=2;
            }
          }
        }
        if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 4");
        }
      }  
      
    }
    
    else if(waag[f]!=waag1[f] and senk[f]!=senk1[f]){
    if(waag1>=waag and senk<=senk1){
        for(int i=waag1[f]; i<=waag[f];i--){
            k++;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==k and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
                lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 5");
        }
       }
     else if(waag1>waag and senk>senk1){
        for(int i=waag[f]; i<=waag1[f];i--){
            k--;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==k and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
                lopo[0]=2;
              }
            } 
         } 
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 6");
        }       
      }
      else if(waag1<waag and senk>senk1){
        for(int i=waag[f]; i<=waag1[f];i--){
            k--;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==k and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
                lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 7");
        }
      }
      else if(waag1<waag and senk<senk1){
        for(int i=waag[f]; i<=waag1[f];i--){
            k++;
            for(int j=0; j<=31 ;j++){
              if(waag[j]==i and senk1[j]==k and j!=f){
                Serial.println("Figur ist über eine andere Gesprungen");
                lopo[0]=2;
              }
            } 
         }
         if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 8");
        }
      }
    
     //else {
        /*if(senk[geschlagene_Figur]==senk[f] and waag[geschlagene_Figur]==waag[f]){
          //Figur geschlagene Figur wurde von Figur f geschlagen
        }*/
        //else{
        //  Serial.println("Figur ist Rechtmäßig gezogen 3");
          
        //}
      }
     }      
     else{
        Serial.println("Figur ist falsch gefahren");
        
     }
     
 }
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
  senk[f]=2;
  waag[f]=6;
  lopo[0]=0;
  Dame( f, waag1, senk1,  waag, senk, lopo);
  Serial.println(lopo[0]);
}
