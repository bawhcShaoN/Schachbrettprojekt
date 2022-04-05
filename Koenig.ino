void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  König();
}

void Koenig(){
  //Schach
  int z=0;
  if(abs(senk1[f]-senk[f])>=2 and abs(waag1[f]-waag[f])>=2){
    //fehler   
  }
  else{
    //Legal
  }
}

void Rochade(){

//Zwei Figuren 
 if(senk1[f1] > senk1[f]){
    for(int i=senk1[f1]; i<senk1[f]; i--){
       Schach_o_Schachmatt();
       for(int j=0; j<=32;j++){
          if(senk1[j]==senk1[i] and waag1[i]==waag1[j] and F[j]!=1 and F[j]!=2){
              //illegal
          }
       }
   }
   if(){//Wenn bisher legal
     if(){
        //Wenn variable = 1 könig also nicht im schach steht passt
     }
     if(senk[f]==senk1[f]-2 and senk[f]==senk1[f1]-1){
        //Figur ist auf richtiges Feld gezogen
        //legal
     }
     else{
        //Figur ist auf flasches Feld gezogen
     }
   }
}
 if(senk1[f1] < senk1[f]){
    for(int i=senk1[f1]; i<senk[f]; i++){
        Schach_o_Schachmatt();
        for(int j=0; j<=32;j++){
          if(senk1[j]==senk1[i] and waag1[i]==waag1[j] and F[j]!=1 and F[j]!=2){
              //illegal
              
          }
   if(){//Wenn bisher legal
     if(){
        //Wenn variable = 1 könig also nicht im schach steht passt
     }
     if(senk[f]==senk1[f]-2 and senk[f]==senk1[f1]-1){
        //Figur ist auf richtiges Feld gezogen
        //legal
     }
     else{
        //Figur ist auf flasches Feld gezogen
     }
   }
  }
}
