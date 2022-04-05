void setup() {
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
       if(waag1[f]<waag[f]){
        for(int i=waag1[f]+1; i<=waag[f];i++){                            //1
          for(int j=0; j<=31 ;j++){                                       //2
            if(waag[j]==i and j!=f){                                      //3
              Serial.println("Figur ist über eine andere Gesprungen");
            }
          }
        }
        if(lopo[0]!=2){
           Serial.println("Figur ist Rechtmäßig gezogen 1");
        }
      }
      
      else if(waag1[f]>waag[f]){
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
}
