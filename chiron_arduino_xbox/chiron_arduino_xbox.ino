/*
This is the aduino code for AJ 2.0, for electrical designs and documentation
check the GIT Hub located at ...
 */

//include rosserial libaries
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>
//#include <std_msgs/ByteMultiArray.h>

ros::NodeHandle nh;

// set pin numbers:
const int forward_pin = 2;     // the number of the pushbutton pin
const int reverse_pin = 3;
const int left_pin = 4;	//setting pins for motor controller
const int right_pin = 5;
const int fifth_switch_pin = 6;

boolean forward_bool = true;
boolean reverse_bool = true;
boolean left_bool = true;
boolean right_bool = true;
boolean fifth_switch_bool = true;

void bool_callback( const std_msgs::UInt16& bool_value){
	if(bool_value.data == 1){
		forward_bool = false;	    
		//bool_array_update();
	
	}

	if(bool_value.data == 2){
		forward_bool = true;    
		//bool_array_update();
	
	}

	if(bool_value.data == 3){
		reverse_bool = false;
		//bool_array_update();
	
	}

	if(bool_value.data == 4){
		reverse_bool = true;
		//bool_array_update();
	
	}

	if(bool_value.data == 5){
		left_bool = false;
		//bool_array_update();
	
	}

	if(bool_value.data == 6){
		left_bool = true;
		//bool_array_update();
	
	}

	if(bool_value.data == 7){
		right_bool = false;
		//bool_array_update();
	
	}

	if(bool_value.data == 8){
		right_bool = true;
		//bool_array_update();
	}

	if(bool_value.data == 9){
		fifth_switch_bool = false;
		//bool_array_update();
	
	}

	if(bool_value.data == 10){
		fifth_switch_bool = true;
		//bool_array_update();
	}
	else{
		return; 
	}	    
}

ros::Subscriber<std_msgs::UInt16> sub_1("/bool", bool_callback);

void setup(){
	// initialize the pushbutton pin as an input:
	pinMode(forward_pin, OUTPUT);     
	pinMode(reverse_pin, OUTPUT);
	pinMode(left_pin, OUTPUT);
	pinMode(right_pin, OUTPUT);
	pinMode(fifth_switch_pin, OUTPUT);

	nh.initNode();
	
	forward_bool = true;
	reverse_bool = true;
	left_bool = true;
	right_bool = true;
	fifth_switch_bool = true;
	
	nh.subscribe(sub_1);
	}

void loop(){
	if(forward_bool == true){
		digitalWrite(forward_pin, HIGH);	
	}
	if(forward_bool == false){
		digitalWrite(forward_pin, LOW);
	}	

	if(reverse_bool == true){
		digitalWrite(reverse_pin, HIGH);	
	}
	if(reverse_bool == false){
		digitalWrite(reverse_pin, LOW);
	}	

	if(left_bool == true){
		digitalWrite(left_pin, HIGH);
	}
	if(left_bool == false){
		digitalWrite(left_pin, LOW);
	}

	if(right_bool == true){
		digitalWrite(right_pin, HIGH);
	}
	if(right_bool == false){
		digitalWrite(right_pin, LOW);
	}

	if(fifth_switch_bool == true){
		digitalWrite(fifth_switch_pin, HIGH);
	}
	if(fifth_switch_bool == false){
		digitalWrite(fifth_switch_pin, LOW);
	}

	nh.spinOnce();
}
