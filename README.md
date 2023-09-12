# TASK7.3- Hero of Mobility

# Forward Kinematic

[https://drive.google.com/file/d/1CvsjWeY3RYReH1kwNlzN3aZr9s16NL7n/view?usp=sharing](https://drive.google.com/file/d/1CvsjWeY3RYReH1kwNlzN3aZr9s16NL7n/view?usp=sharing)

Considering the first wheel which is far of the x-axis by a1 = 30. Then, s1 will go to y-axis by s1cos(a1) and will go to x-axis by -s1sin(a1). Adding all other compounds the result will be

```arduino
Vy = s1*np.sin(30) + s2*-np.sin(150) + s3*-np.sin(270)

Vx = s1*np.cos(30) + s2*np.cos(150) + s3*np.cos(270)
```

while the w will be the sum of all V of the wheels

[https://drive.google.com/file/d/1OzK0TrjT7tKKhNRe0rADzjQb5_uqgGMI/view?usp=sharing](https://drive.google.com/file/d/1OzK0TrjT7tKKhNRe0rADzjQb5_uqgGMI/view?usp=sharing)

Therefore, the matrix for the Forward Kinematic will be

[https://drive.google.com/file/d/1TlSlGV2QIbdRL24mUycmSjSIhSVo6kFK/view?usp=sharing](https://drive.google.com/file/d/1TlSlGV2QIbdRL24mUycmSjSIhSVo6kFK/view?usp=sharing)

# Reverse Kinematic

using the above information and forming the matrix of forward Kinematic the matrix for the reverse will be

[https://drive.google.com/file/d/1SDN1P5WCnXjuhcvZyBQ2mKJ6_JeFHm_t/view?usp=sharing](https://drive.google.com/file/d/1SDN1P5WCnXjuhcvZyBQ2mKJ6_JeFHm_t/view?usp=sharing)

# Transferring from local to global

using the same equation in the video since considering 2D

[https://drive.google.com/file/d/130qzR2ZBWsnoSJWSDLHm1w3W69h-C9hi/view?usp=sharing](https://drive.google.com/file/d/130qzR2ZBWsnoSJWSDLHm1w3W69h-C9hi/view?usp=sharing)