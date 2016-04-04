#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INFINITY = 10000;
const int HIGH_VALUE = 8000;
const int CHECK_VALUE = 9000;

class dist {
public:
    int x;
    int y;
    int d;
    dist(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};
    
class state {
public:
    int city;
    int cost;
    vector<vector<int > > matrix;
    vector<int> remaining_cities;
    int cities_left_to_expand;
    list<int> stack;

    const bool operator<(const state& s) const {
        return cost < s.cost;
    }
};

void available_moves (vector<pair<int, int> >& xs, int x, int y)
{
    int offsets[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for(int i = 0; i < 4; i++) {
        xs[i] = make_pair(x + offsets[i][0], y + offsets[i][1]);
    }
}

bool valid_move(vector<vector<char> >& map, int x, int y) {
    return x >= 0 && x <= map[0].size() && y >= 0 && y < map.size() && map[y][x] != 'X';
}
    
bool valid_moves(vector<vector<char> >& map, list<pair<int, int> >& valid, vector<pair<int, int> >& available) {
    for (auto it = available.begin(); it != available.end(); it++) {
        if (valid_move(map, it->first, it->second)) {
            valid.push_front(*it);
        }
    }
}
    
void path_map(vector<vector<char> >& map, vector<vector<int> >& paths, int x, int y) {
    int size_y = map.size();
    int size_x = map[0].size();
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            paths[i][j] = -1;
        }
    }
    list<dist> pending;
    dist initial(x, y, 0);
    pending.push_front(initial);
    while (!pending.empty()) {
        dist current = pending.front();
        pending.pop_front();
        if (paths[current.y][current.x] == -1) {
            paths[current.y][current.x] = current.d;
            vector<pair<int, int> > available(4);
            available_moves(available, current.x, current.y);
            list<pair<int, int> > valid;
            valid_moves(map, valid, available);
            for (auto it = valid.begin(); it != valid.end(); it++) {
                dist next(it->first, it->second, current.d + 1);
                pending.push_back(next);
            }
        }
    }
}

void positions(vector<vector<char> >&map, vector<pair<int, int> >& positions, int x, int y) {
    int i = 1;
    for (int j = 0; j < y; j++) {
        for (int k = 0; k < x; k++) {
            switch(map[j][k]) {
            case 'M':
                positions[i] = make_pair(k, j);
                i++;
                break;
            case 'B':
                positions[0] = make_pair(k, j);
                break;
            }
        }
    }
}

void distances(vector<vector<int> >& distances, vector<vector<char> >&map, vector<pair<int, int> >& positions) {
    int size = positions.size();
    vector<vector<int> > paths = vector<vector<int> >(map.size());
    for (int i = 0; i < map[0].size(); i++) {
        paths[i] = vector<int>(map[0].size());
    }
    for (int i = 0; i < size; i++) {
        distances[i][i] = INFINITY;
        path_map(map, paths, positions[i].first, positions[i].second);
        for (int j = i + 1; j < size; j++) {
            pair<int, int> target = positions[j];
            int x = target.first;
            int y = target.second;
            int distance = paths[y][x];
            distances[i][j] = distance;
            distances[j][i] = distance;
        }
    }
    for (int i = 1; i < size; i++) {
        distances[size][i] = HIGH_VALUE;
        distances[i][size] = HIGH_VALUE;
    }
    distances[size][size] = INFINITY;
    distances[size][size] = INFINITY;
}

void minimize(vector<int>& xs, int min) {
    for(int i = 0; i < xs.size(); i++) {
        xs[i] -= min;
    }
}

int minimum(vector<int>& xs) {
    int min = CHECK_VALUE;
    for(auto it = xs.begin(); it != xs.end(); it++) {
        min = min < *it ? min : *it;
    }
    if (min == CHECK_VALUE) {
        return 0;
    }
    return min;
}

int reduce_distances(vector<vector<int> >&distances, int cost, int row, int column) {
    int new_cost = cost;
    for (int i = 0; i < distances.size(); i++) {
        if (i == row) continue;
        int min = minimum(distances[i]);
        if (min) {
            new_cost += min;
            minimize(distances[i], min);
        }
    }
    for (int i = 0; i < distances.size(); i++) {
        if (i == column) continue;
        vector<int> to_reduce(distances.size());
        for (int j = 0; j < distances.size(); j++) {
            to_reduce[j] = distances[j][i];
        }
        int min = minimum(to_reduce);
        if (min) {
            new_cost += min;
            minimize(to_reduce, min);
            for (int j = 0; j < distances.size(); j++) {
                distances[j][i] = to_reduce[j];
            }
        }
    }
    return new_cost;
}

void expand(list<state>& expanded, state& current) {
    for (int i = 0; i < current.remaining_cities.size(); i++) {
        int remaining_city = current.remaining_cities[i];
        if (remaining_city) {
            int size = current.matrix.size();
            vector<vector<int> > matrix = current.matrix;
            int cost = current.cost + matrix[current.city][remaining_city];
            for (int j = 0; j < size; j++) {
                matrix[current.city][j] = INFINITY;
                matrix[j][remaining_city] = INFINITY;
            }
            matrix[remaining_city][0] = INFINITY;

            state next;
            next.matrix = matrix;
            next.city = remaining_city;
            next.cost = reduce_distances(matrix, cost, current.city, remaining_city);
            vector<int> remaining_cities = vector<int>(current.remaining_cities.size());
            for (int j = 0; j < current.remaining_cities.size(); j++) {
                remaining_cities[j] = current.remaining_cities[j];
            }
            remaining_cities[i] = 0;
            next.remaining_cities = remaining_cities;
            next.cities_left_to_expand = current.cities_left_to_expand - 1;
            list<int> stack;
            for (auto it = current.stack.begin(); it != current.stack.end(); it++) {
                stack.push_front(*it);
            }
            stack.push_front(remaining_city);
            next.stack = stack;
            expanded.push_front(next);
        }
    }
}

void process() {
    int steps;
    int x;
    int y;
    cin >> steps >> x >> y;
    vector<vector<char> > map = vector<vector<char> >(y);
    int mice = 0;
    for (int i = 0; i < y; i++) {
        map[i] = vector<char>(x);
        for (int j = 0; j < x; j++) {
            char ch;
            cin >> ch;
            if (ch == 'M') mice++;
            map[i][j] = ch;
        }
    }
    vector<pair<int, int> > pos(mice + 1);
    positions(map, pos, x, y);
    vector<vector<int> > dists = vector<vector<int> >(mice + 3);
    for (int i = 0; i < mice + 3; i++) {
        dists[i] = vector<int>(mice + 3);
    }
    distances(dists, map, pos);
        
    state s1;
    s1.city = 0;
    s1.cost = reduce_distances(dists, 0, -1, -1);
    s1.matrix = dists;
    s1.stack.push_front(0);
    vector<int> remaining_cities = vector<int>(dists.size() - 1);
    for (int i = 0; i < remaining_cities.size(); i++) {
        remaining_cities[i] = i + 1;
    }
    s1.remaining_cities = remaining_cities;
    s1.cities_left_to_expand = dists.size() - 1;
    list<state> nodes;
    nodes.push_front(s1);
    state best_solution;
    int best = INFINITY * 2;
    while (!nodes.empty()) {
        state current = nodes.front();
        nodes.pop_front();
        if (current.cities_left_to_expand) {
            if (current.cost <= best) {
                list<state> expanded;
                expand(expanded, current);
                expanded.sort();
                for (auto it = expanded.begin(); it != expanded.end(); it++) {
                    nodes.push_front(*it);
                }
            }
        } else {
            if (current.cost <= best) {
                best_solution = current;
                best = best_solution.cost;
            }
        }
    }
    if (best <= steps) {
        cout << (steps - best) << endl;
    } else {
        cout << "NO\n";
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        process();
    }
}
