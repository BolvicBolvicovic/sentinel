#include "../Map.hpp"
#include <queue>
#include <deque>
#include <unordered_map>

namespace std {
    template <>
    struct hash<sf::Vector2f> {
        size_t operator()(const sf::Vector2f& v) const {
            return hash<float>()(v.x) ^ (hash<float>()(v.y) << 1);
        }
    };

    template <>
    struct equal_to<sf::Vector2f> {
        bool operator()(const sf::Vector2f& lhs, const sf::Vector2f& rhs) const {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }
    };
}

struct Node {
	sf::Vector2f	position;
	float			gCost;
	float			hCost;
	float			fCost;
	Node			*parent;

	Node() : position(0, 0), gCost(0), hCost(0), fCost(0), parent(nullptr) {}

	Node(sf::Vector2f pos, float g, float h, Node* p = nullptr)
		: position(pos), gCost(g), hCost(h), fCost(g + h), parent(p) {}
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        return a.fCost > b.fCost;
    }
};

float heuristic(sf::Vector2f a, sf::Vector2f b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

deque<sf::Vector2f> findPath(sf::Vector2f start, sf::Vector2f end, Map* map, Entity* entity) {
    priority_queue<Node, std::vector<Node>, CompareNode> openSet;
    unordered_map<sf::Vector2f, Node> allNodes;
	deque<sf::Vector2f> path;

    Node startNode(start, 0.0f, heuristic(start, end));
    openSet.push(startNode);
    allNodes[start] = startNode;

    while (!openSet.empty()) {
        Node currentNode = openSet.top();
        openSet.pop();
		sf::Vector2f dir = currentNode.position - end;
        if (abs(dir.x) < 10 && abs(dir.y) < 10) {
            Node* node = &allNodes[end];
            while (node != nullptr) {
                path.push_front(node->position);
                node = node->parent;
            }
			cout << "test" << endl;
            return path;
        }
        std::vector<sf::Vector2f> neighbors = {
            {currentNode.position.x + 10, currentNode.position.y},
            {currentNode.position.x - 10, currentNode.position.y},
            {currentNode.position.x, currentNode.position.y + 10},
            {currentNode.position.x, currentNode.position.y - 10}
        };

        for (sf::Vector2f neighborPos : neighbors) {
            if (map->intersect_with_walls(entity, neighborPos)) {
                continue;
            }
            float newGCost = currentNode.gCost + heuristic(currentNode.position, neighborPos);
            float hCost = heuristic(neighborPos, end);
            if (allNodes.find(neighborPos) == allNodes.end() || newGCost + hCost < allNodes[neighborPos].fCost) {
                Node neighborNode(neighborPos, newGCost, hCost, &allNodes[currentNode.position]);
                openSet.push(neighborNode);
                allNodes[neighborPos] = neighborNode;
            }
        }
    }

    return path;
}
