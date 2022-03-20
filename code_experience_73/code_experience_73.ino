/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
#include <DFRobot_TFmini.h>
SoftwareSerial mySerial(12, 13); // RX, TX
DFRobot_TFmini  TFmini;
uint16_t distance,strength;
void setup(){
    Serial.begin(115200);
    TFmini.begin(mySerial);
}
void loop(){
    if(TFmini.measure()){                     
        distance = TFmini.getDistance();      
        strength = TFmini.getStrength();    
        Serial.print("Distance = ");
        Serial.print(distance);
        Serial.println("cm");
        Serial.print("Strength = ");
        Serial.println(strength);
        delay(500);
    }
    delay(500);
}
