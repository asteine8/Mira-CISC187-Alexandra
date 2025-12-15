#include <string>
#include <unordered_map>
#include <iostream>

struct Player {
    std::string firstName;
    std::string lastName;
    std::string team;

    Player(std::string fn, std::string ln, std::string tm) {
        firstName = fn;
        lastName = ln;
        team = tm;
    }
};


class PlayerRoster {
    public:
        // key = first name+last name
        std::unordered_map<std::string, Player> players;

        void addPlayer(Player player) {
            std::string fullName = player.firstName + " " + player.lastName;
            players.insert({fullName, player});
        }

        void addPlayers(std::vector<Player> ps) {
            for (auto p : ps) {
                std::string fullName = p.firstName + " " + p.lastName;
                players.insert({fullName, p});
            }
        }

        void appendRoster(PlayerRoster roster) {
            // players.merge(roster.players);
            for (auto p : roster.players) {
                players.insert(p);
            }
        }

        void printRoster() {
            std::cout << "[" << std::endl;
            for (auto player : players) {
                std::cout << "{first_name: ";
                std::cout << player.second.firstName << ", last_name: ";
                std::cout << player.second.lastName << ", team: ";
                std::cout << player.second.team;
                std::cout << "}" << std::endl;
            }
            std::cout << "]";
        }
};

class Task1 {
    public:

        static PlayerRoster findSharedPlayers(PlayerRoster roster1, PlayerRoster roster2) {

            // Operates in O(N+M) time
            PlayerRoster allPlayers;
            allPlayers.appendRoster(roster1);
            allPlayers.appendRoster(roster2);

            std::unordered_map<std::string, bool> playerMap;

            // Also in O(N+M) time
            for (auto it: allPlayers.players) {
                playerMap.insert({it.first, false});
            }

            // Operates in O(N)
            for (auto it: roster1.players) {
                playerMap[it.first] = true;
            }

            PlayerRoster sharedPlayers;

            // Operates in O(M)
            for (auto it: roster2.players) {
                if (playerMap[it.first] == true) {
                    sharedPlayers.addPlayer(it.second);
                }
            }

            return sharedPlayers;
        }
};