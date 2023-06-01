# Hiking in the US

![Hiking Banner](https://i.imgur.com/uDDrjwD.png)

Hiking in the US is a terminal-based application designed to help outdoor enthusiasts find, browse, and reserve hiking experiences across the United States. This application was created as a group project for the CS250 C++ Programming class at Orange Coast College by students Henry Do, Louis Ramirez, and Benjamin Nguyen. All credits are included in the source code.

## Features

- **Browse by location**: Explore various hiking locations across the United States.
- **Browse by duration**: Find hikes based on how long you want to be on the trail.
- **Browse by difficulty**: Search for hikes that match your skill level.
- **Browse by price**: Look for hikes that fit your budget.
- **Make a reservation**: Reserve your spot on a hiking trip.
- **View reservation**: Check your reservation details.
- **Cancel reservation**: Change of plans? No problem! You can cancel your reservation here.
- **Exit**: Done with the application? Use this option to exit.

## Data Management

The application interacts with three plain text files to handle data management:

1. **Hikes Database**: The program reads from and writes to a plain text file named `hikes_database.txt`. In this file, each row corresponds to a specific hike, containing information about the state, name of the hike, duration, and price per person.

2. **Members Database**: The program reads from and writes to a plain text file named `members_database.txt`. In this file, each row contains a member's first name, last name, and member ID.

3. **Reservations Database**: The program reads from and writes to a plain text file named `reservations_database.txt`. In this file, each row contains a reservation ID followed by the hike name.

## Note on Contributions

This repository is primarily for demonstration and reference purposes as part of a class project. As such, we are not currently accepting contributions.
