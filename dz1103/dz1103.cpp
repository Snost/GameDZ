#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Game {
    string name;
    string type;
    int year;
    double rating;

    Game(const string& t, const string& g, int y, double r) : name(t), type(g), year(y), rating(r) {}
};

class GameDatabase {
private:
    vector<Game> games;

public:
    void createGame(const string& name, const string& type, int year, double rating) {
        games.emplace_back(name, type, year, rating);
    }

    void showGames() {
        cout << "List of games:\n";
        for (const auto& game : games) {
            cout << "\nName: " << game.name << "\n Type: " << game.type << "\n Year: " << game.year << "\n Rating: " << game.rating << endl<<endl;
        }
    }

    void updateGameRating(const string& name, double newRating) {
        auto it = find_if(games.begin(), games.end(), [&](const Game& game) { return game.name == name; });
        if (it != games.end()) {
            it->rating = newRating;
            cout << "Rating updated!\n";
        }
        else {
            cout << "ERROR!\n";
        }
    }

    void deleteGame(const string& name) {
        auto it = find_if(games.begin(), games.end(), [&](const Game& game) { return game.name == name; });
        if (it != games.end()) {
            games.erase(it);
            cout << "Game deleted!\n";
        }
        else {
            cout << "ERROR!\n";
        }
    }
};

int main() {
    GameDatabase db;

    
    db.createGame("RPG GAME", "RPG", 2015, 9.8);
    db.createGame("SIMS", "Simulator", 2013, 9.7);
    db.createGame("Minecraft", "Survive", 2020, 9.5);
    db.showGames();
    cout << endl;
    db.updateGameRating("SIMS", 9.9);
    db.showGames();
    cout << endl;
    db.deleteGame("SIMS");
    db.showGames();

    return 0;
}
