# TFmini-Sensor

Chapter 3 code_Project_73 The second part 2 of "The Arduino World Book" code_Project_73
 
- code_Project_73
-  By:Farkad Adnan فرقد عدنان - 
 -E-mail: farkad.hpfa95@gmail.com 
-inst : farkadadnan 
- #farkadadnan , #farkad_adnan , فرقد عدنان# 
- FaceBook: كتاب عالم الاردوينو 
- inst : arduinobook
1. #كتاب_عالم_الاردوينو
2. #كتاب_عالم_الآردوينو

* facebook : https://www.facebook.com/profile.php?id=100002145048612
* instagram:  https://www.instagram.com/farkadadnan/
* linkedin : https://www.linkedin.com/in/farkad-adnan-499972121/

 <p>
 <a href='https://mobile.twitter.com/farkadadnan'>
        <img alt="Twitter Follow" src="https://img.shields.io/twitter/follow/farkadadnan?label=%40farkadadnan&style=social" alt='Twitter' align="center"/>
    </a>
</p>

![images (1)](https://user-images.githubusercontent.com/35774039/159183585-7de41a33-328e-4259-92da-8e417aa2283c.jpg)
![51wQEv0OrdL _AC_SY355_](https://user-images.githubusercontent.com/35774039/159183625-a31ff44e-857d-4707-b5cb-06bc94d706e0.jpg)



# Description
> 
يعتب هذا الحساس هو  مكتشف نطاق ليزر أحادي الاتجاه يعتمد على تقنية وقت الرحلة (ToF:Time-Of-Flight)  وهو يتألف من أجهزة بصرية وإلكترونية خاصة، والتي تدمج خوارزمية تكيفية لبيئة التطبيقات الداخلية والخارجية. لها جسم صغير وأداء عالي في قياس المسافة.
> This sensor is a unidirectional laser range finder based on time-of-flight technology (ToF:Time-Of-Flight) which consists of special optical and electronic devices, which integrate an adaptive algorithm for indoor and outdoor application environment. It has a small body and a high performance in measuring distance.
![14](https://user-images.githubusercontent.com/35774039/159183646-658a7524-4beb-4a2f-8f07-4639e259f38a.JPG)
![5](https://user-images.githubusercontent.com/35774039/159183655-aa51aaa4-847b-4dfa-91ab-7a8bd556d607.JPG)

# Parameters
![aasasas](https://user-images.githubusercontent.com/35774039/159183712-63d947eb-ca22-4a09-954a-c8c2275a1971.png)
- .Operating range based on a standard whiteboard with reflectivity 90% in indoor condition
- .The distance measurement here is absolute accuracy, and the specific repeat accuracy will be described in the next section 2.4.
- . 3.6°is the theoretical value, from which the actual value will be different. The theoretical divergence angle is 6°.
- . Only frame rates meeting the formula–1000/n (n is positive integer) can be set. The default frame rate is 100Hz.
![6](https://user-images.githubusercontent.com/35774039/159183829-24c5ee22-f5d0-44ce-ad41-9772be200174.jpg)

# code_Project_73

```
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
```

# Distance Measurement Characteristics
> مع تحسين مسار الضوء ، يقلل TFmini Plus من تأثير البيئة الخارجية على أداء قياس المسافة. على الرغم من ذلك ، قد لا يزال نطاق قياس المسافة يتأثر بكثافة إضاءة البيئة .  
> With light path optimization, TFmini Plus reduces the influence of the external environment on distance measurement performance. Despite this, the distance measurement range may still be affected by the illumination intensity of the environment.
> ![111111111](https://user-images.githubusercontent.com/35774039/159186788-3a55b678-29ae-4b32-b63d-bfd5e0a6b937.png)

Represents the detection blind zone of TFmini Plus, 0-10cm, within which the output data is unreliable.
Represents the operating range of TFmini Plus detecting black target with 10% reflectivity, 0.1-5m.
Represents the operating range of TFmini Plus detecting white target with 90% reflectivity, 0.1-12m.
Vertical Coordinates: Represents the radius of light spot for TFmini Plus at the different distances. The diameter of light spot depends on the FOV of TFmini Plus (the term of FOV generally refers to the smaller value between the receiving angle and the transmitting angle), which is calculated as follows: d= D ∙ tanβ In the formula above, d is the diameter of light spot; D is detecting range; β is the the value of the receiving angle of TFmini Plus, 3.6°.  
# For more information about the sensor
https://cdn-shop.adafruit.com/product-files/3978/3978_manual_SJ-PM-TFmini-T-01_A03ProductManual_EN.pdf
