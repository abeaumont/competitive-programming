# https://open.kattis.com/problems/subway2

from math import dist
from collections import defaultdict
from math import inf  # Default value in Dijkstra's algorithm
from sys import stdin  # Instead of input

adjacency_list = defaultdict(dict)
line_dict = defaultdict(dict)

TRAIN_SPEED = 40_000 / 60  # meter / min
WALK_SPEED = 10_000 / 60  # meter / min

# Parse home and school coordinates
data = list(stdin)
first_line = list(map(int, data[0].split()))
home = tuple(first_line[:2])
school = tuple(first_line[2:])

# Parse subway station's coordinates, add them to the adjacency_list and calculate their weights
for row in data[1:]:

    # Parse
    subway = list(map(int, row.split()))[:-1]
    subway = [*zip(subway[::2], subway[1::2])]

    # Add surrounding stations with the travel time to the adjacency_list
    sis = set(range(len(subway)))
    for station_index, station in enumerate(subway):

        # Add the station before and after (if possible)
        for i in [-1, 1]:

            if station_index + i in sis:
                line_dict[station][subway[i + station_index]] = dist(station, subway[i + station_index]) / TRAIN_SPEED


# Add all the walkingways between stations. But only if there doesn't already exist a connection.
all_stations = list(line_dict) + [home, school]  # Add the start- and endpoint to the graph
for current_station_index, current_station in enumerate(all_stations):
    adjacency_list[current_station] = {s: dist(s, current_station) / WALK_SPEED
                               for s in all_stations[:current_station_index] +
                                       all_stations[current_station_index + 1:]}  # Dict comprehension
    adjacency_list[current_station].update(line_dict[current_station])  # Replace walkways with subways

# Initialise some variables for the algorithm
visited = set()
node_information = {x: {"dist": inf, "from": None} for x in adjacency_list}
node_information[home]["dist"] = 0

# Using Dijkstra's algorithm to calculate the shortest path from home to school
current = home  # Start at home
while True:

    if current not in visited:
        visited.add(current)
        stack = []

        for neighbor in adjacency_list[current]:

            if neighbor not in visited:
                new_dist = node_information[current]["dist"] + adjacency_list[current][neighbor]

                if new_dist < node_information[neighbor]["dist"]:
                    node_information[neighbor] = {"dist": new_dist, "from": current}
                stack.append((node_information[neighbor]["dist"], neighbor))

        if stack:
            current = min(stack)[1]

        else:
            break


# Print result! Woohoo!
print(int(round(node_information[school]["dist"])))
