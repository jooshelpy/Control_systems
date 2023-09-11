# README.md

# TASK7.2-**Magic of PID**

---

## Task description

If you have a flow meter that measures the flow rate in the cleaner hose, implement PID that makes suction mechanism clean at rate 90 CFM (cubic feet per meter)

---

### Task output

(.ino) file added to Group repo and it’s documentation in MD

---

## Code descitption

Implementing PID 

**Proportional**

```arduino
float p_cur_val = kp * error;
```

Integration

```arduino
float i_cur_val = ki * (error + e_last_val) / 2.0 * time_delay;
```

**Derivative**

```arduino
float d_cur_val = kd * (error - e_last_val) / time_delay;
```

Adding 3 values to get the old current value and print it to serial