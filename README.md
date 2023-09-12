# TASK7.2-**Magic of PID**

---

## Task dscription

If you have a flow meter that measures the flow rate in the cleaner hose, implement PID that makes suction mechanism clean at rate 90 CFM (cubic feet per meter)

---

### Task output

(.ino) file added to Group repo and it’s documentation in MD

---

## Code descitption
### -PID Class 

Implementing PID class
**Private:**
In private section we define the variables

```arduino
class PID_Controller {
private:
 //Attributes
 //PID parameters
  double Kp, Ki, Kd;

  // Desired flow rate
  double Clear_Rate_Point;

  //Variable to hold the time
  unsigned long Prev_Time = 0;

  //Variable to hold previous error
  long prev_error = 0;

  //Varaibles to calculate the PID
  long proportional = 0;
  long integral = 0;
  long derivative = 0;
```
**public:**
We start with the class instructor, we use it to initialize the class and to get the values of the parameters of PID 
```arduino
//Class constructor
  PID_Controller(double K_P, double K_I, double K_D) : Kp(K_P), Ki(k_I), Kd(K_D){}
  ```
  Function to get the desired final value
  ```arduino
  //Get desired clearing rate
  void Set_CR(double C_R) {
    Clear_Rate_Point = C_R;
  }
```
Finally a function to implement the PID control
```arduino
{
    //Calculate error
    double error = Clear_Rate_Point - Flow_Rate;

    //Calculate time differenc
    double dt = millis() - Prev_Time;
    Prev_Time = millis();

    //Calculate control signal
    proportional = Kp * error;
    integral += Ki * error * dt;
    derivative = Kd * (error - prev_error) / dt;
    
    //Update previous error for derivative term
    prev_error = error;
    
    //Return sum all of them to get the output of the controller
    return (proportional + integral + derivative);
  }
```

### -Setup
Initialize the class instructor and give it the parameters.
```arduino
PID_Controller pid(1.0, 1.0, 1.0);
```
Then assign the Pins of the flow meter(input) and the suction motor(output).
Set the desired final cleaning rate as *90 FM*. 
```arduino
void setup() {
  //Assign pins to interface with the flow meter and suction mechanism
  pinMode(Flow_Meter, INPUT); //Input for the flow meter 
  pinMode(Suction_Mechanism, OUTPUT); //Output for the suction mechanism
  
  //Set desired flow rate in CFM (cubic feet per meter)
  pid.Set_CR(90);
}
```
### -lOOP
Finally loop to perform multiple iteratoins untill reach desired goal.
```arduino
void loop() {
    //Read current flow date rate from flow meter and send it to the PID class
    double control_signal_Output = pid.PID_Control(analogRead(Flow_Meter));

    //Apply control signal to suction mechanism to adjust suction rate
    analogWrite(Suction_Mechanism, control_signal_Output);
}
``` 
