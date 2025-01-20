#include <Key.h>
#include <Keypad.h>

int number = 0;
int temp=0;
int ans=0;
char oper;

const byte ROWS = 4;
const byte COLS=4;

char keys[ROWS][COLS]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'.','0','=','/'}
  };


  byte rowPins[ROWS] = {9,8,7,6};
  byte colPins[COLS] = {5,4,3,2};


  Keypad kpd = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup()

{
	Serial.begin(9600);
}

void loop() {

  char key = kpd.getKey();
  
  if(key=='1' || key=='2' || key=='3' ||key=='4' ||key=='5' ||key=='6' ||key=='7' ||key=='8' ||key=='9' ||key=='0')
  {
    number = number*10 + ( key - '0');
    Serial.println(number);
  }
  
  if(key=='+' || key=='-' || key=='*' || key=='/')
  {
    temp = number;
    number=0;
    oper=key;
    Serial.println(oper);
  }
  
  if( key == '=')
  {
   	   if(oper == '+')
       {
			ans = number+temp;
       }
       if(oper == '-')
       {
			ans = temp-number;
       }
          if(oper == '*')
       {
			ans = number*temp;
       }
       if(oper == '/')
       {
			ans = temp / number;
    	}
    
    Serial.print("Answer: ");
    Serial.print(temp);
    Serial.print(oper);
    Serial.print(number);
    Serial.print('=');
    Serial.print(ans);
    Serial.print("\n");
    number=0;
    temp=0;
  }
  if(key=='.')
  {
    number=0;
    temp=0;
    oper=' ';
  }
}