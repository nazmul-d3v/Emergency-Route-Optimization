# 🚑 Emergency Route Optimization

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=cplusplus" />
  <img src="https://img.shields.io/badge/Algorithm-Dijkstra-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Graph-Theory-orange?style=for-the-badge" />
  <img src="https://img.shields.io/github/license/nazmul-d3v/Emergency-Route-Optimization?style=for-the-badge" />
</p>

<p align="center">
  <strong>A graph-based emergency route optimization system that finds the shortest and fastest path for emergency vehicles using Dijkstra's Algorithm.</strong>
</p>

---

## 📖 Project Overview

**Emergency Route Optimization** is a C++ project that simulates how emergency services (such as ambulances, fire trucks, or police vehicles) can quickly reach their destination by calculating the shortest route in a road network.

The project models a city as a weighted graph, where:

* 🏙️ Nodes represent locations or intersections.
* 🛣️ Edges represent roads.
* ⏱️ Edge weights represent travel time or distance.

The shortest route is computed using **Dijkstra's Algorithm**, one of the most efficient algorithms for solving single-source shortest path problems on graphs with non-negative edge weights. Dijkstra's algorithm is a standard choice for shortest-path routing in road networks and transportation systems.

---

## ✨ Features

* 🚑 Shortest path calculation
* 📍 Graph-based city representation
* ⚡ Fast route computation
* 🧠 Dijkstra's Algorithm implementation
* 📊 Weighted graph support
* 💻 Console-based simulation
* 📚 Beginner-friendly code structure

---

## 🛠️ Technologies Used

* C++
* STL (Standard Template Library)
* Graph Theory
* Dijkstra's Algorithm

---

## 📂 Project Structure

```text
Emergency-Route-Optimization/
│
├── main.cpp
├── graph.cpp
├── graph.h
├── dijkstra.cpp
├── dijkstra.h
└── README.md
```

> **Note:** Update the file names above if your repository structure is different.

---

## 🚀 How It Works

1. Create a weighted graph representing the road network.
2. Select a source (starting location).
3. Select a destination.
4. Run Dijkstra's Algorithm.
5. Display the shortest route and total travel cost.

---

## 📊 Algorithm

**Dijkstra's Algorithm**

The algorithm repeatedly selects the unvisited node with the smallest known distance and updates the distances to its neighboring nodes until all reachable nodes have been processed.

### Time Complexity

| Operation                 |           Complexity |
| ------------------------- | -------------------: |
| Dijkstra (Priority Queue) | **O((V + E) log V)** |

Where:

* **V** = Number of vertices
* **E** = Number of edges

---

## ▶️ Compile & Run

```bash
g++ main.cpp -o emergency_route
./emergency_route
```

---

## 📚 Concepts Covered

* Graph Theory
* Weighted Graphs
* Shortest Path
* Dijkstra's Algorithm
* Data Structures
* Priority Queue
* C++ STL

---

## 🎯 Applications

* 🚑 Ambulance Routing
* 🚒 Fire Department Navigation
* 🚓 Police Dispatch Systems
* 🗺️ GPS Navigation
* 🚚 Logistics & Delivery
* 🚦 Smart City Transportation

---

## 🔮 Future Improvements

* Interactive map visualization
* Real-time traffic updates
* A* Search Algorithm
* Multiple destination support
* Road blockage simulation
* Dynamic edge weights
* Graphical User Interface (GUI)

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push the branch
5. Open a Pull Request

---

## 👨‍💻 Author

**Nazmul Islam**

* GitHub: https://github.com/nazmul-d3v

---

## ⭐ Support

If you found this project useful, consider giving it a **⭐ Star** on GitHub.

---

<p align="center">
Made with ❤️ using C++ and Graph Theory
</p>
