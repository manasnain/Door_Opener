# Door_Opener
Door opener for the door at the small workshop

## ADDING CARDS

To add cards, tap the master chip (currently the yellow erární chip in the Big Workshop) and immediately replace it with the card that needs to be added.
*add pics*

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



