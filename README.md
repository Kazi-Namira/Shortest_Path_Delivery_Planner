# **Shortest Path Delivery Planner** 🛣️

**Shortest Path Delivery Planner** is an interactive application that calculates and visualizes the shortest path between two locations using **Dijkstra's Algorithm**. Built with **C++** and **SFML** (Simple and Fast Multimedia Library), this project allows users to interact with a graphical map, select nodes, and see the real-time animation of a car following the shortest route.

---

## **✨  Features**
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
     

![image](https://github.com/user-attachments/assets/273b50cf-a986-4308-b535-35e22ca88a3c)


---

## **🔧 Step-by-Step Guide**

### **1. Prerequisites**

Before starting, make sure you have the following:

- A C++ compiler installed (e.g., **g++** or **MinGW**).
- **SFML** library set up for rendering graphics. Follow the instructions below to set it up.

---

### **2. SFML Setup**

Before running the project, you need to set up **SFML** for rendering graphics.

- **Follow this YouTube tutorial** to set up SFML on your machine:  
  [**SFML Setup Tutorial**](https://youtu.be/PJN5XlAUThU?si=6-oi2c1NhKtcEGdk)

Make sure to follow the instructions for your specific platform (Windows, macOS, Linux) to correctly install and configure SFML.

---

### **3. Setting Up Assets and Code**

Before running the project, make sure you set up the **Assets/** and **Code/** folders with the necessary image files and code.

1. **Setting Up the Assets Folder**:
   - In the root directory of the project, create a folder named `Assets/`.
     
     [Explore Assets](./Assets)

2. **Setting Up the Code Folder**:
   - The **Code/** folder contains the main program file (`main.cpp`), where the core logic of the project resides.
   - You do **not** need to modify the `main.cpp` file unless you want to customize the logic or add new features.
     
     [Explore Code](./Code)

---

### **4. Compiling and Running the Project**

Once you have set up the **Assets/** and **Code/** folders correctly, follow these steps to compile and run the project:

1. **Open the Terminal or Command Prompt**:
   - For Windows, you can use **Command Prompt** or **Git Bash**.
   - For macOS/Linux, you can use the **Terminal**.

2. **Navigate to the Project Directory**:
   - Use the `cd` (change directory) command to navigate to the root directory of the project where the `Makefile` is located.
   
     Example:
     ```bash
     cd path/to/Shortest_Path_Delivery_Planner
     ```

3. **Compile the Code**:
   - Run the following command to compile the project using **MinGW** (for Windows users) or **g++** (on macOS/Linux):
     ```bash
     mingw32-make -f Makefile.txt
     ```
     This command will compile the project and generate the `main.exe` file (for Windows) or an executable file for macOS/Linux.

4. **Run the Project**:
   - After successful compilation, run the project using the following command:
     ```bash
     ./main.exe   # For Windows users
     ```
     Or, for macOS/Linux:
     ```bash
     ./main       # If no extension is needed
     ```

5. **Input the Required Data**:
   - Once the program is running, it will prompt you to input the following:
     - **Number of vertices**: Enter the number of locations (nodes) in the map.
     - **Number of edges**: Enter the number of connections (edges) between the nodes.
     - **Edge weights**: Enter the weight for each edge (this typically represents the distance or time between two locations).
     - **Source and destination nodes**: Select the starting and ending locations for the shortest path calculation.

6. **Enjoy the Real-Time Animation**:
   - After entering the required inputs, the program will calculate the shortest path using **Dijkstra's Algorithm** and display the graphical map.
   - The **car icon** will animate along the shortest path from the source to the destination, and the path will be highlighted in **green**.

---

### **5. Customization and Advanced Features**

- You can modify the logic in `main.cpp` to customize the project to your needs. For example, you can change the appearance of the map or modify how the data is input.
- You may also explore adding more advanced features, such as dynamically changing the nodes, adding more algorithms for comparison, or enhancing the UI.

---

Feel free to explore the project and experiment with different configurations!
