# Project 02 — C# Bootcamp

**Summary:** In this project, you will continue to explore the C# language and delve into object-oriented programming in C#.

💡 [Click here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) to share feedback on this project. It is anonymous and will help our team improve the training. We recommend completing the survey immediately after completing the project.

## Contents

  - [Chapter I](#chapter-i)
    - [Instruction](#instruction)
  - [Chapter II](#chapter-ii)
    - [General Information](#general-information)
  - [Chapter III](#chapter-iii)
    - [Task 1. Variety of Vehicles](#task-1-variety-of-vehicles)
    - [Task 2. Fuel Consumption per 100 km](#task-2-fuel-consumption-per-100-km)
    - [Task 3. Air and Land Transport](#task-3-air-and-land-transport)
    - [Task 4. Speed Increase and Sorting](#task-4-speed-increase-and-sorting)
    - [Task 5. Winner](#task-5-winner)

## Chapter I

### Instruction

1. Throughout the course, you will experience uncertainty and a severe lack of information — this is normal. Remember that the repository and Google are always available to you, as are your peers and Rocket.Chat. Communicate. Search. Rely on common sense. Do not be afraid of making mistakes.
1. Pay attention to sources of information. Verify, think, analyze, compare.
1. Read the assignments carefully. Reread them several times.
1. It’s best to read the examples carefully as well. They may contain something not explicitly stated in the assignment itself.
1. You might encounter inconsistencies when something new in the task or example contradicts what you already know. If that happens, try to figure it out. If you fail, make a note under "open questions" and resolve it during your work. Do not leave open questions unresolved.
1. If a task seems unclear or unachievable, it only seems that way. Try decomposing it. Most likely, individual parts will become clearer.
1. Along the way, you’ll encounter many different tasks. Those marked with an asterisk (\*) are for more meticulous learners. They are of higher complexity and are not mandatory, but if you do them, you’ll gain additional experience and knowledge.
1. Do not try to fool the system or those around you. You’ll only be fooling yourself.
1. Have a question? Ask the neighbor on your right. If that doesn’t help, ask the neighbor on your left.
1. When using someone’s help, always make sure you understand why, how, and what for. Otherwise, that help is meaningless.
1. Always push only to the **develop** branch! The **master** branch will be ignored. Work in the **src** directory.
1. Your directory should not contain any files other than those specified in the tasks.

## Chapter II
### General Information

**Topics for Study:**

- OOP/Procedural/Multi-Paradigm Approach in C#;
- Differences from C and C++;
- Functional Paradigm; 
- Asynchronous/Parallel Programming, Closures.

## Chapter III

**Attention!** Each task should be set up as a separate project. For example, `T01/src/exercise0`, `T01/src/exercise1`, ... `T01/src/exerciseN-1`, where *N* is the number of tasks. If the previous task is needed for the next one, simply copy the previous project into the directory of the next task and continue development there.

### Task 1. Variety of Vehicles
Develop a module that prints a list of vehicles and information about each vehicle.

- The program uses reference data types.

**Creating Classes and Overriding Methods** 

- Create an abstract class Vehicle with two private fields: String type, Double speed.
- The class Vehicle should be in a separate file.
- In the class Vehicle, create an abstract method String intelligence().
- Create a class Car that inherits from Vehicle.
- Override the intelligence() method in the class Car so that information about the vehicle is output in the following format: "Type car = [car type], speed = [vehicle speed]".
- The class Car should be in a separate file.
- Create a class Plane that inherits from the class Vehicle.
- Override the intelligence() method in the class Plane to output information about the vehicle in the following format: "Type plane = [plane type], speed = [vehicle speed]".
- The class Plane should be in a separate file.

**Reading input data for the program**

- The program reads the number of vehicles.
- The program reads the type of the input vehicle: car/plane.
- Then the program reads the vehicle type and speed.
- Each vehicle is added to the common list of transports.

**Input data validation**

- If an incorrect vehicle type is entered, the program outputs: "Incorrect input. Unsupported vehicle type" and proceeds to the next input.
- If a negative speed is entered, the program outputs: "Incorrect input. Speed < 0" and proceeds to the next input.
- The program does not terminate with an error if the input data is incorrect. It outputs: "Could not parse a number. Please try again" and repeats the input attempt.

**Output** 

- The program should output information about each vehicle.

<table>
    <tr>
        <th>Input data</th>
        <th>Output data</th>
    </tr>
    <tr>
        <td>3 
<br>plane
<br>cargo
<br>780
<br>car
<br>passenger
<br>100
<br>car
<br>truck
<br>60	</td>
        <td>Type plane = cargo, speed = 780
<br>Type car = passenger, speed = 100
<br>Type car = truck, speed = 60</td>
    </tr>
 <tr>
        <td>3
<br>train
<br>car
<br>truck
<br>-41
<br>plane
<br>passenger
<br>500</td>
        <td>Incorrect input. Unsupported vehicle type
<br>Incorrect input. Speed < 0
<br>Type plane = passenger, speed = 500</td>
    </tr>
 <tr>
        <td>2
<br>car
<br>passenger
<br>90
<br>plane
<br>cargo
<br>800</td>
        <td>Type car = passenger, speed = 90
<br>Type plane = cargo, speed = 800
</td>
    </tr>
</table>

### Task 2. Fuel Consumption per 100 km
Develop a module that outputs the fuel consumption per 100 km for each vehicle.

- Accuracy: 3 decimal places.
- The program uses reference data types.

**Creating Classes and Overriding Methods**

- Use the functionality from the previous task with some additions.
- Add a private field int tankVolume to the class Vehicle.
- Declare a method float getFuelConsumL() in the class Vehicle.
- Implement the getFuelConsumL() method in the class Car, which calculates the amount of fuel needed to drive 100 km using the following formula: `fuel consumption = tank volume / distance traveled in km * 100`.
- Override the intelligence() method in the class Car so that information about the vehicle is output in the following format: "Type car = [car type], speed = [vehicle speed], tankVolume = [tank volume], fuelConsum = [fuel consumption]".
- Implement the getFuelConsumL() method in the class Plane, which calculates the amount of fuel needed to travel 100 km using the following formula: `fuel consumption = tank volume / distance traveled in km * 100 * 3`. 
- Override the intelligence() method in the class Plane so that information about the vehicle is output in the following format: "Type plane = [plane type], speed = [vehicle speed], tankVolume = [tank volume], fuelConsum = [fuel consumption]".

**Reading input data for the program**

- The program reads the type of the input vehicle: car/plane.
- The program reads the number of vehicles.
- Then the program reads the vehicle type, speed and tank volume.
- Each vehicle is added to the common list of transports.
- The program reads the distance traveled by the vehicle.

**Input data validation**

- If an incorrect vehicle type is entered, the program outputs "Incorrect input. Unsupported vehicle type" and proceeds to the next input.
- If a negative speed is entered, the program outputs: "Incorrect input. Speed < 0" and proceeds to the next input.
- If a negative tank volume is entered, the program outputs: "Incorrect input. tankVolume < 0" and proceeds to the next input.
- If a negative or zero distance is entered, the program outputs: "Incorrect input. Distance <= 0" and proceeds to the next input.

**Output** 

- The program should output information about each vehicle and its fuel consumption per 100 km.

<table>
    <tr>
        <th>Input data</th>
        <th>Output data</th>
    </tr>
    <tr>
        <td>3
<br>plane
<br>cargo
<br>780
<br>30000
<br>8000
<br>car
<br>passenger
<br>100
<br>50
<br>500
<br>car
<br>truck
<br>60
<br>60
<br>700	</td>
        <td>Type plane = cargo, speed = 780, tankVolume = 30000, fuelConsum = 1125
<br>Type car = passenger, speed = 100, tankVolume = 50, fuelConsum = 10
<br>Type car = truck, speed = 60, tankVolume = 60, fuelConsum = 8,571</td>
    </tr>
 <tr>
        <td>3
<br>train
<br>car
<br>truck
<br>-41
<br>plane
<br>passenger
<br>500
<br>28000
<br>7000	</td>
        <td>Incorrect input. Unsupported vehicle type
<br>Incorrect input. Speed < 0
<br>Type plane = passenger, speed = 500, tankVolume = 28000, fuelConsum = 1200</td>
    </tr>
 <tr>
        <td>2
<br>car
<br>passenger
<br>90
<br>83
<br>900
<br>plane
<br>cargo
<br>800
<br>43000
<br>9500</td>
        <td>Type car = passenger, speed = 90, tankVolume = 83, fuelConsum = 9,222
<br>Type plane = cargo, speed = 800, tankVolume = 43000, fuelConsum = 1357,895</td>
    </tr>
</table>

### Task 3. Air and Land Transport
Develop a module that separates transport into air and land categories.

- The program uses reference data types.

**Creating interfaces**

- Create an interface Air.
- Declare a property float maxFlightAltitude in Air.
- The Air interface should be in a separate file.
- Create an interface Land.
- Declare a property int numberOfWheels in Land.
- The Land interface should be in a separate file.

**Creating Classes and Overriding Methods**

- Use the functionality from Task 1 with some additions.
- Add a private double speed field to the class Vehicle.
- Override the intelligence() method in the class Car to output information about the Vehicle in the following format: "Type car = [car type], speed = [vehicle speed], numberOfWheels = [number of wheels]".
- Override the intelligence() method in the class Plane to output information about the vehicle in the following format: "Type plane = [plane type], speed = [vehicle speed], maxFlightAltitude = [maximum flight altitude in m]".
- Create a class Bike that inherits from Vehicle.
- Override the intelligence() method in the class Bike to output information about the vehicle in the following format: "Type bike = [bike type], speed = [vehicle speed], numberOfWheels = [number of wheels]".
- The class Bike should be in a separate file.
- Create an class Airship that inherits from the class Vehicle.
- Override the intelligence() method in the class Airship to output information about the vehicle in the following format: "Type airship = [airship type], speed = [vehicle speed], maxFlightAltitude = [maximum flight altitude in m]".
- The class Airship should be in a separate file.

**Reading input data for the program** 

- The program reads the type of the input vehicle: car/plane/bike/airship.
- The program reads the number of vehicles.
- Then the program reads the vehicle type and speed.
- Each vehicle is added to the common list of transports.

**Input data validation** 

- If a wrong type of vehicle is entered, the program outputs: "Incorrect input. Unsupported vehicle type" and proceeds to the next input.
- If a negative speed is entered, the program outputs: "Incorrect input. Speed < 0" and proceeds to the next input.
- If a negative or zero number of wheels is entered for a land vehicle, the program outputs: "Incorrect input. numberOfWheels <= 0" and proceeds to the next input.
- If a negative or zero altitude is entered for an air vehicle, the program outputs: "Incorrect input. maxFlightAltitude < 0" and proceeds to the next input.
- The program does not terminate with an error if the input data is incorrect. It outputs: "Could not parse a number. Please try again" and retries the input.

**Output**

- The program should output information about the air transport first, then about the land transport.

<table>
    <tr>
        <th>Input data</th>
        <th>Output data</th>
    </tr>
    <tr>
        <td>4
<br>airship
<br>rigid
<br>170
<br>1000
<br>car
<br>passenger
<br>100
<br>4
<br>bike
<br>sports
<br>110
<br>2
<br>plane
<br>cargo
<br>740
<br>5000</td>
        <td>Type airship = rigid, speed = 170, maxFlightAltitude = 1000
<br>Type plane = cargo, speed = 740, maxFlightAltitude = 5000
<br>Type car = passenger, speed = 100, numberOfWheels = 4
<br>Type bike = sports, speed = 110, numberOfWheels = 2</td>
    </tr>
 <tr>
        <td>3
<br>train
<br>car
<br>truck
<br>-41
<br>bike
<br>quad
<br>150
<br>4</td>
        <td>Incorrect input. Unsupported vehicle type
<br>Incorrect input. Speed < 0
<br>Type bike = quad, speed = 150, numberOfWheels = 4</td>
    </tr>
 <tr>
        <td>2
<br>car
<br>passenger
<br>90
<br>4
<br>airship
<br>soft
<br>182
<br>957</td>
        <td>Type airship = soft, speed = 182, maxFlightAltitude = 957 <br>
Type car = passenger, speed = 90, numberOfWheels = 4</td>
    </tr>
</table>

### Task 4. Speed Increase and Sorting
Develop a module that increases the speed of vehicles by 7% if they exceed 100 km/h and then sorts them by year of manufacture, following the functional paradigm.

**Creating Classes and Overriding Methods** 

- Use the classes you created in Task 3 with some additions.
- Add a private int year field to the class Vehicle.
- Override the intelligence() method in the class Car to output information about the vehicle in the following format: "Type car = [car type], speed = [vehicle speed], year = [year of manufacture]".
- Override the intelligence() method in the class Plane to output information about the vehicle in the following format: "Type plane = [plane type], speed = [vehicle speed], year = [year of manufacture]".
- Override the intelligence() method in the class Bike to output information about the vehicle in the following format: "Type bike = [bike type], speed = [vehicle speed], year = [year of manufacture]".
- Override the intelligence() method in the class Airship to output information about the vehicle in the following format "Type airship = [airship type], speed = [vehicle speed], year = [year of manufacture]".

**Reading input data for the program** 

- The program reads the number of vehicles.
- The program reads the type of the input vehicle: car/plane/bike/airship.
- Then the program reads the vehicle type, speed and year of manufacture.
- Each vehicle is added to the common list of transports.

**Input data validation** 

- If an incorrect type of vehicle is entered, the program outputs: "Incorrect input. Unsupported vehicle type" and proceeds to the next input.
- If a negative speed is entered, the program outputs: "Incorrect input. Speed < 0" and proceeds to the next input.
- If a negative year or a year > 2023 is entered, the program outputs: "Incorrect input. Year < 0 or year > 2023" and proceeds to the next input.
- The program does not terminate with an error if the input data is incorrect. It outputs: "Could not parse a number. Please try again" and retries the input.

**Task execution and output** 

- The program should increase the speed of all vehicles by 7% if their speed is greater than 100 km/h.
- The program should sort the vehicles by year of manufacture in descending order.
- The program should output information about each vehicle.

**Requirements for implementing the program**

- The program should use reference data types.
- The program should adhere to the functional paradigm.
- The program should use LINQ.
- Accuracy: 3 decimal places.
- It is forbidden to use loop operators.

<table>
    <tr>
        <th>Input data</th>
        <th>Output data</th>
    </tr>
    <tr>
        <td>4
<br>airship
<br>rigid
<br>170
<br>1999
<br>car
<br>passenger
<br>88
<br>2015
<br>bike
<br>sports
<br>110
<br>2022
<br>plane
<br>cargo
<br>740
<br>2010</td>
        <td>Type bike = sports, speed = 117.7, year = 2022
<br>Type car = passenger, speed = 100, year = 2015
<br>Type plane = cargo, speed = 791.8, year = 2010
<br>Type airship = rigid, speed = 181.9, year = 1999</td>
    </tr>
 <tr>
        <td>3
<br>train
<br>car
<br>truck
<br>115
<br>-1998
<br>bike
<br>quad
<br>150
<br>2023</td>
        <td>Incorrect input. Unsupported vehicle type
<br>Incorrect input. year < 0
<br>Type bike = quad, speed = 160.5, year = 2023</td>
    </tr>
 <tr>
        <td>2
<br>car
<br>passenger
<br>90
<br>2003
<br>airship
<br>soft
<br>182
<br>2021</td>
        <td>Type airship = soft, speed = 194.74, year = 2021
<br>Type car = passenger, speed = 90, year = 2003</td>
    </tr>
</table>

### Task 5. Winner
Develop a module that displays information about each vehicle, and also displays the winner of the race and the time each vehicle spent in the race.

**Creating Classes and Overriding Methods** 

- Use the functionality from Task 1 (class Car).
- Use the class Bike from Task 3.
- In the class Vehicle, declare a method double timeRace().
- Override the timeRace() method in the class Car as follows: The method calculates the time spent in the race, in seconds.
- Override the intelligence() method in the class Bike to display information about the vehicle in the following format: "Type bike = [bike type], speed = [vehicle speed]".
- Override the timeRace() method of the class Bike as follows: the method calculates the time spent in the race, in seconds.
- Calculate the race time for the class Car using the following formula `[race_time] = [track_length] / [vehicle_speed in m/s] * 1.07`.
- Calculate the race time for the class Bike using the following formula `[race_time] = [track_length] / [vehicle_speed in m/s]`.

**Reading the input data for the program** 

- The program reads the number of vehicles.
- The program reads the length of the track in meters.
- The program reads the type of the input vehicle: car/bike.
- Then the program reads the vehicle type and speed.
- Each vehicle is added to the common list of transports.

**Input data validation** 

- If there are less than 2 vehicles in transports, the program outputs: "No one to compete with".
- If a negative or zero track length is entered, the program outputs "Incorrect input. Distance < 0" and moves on to the next input.
- If a wrong type of vehicle is entered, the program outputs: "Incorrect input. Unsupported vehicle type" and proceeds to the next input.
- If a negative speed is entered, the program outputs: "Incorrect input. Speed < 0" and proceeds to the next input.
- The program does not terminate with an error if the input data is incorrect. It outputs: "Could not parse a number. Please try again" and retries the input.

**Task execution** 

- The program should call the timeRace() method on each vehicle.
- The vehicles start simultaneously, so each call of the timeRace() method is executed in parallel in a separate thread.
- The program waits until all calls to the timeRace() method have finished before it terminates.

**Output** 

- After the race is finished, the program should output the following information to a line in the console: the information about the vehicle and the time spent on the race.
- After all parallel threads have finished, the program outputs information about the winner.

**Requirements** 

- Accuracy: 3 decimal places.
- The program uses reference data types.
- The program should use parallel programming, which you can learn about in the materials for this lesson.

<table>
    <tr>
        <th>Input data</th>
        <th>Output data</th>
    </tr>
<tr>
        <td>2
<br>5220
<br>car
<br>passenger
<br>39
<br>bike
<br>sports
<br>43</td>
<td>Type bike = sports, speed = 43, timeRace = 121.395
<br>Type car = passenger, speed = 39, timeRace = 143.215
<br>Winner = sports bike with speed 43 m/s</td>
    </tr>
 <tr>
        <td>3
<br>6743
<br>car
<br>sports
<br>53
<br>bike
<br>quad
<br>43
<br>bike
<br>sports
<br>49</td>
        <td>Type car = sports, speed = 53, timeRace = 136.132
<br>Type bike = sports, speed = 49, timeRace = 137.612
<br>Type bike = quad, speed = 43, timeRace = 156.814
<br>Winner = sports car with speed 53 m/s</td>
    </tr>
 <tr>
        <td>3
<br>8256
<br>train
<br>car
<br>passenger
<br>-43
<br>bike
<br>quad
<br>57</td>
        <td>Incorrect input. Unsupported vehicle type 
<br>Incorrect input. Speed < 0
<br>No one to compete with</td>
    </tr>
</table>
