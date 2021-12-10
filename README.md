# casa0016-Auto-Humidifier

## Motivation
Humidifiers provide an easy solution for the dry air problems. However, most of them need manual intervention to be turned on and off. Alternatively, keeping it on all day would result in energy wastage. Also, it would mean the user would have to refill the water source more often.

In comparison, a better solution is to trigger the humidifier only when the humidity level decreases in the room. 
In this way, the humidifier runs in a controlled manner using only as much electricity and water as required.

## Goal
Connect a small power drawing ultrasonic atomiser to the humidity sensor and control the atomiser based on the current humidity levels.

## Components used for the sensor network
<ul>
  <li>Arduino UNO board</li>
  <li>DHT sensor to measure the humidity level</li>
  <li>5V Humidifier module</li>
  <li>DC motor – to repurpose as a fan to disperse the mist</li>
  <li>PIR sensor</li>
  <li>Moisture sensor</li>
  <li>Red LED</li>
  <li>5V battery</li>
</ul>

## Circuit diagram
![Engineering](https://user-images.githubusercontent.com/91799774/145638139-87c108ed-cdf4-4b8b-83be-5279f4f97933.jpg "Made from website https://cloud.smartdraw.com/editor.aspx")

## Operation logic

Step 1: Check the humidity level at a predefined interval.

Step 2: Check the PIR readings. If any presence is detected, save it.

Step 3: If the humidifier decreases below threshold and presence has been detected 
in the last few minutes, trigger the humidifier module and start the DC fan.

Step 4: After a fixed delay, stop the fan and humidifier.

Step 5: Reset the presence detected state.

Step 6: Check the moisture reading for the water level. If moisture reading drops below threshold, switch on the red LED to signal water refill.

## Creating the prototype
For the initial prototype, I used a cardboard box to house the circuit as well as the jumper wires. 
To complete the components to be used in the circuit,
1. I created the blades for my DC motor fan from cardboard cutouts.
2. The mister(atomiser) module contained a USB input jack but no serial pins. Hence, I soldered the positive, negative pins below the USB supply for serial input.

Attached below is a picture of the circuit and the cardboard prototype which did not have moisture sensor. Also, I tried to power the 300mA atomiser module through a transistor.
![IMG_20211206_231819](https://user-images.githubusercontent.com/91799774/145641174-4b67e08a-c1c0-4676-a36e-7155655619d4.jpg)
![image](https://user-images.githubusercontent.com/91799774/145641221-0a01fbc6-edaa-4104-a3ae-f050fa126c88.png)
![image](https://user-images.githubusercontent.com/91799774/145641299-68965ec5-e268-482c-ab2d-b20f53d5963b.png)

With this initial design, the following design flaws became apparent:
1. The DC motor wasnt stable and kept falling off when started.
2. The design direly needed a signal to alert the user to change the water. I contemplated on the best approach(send alerts via MQTT or make an offline signal on the device)
3. Owing to the requirement of water nearby the sensor system, I considered it best not to use paper based cover.
4. The speed of the mister remained very less in comparision to USB supply. It was necessary to add additional power supply for the atomiser module.

## Second iteration
A 5V supply was added with the atomiser module. 
A 3D printed box was created with a slot for the DC motor.
To measure the level of water, I used the soil moisture sensor used in the Plant monitor project(Ref: https://github.com/AbhipsaKar/casa0014/blob/main/Plant%20Monitor/README.md). If the moisture level drops, the red LED is switched on to signal a refill.
Additionally, I curved the blades of the DC motor to streamline the flow the air so that the mist is dispersed properly.
With the new design, the mister module now works at a full capacity and the DC motor is steadfast in its socket.
The plastic cover hides the breadboard, Arduino as well as most of the jumper wires.
Given below are images of the improved system:
![IMG_20211210_214008](https://user-images.githubusercontent.com/91799774/145645140-95794ed5-6b0b-4157-980c-8b55305121f8.jpg)
![IMG_20211210_214027](https://user-images.githubusercontent.com/91799774/145645151-a034e556-0e45-40d8-b981-16524deb27b3.jpg)
![Screenshot_20211210-213102](https://user-images.githubusercontent.com/91799774/145645159-151591cc-26fd-421e-83a0-e5656d90341e.jpg)
![Screenshot_20211210-213113](https://user-images.githubusercontent.com/91799774/145645266-35494ffe-eeb2-4e87-91a1-e3f7cb7f5eb0.jpg)

## Still more to do
<ul>
  <li>The outer case needs a transparent dome to hide the remaining wires and mister module.</li>
  <li>It is required to check how the rusting of the nails and the mister module can be stopped in this system </li>
</ul>
