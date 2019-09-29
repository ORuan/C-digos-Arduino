int esqFre = 13;
int esqTras = 12;
int direTras = 11;
int direFre = 10;
char estado = 'S';
 
void setup() {
Serial.begin(9600);
pinMode(esqFre, OUTPUT);   //left motors forward
pinMode(esqTras, OUTPUT);   //left motors reverse
pinMode(direTras, OUTPUT);   //right motors forward
pinMode(direFre, OUTPUT);   //right motors reverse

}
 
void loop() {
if(Serial.available()){
  estado = Serial.read();
}
 
if(estado == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(esqFre, HIGH);
  digitalWrite(esqTras, LOW);
  digitalWrite(direTras, LOW);
  digitalWrite(direFre, HIGH);
}

else if(estado == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(esqFre, LOW);
  digitalWrite(esqTras, LOW);
  digitalWrite(direTras, LOW);
  digitalWrite(direFre, HIGH);
}
 
else if(estado == 'S'){      //STOP (all motors stop)
  digitalWrite(esqFre, LOW);
  digitalWrite(esqTras, LOW);
  digitalWrite(direTras, LOW);
  digitalWrite(direFre, LOW);
}

else if(estado == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(esqFre, HIGH);
  digitalWrite(esqTras, LOW);
  digitalWrite(direTras, LOW);
  digitalWrite(direFre, LOW);
}
 
else if(estado == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(esqFre, LOW);
  digitalWrite(esqTras, HIGH);
  digitalWrite(direTras, HIGH);
  digitalWrite(direFre, LOW);
}

}
