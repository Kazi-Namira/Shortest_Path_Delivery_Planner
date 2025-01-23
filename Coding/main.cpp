#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

// Dijkstra's Algorithm to find the shortest path
vector<int> dijkstra(int source, int dest, vector<vector<pii>> &graph, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1); // To reconstruct the path

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                parent[v] = u; // Update parent
                pq.push({distance[v], v});
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> path;
    for (int at = dest; at != -1; at = parent[at])
        path.push_back(at);

    reverse(path.begin(), path.end());
    return path;
}

// Function to calculate distance between two points
float calculateDistance(sf::Vector2f a, sf::Vector2f b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main()
{
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    vector<sf::Vector2f> positions(n); // Store positions of nodes

    cout << "Enter the edges (u, v, weight): " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << "Enter node positions (x, y) for each vertex: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i].x >> positions[i].y;
    }

    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shortest Path Delivery Planner");

    // Load the city map texture
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("Assets/Background-map.jpg"))
    {
        cerr << "Error: Failed to load city map texture!" << endl;
        return -1;
    }
    sf::Sprite mapSprite(mapTexture);

    // Load the location marker texture (used as vertex icons)
    sf::Texture locationTexture;
    if (!locationTexture.loadFromFile("Assets/location.png"))
    {
        cerr << "Error: Failed to load location marker texture!" << endl;
        return -1;
    }

    // Load the car texture
    sf::Texture carTexture;
    if (!carTexture.loadFromFile("Assets/car-icon.png"))
    {
        cerr << "Error: Failed to load car texture!" << endl;
        return -1;
    }
    sf::Sprite carSprite(carTexture);
    carSprite.setScale(1.1f, 1.1f); // Adjust car size

    // Create vertex markers (sprites) using the location marker
    vector<sf::Sprite> vertices(n);
    for (int i = 0; i < n; i++)
    {
        vertices[i].setTexture(locationTexture);
        vertices[i].setScale(0.1f, 0.1f);                                  // Adjust size of location icons
        vertices[i].setPosition(positions[i].x - 10, positions[i].y - 10); // Center the icons
    }

    // Create edges as lines
    vector<sf::VertexArray> edges;
    for (int u = 0; u < n; u++)
    {
        for (auto neighbor : graph[u])
        {
            int v = neighbor.first;
            sf::VertexArray edge(sf::Lines, 2);
            edge[0].position = positions[u];
            edge[1].position = positions[v];
            edge[0].color = sf::Color::Black;
            edge[1].color = sf::Color::Black;
            edges.push_back(edge);
        }
    }

    // Create text objects for displaying vertex numbers and edge weights
    sf::Font font;
    if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
    {
        cerr << "Error: Failed to load font!" << endl;
        return -1;
    }

    vector<sf::Text> vertexNumbers(n);
    for (int i = 0; i < n; i++)
    {
        vertexNumbers[i].setFont(font);
        vertexNumbers[i].setString(std::to_string(i));
        vertexNumbers[i].setCharacterSize(20);
        vertexNumbers[i].setFillColor(sf::Color::Black);
        vertexNumbers[i].setPosition(positions[i].x + 12, positions[i].y - 12); // Adjust text position
    }

    vector<sf::Text> edgeWeights;
    for (int u = 0; u < n; u++)
    {
        for (auto neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            sf::Text edgeWeight;
            edgeWeight.setFont(font);
            edgeWeight.setString(std::to_string(weight));
            edgeWeight.setCharacterSize(15);
            edgeWeight.setFillColor(sf::Color::Blue);

            // Place the text in the middle of the edge
            sf::Vector2f midPoint = (positions[u] + positions[v]) / 2.f;
            edgeWeight.setPosition(midPoint.x - 10, midPoint.y - 10);
            edgeWeights.push_back(edgeWeight);
        }
    }

    // Variables for source and destination
    int source = -1, destination = -1;
    bool pathFound = false;
    vector<int> path;

    // Variables for car movement
    size_t currentPathIndex = 0;
    float carSpeed = 0.05f; // Speed of the car's movement (reduced speed)

    // Main rendering loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse click for selecting source and destination
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);
                    for (int i = 0; i < n; i++)
                    {
                        sf::FloatRect vertexBounds(vertices[i].getGlobalBounds());
                        if (vertexBounds.contains(worldMousePos))
                        {
                            if (source == -1)
                            {
                                source = i;
                                carSprite.setPosition(positions[source]); // Place car at the source
                            }
                            else if (destination == -1 && i != source)
                            {
                                destination = i;
                                path = dijkstra(source, destination, graph, n);
                                pathFound = true;
                                currentPathIndex = 0; // Start from the first point in the path
                            }
                        }
                    }
                }
            }
        }

        // Move the car along the path
        if (pathFound && currentPathIndex < path.size() - 1)
        {
            sf::Vector2f currentPos = positions[path[currentPathIndex]];
            sf::Vector2f nextPos = positions[path[currentPathIndex + 1]];

            // Move the car gradually towards the next point
            sf::Vector2f direction = nextPos - currentPos;
            float distanceToMove = carSpeed;
            if (calculateDistance(currentPos, nextPos) < carSpeed)
                distanceToMove = calculateDistance(currentPos, nextPos);

            direction = direction / calculateDistance(currentPos, nextPos); // Normalize the direction
            carSprite.move(direction * distanceToMove);

            // If car reaches the next point in the path, move to the next segment
            if (calculateDistance(carSprite.getPosition(), nextPos) < 5.0f)
            {
                currentPathIndex++;
            }
        }

        // Reset source and destination after completing the path
        if (pathFound && currentPathIndex == path.size() - 1)
        {
            // Reset source to the destination for the next trip
            source = destination;
            destination = -1;  // Allow re-selecting the destination
            pathFound = false; // Path traversal completed
        }

        window.clear();
        window.draw(mapSprite);  // Draw the map background
        for (auto &edge : edges) // Draw all edges
            window.draw(edge);
        for (auto &vertex : vertices) // Draw all vertices (location markers)
            window.draw(vertex);

        // Draw the vertex numbers
        for (auto &text : vertexNumbers)
            window.draw(text);

        // Draw the edge weights
        for (auto &text : edgeWeights)
            window.draw(text);

        // Draw shortest path if found (yellow lines)
        if (pathFound)
        {
            for (size_t i = 0; i < path.size() - 1; i++)
            {
                sf::VertexArray pathEdge(sf::Lines, 2);
                pathEdge[0].position = positions[path[i]];
                pathEdge[1].position = positions[path[i + 1]];
                pathEdge[0].color = sf::Color::Green;
                pathEdge[1].color = sf::Color::Green;
                window.draw(pathEdge);
            }
        }

        window.draw(carSprite); // Draw the car
        window.display();
    }

    return 0;
}
