//시리얼통신으로 받은 숫자를 세그먼트로 표시//

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  


 //   int ar= int(Serial.read());
        int(ar) = int(Serial.read());
  
    if(ar==48)
  {
      digitalWrite(13,1); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,1); // d
      digitalWrite(9,1); // e
      digitalWrite(8,1); // f
      digitalWrite(7,0); // g
  }
  
  if(ar==49)
  {
      digitalWrite(13,0); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,0); // d
      digitalWrite(9,0); // e
      digitalWrite(8,0); // f
      digitalWrite(7,0); // g
  }

   if(ar==50)
   {
      digitalWrite(13,1); // a
      digitalWrite(12,1); // b
      digitalWrite(11,0); // c
      digitalWrite(10,1); // d
      digitalWrite(9,1); // e
      digitalWrite(8,0); // f
      digitalWrite(7,1); // g
   }
      if(ar==51)
    
   {
      digitalWrite(13,1); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,1); // d
      digitalWrite(9,0); // e
      digitalWrite(8,0); // f
      digitalWrite(7,1); // g
      
   }
     if(ar==52)
     
   {
      digitalWrite(13,0); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,0); // d
      digitalWrite(9,0); // e
      digitalWrite(8,1); // f
      digitalWrite(7,1); // g
      
   }
      if(ar==53)
      
   {
      digitalWrite(13,1); // a
      digitalWrite(12,0); // b
      digitalWrite(11,1); // c
      digitalWrite(10,1); // d
      digitalWrite(9,0); // e
      digitalWrite(8,1); // f
      digitalWrite(7,1); // g
    
   }
      if(ar==54)
      
   {
      digitalWrite(13,1); // a
      digitalWrite(12,0); // b
      digitalWrite(11,1); // c
      digitalWrite(10,1); // d
      digitalWrite(9,1); // e
      digitalWrite(8,1); // f
      digitalWrite(7,1); // g
      
   }
     if(ar==55)
      
   {
      digitalWrite(13,1); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,0); // d
      digitalWrite(9,0); // e
      digitalWrite(8,1); // f
      digitalWrite(7,0); // g
      
   }
      if(ar==56)
     
   {
      digitalWrite(13,1); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,1); // d
      digitalWrite(9,1); // e
      digitalWrite(8,1); // f
      digitalWrite(7,1); // g
   
   }
      if(ar==57)
    
   {
      digitalWrite(13,1); // a
      digitalWrite(12,1); // b
      digitalWrite(11,1); // c
      digitalWrite(10,0); // d
      digitalWrite(9,0); // e
      digitalWrite(8,1); // f
      digitalWrite(7,1); // g
     
   }


}
