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
  waag[f]= 3;
  lopo[0]=0;
  Pferd( f, waag1, senk1,  waag, senk, lopo);
  Serial.println(lopo[0]);
}

void Pferd(int f, int *waag1,int *senk1, int *waag,int *senk, int lopo){
    if(senk[f]==senk1[f]-2 and waag[f]==waag1[f]+1){
      Serial.println("Zug ist legal");
    }
    else if(senk[f]==senk1[f]-2 and waag[f]==waag1[f]-1){
      Serial.println("Zug ist legal");
    }
    else if(senk[f]==senk1[f]+2 and waag[f]==waag1[f]+1){
      Serial.println("Zug ist legal");
    }
    else if(senk[f]==senk1[f]+2 and waag[f]==waag1[f]-1){
      Serial.println("Zug ist legal");
    }
    else if(waag[f]==waag1[f]+2 and senk[f]==senk1[f]-1){
      Serial.println("Zug ist legal");
    }
    else if(waag[f]==waag1[f]+2 and senk[f]==senk1[f]+1){
      Serial.println("Zug ist legal");
    }
    else if(waag[f]==waag1[f]-2 and senk[f]==senk1[f]-1){
      Serial.println("Zug ist legal");
    }
    else if(waag[f]==waag1[f]-2 and senk[f]==senk1[f]+1){
      Serial.println("Zug ist legal");
    }
    else{
      Serial.println("Zug ist illegal");
    }
    
}
