

float e_last_val = 0;
float time_delay = 0.1;

float kp = 1, ki = 8, kd = 0.01;

int fin_val = 90;
double cur_val = 0;


/**
 * @fn setup
 * @brief begin serial monitor
*/

void setup() {
  Serial.begin(9600);
}

/**
 * @fn loop
 * @brief calculate new PID values and control value and printing the control one to serial
*/

void loop() {
  
  float error = fin_val - cur_val;

  float p_cur_val = kp * error;
  float d_cur_val = kd * (error - e_last_val) / time_delay;
  float i_cur_val = ki * (error + e_last_val) / 2.0 * time_delay;

  cur_val += p_cur_val + d_cur_val + i_cur_val;


  Serial.println(cur_val);

  e_last_val = error;

  delay(100);
}
