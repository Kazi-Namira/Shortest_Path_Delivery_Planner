# **Shortest Path Delivery Planner** 

**Shortest Path Delivery Planner** is an interactive application that calculates and visualizes the shortest path between two locations using **Dijkstra's Algorithm**. Built with **C++** and **SFML** (Simple and Fast Multimedia Library), this project allows users to interact with a graphical map, select nodes, and see the real-time animation of a car following the shortest route.

---

## **🌟 Features**
- **Dijkstra's Algorithm**: Efficiently calculates the shortest path between two nodes.
- **Interactive UI**: Select source and destination nodes directly on the graphical map.
- **Graphical Visualization**:
  - Nodes are represented with easily identifiable icons.
  - Edges connect nodes, displaying their respective weights.
  - The shortest path is highlighted in **green** for easy identification.
- **Real-Time Animation**: Watch a car follow the calculated shortest path, providing a dynamic and engaging representation of the solution.

---

## **🔧 How It Works**
1. **Input**:
   - The user provides the number of vertices and edges.
   - The user specifies the connections between nodes and their respective weights.
   - Node positions are set on the map, allowing for an interactive experience.
2. **Shortest Path Calculation**:
   - The program uses **Dijkstra's Algorithm** to determine the shortest path between the selected source and destination nodes.
3. **Rendering**:
   - **SFML** is used to render the map, nodes, edges, and animations, offering smooth graphics and an engaging interface.
4. **Real-Time Animation**:
   - The car icon animates along the shortest path, providing a real-time visualization of the route.

---

## **🔧 Step-by-Step Guide**

### **1. SFML Setup**

Before running the project, you need to set up **SFML** for rendering graphics.

- **Follow this YouTube tutorial** to set up SFML on your machine:  
  [**SFML Setup Tutorial**](https://youtu.be/PJN5XlAUThU?si=6-oi2c1NhKtcEGdk)  

Make sure to follow the instructions for your specific platform (Windows, macOS, Linux) to correctly install and configure SFML.

---
