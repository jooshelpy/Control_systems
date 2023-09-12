# TASK7.3- Hero of Mobility

# Forward Kinematic

[https://www.notion.so](https://www.notion.so)

![Untitled](TASK7%203-%20Hero%20of%20Mobility%205225380ddd804df99cb21dd8156adb56/Untitled.png)

Considering the first wheel which is far of the x-axis by a1 = 30. Then, s1 will go to y-axis by s1cos(a1) and will go to x-axis by -s1sin(a1). Adding all other compounds the result will be

```arduino
Vy = s1*np.sin(30) + s2*-np.sin(150) + s3*-np.sin(270)

Vx = s1*np.cos(30) + s2*np.cos(150) + s3*np.cos(270)
```

while the w will be the sum of all V of the wheels

[https://www.notion.so](https://www.notion.so)

![Untitled](TASK7%203-%20Hero%20of%20Mobility%205225380ddd804df99cb21dd8156adb56/Untitled%201.png)

Therefore, the matrix for the Forward Kinematic will be

[https://www.notion.so](https://www.notion.so)

![Untitled](TASK7%203-%20Hero%20of%20Mobility%205225380ddd804df99cb21dd8156adb56/Untitled%202.png)

# Reverse Kinematic

using the above information and forming the matrix of forward Kinematic the matrix for the reverse will be

[https://www.notion.so](https://www.notion.so)

![Untitled](TASK7%203-%20Hero%20of%20Mobility%205225380ddd804df99cb21dd8156adb56/Untitled%203.png)

# Transferring from local to global

using the same equation in the video since considering 2D

[https://www.notion.so](https://www.notion.so)

![Untitled](TASK7%203-%20Hero%20of%20Mobility%205225380ddd804df99cb21dd8156adb56/Untitled%204.png)