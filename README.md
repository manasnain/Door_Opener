# Door_Opener
Door opener for the door at the small workshop

PCB: [link to Altium365](https://eforce.365.altium.com/designs/4DC78BE3-F31A-49D6-B669-CB9EC259C5F4)

## ADDING CARDS

to add a card, log in to the access point:
ssid: Door_Opener
password: ''
Then head to http://192.168.4.1

Enter name and Card ID using the card reader
Click add card.

## DELETING CARDS

follow the same steps as adding a card, enter the card UID into the text box and click Delete card.

## IN CASE CHIP IS LOST
To make another chip/card the master chip. just add/replace the comparitor in line 50 of the code with the new chips ID and flash the ESP.

To find out what the chips ID is, tap it on the reader and check it out on the serial output.

"Card ID : YOUR_CARD_ID has not registered. 

------------"

  Heres the line you need to edit:
  
```if (card_num.equals("040646F2AD6F80")){```   
change it to   
```if (card_num.equals("YOUR_CARD_ID")){```

The master chip can also be used to open the door, you just have to wait longer.



