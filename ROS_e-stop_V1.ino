#define BUTTON_PIN 14                          //this is the pin that will send the kill command by going HIGH

//include ROS header files
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;                             //instantiate the node handle - lets us create pub/sub and serial msgs 

std_msgs::String str_msg;                       //create a pub with the topic "chatter"
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";                //character variable that will be sent as a string msg. refrenced later

//--------------------------------------------------------------------------------------------------------------------

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);               //initalizes led pin to confirm the press
  pinMode(BUTTON_PIN, INPUT);                 //initalizes button pin

  Serial.begin(9600);    //opens a arduino serial connection to debug

  //
  nh.initNode();                //initialize ROS node handle
  nh.advertise(chatter);        //advertise topics being published (can also subscribe to any topics here)
}

//--------------------------------------------------------------------------------------------------------------------

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {        //loop is all set up. add commands to send here
    digitalWrite(LED_BUILTIN, HIGH);

    Serial.print("Good "); //serial debug msg  //i have no idea why it is inverted from the logic. When button pressed, print statement stops. 


    //rosserial
    str_msg.data = hello;           //selects the string to send
    chatter.publish( &str_msg );    //publishes the string
    nh.spinOnce();                  //ros::spinOnce() is where all of the ROS communication callbacks are handled
    delay(1000);   //wait

  }

  else {                                        //keeps the led off when not pressed
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("\nBAD BAD BAD\n");
  }
}