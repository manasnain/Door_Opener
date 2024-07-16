#include <SPI.h>
#include <MFRC522.h>
#include <vector>
#define SS_PIN 15 //D8
#define RST_PIN 2 //D4
MFRC522 mfrc522(SS_PIN, RST_PIN);
int mosfet = 1;
int buzzer = 12;
std::vector<String> card_list2 = {"040646F2AD6F80"};
int total_card;
String card_num;
void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println();
}
void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()){
    return;
  } 
  card_num = getCardNumber();
  showData();
}

String getCardNumber(){
  String UID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    UID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    UID += String(mfrc522.uid.uidByte[i], HEX);
  }
  UID.toUpperCase();
  return UID;
}

void Opener(){
  digitalWrite(mosfet,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(4000);
  digitalWrite(buzzer,LOW);
  digitalWrite(mosfet,LOW);
}



void showData(){

  boolean user_found = false;
  
  if (card_num.equals("040646F2AD6F80")){
    Serial.print("override addition");
    delay(2000);
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      String addition = getCardNumber();
      if (!addition.equals("040646F2AD6F80")){
        card_list2.push_back(addition);
        Serial.print("Added card ID: ");
        Serial.println(addition);
        Serial.println("------------");
      }
    }
  }
  total_card = card_list2.size();
  for(int i=0;i<total_card;i++){
    String check_num = card_list2[i];
    if(card_num.equals(check_num)){
      user_found = true;
      Serial.print("registered Card ID : ");
      Serial.println(card_num);
      Serial.println("------------");
      Opener();
    }  
  }
  if(user_found == false){
    Serial.print("Card ID : ");
    Serial.print(card_num);
    Serial.println(" has not registered.");
    Serial.println("------------");
  }
  delay(400);
}


