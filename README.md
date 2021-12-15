# Handrail-Cleaner

My project for the course ELEC-C9801 Design Thinking and Electronic Prototyping
in Autumn 2021 (First year).

[Click here](final_code.ino) to quickly get to the code.

![alt text](https://github.com/tamdnguyen/Handrail-Cleaner/blob/main/Handrail%20Cleaner.png?raw=true)

## Introduction
- Team members: Himanshu Jain, Nguyen Gia Khanh, Saku Kovanen, Nguyen Duc Tam
  (Team 8 - The Orange Team)
- Idea: a device that automatically cleans the handrail
- Purpose: to clean the handrail effortlessly and automatically
- Target users: cleaning workers, janitors, shopping centers, universities 
and other big buildings, homeowners

## Technical aspect
- Hardware
  - 1 x 3D printed body
  - 1 x Arduino Uno microcontroller
  - 2 x DC motors (+ wheels)
  - 4 x HC-SR04 ultrasonic distance sensor
  - Microfiber cloths
- Software
  - [Controlling motors](move_with_l298n.ino)
  - [Connecting and retrieving data from sensors](ultrasonic_sensor.ino)
  - [Base code for connecting sensors](retest_hc-sr04.ino)

https://user-images.githubusercontent.com/95592965/145734519-16925650-df71-443d-8957-13d38b1f1c00.mp4

## License
Shield: [![CC BY 4.0][cc-by-shield]][cc-by]

This work is licensed under a
[Creative Commons Attribution 4.0 International License][cc-by].

[![CC BY 4.0][cc-by-image]][cc-by]

[cc-by]: http://creativecommons.org/licenses/by/4.0/
[cc-by-image]: https://i.creativecommons.org/l/by/4.0/88x31.png
[cc-by-shield]: https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg
