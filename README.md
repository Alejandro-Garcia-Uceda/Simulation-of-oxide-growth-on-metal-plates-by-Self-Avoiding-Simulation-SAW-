# Simulation-of-oxide-growth-on-metal-plates-by-Self-Avoiding-Simulation-SAW-
This project is a simulation of rust growth on metal plates under different rust conditions and elements, using the Self-Avoiding Simulation (SAW) algorithm.

This project is a simplified simulation of the oxidation process, since this phenomenon takes into account pressure, temperature, humidity, deformations and impurities. conditions. The variables in this simulation are the volume of oxide in air, the percentage of surface area initially oxidized and the elements and alloys of the metal.

El primer objetivo era comparar el resultado con el estudio realizado por C. Palacio, H.J Mathieu y D. Landolt sobre la oxidación de una placa de cromo, tras un resultado positivo se realizaron diferentes simulaciones con diferentes elementos y condiciones.

The files and folder are:
1- nverstrab.cpp : C++ code that performs the simulation and exports in a file the evolution and the results. This code will ask for the initial condition before starting.
2- representacion.m : Matlab code made to show the evolution to the sistem and the graphs, importing the file that nverstrab.cpp exported.
3- Graphs: This folder has the results of the simulation graphs. 
